const int led = 13;  
String code = "";
const int resetButton = 6; // Reset button pin
int len = 0;
char ch;
char new_char;
int unit_delay = 500;

void dot() {
  Serial.print(".");
  digitalWrite(led, HIGH);
  delay(unit_delay);
  digitalWrite(led, LOW);
  delay(unit_delay);
}

void dash() {
  Serial.print("-");
  digitalWrite(led, HIGH);
  delay(unit_delay * 3);
  digitalWrite(led, LOW);
  delay(unit_delay * 3);
}



void G()
{
  dash();
  delay(unit_delay);
  dash();
  delay(unit_delay);
  dot();
  delay(unit_delay);
}
void U()
{
  dot();
  delay(unit_delay);
  dot();
  delay(unit_delay);
  dash();
  delay(unit_delay);
}
void R()
{
  dot();
  delay(unit_delay);
  dash();
  delay(unit_delay);
  dot();
  delay(unit_delay);
}
void K()
{
  dash();
  delay(unit_delay);
  dot();
  delay(unit_delay);
  dash();
  delay(unit_delay);
}

void I()
{
  dot();
  delay(unit_delay);
  dot();
  delay(unit_delay);
}
void A() {
  dot();
  delay(unit_delay);
  dash();
  delay(unit_delay);
}
void T()
{
  dash();
  delay(unit_delay);
}

void one()
{
  dot();
  delay(unit_delay);
  dash();
  delay(unit_delay);
  dash();
  delay(unit_delay);
  dash();
  delay(unit_delay);
  dash();
  delay(unit_delay);
}
void two()
{
  dot();
  delay(unit_delay);
  dot();
  delay(unit_delay);
  dash();
  delay(unit_delay);
  dash();
  delay(unit_delay);
  dash();
  delay(unit_delay);
}
void three()
{
  dot();
  delay(unit_delay);
  dot();
  delay(unit_delay);
  dot();
  delay(unit_delay);
  dash();
  delay(unit_delay);
  dash();
  delay(unit_delay);
}
void four()
{
  dot();
  delay(unit_delay);
  dot();
  delay(unit_delay);
  dot();
  delay(unit_delay);
  dot();
  delay(unit_delay);
  dash();
  delay(unit_delay);
}
void five()
{
  dot();
  delay(unit_delay);
  dot();
  delay(unit_delay);
  dot();
  delay(unit_delay);
  dot();
  delay(unit_delay);
  dot();
  delay(unit_delay);
}
void six()
{
  dash();
  delay(unit_delay);
  dot();
  delay(unit_delay);
  dot();
  delay(unit_delay);
  dot();
  delay(unit_delay);
  dot();
  delay(unit_delay);
}
void seven()
{
  dash();
  delay(unit_delay);
  dash();
  delay(unit_delay);
  dot();
  delay(unit_delay);
  dot();
  delay(unit_delay);
  dot();
  delay(unit_delay);
}
void eight()
{
  dash();
  delay(unit_delay);
  dash();
  delay(unit_delay);
  dash();
  delay(unit_delay);
  dot();
  delay(unit_delay);
  dot();
  delay(unit_delay);
}
void nine()
{
  dash();
  delay(unit_delay);
  dash();
  delay(unit_delay);
  dash();
  delay(unit_delay);
  dash();
  delay(unit_delay);
  dot();
  delay(unit_delay);
}
void zero()
{
  dash();
  delay(unit_delay);
  dash();
  delay(unit_delay);
  dash();
  delay(unit_delay);
  dash();
  delay(unit_delay);
  dash();
  delay(unit_delay);
}


void morse() {
  if (ch == 'A' || ch == 'a') {
    A();
    Serial.print(" ");
  }
  else if (ch == 'G' || ch == 'g')
  {
    G();
    Serial.print(" ");
  }
  else if (ch == 'U' || ch == 'u')
  {
    U();
    Serial.print(" ");
  }
 else if (ch == 'R' || ch == 'r')
  {
    R();
    Serial.print(" ");
  }
  else if (ch == 'K' || ch == 'k')
  {
    K();
    Serial.print(" ");
  }
  else if (ch == 'I' || ch == 'i')
  {
    I();
    Serial.print(" ");
  }
  else if (ch == 'R' || ch == 'r')
  {
    R();
    Serial.print(" ");
  }
  else if (ch == 'T' || ch == 't')
  {
    T();
    Serial.print(" ");
  }

  
  else if (ch == '0')
  {
    zero();
    Serial.print(" ");
  }
  else if (ch == '1')
  {
    one();
    Serial.print(" ");
  }
  else if (ch == '2')
  {
    two();
    Serial.print(" ");
  }
  else if (ch == '3')
  {
    three();
    Serial.print(" ");
  }
  else if (ch == '4')
  {
    four();
    Serial.print(" ");
  }
  else if (ch == '5')
  {
    five();
    Serial.print(" ");
  }
  else if (ch == '6')
  {
    six();
    Serial.print(" ");
  }
  else if (ch == '7')
  {
    seven();
    Serial.print(" ");
  }
  else if (ch == '8')
  {
    eight();
    Serial.print(" ");
  }
  else if (ch == '9')
  {
    nine();
    Serial.print(" ");
  }

  else if (ch == ' ') {
    delay(unit_delay * 7);
    Serial.print("/ ");
  }
  else if (ch == '\n') {
    Serial.println("");
  }
  else {
    Serial.println("Unknown Character!");
  }

}


void String2Morse() {
  len = code.length();
  for (int i = 0; i < len; i++) {
    ch = code.charAt(i);
    morse();
  }
}

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(resetButton, INPUT_PULLUP);
  Serial.println("Please type your message here ");
}

void loop() {
  
  if (digitalRead(resetButton) == LOW) {
    // Reset button pressed, restart the blinking sequence
    digitalWrite(led, LOW);
    delay(100); // Debounce delay
    while (digitalRead(resetButton) == LOW) {} // Wait for button release
    code = "";
    len = 0;
    ch = 0;
  }
  while (Serial.available()){
    code = Serial.readString();
    Serial.println(code + " = ");
    String2Morse();
    Serial.println(); 
  }
  delay(1000);
  }