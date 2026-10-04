# Buzzer Output Tutorial

This tutorial will walk you through connecting one passive buzzer to your microcontroller and making it beep.

## You Will Need

- 1 passive piezo buzzer suitable for a 3.3 V GPIO signal
- 1 ESP32S3 microcontroller
- Data transfer cable
- Breadboard
- 2 jumper wires

This tutorial uses a **passive piezo buzzer**, which needs a changing signal to produce sound. An active buzzer has a built-in oscillator and works differently.

## Hardware Connections

Disconnect your microcontroller from power (device) before wiring.

1. Connect the buzzer’s **positive (+)** terminal to an output-capable `GPIO` on your microcontroller.
2. Connect the buzzer’s **negative (−)** terminal to `GND` on your microcontroller. You can also use the breadboard’s `GND` rail if it is connected to the microcontroller’s `GND`.

Use a small piezo buzzer designed for direct GPIO drive. A speaker or higher-current buzzer requires a separate driver circuit.

![boards dropdown](.\images\buzzer.jpg)

## Software

1. Create a variable called `BUZZER_PIN`, with the type `const int` and value `{pin number}` from your board’s pinout diagram. The example uses `D0`; replace it with your chosen pin if needed. Some boards use GPIO numbers instead of `D0` labels.
2. Set it as an `OUTPUT` in the `setup` function.
3. In the `loop` function, use `tone(BUZZER_PIN, 1000)` to produce a tone at **1000 Hz**. Frequency controls the pitch of the sound.
4. Use `delay(1000)` to let the tone play for one second.
5. Use `noTone(BUZZER_PIN)` to stop the sound.
6. Wait another second before repeating.

## Code

```cpp
const int BUZZER_PIN = D0;

void setup() {
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  tone(BUZZER_PIN, 1000); // Start a 1000 Hz tone.
  delay(1000);           // Let it play for 1 second.

  noTone(BUZZER_PIN);    // Stop the sound.
  delay(1000);           // Wait 1 second.
}
```

## Challenge: Create a Function for Buzzer Output

Create a function called `beepBuzzer` that takes a buzzer pin (type `int`) as an argument. The function should play a tone for one second, then stay silent for one second.

This breaks up the code for readability and makes it easier to reuse. Instead of putting the beeping code directly in `loop`, call `beepBuzzer(BUZZER_PIN)`. Each function call performs one beep, and `loop` calls it repeatedly.

## Code

```cpp
const int BUZZER_PIN = D0;

void setup() {
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  beepBuzzer(BUZZER_PIN);
}

void beepBuzzer(int buzzer_pin) {
  tone(buzzer_pin, 1000); // Start a 1000 Hz tone.
  delay(1000);

  noTone(buzzer_pin);    // Stop the sound.
  delay(1000);
}
```

## Verification

Upload the code to your microcontroller. The buzzer should sound for one second, then stay silent for one second, repeatedly.

Try changing the frequency in `tone` to change the pitch. For example, `tone(BUZZER_PIN, 2000)` produces a higher pitch than `tone(BUZZER_PIN, 1000)`.

Change the `delay` values to make the beeps shorter or longer. These values are in **milliseconds**, so `delay(500)` waits half a second.