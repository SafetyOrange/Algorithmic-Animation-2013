#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    Hank=Creature();
    
    for(int i=0;i<200;i++){
        stars[i].x=ofRandom(ofGetWidth());
        stars[i].y=ofRandom(ofGetHeight());
    }
    ofBackground(0);

}

//--------------------------------------------------------------
void testApp::update(){
    
    

}

//--------------------------------------------------------------
void testApp::draw(){
    
    
    
    for(int i=0;i<200;i++){
        ofSetColor(255);
        ofCircle(stars[i].x, stars[i].y, 1);
    }
    
    Hank.update();

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
