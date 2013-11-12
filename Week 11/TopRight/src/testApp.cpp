#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    
    mReceiver.setup( 12345 );
    mSender.setup( "localhost", 12346 );
    mSender2.setup( "localhost", 12347 );
    mSender3.setup( "localhost", 12348 );
    
    pos.set( ofGetWindowSize() /2 );
    mousePos.set( ofGetWindowSize() /2 );
    
    ofSetWindowPosition(ofGetScreenWidth()-ofGetWindowWidth(), 0);
    
    ofBackground(0);
}

//--------------------------------------------------------------
void testApp::update(){
    checkOsc();
    
    pos += vel;
    
    if( pos.x < 0 ){ pos.x = ofGetWindowWidth()*2; }
    else if( pos.x > ofGetWindowWidth()*2 ){ pos.x = 0; }
    
    if( pos.y < 0 ){ pos.y = ofGetWindowHeight()*2; }
    else if( pos.y > ofGetWindowHeight()*2 ){ pos.y = 0; }
    
    vel *= 0.97;
    
    // send out bg color information
    ofxOscMessage m;
    m.setAddress("/bgColor");
    m.addIntArg( bgColor );
    mSender.sendMessage(m);
    mSender2.sendMessage(m);
    mSender3.sendMessage(m);
    
    // send ball position
    ofxOscMessage mPos;
    mPos.setAddress("/ball/pos");
    mPos.addFloatArg( pos.x );
    mPos.addFloatArg( pos.y );
    mSender.sendMessage(mPos);
    mSender2.sendMessage(mPos);
    mSender3.sendMessage(mPos);
}

void testApp::checkOsc() {
    
	// check for waiting messages
	while(mReceiver.hasWaitingMessages()){
		// get the next message
		ofxOscMessage m;
		mReceiver.getNextMessage(&m);
        
        string addr = m.getAddress();
        
        if( addr == "/mouse/pos" ){
            int xPos = m.getArgAsInt32(0);
            int yPos = m.getArgAsInt32(1);
            
//            mousePos.set( xPos, yPos );
        }else if( addr == "/vel" ){
            cout << "got vel" << endl;
            
            int xVel = m.getArgAsFloat(0);
            int yVel = m.getArgAsFloat(1);
            
            vel.set( xVel, yVel );
        }else if( addr == "/bgColor" ){
            float bg = m.getArgAsFloat(0);
            bgColor = floor(bg * 255.0);
            
            ofBackground( bgColor );
        }
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    ofCircle( pos, 20 );
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