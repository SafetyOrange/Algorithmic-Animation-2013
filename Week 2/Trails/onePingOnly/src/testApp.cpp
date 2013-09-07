#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofEnableAlphaBlending();
    ofSetBackgroundAuto(false);
    ofEnableSmoothing();

}

//--------------------------------------------------------------
void testApp::update(){
    


}

//--------------------------------------------------------------
void testApp::draw(){
    ofSetColor(0, 0, 0, 70);
    ofRect(0,0,ofGetWidth(),ofGetHeight());
    
    ofSetColor(0, 255, 0, 255);
    ofSetLineWidth(5);
        x=400*cos(i)+ofGetWidth()/2;
        y=400*sin(i)+ofGetHeight()/2;
        ofLine(ofGetWidth()/2, ofGetHeight()/2, x, y);
        if(ofDist(x,y,200,200)<50) ofEllipse(200,200,30,30);
     if(ofDist(x,y,500,700)<100) ofEllipse(500,500,30,30);

    i+=.05;
    if(i>2*PI) i=0;


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
