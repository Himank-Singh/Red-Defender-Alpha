#include <Servo.h>

int x_pin = 9;
int x1_axis, x2_axis;
String x1_angle, x2_angle;

Servo myServo;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  myServo.attach(x_pin);
  Serial.println("Start");
}

void loop() {
  // put your main code here, to run repeatedly:
  while(Serial.available() == 0){

  }
  while(true){
    x1_angle = Serial.readStringUntil('\n');
    x2_angle = Serial.readStringUntil('\n');
    x1_axis = x1_angle.toInt();
    x2_axis = x2_angle.toInt();
    myServo.write(x1_axis);
    delay(500);
    myServo.write(x2_axis);
    delay(500);
    Serial.println("Done");
  }
}
