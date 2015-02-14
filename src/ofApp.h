#pragma once

#include "ofMain.h"

class Polygon3d{
public:
    ofVec3f mPolygonPosition = ofVec3f(0,0,0); //座標
    int mPolygonSize = 10; //大きさ
    int mPolygonType=0; //形0:Box, 1:Sphere
    int mPolygonColor=0;
    ofColor color;
    

    
    Polygon3d(){
        mPolygonPosition = ofVec3f(ofRandom(-2000,2000),ofRandom(-2000,2000),ofRandom(-2000,2000));
        
        mPolygonSize = floor(ofRandom(10, 100));
        mPolygonType = floor(ofRandom(2));//floor..少数以下切り捨て
        mPolygonColor = floor(ofRandom(255));
        color.setHsb(mPolygonColor,255,255);
    }; //constructor
    ~Polygon3d(){}; //destructor
    void draw(){
        if(mPolygonType == 0){
            ofBoxPrimitive boxPrimitive;
            boxPrimitive.setPosition(mPolygonPosition);
            boxPrimitive.set(mPolygonSize);
            boxPrimitive.drawWireframe();
           // ofSetColor(color);
        }else if(mPolygonType == 1){
            ofSpherePrimitive spherePrimitive;
            spherePrimitive.setPosition(mPolygonPosition);
            spherePrimitive.setRadius(mPolygonSize);
            spherePrimitive.drawWireframe();
          //  ofSetColor(color);
        }
    }
};


class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    ofBoxPrimitive box;
    ofSpherePrimitive sphere;
    ofEasyCam easycam;
    ofCamera camera;
    
    vector<Polygon3d *> polygons; //インスタンス生成
		
};
