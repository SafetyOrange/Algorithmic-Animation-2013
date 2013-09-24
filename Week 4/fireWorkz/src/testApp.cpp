#include "testApp.h"



//Code mostly by Charlie Whitney (github.com/cwhitney)
//Flowery design idea by Michael Kahane (github.com/lordofcorners)

//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(0);
    ofSetVerticalSync(true);
    ofSetBackgroundAuto(false);
    ofSetFrameRate(60);

}

//--------------------------------------------------------------
void testApp::update(){

    // This is how you loop through and delete a particle using iterators and vectors
    // Note how we don't put it++ up in the top of the loop.
    for( vector<Particle>::iterator it=pList.begin(); it!=pList.end(); ){
        it->update();

        if( it->bIsDead ){
            it = pList.erase(it);   // When we erase one, it returns the next particle automatically.  It's done the "it++" for us!
            ofLog( OF_LOG_NOTICE, "size is " + ofToString(pList.size()) );
        }else {
            it++;
        }
    }
    if(time<ofGetElapsedTimef()-ofRandom(.7, 6)){
        ofVec3f tmp;
        tmp=ofVec3f(ofRandom(-500, 500), ofRandom(0, 500), ofRandom(-500,500));
        ofColor tmp2;
        tmp2 = ofColor(ofRandom(255), ofRandom(255), ofRandom(255));
        
        for( int i=0; i<150; i++ ){
            addParticle(tmp, tmp2);
        }
        
        time=ofGetElapsedTimef();
    }
    
}

//--------------------------------------------------------------
void testApp::draw(){
    ofSetColor(255);
    ofDrawBitmapString("EasyCam enabled. You are now in 3D Space.", 10, 20);
    cam.begin();
    for( vector<Particle>::iterator it = pList.begin(); it!=pList.end(); it++){
        it->draw();
    }
    cam.end();
}

void testApp::addParticle(ofVec3f place, ofColor color){
    Particle p;
    
    // we'll pick a random direction for our particle to move initially
    ofVec3f rVel = ofVec3f( ofRandom(1.0), ofRandom(1.0), ofRandom(1.0) ) * 10.0 - 5.0;
    p.setup( rVel );
    p.pos = place;
    p.c= color;
    pList.push_back( p );
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
