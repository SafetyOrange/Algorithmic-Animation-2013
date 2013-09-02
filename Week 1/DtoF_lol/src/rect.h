//
//  rect.h
//  DtoF_lol
//
//  Created by Keion Anthony Marefat on 9/1/13.
//
//

#pragma once
#include "ofMain.h"

class rectangle {
    
public:
	
    rectangle();
	
    void	draw();
    void    prime(int incr);
    void	xenoToPoint(float catchX, float catchY);
    void    chainToPoint(float catchX, float catchY);
	
    ofVec2f		pos;
    float		catchUpSpeed;		// take this pct of where I want to be, and 1-catchUpSpeed of my pos
	
    float displace = .03f;
    float sizer=1;
    ofColor c;
};
