
int ledPin = 9; //LED pin
int trigPin = 2; //Ultrasonic trigger
int echoPin = 3; //Ultrasonic echo
int ldrPin = A0; //Photoresistor
int buzzerPin = 10; //Piezo buzzer

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ldrPin, INPUT_PULLUP);
  pinMode(buzzerPin, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  //Uncomment the activities one at a time
  //Make sure to comment out the previous activity

  activity1();   //Blink an LED
  //activity2(); //Ultrasonic controls LED brightness
  //activity3(); //Photoresistor controls LED brightness
  //activity4(); //Ultrasonic controls buzzer sound
  //activity5(); //Photoresistor controls buzzer sound
  //activity6(); //Detect laser with photoresistor

  //Rest is up to you! A fun project would be
  //making a laser alarm system. When someone
  //breaks the laser beam, the LED should flash
  //and the buzzer should start beeping.
}

//ACTIVITY 1
//Blink an LED
void activity1() {
  digitalWrite(ledPin, HIGH);
  delay(500);
  digitalWrite(ledPin, LOW);
  delay(500);
}

//ACTIVITY 2
//Ultrasonic sensor controls LED brightness
void activity2() {
  pulse();
  long duration = pulseIn(echoPin, HIGH, 30000);
  int distance = duration * 0.0344 / 2;

  Serial.print("Distance: ");
  Serial.println(distance);

  int ledBrightness = map(distance, 0, 200, 255, 0);
  ledBrightness = constrain(ledBrightness, 0, 255);
  analogWrite(ledPin, ledBrightness);
  delay(100);
}

//ACTIVITY 3
//Photoresistor controls LED brightness
void activity3() {
  int ldrValue = analogRead(ldrPin);
  int ledBrightness = map(ldrValue, 0, 1023, 255, 0);

  analogWrite(ledPin, ledBrightness);
  delay(100);
}

//ACTIVITY 4
//Control piezo buzzer sound using ultrasonic sensor
void activity4() {
  pulse();
  long duration = pulseIn(echoPin, HIGH, 30000);
  int distance = duration * 0.0344 / 2;

  int buzzerFrequency = map(distance, 0, 200, 1000, 3000);
  buzzerFrequency = constrain(buzzerFrequency, 1000, 3000);

  tone(buzzerPin, buzzerFrequency);
  delay(100);
}

//ACTIVITY 5
//Control piezo buzzer sound using photoresistor
void activity5() {
  int ldrValue = analogRead(ldrPin);
  int buzzerFrequency = map(ldrValue, 0, 1023, 1000, 3000);

  tone(buzzerPin, buzzerFrequency);
  delay(100);
}

//ACTIVITY 6
//Detect laser with photoresistor
void activity6() {
  int ldrValue = analogRead(ldrPin);
  Serial.println(ldrValue);

  if (ldrValue > 100) {
    digitalWrite(ledPin, HIGH);
  }
  else {
    digitalWrite(ledPin, LOW);
  }
}

//Ultrasonic sensor pulse
void pulse() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
}