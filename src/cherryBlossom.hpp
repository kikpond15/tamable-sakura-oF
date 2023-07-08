//
//  cherryBlossom.hpp
//  tamable_sakura
//
//  Created by amalab on 2023/07/03.
//

#ifndef cherryBlossom_hpp
#define cherryBlossom_hpp

#include <stdio.h>
#include "ofMain.h"

class CherryBlossom {
public:
    CherryBlossom(float y, float _size);
    void init();
    void update();
    void draw();
    float calcH(float x);
    float constrain(float val, float min, float max);
    bool isLimitOver(float limmi);
    
    ofVec3f loc, lvel, rot, rvel;
    float size;
};
#endif /* cherryBlossom_hpp */
