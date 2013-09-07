//
//  text.cpp
//  coolTrails
//
//  Created by Keion Anthony Marefat on 9/6/13.
//
//

#include "text.h"


void Text::setup(){
    pos.x=ofRandom(ofGetWidth());
    pos.y=ofRandom(-10,0);
    
    
}

void Text:: update(){
    
    pos.y+=fallSpeed;
    
    if (pos.y>ofGetHeight()) {
        pos.y=-10;
    }
}
void Text:: draw(){
    
    ofDrawBitmapString(ofToString(int(ofRandom(100))), pos.x, pos.y);
    
}