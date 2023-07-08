#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "visualizer.hpp"
#include "kinectManager.hpp"
#include "viewSelector.hpp"

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    
    Visualizer visualizer;
    KinectManager kinectManager;
    ViewSelector viewSelector;
    ofxPanel gui;
    ofxIntSlider thresholed, blur, nearDepth, farDepth;

    bool isShowGui;
    int mode;
};
