#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
 //   ofEnableAlphaBlending();
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    
    red.prime(ofColor(255,0,0));
    green.prime(ofColor(0,255,0));
    blue.prime(ofColor(0,0,255));
}

//--------------------------------------------------------------
void testApp::update(){
    red.update();
    blue.update();
    green.update();
}

//--------------------------------------------------------------
void testApp::draw(){
    ofBackground(0);
    red.draw();
    green.draw();
    blue.draw();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
