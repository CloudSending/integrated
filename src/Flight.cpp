//
//  Flight.cpp
//  cloudSending
//
//  Created by NAOYAIWAMOTO on 2014/03/04.
//
//

#include "Flight.h"

void Flight::setup()
{
    mapImg.loadImage("Flight/Italy.png");
    font.loadFont("font/avenir-next-medium-sc-latin-1.ttf", 60);
    flightInfo  = "ITALY";
//    j_font.loadFont("font/KozGoPro-ExtraLight.otf", 20);
//    sampleString = L"あなたの渡航先";
//    sampleString2 = L"イタリア";
    sampleString = "あなたの渡航先";
    sampleString2 = "イタリア";

    
}

void Flight::update()
{
	if (ofGetElapsedTimeMillis() - getSharedData().lastUpdate > 1000)
	{
		getSharedData().counter++;
		getSharedData().lastUpdate = ofGetElapsedTimeMillis();
        
        // 時間がたったら次へ
        if (getSharedData().counter > 3) {
            getSharedData().counter = 0;
            changeState("Measure1");
        }
	}
}

void Flight::draw()
{
    ofBackground(100);
    
    // 文字
//    j_font.drawString(sampleString, 210, 220);
    font.drawString(sampleString, 210, 220);
    font.drawString(flightInfo, 200, 300);
//    j_font.drawString(sampleString2, 250, 350);
    font.drawString(sampleString2, 250, 350);
    
    // 地図
    mapImg.resize(560, 350);
    mapImg.draw(20,400);
}

void Flight::mousePressed(int x, int y, int button)
{
	changeState("Measure1");
}

string Flight::getName()
{
	return "Flight";
}