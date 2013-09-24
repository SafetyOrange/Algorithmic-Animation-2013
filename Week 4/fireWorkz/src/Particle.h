//
//  Particle.h
//  NoiseParticles
//
//  Created by Charlie Whitney on 9/18/13.
//
//

#pragma once

#include "ofMain.h"

class Particle {
public:
    Particle(){};
    void setup( ofVec3f rVel );
    void update();
    void draw();
    
    ofVec3f pos;
    ofVec3f vel;
    int age, lifespan;
    bool bIsDead;
    
    ofColor c;
};
