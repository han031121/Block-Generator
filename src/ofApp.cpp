#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(0);
	block_data = std::make_unique<blockData>(4, 8, 4, 4, 4);
	block_data->generateBlock();
	draw_object = std::make_unique<drawObject>(block_data.get(), 1000, 1000);

	updateUI();
}

void ofApp::updateUI() {
	float w = ofGetWidth();
	float h = ofGetHeight();

	gui_rect.set(margin, margin, gui_width, h - 2 * margin);
	draw_rect.set(gui_width + 2 * margin, margin, w - gui_width - 3 * margin, h - 2 * margin);
	gui.setPosition(gui_rect.x, gui_rect.y);
}

//--------------------------------------------------------------
void ofApp::update(){
	if (draw_object)
		draw_object->render();
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetColor(50);
	ofDrawRectangle(gui_rect);
	ofSetColor(220);
	ofDrawRectangle(draw_rect);

	if (draw_object) {
		float size = std::min(draw_rect.getWidth(), draw_rect.getHeight());
		float x = (2 * draw_rect.x + draw_rect.getWidth() - size) / 2;
		float y = (2 * draw_rect.y + draw_rect.getHeight() - size) / 2;
		ofSetColor(255);
		draw_object->drawFbo(x, y, size, size);
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
	updateUI();
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
