#include "ofApp.h"
#define NUM 200

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofEnableDepthTest();//奥行き判断　図形の順番
    
    for(int i =0; i<NUM;i++){
        polygons.push_back(new Polygon3d);//push_back...一番最後に入れる
    }
   /* for(int i =0; i<NUM;i++){
        cout << i << ": " << polygons.at(i)->mPolygonPosition << endl;
    }確認用*/
}

//--------------------------------------------------------------
void ofApp::update(){
    camera.setPosition(3000*cos((double)ofGetElapsedTimeMillis()/800), 30, 3000*sin((double)ofGetElapsedTimeMillis()/800));
    camera.lookAt(ofVec3f(0,0,0));
    
  /*  半径1の円において
     (x,y)=(cosθ,sinθ)  今回の場合はyを固定、xz平面でカメラを動かす
     ofGetElapsedTimeMillis()一秒で1000増える時間を取得
     半径200の円を表すようにかける*/
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2,0);
    
    camera.begin();
    
   /* box.setPosition(0,0,0);
    box.set(100);
    ofSetColor(255);
    box.drawWireframe();
    
    Polygon3d polygon1 = Polygon3d();
       polygon1.draw();
    */
    
    for(int i= 0; i<NUM;i++){
        ofSetColor(ofRandom(255),ofRandom(255),ofRandom(255)); //色ランダム
        polygons.at(i)->draw();
        ofSetColor(255,255,255);
        if(i!=0){
        ofLine(polygons.at(i-1)->mPolygonPosition,polygons.at(i)->mPolygonPosition);
        }
    }
    
    camera.end();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
