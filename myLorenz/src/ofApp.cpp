#include "ofApp.h"

void ofApp::setup(){
    ofBackground(0);
    x = 0.01f;
    y = 0.0f;
    z = 0.0f;

    // have a look at the wikipedia page, "Example solutions of the Lorenz system for different values of ρ "
    // https://en.wikipedia.org/wiki/Lorenz_system
    // try to change those values

    a = 10.0f;
    b = 28.0f;
    c = 8.0f / 3.0f ;
    hue = 0.0f;

    mesh.setMode(OF_PRIMITIVE_POINTS);
    mesh.enableColors();
}

//--------------------------------------------------------------
void ofApp::update(){
    float dt = 0.01f;
    float dx =  (a*(y - x)) * dt;
    float dy =  (x* (b - z) - y) * dt;
    float dz =  (x*y - c*z ) * dt;

    x += dx;
    y += dy;
    z += dz;

    hue += 0.1;
    if (hue>= 255) hue=0;
    mesh.addVertex(glm::vec3(x, y, z));
    ofColor color;
    color.setHsb(hue, 255, 255);
    mesh.addColor(color);
}

//--------------------------------------------------------------
void ofApp::draw(){
    cam.begin();
    mesh.draw();
    cam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 's'){
        mesh.save(ofGetTimestampString("[%H:%M:%S.%i]")+".ply");
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

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
