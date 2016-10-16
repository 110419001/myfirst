 int ledCount =10;
  int ledPins[]={2,3,4,5,6,7,8,9,10,11};

void setup() {
  // put your setup code here, to run once:
   Serial.begin(9600);
  for(int thisLed=0;thisLed<ledCount;thisLed++){
    pinMode(ledPins[thisLed],OUTPUT);
  }
}


void loop() {
  // put your main code here, to run repeatedly:
  int sensorValue = analogRead(A0);
  Serial.println(sensorValue);
  int ledLevel=map(sensorValue,420,949,0,ledCount);
  if(sensorValue>=949)sensorValue=949;
  if(sensorValue<=420)sensorValue=420;
  for(int thisLed=0;thisLed<ledCount;thisLed++){
    if(thisLed<ledLevel){
      digitalWrite(ledPins[thisLed],LOW);
    }
    else{
      digitalWrite(ledPins[thisLed],HIGH);
    }
  }
  delay(1);
}
