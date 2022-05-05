#define buzzer 11
#define fsrPin A0 // analog pin0 , the sensor output is connected here.
#define ECHO_PIN 8
#define TRIG_PIN 9
int fsrReading;
int threshold = 100;
int safe_distance = 10;


void setup() {
  Serial.begin(9600);
  pinMode(ECHO_PIN, INPUT);
  pinMode(TRIG_PIN, OUTPUT);
}

void loop() {
  //get the FSR reading
  fsrReading = analogRead(fsrPin); //this is used for debug purposes only.

  Serial.print("FSR data: ");
  Serial.println(fsrReading);
  //  lcd.clear();
  //  lcd.setCursor(0,0);
  //  lcd.print(analogReading);
  if (fsrReading < threshold) {
    tone(buzzer, 700);
    delay(300);
    noTone(buzzer);
  }

  //get the ultrasonic reading.
  int distance = readDistance();
  Serial.print("distance= ");
  Serial.println(distance);
  if(distance < safe_distance){
    tone(buzzer,1000);
    delay(300);
    noTone(buzzer);
  }

  delay(1000);
}



//method for reading distance from ultrasonic sensor (in cm)
int readDistance() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH);

  return duration * 0.034 / 2;
}
