//
//  Swirl.cpp
//  maelstrom
//
//  Created by Keion Anthony Marefat on 9/6/13.
//
//

#include "Swirl.h"


void Swirl::setup(float _r, float _s, char dir){
    r=_r;
    s=_s;
    
    if(dir=='l') s*=-1;
    
    int temp = ofRandom(255);
    c=ofColor(temp,temp,255,100);
    
    size=s*2000;
    
}
void Swirl::update(){
    

}
void Swirl::draw(){
    
    ofSetColor(c);
    
    x=r*cos(i)+ofGetWidth()/2;
    y=r*sin(i)+ofGetHeight()/2;
    
    ofEllipse(x, y, size, size);

    i+=s;
    if(i>2*PI) i=0;
    

    
}