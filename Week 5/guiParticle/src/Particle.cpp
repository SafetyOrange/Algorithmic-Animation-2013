//
//  Particle.cpp
//  guiParticle
//
//  Created by Keion Anthony Marefat on 9/26/13.
//
//

#include "Particle.h"

Particle::Particle() {
    setParams(0,0,0,0);
    damping = ofVec2f( 0.01f ) - ofVec2f(speed);
}

void Particle::setParams( float px, float py, float vx, float vy ){
    pos.set( px, py );
    vel.set( vx, vy );
    damping = ofVec2f(speed);

}

void Particle::addForce( ofVec2f force ){
    frc += force;
}

void Particle::addDampingForce() {
    frc = frc - vel * damping;
}

void Particle::resetForces() {
    frc.set(0,0);
}

void Particle::update() {
    vel = vel + frc;
    pos = pos + vel;
}

void Particle::draw() {
    ofCircle(pos.x, pos.y, 3);
}