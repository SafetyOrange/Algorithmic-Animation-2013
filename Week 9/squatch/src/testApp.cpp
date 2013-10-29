#include "testApp.h"

//Squash and Stretch

//Staging

//--------------------------------------------------------------
void testApp::setup(){
    ofSetCircleResolution(1000);
    ofEnableSmoothing();
    ofBackground(0);
    
    x=ofGetWidth()/2;
    y=ofGetHeight()/2;
    w=100;
    h=100;

    thresh=ofGetHeight()-100-h;
}

//--------------------------------------------------------------
void testApp::update(){
    
    y+=vel;
    vel+=grav;
    
    if(y>=ofGetHeight()-100){
        y=ofGetHeight()-101;
        vel*=-.96;
    }
    
    if(y>thresh){
        w=ofMap(y, thresh, ofGetHeight(), 100, 500);
        h=ofMap(w, 500, 100, 100, 120);
    }
    if(y<=thresh) {
        h=ofMap(abs(vel), 0, 6, 100, 120);
    }

}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofSetColor(255,0,0);
    ofEllipse(x,y,w,h);
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
