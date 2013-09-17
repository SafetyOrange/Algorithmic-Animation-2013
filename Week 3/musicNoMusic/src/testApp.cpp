#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    for(int i=0; i<300;i++){
        stars[i].x=ofRandom(0,ofGetWidth());
        stars[i].y=ofRandom(0,ofGetHeight());
        stars[i].z=ofRandom(0,ofGetWidth());
        
        angles[i]=ofRandom(360);
        vecs[i]=ofVec3f(ofRandom(30), ofRandom(30), ofRandom(30));
    }

}

//--------------------------------------------------------------
void testApp::update(){


}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofPushMatrix();
    
    rot+=1;
    ofRotateY(ofDegToRad(rot));
    ofBackground(0);

    for(int i=0; i<300;i++){
        ofPushMatrix();
        ofTranslate(stars[i].x, stars[i].y, stars[i].z);
        ofRotate(angles[i], vecs[i].x, vecs[i].y, vecs[i].z);
        ofDrawCone(0,0,0, 2, 30);
        ofPopMatrix();
    }
    
    
    ofPopMatrix();
    
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
