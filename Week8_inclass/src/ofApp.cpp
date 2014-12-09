#include "ofApp.h"
ofPoint location;
ofVec3f velocity;
ofVec3f loc3D;
ofPoint mouse;
ofPoint center;
float m;

class Mover {
public:
	ofPoint location;
	ofPoint velocity;
	ofPoint accel;

	Mover(){
		accel = ofPoint(-.001,.01);
		location=ofPoint(ofRandom(ofGetWidth()),ofRandom(ofGetHeight()));
		velocity= ofPoint(ofRandom(-2.0,2.0),ofRandom(2.0,2.0));

		ofSetColor(100,ofRandom(255),100);
	}

	void update(){
		velocity += accel;
		location += velocity;
		velocity.limit(3);
	}

	void display(){
		ofFill();
		ofCircle(location,50);
	}

	void checkEdges(){
		if(location.x>ofGetWidth()) location.x=0;
		else if(location.x<0) location.x = ofGetWidth();

		if(location.y>ofGetHeight()) location.y=0;
		else if(location.y<0) location.y = ofGetHeight();

	}
	}
//--------------------------------------------------------------

Mover *m;
void ofApp::setup(){
	location = ofPoint(100,100,5);
	velocity = ofVec3f (5.0, 5.0, 10);
	loc3D = ofVec3f(100, 100, 20);
	ofSetColor(255);
	ofSetVerticalSync(true);
	ofSetCircleResolution(200);

	ofSetColor(255);
	center = ofPoint(ofGetWidth()/2, ofGetHeight()/2);
	m= new Mover;

}

//--------------------------------------------------------------
void ofApp::update(){
	loc3D += velocity;
	if(loc3D.x > ofGetWidth() || loc3D.x < 0){
		velocity.x *= -1;
	}
	if(loc3D.y > ofGetHeight() || loc3D.y < 0){
		velocity.y *= -1;
	}
	if(loc3D.z>20 || loc3D.z < 0){
		velocity.z *= -1;
	}

	
	mouse = ofPoint(mouseX, mouseY);
	mouse -= center;
	//multiplier my scalar
	//mouse*=0.5;
	//division

	//mouse = mouse/2;


	m = mouse.length();

	mouse.normalize();
	mouse*=50;

	m-> update();
	m-> checkEdges();

}


//--------------------------------------------------------------
void ofApp::draw(){
	ofFill();
	ofEllipse(loc3D.x,loc3D.y, loc3D.z,50,50);

	ofRect(0,0,m,10);

	ofTranslate(center);
	ofLine(0,0,mouse.x,mouse.y);

	m->display();

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
