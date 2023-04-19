#include <SoftwareSerial.h>
SoftwareSerial BTSerial(0, 1); // RX | TX
#include <Servo.h> // Import the Servo library
Servo myservo;  // Create a servo object


void setup() {
  myservo.attach(8);  //
   Connect the servo to pin 8
  // setup the BT serial port
  BTSerial.begin(9600);  
  Serial.begin(9600);
  myservo.write(90);
 

}

void loop() {
  if (BTSerial.available()) {
    char c = BTSerial.read();
    if (c == '1') {
      myservo.write(115);
      delay(100);
      myservo.write(90);
      delay(2000);
    }
    if (c == '0') {
      myservo.write(60);
      delay(100);
      myservo.write(90);
      delay(2000);
    }
    if (c == '2') {
      while (BTSerial.read() != '4') { // Loop until '3' is received
      myservo.write(60);
      delay(100);
      myservo.write(90);
      delay(100);
      }
    }
    if (c == '3') {
      while (BTSerial.read() != '4') { // Loop until '4' is received
        myservo.write(115);
        delay(100);
        myservo.write(90);
        delay(100);
      }
    }
  }
}
