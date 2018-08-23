#include <LiquidCrystal.h> // includes the library to control the LCD display

#define BUTTONUP 14   //Button up in on Pin14 of the Arduino Nano
#define BUTTONDOWN 16 //Button down in on Pin16 of the Arduino Nano
#define BUTTONOK 15   //Button OK in on Pin15 of the Arduino Nano
#define BUTTONCE 17   //Button CE in on Pin17 of the Arduino Nano
#define LEDB 12   //Button CE in on Pin17 of the Arduino Nano
#define LEDR 13   //Button CE in on Pin17 of the Arduino Nano
LiquidCrystal lcd(7, 6, 11, 10, 9, 8); // Defines where the LCD is connected to the Arduino Nano
String lcdtext; //sets variable to string 

// this function is to display the variable "lcdtext" to the second line of the display
void LCD() {
lcd.setCursor(0,1); //sets cursor to the left of the second line
lcd.print("Input " );lcd.print(lcdtext);lcd.print("      ");  // prints this to the Display
}
// end of the LCD function

void setup() {
lcd.begin(16, 2);
lcd.clear();      //Clear LCD
lcd.setCursor(0,0); // Set cursor positon to the upper left
lcd.print("ArduinoNanoQP-4B"); // prints the text between the brackets on the Display


pinMode(BUTTONUP, INPUT);   //defines the pin on the Arduino as input
pinMode(BUTTONDOWN, INPUT); //defines the pin on the Arduino as input
pinMode(BUTTONOK, INPUT); //defines the pin on the Arduino as input
pinMode(BUTTONCE, INPUT); //defines the pin on the Arduino as input
pinMode(LEDB, OUTPUT); //defines the pin on the Arduino as output
pinMode(LEDR, OUTPUT); //defines the pin on the Arduino as output


}

void loop() {
if (digitalRead(BUTTONUP) == LOW) {lcdtext="UP"; LCD();digitalWrite(LEDB,HIGH);} 
 else if (digitalRead(BUTTONDOWN) == LOW) {lcdtext="DOWN"; LCD();digitalWrite(LEDB,HIGH);}
 else if (digitalRead(BUTTONOK) == LOW) {lcdtext="OK"; LCD();digitalWrite(LEDR,HIGH);}
 else if (digitalRead(BUTTONCE) == LOW) {lcdtext="CLEAR"; LCD();digitalWrite(LEDR,HIGH);} 

else {
lcdtext="none";
LCD();
digitalWrite(LEDB,LOW);digitalWrite(LEDR,LOW);
}


}
