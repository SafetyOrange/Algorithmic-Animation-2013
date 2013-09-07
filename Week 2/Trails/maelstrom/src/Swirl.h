//
//  Swirl.h
//  maelstrom
//
//  Created by Keion Anthony Marefat on 9/6/13.
//
//

#pragma once
#include "ofMain.h"


class Swirl{
    
public:
    void setup(float _r, float _s, char dir);
    void update();
    void draw();
    
    float x;
    float y;
    float r;
    float s;
    float d;
    float size;
    float i=0;
    
    ofColor c;
    
};