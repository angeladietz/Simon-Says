const int buttonPinB = 3;
const int buttonPinG = 2;
const int buttonPinR = 1;
const int buttonPinY = 0;
int ledPinB = 13;
int ledPinG = 12;
int ledPinR = 11;
int ledPinY = 10;

int buzzPin = 7;
int bFreq = 392;
int gFreq = 247;
int rFreq = 196;
int yFreq = 294;

int buttonStateR = 0;
int buttonStateB = 0;
int buttonStateG = 0;
int buttonStateY = 0;
 
const int length = 20;
int sequence[length];
int n = 0;
int input = 0;
int count = 0;
int t = 0;


int check = 0;
int correct = 1;

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

  
  Serial.begin(9600);
  
  randomSeed(analogRead(0));
  
  for (int i = 0; i<length; i++) {
    sequence[i] = random(1,5);

  }

}


int checkP(int input, int count){

  int flag = 1;
  
      if (input != sequence[count]){
         flag = 0;
      }

  return flag;
}


void loop() {

  buttonStateR = digitalRead(buttonPinR);
  buttonStateB = digitalRead(buttonPinB);
  buttonStateG = digitalRead(buttonPinG);
  buttonStateY = digitalRead(buttonPinY);

  while (check == 0){
 
    for (int i = 0; i<length; i++) {
      digitalWrite(ledPinY, HIGH);
      digitalWrite(ledPinR, HIGH);
      digitalWrite(ledPinG, HIGH);
      digitalWrite(ledPinB, HIGH);
      delay(100);
        
      digitalWrite(ledPinY, LOW);
      digitalWrite(ledPinR, LOW);
      digitalWrite(ledPinG, LOW);
      digitalWrite(ledPinB, LOW);
    
      delay(500);

      
      while (n<=i){
        if (sequence[n] == 1){
          digitalWrite(ledPinY, HIGH);
          tone(buzzPin, yFreq);
          delay(500 - t);
          digitalWrite(ledPinY, LOW);
          noTone(buzzPin);
        }
        else if (sequence[n] == 2){
          digitalWrite(ledPinR, HIGH);
          tone(buzzPin, rFreq);
          delay(500 - t);
          digitalWrite(ledPinR, LOW);
          noTone(buzzPin);
        }
        else if (sequence[n] == 3){
          digitalWrite(ledPinG, HIGH);
          tone(buzzPin, gFreq);
          delay(500 - t);
          digitalWrite(ledPinG, LOW);
          noTone(buzzPin);
        }
        else if (sequence[n] == 4){
          digitalWrite(ledPinB, HIGH);
          tone(buzzPin, bFreq);
          delay(500 - t);
          digitalWrite(ledPinB, LOW);
          noTone(buzzPin);

          delay(500 - t);
          digitalWrite(ledPinY, LOW);
        }
        else if (sequence[n] == 2){
          digitalWrite(ledPinR, HIGH);
          delay(500 - t);
          digitalWrite(ledPinR, LOW);
        }
        else if (sequence[n] == 3){
          digitalWrite(ledPinG, HIGH);
          delay(500 - t);
          digitalWrite(ledPinG, LOW);
        }
        else if (sequence[n] == 4){
          digitalWrite(ledPinB, HIGH);
          delay(500 - t);
          digitalWrite(ledPinB, LOW);
        }
        delay(500);
        n++;
      } 
    

      digitalWrite(ledPinY, HIGH);
      digitalWrite(ledPinR, HIGH);
      digitalWrite(ledPinG, HIGH);
      digitalWrite(ledPinB, HIGH);
      delay(700);
        
      digitalWrite(ledPinY, LOW);
      digitalWrite(ledPinR, LOW);
      digitalWrite(ledPinG, LOW);
      digitalWrite(ledPinB, LOW);
    
      delay(500);
      check = 1; //indicates that input from the user is required
      
      if (check == 1){
    
         count = 0; //counts the number of times that the user pushes a button
         while (count <= i){ //count!= the number of times a light flashed

            buttonStateR = digitalRead(buttonPinR);
            buttonStateB = digitalRead(buttonPinB);
            buttonStateG = digitalRead(buttonPinG);
            buttonStateY = digitalRead(buttonPinY);
          
           //turns on the corresponding light when the user presses a button

           if (buttonStateY == LOW){
             digitalWrite(ledPinY, HIGH);
             tone(buzzPin, yFreq);
             correct = checkP(1, count);
             count++;
             delay(400);
             digitalWrite(ledPinY, LOW);
             noTone(buzzPin);
           }
           
           if (buttonStateR == LOW){
             digitalWrite(ledPinR, HIGH);
             tone(buzzPin, rFreq);
             correct = checkP(2, count);
             count++;
             delay(400);
             digitalWrite(ledPinR, LOW);
             noTone(buzzPin);
           }


           if (buttonStateG == LOW){
             digitalWrite(ledPinG, HIGH);
             tone(buzzPin, gFreq);
             correct = checkP(3, count);
             count++;
             delay(400);
             digitalWrite(ledPinG, LOW);
             noTone(buzzPin);
           }

           
           if (buttonStateB == LOW){
             digitalWrite(ledPinB, HIGH);
             tone(buzzPin, bFreq);
             correct = checkP(4, count);
             count++;
             delay(400);
             digitalWrite(ledPinB, LOW);
             noTone(buzzPin);
           }
        }
          while (correct == 0){

           }
        }
        delay(400);
          while (correct == 0){
            //flashes the lights the number 
            for (int j = 0; j<i;j++){
              digitalWrite(ledPinY, HIGH);
              digitalWrite(ledPinR, HIGH);
              digitalWrite(ledPinG, HIGH);
              digitalWrite(ledPinB, HIGH);
              delay(300);
              digitalWrite(ledPinY, LOW);
              digitalWrite(ledPinR, LOW);
              digitalWrite(ledPinG, LOW);
              digitalWrite(ledPinB, LOW);
              delay(300);
            }
            digitalWrite(ledPinY, HIGH);
            digitalWrite(ledPinR, HIGH);
            digitalWrite(ledPinG, HIGH);
            digitalWrite(ledPinB, HIGH);
          }
    
    }

    n = 0;
    t += 25;

    digitalWrite(ledPinY, LOW);
    digitalWrite(ledPinR, LOW);
    digitalWrite(ledPinG, LOW);
    digitalWrite(ledPinB, LOW);

    }
    for (int i = 0; i<6; i++){

      digitalWrite(ledPinB, HIGH);
      delay(50);
      digitalWrite(ledPinB, LOW);
      digitalWrite(ledPinG, HIGH);
      delay(50);
      digitalWrite(ledPinG, LOW);
      digitalWrite(ledPinR, HIGH);
      delay(50);
      digitalWrite(ledPinR, LOW);
      digitalWrite(ledPinY, HIGH);
      delay(50);
      digitalWrite(ledPinY, LOW);
    }
  }
}
