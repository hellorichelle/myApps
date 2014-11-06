#include <stdio.h>
#include <ofMain.h>
using namespace std;

class arduinoAdd{
public:
	arduinoAdd(){};
	void setup(string port);
	void setupArduino(const int &version);
	void update ();
	void draw ();
	void testLed();
	ofArduino ard;


}; //The semicolon is THE TERMINATOR