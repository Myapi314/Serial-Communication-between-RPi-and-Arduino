#define LED_RED_PIN A2
#define LED_BLUE_PIN A3
#define BUTTON_PIN A4

byte lastButtonState = LOW;
byte currentButtonState = LOW;

unsigned long lastButtonDebounceTime = 0;
unsigned long buttonBounceDelay = 20;

void powerOffAllLEDs()
{
  digitalWrite(LED_RED_PIN, LOW);
  digitalWrite(LED_BLUE_PIN, LOW);
}

void setup() {
  Serial.begin(9600);
  pinMode(LED_RED_PIN, OUTPUT);
  pinMode(LED_BLUE_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);

  powerOffAllLEDs();
}

void loop() {
  byte readValue = digitalRead(BUTTON_PIN);

  if (readValue != lastButtonState) {
    lastButtonDebounceTime = millis();
  }

  if (millis() - lastButtonDebounceTime > buttonBounceDelay) {
    if (readValue != currentButtonState) {
      currentButtonState = readValue;
      if (currentButtonState == HIGH) {
        Serial.write(18);
      }
    }
  }

  lastButtonState = readValue;

  
  if (Serial.available() > 0) {
    int ledState = Serial.read() - '0';

    powerOffAllLEDs();

    switch (ledState) {
      case 1:
        digitalWrite(LED_RED_PIN, HIGH);
        break;
      case 2:
        digitalWrite(LED_BLUE_PIN, HIGH);
        break;
      default:
        break;
    }
  }
}
