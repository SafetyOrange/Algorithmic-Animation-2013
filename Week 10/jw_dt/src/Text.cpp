//
//  Text.cpp
//  jw
//
//  Created by Keion Anthony Marefat on 9/17/13.
//
//

#include "Text.h"


void Text::prime(ofColor _c){
    c=_c;
    if(c==ofColor(0,0,255)) {
        type='b';
        c=ofColor(0, 0, 255, 255);
        x=1.15*ofGetWidth()/2;
        y=.9*ofGetHeight()/4;
    }
    
    if(c==ofColor(0,255,0)) {
        type='g';
        c=ofColor(0, 255, 0, 255);
        x= 20;
        y=.9*ofGetHeight()/4;
    }
    
    if(c==ofColor(255,0,0)) {
        type='r';
        c=ofColor(255, 0, 0, 255);
        x=1.2*ofGetWidth()/4;
        y=3.3*ofGetHeight()/4;
    }
    font.loadFont("1.ttf", 36,true,false,true);
    
    
}
void Text::draw(){
    
    ofSetColor(c);
    
    if(x>ofGetWidth()/2 && y>ofGetHeight()/2 && ofDist(ofGetMouseX(),ofGetMouseY(),x,y)>500){
        font.drawStringAsShapes("LOL BYE", x, y);
    } else {
        font.drawStringAsShapes("JOHN WHITNEY", x, y);
    }
    
    
    
}
    

void Text::update(float dt){
    
    if(x>1.2*ofGetWidth()/4)x-=1.05*speed*dt*50;
    if(x<1.2*ofGetWidth()/4)x+=1.05*speed*dt*50;
    if(y>1.05*ofGetHeight()/2)y-=.85*speed*dt*50;
    if(y<1.05*ofGetHeight()/2)y+=.85*speed*dt*50;
    
    
}