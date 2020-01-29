#pragma once

#include "ofMain.h"
#include "Quadtree.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();


    Quadtree quadtree;
};
