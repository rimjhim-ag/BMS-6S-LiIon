# Battery Management System (BMS) Simulation – Arduino + Tinkercad

This project simulates a Battery Management System (BMS) for a 6-cell Li-ion battery pack using an Arduino Uno, implemented entirely in Tinkercad. The system detects overvoltage, undervoltage, overcurrent, and undercurrent conditions. It provides visual fault indications using LEDs and logs all data to the Serial Monitor.

---

## Features

- Real-time voltage monitoring for 6 individual cells
- Current monitoring using an analog input
- Fault detection for:
  - Overvoltage and undervoltage
  - Overcurrent and undercurrent
- LED indicators for per-cell voltage faults
- Serial Monitor output for live readings and combined fault summaries
- Fully simulated in Tinkercad (no physical hardware needed)

---

## Components Used

- Arduino Uno R3
- 6 potentiometers (to simulate cell voltages)
- 1 potentiometer (to simulate current)
- 6 LEDs with resistors (to indicate per-cell faults)
- Breadboard and jumper wires

---

## Circuit Overview

| Arduino Pin | Connected Component        | Purpose                    |
|-------------|----------------------------|----------------------------|
| A0–A5       | 6 potentiometers            | Simulated cell voltages    |
| A6          | 1 potentiometer             | Simulated total current    |
| D2–D7       | 6 LEDs (with 220Ω resistors) | Fault indication for cells |

---

## Configuration

| Parameter       | Value (Simulation) |
|-----------------|--------------------|
| Max Cell Voltage | 6.0 V (for demo clarity) |
| Min Cell Voltage | 3.0 V              |
| Max Current      | 5.0 A              |
| Min Current      | 0.2 A              |

These values can be adjusted in the code for more realistic or strict limits.

---

## How to Use in Tinkercad

1. Open Tinkercad and create a new **Circuit**.
2. Add the listed components and wire them according to the schematic.
3. Paste the Arduino code into the **code editor**.
4. Click **Start Simulation**.
5. Open the **Serial Monitor** to view live voltage and current readings.
6. Adjust the potentiometers to simulate faults:
   - Rotate a cell pot above 6.0V or below 3.0V to trigger voltage faults.
   - Rotate the current pot to simulate overcurrent (>5.0A) or undercurrent (<0.2A).



