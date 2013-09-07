//
//  Ball.cpp
//  bouncingBall
//
//  Created by Keion Anthony Marefat on 9/3/13.
//
//

#include "Ball.h"
#include "ofMain.h"


Ball::Ball(){
    
    ofSeedRandom();
    vel.x=ofRandom(0.0,1.0f);
    vel.y=ofRandom(0.0f,1.0f);
    
    pos.x=ofGetWidth()/2;
    pos.y=200;
    
    ofLog()<< vel.x;
    
}

void Ball::setup(float grav, float _ratio){
    
    gravity = (grav*2.794)/60;
    ratioToEarth=_ratio;
    
    //110 PPI = 2.794 PPM @ 60FPS
    //That's accuracy, son
}

void Ball::update(){
    
    pos.x+=vel.x*10;
    pos.y+=vel.y;
    
    vel.y+=gravity;
    
    if(pos.x>= ofGetWidth()-(15*ratioToEarth) || pos.x <=15*ratioToEarth){
        vel.x*=-.8;
        if(pos.x>= ofGetWidth()-(15*ratioToEarth)){
            pos.x=ofGetWidth()-(16*ratioToEarth);
        }
        if(pos.x <=15*ratioToEarth){
            pos.x=(16*ratioToEarth);
        }
    }

    if(pos.y+(15*ratioToEarth)>=ofGetHeight()){
        pos.y=ofGetHeight()-(17*ratioToEarth);
        vel.y*=-.8;        
    }
    if(pos.y-(15*ratioToEarth)<=0){
        pos.y=(17*ratioToEarth);
        vel.y*=-.8;
    }

}


void Ball::draw(char planet){
    
    
    if(planet=='j') ofSetColor(160, 130, 100);
    if(planet=='e') ofSetColor(0, 0, 200);
    if(planet=='m') ofSetColor(100, 100, 100);
    
    ofCircle(pos.x, pos.y, earthDiam*ratioToEarth);
    
    
    
}