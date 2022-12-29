#include <Servo.h>
Servo mid;
Servo right;
Servo left;

long randNumber;

void setup() {
mid.attach(9);
right.attach(5);
left.attach(6);

mid.write(65);
right.write(90);
left.write(90);
Serial.begin(9600);
}

void loop() {
delay(1000);
wakeup();
randNumber = random(10,30);
delay(randNumber*100);
for (int i=0; i<3; i++){
  randNumber = random(1,3);
  if (randNumber == 2){
    left_motion();
    delay(1500);
    middle();
    delay(500);
  }
  else {
    right_motion();
    delay(1500);
    middle();
    delay(500);
  }
}
sleep();
delay(1500);

}

void left_motion(){
right.write(70);
left.write(70);
}
void right_motion(){
right.write(120);
left.write(120);
}

void wakeup(){
  mid.write(10);
}

void sleep(){
mid.write(75);
}

void middle(){
right.write(90);
left.write(90); 
}

