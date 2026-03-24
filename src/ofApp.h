#pragma once

#include "ofMain.h"
#include "ofxBlockGenerator.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		void updateUI();

		std::unique_ptr<blockData> block_data;
		std::unique_ptr<drawObject> draw_object;

		ofRectangle gui_rect;
		ofRectangle draw_rect;
		float gui_width = 500.0f;
		float margin = 10.0f;

		ofxPanel gui;
};
