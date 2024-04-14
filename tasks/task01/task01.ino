const int ledPins[] = {3, 5, 6, 9, 10};  
const int numLeds = 5;                   

const unsigned long intervals[] = {10000, 1000, 500, 100, 50};

int ledStates[] = {LOW, LOW, LOW, LOW, LOW};  
unsigned long previousMicros[] = {0, 0, 0, 0, 0};  

void setup() {
  for (int i = 0; i < numLeds; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  for (int i = 0; i < numLeds; i++) {
    unsigned long currentMicros = micros();

    if (currentMicros - previousMicros[i] >= intervals[i]) {
      previousMicros[i] = currentMicros;

      if (ledStates[i] == LOW) {
        ledStates[i] = HIGH;
      } else {
        ledStates[i] = LOW;
      }

      digitalWrite(ledPins[i], ledStates[i]);
    }
  }
}
