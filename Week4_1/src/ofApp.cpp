#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	for(int xi=0; xi<11; xi++){
		circle c;
		c.x=ofRandom(ofGetWidth());
		c.y=ofRandom(ofGetHeight());
		c.width=ofMap(c.x,0,1024, 0,100);
		c.height=c.width;
		circles.push_back(c);
	}
	//for loop ended
	int &rx = x;

	passByValue(x);
	cout<<x<<"is the value of x after running passByValue"<<endl;

	passByReference(rx);
	cout << x << "is the value of x after running passByReference"<<endl;
}

void ofApp::passByReference(int& ref){
	ref *=10;
}

void ofApp::passByValue(int _x){
	_x=_x+10;
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	for(int i=0; i<circles.size(); i++){
		ofSetColor(circles[i].width,255,255);
		ofFill();
		ofEllipse(circles[i].x, circles[i].y, circles[i].width, circles[i].height);
	}

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
