#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync( true );
    ofSetBackgroundAuto(false);
    ofSetColor(0);
    ofRect(0,0, ofGetWidth(), ofGetHeight());
    
    gui = new ofxUICanvas;
    gui->addLabel("Particle Test");
    gui->addSpacer();
    gui->addButton("FIRE", false, 44, 44);
    
    gui->setColorBack(ofColor(0,100));
    gui->setWidgetColor(OFX_UI_WIDGET_COLOR_BACK, ofColor(255,100));
    gui->addSlider("Volume", 0, 4000, 1000);
    gui->addSlider("Power", 0, 20, 4);
    gui->addSlider("Damplitude", 0, .1f, .01f);
    gui->addToggle("WarpContainment", true, 20, 20);
    
    ofAddListener(gui->newGUIEvent,this,&testApp::onGuiEvent);
    
    circleRadius = 50.0;
    circleColor.set(255, 0, 255);
    
    for (int i = 0; i < 1000; i++){
        addParticle();
    }
}

void testApp::exit() {
    delete gui;
}

void testApp::onGuiEvent(ofxUIEventArgs &e) {
    
    
    string name = e.widget->getName();
	int kind = e.widget->getKind();
    
    if( name == "Power" ){
        ofxUISlider *mySlider = (ofxUISlider *)e.widget;
        spread = mySlider->getScaledValue();
        
    //    cout << "Got a message! " << name << " - " << mySlider->getValue() << endl;
    }else if( name == "FIRE"){
        
        ofxUIButton *myButton = (ofxUIButton *)e.widget;
        
        if(myButton->getValue() == 0){
            for (int i = 0; i < particleList.size(); i++){
                //		float vx = ofRandom(-4,4);
                //		float vy = ofRandom(-4,4);
                
                float circVal = ofRandom(TWO_PI);
                
                float vx = cos( circVal ) * ofRandom(0,spread);
                float vy = sin( circVal ) * ofRandom(0,spread);
                
                particleList[i].setParams(ofGetWidth()/2,ofGetHeight()/2,vx, vy);
                
            }
        }
    }
    else if( name == "WarpContainment"){
        
        ofxUIToggle *myToggle = (ofxUIToggle *)e.widget;
        
        bg = myToggle->getValue();
    }

    
    else if( name == "Damplitude"){
        
        ofxUISlider *mySlider = (ofxUISlider *)e.widget;
        for (int i = 0; i < particleList.size(); i++){
            particleList[i].speed = mySlider->getScaledValue();
        }
        
    }
    
    else if( name == "Volume"){
        
        ofxUISlider *mySlider = (ofxUISlider *)e.widget;
        if(particleList.size()>mySlider->getScaledValue()){
            for(int i=0; i<(particleList.size()-mySlider->getScaledValue()); i++){
                particleList.pop_back();
            }
        }
        if(particleList.size()<mySlider->getScaledValue()){
            for(int i=0; i<(mySlider->getScaledValue()-particleList.size()); i++){
                addParticle();
            }
        }
        
    }
    
    
    //    cout << "Got a message! " << name  << " - " << kind << endl;
}


//--------------------------------------------------------------
void testApp::update(){
    
    for (int i=0; i < particleList.size(); i++){
		particleList[i].resetForces();
        //		particleList[i].addForce( ofVec2f(0,0.04));  // gravity
		particleList[i].addDampingForce();
		particleList[i].update();
	}

}
//--------------------------------------------------------------
void testApp::addParticle() {
    Particle myParticle;
    
    float vx = ofRandom(-10,10);
    float vy = ofRandom(-10,10);
    myParticle.setParams(ofGetWidth()/2,ofGetHeight()/2,vx, vy);
    
    // more interesting with diversity :)
    // uncomment this:
    //		myParticle.damping = ofRandom(0.01, 0.05);
    particleList.push_back(myParticle);
}


//--------------------------------------------------------------
void testApp::draw(){
    
    if(bg==true){
        ofSetColor(0);
        ofRect(0,0,ofGetWidth(),ofGetHeight());
    }
    
    ofSetColor(255);
    for (int i=0; i < particleList.size(); i++){
        particleList[i].draw();
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
