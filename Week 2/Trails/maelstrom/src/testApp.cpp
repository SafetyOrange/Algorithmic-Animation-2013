#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofEnableAlphaBlending();
    ofSetBackgroundAuto(false);
    ofEnableSmoothing();
    
    char derp;
    
    int temp=int(ofRandom(0,1));
    if(temp==0){
         derp = 'l';
    } else  derp = 'r';
    
    for(int i=0; i<numSwirls; i++){
        float s= ofMap(i, 0, numSwirls-1, .01, .09);
        
        int temp=ofRandom(0,1);
        if(temp==0){
            derp = 'l';
        } else  derp = 'r';
        if(i==numSwirls-1) swirls[i].setup(1+i*metaR/numSwirls,s,derp);
        else swirls[i].setup(i*metaR/numSwirls,s,derp);
    }

}

//--------------------------------------------------------------
void testApp::update(){
    
    for(int i=numSwirls; i>0; i--){
        swirls[i].update();
    }


}

//--------------------------------------------------------------
void testApp::draw(){
    ofSetColor(0, 0, 0, 50);
    ofRect(0,0,ofGetWidth(),ofGetHeight());
    
    for(int i=0; i<numSwirls; i++){
        swirls[i].draw();
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
