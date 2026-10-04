# Getting Started With Arduino IDE

## 1. Installation

Download and install **Arduino IDE 2** from the [Arduino website](https://www.arduino.cc/en/software), then open it.

## 2. Boards Manager

1. Open **Boards Manager** from the left sidebar.
2. Search for `esp32`.
3. Install **esp32 by Espressif Systems**, (not **Arduino ESP32 Boards by Arduino**.)
4. Wait for installation to finish. This may take several minutes.

## 3. Connecting to Your Device

1. Open the board dropdown near the top of the IDE.
2. Connect your **XIAO ESP32S3** to your computer using a **USB data cable**. A charge-only cable will not work. A new port should appear in the dropdown.
- On Windows, the port usually looks like `COM3` or `COM4`. On macOS, it usually contains `usbmodem`.
3. Go to **Tools → Board → esp32 → XIAO_ESP32S3**.

In the bottom right corner of the screen it should say `ESP32S3 on [port number] connected`. If it says `not connected` then follow the troubleshooting steps below until it has been connected.

<details>
<summary>Troubleshooting</summary>

First, check that your cable supports data transfer.

If the board still does not appear, enter bootloader mode:

1. Unplug the board.
2. Press and hold the button labeled **BOOT**.
3. While holding BOOT, plug the board into your computer.
4. Release BOOT.
5. Select the port that appears in Arduino IDE.

Bootloader mode prepares the board to receive a program.

</details>

## 4. Flashing Code

Flashing means writing your program to the board's memory.

1. Open **File → Examples → 01.Basics → Blink**.
2. Check that the correct board and port are selected in the new window.
3. Click **Upload**, the right-arrow button near the **top-left** corner.
4. Wait until uploading finishes.
5. The orange user LED should begin blinking. If it does not start after a successful upload, press **RESET** (top-left button) once.

<details><summary>Verify vs. Upload</summary>

- **Verify (checkmark):** Compiles your code and checks for errors without sending it to the board.
- **Upload (right arrow):** Compiles your code and sends it to the board.

You can click Upload directly; you do not need to click Verify first.
</details>

<details>
<summary>What should I do each time to upload code?</summary>

For normal uploads:

1. Connect the board.
2. Check the selected board and port.
3. Open or edit your code.
4. Click **Upload** and wait for it to finish.

You normally do not need to press BOOT or RESET.

If uploading fails because the IDE cannot connect to the board:

1. Follow the bootloader-mode instructions above.
2. Select the board's port again—it may have changed.
3. Click **Upload**.
4. After uploading finishes, press **RESET** if the program does not start.

Your XIAO ESP32S3 is now ready to program!
</details>

## 5. Blink.ino & Arduino Code Structure

Arduino sketches are written in C++. Let's look at `Blink.ino` to understand the basic structure of an Arduino program.

### Arduino Code Structure: setup and loop
A typical sketch contains two main functions: `setup()` and `loop()`.

- **`setup()`** runs once each time the board powers on or resets. Use it to configure pins, start serial communication, and initialize sensors or other hardware.
- **`loop()`** runs repeatedly after `setup()` finishes. Use it for tasks such as reading sensors, checking buttons, and updating outputs. Whenever it reaches the end, it starts again.

Variables declared inside `setup()` are local to that function—you cannot access them directly from `loop()`. Use loop for doing stuff, not assigning global values. If both functions need a variable, you can declare it outside both functions. We will talk about how to write functions next week.

### Blink.ino: Setup Function
Inside `setup`, `pinMode(LED_BUILTIN, OUTPUT);` initializes LED_BUILTIN as an output pin. Every pin on the microcontroller can be set as either an input or an output. `LED_BUILTIN` addresses the on-board LED, we can also set actual pins to be outputs or inputs. To find out what names to use for them and what they can be used for we need to look at their pinout diagrams.

### Blink.ino: Loop Function
Inside `loop`, `digitalWrite(LED_BUILTIN, HIGH)` writes HIGH to LED_BUILTIN. 
- **Pins that are outputs can be written to using `digitalWrite`** 
- **Pins that are inputs can be read from using `digitalRead`.** 

Finally, we do `delay(1000)` to create a delay of 1000ms or 1 second. This keeps the LED on for 1 second before writing low to it to turn it off. 

