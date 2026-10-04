# Button Input Tutorial

This tutorial will walk you through connecting one button to your microcontroller and detecting when it is pressed. The code and hardware setup in this guide can be used as a basis for more complex designs involving more inputs.

## You Will Need

- 1 button
- 1 ESP32S3 microcontroller
- Data transfer cable
- Breadboard
- Jumper wires

## Breadboard Power and Ground Rail Setup

### 1. Make `GND` connection
Connect microcontroller `GND` to breadboard `GND` (blue) on one side.

![boards dropdown](.\images\gnd1.jpg)

### 2. Make `3V3` power connection
Connect microcontroller `3V3` to breadboard `POWER` (red) on one side.

![boards dropdown](.\images\pwr1.jpg)

### 3. Powering all 4 power rails
Connect breadboard `GND` to `GND` and `POWER` to `POWER` so that `GND` and `POWER` can both be accessed from either side of the breadboard.

![boards dropdown](.\images\power4.jpg)


## Hardware Connections
Disconnect your microcontroller from device (computer) before wiring.

### 1. Connect one terminal of the button to an input-capable `GPIO` on your microcontroller.
In the example code provided I used `D0` but you can use whichever GPIO you want and change the `D0` variable to the pin you used.

### 2. Connect the other terminal to `GND`. 
You can also use either of the breadboard’s ground rails if they are connected to the microcontroller’s `GND`.

If your button has four legs, two pairs are already connected internally. Choose terminals that become connected **when you press the button**.

![boards dropdown](.\images\button.jpg)

## Software

1. Create a variable called `BUTTON_PIN` with the type `const int`. Assign it the pin connected to your button. The example uses `D0`, but your pin may be different—check your board’s pinout.
2. In `setup()`, start serial communication with `Serial.begin(9600)`.
3. Set the button pin as `INPUT_PULLUP` using `pinMode()`.
4. In `loop()`, use `digitalRead()` to read the button’s state.
5. If the state is `LOW`, print `"button pressed"`. Otherwise, print nothing.

**Why does `LOW` mean pressed?** With `INPUT_PULLUP`, an internal resistor holds the pin `HIGH` when the button is released. Pressing the button connects the pin to ground, making it read `LOW`.

## Code

```cpp
const int BUTTON_PIN = D0;

void setup() {
  Serial.begin(9600);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
}

void loop() {
  int state = digitalRead(BUTTON_PIN);

  if (state == LOW) {
    Serial.println("button pressed");
  }
}
```

## Challenge: Create a Function for Button Press Action

Create a function called `buttonAction` that:

- Takes a button pin of type `int` as an argument.
- Prints `"button pressed"` if the button is pressed.
- Prints `"button released"` if the button is released.

Moving the button logic into a function makes `loop()` easier to read and lets you reuse the same function for other buttons.

Call `buttonAction(BUTTON_PIN)` inside `loop()`. The function runs again each time `loop()` repeats.

## Code

```cpp
const int BUTTON_PIN = D0; // REPLACE WITH WHICHEVER PIN YOU ARE USING

void setup() {
  Serial.begin(9600);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
}

void loop() {
  buttonAction(BUTTON_PIN);
}

void buttonAction(int button_pin) {
  int state = digitalRead(button_pin);

  if (state == LOW) {
    Serial.println("button pressed");
  } else {
    Serial.println("button released");
  }
}
```

## Verification

Upload the code to your microcontroller, then open **Tools → Serial Monitor**. Set the baud rate to **9600** to match `Serial.begin(9600)`.

![boards dropdown](.\images\smmenu.png)

### Expected Behavior

- **First example:** Prints `"button pressed"` while you hold the button and prints nothing when you release it.
- **Function challenge:** Prints `"button pressed"` while you hold the button and `"button released"` when you release it.


![boards dropdown](.\images\serialmonitor.png)

The messages repeat because the code checks the button continuously in `loop()`.

## Troubleshooting

- Make sure the Arduino is set up correctly for flashing. If the IDE does not say ESP32S3 on [port number] connected, go back to the Arduino setup tutorial in week 1 and verify that your microcontroller works with the Blink example file provided by Arduino.

- Your breadboard ground and power rails should be connected to the microcontroller ground and power rails

- Check that the components are actually connected based on the breadboard connection diagram.

- Make sure you are connected to pin `D0` if you are using the starter code, otherwise replace `D0` with the pin you are actually using.

- Make sure Arduino baud rate is set to 9600.