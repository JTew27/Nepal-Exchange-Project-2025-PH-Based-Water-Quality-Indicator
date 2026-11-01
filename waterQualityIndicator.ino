#include <LiquidCrystal.h>

// LCD pin connections: RS, EN, D4, D5, D6, D7
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Calibration value for pH
float calibration_value = 16.9; //17.29

float calibration_slope = -6.54; //m found with cola ph and v



int buffer_arr[10], temp;
unsigned long int avgval;



// LED Pins
#define GREEN_LED_PIN 6  // Safe LED
#define RED_LED_PIN 7     // Unsafe LED

void setup() {
  Serial.begin(9600);
  delay(1000);
  Serial.println("Hello There");
  Serial.println("pH Sensor Initialised");

  pinMode(GREEN_LED_PIN, OUTPUT);
  pinMode(RED_LED_PIN, OUTPUT);

  lcd.begin(16, 2);  // Initialize 16x2 LCD
  lcd.clear();
}

void loop() {
  // Read 10 samples
  for (int i = 0; i < 10; i++) {
    buffer_arr[i] = analogRead(A0);
    delay(50);
  }

  // Sort readings
  for (int i = 0; i < 9; i++) {
    for (int j = i + 1; j < 10; j++) {
      if (buffer_arr[i] > buffer_arr[j]) {
        temp = buffer_arr[i];
        buffer_arr[i] = buffer_arr[j];
        buffer_arr[j] = temp;
      }
    }
  }

  // Average the middle 6
  avgval = 0;
  for (int i = 2; i < 8; i++) {
    avgval += buffer_arr[i];
  }

  float volt = (float)avgval * 5.0 / 1024 / 6;

  float ph_act = -6.45 * volt + calibration_value;
  //float ph_act = calibration_slope * volt + calibration_value; // y=mx+c

  Serial.print("Analog: ");
  Serial.print(avgval / 6);
  Serial.print(" | Voltage: ");
  Serial.print(volt, 3);
  Serial.print(" V | pH: ");
  Serial.print(ph_act, 2);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("pH Value:");
  lcd.setCursor(0, 1);
  lcd.print(ph_act, 2);

  if (ph_act >= 6.5 && ph_act <= 7.8) {
    // Safe pH range
    Serial.println(" -> Safe");
    digitalWrite(GREEN_LED_PIN, HIGH);
    digitalWrite(RED_LED_PIN, LOW);
  } else {
    // Unsafe pH range
    Serial.println(" -> Unsafe");
    digitalWrite(GREEN_LED_PIN, LOW);
    digitalWrite(RED_LED_PIN, HIGH);
  }

  delay(600);
}
