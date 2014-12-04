/*
*  
* https://github.com/incmve/Arduino-RF-receiver
*
*
* switchtype 1 = on
* switchtype 2 = off
* switchtype 3 = dim
* For details, see NewRemoteReceiver.h!
*
* This sketch receives a KAKU signal and fades an RGB LED.
* Connect the receiver to digital pin 2.
*
*/


#include <NewRemoteReceiver.h>
int ledPinR = 6;    // Red LED connected to digital pin 6
int ledPinB = 5;    // Blue LED connected to digital pin 5
int ledPinG = 3;    // Green LED connected to digital pin 4

void setup() {
  Serial.begin(115200);
    NewRemoteReceiver::init(0, 2, egg);
  
  // Initialize receiver on interrupt 0 (= digital pin 2), calls the callback "egg"
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
void egg(NewRemoteCode receivedCode) {
  // Note: interrupts are disabled. You can re-enable them if needed.
  
 
    if (receivedCode.address == 66 && receivedCode.unit == 6 && receivedCode.switchType == 2 && receivedCode.dimLevel == 1) // Unit 66 ID 6 dim level 1 RED
	{  
	analogWrite(ledPinR, 0); 
	analogWrite(ledPinG, 0);
	analogWrite(ledPinB, 0);
	for(int i = 0; i < 3; i++)
		{
  delay(500);
  Serial.print("Off"); //print to serial
       // fade in from min to max in increments of 5 points:
  for(int fadeValue = 0 ; fadeValue <= 255; fadeValue +=1) { 
    // sets the value (range from 0 to 255):
    analogWrite(ledPinR, fadeValue);         
    // wait for 500 milliseconds to see the dimming effect    
    delay(500);                            
			} 

  // fade out from max to min in increments of 5 points:
  for(int fadeValue = 255 ; fadeValue >= 15; fadeValue -=1) { 
    // sets the value (range from 0 to 255):
    analogWrite(ledPinR, fadeValue);         
    // wait for 500 milliseconds to see the dimming effect    
    delay(500);     
			}
		}  
	}
  if (receivedCode.address == 66 && receivedCode.unit == 6 && receivedCode.switchType == 2 && receivedCode.dimLevel == 2) // Unit 66 ID 6 dim level 2 BLUE
	{
	analogWrite(ledPinR, 0); 
	analogWrite(ledPinG, 0);
	analogWrite(ledPinB, 0);
	for(int i = 0; i < 3; i++)
		{
  delay(500);
  Serial.print("On"); //print to serial
       // fade in from min to max in increments of 5 points:
  for(int fadeValue = 0 ; fadeValue <= 255; fadeValue +=1) { 
    // sets the value (range from 0 to 255):
    analogWrite(ledPinB, fadeValue);         
    // wait for 500 milliseconds to see the dimming effect    
    delay(500);                            
  } 

  // fade out from max to min in increments of 5 points:
  for(int fadeValue = 255 ; fadeValue >= 15; fadeValue -=1) { 
    // sets the value (range from 0 to 255):
    analogWrite(ledPinB, fadeValue);         
    // wait for 500 milliseconds to see the dimming effect    
    delay(500);     
			}
		}  
	}
    if (receivedCode.address == 66 && receivedCode.unit == 6 && receivedCode.switchType == 2 && receivedCode.dimLevel == 3) // Unit 66 ID 6 dim level 3 Blink RED
    {
	analogWrite(ledPinR, 0); 
	analogWrite(ledPinG, 0);
	analogWrite(ledPinB, 0);
		{
	BlinkR(ledPinR,10);
	delay(50);
		}
	}
    if (receivedCode.address == 66 && receivedCode.unit == 6 && receivedCode.switchType == 2 && receivedCode.dimLevel == 4) // Unit 66 ID 6 dim level 4 Blink RED/BLUE
    {
	analogWrite(ledPinR, 0); 
	analogWrite(ledPinG, 0);
	analogWrite(ledPinB, 0);
		{
	BlinkRB(ledPinR,10);
	delay(50);
		}
	}
    if (receivedCode.address == 66 && receivedCode.unit == 6 && receivedCode.switchType == 2 && receivedCode.dimLevel == 5) // Unit 66 ID 6 dim level 5 Glow PINK
	{
  	analogWrite(ledPinR, 0); 
	analogWrite(ledPinG, 0);
	analogWrite(ledPinB, 0);
	// Glow Pink
	analogWrite(ledPinR, 255); 
	analogWrite(ledPinG, 51);
	analogWrite(ledPinB, 153); 
	}
    if (receivedCode.address == 66 && receivedCode.unit == 6 && receivedCode.switchType == 2 && receivedCode.dimLevel == 6) // Unit 66 ID 6 dim level 6 Glow GREEN
	{
  	analogWrite(ledPinR, 0); 
	analogWrite(ledPinG, 0);
	analogWrite(ledPinB, 0);
	// Glow Green
	analogWrite(ledPinG, 255);
	}

//Blink routine
}
void BlinkR(int led, int times) // Unit 66 ID 6 dim level 3
{
 for (int i=0; i< times; i++)
 {
  digitalWrite(ledPinR,HIGH);
  delay (10000);
  digitalWrite(ledPinR,LOW);
  delay (10000);
 }
}
void BlinkRB(int led, int times) // Unit 66 ID 6 dim level 4
{
 for (int i=0; i< times; i++)
 {
  digitalWrite(ledPinB,HIGH);
  delay (10000);
  digitalWrite(ledPinR,HIGH);
  delay (10000);
  digitalWrite(ledPinB,LOW);
  delay (10000);
  digitalWrite(ledPinR,LOW);
  delay (10000);
 }
}


