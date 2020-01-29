#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    x = 0.01f;
    y = 0.0f;
    z = 0.0f;

    // have a look at the wikipedia page, "Example solutions of the Lorenz system for different values of ρ "
    // https://en.wikipedia.org/wiki/Lorenz_system
    // try to change those values
    a = 10.0f;
    b = 28.0f;
    c = 8.0f/3.0f;
    hue = 0;

    mesh.setMode(OF_PRIMITIVE_POINTS);
    mesh.enableColors();
}

//--------------------------------------------------------------
void ofApp::update(){
    // this is where all the magic is happening
    float dt = 0.01f;
    float dx = (a * (y - x))*dt;
    float dy = (x * (b - z) - y)*dt;
    float dz = (x * y - c * z)*dt;
    x = x + dx;
    y = y + dy;
    z = z + dz;

    mesh.addVertex(glm::vec3(x,y,z));

    ofColor col;
    hue += 0.1f;
    if (hue>255.0f) {
        hue = 0.0f;
    }
    col.setHsb(hue, 255, 255);
    mesh.addColor(col);

    // reset at frame 600
    if (ofGetFrameNum() % 1200 == 0) {
        mesh.clear();
        x = 0.01f;
        y = 0.0f;
        z = 0.0f;

        a = 10.0f;
        b = 28.0f;
        c = 8.0f/3.0f;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    cam.begin();
    mesh.draw();
    cam.end();
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

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
