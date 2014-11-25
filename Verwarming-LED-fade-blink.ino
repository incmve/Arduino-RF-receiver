/*
*  
* https://github.com/incmve/Arduino-RF-receiver
*
* For details, see NewRemoteReceiver.h!
*
* This sketch receives a KAKU signal and fades an RGB LED.
* Connect the receiver to digital pin 2.
*
*/


#include <NewRemoteReceiver.h>
int ledPinR = 6;    // Red LED connected to digital pin 6
int ledPinB = 5;    // Blue LED connected to digital pin 5
int ledPinG = 4;    // Green LED connected to digital pin 4

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
  
 
    if (receivedCode.address == 66 && receivedCode.unit == 6 && receivedCode.switchType == 1) // Unit 66 ID 6 Off signal
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
  for(int fadeValue = 255 ; fadeValue >= 10; fadeValue -=1) { 
    // sets the value (range from 0 to 255):
    analogWrite(ledPinR, fadeValue);         
    // wait for 500 milliseconds to see the dimming effect    
    delay(500);     
			}
		}  
	}
  if (receivedCode.address == 66 && receivedCode.unit == 6 && receivedCode.switchType == 0) // Unit 66 ID 6 On signal
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
  for(int fadeValue = 255 ; fadeValue >= 10; fadeValue -=1) { 
    // sets the value (range from 0 to 255):
    analogWrite(ledPinB, fadeValue);         
    // wait for 500 milliseconds to see the dimming effect    
    delay(500);     
			}
		}  
	}
	if (receivedCode.address == 66 && receivedCode.unit == 7 && receivedCode.switchType == 0) // Unit 66 ID 7 On signal
    {
	analogWrite(ledPinR, 0); 
	analogWrite(ledPinG, 0);
	analogWrite(ledPinB, 0);
		{
	BlinkR(ledPinR,20);
	delay(50);
		}
	}
	if (receivedCode.address == 66 && receivedCode.unit == 7 && receivedCode.switchType == 1) // Unit 66 ID 7 Off signal
    {
	analogWrite(ledPinR, 0); 
	analogWrite(ledPinG, 0);
	analogWrite(ledPinB, 0);
		{
	BlinkRB(ledPinR,20);
	delay(50);
		}
	}
	if (receivedCode.address == 66 && receivedCode.unit == 8 && receivedCode.switchType == 0) // Unit 66 ID 8 On signal
	{
	// Glow Pink
	analogWrite(ledPinR, 255); 
	analogWrite(ledPinG, 204);
	analogWrite(ledPinB, 255); 
	}

//Blink routine
}
void BlinkR(int led, int times) //Unit 66 ID 7 On Blink
{
 for (int i=0; i< times; i++)
 {
  digitalWrite(ledPinR,HIGH);
  delay (250);
  digitalWrite(ledPinR,LOW);
  delay (250);
 }
}
void BlinkRB(int led, int times) //Unit 66 ID 7 Off Blink
{
 for (int i=0; i< times; i++)
 {
  digitalWrite(ledPinR,HIGH);
  delay (250);
  digitalWrite(ledPinR,LOW);
  delay (250);
  digitalWrite(ledPinB,HIGH);
  delay (250);
  digitalWrite(ledPinB,LOW);
  delay (250);
 }
}


