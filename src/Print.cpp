//
//  Print.cpp
//  cloudSending
//
//  Created by NAOYAIWAMOTO on 2014/03/05.
//
//

#include "Print.h"

void Print::setup()
{
    // image
    bg1.loadImage("Print/img/top.png");
    bg2.loadImage("Print/img/under.png");
    reciept.loadImage("Print/img/reciept.png");
    
    // Animation
    ofxAnimatableFloat f;
	f.animateFromTo( 0, 150 ); //suitcase
	f.setDuration(2);
	//f.setRepeatType( LOOP_BACK_AND_FORTH );
	f.setRepeatType( LOOP ); //PLAY_ONCE
    pos = f;
    curve = (AnimCurve) (EASE_IN_EASE_OUT);
    pos.setCurve( curve );
    curveNames = ofxAnimatable::getCurveName( curve );
}

void Print::update()
{
    float dt = 1.0f / ofGetFrameRate();
    pos.update( dt );
}

void Print::draw()
{
    ofSetColor(255);
    bg2.resize(ofGetWidth(), 600);
    bg1.resize(ofGetWidth(), 500);
    reciept.resize(250, 400+pos.val());

    ofEnableAlphaBlending();
    bg2.draw(0, 500);
    reciept.draw(175, 250);
    bg1.draw(0,0);
    ofDisableAlphaBlending();
}

void Print::mousePressed(int x, int y, int button)
{
	changeState("End");
}

string Print::getName()
{
	return "Print";    
}
