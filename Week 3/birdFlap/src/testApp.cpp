#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    lwing.loadImage("lwing.jpg");
    rwing.loadImage("wing.jpg");
    
    
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    
    
    cam.begin();
    
    ofBackground(255);

    ofPushMatrix();
    float sinOfTime=sin(ofGetElapsedTimef()*2);
    lworld=ofMap(sinOfTime, -1, 1, -.3, .3);
    ofRotateY( ofRadToDeg(lworld) );
    lwing.draw(0, 0, 0);
    ofPopMatrix();
    
    ofPushMatrix();
    float cosOfTime=-1*sin(ofGetElapsedTimef()*2);
    rworld=ofMap(cosOfTime, -1, 1, -.3, .3);
    ofRotateY( ofRadToDeg(rworld) );
    rwing.draw(rwing.width*-1, 0, 0);
    ofPopMatrix();
    
    cam.end();
     ofDrawBitmapStringHighlight("EasyCam enabled.", ofPoint(20,20));
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
