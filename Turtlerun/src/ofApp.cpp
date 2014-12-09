#include "ofApp.h"
#include "ofMain.h"
#include <ofBaseSoundPlayer.h>
#include <ofSoundPlayer.h>
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
	vector<string> textSet;
	ofImage showText;

	int i;
	vector<string> turtlePose;
	ofImage turtle;

	vector<string> bgBucket;
	ofImage bg;
	string bgName;
	string extension;
	int bgNum;

	vector<string> birdPose;
	ofImage bird;
	int pose;
	int poseX;
	bool poseXmove=true;

	ofSoundPlayer bgMusic;
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
	//instruction.push_back("To move forward you must remember this combination. Press the DOWN-key");
	//instruction.push_back("Press the UP-key");
	//instruction.push_back("Press the LEFT-key");
	//instruction.push_back("Press the RIGHT-key");
	//instruction.push_back("That's it! Press DOWN");
	//instruction.push_back("Press UP");
	//instruction.push_back("Press LEFT");
	//instruction.push_back("Press RIGHT");
	//instruction.push_back("");

	//cout<<instruction[line];

	//setting the game states
	gameOver=false;
	gameWin=false;

	combo=0;
	

	//Setting images
	turtlePose.push_back("images/turtle01.png");
	turtlePose.push_back("images/turtle02.png");
	turtlePose.push_back("images/turtle03.png");
	turtlePose.push_back("images/turtle04.png");
	turtlePose.push_back("images/turtle01.png");
	turtlePose.push_back("images/text12.png");

	birdPose.push_back("images/bird01.png"); //0
	birdPose.push_back("images/bird02.png"); //1
	birdPose.push_back("images/bird03.png"); //2
	birdPose.push_back("images/bird04.png"); //3
	birdPose.push_back("images/bird05.png"); //4
	birdPose.push_back("images/bird06.png"); //5

	pose=0;
	poseX=-200;

	//bgNum=1;
	//extension=".png";
	//bgName="images/animateBG00"+to_string(bgNum)+extension;
	

	for(int i=1; i<30; i++)bgBucket.push_back("images/animateBG00"+ to_string(i)+".png");
	bgNum=0;

	for(int i=1; i<13; i++){textSet.push_back("images/text"+ to_string(i)+".png"); cout<<i<<endl;}
	line=0;
	//textSet.push_back("images/text01.png"); //0
	//textSet.push_back("images/text02.png"); //1
	//textSet.push_back("images/text03.png"); //2
	//textSet.push_back("images/text04.png"); //3
	//textSet.push_back("images/text05.png"); //4
	//textSet.push_back("images/text06.png"); //5
	//textSet.push_back("images/text07.png"); //6
	//textSet.push_back("images/text08.png"); //7
	//textSet.push_back("images/text09.png"); //8
	//textSet.push_back("images/text10.png"); //9
	//textSet.push_back("images/text11.png"); //10
	//textSet.push_back("images/text12.png"); //11

	bgMusic.loadSound("sounds/bg_soundfile.mp3");
	bgMusic.play();
}

//--------------------------------------------------------------
void ofApp::update(){ 
	

	if(enemyX>100){
	pose=1;
	poseX=50;
	}
	if(enemyX>300){
	pose=2;
	poseX=150;
	}
	if(enemyX>450){
	pose=3;
	poseX=300;
	}
	if(enemyX>600){
	pose=0;
	poseX=450;
	}
	if(gameOver){
	pose=5;
	combo=5;
	}
	
	//Set the game over statement
	if(gameOver==false&&gameWin==false){
		enemySpeed++;
		enemyX+= enemySpeed/50;
		bgNum++;
		if (playerX>=700){
			poseXmove=false;
			enemyX+= enemySpeed/20;
			pose=4;
		}

		if(enemyX>=playerX){
			gameOver=true;
			bgMusic.stop();
		}
		if (playerX >= 980){
			gameWin=true;
			bgMusic.stop();
		}

		if(bgNum>28)bgNum=0;
		//cout<<bgNum<<endl;
	}
	
	turtle.loadImage(turtlePose[combo]);
	bird.loadImage(birdPose[pose]);
	showText.loadImage(textSet[line]);
	bg.loadImage(bgBucket[bgNum]);
	ofSetFrameRate(25);
	//cout<< ofGetFrameRate << endl;
}

//--------------------------------------------------------------
void ofApp::draw(){


//ofBackground(0);
bg.draw(0,0);

turtle.draw(playerX,playerY);

showText.draw(200,150);

if(poseXmove){
	bird.draw(poseX,300);
}
else {
	bird.draw(enemyX-150,300);
}
//Creating the enemy
//ofSetColor (255,0,0);
//ofCircle(enemyX, enemyY, enemyWidth);
 //bird.draw(enemyX,enemyY);



//Creating the player
//ofSetColor (0,0,255);
//ofCircle(playerX, playerY, bodyWidth);

//Show the instructions in screen
//ofDrawBitmapString(instruction[line],20,20);

//Draw the game over state
	if(gameOver){
			line=11;
			pose=5;
			
	}
	if (gameWin){
		line=10;
	}

	//bgMusic.play();
	//bgMusic.setVolume(1);
	//cout<<bgMusic.isLoaded<<endl;

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	//bgMusic.play();

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
			poseX=-200;
			line=0;
			pose=0;
			combo=0;

			poseXmove=true;
			gameOver=false;
			gameWin=false;
			bgMusic.play();



		}
	}
		
	
}

void ofApp::pushKey(int key){ //Checks the combination of keys
	if (combination[combo] == key){  //Checks if the number saved in combo (vector) is same as the pressed key
		if (combo == 4){ //If the last of the vector is reached, reloop
			combo =0;
		}
		playerX=playerX+10;
		combo=combo+1;

		
		line++;
		if (line>8){
				line=9;
			}	
			cout<<line<<endl;
		
		
	}
	else {
		if(combo==0){ //If it's at the beginning of the vector don't go below 0
			combo=combo+1;
		}
		playerX= playerX-10;
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
