#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    ofBackground(0);
    
    speed=.0008f;
    fspeed=speed;
    accel=.5f;
    
    pos.x=100;
    pos.y=ofGetHeight()/2;
    
    fpos.x=ofGetWidth()/2-40;
    fpos.y=-20;
    
    lineA.x = 3*(ofGetWidth()/4);
    lineA.y = ofGetHeight()/4;
    lineB.x = 3*(ofGetWidth()/4);
    lineB.y = 3*(ofGetHeight()/4);

    
    
    ofEnableSmoothing();
    
}

//--------------------------------------------------------------
void testApp::update(){
    
    pos.y+=speed;
    if(pos.x>=ofGetWidth())pos.x=0;
    
    
    fpos.y+=fspeed;
    fspeed+=accel;
    if(fpos.y>ofGetHeight())fpos.y=-20;
    if(fspeed>783) accel=0;
    
    
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofSetColor(255);
    
    
    //Nonmoving
    ofRect(pos.x, pos.y, 20, 20);
    
    string pps = ofToString(speed*60) + " pixels per second";
    ofDrawBitmapString(pps, 0, 10);
    string ins = ofToString((speed*60)/110) + " inches per second";
    ofDrawBitmapString(ins, 0, 20);
    string mph = ofToString(((speed*60))/110*.0568181818)+ " miles per hour";
    ofDrawBitmapString(mph, 0, 30);
    string time = ofToString(ofGetWidth()/(speed*60)) + " seconds per lap";
    ofDrawBitmapString(time, 0, 50);
                             
    
    
    
    
    //Fastmoving
    ofRect(fpos.x,fpos.y,20,20);
    
    string fpps = ofToString(fspeed*60) + " pixels per second";
    ofDrawBitmapString(fpps, ofGetWidth()/2-100, 10);
    string fins = ofToString((fspeed*60)/110) + " inches per second";
    ofDrawBitmapString(fins, ofGetWidth()/2-100, 20);
    string fmph = ofToString(((fspeed*60))/110*.0568181818)+ " miles per hour";
    ofDrawBitmapString(fmph, ofGetWidth()/2-100, 30);
    string ftime = ofToString(ofGetHeight()/(fspeed*60)) + " seconds per lap";
    ofDrawBitmapString(ftime, ofGetWidth()/2-100, 50);
    
    
    
    //Line
    ofSetLineWidth(1);
    ofLine(lineA.x, lineA.y, lineB.x, lineB.y);
    ofDrawBitmapString("Left Click",lineA.x, lineA.y);
    ofDrawBitmapString("Right Click", lineB.x, lineB.y);
    
    

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
    
    if(button==0){
        lineA.x=mouseX;
        lineA.y=mouseY;
    }
    if(button==2){
        lineB.x=mouseX;
        lineB.y=mouseY;
    }
    

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
