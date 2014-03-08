//
//  Start.cpp
//  cloudSending
//
//  Created by NAOYAIWAMOTO on 2014/03/04.
//
//

#include "Start.h"

void Start::setup()
{
    // img
    topImg.loadImage("Start/top.jpg");
    
    // e-font
    font.loadFont("font/avenir-next-medium-sc-latin-1.ttf", 50);
    title1  = "CLOUD";
    title2  = "SENDING";
    
    // j-font
    j_font.loadFont("font/KozGoPro-ExtraLight.otf", 20);
//    sampleString = L"クラウドセンディング";
    sampleString = "クラウドセンディング";

// set up for reading QR codes (activate camera)
    ofSetVerticalSync(true);
	cam.initGrabber(640, 480);
}

void Start::update()
{
	if (ofGetElapsedTimeMillis() - getSharedData().lastUpdate > 1000)
	{
		//getSharedData().counter--;
		getSharedData().lastUpdate = ofGetElapsedTimeMillis();
	}

// update for reading QR codes
	cam.update();
	if(cam.isFrameNew()) {
		ofxZxing::Result curResult = ofxZxing::decode(cam.getPixelsRef(), true);
		float curTime = ofGetElapsedTimef();
		if(curResult.getFound()) { // only update if we found something, avoid flickering
			result = curResult;
			lastFound = curTime;
		} else if(curTime - lastFound > 1) {  // if we haven't found anything after a second
			result = curResult; // then update anyway
		}
	}
}

void Start::draw()
{
    // img
    topImg.resize(ofGetWidth(), ofGetHeight());
    topImg.draw(0,0);
    
    // e-font
    font.drawString(title1, 50, 150);
    font.drawString(title2, 50, 210);
    
    // j-font
//    j_font.drawString(sampleString, 50, 250);
    font.drawString(sampleString, 50, 250);

    
	//getSharedData().font.drawString(ofToString(getSharedData().counter), ofGetWidth() >> 1, ofGetHeight() >> 1);

	
// Scan QR codes and get the info
    if(result.getFound()) {
        ticketData = result.getText();
        string from = ofSplitString(ticketData, ",")[0];
        string to = ofSplitString(ticketData, ",")[1];
        string flight = ofSplitString(ticketData, ",")[2];
        string company = ofSplitString(ticketData, ",")[3];
        string time = ofSplitString(ticketData, ",")[4];
        cout << company << endl;
        if(company == "JAL"){
            //do something for JAL
        }else if(company == "ANA"){
            //do something for ANA
        }
        changeState("Flight");
	}

}

void Start::mousePressed(int x, int y, int button)
{
	changeState("Flight");
}

string Start::getName()
{
	return "Start";
}