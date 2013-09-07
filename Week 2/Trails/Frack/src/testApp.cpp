#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofEnableAlphaBlending();
    ofSetBackgroundAuto(false);
    ofSetRectMode(OF_RECTMODE_CENTER);
    
    for(int i=0; i<numText;i++){
        text[i].setup();
    }

}

//--------------------------------------------------------------
void testApp::update(){
    
    for(int i=0; i<numText;i++){
        text[i].update();
    }

}

//--------------------------------------------------------------
void testApp::draw(){
    ofSetColor(0, 0, 0, 10);
    ofRect(ofGetWidth()/2,ofGetHeight()/2,ofGetWidth(), ofGetHeight());
    
    ofSetColor(255, 0, 0, 255);
    ofEllipse(xPos, ofGetHeight()/2, 50, 50);
    ofSetColor(255, 0, 0, 20);
    ofEllipse(xPos, ofGetHeight()/2, 100,100);
    sizer-=.75;
    xPos+=displace;
    if(xPos>=3*ofGetWidth()/4 || xPos<=ofGetWidth()/4){
        displace*=-1;
        sizer=50;
    }

    for(int i=0; i<numText;i++){
        text[i].draw();
    }

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
