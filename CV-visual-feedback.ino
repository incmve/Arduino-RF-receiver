/*
* Demo for RF remote switch receiver. 
* This example is for the new KaKu / Home Easy type of remotes!

* For details, see NewRemoteReceiver.h!
*
* This sketch shows the received signals on the serial port.
* Connect the receiver to digital pin 2.
*/


#include <NewRemoteReceiver.h>
int ledPinR = 6;    // Red LED connected to digital pin 6
int ledPinB = 5;    // Blue LED connected to digital pin 9

void setup() {
  Serial.begin(115200);
    NewRemoteReceiver::init(0, 2, showCode);
 //NewRemoteReceiver::init(0, 2, showCode);
  
  // Initialize receiver on interrupt 0 (= digital pin 2), calls the callback "showCode"
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
void showCode(NewRemoteCode receivedCode) {
  // Note: interrupts are disabled. You can re-enable them if needed.
  
  // Print the received code.
  
 
    if (receivedCode.address == 66 && receivedCode.unit == 6 && receivedCode.switchType == 1)
    {  
      analogWrite(ledPinB, 0);
	for(int i = 0; i < 3; i++)
	{
  delay(500);
       // fade in from min to max in increments of 5 points:
  for(int fadeValue = 0 ; fadeValue <= 255; fadeValue +=1) { 
    // sets the value (range from 0 to 255):
    analogWrite(ledPinR, fadeValue);         
    // wait for 30 milliseconds to see the dimming effect    
    delay(500);                            
  } 

  // fade out from max to min in increments of 5 points:
  for(int fadeValue = 255 ; fadeValue >= 0; fadeValue -=2) { 
    // sets the value (range from 0 to 255):
    analogWrite(ledPinR, fadeValue);         
    // wait for 30 milliseconds to see the dimming effect    
    delay(500);     
  }
}  
  }
  if (receivedCode.address == 66 && receivedCode.unit == 6 && receivedCode.switchType == 0)
    {
    analogWrite(ledPinR, 0);  
	for(int i = 0; i < 3; i++)
	{
  delay(500);
       // fade in from min to max in increments of 5 points:
  for(int fadeValue = 0 ; fadeValue <= 255; fadeValue +=1) { 
    // sets the value (range from 0 to 255):
    analogWrite(ledPinB, fadeValue);         
    // wait for 30 milliseconds to see the dimming effect    
    delay(500);                            
  } 

  // fade out from max to min in increments of 5 points:
  for(int fadeValue = 255 ; fadeValue >= 0; fadeValue -=2) { 
    // sets the value (range from 0 to 255):
    analogWrite(ledPinB, fadeValue);         
    // wait for 30 milliseconds to see the dimming effect    
    delay(500);     
  }
}  
  }
  
  
  Serial.print(", period: "); //
  Serial.print(receivedCode.period); //
  Serial.println("us."); //
}



