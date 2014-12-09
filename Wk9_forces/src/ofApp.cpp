#include "ofApp.h"
#include <iostream>
//--------------------------------------------------------------
void ofApp::setup(){
	//m=new Mover();
	gravity = ofVec2f(0,0.01);
	wind = ofVec2f(0.01,0);
	numMovers=20;
	for(int i=0; i<numMovers; i++){
		Mover*m = new Mover (ofRandom(0.1,4), ofRandom(0,ofGetWidth()),ofRandom(0,ofGetHeight()));
		movers.push_back(*m);
		cout << movers.size() << endl;
	}
}

//--------------------------------------------------------------
void ofApp::update(){

	for(int i=0; i<numMovers; i++){
		movers[i].applyForce(wind);
		movers[i].applyForce(gravity);
	}

	//m.applyForce(wind);
	//m.applyForce(gravity);
}

//--------------------------------------------------------------
void ofApp::draw(){
	for(int i=0; i<numMovers; i++){
		movers[i].update();
		movers[i].display();
		movers[i].checkEdges();
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
