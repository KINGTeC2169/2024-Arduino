#include <Joystick.h>
#include <USBAPI.h>

Joystick_ stick;

// IMPORTANT ************** READ **************
// To add a button, change the amountOfButtons variable to be the intended button amount 
// and the number in the [] to be the same as the aount of buttons
// then, add the button number in the vector
int amountOfButtons = 9;
int buttons[9] = {0, 1, 2, 3, 4, 5, 6, 7, 8};

void setup() {
  // Loops through the vector of buttons and initializes each one
  for(int button = 0; button < amountOfButtons; button++){
    pinMode(buttons[button], INPUT_PULLUP);
  }

  Serial.begin(9600);
  stick.begin();
}

void loop() {
  // Checks if each button is pressed or not
  for(int button = 0; button < amountOfButtons; button++){
    // Finds the current state of the button
    int state = digitalRead(buttons[button]);
    // IF the button is pressed something happens
    if(state == HIGH){
      stick.setButton(buttons[button], 0);
    } else{
      stick.setButton(buttons[button], 1);
    }
  }
  // Wait for 50 ms
  delay(50);
}
