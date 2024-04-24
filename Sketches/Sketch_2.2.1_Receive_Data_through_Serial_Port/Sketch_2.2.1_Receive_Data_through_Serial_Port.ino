/*
  Sketch 2.2.1
  Receive Data through Serial Port

  modified 2024/4/18
  by http://www.freenove.com
*/

char inChar;      // define a variable to store characters received from serial port

void setup() {
  Serial.begin(9600);                 // initialize serial port, set baud rate to 9600
  Serial.println("UNO is ready!");    // print the string "UNO is ready!"
}

void loop() {
  if (Serial.available()) {         // judge whether data has been received
    inChar = Serial.read();         // read one character
    Serial.print("UNO received:");  // print the string "UNO received:"
    Serial.println(inChar);         // print the received character
  }
}

