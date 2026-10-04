# LED Output Tutorial

This tutorial will walk you through connecting one LED to your microcontroller and making it blink.

## You Will Need

- 1 LED
- 1 resistor (330 Ω)
- 1 ESP32S3 microcontroller
- Data transfer cable
- Breadboard
- 2 jumper wires

## Hardware Connections

Disconnect your microcontroller from power before wiring.

1. Connect an output-capable `GPIO` on your microcontroller to one end of the resistor.
2. Connect the other end of the resistor to the **long leg (anode)** of the LED.
3. Connect the **short leg (cathode)** of the LED to `GND` on your microcontroller. You can also use the breadboard’s `GND` rail if it is connected to the microcontroller’s `GND`.

The resistor limits the current through the LED. Do not connect the LED without it.

## Software

1. Create a variable called `LED_PIN`, with the type `const int` and value `{pin number}` from your board’s pinout diagram. The example uses `D0`; replace it with your chosen pin if needed. Some boards use GPIO numbers instead of `D0` labels.
2. Set it as an `OUTPUT` in the `setup` function.
3. In the `loop` function, use `digitalWrite(LED_PIN, HIGH)` to turn the LED on.
4. Use `delay(1000)` to wait one second.
5. Use `digitalWrite(LED_PIN, LOW)` to turn the LED off.
6. Wait another second before repeating.

## Code

```cpp
const int LED_PIN = D0;

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_PIN, HIGH); // Turn the LED on.
  delay(1000);                // Wait 1000 milliseconds (1 second).

  digitalWrite(LED_PIN, LOW);  // Turn the LED off.
  delay(1000);                // Wait 1 second.
}
```

## Challenge: Create a Function for LED Output

Create a function called `blinkLED` that takes an LED pin (type `int`) as an argument. The function should turn the LED on for one second, then off for one second.

This breaks up the code for readability and makes it easier to reuse. Instead of putting the blinking code directly in `loop`, call `blinkLED(LED_PIN)`. Each function call performs one blink, and `loop` calls it repeatedly.

## Code

```cpp
const int LED_PIN = D0;

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  blinkLED(LED_PIN);
}

void blinkLED(int led_pin) {
  digitalWrite(led_pin, HIGH); // Turn the LED on.
  delay(1000);

  digitalWrite(led_pin, LOW);  // Turn the LED off.
  delay(1000);
}
```

## Verification

Upload the code to your microcontroller. The LED should turn on for one second, then off for one second, repeatedly.

Try changing the `delay` values to make it blink faster or slower. The values are in **milliseconds**, so `delay(500)` waits half a second.