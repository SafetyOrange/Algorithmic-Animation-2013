
// Code by Charlie Whitney (www.github.com/cwhitney)
#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSeedRandom();

    ofSetVerticalSync(true);
    ofSetFrameRate(60);

    pos = ofGetWindowSize() / 2;
    dest.push_back(ofVec2f( ofRandomWidth(), ofRandomHeight() ));

    Particle doop;
    
    doop.setParams( pos, ofVec2f(10, -5) );
    
    carz.push_back(doop);

    ofBackground(0);
}

//--------------------------------------------------------------
void testApp::update(){
    
    for(int i=0;i<carz.size();i++){
        carz[i].seek( dest[i] );
        carz[i].update();
        
        if( carz[i].pos.distance(dest[i]) < 5){
            dest[i] = ofVec2f( ofRandomWidth(), ofRandomHeight() );
        }
    
    if(carz.size()>1){
        
        for(int j=i+1; j<carz.size();j++){
            if(i==carz.size()-1) j=0;
        if(ofDist(carz[i].pos.x, carz[i].pos.y, carz[j].pos.x, carz[j].pos.y)<50){
                carz[i].vel*=-1;
                carz[j].vel*=-1;
            
                dest[i]=ofVec2f( ofRandomWidth(), ofRandomHeight() );
                dest[j]=ofVec2f( ofRandomWidth(), ofRandomHeight() );
            }
        }
        }
        
    }
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofDrawBitmapString("Press any key to spawn car.\nWait until car is deployed to do again.", 20, 20);
    
    for(int i=0;i<carz.size();i++){
        ofSetColor(255);
        carz[i].draw();
        
        ofSetColor(255,0,0);
        ofCircle( dest[i], 4 );
    }

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
    Particle derp;
    dest.push_back(ofVec2f( ofRandomWidth(), ofRandomHeight() )) ;
    
    derp.setParams( ofVec2f(0,0), ofVec2f(10, -5) );
    
    carz.push_back(derp);

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
