//Collaboration with Michael Kahane (www.github.com/lordofcorners)


#include "testApp.h"
#include "ofMain.h"
#include "rect.h"

//--------------------------------------------------------------
void testApp::setup(){	
	
    for(int i=0;i<numDudes;i++){
        dudes[i].prime(i+1);
    }
    
}

//--------------------------------------------------------------
void testApp::update(){
	
    mousePos = ofVec2f(mouseX,mouseY);
}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofBackground(0);
    
    ofSetColor(255);
    ofDrawBitmapString("Press X for Xeno.", 0, 10);
    ofDrawBitmapString("Press C for Chain.", 0, 30);
    ofDrawBitmapString("Click to scatter.", 0, 50);

    if(xeno==true){
        for(int i=0;i<numDudes;i++){
            dudes[i].xenoToPoint(mousePos);
        }
    }
    
    
    if(chain){
        dudes[0].chainToPoint(mousePos);
        for(int i=numDudes-1;i>0;i--){
            dudes[i].chainToPoint(ofVec2f(dudes[i-1].pos.x, dudes[i-1].pos.y));
            dudes[i-1].c = dudes[i].c;

        }
        
    }
    
    for(int i=0;i<numDudes;i++){
        dudes[i].draw();
    }
    
}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){
    if(key=='x'){
        xeno=true;
    }
    if(key=='c'){
        chain=true;
    }
}

//--------------------------------------------------------------
void testApp::keyReleased  (int key){
    if(key=='x'){
        xeno=false;
    }
    if(key=='c'){
        chain=false;
    }
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    
    
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    
    for(int i=0;i<numDudes;i++){
        dudes[i].prime(i+1);
    }
    
    
}
