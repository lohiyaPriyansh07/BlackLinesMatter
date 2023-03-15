//declaring mototrs pin
int motor1pin1 = 2;
int motor1pin2 = 4;
int motor2pin1 = 7;
int motor2pin2 = 8;

//delcaring speedControl
int motorspeed=170;
int curvespeed=130;

//sensors pins
int s1=A0;
int s2=A1;
int s3=A2;
int s4=A3;
int s5=A4;

//sensor data collecting variable
int datas1;
int datas2;
int datas3;
int datas4;
int datas5;
int dtt=400;
int dtt2=250;

//movestraight
void movestraight(){
    analogWrite(3, motorspeed); //ENA pin
    analogWrite(5, motorspeed); //ENB pin
    
    digitalWrite(motor1pin1, LOW);
    digitalWrite(motor1pin2, HIGH);

    digitalWrite(motor2pin1, LOW);
    digitalWrite(motor2pin2, HIGH);
}

//curveturnleft
void curveturnleft(){
    analogWrite(3, curvespeed); //ENA pin
    analogWrite(5, motorspeed); //ENB pin
    digitalWrite(motor1pin1, LOW);
    digitalWrite(motor1pin2, HIGH);

    digitalWrite(motor2pin1, LOW);
    digitalWrite(motor2pin2, HIGH);
    
}

//curveturnright
void curveturnright(){
    analogWrite(3, motorspeed); //ENA pin
    analogWrite(5, curvespeed); //ENB pin
    digitalWrite(motor1pin1, LOW);
    digitalWrite(motor1pin2, HIGH);

    digitalWrite(motor2pin1, LOW);
    digitalWrite(motor2pin2, HIGH);
}

//finish
//void finish(){
//            analogWrite(3, motorspeed); //ENA pin
//            analogWrite(5, motorspeed); //ENB pin
//            digitalWrite(motor1pin1, LOW);
//            digitalWrite(motor1pin2, LOW);
//            digitalWrite(motor2pin1, LOW);
//            digitalWrite(motor2pin2, LOW);
//}

//turnleft
void turnleft(){
    analogWrite(3, 200); //ENA pin
    analogWrite(5, 200); //ENB pin
    digitalWrite(motor1pin1, LOW);
    digitalWrite(motor1pin2, LOW);

    digitalWrite(motor2pin1, LOW);
    digitalWrite(motor2pin2, HIGH);    
}

//turnright
void turnright(){
    analogWrite(3, motorspeed); //ENA pin
    analogWrite(5, motorspeed); //ENB pin
    digitalWrite(motor1pin1, LOW);
    digitalWrite(motor1pin2, HIGH);

    digitalWrite(motor2pin1, LOW);
    digitalWrite(motor2pin2, LOW);
}

//reverseturn 
void reverseturn(){
    analogWrite(3, motorspeed); //ENA pin
    analogWrite(5, motorspeed); //ENB pin
    digitalWrite(motor1pin1, LOW);
    digitalWrite(motor1pin2, HIGH);

    digitalWrite(motor2pin1, HIGH);
    digitalWrite(motor2pin2, LOW);
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
//  for mototr pins
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);

//for speed controller
  pinMode(3, OUTPUT); 
  pinMode(5, OUTPUT);

//  for IR sensor
//
  pinMode(s1,INPUT);
  pinMode(s2,INPUT);
  pinMode(s3,INPUT);
  pinMode(s4,INPUT);
  pinMode(s5,INPUT);
  
}

void loop() {

//taking sensor inputs
  datas1=digitalRead(s1);
  datas2=digitalRead(s2);
  datas3=digitalRead(s3);
  datas4=digitalRead(s4);
  datas5=digitalRead(s5);
  if((datas3==1) && (datas1==0 && datas2==0 && datas4==0 && datas5==0)){
    movestraight();
  }
  else if((datas2==1)&&(datas1==0 && datas4==0 && datas5==0)){
    curveturnleft();
  }
  else if(datas1==1){
    turnleft();
    delay(200);
  }
   else if((datas4==1)&&(datas1==0 && datas2==0 && datas5==0)){
    curveturnright();
  }

//during right we have to always check for right T
  else if(datas5==1 && datas1==1 && datas4==1){
     movestraight();
     delay(dtt2);
     if(datas4==0 && datas5==0 && datas1==0 && datas2==0 && datas3==0){
     turnright();
     delay(dtt);
     }
     else {
          movestraight();
     }
  }
  
  
  else if(datas1==datas2==datas3==datas4==datas5==0){
    reverseturn();
//    delay(dtt);
  }
}
