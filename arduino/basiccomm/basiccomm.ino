const int TRIG = 12;
const int ECHO = 13;

const int L1 = 2; // #1 LED green
const int L2 = 3; // #2 LED green
const int L3 = 4; // #3 LED yellow
const int L4 = 5; // #4 LED yellow
const int L5 = 6; // #5 LED red
const int L6 = 7; // #6 LED red

String dataIn;
int duration;
int distance;

void setup() {
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);

  pinMode(L1, OUTPUT);
  pinMode(L2, OUTPUT);
  pinMode(L3, OUTPUT);
  pinMode(L4, OUTPUT);
  pinMode(L5, OUTPUT);
  pinMode(L6, OUTPUT);
  
  Serial.begin(115200);
}

void loop() {
  
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  // write to serial
  duration = pulseIn(ECHO, HIGH);
  Serial.print(duration, DEC);

  //read from serial
  dataIn = Serial.readString();
  distance = dataIn.toInt();

  // process LEDs
  processLEDs(distance);
  
  delay(500);

}

void processLEDs(int distance){
  if(distance > 50){
    digitalWrite(L1, HIGH);
    digitalWrite(L2, LOW);
    digitalWrite(L3, LOW);
    digitalWrite(L4, LOW);
    digitalWrite(L5, LOW);
    digitalWrite(L6, LOW);
  }
  else if(distance > 20){
    digitalWrite(L1, HIGH);
    digitalWrite(L2, HIGH);
    digitalWrite(L3, LOW);
    digitalWrite(L4, LOW);
    digitalWrite(L5, LOW);
    digitalWrite(L6, LOW);
  }
  else if(distance > 15){
    digitalWrite(L1, HIGH);
    digitalWrite(L2, HIGH);
    digitalWrite(L3, HIGH);
    digitalWrite(L4, LOW);
    digitalWrite(L5, LOW);
    digitalWrite(L6, LOW);
  }
  else if(distance > 10){
    digitalWrite(L1, HIGH);
    digitalWrite(L2, HIGH);
    digitalWrite(L3, HIGH);
    digitalWrite(L4, HIGH);  
    digitalWrite(L5, LOW);
    digitalWrite(L6, LOW);     
  }
  else if(distance > 5){
    digitalWrite(L1, HIGH);
    digitalWrite(L2, HIGH);
    digitalWrite(L3, HIGH);
    digitalWrite(L4, HIGH);
    digitalWrite(L5, HIGH);
    digitalWrite(L6, LOW);     
  }
  else if(distance > 1){
    digitalWrite(L1, HIGH);
    digitalWrite(L2, HIGH);
    digitalWrite(L3, HIGH);
    digitalWrite(L4, HIGH);
    digitalWrite(L5, HIGH);
    digitalWrite(L6, HIGH);     
  }
  else{
    digitalWrite(L1, LOW);
    digitalWrite(L2, LOW);
    digitalWrite(L3, LOW);
    digitalWrite(L4, LOW);
    digitalWrite(L5, LOW);
    digitalWrite(L6, LOW);     
  }
}

