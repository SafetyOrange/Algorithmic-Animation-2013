#pragma once

#include "ofMain.h"
#include "rect.h"

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
    
    bool xeno;
    bool chain;
    
    int numDudes = 10;
    rectangle dudes[10];
		
};
