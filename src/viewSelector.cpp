//
//  viewSelecter.cpp
//  tamaBle_sakura
//
//  Created by amalab on 2023/06/28.
//

#include "viewSelector.hpp"

ViewSelector::ViewSelector(){
    viewPattern = 1;
}

int ViewSelector::selectViewFromPos(ofVec2f p){
//    float px = ofMap(p.x, 0, 640, 0, ofGetWidth());
//    float py = ofMap(p.y, 0, 480, 0, ofGetHeight());
    float px = p.x;
    float py = p.y;
    viewPattern = 1;
    
    if(px <= ofGetWidth()/2 && py <= ofGetHeight()/2) viewPattern = viewPattern*10;
    else if(px > ofGetWidth()/2 && py <= ofGetHeight()/2) viewPattern = viewPattern*20;
    else if(px > ofGetWidth()/2 && py > ofGetHeight()/2) viewPattern = viewPattern*30;
    else if(px <= ofGetWidth()/2 && py > ofGetHeight()/2) viewPattern = viewPattern*40;
    
    float distance = ofDist(px, py, ofGetWidth()/2, ofGetHeight()/2);
    
    if(distance <= areaRad[0]) viewPattern+=1;
    else if(distance <= areaRad[1]) viewPattern+=2;
    else if(distance <= areaRad[2]) viewPattern+=3;
    else if(distance <= areaRad[3]) viewPattern+=4;
    return viewPattern;
}

void ViewSelector::drawMatArea(){
    ofPushStyle();
    ofSetLineWidth(3);
    ofNoFill();
    ofSetColor(116, 80, 48);
    ofDrawCircle(ofGetWidth()/2, ofGetHeight()/2, areaRad[3]);
    ofDrawCircle(ofGetWidth()/2, ofGetHeight()/2, areaRad[2]);
    ofDrawCircle(ofGetWidth()/2, ofGetHeight()/2, areaRad[1]);
    ofDrawCircle(ofGetWidth()/2, ofGetHeight()/2, areaRad[0]);
    ofPopStyle();
}

int ViewSelector::select(){
}
