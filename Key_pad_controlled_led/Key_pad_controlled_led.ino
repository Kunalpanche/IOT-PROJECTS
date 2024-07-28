
#include <Keypad.h>

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
//define the cymbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {64, 62, 68, 66}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {65, 63, 69,67}; //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

void setup(){
  Serial.begin(9600);
  pinMode(55, OUTPUT);
  pinMode(56, OUTPUT);
  pinMode(57, OUTPUT);
}
  
void loop(){
  char customKey = customKeypad.getKey();
  
  if (customKey){
    Serial.println(customKey);
    if(customKey == '1')
    {
      digitalWrite(57, 1);
    }
    else if(customKey == '2')
    {
      digitalWrite(56, 1);
    }
    else if(customKey == '3')
    {
      digitalWrite(55, 1);
    }
    else if(customKey == '0')
    {
      digitalWrite(55, 0);
      digitalWrite(56, 0);
      digitalWrite(57, 0);
    }
  }
}
