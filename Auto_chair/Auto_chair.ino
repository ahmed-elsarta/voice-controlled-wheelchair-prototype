int buzzer = 11;
char receivedChar;
boolean newData = false;
String voice;

#define fsrPin A0 // analog pin0 , the sensor output is connected here.
#define ECHO_PIN 8
#define TRIG_PIN 9
int fsrReading;
int threshold = 100;
int safe_distance = 10;

int M1 = 7;
int M2 = 6;
int M3 = 5;
int M4 = 4;

void setup() {
  Serial.begin(9600);
  Serial.println("<Arduino is ready>");
  pinMode(ECHO_PIN, INPUT);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(M1, OUTPUT);
  pinMode(M2, OUTPUT);
  pinMode(M3, OUTPUT);
  pinMode(M4, OUTPUT);
}

void loop() {
  checkFsr(); //Check the force on the chair (to make sure user hasn't fallen down)
  checkDis(); // Check the distance in front of the chair
  recvOneChar(); //check if there's a new order recieved from the app
  showNewData(); //display the order on the serial (for debug purposes)
  steer(receivedChar); //use the order recieved from the app to move.

}

//method for steering, (input) is instructions recieved from the app
void steer(char input) {
  switch (input) {
    case 'l':
      Serial.print("I went left.\n");
      left();
      break;
    case 'r' :
      Serial.print("I went right.\n");
      right();
      break;
    case 'g':
      Serial.print("I went forward. \n");
      forward();
      break;
    case 'b' :
      Serial.print("I went back. \n");
      backward();
      break;
    case 'p' :
      Serial.print("I went beep. \n");
      tone(buzzer, 700);
      delay(200);
      noTone(buzzer);
      tone(buzzer, 700);
      delay(200);
      noTone(buzzer);
      break;
    case 's' :
      Serial.print("I stopped. \n");
      Stop();
      break;
    case 'd' :
      Serial.print("I went dance. \n");
      dance();
      break;
  }
}
//receive the instruction from the app (which sends the word to the serial)
void recvOneChar() {
  if (Serial.available() > 0) {
    //if condition to check if there's new instructions, if so, then we can read it.
    receivedChar = Serial.read();
    newData = false;
  }
}

//method for reading distance from ultrasonic sensor (in cm)
int readDistance() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH);

  return duration * 0.034 / 2; //conversion to Cm
}

void checkFsr() {
  fsrReading = analogRead(fsrPin); //this is used for debug purposes only.
  Serial.print("FSR data: ");
  Serial.println(fsrReading);
  if (fsrReading < threshold) {
    Stop();
    buzz();
    receivedChar = 's';

  }
}
void checkDis() {
  int distance = readDistance();
  Serial.print("distance= ");
  Serial.println(distance);
  if (distance < safe_distance) {
    buzz();
    Stop();
    receivedChar = 's';
  }
}
void buzz() {
  tone(buzzer, 700);
  delay(200);
  noTone(buzzer);
}
//function to cheack if there's new data in the serial monitor.
void showNewData() {
  if (newData == true) {
    Serial.print("This just in ... ");
    Serial.println(receivedChar);
    newData = false;
  }
}

//these methods are for movement.
void backward() {
  digitalWrite (M1, HIGH);
  digitalWrite (M2, LOW);
  digitalWrite (M3, HIGH);
  digitalWrite (M4, LOW);
}

void forward() {
  digitalWrite (M1, LOW);
  digitalWrite (M2, HIGH);
  digitalWrite (M3, LOW);
  digitalWrite (M4, HIGH);
}

void left() {
  digitalWrite (M1, HIGH);
  digitalWrite (M2, LOW);
  digitalWrite (M3, LOW);
  digitalWrite (M4, HIGH);

}

void right() {
  digitalWrite (M1, LOW);
  digitalWrite (M2, HIGH);
  digitalWrite (M3, HIGH);
  digitalWrite (M4, LOW);

}

void Stop() {
  digitalWrite (M1, LOW);
  digitalWrite (M2, LOW);
  digitalWrite (M3, LOW);
  digitalWrite (M4, LOW);

}
void circle() {
  digitalWrite (M4, HIGH);
  digitalWrite (M2, LOW);
  digitalWrite (M3, LOW);
  digitalWrite (M1, HIGH);
  delay (100);

}

