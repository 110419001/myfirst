int greenPin = 6;


int redPin = 9;


int bluePin = 5;


int counter = 0;//狀態切換




void setup() {


pinMode(greenPin,OUTPUT);


pinMode(redPin,OUTPUT);


pinMode(bluePin,OUTPUT);


}




void loop() {


counter++;


if(counter == 1){//點亮綠色


analogWrite(greenPin,0);


analogWrite(redPin,255);


analogWrite(bluePin,255);


}


else if(counter == 2){//點亮紅色


analogWrite(greenPin,0);


analogWrite(redPin,255);


analogWrite(bluePin,0);


}


else if(counter == 3){//點亮藍色


analogWrite(greenPin,0);


analogWrite(redPin,0);


analogWrite(bluePin,255);


counter = 0;//歸零


}


delay(1000);}
