#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    //ofEnableSmoothing();
    gui.setup();
    gui.add(blur.setup("blur", 10, 0, 50));
    gui.add(nearDepth.setup("near depth", 255, 0, 255));
    gui.add(farDepth.setup("far depth", 230, 0, 255));
    visualizer.init(20,30,50);
    isShowGui = true;
    mode = 0;
}

//--------------------------------------------------------------
void ofApp::update(){
    kinectManager.update(nearDepth, farDepth, blur);
    //ofVec2f pos = kinectManager.getCenterAverage();   // x:0~640,y:0~480
    ofVec2f pos = kinectManager.getMapWindowCenterAverage();    // x:0~mapWidth,y:0~height
    ofVec2f mouse = ofVec2f(ofGetMouseX(), ofGetMouseY());  //Debug mouse point
    int viewPattan = viewSelector.selectViewFromPos(mouse);
    cout << "viewPattan : " << viewPattan << endl;
    visualizer.update(viewPattan);
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    if(mode == 0){
//        visualizer.drawTree(ofVec2f(ofGetWidth()/2, ofGetHeight()/1.7), ofGetWidth()/5, ofGetHeight()/1.5);
        visualizer.drawTree(ofVec2f(ofGetWidth()/2, ofGetHeight()/1.7), ofGetWidth()/5, ofGetHeight()/1.5);
        visualizer.drawVisualizData(ofVec2f(ofGetWidth()/2, 0));
        visualizer.drawAreaMap(ofVec2f(ofGetWidth()/10*8.5, ofGetHeight()/10*8.5));
        visualizer.drawVisualizeInfo();
        visualizer.drawSakura(ofGetHeight()/1.8, 60);
    }
    else if(mode == 1) kinectManager.drawCalibration();
    else if(mode == 2){
        viewSelector.drawMatArea();
        kinectManager.drawContourFinder();
    }
    if (isShowGui) gui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 'm') isShowGui = !isShowGui;
    else if(key == '0') mode = 0;
    else if(key == '1') mode = 1;
    else if(key == '2') mode = 2;
}
