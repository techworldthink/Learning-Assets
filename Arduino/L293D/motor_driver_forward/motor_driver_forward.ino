

// Motor driver pins
const int L1 = 5;
const int L2 = 6;
const int R1 = 3;
const int R2 = 4;



void setup() {
  pinMode(L1,OUTPUT);
  pinMode(L2,OUTPUT);
  pinMode(R1,OUTPUT);
  pinMode(R2,OUTPUT);



}

void loop() {

  forward();
 

 

}

void forward(){
  digitalWrite(L1,HIGH);
  digitalWrite(L2,LOW);
  digitalWrite(R1,HIGH);
  digitalWrite(R2,LOW);
}
