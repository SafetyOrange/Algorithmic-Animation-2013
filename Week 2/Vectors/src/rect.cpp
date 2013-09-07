//
//  rect.cpp
//  DtoF_lol
//
//  Created by Keion Anthony Marefat on 9/1/13.
//
//

#include "rect.h"


//------------------------------------------------------------------
rectangle::rectangle(){
	
    
    pos.x = ofRandom(ofGetWidth());
    pos.y = ofRandom(ofGetHeight());

}

//------------------------------------------------------------------

void rectangle::prime(int incr){
    
    catchUpSpeed = .09f+(incr*-.007f);
    pos.x = ofRandom(ofGetWidth());
    pos.y = ofRandom(ofGetHeight());


}


//------------------------------------------------------------------

void rectangle::draw() {
	ofFill();
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofSetColor(c);
    ofRect(pos.x, pos.y, sizer, sizer);
}

//------------------------------------------------------------------
void rectangle::xenoToPoint(ofVec2f point){
    pos = catchUpSpeed*point + (1-catchUpSpeed)*pos;
    
//    float daX= catchUpSpeed * catchX + (1-catchUpSpeed) * pos.x;
//    float daY= catchUpSpeed * catchY + (1-catchUpSpeed) * pos.y;

//	pos.x = daX;
//	pos.y = daY;
    
    float temp = ofMap(ofDist(pos.x, pos.y, point.x,point.y), 0, 500, 0, 255); //Map distance to color
    sizer = ofMap(ofDist(pos.x, pos.y, point.x, point.y), 0, 450, 50, 10);      //Map distance to size
    
    c = ofColor(temp, 0, 255-temp);
    
}
//------------------------------------------------------------------
void rectangle::chainToPoint(ofVec2f point){
//    float daX= catchUpSpeed * catchX + (1-catchUpSpeed) * pos.x;
//    float daY= catchUpSpeed * catchY + (1-catchUpSpeed) * pos.y;
//    
//	pos.x = daX;
//	pos.y = daY;
    
     pos = catchUpSpeed*point + (1-catchUpSpeed)*pos;
    
    float temp = ofMap(ofDist(pos.x, pos.y, ofGetMouseX(), ofGetMouseY()), 0, ofGetWidth(), 0, 255);
    sizer = ofMap(ofDist(pos.x, pos.y, point.x, point.y), 0, ofGetWidth(), 50, 10);
    
    c = ofColor(temp, 0, 255-temp);
    
}