void dance() {
  digitalWrite (M4, LOW);
  digitalWrite (M2, HIGH);
  digitalWrite (M3, LOW);
  digitalWrite (M1, LOW);
  delay (400);
  digitalWrite(M4, HIGH);
  digitalWrite (M2, HIGH);
  digitalWrite(M3, LOW);
  digitalWrite(M1, LOW);
  delay(600);
  digitalWrite (M4, LOW);
  digitalWrite (M2, HIGH);
  digitalWrite (M3, HIGH);
  digitalWrite (M1, LOW);
  delay (500);
  digitalWrite (M4, HIGH);
  digitalWrite (M2, LOW);
  digitalWrite (M3, LOW);
  digitalWrite (M1, HIGH);
  delay (500);

  digitalWrite (M4, LOW);
  digitalWrite (M2, HIGH);
  digitalWrite (M3, LOW);
  digitalWrite (M1, LOW);
  delay (400);
  digitalWrite(M4, HIGH);
  digitalWrite (M2, HIGH);
  digitalWrite(M3, LOW);
  digitalWrite(M1, LOW);
  delay(600);
  digitalWrite (M4, LOW);
  digitalWrite (M2, HIGH);
  digitalWrite (M3, HIGH);
  digitalWrite (M1, LOW);
  delay (500);
  digitalWrite (M4, HIGH);
  digitalWrite (M2, LOW);
  digitalWrite (M3, LOW);
  digitalWrite (M1, HIGH);
  delay (500);
  digitalWrite (M4, LOW);
  digitalWrite (M2, HIGH);
  digitalWrite (M3, LOW);
  digitalWrite (M1, LOW);
  delay (400);
  digitalWrite(M4, HIGH);
  digitalWrite (M2, HIGH);
  digitalWrite(M3, LOW);
  digitalWrite(M1, LOW);
  delay(600);
  digitalWrite (M4, LOW);
  digitalWrite (M2, HIGH);
  digitalWrite (M3, HIGH);
  digitalWrite (M1, LOW);
  delay (500);
  digitalWrite (M4, HIGH);
  digitalWrite (M2, LOW);
  digitalWrite (M3, LOW);
  digitalWrite (M1, HIGH);
  delay (500);
  digitalWrite (M4, LOW);
  digitalWrite (M2, HIGH);
  digitalWrite (M3, LOW);
  digitalWrite (M1, LOW);
  delay (400);
  digitalWrite(M4, HIGH);
  digitalWrite(M2, HIGH);
  digitalWrite(M3, LOW);
  digitalWrite(M1, LOW);
  delay(600);
  digitalWrite (M4, LOW);
  digitalWrite (M2, HIGH);
  digitalWrite (M3, HIGH);
  digitalWrite (M1, LOW);
  delay (500);
  digitalWrite (M4, HIGH);
  digitalWrite (M2, LOW);
  digitalWrite (M3, LOW);
  digitalWrite (M1, HIGH);
  delay (500);
  digitalWrite (M4, LOW);
  digitalWrite (M2, HIGH);
  digitalWrite (M3, LOW);
  digitalWrite (M1, LOW);
  delay (400);
  digitalWrite(M4, HIGH);
  digitalWrite (M2, HIGH);
  digitalWrite(M3, LOW);
  digitalWrite(M1, LOW);
  delay(600);
  digitalWrite (M4, LOW);
  digitalWrite (M2, HIGH);
  digitalWrite (M3, HIGH);
  digitalWrite (M1, LOW);
  delay (500);
  digitalWrite (M4, HIGH);
  digitalWrite (M2, LOW);
  digitalWrite (M3, LOW);
  digitalWrite (M1, HIGH);
  delay (500);
  digitalWrite (M4, LOW);
  digitalWrite (M2, HIGH);
  digitalWrite (M3, LOW);
  digitalWrite (M1, LOW);
  delay (400);
  digitalWrite(M4, HIGH);
  digitalWrite (M2, HIGH);
  digitalWrite(M3, LOW);
  digitalWrite(M1, LOW);
  delay(600);
  digitalWrite (M4, LOW);
  digitalWrite (M2, HIGH);
  digitalWrite (M3, HIGH);
  digitalWrite (M1, LOW);
  delay (500);
  digitalWrite (M4, HIGH);
  digitalWrite (M2, LOW);
  digitalWrite (M3, LOW);
  digitalWrite (M1, HIGH);
  delay (500);
  digitalWrite (M4, LOW);
  digitalWrite (M2, HIGH);
  digitalWrite (M3, LOW);
  digitalWrite (M1, LOW);
  delay (400);
  digitalWrite(M4, HIGH);
  digitalWrite (M2, HIGH);
  digitalWrite(M3, LOW);
  digitalWrite(M1, LOW);
  delay(600);
  digitalWrite (M4, LOW);
  digitalWrite (M2, HIGH);
  digitalWrite (M3, HIGH);
  digitalWrite (M1, LOW);
  delay (500);
  digitalWrite (M4, HIGH);
  digitalWrite (M2, LOW);
  digitalWrite (M3, LOW);
  digitalWrite (M1, HIGH);
  delay (500);
  digitalWrite (M4, LOW);
  digitalWrite (M2, HIGH);
  digitalWrite (M3, LOW);
  digitalWrite (M1, LOW);
  delay (400);
  digitalWrite(M4, HIGH);
  digitalWrite (M2, HIGH);
  digitalWrite(M3, LOW);
  digitalWrite(M1, LOW);
  delay(600);
  digitalWrite (M4, LOW);
  digitalWrite (M2, HIGH);
  digitalWrite (M3, HIGH);
  digitalWrite (M1, LOW);
  delay (500);
  digitalWrite (M4, HIGH);
  digitalWrite (M2, LOW);
  digitalWrite (M3, LOW);
  digitalWrite (M1, HIGH);
  delay (500);
}
