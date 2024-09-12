/**********************************************************************
  Filename    : Sketch_4.1.1_LEDs_Emit_Different_Brightness
  Description : LEDs Emit Different Brightness
  Auther      : www.freenove.com
  Modification: 2024/08/05
**********************************************************************/

// set pin numbers:
int ledPin = 13;
void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
}

void loop()
{
  // set the ports output PWM waves with differrent duty cycle
  analogWrite(ledPin, map(10, 0, 100, 0, 255));
  delay(3000);
  analogWrite(ledPin, map(50, 0, 100, 0, 255));
  delay(3000);
}

