//
//  KinectManager.cpp
//  tamaBle_sakura
//
//  Created by amalab on 2023/06/28.

#include "kinectManager.hpp"
KinectManager::KinectManager(){
    kinect.setRegistration(true);
    kinect.init();
    kinect.open();
    kinectWidth = kinect.width;
    kinectHeight = kinect.height;
    colorImg.allocate(kinectWidth, kinectHeight);
    grayImage.allocate(kinectWidth, kinectHeight);
    grayThreshNear.allocate(kinectWidth, kinectHeight);
    grayThreshFar.allocate(kinectWidth, kinectHeight);
}

void KinectManager::update(int _near, int _far, int _blur){
    kinect.update();
    if(kinect.isFrameNew()) {
        
        grayImage.setFromPixels(kinect.getDepthPixels().getData(), kinectWidth, kinectHeight);
        grayThreshNear = grayImage;
        grayThreshFar = grayImage;
        grayThreshNear.threshold(_near, true);
        grayThreshFar.threshold(_far);
        cvAnd(grayThreshNear.getCvImage(), grayThreshFar.getCvImage(), grayImage.getCvImage(), NULL);
        grayImage.flagImageChanged();
        //grayImage.blurGaussian(_blur);
        contourFinder.findContours(grayImage, 10,(kinectWidth*kinectHeight)/2, 20, false);
        
        centers.clear();
        if(contourFinder.nBlobs > 0){
            for(int i=0; i<contourFinder.nBlobs; i++){
                ofRectangle r = contourFinder.blobs.at(i).boundingRect;
                centers.push_back(ofVec2f(r.x + r.width/2, r.y + r.height/2));
            }
        }
    }
}

void KinectManager::drawCalibration(){
    ofSetColor(255);
    kinect.draw(0, 0, ofGetWidth()/2, ofGetHeight()/2);
    kinect.drawDepth(ofGetWidth()/2, 0, ofGetWidth()/2, ofGetHeight()/2);
    
    grayImage.draw(0, ofGetHeight()/2, ofGetWidth()/2, ofGetHeight()/2);
    contourFinder.draw(ofGetWidth()/2, ofGetHeight()/2, ofGetWidth()/2, ofGetHeight()/2);
    for(auto p: centers){
        ofSetColor(255,0,0);
        p.x = ofMap(p.x, 0, kinectWidth, ofGetWidth()/2, ofGetWidth());
        p.y = ofMap(p.y, 0, kinectHeight, ofGetHeight()/2, ofGetHeight());
        ofDrawEllipse(p.x , p.y, 10, 10);
    }
}

void KinectManager::drawContourFinder(){
    ofPushStyle();
    int mapK2DispW = ofGetHeight()*1.33;
    int mapK2DispH = ofGetHeight();
    contourFinder.draw(ofGetWidth()/2 - mapK2DispW/2, 0, mapK2DispW, mapK2DispH);
    for(auto p: centers){
        ofSetColor(255,0,0);
        p.x = ofMap(p.x, 0, kinectWidth, ofGetWidth()/2-mapK2DispW/2, ofGetWidth()/2-mapK2DispW/2+mapK2DispW);
        p.y = ofMap(p.y, 0, kinectHeight, 0, mapK2DispH);
        ofDrawEllipse(p.x , p.y, 10, 10);
    }
    
    ofSetColor(255, 255, 0);
    ofVec2f c = getCenterAverage();
    c.x = ofMap(c.x, 0, kinectWidth, ofGetWidth()/2-mapK2DispW/2,
                ofGetWidth()/2-mapK2DispW/2+mapK2DispW);
    c.y = ofMap(c.y, 0, kinectHeight, 0, mapK2DispH);
    ofDrawEllipse(c.x, c.y, 10, 10);
    ofNoFill();
    ofDrawRectangle(ofGetWidth()/2-mapK2DispW/2, 0, mapK2DispW, mapK2DispH);
    ofPopStyle();
}

ofVec2f KinectManager::getCenterAverage(){
    ofVec2f aveCenter = ofVec2f(0,0);
    for(auto p: centers){
        aveCenter += p;
    }
    aveCenter.x = aveCenter.x/centers.size();
    aveCenter.y = aveCenter.y/centers.size();
    return aveCenter;
}

ofVec2f KinectManager::getMapWindowCenterAverage(){
    int mapK2DispW = ofGetHeight()*1.33;
    int mapK2DispH = ofGetHeight();
    ofVec2f c = getCenterAverage();
    c.x = ofMap(c.x, 0, kinectWidth, ofGetWidth()/2-mapK2DispW/2,ofGetWidth()/2-mapK2DispW/2+mapK2DispW);
    c.y = ofMap(c.y, 0, kinectHeight, 0, mapK2DispH);
    mapWindowCenterAverage = ofVec2f(c.x, c.y);
    return mapWindowCenterAverage;
}

vector<ofVec2f> KinectManager::getContourCenters(){
    return centers;
}

int  KinectManager::getCenterCount(){
    return  centers.size();
}

void KinectManager::exit(){
    kinect.clear();
}

