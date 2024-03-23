
<p align="center">
	<img src="http://content.arduino.cc/brand/arduino-color.svg" width="50%" />
</p>

# Introduction
**Arduino** is an open-source physical computing platform based on a simple I/O board and a development environment that implements the Processing/Wiring
language. Arduino can be used to develop stand-alone interactive objects or can be connected to software on your computer (e.g. Flash, Processing and MaxMSP).The boards can be assembled by hand or purchased preassembled; the open-source IDE can be downloaded for free at [https://arduino.cc](https://www.arduino.cc/en/Main/Software)

The **Arduino** platform has become quite popular with people just starting out with electronics, and for good reason. Unlike most previous programmable circuit boards, the Arduino does not need a separate piece of hardware (called a programmer) in order to load new code onto the board -- you can simply use a USB cable. Additionally, the Arduino IDE uses a simplified version of C++, making it easier to learn to program. Finally, Arduino provides a standard form factor that breaks out the functions of the micro-controller into a more accessible package <hr>

# Arduino UNO Components
There are many varieties of Arduino boards that can be used for different purposes. Some boards look a bit different from the one below, but most Arduinos have the majority of these components in common:
<p align="center">
	<img src="https://cdn.sparkfun.com/r/600-600/assets/b/f/e/9/c/513824face395f6d3d000000.png" width="50%" />
</p>

### Power (USB / Barrel Jack)
- Every Arduino board needs a way to be connected to a power source. The Arduino UNO can be powered from a USB cable coming from your computer or a wall power supply (like this) that is terminated in a barrel jack. In the picture above the USB connection is labeled **(1)** and the barrel jack is labeled **(2)**.

- The USB connection is also how you will load code onto your Arduino board. More on how to program with Arduino can be found in our Installing and Programming Arduino tutorial.

- NOTE: Do NOT use a power supply greater than 20 Volts as you will overpower (and thereby destroy) your Arduino. The recommended voltage for most Arduino models is between 6 and 12 Volts.

### Pins (5V, 3.3V, GND, Analog, Digital, PWM, AREF)
- The pins on your Arduino are the places where you connect wires to construct a circuit (probably in conjuction with a breadboard and some wire. They usually have black plastic ‘headers’ that allow you to just plug a wire right into the board. The Arduino has several different kinds of pins, each of which is labeled on the board and used for different functions.

  - **GND (3)**: Short for ‘Ground’. There are several GND pins on the Arduino, any of which can be used to ground your circuit.
  - **5V (4) & 3.3V (5)**: As you might guess, the 5V pin supplies 5 volts of power, and the 3.3V pin supplies 3.3 volts of power. Most of the simple components used with the Arduino run happily off of 5 or 3.3 volts.
  - **Analog (6)**: The area of pins under the ‘Analog In’ label (A0 through A5 on the UNO) are Analog In pins. These pins can read the signal from an analog sensor (like a temperature sensor) and convert it into a digital value that we can read.
  - **Digital (7)**: Across from the analog pins are the digital pins (0 through 13 on the UNO). These pins can be used for both digital input (like telling if a button is pushed) and digital output (like powering an LED).
  - **PWM (8)**: You may have noticed the tilde (~) next to some of the digital pins (3, 5, 6, 9, 10, and 11 on the UNO). These pins act as normal digital pins, but can also be used for something called Pulse-Width Modulation (PWM). We have a tutorial on PWM, but for now, think of these pins as being able to simulate analog output (like fading an LED in and out).
  - **AREF (9)**: Stands for Analog Reference. Most of the time you can leave this pin alone. It is sometimes used to set an external reference voltage (between 0 and 5 Volts) as the upper limit for the analog input pins.
 
### Reset Button
Just like the original Nintendo, the Arduino has a reset button **(10)**. Pushing it will temporarily connect the reset pin to ground and restart any code that is loaded on the Arduino. This can be very useful if your code doesn’t repeat, but you want to test it multiple times. Unlike the original Nintendo however, blowing on the Arduino doesn't usually fix any problems.

### Power LED Indicator
Just beneath and to the right of the word “UNO” on your circuit board, there’s a tiny LED next to the word ‘ON’ **(11)**. This LED should light up whenever you plug your Arduino into a power source. If this light doesn’t turn on, there’s a good chance something is wrong. Time to re-check your circuit!

### TX RX LEDs
TX is short for transmit, RX is short for receive. These markings appear quite a bit in electronics to indicate the pins responsible for serial communication. In our case, there are two places on the Arduino UNO where TX and RX appear -- once by digital pins 0 and 1, and a second time next to the TX and RX indicator LEDs **(12)**. These LEDs will give us some nice visual indications whenever our Arduino is receiving or transmitting data (like when we’re loading a new program onto the board).

### Main IC
The black thing with all the metal legs is an IC, or Integrated Circuit **(13)**. Think of it as the brains of our Arduino. The main IC on the Arduino is slightly different from board type to board type, but is usually from the ATmega line of IC’s from the ATMEL company. This can be important, as you may need to know the IC type (along with your board type) before loading up a new program from the Arduino software. This information can usually be found in writing on the top side of the IC. If you want to know more about the difference between various IC's, reading the datasheets is often a good idea.

### Voltage Regulator
The voltage regulator (14) is not actually something you can (or should) interact with on the Arduino. But it is potentially useful to know that it is there and what it’s for. The voltage regulator does exactly what it says -- it controls the amount of voltage that is let into the Arduino board. Think of it as a kind of gatekeeper; it will turn away an extra voltage that might harm the circuit. Of course, it has its limits, so don’t hook up your Arduino to anything greater than 20 volts. 

<p align="center">
	<img src="https://github.com/Bouni/Arduino-Pinout/raw/master/Arduino%20Uno%20Pinout.png" width="50%" />
</p> <hr>

# Microcontroller
The ATmega328 microcontroller is the MCU used in Arduino UNO R3 as a main controller. ATmega328 is an MCU from the AVR family; it is an 8-bit device, which means that its data-bus architecture and internal registers are designed to handle 8 parallel data signals.

- **ATmega328** has three types of memory

  - **Flash memory**: 32KB nonvolatile memory. This is used for storing application, which explains why you don't need to upload your application every time you unplug arduino from its power source.
  - **SRAM memory**: 2KB volatile memory. This is used for storing variables used by the application while it's running.
  - **EEPROM memory**: 1KB nonvolatile memory. This can be used to store data that must be available even after the board is powered down and then powered up again.
 <hr>

# Getting Started

To get started with these projects, follow these steps:

1. **Clone the Repository:** Clone this repository to your local machine using the following command:

    ```
    git clone https://github.com/A4sa/Arduino.git
    ```

2. **Navigate to Project Directory:** Navigate to the directory of the project you're interested in:

    ```
    cd Arduino/project-name
    ```

3. **Set Up Arduino IDE:** Ensure you have the Arduino IDE installed on your machine. If not, download and install it from the [Arduino website](https://www.arduino.cc/en/software).

4. **Open Project Sketch:** Open the `.ino` file corresponding to the project in the Arduino IDE.

5. **Upload to Arduino Board:** Connect your Arduino board to your computer via USB, select the correct board and port in the Arduino IDE, then upload the sketch to the board.

6. **Explore and Experiment:** Once uploaded, explore the code, experiment with modifications, and enjoy tinkering with Arduino!
-----
# Projects Overview

Here's a brief overview of the projects included in this repository:

1. **LED Blink:** A basic Arduino sketch to blink an LED connected to a digital pin.
2. **Temperature Monitor:** An Arduino project to read temperature data from a sensor and display it on an LCD screen.
3. **Motion Detector:** An Arduino-based motion detector using a PIR sensor to detect movement.
4. **IoT Weather Station:** A more advanced project that connects Arduino to the internet to fetch and display weather data.

Feel free to explore each project directory for more details and instructions on how to set up and run the projects.
