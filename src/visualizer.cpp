//  visualizer.cpp
//  tamable_sakura
//
//  Created by amalab on 2023/06/21.

#include "visualizer.hpp"

Visualizer::Visualizer(){}
void Visualizer::init(int fSize1, int fSize2, int fSize3){
    tFlag = true;
    smoleFont.loadFont("Yu Gothic Medium.ttf", fSize1);
    mediumFont.loadFont("Yu Gothic Medium.ttf", fSize2);
    bigFont.loadFont("Yu Gothic Medium.ttf", fSize3);
    
    treeImg.load("tree.png");
    target = 2;
    dataSize = sizeof(manData)/sizeof(int);
}

void Visualizer::update(int _num){
    num = _num;
    if(num == 11) target = 0;
    else if(num == 21) target = 1;
    else if(num == 31) target = 2;
    //else if(num == 41) ;
    else if(num == 12) target = 3;
    else if(num == 22) target = 4;
    else if(num == 32) target = 5;
    //else if(num == 42) ;
    else if(num == 13) target = 6;
    else if(num == 23) target = 7;
    else if(num == 33) target = 8;
    //else if(num == 43) ;
    else if(num == 14) target = 9;
    else if(num == 24) target = 10;
    else if(num == 34) target = 11;
    //else if(num == 44) ;
}

void Visualizer::drawAreaMap(ofVec2f p){
    ofPushMatrix();
    ofPushStyle();
    ofTranslate(p.x, p.y);
    //Text
    smoleFont.drawString("全国", -200, -130);
    smoleFont.drawString("多摩市", 120, -130);
    smoleFont.drawString("東京都", -250, 150);
    //ellipse fill
    ofSetColor(205, 161, 111);
    ofSetCircleResolution(100);
    for (int i=0; i<4; i++){
        ofDrawEllipse(0, 0, diameters[i]*1.5 * 0.35, diameters[i]*1.5 * 0.35);
    }
    //ellipse line
    ofNoFill();
    ofSetLineWidth(2);
    ofSetColor(116, 80, 48);
    for (int i=0; i<4; i++){
        ofDrawEllipse(0, 0, diameters[i]*1.5 * 0.35, diameters[i]*1.5 * 0.35);
    }
    ofPopStyle();
    ofPushStyle();
    ofVec3f center = ofVec3f(0,0);
    float arcMargin = 40;
    ofColor c = ofColor(245, 178, 178, 150);
    if(num == 11) drawArc(center, diameters[3]*1.5, 270, 360, arcMargin, c);
    else if(num == 21) drawArc(center, diameters[3]/2*1.5* 0.35, 180, 270, arcMargin, c);
    else if(num == 31) drawArc(center, diameters[3]/2*1.5* 0.35, 90, 180, arcMargin, c);
    else if(num == 41) drawArc(center, diameters[3]/2*1.5* 0.35, 0, 90, arcMargin, c);
    
    else if(num == 12) drawArc(center, diameters[2]/2*1.5* 0.35, 270, 360, arcMargin, c);
    else if(num == 22) drawArc(center, diameters[2]/2*1.5* 0.35, 180, 270, arcMargin, c);
    else if(num == 32) drawArc(center, diameters[2]/2*1.5* 0.35, 90, 180, arcMargin, c);
    else if(num == 42) drawArc(center, diameters[2]/2*1.5* 0.35, 0, 90, arcMargin, c);
    
    else if(num == 13) drawArc(center, diameters[1]/2*1.5* 0.35, 270, 360, arcMargin, c);
    else if(num == 23) drawArc(center, diameters[1]/2*1.5* 0.35, 180, 270, arcMargin, c);
    else if(num == 33) drawArc(center, diameters[1]/2*1.5* 0.35, 90, 180, arcMargin, c);
    else if(num == 43) drawArc(center, diameters[1]/2*1.5* 0.35, 0, 90, arcMargin, c);
    
    else if(num == 14) drawArc(center, diameters[0]/2*1.5* 0.35, 270, 360, arcMargin, c);
    else if(num == 24) drawArc(center, diameters[0]/2*1.5* 0.35, 180, 270, arcMargin, c);
    else if(num == 34) drawArc(center, diameters[0]/2*1.5* 0.35, 90, 180, arcMargin, c);
    else if(num == 44) drawArc(center, diameters[0]/2*1.5* 0.35, 0, 90, arcMargin, c);
    ofPopStyle();
    ofPopMatrix();
}

