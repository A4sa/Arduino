## Summary

This is a library for the Arduino IDE that helps interface with ST's LSM6DS33 and LSM6DSO 3D accelerometer and gyro ICs on Pololu boards. It makes it simple to configure the LSM6 and read the raw accelerometer and gyro data from these boards:

 * [LSM6DSO 3D accelerometer and gyro carrier](https://www.pololu.com/product/2798)
 * [LSM6DS33 3D accelerometer and gyro carrier](https://www.pololu.com/product/2736)
 * [MinIMU-9 v6 (LSM6DSO and LIS3MDL carrier)](https://www.pololu.com/product/2862)
 * [AltIMU-10 v6 (LSM6DSO, LIS3MDL, and LPS22DF Carrier)](https://www.pololu.com/product/2863)
 * [MinIMU-9 v5 (LSM6DS33 and LIS3MDL carrier)](https://www.pololu.com/product/2738)
 * [AltIMU-9 v5 (LSM6DS33, LIS3MDL, and LPS25H carrier)](https://www.pololu.com/product/2739)

## Getting started

### Hardware

An LSM6 carrier can be purchased from Pololu's website.  Before continuing, careful reading of the product page as well as the chip datasheet and application note is recommended.

Make the following connections between the Arduino and the LSM6 board:

#### 5V Arduino boards

(including Arduino Uno, Leonardo, Mega;)

    Arduino   LSM6 board
    -------   ----------
         5V - VIN
        GND - GND
        SDA - SDA
        SCL - SCL

#### 3.3V Arduino boards

(including Arduino Due)

    Arduino   LSM6 board
    -------   ----------
        3V3 - VIN
        GND - GND
        SDA - SDA
        SCL - SCL

### Software

If you are using version 1.6.2 or later of the [Arduino software (IDE)](http://www.arduino.cc/en/Main/Software), you can use the Library Manager to install this library:

1. In the Arduino IDE, open the "Sketch" menu, select "Include Library", then "Manage Libraries...".
2. Search for "LSM6".
3. Click the LSM6 entry in the list.
4. Click "Install".

If this does not work, you can manually install the library:

1. Download the [latest release archive from GitHub](https://github.com/pololu/lsm6-arduino/releases) and decompress it.
2. Rename the folder "lsm6-arduino-master" to "LSM6".
3. Move the "LSM6" folder into the "libraries" directory inside your Arduino sketchbook directory.  You can view your sketchbook location by opening the "File" menu and selecting "Preferences" in the Arduino IDE.  If there is not already a "libraries" folder in that location, you should make the folder yourself.
4. After installing the library, restart the Arduino IDE.

## Examples

An example sketch is available that shows how to use the library. You can access it from the Arduino IDE by opening the "File" menu, selecting "Examples", and then selecting "LSM6". If you cannot find the example, the library was probably installed incorrectly and you should retry the installation instructions above.

## Library reference

* `vector<int16_t> a`<br>
  The last values read from the accelerometer.

* `vector<int16_t> g`<br>
  The last values read from the gyro.

* `uint8_t last_status`<br>
  The status of the last I&sup2;C write transmission. See the [`Wire.endTransmission()` documentation](http://arduino.cc/en/Reference/WireEndTransmission) for return values.

* `LSM6()`<br>
  Constructor.

* `void setBus(TwoWire * bus)`<br>
  Configures this object to use the specified I&sup2;C bus. `bus` should be a pointer to a `TwoWire` object; the default bus is `Wire`, which is typically the first or only I&sup2;C bus on an Arduino. If your Arduino has more than one I&sup2;C bus and you have the VL53L0X connected to the second bus, which is typically called `Wire1`, you can call `sensor.setBus(&Wire1);`.

* `TwoWire * getBus()`<br>
  Returns a pointer to the I&sup2;C bus this object is using.

* `bool init(deviceType device, sa0State sa0)`<br>
  Initializes the library with the device being used (`device_DS33` or `device_auto`) and the state of the SA0 pin (`sa0_low`, `sa0_high`, or `sa0_auto`), which determines the least significant bit of the I&sup2;C slave address. Constants for these arguments are defined in LSM6.h. Both of these arguments are optional; if they are not specified, the library will try to automatically detect the device address. A boolean is returned indicating whether the type of LSM6 device was successfully determined (if necessary).

* `void getDeviceType()`<br>
  Returns the device type specified to or detected by `init()`.

* `void enableDefault()`<br>
  Turns on the accelerometer and gyro and enables a consistent set of default settings.

  This function will reset the accelerometer to &plusmn;2&nbsp;g full scale and the gyro to &plusmn;245&nbsp;dps. See the comments in LSM6.cpp for a full explanation of the settings.

* `void writeReg(uint8_t reg, uint8_t value)`<br>
  Writes a sensor register with the given value.

  Register address constants are defined by the regAddr enumeration type in LSM6.h.<br>
  Example use: `imu.writeReg(LSM6::CTRL1_XL, 0x80);`

* `uint8_t readReg(uint8_t reg)`<br>
  Reads a sensor register and returns the value read.

* `void readAcc()`<br>
  Takes a reading from the accelerometer and stores the values in the vector `a`. Conversion of the readings to units of g depends on the accelerometer's selected gain (full scale setting).

* `void readGyro()`<br>
  Takes a reading from the gyro and stores the values in the vector `g`. Conversion of the readings to units of dps (degrees per second) depends on the gyro's selected gain (full scale setting).

* `void read()`<br>
  Takes a reading from both the accelerometer and gyro and stores the values in the vectors `a` and `g`.

## Version history

* 2.0.1 (2022-10-14): Renamed PIN_CTRL to DSO_PIN_CTRL to work around a naming conflict with the ESP32. The original name can still be used on other platforms.
* 2.0.0 (2022-09-02): Added support for LSM6DSO and support for alternative I&sup2;C buses. Removed timeout functionality that did not work as intended.
* 1.0.0 (2016-01-19): Original release.

