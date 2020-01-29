#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    image.allocate(side, side, OF_IMAGE_COLOR);

    int i = 0;
    while (i < 30) {
        seeds.push_back(glm::vec2(ofRandom(side), ofRandom(side)));
        i++;
        colors.push_back(ofColor(ofRandom(255),
                                 ofRandom(255),
                                 ofRandom(255)
        ));
    }

    auto &pixels = image.getPixels();
    auto currentPixel = glm::vec2();
    for (int y = 0; y < pixels.getHeight(); y++) {
        for (int x = 0; x <pixels.getWidth(); x++) {
            currentPixel.x = x;
            currentPixel.y = y;
            int idx =  getClosestSeedIndex(currentPixel);
            pixels.setColor(x, y, colors[idx]);
        }
    }

    image.setFromPixels(pixels);
}

int ofApp::getClosestSeedIndex(glm::vec2 point){
    float dist = std::numeric_limits<float>::max();
    int result, index = 0;

    for (auto s:seeds) {
        float p = 3.0;
        auto tmpDist = glm::distance(s, point); // euclidian distance
        //auto tmpDist = abs(s.x - point.x) + abs(s.y - point.y); //manhattan distance
        //auto tmpDist = pow(pow(abs(s.x - point.x), p) + pow(abs(s.y - point.y), p), (1.0f / p)); // Minkovski distance
        if (tmpDist < dist) {
            dist = tmpDist;
            result = index;
        };
        index ++;
    }
    return result;
};

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    image.draw(0,0);
    if (debug) {
        for (auto s:seeds) {
            ofDrawCircle(s, 2);
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 'd') {
        debug = !debug;
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
