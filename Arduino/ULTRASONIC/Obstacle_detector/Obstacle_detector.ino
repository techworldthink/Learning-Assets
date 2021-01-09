// Motor driver pins
const int L1 = 5;
const int L2 = 6;
const int R1 = 3;
const int R2 = 4;

//Ultrasonic device pins
const int trigPin = 9;
const int echoPin = 10;
// variables for ultrasonic
long duration;
int distance;

void setup() {
  pinMode(L1,OUTPUT);
  pinMode(L2,OUTPUT);
  pinMode(R1,OUTPUT);
  pinMode(R2,OUTPUT);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

}

void loop() {

  forward();
  distance=ultrasonic_check();
  if(distance<20)
  {
    right();
    delay(1000);
  }
 

}

void forward(){
  digitalWrite(L1,HIGH);
  digitalWrite(L2,LOW);
  digitalWrite(R1,HIGH);
  digitalWrite(R2,LOW);
}
void right(){
  digitalWrite(L1,LOW);
  digitalWrite(L2,LOW);
  digitalWrite(R1,HIGH);
  digitalWrite(R2,LOW);
}

int ultrasonic_check(){
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
// Calculating the distance
distance= duration*0.034/2;
return distance;
}
