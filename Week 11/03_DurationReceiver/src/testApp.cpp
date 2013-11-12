#include "testApp.h"



/**
 *  This app is set up to receive a 'bangs' track from Duration.  It simply makes a flash of light when it gets a signal.
 *  By CWhitney (www.github.com/cwhitney)
 */

//--------------------------------------------------------------
void testApp::setup(){
    pos.set(ofNoise(1),20);
    mReceiver.setup(12345);

    ofBackground(0);
}

//--------------------------------------------------------------
void testApp::update(){
    checkOsc();
    
    if(pos.x>=ofGetWidth()-20){
        pos.y+=50;
        pos.x=ofNoise(1);
    }
    if(pos.y>=ofGetHeight()-20){
        pos.set(ofNoise(1),20);
    }
}

void testApp::checkOsc() {
    
	while(mReceiver.hasWaitingMessages()){
        
		ofxOscMessage m;
		mReceiver.getNextMessage(&m);
        string addr = m.getAddress();
        
        cout << "got a message " << addr << endl;
        
        if( addr == "/bangs" ){
            cirList.push_back(pos);
        }
        if( addr == "/bangs_0" ){
            pos.x+=50;
        }
        
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    ofBackground( floor( bgColor ) );
    ofSetColor(255,0,0);
    ofCircle(pos, 20);
    
    for(int i=0;i<cirList.size();i++){
        ofSetColor(255);
        ofCircle(cirList[i], 20);
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
