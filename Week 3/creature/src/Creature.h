//
//  Creature.h
//  creature
//
//  Created by Keion Anthony Marefat on 9/16/13.
//
//

#pragma once

#include "ofMain.h"

class Creature {
public:
    float xPos;
    float xSpeed;
    float yPos;
    float ySpeed;
    float bigness;
    ofColor fur;

    Creature();
    void update();
    void draw();
    
    float catchUpSpeed=.03f;
    

};