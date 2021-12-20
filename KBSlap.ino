#include <Keyboard.h>

//Constants
const int powPin = 2;
const int inPin = 3;

bool inLoop = false;

//Store Millis before while loop
int startTime = 0;

void setup() 
{
  //Begin Serial
  Serial.begin(9600);

  //Begin Keyboard
  Keyboard.begin();

  //Set Pin Modes for bar
  pinMode(powPin, OUTPUT);
  pinMode(inPin, INPUT);

  //Constantly Power the bar as an output
  digitalWrite(powPin, HIGH);
}
                                                                                                                                                                                                  
void loop() 
{
  //When Bar is Slapped
  if(digitalRead(inPin))
  {
      //Print the space character constantly for 1 sec (1000 ms)
      startTime = millis();
      inLoop = true;
      while(millis() < startTime + 1000)
      {
          Keyboard.print(" ");
      }
      inLoop = true;
  }  
}
