//CODE DONE MY BOY CWHITNEY
//www.github.com/cwhitney


#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    mReceiver.setup( 12348 );
    
    ofSetWindowPosition(ofGetScreenWidth()-ofGetWindowWidth(), ofGetScreenHeight()-ofGetWindowHeight());
}

//--------------------------------------------------------------
void testApp::update(){
    checkOsc();
}

void testApp::checkOsc() {

	while(mReceiver.hasWaitingMessages()){
		ofxOscMessage m;
		mReceiver.getNextMessage(&m);
        
        string addr = m.getAddress();
        
        if( addr == "/bgColor" ){
            float bg = m.getArgAsInt32(0);
            ofBackground( bg );
        }else if( addr == "/ball/pos" ){
            receivedPos.set( m.getArgAsFloat(0), m.getArgAsFloat(1) );
        }
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    ofPushMatrix();
        ofTranslate( 0, -ofGetWindowHeight());
        ofCircle( receivedPos, 20 );
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
