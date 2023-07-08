#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){
	//ofSetupOpenGL(1280,960,OF_WINDOW);			// <-------- setup the GL context
    //ofSetupOpenGL(1950, 1200, OF_FULLSCREEN);     //Full Screen
    ofSetupOpenGL(1920, 1080, OF_WINDOW);           //熊さんのプログラムに準拠
    
	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new ofApp());
}
