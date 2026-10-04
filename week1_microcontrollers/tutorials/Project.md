# Week 1 Project: A Buzzer Synth

In this project, you will create a simple synthesizer using a microcontroller, a passive buzzer, three buttons, and three LEDs. Each button will light an LED and play a different note.

You can refer to the button, buzzer and LED tutorial files for help in each section if needed. They will show you the basic setup, which you can base your design on for this project. The contents of this tutorial should be thorough enough that you don't need the other tutorials, but they still are a good starting point to familiarize with the software and hardware, and may be useful for troubleshooting individual components of the project.

## You Will Need

- 1 ESP32S3 microcontroller
- 1 passive piezo buzzer suitable for direct 3.3 V GPIO drive
- 3 buttons
- 3 LEDs
- 3 resistors (330 Ω each)
- Breadboard and jumper wires
- Data transfer cable

This tutorial uses pin labels `D0` through `D6`. Check your board’s pinout to confirm these labels exist and the selected pins support the required inputs or outputs.

Disconnect power before changing your wiring.

## 1. Detect Button Presses

Connect three buttons to `D0`, `D1`, and `D2`. Configure these pins as `INPUT_PULLUP` so that:

- `HIGH` means the button is released.
- `LOW` means the button is pressed.

### 1.1. Open a new Arduino sketch

Start with the empty `setup()` and `loop()` functions.

### 1.2. Create variables for the button pins

Create three `const int` variables named `Button1_Pin`, `Button2_Pin`, and `Button3_Pin`.

Place these declarations **above `setup()` and `loop()`**.

<details>
<summary>Show Code</summary>

```cpp
const int Button1_Pin = D0;
const int Button2_Pin = D1;
const int Button3_Pin = D2;
```

</details>

### 1.3. Set the pins as inputs with pull-up resistors

Use `pinMode(pin, INPUT_PULLUP)` for each button pin.

Place this code **inside `setup()`**.

<details>
<summary>Show Explanation</summary>

An input pin needs a defined voltage when the button is released. `INPUT_PULLUP` enables an internal resistor that pulls the pin toward the microcontroller’s supply voltage, making it read `HIGH`.

Pressing the button connects the pin to ground, making it read `LOW`.

</details>

<details>
<summary>Show Code</summary>

```cpp
pinMode(Button1_Pin, INPUT_PULLUP);
pinMode(Button2_Pin, INPUT_PULLUP);
pinMode(Button3_Pin, INPUT_PULLUP);
```

</details>

### 1.4. Connect the buttons

| Button | One terminal | Other terminal |
|---|---|---|
| Button 1 | `D0` | `GND` |
| Button 2 | `D1` | `GND` |
| Button 3 | `D2` | `GND` |

If your button has four legs, two pairs are already connected internally. Use terminals that become connected **when the button is pressed**.

### 1.5. Test button presses in Serial Monitor

Add `Serial.begin(9600)` **inside `setup()`** to start serial communication.

Then, add three `if` statements **inside `loop()`** to print a message when each button is pressed.

<details>
<summary>Show Code</summary>

Add to `setup()`:

```cpp
Serial.begin(9600);
```

Add to `loop()`:

```cpp
if (digitalRead(Button1_Pin) == LOW) {
  Serial.println("button 1 pressed");
}

if (digitalRead(Button2_Pin) == LOW) {
  Serial.println("button 2 pressed");
}

if (digitalRead(Button3_Pin) == LOW) {
  Serial.println("button 3 pressed");
}
```

</details>

Upload the sketch and open **Tools → Serial Monitor**. Select **9600 baud**.

Press each button and verify that the correct message appears. The message will repeat while you hold the button because `loop()` runs repeatedly.

## 2. Set Up LED Outputs

Each button will control one LED. The LED should stay on while its button is pressed and turn off when the button is released.

### 2.1. Create variables for the LED pins

Use `D3`, `D4`, and `D5`. Place these declarations **above `setup()` and `loop()`**.

<details>
<summary>Show Code</summary>

