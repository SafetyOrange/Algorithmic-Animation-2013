#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ballPlace=ofVec3f(0,0,0);
    ballVel=ofVec3f(5,7,2);

}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    ofBackground (255, 127, 0);
    ofSetColor(0, 0, 0);
    ofSetLineWidth(3);
    ofDrawBitmapString("Click and drag. Double click to reset", ofPoint(10,20));

    cam.begin();
    ofNoFill();
    ofDrawBox(0, 0, 0, 500, 500, 500);
    ofDrawSphere(ballPlace.x, ballPlace.y, ballPlace.z, 50);
    
    ballPlace+=ballVel;
 
    if(ballPlace.x+25>=250 || ballPlace.x-25<=-250) ballVel.x*=-1;
    if(ballPlace.y+25>=250 || ballPlace.y-25<=-250) ballVel.y*=-1;
    if(ballPlace.z+25>=250 || ballPlace.z-25<=-250) ballVel.z*=-1;
    
    
    
    cam.end();

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
