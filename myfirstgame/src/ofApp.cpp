#include "ofApp.h"

#include "ofMain.h"
#include<iostream>
using namespace std;

float playRadius;
float enemyRadius;
float enemyX;
float enemyY;
int score;
bool gameOver;
int enemySpeed;

//--------------------------------------------------------------
void ofApp::setup(){
	/* This is a multiline comment, I can just enter the heck whatever I want!
	Like this
	and this! 
	It's such amazingness */

	//And this just for 1 line. Peace, Richelle (:
	
	/* pos_x = 10;
	pos_y = 10;
	speed = 1;

	blue = 0;
	sunfall = 1; */

	enemyRadius = 20;
	playRadius = 60;

	//The enemy starts out of the screen.
	enemyY= 0-enemyRadius;
	enemyX = ofRandom(ofGetWidth());
	enemySpeed = 10;
	gameOver = false;
	score = 0;
	ofSetVerticalSync(true);
}

//--------------------------------------------------------------
void ofApp::update(){ //Update makes you do the magic stuff to work behind the scenes
	/* pos_x+=speed;
	pos_y+=speed;
	blue += sunfall;*/ 

	if (gameOver == false) {
		if (enemyY > ofGetHeight()+enemyRadius){
			score++;
			enemySpeed++;
			enemyRadius= enemyRadius +10;

			enemyY= 0- enemyRadius;
			enemyX= ofRandom(ofGetWidth());
		}
		enemyY+= enemySpeed;
		if(ofDist(mouseX,mouseY, enemyX, enemyY)<=playRadius+enemyRadius){
			gameOver=true;
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw(){ // And draw is there to show the action
	/* ofSetColor(255,255,blue);
	ofCircle(pos_x,pos_y,100); */

	ofBackground(0);

	ofSetColor(255,0,255); //Here we create the enemy by setting the color and then the shape. 
	ofCircle(enemyX,enemyY,enemyRadius);
	
	ofSetColor(200,200,255);
	ofCircle(mouseX, mouseY, playRadius);

	ofDrawBitmapString("Score :"+ ofToString(score),120,120);

	if (gameOver){
		ofDrawBitmapString("\n Game over! \n\n Press any key to restart",120,200);
	}

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	if(gameOver){
		enemyX=ofRandom(ofGetWidth());
		enemyY = 0- enemyRadius;
		enemyRadius = 20;
		enemySpeed = 10;

		score = 0;
		ofBackground(255);
		gameOver=false;
	}
	
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