```cpp
const int LED1_Pin = D3;
const int LED2_Pin = D4;
const int LED3_Pin = D5;
```

</details>

### 2.2. Set the pins as outputs

Place this code **inside `setup()`**.

<details>
<summary>Show Code</summary>

```cpp
pinMode(LED1_Pin, OUTPUT);
pinMode(LED2_Pin, OUTPUT);
pinMode(LED3_Pin, OUTPUT);
```

</details>

### 2.3. Connect the LEDs

Each LED has two terminals:

- **Anode:** the long leg; connect it to the assigned GPIO through a resistor.
- **Cathode:** the short leg; connect it to `GND`.

| LED | GPIO connection | Ground connection |
|---|---|---|
| LED 1 | `D3` through a 330 Ω resistor to the anode | Cathode to `GND` |
| LED 2 | `D4` through a 330 Ω resistor to the anode | Cathode to `GND` |
| LED 3 | `D5` through a 330 Ω resistor to the anode | Cathode to `GND` |

Each LED needs its **own resistor** to limit current. The resistor can go on either side of the LED, as long as it is in series.

### 2.4. Test the LEDs

Temporarily add the following code to `loop()`:

```cpp
digitalWrite(LED1_Pin, HIGH);
digitalWrite(LED2_Pin, HIGH);
digitalWrite(LED3_Pin, HIGH);
```

Upload the sketch. All three LEDs should turn on.

**Remove this test code before continuing.**

### 2.5. Make each button control its LED

Update the button checks in `loop()` so that each button turns on its corresponding LED.

Add an `else` statement to turn the LED off when the button is released.

<details>
<summary>Show Code</summary>

```cpp
if (digitalRead(Button1_Pin) == LOW) {
  digitalWrite(LED1_Pin, HIGH);
} else {
  digitalWrite(LED1_Pin, LOW);
}

if (digitalRead(Button2_Pin) == LOW) {
  digitalWrite(LED2_Pin, HIGH);
} else {
  digitalWrite(LED2_Pin, LOW);
}

if (digitalRead(Button3_Pin) == LOW) {
  digitalWrite(LED3_Pin, HIGH);
} else {
  digitalWrite(LED3_Pin, LOW);
}
```

</details>

Upload the sketch and test each button. You can keep the serial messages inside the corresponding `if` blocks if you want them for debugging.

## 3. Add the Buzzer

The buzzer will play a different note for each button.

### 3.1. Connect the buzzer

Use a small **passive piezo buzzer suitable for direct GPIO drive**.

- Connect the positive (`+`) terminal to `D6`.
- Connect the negative (`−`) terminal to `GND`.
- If the piezo buzzer has no polarity markings, either orientation generally works for this project.

A speaker or higher-current buzzer requires a separate driver circuit.

### 3.2. Create a variable for the buzzer pin

Place this declaration **above `setup()` and `loop()`**.

```cpp
const int Buzzer_Pin = D6;
```

### 3.3. Set the pin as an output

Place this code **inside `setup()`**.

```cpp
pinMode(Buzzer_Pin, OUTPUT);
```

### 3.4. Test a tone

Temporarily add the following code to `loop()`:

```cpp
tone(Buzzer_Pin, 440);
```

`tone(pin, frequency)` starts a sound at the specified frequency in hertz. A frequency of **440 Hz** corresponds to the musical note **A4**.

Upload the sketch. The buzzer should produce a continuous tone.

**Remove this test code before continuing.**

### 3.5. Play a different note for each button

Add the following logic to `loop()`, **after the LED control code**.

| Button | Note | Frequency |
|---|---|---|
| Button 1 | A4 | 440 Hz |
| Button 2 | B4 | 494 Hz |
| Button 3 | C5 | 523 Hz |

Use `noTone(Buzzer_Pin)` to stop the sound when no buttons are pressed.

<details>
<summary>Show Code</summary>

