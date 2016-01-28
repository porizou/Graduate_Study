#include "main.h"

void Mode2(void) {

	lcd.locate(0,0); lcd.printf("MODE2    \n");
	isControllHeading  = 0;
	isControllDistance = 1;
	if(SW_ON(2)) isMoving = 1;
}

void mesureMode2(void) {

	lcd.locate(0,0); lcd.printf("MEASURE MODE2    \n");
	isControllHeading  = 0;
	isControllDistance = 1;
	if(SW_ON(2)) isMoving = 1;
}
