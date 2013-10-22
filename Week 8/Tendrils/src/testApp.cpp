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
        
        if(i!=particleList.size()-1){
        if(ofDist(particleList[i].pos.x, particleList[i].pos.y,particleList[i+1].pos.x, particleList[i+1].pos.y)<5){
            myField.addRepelForce(particleList[i].pos.x, particleList[i].pos.y, 2, 0.5);
        }else{
            myField.addAttractForce(mouseX, mouseY, 500, 1.0);
            }
        }
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    ofSetColor(255);
   // myField.draw();
    
    ofSetColor(255, 0, 0);
    for( int i=0; i<particleList.size(); i++ ){
        particleList[i].draw();
    }
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if( key == '1'){
        myField.setRandom( 20.0 );
    }else if( key == '2' ){
        myField.setPerlin();
    }else if( key == 'r' ){
        for( int i=0; i<particleList.size(); i++ ){
            particleList[i].pos = ofVec2f( ofRandomWidth(), ofRandomHeight() );
        }
    }
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
    mouseDragged(x, y, button);
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
