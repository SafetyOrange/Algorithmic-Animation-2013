#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    Earth.setup(9.8, 1);  //Actual Gravity, Ratio to Earth size
    Jupiter.setup(24.79, 11.21);
    Moon.setup(1.622, 0.2724);
    
    for(int i=0;i<200;i++){
        stars[i].x=ofRandom(ofGetWidth());
        stars[i].y=ofRandom(ofGetHeight());
    }

}

//--------------------------------------------------------------
void testApp::update(){
    
    Earth.update();
    Jupiter.update();
    Moon.update();

}

//--------------------------------------------------------------
void testApp::draw(){
    
    
    ofBackground(0);
    
    for(int i=0;i<200;i++){
        ofSetColor(255);
        ofCircle(stars[i], 1);
    }
    
    Jupiter.draw('j');
    Earth.draw('e');
    Moon.draw('m');
    
    ofDrawBitmapStringHighlight("Click to spice up the velocity", 10, 20);

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
    
    Earth.vel+=ofVec2f(ofRandom(-5,5), ofRandom(-15, -10));
    Jupiter.vel+=ofVec2f(ofRandom(-5,5), ofRandom(-15,-10));
    Moon.vel+=ofVec2f(ofRandom(-5,5), ofRandom(-15,-10));

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
