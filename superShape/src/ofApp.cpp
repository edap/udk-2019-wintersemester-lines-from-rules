#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
        ofEnableDepthTest();
    // necessary intro, the equation of a sphere
    //http://paulbourke.net/geometry/supershape/
    // https://www.syedrezaali.com/3d-supershapes/

    mesh.setMode(OF_PRIMITIVE_POINTS);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    m = ofMap(offset, -1, 1, 0, 7.0);
    offset += 0.02;
    globe.clear();
    mesh.clear();
    globe.resize(total+1);
    for (int i = 0; i < total+1; i++) {
        vector<glm::vec3> vect;
        vect.resize(total);
        globe[i] = vect;
        auto lat = ofMap(i, 0, total, -HALF_PI, HALF_PI);
        auto r2 = supershape(lat, 2, 10, 10, 10);

        for (int j = 0; j < total+1; j++) {
            auto lon = ofMap(j, 0, total, -PI, PI);
            auto r1 = supershape(lon, 8, 60, 100, 30);
            auto x = r * r1 * cos(lon) * r2 * cos(lat);
            auto y = r * r1 * sin(lon) * r2 * cos(lat);
            auto z = r * r2 * sin(lat);

            globe[i].push_back(glm::vec3(x, y, z));
            ofLog() << x;
        }
    }


    cam.begin();
//    for (int i = 0; i < total; i++) {
//        for(int j = 0; j < total+1; j++){
//            //ofDrawIcoSphere(b, 4);
//            auto v = globe[i][j];
//            mesh.addVertex(v);
//            ofDrawSphere(v, 1);
//            //mesh.addVertex(globe[a+1][b]);
//        }
//    }


    int i, j = 0;
    for(auto a: globe){
        for (auto b:a){
            
            ofLog() << a.size();
            ofLog() << globe.size();
            //ofDrawSphere(b, 5);
            auto v = globe[i][j];
            mesh.addVertex(v);
            j++;
        }
        i++;
    }
    mesh.draw();
    cam.end();

}

float ofApp::supershape(float theta, float m, float n1, float n2, float n3){
    float t1 = abs((1.0f/a)*cos(m * theta / 4.0f));
    t1 = pow(t1, n2);
    float t2 = abs((1.0f/b)*sin(m * theta/4.0f));
    t2 = pow(t2, n3);
    float t3 = t1 + t2;
    float r = pow(t3, - 1.0f / n1);
    return r;

};

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
