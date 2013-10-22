//Charlie's code (www.github.com/cwhitney)


//after a while this turns into a sort of tendril thing that looks 3d-ish.
// huge framerate issues though.

#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    myField.setup( ofGetWindowWidth(), ofGetWindowHeight(), 20 );
    
    particleList.clear();
    
    for( int i=0; i<300; i++ ){
        addParticle();
    }
    for(int i=0;i<300;i++){
        stars[i].set(ofRandomWidth(), ofRandomHeight());
    }
    ofBackground(0);
}

void testApp::addParticle() {
    Particle part;
    part.pos = ofVec2f( ofRandomWidth(), ofRandomHeight() );
    
    particleList.push_back( part );

}

//--------------------------------------------------------------
void testApp::update(){
    myField.update();
    
    for( int i=0; i<particleList.size(); i++ ){
        particleList[i].applyForce( myField.getForceAtPosition(particleList[i].pos ) * 0.005 );
        particleList[i].update();
        
        if(ofDist(particleList[i].pos.x, particleList[i].pos.y, mouseX, mouseY)<100){
            myField.addRepelForce(mouseX, mouseY, 20, 42);
            }
        }
    }

//--------------------------------------------------------------
void testApp::draw(){
    ofSetColor(255);
  //  myField.draw();
    
    ofSetColor(100, 75, 75);
    for( int i=0; i<particleList.size(); i++ ){
        particleList[i].draw();
    }
    
    for(int i=0;i<300;i++){
        ofSetColor(255);
        ofCircle(stars[i], 1);
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
