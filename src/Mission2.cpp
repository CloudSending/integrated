//
//  Mission2.cpp
//  cloudSending
//
//  Created by NAOYAIWAMOTO on 2014/03/05.
//
//

#include "Mission2.h"

void Mission2::setup()
{
    // initialize
    vel = 20;
    _count = 2;
    p.set(250, 900);
    pp.set(ofGetWidth()/2, 0);
    x = 0;
    xx = 0;
    
    // image
    img = new ofImage [5];
    for(int i=0; i<5; i++){
        string filename = "Mission2/img/" + ofToString(i) + ".png";
        img[i].loadImage(filename);
    }
    
    flight.loadImage("Mission2/img/flight2.png");
}

void Mission2::update()
{

}

void Mission2::draw()
{
    // image
    ofSetColor(255);
    img[_count].resize(ofGetWidth(), ofGetHeight());
    img[_count].draw(0.0, 0.0);
    
    ofSetColor(255, 102, 102);
    if(_count == 0 && pp.y < ofGetHeight())
    {
        //x++;
        pp.y += vel;
        ofBeginShape();
        ofVertex(0, ofGetHeight());
        ofVertex(0,0);
        ofVertex(pp.x, pp.y);
        ofVertex(ofGetWidth(),0);
        ofVertex(ofGetWidth(), ofGetHeight());
        ofEndShape();
        flight.resize(120, 120);
        ofSetColor(255);
        
        ofEnableAlphaBlending();
        flight.draw(ofGetWidth()/2-60, pp.y);
        ofDisableAlphaBlending();
        
        //x = 0;
    }else if(_count == 0){
        x+=7;
        pp.y += vel;
        ofBeginShape();
        ofVertex(0, ofGetHeight());
        ofVertex(-x,0);
        ofVertex(pp.x, pp.y);
        ofVertex(ofGetWidth()+x,0);
        ofVertex(ofGetWidth(), ofGetHeight());
        ofEndShape();
    }
}

void Mission2::mousePressed(int x, int y, int button)
{
	changeState("Print");
}

string Mission2::getName()
{
	return "Mission2";
}

void Mission2::keyPressed(int key){
    switch (key) {
        case ' ':
            _count++;
            if(_count == 5){
                _count = 0;
            }
            break;
            
        default:
            break;
    }
}
