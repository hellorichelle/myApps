#include "ofApp.h"
#include <iostream>
using namespace std;

//--------------------------------------------------------------
void ofApp::setup(){
	instruction.push_back("type your 5 favorite words about the HKU, press down for next input");
	instruction.push_back("Now your partner must guess the right words");
	instruction.push_back("Try to type the 5 favorite words of the HKU your friend filled in");
	text="";
	cursor=0;
	count=0;
	tries =0;
	guessingTime=false;
	score=0;

}

//--------------------------------------------------------------
void ofApp::update(){
	
	

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(0);

	if(count<=4){
		ofSetColor(255);
		ofDrawBitmapString(instruction[0],300,300);
		ofDrawBitmapString(text,300,400);
	}
	else{
		if(count == 5){
			ofSetColor(255);
			ofDrawBitmapString(instruction[1],300,300);
			guessingTime=true;
		}
	}

	if(guessingTime){
		ofDrawBitmapString(instruction[2],300,320);
		ofDrawBitmapString(text,300,400);
		if (tries==5){
			chckResults();
			tries++;
		}
		if(tries==6){
			ofBackground(255);
			ofSetColor(0);
			ofDrawBitmapString("       Well done, you scored " + score,300,600);
			cout << "You scored " << score << " points out of 5"<< endl;
		}
		
	}



}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	typeKey(key);

}

void ofApp::typeKey(int key) {
		//add charachter
		if (key >=32 && key <=126) {
			text.insert(text.begin()+cursor, key);
			cursor++;
			//cout <<text << endl;
		}
	
		if(guessingTime){
			if(key==OF_KEY_DOWN){
			inputP2.push_back(text);
			cout << "saved the input containing:" << text <<endl;
			text="";
			cursor=0;
			tries++;
			}
		}
		else{
				if(key==OF_KEY_DOWN){
					answer.push_back(text);
					cout << "saved the text containing:" << text <<endl;
					text="";
					cursor=0;
					count++;
				}
			}


	}

void ofApp::chckResults(){
	if(answer[0]==inputP2[0]){
		score++;
	}
	if(answer[1]==inputP2[1]){
		score++;
	}
	if(answer[2]==inputP2[2]){
		score++;
	}
	if(answer[3]==inputP2[3]){
		score++;
	}
	if(answer[4]==inputP2[4]){
		score++;
	}


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
