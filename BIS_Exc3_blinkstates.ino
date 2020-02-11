// BIS LED code
// Author: Jakob

const int MIN = 1;
const int MAX = 20;
const int buttonPin = 12;
int state = 0;

void ok (void) {
  for (int i = 0; i < 3; i++) {
  digitalWrite(LED_BUILTIN, HIGH);                       
  delay(50);                     
  digitalWrite(LED_BUILTIN, LOW);  
  delay(50);        
  }
}

void warning(void) {
  for (int i = 0; i < 9; i++){
    for (int j = 0; j < 3; j++){   
      digitalWrite(LED_BUILTIN, HIGH);                       
      delay(200);                     
      digitalWrite(LED_BUILTIN, LOW);  
      delay(200);
      }
  delay(500);
  }
}

void error(void) {
  for (int i = 0; i < 30; i++) {
  digitalWrite(LED_BUILTIN, HIGH);                       
  delay(100);                     
  digitalWrite(LED_BUILTIN, LOW);  
  delay(100); 
  }
}

void busy(void) {
  for (int i=0; i <= 400; i++){
  digitalWrite(LED_BUILTIN, HIGH);                       
  delay(random(MIN,MAX));                     
  digitalWrite(LED_BUILTIN, LOW);  
  delay(random(MIN,MAX)); 
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
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
  switch (state) {
    case 0: ok();         next_state();   break;
    case 1: warning();    next_state();   break;
    case 2: error();      next_state();   break;
    case 3: busy();       next_state();   break;
  }
}