void Visualizer::drawVisualizeInfo(){
    ofVec2f agePos = ofVec2f(100, 100);
    ofVec2f plasePos = ofVec2f(100, 200);
    ofVec2f infoPos = ofVec2f(ofGetWidth()/1.3, 100);
    int textMargin = 30;
    ofPushStyle();
    if(num == 11){
        bigFont.drawString("1960", agePos.x, agePos.y);
        bigFont.drawString("全国", plasePos.x, plasePos.y);
    } else if(num == 21){
        bigFont.drawString("1960", agePos.x, agePos.y);
        bigFont.drawString("東京都", plasePos.x, plasePos.y);
    } else if(num == 31){
        bigFont.drawString("1971", agePos.x, agePos.y);
        bigFont.drawString("多摩", plasePos.x, plasePos.y);
    } else if(num == 41){
        bigFont.drawString("～1971", agePos.x, agePos.y);
        smoleFont.drawString("1945年　終戦", infoPos.x, infoPos.y);
        smoleFont.drawString("1956年　団地族の誕生", infoPos.x, infoPos.y+textMargin);
        smoleFont.drawString("1962年　東京都の常住人口推定1千万人突破", infoPos.x, infoPos.y+textMargin*2);
        smoleFont.drawString("1963年　新住宅市街地開発法", infoPos.x, infoPos.y+textMargin*3);
        smoleFont.drawString(" マンションブーム", infoPos.x, infoPos.y+textMargin*4);
        smoleFont.drawString("1964年　東海道新幹線開通", infoPos.x, infoPos.y+textMargin*5);
        smoleFont.drawString(" 東京オリンピック開催", infoPos.x, infoPos.y+textMargin*6);
        smoleFont.drawString("1965年　多摩ニュータウン計画決定", infoPos.x, infoPos.y+textMargin*7);
        smoleFont.drawString("1966年　丙午", infoPos.x, infoPos.y+textMargin*8);
        smoleFont.drawString("1970年　日本万国博覧会（大阪）", infoPos.x, infoPos.y+textMargin*9);
        smoleFont.drawString("1971年　市制が施工され、", infoPos.x, infoPos.y+textMargin*10);
        smoleFont.drawString(" 「南多摩郡多摩村」から「多摩市」へ", infoPos.x, infoPos.y+textMargin*11);
        smoleFont.drawString(" 多摩ニュータウン入居開始", infoPos.x, infoPos.y+textMargin*12);
    } else if(num == 12){
        bigFont.drawString("1980", agePos.x, agePos.y);
        bigFont.drawString("全国", plasePos.x, plasePos.y);
    } else if(num == 22){
        bigFont.drawString("1980", agePos.x, agePos.y);
        bigFont.drawString("東京", plasePos.x, plasePos.y);
    } else if(num == 32){
        bigFont.drawString("1980", agePos.x, agePos.y);
        bigFont.drawString("多摩", plasePos.x, plasePos.y);
    } else if(num == 42){
        bigFont.drawString("～1980", agePos.x, agePos.y);
        smoleFont.drawString("1974年　オイルショックにより、", infoPos.x, infoPos.y);
        smoleFont.drawString(" 高度経済成長期終了", infoPos.x, infoPos.y+textMargin);
        smoleFont.drawString("1974年　京王相模原線が", infoPos.x, infoPos.y+textMargin*2);
        smoleFont.drawString(" 多摩センター駅まで開通", infoPos.x, infoPos.y+textMargin*3);
        smoleFont.drawString("1975年　小田急多摩線が", infoPos.x, infoPos.y+textMargin*4);
        smoleFont.drawString(" 多摩センター駅まで開通", infoPos.x, infoPos.y+textMargin*5);
        smoleFont.drawString("1977年　平均寿命が男女ともに世界一", infoPos.x, infoPos.y+textMargin*6);
        smoleFont.drawString("1978年　成田空港開港", infoPos.x, infoPos.y+textMargin*7);
    } else if(num == 13){
        bigFont.drawString("2000", agePos.x, agePos.y);
        bigFont.drawString("全国", plasePos.x, plasePos.y);
    } else if(num == 23){
        bigFont.drawString("2000", agePos.x, agePos.y);
        bigFont.drawString("東京", plasePos.x, plasePos.y);
    } else if(num == 33){
        bigFont.drawString("2000", agePos.x, agePos.y);
        bigFont.drawString("多摩", plasePos.x, plasePos.y);
    } else if(num == 43){
        mediumFont.drawString("～2000", agePos.x, agePos.y);
        smoleFont.drawString("1980年　多摩センター駅前広場が完成、", infoPos.x, infoPos.y);
        smoleFont.drawString(" バスターミナル使用開始", infoPos.x, infoPos.y+textMargin);
        smoleFont.drawString("1986年　バブル景気", infoPos.x, infoPos.y+textMargin*2);
        smoleFont.drawString("1987年　パルテノン多摩開館", infoPos.x, infoPos.y+textMargin*3);
        smoleFont.drawString("1987年　国鉄分割・民営化によってJR各社誕生", infoPos.x, infoPos.y+textMargin*4);
        smoleFont.drawString("1990年　サンリオピューロランド開園", infoPos.x, infoPos.y+textMargin*5);
        smoleFont.drawString("1991年　バブル崩壊", infoPos.x, infoPos.y+textMargin*6);
        smoleFont.drawString("1995年　阪神淡路大震災発生", infoPos.x, infoPos.y+textMargin*7);
        smoleFont.drawString(" 地下鉄サリン事件", infoPos.x, infoPos.y+textMargin*8);
        smoleFont.drawString("1997年　子どもの人口が高齢者人口を下回る", infoPos.x, infoPos.y+textMargin*9);
        smoleFont.drawString("2000年　多摩モノレール開通", infoPos.x, infoPos.y+textMargin*10);
    } else if(num == 14){
        bigFont.drawString("2020", agePos.x, agePos.y);
        bigFont.drawString("全国", plasePos.x, plasePos.y);
    } else if(num == 24){
        bigFont.drawString("2020", agePos.x, agePos.y);
        bigFont.drawString("東京", plasePos.x, plasePos.y);
    } else if(num == 34){
        bigFont.drawString("2020", agePos.x, agePos.y);
        bigFont.drawString("多摩", plasePos.x, plasePos.y);
    } else if(num == 44){
        bigFont.drawString("～2020", agePos.x, agePos.y);
        smoleFont.drawString("2011年　東日本大震災", infoPos.x, infoPos.y);
        smoleFont.drawString("2020年　新型コロナウイルス流行", infoPos.x, infoPos.y+textMargin);
    }
    ofPopStyle();
}

