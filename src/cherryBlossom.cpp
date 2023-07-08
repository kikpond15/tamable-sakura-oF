//  cherryBlossom.cpp
//  tamable_sakura
//
//  Created by amalab on 2023/07/03.

#include "cherryBlossom.hpp"
CherryBlossom::CherryBlossom(float y, float _size){
    loc = ofVec3f(ofMap(ofNoise(ofGetFrameNum()* 0.01), 0, 1, 0, ofGetWidth()), y, ofRandom(-30, 30)-50);
    //loc = ofVec3f(ofMap(ofNoise(ofGetFrameNum()* 0.01), 0, 1, 0, ofGetWidth()),-50, ofRandom(-30, 30)-50);
    lvel = ofVec3f(0, 0, 0);
    rot = ofVec3f(ofRandom(TWO_PI), ofRandom(TWO_PI), ofRandom(TWO_PI));
    rvel = ofVec3f(0, 0, 0);
    size = _size;
}

void CherryBlossom::update(){
    
    lvel+=ofVec3f(ofRandom(-0.1, 0.1), ofRandom(-0.1, 0.1));
    lvel.x = constrain(lvel.x, -1, 1);
    lvel.z = constrain(lvel.z, -1, 1);
    loc += lvel;
    loc.y += ofRandom(0, 3);
    rvel += ofVec3f(ofRandom(-PI / 128, PI / 128), ofRandom(-PI / 128, PI / 128));
    rvel.x = constrain(rvel.x, -PI / 32, PI / 32);
    rvel.y = constrain(rvel.x, -PI / 32, PI / 32);
    rvel.z = constrain(rvel.x, -PI / 32, PI / 32);
    rot += rvel;
}

void CherryBlossom::draw(){
    ofPushMatrix();
    ofTranslate(loc.x, loc.y, loc.z);
    ofRotateXRad(rot.x);
    ofRotateYRad(rot.y);
    ofRotateZRad(rot.z);
    ofPushStyle();
    ofSetColor(255, 230, 234);
    ofBeginShape();
    for (int t = 0; t < 360/4; t++) {
        float A = 4 / PI * ofDegToRad(t);
        float md = int(A) % 2;
        float r = pow(-1, md) * (A - int(A)) + md;
        float R = r + 2 * calcH(r);
        float x = size * R * cos(ofDegToRad(t));
        float y = size * R * sin(ofDegToRad(t));
        ofVertex(x*cos(PI*2/3), y*sin(PI*2/3), 0);
    }
    ofEndShape(OF_CLOSE);
    ofPopStyle();
    ofPopMatrix();
}

float CherryBlossom::calcH(float x) {
    if (x < 0.8) {
        return 0;
    } else {
        return 0.8 - x;
    }
}

float CherryBlossom::constrain(float val, float min, float max){
    if (val < min) val = min;
    if (val > max) val = max;
    return  val;
}

bool CherryBlossom::isLimitOver(float limmi){
    if(limmi < loc.y) return true;
    else return false;
}
