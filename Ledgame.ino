int JackPot = 13;
int YellowLed1 = 12;
int RedLed1 = 11;
int RedLed2 = 10;
int YellowLed2 = 9;
int Button = 8;
int arrayOfLeds[5] = {JackPot, YellowLed1, RedLed1, RedLed2, YellowLed2};
int ButtonVal = 0;
int Direction = 1;

void setup() {
// Here we are declareing the IO for the pins.
  pinMode(JackPot, OUTPUT);
  pinMode(YellowLed1, OUTPUT);
  pinMode(RedLed1, OUTPUT);
  pinMode(RedLed2, OUTPUT);
  pinMode(YellowLed2, OUTPUT);
  pinMode(Button, INPUT);
//Starting the serial protocall.
  Serial.begin(9600);
}

void loop() {
  if (Direction == 1) {                                 //Setting the direction for the led's.
    for (int counter1 = 0; counter1  < 5; counter1++) { //Counting UP in a loop.
      ButtonVal = digitalRead(Button);                  //Reading the button.
      if (ButtonVal == HIGH) {                          //Checking if the button is pressed.
        Serial.println("Button Pressed");               // If pressed print to serial monitor
        delay(4000);                                    //Wait 4 secconds before starting again.
      } else {
        Serial.println("Button Not Pressed");           // no button pressed.
      }
      leds(counter1);                                   //Sending the number to the led's.
      delay(100);                                       //delay can be longer or shorter.
      if (counter1 == 4){Direction = 0;}                // Switched the direction that the loop runs in.
      
    }
    
  }
  if (Direction == 0) {
    Serial.println("We are in the else loop now");
    for (int counter2 = 4; counter2  >= 0; counter2--) {
      ButtonVal = digitalRead(Button);
      if (ButtonVal == HIGH) {
        Serial.println("Button Pressed");
        delay(4000);
      } else {
        Serial.println("Button Not Pressed");
      }
      leds(counter2);
      delay(100);
      if (counter2 == 0){Direction = 1;}
    }
  }
}


void leds(int counted) {                                   //Turns off all led, except for the one that needs to be light up.
  for (int ThisCount = 0; ThisCount < 5; ThisCount++){
    if (ThisCount == counted){
      digitalWrite(arrayOfLeds[counted], HIGH);
    }
    else
    {
      digitalWrite(arrayOfLeds[ThisCount], LOW);
    }
  }
}
