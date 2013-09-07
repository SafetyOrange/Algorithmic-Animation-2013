//
//  Ball.h
//  bouncingBall
//
//  Created by Keion Anthony Marefat on 9/3/13.
//
//

#pragma once
#include "ofMain.h"

class Ball {
    
public:
    Ball();
    
    void setup(float grav, float _ratio);
    void update();
    void draw(char planet);
    
    ofVec2f pos;
    ofVec2f vel;
    float gravity;
    
    float ratioToEarth;
    float earthDiam = 20;

    
};