//
//  Text.h
//  jw
//
//  Created by Keion Anthony Marefat on 9/17/13.
//
//

#pragma once
#include "ofMain.h"

class Text{
public:
    void prime(ofColor _c);
    void draw();
    void update();
    
    float x;
    float y;
    
    ofColor c;
    
    char type;
    
    bool done = false;
    
    ofTrueTypeFont font;
    
    float speed =1;
};