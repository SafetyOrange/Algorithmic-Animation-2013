
//BROKEN FROM WHAT WAS ONCE ART BY MIRTE BECKER
//https://github.com/mirtebecker/becker_algo2013/tree/master/w6_homework_ParticleSinCos

#pragma once

#include "ofMain.h"
#include "ofxUI.h"
#include "Particle.h"

class testApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    // ofxUI
    void exit();
    void onGuiEvent(ofxUIEventArgs &e);
    ofxUICanvas *gui;
    
    // Particles
    vector<Particle> particleList;
    int now, target;
    float steps, strength, size;
    
    ofSoundPlayer jam;
    ofEasyCam cam;

};