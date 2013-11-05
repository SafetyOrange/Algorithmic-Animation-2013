#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    
    int num = 300;
    size = 10;
    
    numbo = num;
    for(int i=0;i<num;i++){
        
    pos.push_back(ofVec2f(ofGetWidth()/4,ofGetHeight()/4));
    vel.push_back(ofVec3f( ofRandom(-20,20), ofRandom(-10, 10), 0 ));
    
    mFbo.allocate( ofGetWindowWidth(), ofGetWindowHeight() );
    
    ofBackground(0);
    ofEnableAlphaBlending();
    }
}

//--------------------------------------------------------------
void testApp::update(){
    
    for(int i=1;i<numbo; i++){
        
    
    pos[i] += vel[i];
    
        if( pos[i].x < -ofGetWidth()/4 || pos[i].x > 1.25*ofGetWidth() ){
            vel[i].x *= -1;
        }
        
        if( pos[i].y < -ofGetWidth()/4 || pos[i].y > 1.25*ofGetHeight() ){
            vel[i].y *= -1;
        }
        
    }
        
}

//--------------------------------------------------------------
void testApp::draw(){
    mFbo.begin();
    
    // to prevent uncleared video memory!
    ofSetColor(255, 255, 255, 0);
    ofClear(255, 255, 255, 0);
    
    ofSetColor(255, 255, 255, 255);
  ofPushMatrix();{
        
        ofTranslate( pos[0] );
         ofSetRectMode( OF_RECTMODE_CENTER );
        ofRotate( ofGetElapsedTimef() * 90 );
        ofRect(0,0, 20, 20);

    
        ofSetRectMode( OF_RECTMODE_CORNER );
  }ofPopMatrix();
    mFbo.end();
    
//    mFbo.draw(0,0);
//    mFbo.draw(0,200);
//    mFbo.draw(200,200);
//    mFbo.draw(200,0);
    
    for(int i=0;i<numbo; i++){
        mFbo.draw(pos[i].x, pos[i].y);
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
