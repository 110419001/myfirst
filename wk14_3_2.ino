#include <Wire.h>
#include <Servo.h>

Servo myservo;
int value = 0;
int motorstatus = 0;
void setup() {
  Wire.begin(8);                // join i2c bus with address #8
  Wire.onReceive(receiveEvent); // register event
  pinMode(13,OUTPUT);
  Serial.begin(115200);           // start serial for output
  myservo.attach(13);
}

void loop() {
  delay(100);
  if(motorstatus){
  if (value == 0) 
    value = 180;
  else
    value = 0;
  myservo.write(value); 
  delay(1500);}

}

// function that executes whenever data is received from master
// this function is registered as an event, see setup()
void receiveEvent(int howMany) {
  while (1 < Wire.available()) { // loop through all but the last
    char c = Wire.read(); // receive byte as a character
    Serial.print(c);         // print the character
  }
  int x = Wire.read();    // receive byte as an integer
  if(x == 0){
     
     motorstatus = 1;
  }
  else if(x == 1){
   
     motorstatus = 0;
  }
  Serial.println(x);  
  Serial.println(motorstatus);// print the integer
}
