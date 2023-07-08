//
//  viewSelector.hpp
//  tamaBle_sakura
//
//  Created by amalab on 2023/06/28.
//

#ifndef viewSelector_hpp
#define viewSelector_hpp

#include <stdio.h>
#include "ofMain.h"

class ViewSelector{
public:
    ViewSelector();
    void drawMatArea();
    int selectViewFromPos(ofVec2f p);
    int select();
    
    int viewPattern;
    int areaRad[4] = {125, 250, 375, 500};
};
#endif /* viewSelector_hpp */
