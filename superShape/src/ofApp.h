#pragma once

#include "ofMain.h"

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
    float supershape(float theta, float m, float n1, float n2, float n3);

    float r = 100;
    float a = 1;
    float b = 1;
    int total = 15;
    float offset = 0;
    float m = 0;
    float mchange = 0;

    ofEasyCam cam;
    vector<vector<glm::vec3>> globe;
    ofMesh mesh;

		
};
