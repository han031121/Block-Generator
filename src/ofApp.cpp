#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofBackground(0);

	initializeDrawValue();
	initializeBlockValue();
	loadGuiSettings();

	updateLayout();
	guiSetListener();
	guiSetScale();

	block_data = std::make_unique<blockData>(block_count_1, block_count_2, max_r, max_c, max_h);
	block_data->generateBlock();
	draw_object = std::make_unique<drawObject>(block_data.get(), image_size, image_size);

	blockSettingUpdate();
	blockCurrentInfoUpdate();

	ofSetEscapeQuitsApp(false);
}

//--------------------------------------------------------------
void ofApp::update(){
	if (draw_object) {
		drawObjectUpdate();
		draw_object->render();
	}

	statusUpdate();

	if (fix_light) {
		light_degree_xz = cam_degree_xz;
	}
}

//--------------------------------------------------------------
void ofApp::draw() {
	ofSetColor(220);
	ofDrawRectangle(rect_image);

	if (draw_object) {
		float size = std::min(rect_image.getWidth(), rect_image.getHeight());
		float x = (2 * rect_image.x + rect_image.getWidth() - size) / 2;
		float y = (2 * rect_image.y + rect_image.getHeight() - size) / 2;
		ofSetColor(255);
		draw_object->drawFbo(x, y, size, size);
	}

	if (gui_on) {
		ofSetColor(50);
		ofDrawRectangle(rect_block_gui);
		ofDrawRectangle(rect_draw_gui);

		ofNoFill();
		ofSetLineWidth(3);
		ofDrawRectangle(rect_status_block);
		ofDrawRectangle(rect_status_draw);
		ofFill();

		gui_block.draw();
		gui_draw.draw();

		ofSetColor(255);
		drawStatus();
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == 'n' || key == 'N') {
		setBlockClicked();
	} else if (key == 'g' || key == 'G') {
		generateBlockClicked();
	} else if (key == 's' || key == 'S') {
		saveImageClicked();
	} else if (key == 'r' || key == 'R') {
		drawResetClicked();
	} else if (key == '=') {
		if (gui_scale < 8) {
			gui_scale++;
			guiSetScale();
		}
	} else if (key == '-') {
		if (gui_scale > 1) {
			gui_scale--;
			guiSetScale();
		}
	} else if (key == OF_KEY_ESC) {
		gui_on = !gui_on;
		updateLayout();
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
	updateLayout();
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

//--------------------------------------------------------------
void ofApp::exit() {
	saveGuiSettings();
}
