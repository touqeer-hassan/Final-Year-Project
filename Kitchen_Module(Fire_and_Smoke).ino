int buzzer = 11;
int smokeA0 = A5;
int flameA0 = A0;
// Your threshold value
int sensorThres = 400;

void setup() {
  pinMode(buzzer, OUTPUT);
  pinMode(smokeA0, INPUT);
  pinMode(flameA0, INPUT);
  Serial.begin(9600);
}

void loop()
{
  int analogSensor = analogRead(smokeA0);
  int flameRead = analogRead(flameA0);

  Serial.print("Flame: ");
  Serial.println(flameRead);
  // Checks if it has reached the threshold value
  if (analogSensor > sensorThres || flameRead < sensorThres)
  {
    tone(buzzer, 1000, 200);
  }
  else
  {
    noTone(buzzer);
  }
  delay(100);
}
