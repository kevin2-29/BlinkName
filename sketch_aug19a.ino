const int led1 = LED_BUILTIN;
int buttonPin = 6; // Push button for resetting the name
bool isButtonPressed = false;

void blinkDot() {
  digitalWrite(led1, HIGH);
  delay(200);
  digitalWrite(led1, LOW);
  delay(200);
  Serial.print(".");
}

void blinkDash() {
  digitalWrite(led1, HIGH);
  delay(600);
  digitalWrite(led1, LOW);
  delay(200);
  Serial.print("-");
}

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(buttonPin), resetName, FALLING);
}

void loop() 
{
  if (isButtonPressed) {
    resetName();
    isButtonPressed = false;
  }

// G (. _ _)
  blinkDot(); delay(1000);
  blinkDash(); delay(500);
  blinkDash(); delay(500);

  // U (. . -)
  blinkDot(); delay(500);
  blinkDot(); delay(500);
  blinkDash(); delay(1000);
  
  // R (.-.)
  blinkDot(); delay(500);
  blinkDash(); delay(500);
  blinkDot(); delay(500);
  blinkDot(); delay(1000);

  // K (- . -)
  blinkDash(); delay(1000);
  blinkDot(); delay(500);
  blinkDash(); delay(1000);

  // I (. .)
  blinkDot(); delay(500);
  blinkDot(); delay(1000);

  // A (.-)
  blinkDot(); delay(500);
  blinkDash(); delay(1000);

  // T (-)
  blinkDash(); delay(1000);

  delay(3000);  // Gap between words
}

void resetName() {
  // Reset the name 
  digitalWrite(led1, LOW);
  delay(1000);
  digitalWrite(led1, HIGH);
  delay(1000);
  digitalWrite(led1, LOW);
  delay(1000);
}
