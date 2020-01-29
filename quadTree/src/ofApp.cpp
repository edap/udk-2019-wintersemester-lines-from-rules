#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    int w = 800;
    int h = 800;
    quadtree = Quadtree(0, w, 0, h, 1);

    vector<ofPoint> points;
    for (int i = 0; i < 200; i++) {
        auto point = ofPoint(ofRandom(w), ofRandom(h));
        quadtree.add(point);
    }

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    ofSetColor(255);
    quadtree.draw();

    ofSetColor(0, 255, 0);
    ofDrawRectangle(mouseX, mouseY, 300, 300);

    vector<ofPoint> result;
    quadtree.query(mouseX, mouseY, 300, 300, result);
    for(auto r:result){
        ofDrawCircle(r.x, r.y, 5);
    }
}
