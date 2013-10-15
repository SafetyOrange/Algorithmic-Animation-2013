#include "testApp.h"

//??WHAT IS THIS PLACE

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync(true);
    ofSetBackgroundAuto(false);
    ofBackground(0);
    ofEnableAlphaBlending();
    
    jam.loadSound("song.mp3");
    
    // Particles
    steps = 13;
    strength = 1;
    size = 300;
    
    now = ofGetElapsedTimeMillis();
    target = ofGetElapsedTimeMillis() + ofRandom(500);
    
    for(int i = 0; i < 100; i++){
        Particle p;
        particleList.push_back(p);
    }
    
    // UI
    gui = new ofxUICanvas;
    
    gui->setColorBack(ofColor(255, 100));
    gui->setWidgetColor(OFX_UI_WIDGET_COLOR_BACK, ofColor(255, 100));
    gui->addSlider("Dopeness", 1, 10, 6);
    gui->addSlider("Catharsis", 0, 50, strength);
    gui->addSlider("Safety", 0, 1000000000, 1000000000);
    gui->addButton("WHAT AM I", true);
    gui->addSpacer("LOLOL");
    gui->addSpacer("LOLOL");
    gui->addSpacer("LOLOL");
    gui->addTextArea("TEST", "EASYCAM ENABLED. YOU ARE NOW IN 3D SPACE?");
    
    ofAddListener(gui->newGUIEvent, this, &testApp::onGuiEvent);
    jam.play();
    ofSetColor(255);
        ofDrawBitmapString("You are now in 3D space.", ofGetWidth()/2, ofGetHeight()/2);
}

//--------------------------------------------------------------
void testApp::exit(){
    delete gui;
}

//--------------------------------------------------------------
void testApp::onGuiEvent(ofxUIEventArgs &e){
    if( e.getName() == "Steps" ){                                       //THESE ARENT EVEN USED LOLWUT
        ofxUISlider *stepsSlider = (ofxUISlider *)e.widget;
        steps = stepsSlider->getScaledValue();
    }
    if( e.getName() == "Strength" ){
        ofxUISlider *strengthSlider = (ofxUISlider *)e.widget;
        strength = strengthSlider->getScaledValue();
    }
    if( e.getName() == "Size" ){
        ofxUISlider *sizeSlider = (ofxUISlider *)e.widget;
        size = sizeSlider->getScaledValue();
    }
}

//--------------------------------------------------------------
void testApp::update(){
    for(int i = 0; i < particleList.size(); i++){
        particleList[i].update(steps, strength, size);
    }
    
    if(ofGetElapsedTimeMillis() > target){
        strength = ofRandom(0, 25);
        now = ofGetElapsedTimeMillis();
        target = ofGetElapsedTimeMillis() + ofRandom(500);
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofBackgroundGradient(ofColor(0, 1), ofColor(0, 1), OF_GRADIENT_CIRCULAR);
    
    ofSetColor(0);
    ofFill();
    ofRect(0, 0, 210, 210);
    
    cam.begin();
    for(int i = 0; i < particleList.size(); i++){
        particleList[i].draw();
    }
    cam.end();
    
    if(ofGetElapsedTimeMillis()>60250){
        for(int i = 0; i<10; i++){
        ofLog() << "HAD TO QUIT. TOO MUCH FAIL. PLEASE KILL ME." << endl;
        }
        exit();
    }
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if(key == 'c'){
        ofClear(0);
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
    
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

//    if(msg=="Fucking help me; I'm trapped in a computer"){
//        beam.rematerialze(Flynn);
//    }
    
}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){
    
}
