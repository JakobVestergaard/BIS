// BIS BUZZER code
// Author: Jakob Vestergaard

const int MIN = 10;
const int MAX = 40;
const int buttonPin = 12;
const int buzzerPin = 11;
int state = 3;

void ok (void) {
  for (int k = 0; k < 3; k++){
    for (int i = 0; i < 3; i++) {
        for (int i = 0; i < 10; i++) {
        digitalWrite(buzzerPin, HIGH);                       
        delay(1);                     
        digitalWrite(buzzerPin, LOW);  
        delay(1);  
        }    
    delay(100);   
    }
  delay(1000);
  }
}

void warning(void) {
  for (int j = 0; j < 5; j++){
    for (int i = 0; i < 10; i++) {
    digitalWrite(buzzerPin, HIGH);                       
    delay(3);                     
    digitalWrite(buzzerPin, LOW);  
    delay(3);        
    }
    delay(200);
    for (int i = 0; i < 5; i++) {
    digitalWrite(buzzerPin, HIGH);                       
    delay(1);                     
    digitalWrite(buzzerPin, LOW);  
    delay(1);        
    }
  delay(1000);
  }
}

void error(void) {
  for (int i = 0; i < 300; i++) {
  digitalWrite(buzzerPin, HIGH);                       
  delay(1);                     
  digitalWrite(buzzerPin, LOW);  
  delay(1); 
  }
  delay(300);
  for (int i = 0; i < 300; i++) {
  digitalWrite(buzzerPin, HIGH);                       
  delay(1);                     
  digitalWrite(buzzerPin, LOW);  
  delay(1); 
  }
  delay(300);
  for (int i = 0; i < 300; i++) {
  digitalWrite(buzzerPin, HIGH);                       
  delay(1);                     
  digitalWrite(buzzerPin, LOW);  
  delay(1); 
  }
}


void busy(void) {
  for (int i=0; i <= 300; i++){
  digitalWrite(buzzerPin, HIGH);                       
  delay(5);                     
  digitalWrite(buzzerPin, LOW);  
  delay(5); 
  }
}

int next_state(void) {
  while (digitalRead(buttonPin) == 0) {
    delay(0);
    // wait here till button is pressed
  }
  state++;
  if (state == 4) { state = 0; }
}

void setup() {
  pinMode(buzzerPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}


void loop() {
  switch (state) {
    case 0: ok();       next_state();   break;
    case 1: warning();  next_state();   break;
    case 2: error();    next_state();   break;
    case 3: busy();     next_state();   break;
  }
}
