//
//  Particle.h
//  guiParticle
//
//  Created by Keion Anthony Marefat on 9/26/13.
//
//

#pragma once

#include "ofMain.h"

class Particle {
public:
    Particle();
    
    void update();
    void draw();
    
    void setParams( float px, float py, float vx, float vy );
    void addForce( ofVec2f force );
    void addDampingForce();
    void resetForces();
    
    ofVec2f pos;
    ofVec2f vel;
    ofVec2f frc;
    
    ofVec2f damping;  // could also be a ofVec2f

       float speed = .04f;
    
};