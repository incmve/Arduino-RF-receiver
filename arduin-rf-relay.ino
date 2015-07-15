/*
 * Active low relay receiver working with kaku protocol
*/


#include <NewRemoteReceiver.h>
#define RELAY1  8
#define RELAY2  9

void setup() {
  Serial.begin(115200);
    NewRemoteReceiver::init(0, 2, rfstart);
   // digitalWrite(RELAY1, HIGH);
    pinMode(RELAY1, OUTPUT);
    pinMode(RELAY2, OUTPUT);
  
  // Initialize receiver on interrupt 0 (= digital pin 2), calls the callback "rfstart"
  // after 2 identical codes have been received in a row. (thus, keep the button pressed
  // for a moment)
  //
  // See the interrupt-parameter of attachInterrupt for possible values (and pins)
  // to connect the receiver.
  
}

void loop() 
{
  
}

// Callback function is called only when a valid code is received.
void rfstart(NewRemoteCode receivedCode) {
  // Note: interrupts are disabled. You can re-enable them if needed.
  
 
  if (receivedCode.address == 88 && receivedCode.unit == 1 && receivedCode.switchType == 1) //Unit 66, ID 6, ON
    {
  digitalWrite(RELAY1,HIGH);           // Turns ON Relays 1
  }
  if (receivedCode.address == 88 && receivedCode.unit == 1 && receivedCode.switchType == 0) //Unit 66, ID 6, OFF
    {
   digitalWrite(RELAY1,LOW);          // Turns Relay Off 
  }
  if (receivedCode.address == 99 && receivedCode.unit == 2 && receivedCode.switchType == 1) //Unit 66, ID 6, ON
    {
  digitalWrite(RELAY2,HIGH);           // Turns ON Relays 1
  }
  if (receivedCode.address == 99 && receivedCode.unit == 2 && receivedCode.switchType == 0) //Unit 66, ID 6, OFF
    {
   digitalWrite(RELAY2,LOW);          // Turns Relay Off 
  }
  }
  