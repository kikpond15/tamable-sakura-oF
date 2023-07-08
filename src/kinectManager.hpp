//
//  kinectManager.hpp
//  tamaBle_sakura
//
//  Created by amalab on 2023/06/28.
//

#ifndef kinectManager_hpp
#define kinectManager_hpp

#include <stdio.h>
#include "ofMain.h"
#include "ofxKinect.h"
#include "ofxOpenCv.h"

class KinectManager {
public:
    KinectManager();
    void init();
    void update(int _near, int _far, int _blur);
    void drawCalibration();
    void drawContourFinder();
    vector<ofVec2f> getContourCenters();
    ofVec2f getOnlyOneCenter();
    ofVec2f getCenterAverage();
    ofVec2f getMapWindowCenterAverage();
    int getCenterCount();
    void exit();
    
    ofxKinect kinect;
    ofxCvColorImage colorImg;
    ofxCvGrayscaleImage grayImage; // grayscale depth image
    ofxCvGrayscaleImage grayThreshNear; // the near thresholded image
    ofxCvGrayscaleImage grayThreshFar; // the far thresholded image
    ofxCvContourFinder contourFinder;
    int nearThreshold, farThreshold, kinectWidth, kinectHeight;
    vector<ofVec2f> centers;
    ofVec2f mapWindowCenterAverage;
};
#endif /* KinectManager_hpp */
