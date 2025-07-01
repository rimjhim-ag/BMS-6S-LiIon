int cellPins[6] = {A0, A1, A2, A3, A4, A5};
int ledPins[6] = {2, 3, 4, 5, 6, 7};
const int currentPin = A6;

float voltages[6];
float current;
float maxVolt = 6.2;
float minVolt = 3.0;
float maxCurrent = 5.0;
float minCurrent = 0.2;

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < 6; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  int currentADC = analogRead(currentPin);
  float rawVoltage = currentADC * (5.0 / 1023.0);
  current = (rawVoltage / 5.0) * 10.0;  // Simulate 0–10A

  String voltageFaultCells = "";
  bool allCellsOK = true;

  Serial.println("---- Battery Status ----");

  for (int i = 0; i < 6; i++) {
    int adc = analogRead(cellPins[i]);
    voltages[i] = (adc * 5.0 / 1023.0) * 2.0;

    if (voltages[i] > maxVolt || voltages[i] < minVolt) {
      digitalWrite(ledPins[i], HIGH);
      voltageFaultCells += "Cell " + String(i + 1) + ", ";
      allCellsOK = false;
    } else {
      digitalWrite(ledPins[i], LOW);
    }

    Serial.print("Cell ");
    Serial.print(i + 1);
    Serial.print(": ");
    Serial.print(voltages[i]);
    Serial.println(" V");
  }

  // Voltage Fault Summary
  if (!allCellsOK) {
    voltageFaultCells.remove(voltageFaultCells.length() - 2);  // Remove last comma
    Serial.print("Voltage Faults Detected in: ");
    Serial.println(voltageFaultCells);
  } else {
    Serial.println("All cell voltages are within safe range.");
  }

  // Current Status
  Serial.print("Current: ");
  Serial.print(current);
  Serial.println(" A");

  if (current > maxCurrent) {
    Serial.println("Overcurrent Detected!");
  } else if (current < minCurrent) {
    Serial.println(" Undercurrent Detected!");
  } else {
    Serial.println("Current is within safe range.");
  }

  Serial.println("-------------------------\n");
  delay(5000);
}
