#include <Servo.h>

#define photorPin1 A0 // defind pin A0
#define photorPin2 A1 // defind pin A1
#define photorPin3 A2 // defind pin A2
#define photorPin4 A3 // defind pin A3

Servo myservo1;
Servo myservo2;

int servo1 = 2;
int servo2 = 3;
bool clockWise = true;
int deg = 90;
int photorValue1, photorValue2, photorValue3, photorValue4;

void pinModeValue(int value) {
  pinMode(value, INPUT);
}

void setup() {
  pinModeValue(photorPin1);  // GET Value from LDR0
  pinModeValue(photorPin2);  // GET Value from LDR1
  pinModeValue(photorPin3);  // GET Value from LDR2
  pinModeValue(photorPin4);  // GET Value from LDR3
  //
  //  pinMode(photorPin1, INPUT);
  //  pinMode(photorPin2, INPUT);
  //  pinMode(photorPin3, INPUT);
  //  pinMode(photorPin4, INPUT);
  myservo1.attach(servo1);
  myservo2.attach(servo2);
  Serial.begin(9600);
  myservo1.write(deg);
  myservo2.write(deg);
}

void loop() {
  //  if (clockWise == true) {
  //    deg += 5;
  //  } else {
  //    deg -= 5;
  //  }
  //  if (deg >= 180) {
  //    clockWise = false;
  //  } else if (deg <= 1) {
  //    clockWise = true;
  //  }
  //  myservo1.write(deg);
  //  myservo2.write(deg);

  photorValue1 = analogRead(photorPin1);
  photorValue2 = analogRead(photorPin2);
  photorValue3 = analogRead(photorPin3);
  photorValue4 = analogRead(photorPin4);
  int light1 = map(photorValue1, 0, 1023, 0, 100);
  int light2 = map(photorValue2, 0, 1023, 0, 100);
  int light3 = map(photorValue3, 0, 1023, 0, 100);
  int light4 = map(photorValue4, 0, 1023, 0, 100);

  if (light1 < light2) {
    deg += 20;
  }
  else {
    deg -= 20;
  }
  myservo1.write(deg);
  myservo2.write(deg);

  Serial.print("Light1 :");
  Serial.println(light1);
  Serial.print("\n");
  Serial.print("Light2 :");
  Serial.println(light2);
  Serial.print("\n");
  Serial.print("Light3 :");
  Serial.println(light3);
  Serial.print("\n");
  Serial.print("Light4 :");
  Serial.println(light4);
  Serial.print("\n");
  delay(1000);
}
