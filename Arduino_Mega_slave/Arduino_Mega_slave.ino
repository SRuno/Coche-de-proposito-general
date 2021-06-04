#include <AFMotor.h>
#include <Servo.h>

Servo servo;

AF_DCMotor motor4(4);
AF_DCMotor motor3(3);
AF_DCMotor motor2(2);
AF_DCMotor motor1(1);

const int der = 45;   
const int iz = 49;    
const int rec = 47;  
const int fw = 52;   
const int bw = 50;    
const int id = 44; 

int pos = 0 ;

void setup(){
  Serial.begin(115200);
  servo.attach(9);
  
  motor4.setSpeed(0);
  motor3.setSpeed(0);
  motor2.setSpeed(0);
  motor1.setSpeed(0);
  
  motor4.run(RELEASE);
  motor3.run(RELEASE);
  motor2.run(RELEASE);
  motor1.run(RELEASE);
  
  pinMode ( der , INPUT );
  pinMode ( iz , INPUT );
  pinMode ( rec , INPUT );
  pinMode ( fw , INPUT );
  pinMode ( bw , INPUT );
  pinMode ( id , INPUT );
  
}

void loop() {
   if ( digitalRead(fw) == true){
    Serial.println("palante");
    
    motor4.run(FORWARD);
    motor3.run(FORWARD);
    motor2.run(FORWARD);
    motor1.run(FORWARD);

    motor4.setSpeed(200);
    motor3.setSpeed(200);
    motor2.setSpeed(200);
    motor1.setSpeed(200);
   }
   if ( digitalRead(bw) == true){
    Serial.println("patra");

    motor4.run(BACKWARD);
    motor3.run(BACKWARD);
    motor2.run(BACKWARD);
    motor1.run(BACKWARD);

    motor4.setSpeed(200);
    motor3.setSpeed(200);
    motor2.setSpeed(200);
    motor1.setSpeed(200);
   }
   if ( digitalRead(id) == true){
    Serial.println("quietol");

    motor4.run(RELEASE);
    motor3.run(RELEASE);
    motor2.run(RELEASE);
    motor1.run(RELEASE);

    motor4.setSpeed(0);
    motor3.setSpeed(0);
    motor2.setSpeed(0);
    motor1.setSpeed(0);
   }
   if ( digitalRead(der) == true){
    Serial.println("Derecha");
    
    motor4.run(FORWARD);
    motor3.run(FORWARD);
    motor2.run(BACKWARD);
    motor1.run(BACKWARD);

    motor4.setSpeed(150);
    motor3.setSpeed(150);
    motor2.setSpeed(150);
    motor1.setSpeed(150);
   }
   if ( digitalRead(iz) == true){
    Serial.println("Izquierda");
    
    motor4.run(BACKWARD);
    motor3.run(BACKWARD);
    motor2.run(FORWARD);
    motor1.run(FORWARD);

    motor4.setSpeed(150);
    motor3.setSpeed(150);
    motor2.setSpeed(150);
    motor1.setSpeed(150);
   }
   if ( digitalRead(rec) == true){
    Serial.println("errecto");
    
    motor4.run(RELEASE);
    motor3.run(RELEASE);
    motor2.run(RELEASE);
    motor1.run(RELEASE);

    motor4.setSpeed(0);
    motor3.setSpeed(0);
    motor2.setSpeed(0);
    motor1.setSpeed(0);;
   }
}
