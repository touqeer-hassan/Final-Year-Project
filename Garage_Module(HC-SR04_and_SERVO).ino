#include <Servo.h>

#define echoPin 7 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 6 //attach pin D3 Arduino to pin Trig of HC-SR04
#define servoPin 8

//int buttonPin = 2;

long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement
int resultDistance;
int pos = 0;
int buttonState = 0; 
bool gateStatus;
bool isParked;

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

void setup()
{
  // set up the LCD's number of columns and rows:
  Serial.begin(9600);
  // Print a message to the LCD.


  //Distance Sensor Module
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT

  //Servo Motor
  myservo.attach(servoPin);  // attaches the servo on pin 9 to the servo object

//  pinMode(buttonPin, INPUT);
}

void loop()
{
  Serial.print("Distance: ");
  Serial.print(showDistance());
  Serial.println(" cm");
  delay(400);

  if(showDistance() <= 15 && showDistance()>= 10)
  {
    gateOpen();
    delay(10000);
    gateClose();
  }
  else if(BTN())
  {
    gateOpen();
    delay(10000);
    gateClose();
  }
}

int showDistance()
{
  // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
  return distance;

}

void gateOpen()
{
  for (pos = 0; pos <= 100; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(20);                       // waits 15ms for the servo to reach the position
  }
  gateStatus = true;
}

void gateClose()
{
  for (pos = 100; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(20);                       // waits 15ms for the servo to reach the position
  }
  gateStatus = false;
}

bool BTN()
{
//  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH)
  {
    return true;
  }
  else return false;
}
