//  visualizer.hpp
//  tamable_sakura
//
//  Created by amalab on 2023/06/21.

#ifndef visualizer_hpp
#define visualizer_hpp

#include <stdio.h>
#include "ofMain.h"
#include "ofxTrueTypeFontUC.h"
#include "cherryBlossom.hpp"

class Visualizer {
public:
    Visualizer();
    void init(int fSize1, int fSize2, int fSize3);
    void update(int _num);
    void updateSakura();
    void drawVisualizData(ofVec2f p);
    void drawAreaMap(ofVec2f p);
    void drawVisualizeInfo();
    void drawTree(ofVec2f p, float w, float h);
    void drawSakura(float y, float _size);
    void drawArc(ofVec3f p, float _radius, float _beginAngle, float _endAngle, float _thickness, ofColor c);
    
    ofVec2f mouseLoc;
    ofxTrueTypeFontUC smoleFont, mediumFont, bigFont;
    ofImage treeImg;
    vector<CherryBlossom> cherryBlossom;
    
    int target, num, dataSize;
    bool tFlag;
    int manDatas[12][21] = {
        {461, 583, 662, 402, 332, 377, 377, 287, 239, 237, 224, 206, 172, 129, 91, 52, 25, 7, 1, 0, 0},
        {368, 357, 466, 721, 769, 602, 436, 304, 242, 236, 200, 169, 125, 82, 50, 23, 8, 2, 0, 0, 0 },
        {776, 399, 239, 226, 507, 682, 733, 509, 301, 179, 131, 126, 107, 71, 44, 25, 10, 3, 1, 0, 0 },
        {373, 440, 393, 361, 338, 389, 463, 393, 355, 345, 303, 215, 166, 149, 113, 73, 36, 12, 3, 0, 0},
        {316, 382, 360, 394, 532, 469, 506, 413, 361, 342, 279, 198, 150, 134, 97, 62, 30, 10, 2, 0, 0 },
        {560, 661, 428, 255, 259, 339, 620, 615, 439, 297, 191, 106, 79, 75, 51, 26, 14, 5, 1, 0, 0},
        {239, 243, 265, 303, 340, 392, 350, 323, 310, 353, 411, 339, 296, 265, 211, 128, 72, 38, 12, 2, 0},
        {203, 197, 205, 273, 435, 483, 443, 383, 314, 330, 403, 345, 296, 259, 190, 117, 66, 35, 11, 2, 0},
        {214, 218, 262, 341, 525, 489, 415, 336, 283, 355, 448, 393, 295, 209, 128, 64, 38, 20, 7, 1, 0},
        {147, 209, 222, 230, 244, 249, 262, 295, 328, 391, 369, 311, 292, 307, 370, 247, 195, 123, 51, 11, 1 },
        {156, 203, 197, 193, 278, 335, 339, 364, 316, 426, 413, 338, 269, 243, 292, 201, 157, 102, 40, 9, 0},
        {176, 202, 214, 216, 268, 236, 260, 324, 380, 429, 377, 304, 255, 301, 356, 290, 185, 94, 28, 5, 0 }};
    int womanDatas[12][21] = {
        {443, 560, 638, 425, 381, 384, 378, 340, 292, 278, 240, 210, 178, 140, 111, 76, 43, 15, 3, 0, 0 },
        {348, 339, 444, 570, 582, 532, 431, 351, 284, 250, 202, 166, 126, 89, 63, 38, 18, 5, 1, 0, 0 },
        {728, 399, 222, 214, 557, 749, 610, 384, 248, 189, 160, 139, 113, 80, 60, 38, 26, 11, 2, 0, 0 },
        {355, 418, 373, 346, 332, 384, 457, 394, 357, 347, 312, 265, 215, 190, 146, 102, 58, 23, 6, 1, 0 },
        {301, 364, 342, 362, 428, 403, 466, 411, 374, 351, 295, 240, 191, 162, 122, 84, 46, 18, 05, 1, 0 },
        {513, 627, 404, 244, 233, 443, 670, 579, 362, 244, 174, 131, 106, 91, 66, 45, 27, 14, 5, 1, 0 },
        {227, 232, 252, 288, 325, 381, 343, 317, 306, 351, 413, 351, 315, 296, 255, 199, 134, 83, 33, 7, 1 },
        {193, 188, 196, 259, 390, 448, 407, 347, 294, 313, 393, 354, 318, 286, 230, 173, 114, 70, 28, 7, 1 },
        {204, 210, 244, 318, 436, 443, 361, 300, 302, 403, 472, 398, 282, 200, 142, 102, 69, 48, 21, 5, 0 },
        {141, 199, 211, 219, 235, 240, 253, 288, 321, 384, 367, 313, 300, 325, 411, 300, 265, 209, 13, 43, 3 },
        {149, 194, 187, 186, 279, 338, 335, 353, 370, 418, 401, 312, 260, 247, 319, 252, 225, 176, 95, 31, 2 },
        {166, 198, 203, 209, 253, 227, 247, 306, 357, 411, 354, 296, 286, 357, 413, 354, 232, 140, 67, 20, 3 }};
    
    int manData[21] = {461, 583, 662, 402, 332, 377, 377, 287, 239, 237, 224, 206, 172, 129, 91, 52, 25, 7, 1, 0, 0};
    int womanData[21] = {443, 560, 638, 425, 381, 384, 378, 340, 292, 278, 240, 210, 178, 140, 111, 76, 43, 15, 3, 0, 0};
    int diameters[4] = {640, 480, 320, 160};
};
#endif /* visualizer_hpp */