```cpp
if (digitalRead(Button1_Pin) == LOW) {
  tone(Buzzer_Pin, 440);
} else if (digitalRead(Button2_Pin) == LOW) {
  tone(Buzzer_Pin, 494);
} else if (digitalRead(Button3_Pin) == LOW) {
  tone(Buzzer_Pin, 523);
} else {
  noTone(Buzzer_Pin);
}
```

</details>

The buzzer plays **one note at a time**. The `if` / `else if` chain gives Button 1 first priority, followed by Button 2, then Button 3.

If you press multiple buttons, their LEDs will all light, but only the highest-priority button’s note will play.

## 4. Organize the Code into Functions

Functions help us reuse repeated code and make `loop()` easier to read.

### 4.1. Create a function for a button and its LED

Create a function called `buttonAction` that:

1. Takes a button pin and an LED pin as `int` arguments.
2. Checks whether the button is pressed.
3. Turns the LED on or off.
4. Returns `true` if the button is pressed, or `false` if it is released.

The return type is `bool` because the function returns a true-or-false value.

<details>
<summary>Show Code</summary>

```cpp
bool buttonAction(int button_pin, int led_pin) {
  bool pressed = (digitalRead(button_pin) == LOW);

  if (pressed) {
    digitalWrite(led_pin, HIGH);
  } else {
    digitalWrite(led_pin, LOW);
  }

  return pressed;
}
```

</details>

### 4.2. Create a function to choose the note

Keep the buzzer control in one function so that it selects one note based on all three buttons.

<details>
<summary>Show Code</summary>

```cpp
void playNote(bool button1, bool button2, bool button3) {
  if (button1) {
    tone(Buzzer_Pin, 440);
  } else if (button2) {
    tone(Buzzer_Pin, 494);
  } else if (button3) {
    tone(Buzzer_Pin, 523);
  } else {
    noTone(Buzzer_Pin);
  }
}
```

</details>

### 4.3. Call the functions from `loop()`

Call `buttonAction` once for each button and LED pair. Store the returned button states, then pass them to `playNote`.

<details>
<summary>Show Complete Code</summary>

```cpp
const int Button1_Pin = D0;
const int Button2_Pin = D1;
const int Button3_Pin = D2;

const int LED1_Pin = D3;
const int LED2_Pin = D4;
const int LED3_Pin = D5;

const int Buzzer_Pin = D6;

// Update an LED and return whether its button is pressed.
bool buttonAction(int button_pin, int led_pin) {
  bool pressed = (digitalRead(button_pin) == LOW);

  if (pressed) {
    digitalWrite(led_pin, HIGH);
  } else {
    digitalWrite(led_pin, LOW);
  }

  return pressed;
}

// Choose one note, or stop the sound if no buttons are pressed.
void playNote(bool button1, bool button2, bool button3) {
  if (button1) {
    tone(Buzzer_Pin, 440);
  } else if (button2) {
    tone(Buzzer_Pin, 494);
  } else if (button3) {
    tone(Buzzer_Pin, 523);
  } else {
    noTone(Buzzer_Pin);
  }
}

void setup() {
  pinMode(Button1_Pin, INPUT_PULLUP);
  pinMode(Button2_Pin, INPUT_PULLUP);
  pinMode(Button3_Pin, INPUT_PULLUP);

  pinMode(LED1_Pin, OUTPUT);
  pinMode(LED2_Pin, OUTPUT);
  pinMode(LED3_Pin, OUTPUT);

  pinMode(Buzzer_Pin, OUTPUT);
}

void loop() {
  bool button1 = buttonAction(Button1_Pin, LED1_Pin);
  bool button2 = buttonAction(Button2_Pin, LED2_Pin);
  bool button3 = buttonAction(Button3_Pin, LED3_Pin);

  playNote(button1, button2, button3);
}
```

</details>

## 5. Verify Your Synth

Upload the complete sketch and check that:

- Each button lights its corresponding LED.
- Each button plays the correct note.
- Releasing all buttons turns off all LEDs and stops the sound.
- Holding multiple buttons lights their LEDs and plays the highest-priority note.

**Extra challenge:** Change the three frequencies to create a different set of notes.