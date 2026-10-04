# Week 1 Project: A Buzzer Synth
In this project, we will create a synth using a microcontroller, a passive buzzer, some buttons, and some LEDs.

## 1. Detect Button Presses

We will be connecting 3 buttons to `D0,`, `D1,`, and  `D2`, assigning them to variables called `Button1_Pin`, `Button2_Pin`, and `Button3_Pin`, and setting them as `INPUT_PULLUP`s. Then we will detect button pressed with `digitalRead(pin) == LOW` as a condition that the button has been pressed. We will verify that the press has been detected by printing to serial monitor.

### 1. Open up a new Arduino sketch.  
### 2. Create variables for the button pins.

> <details>
> <summary>Show Details</summary>
>
> Create 3 variables named `Button1_Pin`, `Button2_Pin`, and `Button3_Pin` for each button pin. 
>
> Initialize them with the type const int, and assign their values with `D0,`, `D1,`, and  `D2`. 
>
> This code goes above the loop and setup functions.
>
> </details>

> <details>
> <summary>Show Code</summary>
>
> ```cpp
> const int Button_Pin0 = D0;
> const int Button_Pin1 = D1;
> const int Button_Pin2 = D2;
> ```
>
> </details>


### 3. Set them as `INPUT_PULLUP`.

> <details>
> <summary>Show Explanation</summary>
>
> We want to detect when the buttons are pressed, which means reading the state of the pin. They will be connected to ground, so we should set them to HIGH when not pressed. 
> This means they must be set as `INPUT_PULLUP`. 
> Set the 3 button pins as `INPUT_PULLUP` using the `pinMode(pin_name, pin_mode)` function. 
> This code goes inside the `setup()` function.
>
> </details>

> <details>
> <summary>Show Code</summary>
>
> ```cpp
> pinMode(Button1_Pin, INPUT_PULLUP);
> pinMode(Button2_Pin, INPUT_PULLUP);
> pinMode(Button3_Pin, INPUT_PULLUP);
> ```
>
> </details>

### 4. Connect the buttons to your microcontroller.

> <details>
> <summary> Show Connection Diagram </summary>
>
>- **Button 1:** one leg to `Button1_Pin`, other leg to `GND`.
>- **Button 2:** one leg to `Button2_Pin`, other leg to `GND`.
>- **Button 3:** one leg to `Button3_Pin`, other leg to `GND`.
>
></details>
### 5. Test Button Presses in Serial Monitor

> <details>
> <summary>Show Explanation</summary>
>
>We want to test if we've wired and coded everything correctly, but we don't have any LEDs or buzzers to respond to a button press. This is a good opportunity to use the serial monitor. 
>
>Add code to the `loop` function so that the serial monitor prints text when a button is pressed. Flash the code onto your microcontroller and verify functionality using serial monitor.
>
>
> Use Serial.begin(<baudrate>) and make sure the baud rate matches the one you select in the monitor.
>
> Use Serial.println() to print a new line of text
>
> Use digitalRead(pin_name) to get the value at each pin. Remember LOW means that the pin is pressed.
>
> Use conditional statements to print only when a button is pressed.
>
> ```cpp
> if(digitalRead(Button1_Pin) == LOW){
>   Serial.println("button 1 pressed");
>}
> if(digitalRead(Button2_Pin) == LOW){
>   Serial.println("button 2 pressed");
>}
> if(digitalRead(Button3_Pin) == LOW){
>   Serial.println("button 3 pressed");
>}
> ```
>
>
> </details>


## 2. Setting Up LED Outputs

### 1. Create variables for the LED pins.
Similar to the button pins, we will make variables for the LED pins. This time we will use `D3`, `D4`, and `D5` and name them `LED1_Pin`, `LED2_Pin`, and `LED3_Pin`.

> <details>
> <summary>Show Code</summary>
>
> ```cpp
> const int LED1_Pin = D3;
> const int LED2_Pin = D4;
> const int LED3_Pin = D5;
> ```
>
> </details>

### 3. Set them as outputs.
The LEDs should be set as outputs so that we can do `digitalWrite(pin, value)` to turn them on/off, as seen in the `Blink.ino` example. This code should go inside the `setup` function.

> <details>
> <summary>Show button code</summary>
>
> ```cpp
> pinMode(LED1_Pin, OUTPUT);
> pinMode(LED2_Pin, OUTPUT);
> pinMode(LED3_Pin, OUTPUT);
> ```
>
> </details>

### 4. Connecting LED to microcontroller

The LED has an anode and a cathode.
- **ANODE** should be connected to the positive power source, which is the microcontroller pin.
- **ANODE** is the **LONG** leg of the LED.
- **CATHODE** should be connected to ground.
- **CATHODE** is the **SHORT** leg of the LED.

Each LED should be set up like this: **[MCU LED pin] -- [Anode -- LED -- Cathode] -- [Resistor] -- [Ground]**

You can do a basic test in code to make sure they are connected properly before doing the next step by pasting the following code into the `loop` function above the `if` statements.

``` cpp
digitalWrite(LED1_Pin, HIGH);
digitalWrite(LED2_Pin, HIGH);
digitalWrite(LED3_Pin, HIGH);
```


### 5. Turning on LED in Code
Add code to the `if` statements in the `loop` function for each button press so that each button turns on a different LED. You will need to add an `else` statement so that they LEDs turn off when the button is released. Upload the code and verify that it works.

> <details>
> <summary>Show Code</summary>
>
> ```cpp
> if (digitalRead(Button1_Pin) == LOW) {
>   digitalWrite(LED1_Pin, HIGH);
> } else {
>   digitalWrite(LED1_Pin, LOW);
> }
>
> if (digitalRead(Button2_Pin) == LOW) {
>   digitalWrite(LED2_Pin, HIGH);
> } else {
>   digitalWrite(LED2_Pin, LOW);
> }
>
> if (digitalRead(Button3_Pin) == LOW) {
>   digitalWrite(LED3_Pin, HIGH);
> } else {
>   digitalWrite(LED3_Pin, LOW);
> }
> ```
>
> </details>

## 3. Connect buzzer to microcontroller and set it up as an output.

### 1. Connect buzzer to MCU
We will use pin `D6`. The buzzer is not polarized which means that it doesn't matter which leg you connect to the MCU and which leg you connect to ground.

Connection diagram: **[MCU Pin D6] --- [Leg1 -- Buzzer -- Leg2] --- [Ground]**

### 2. Create variable called Buzzer_Pin
This should again go above the `loop` and `setup` functions. 

> <details>
> <summary>Show Code</summary>
>
> ```cpp
> const int Buzzer_Pin = D6;
> ```
>
> </details>

### 3. Set it as an output
This code goes in `setup`.

> <details>
> <summary>Show Code</summary>
>
> ```cpp
> pinMode(Buzzer_Pin, OUTPUT);
> ```
>
> </details>

### 4. Use tone(buzzer_pin, frequency); to play a 440 Hz tone.
To test if we've connected the buzzer correctly, add the following code to `loop`:

```cpp

tone(Buzzer_Pin, 440);

```

Upload the code. The buzzer should play a tone constantly.


### 5. Modify code so that it the buzzer plays a specific tone for each button, and stops with noTone(Buzzer_Pin)

## 4. Condense each button's behavior into a function, and call it in place of the separate statements.