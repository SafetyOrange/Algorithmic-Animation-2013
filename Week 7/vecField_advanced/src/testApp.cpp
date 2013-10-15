#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    myField.setup( ofGetWindowWidth(), ofGetWindowHeight(), 20 );
    
        
    ofBackground(0);
    
    settings.loadFile("settings.xml");
    int temp = settings.getValue("num",0);
    switch(temp){
        case 0:
            break;
        case 1:
            myField.setRandom(20.0);
            break;
        case 2:
            myField.setPerlin();
            break;
        case 3:
            myField.setSin(10);
            break;
        case 4:
            myField.setMouse(10);
            break;
    }
    
    ofLog()<< settings.getValue("settings:num", 0) << endl;
}

//--------------------------------------------------------------
void testApp::update(){
    myField.update();
}

//--------------------------------------------------------------
void testApp::draw(){
    myField.draw();
    ofDrawBitmapStringHighlight("Hold 3 for flipbook pendulum /n Hit 4 for ...something", 550, 10);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if( key == '1'){
        myField.setRandom( 20.0 );
        settings.setValue("num", 1);
    }else if( key == '2' ){
        myField.setPerlin();
        settings.setValue("num", 2);
    }else if( key == '3' ){
        myField.setSin(10);
        settings.setValue("num", 3);
    }else if( key == '4' ){
        myField.setMouse(10);
        settings.setValue("num", 4);
    }
    settings.saveFile("settings.xml");

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    
    
    if( button == OF_MOUSE_BUTTON_1 ){
//        myField.addRepelForce(x, y, 100, 2.0);
        myField.addCircularForce(x, y, 300, 2.0);
    }else{
        myField.addAttractForce(x, y, 100, 2.0);
    }
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    mouseDragged(x, y, button);
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
