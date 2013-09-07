//
//  text.h
//  coolTrails
//
//  Created by Keion Anthony Marefat on 9/6/13.
//
//




#pragma once
#include "ofMain.h"

class Text{
public:
void update();
void draw();
void setup();

    ofVec2f pos;
    
    
float fallSpeed=ofRandom(1,3);

};