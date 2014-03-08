//
//  Mission1.cpp
//  cloudSending
//
//  Created by NAOYAIWAMOTO on 2014/03/05.
//
//

#include "Mission1.h"


void Mission1::setup()
{
    // img
    img.loadImage("Mission1/img/1.png");
    flight.loadImage("Mission1/img/flight.png");
    flight2.loadImage("Mission1/img/flight2.png");
    
    // Animation
    p.set(250, 900);
    pp.set(ofGetWidth()/2, 0);
    x = 0;
    xx = 0;
}

void Mission1::update()
{
    if(timePast){
        p.y -= 20;
    }
}

void Mission1::draw()
{
    ofSetColor(255);
    img.resize(ofGetWidth(), ofGetHeight());
    img.draw(0, 0);

    // set a timer
    if (ofGetElapsedTimeMillis() - getSharedData().lastUpdate > 1000){
        getSharedData().counter++;
        getSharedData().lastUpdate = ofGetElapsedTimeMillis();
        if (getSharedData().counter > 2) {
            timePast = true;
        }
    }
    
    if(timePast){
        ofEnableAlphaBlending();
        flight.draw(p.x, p.y);
        ofDisableAlphaBlending();
        
        ofSetColor(255, 102, 102);
        if(p.y < -2000){
            timePast = false;
            changeState("Mission2");
        } else if(p.y > 0){
            ofTriangle(p.x+47, p.y+90, 0, ofGetHeight(), ofGetWidth(), ofGetHeight());
        }else{
            x+=5;
            ofTriangle(p.x+47, p.y+90, -x, ofGetHeight(), ofGetWidth()+x, ofGetHeight());
        }
    }

}

void Mission1::mousePressed(int x, int y, int button)
{
	changeState("Mission2");
}

string Mission1::getName()
{
	return "Mission1";
}