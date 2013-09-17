//
//  Creature.cpp
//  creature
//
//  Created by Keion Anthony Marefat on 9/16/13.
//
//

#include "Creature.h"

    
Creature::Creature() {
        ofSetCircleResolution(100);
    ofEnableSmoothing();
        xPos=ofRandom(ofGetWidth());
        xSpeed=(ofRandom(-3, 3));
        yPos=ofRandom(ofGetHeight());
        ySpeed=(ofRandom(-3, 3));
        bigness=3;
    fur = ofColor(110,35,0);
    }

    void Creature::update() {

            
            //The body. Position determined here
        
        bigness=3.2;
        ofSetColor(0);
        ofEllipse(xPos, yPos, bigness*50, bigness*50);
        bigness=3;
        ofSetLineWidth(5);
        ofSetColor(fur);
        ofEllipse(xPos, yPos, bigness*50, bigness*50);
            
            // The eyeball
       //     bigness=3.2;
         //   ofSetColor(0);
        
        
        float cosOfTime=cos(ofGetElapsedTimef()*1);
        float blink = ofMap(cosOfTime, -1, 1, bigness*10, 3);
        
     //       ofEllipse(xPos-(bigness*4), yPos-(bigness*2), bigness*25, bigness*10);
            bigness=3;
            ofSetColor(255);
            ofEllipse(xPos-(bigness*4), yPos-(bigness*2), bigness*25, blink);
            
            //The pupil
            ofSetColor(0);
            ofEllipse(xPos-(bigness*5), yPos-(bigness+bigness*.5), bigness*5, blink/2);
            
            //The mouth
            ofLine(xPos-(bigness*16), yPos+(bigness*10), xPos+(bigness*11), yPos+(bigness*10));
            
            
            
            
            //MOVEMENT

        xPos = catchUpSpeed * ofGetMouseX() + (1-catchUpSpeed) * xPos;
        yPos = catchUpSpeed * ofGetMouseY() + (1-catchUpSpeed) * yPos;
        
        float cosOfTime2=cos(ofGetElapsedTimef()*2.4);
        
        yPos=ofMap(cosOfTime2, -1, 1, yPos-2, yPos+2);
        
    }
