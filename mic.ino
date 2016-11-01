int MIC_PIN = A0;


int led = 13;


void setup()


{


Serial.begin(115200);


pinMode(MIC_PIN, INPUT);


pinMode(led, OUTPUT);


}




int count = 0; // 計算收到幾次的高音量









void loop()


{


int mic = analogRead(MIC_PIN); // 讀取麥克風輸出


// Serial.println(mic);


if(mic >= 400){ // 這裡寫死400，可試試別的值


count++;


Serial.print("mic >= 400, count=");


Serial.println(count);


digitalWrite(led, HIGH);


}


else{


digitalWrite(led, LOW);


}


}
