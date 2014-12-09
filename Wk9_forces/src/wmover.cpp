#include "wmover.h"

Mover::Mover(float m , float x, float y){
	location = ofVec2f(x,y);
	velocity = ofVec2f(0,0);
	accel = ofVec2f(0.0);
	mass = m;

	ofSetColor(255,0,0);
	ofSetBackgroundColor(0,0,0);
	ofSetCircleResolution(200);

}

void Mover::update(){
	velocity += accel;
	location += velocity;
	accel *= 0;
}

void Mover::display(){
	ofFill();
	ofEllipse(location.x,location.y,48,48);
}

void Mover::checkEdges(){

	//x asis check
	if(location.x > ofGetWidth()){
		location.x = ofGetWidth();
		velocity.x*-1;
	}else if(location.x<0){
		velocity.x*=-1;
		location.x=0;
	}

	//y axis check
	if(location.y > ofGetHeight()){
		velocity*=-1;
		location.y = ofGetHeight();
	}
}

void Mover::applyForce(ofVec2f force){
	ofVec2f f = ofVec2f(0,0);
	f=	(force/mass);
	accel+=f;

	

}