void Visualizer::drawVisualizData(ofVec2f p){
    for (int i=0; i< dataSize; i++) {
        //printlnln(target);
        //表示用配列とtarget列目の人口データを比較して，表示用配列の中身を引くか足す
        if (manData[i] > manDatas[target][i]) manData[i] -=1;
        else if (manData[i] < manDatas[target][i]) manData[i] +=1;
        //同じくdata2も
        if (womanData[i] > womanDatas[target][i]) womanData[i] -=1;
        else if (womanData[i] < womanDatas[target][i]) womanData[i] +=1;
    }
    //表示用配列を表示
    ofPushStyle();
    ofSetColor(245, 178, 178);
    float h = ofGetHeight()*0.03;
    for (int i=0; i<dataSize; i++) {
        ofDrawRectangle(p.x-2, p.y + ((dataSize-1 -i)*h), -manData[i], h-2);
        ofDrawRectangle(p.x+2, p.y + ((dataSize-1 -i)*h), womanData[i], h-2);
    }
    ofPopStyle();
}


void Visualizer::drawTree(ofVec2f p, float w, float h){
    treeImg.draw(p.x - w/2, p.y - h/2, w, h);
}


void Visualizer::drawArc(ofVec3f p, float _radius, float _beginAngle, float _endAngle, float _thickness, ofColor c){
    ofPath inner_pLine;
    inner_pLine.setCircleResolution(100);
    //    inner_pLine.arc(p, _radius, _radius, _beginAngle, _endAngle);
    //    inner_pLine.arcNegative(p, _radius+_thickness, _radius+_thickness,_endAngle,_beginAngle);
    inner_pLine.arc(p, _radius-_thickness, _radius-_thickness, _beginAngle, _endAngle);
    inner_pLine.arcNegative(p, _radius, _radius,_endAngle,_beginAngle);
    inner_pLine.close();
    inner_pLine.setColor(c);
    inner_pLine.draw();
}

void Visualizer::drawSakura(float y, float _size){
    vector<CherryBlossom> nextCherryBlossom;
    for(CherryBlossom t : cherryBlossom){
        t.draw();
        t.update();
        if (t.loc.y < ofGetHeight() + 200) nextCherryBlossom.push_back(t);
        cherryBlossom = nextCherryBlossom;
    }
    if (ofRandom(1) < ofNoise(ofGetFrameNum() * 0.001 + 100000)) {
        cherryBlossom.push_back(CherryBlossom(y, _size));
    }
    for(int i=0; i<cherryBlossom.size(); i++){
        if(cherryBlossom[i].isLimitOver(ofGetHeight())) cherryBlossom.erase(cherryBlossom.begin()+i);
    }
}
