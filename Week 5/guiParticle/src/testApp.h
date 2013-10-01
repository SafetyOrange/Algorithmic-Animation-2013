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
    
    void addParticle();
    
    void onGuiEvent( ofxUIEventArgs &e );
    void exit();
    
    ofxUICanvas *gui;
    float       circleRadius;
    ofColor     circleColor;
    float spread = 7;
    
    vector<Particle>    particleList;
    
    bool bg = true;
};
