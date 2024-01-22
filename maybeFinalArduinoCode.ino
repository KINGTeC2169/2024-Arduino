#include <Joystick.h>
#include <USBAPI.h>

Joystick_ stick;

void setup() {
  // Intake and outtake (?)
  pinMode(0, INPUT_PULLUP);
  pinMode(1, INPUT_PULLUP);
  // Speed up of shooting thing
  pinMode(2, INPUT_PULLUP);
  // Up and down of the arm thing
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);

  Serial.begin(9600);
  stick.begin();
}

void loop() {
  // Checks if each button is pressed or not
  for(int i = 0; i < 5; i++){
    // Finds the current state of the button
    int state = digitalRead(i);
    // IF the button is pressed something happens (idk what, I copied this code)
    if(state == HIGH){
      stick.setButton(i, 0);
    } else{
      stick.setButton(i, 1);
    }
  }
  // Wait for 50 ms
  delay(50);
}