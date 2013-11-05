#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    lastTime = ofGetElapsedTimef();
    timeScale = 1.0;
    
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    
    red.prime(ofColor(255,0,0));
    green.prime(ofColor(0,255,0));
    blue.prime(ofColor(0,0,255));
}

//--------------------------------------------------------------
void testApp::update(){
    
    float dt = ofGetElapsedTimef() - lastTime;
    lastTime = ofGetElapsedTimef();
    
    
    red.update( dt * timeScale );
    blue.update( dt * timeScale );
    green.update( dt * timeScale );
    
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
    
    timeScale = ofMap( x, 0, ofGetWindowWidth(), -3, 3 );

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
