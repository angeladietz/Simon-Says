const int buttonPinB = 3;
const int buttonPinG = 2;
const int buttonPinR = 1;
const int buttonPinY = 0;
int ledPinB = 13;
int ledPinG = 12;
int ledPinR = 11;
int ledPinY = 10;

int buttonStateR = 0;
int buttonStateB = 0;
int buttonStateG = 0;
int buttonStateY = 0;

void setup() {
  pinMode(ledPinR, OUTPUT);
  pinMode(ledPinB, OUTPUT);
  pinMode(ledPinG, OUTPUT);
  pinMode(ledPinY, OUTPUT);
  pinMode(buttonPinR, INPUT);
  pinMode(buttonPinB, INPUT);
  pinMode(buttonPinG, INPUT);
  pinMode(buttonPinG, INPUT);

  digitalWrite(ledPinR, LOW);
  digitalWrite(ledPinG, LOW);
  digitalWrite(ledPinB, LOW);
  digitalWrite(ledPinY, LOW);
}



void loop() {
  buttonStateR = digitalRead(buttonPinR);
  buttonStateB = digitalRead(buttonPinB);
  buttonStateG = digitalRead(buttonPinG);
  buttonStateY = digitalRead(buttonPinY);

  if (buttonStateR == LOW){
    digitalWrite(ledPinR, HIGH);
  }
  else{
    digitalWrite(ledPinR, LOW);
  }
  
  if (buttonStateB == LOW){
    digitalWrite(ledPinB, HIGH);
  }
  else{
    digitalWrite(ledPinB, LOW);
  }
  if (buttonStateG == LOW){
    digitalWrite(ledPinG, HIGH);
  }
  else{
    digitalWrite(ledPinG, LOW);
  }
  if (buttonStateY == LOW){
    digitalWrite(ledPinY, HIGH);
  }
  else {
    digitalWrite(ledPinY, LOW);
  }

}
