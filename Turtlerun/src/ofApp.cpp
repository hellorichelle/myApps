#include "ofApp.h"
#include "ofMain.h"
#include <iostream>


		float playerX;
	float playerY;
	float bodyWidth;
	float bodyHeight;

	float enemyX;
	float enemyY;
	float enemyWidth;
	float enemyHeight;
	float enemySpeed;

	int downKey;
	int upKey;
	int leftKey;
	int rightKey;

	int combo;
	vector<int> combination;
	bool gameOver;
	bool gameWin;

	int line;
	vector<string> instruction;

	int i;

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(20);

	//Filling in the player
	bodyWidth = 50;
	bodyHeight = 30;
	playerX = 300;
	playerY = 600;

	//Filling in the enemy
	enemyX = 0;
	enemyY = 600;
	enemyWidth = 70;
	enemyHeight = 100;
	enemySpeed =0;

	//Add keynumbers
	downKey = 40;
	upKey = 38;
	leftKey = 37;
	rightKey = 39;

	//Filling in the vector Combination
	combination.push_back(OF_KEY_DOWN);
	combination.push_back(OF_KEY_UP);
	combination.push_back(OF_KEY_LEFT);
	combination.push_back(OF_KEY_RIGHT);
	combination.push_back(OF_KEY_DOWN);

	//Fillinf in the vector instructions
	instruction.push_back("To move forward you must remember this combination. Press the DOWN-key");
	instruction.push_back("Press the UP-key");
	instruction.push_back("Press the LEFT-key");
	instruction.push_back("Press the RIGHT-key");
	instruction.push_back("That's it! Press DOWN");
	instruction.push_back("Press UP");
	instruction.push_back("Press LEFT");
	instruction.push_back("Press RIGHT");
	instruction.push_back("");

	cout<<instruction[line];

	//setting the game states
	gameOver=false;
	gameWin=false;

	combo=0;
	line=0;

}

//--------------------------------------------------------------
void ofApp::update(){ //Set the game over statement
	if(gameOver==false&&gameWin==false){
		enemySpeed++;
		enemyX+= enemySpeed/100;

		if (playerX>=700){
			enemyX+= enemySpeed/25;
		}

		if(enemyX>=playerX){
			gameOver=true;
		}
		if (playerX >= 1024){
			gameWin=true;
		}
	}
	

}

//--------------------------------------------------------------
void ofApp::draw(){

ofBackground(0);

//Creating the enemy
ofSetColor (255,0,0);
ofCircle(enemyX, enemyY, enemyWidth);

//Creating the player
ofSetColor (0,0,255);
ofCircle(playerX, playerY, bodyWidth);

//Show the instructions in screen
ofDrawBitmapString(instruction[line],20,20);

//Draw the game over state
	if(gameOver){
			ofDrawBitmapString("LOSE",200,200);
	}
	if (gameWin){
		ofDrawBitmapString("WIN!",100, 100);
	}
	

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){ 
	if (gameOver==false&&gameWin==false){
		if(key==OF_KEY_DOWN || key == OF_KEY_UP || key == OF_KEY_LEFT || key == OF_KEY_RIGHT){ //Check is either of these keys are pressed
			pushKey(key); //Send the pressed key to void Pushkey
		}
	}

	if(key==OF_KEY_F1){ // Restart the game
		if(gameOver||gameWin){
			enemyX = 0;
			enemySpeed=0;
			playerX=300;

			gameOver=false;
			gameWin=false;
		}
	}
		
	
}

void ofApp::pushKey(int key){ //Checks the combination of keys
	if (combination[combo] == key){  //Checks if the number saved in combo (vector) is same as the pressed key
		if (combo == 4){ //If the last of the vector is reached, reloop
			combo =0;
		}
		playerX=playerX+20;
		combo=combo+1;
		line++;
			if (line>=8){
				line=8;
			}
		
		
	}
	else {
		if(combo==0){ //If it's at the beginning of the vector don't go below 0
			combo=combo+1;
		}
		playerX= playerX-20;
		combo= combo-1;
		
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
