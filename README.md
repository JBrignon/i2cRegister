# i2cRegister
The i2cRegister library provide a complete solution to create, use and manage two bytes Registers on your AVR based i2c Slave. It has been tested on Arduino Uno and AtTiny 85.
## Install
  - Download zip of the library from GitHub
  - Extract and rename the folder "i2cRegister"
  - Copy/Paste the folder to your arduino library folder
## Library Reference
  - `i2cRegister(int RegisterSize)`
     Constructor of the object i2cRegister need the size of the wanted register as argument.
  - `void setByte(byte registerAddr,byte MSB,byte LSB)`
     This function allow you to directly write bytes into a register address. You need to provide the address into the register and the         MSB and LSB of the word to write, remenber that `byte` is similar to `unsigned char`.
  - `void getByte(byte registerAddr,byte *val)`
     This function return as an array of bytes the word store at the providen address of the register.
  - `void storeInt(byte registerAddr, int val)`
     Store the given `Integer` value into the register at the providen address.
  -  `int readInt(byte registerAddr)`
     This function read the given address and return the value as `Integer`.
  -  `int buildInt(byte MSB, byte LSB)`
     Function used by readInt() to buil an `Integer` value from a `binary Word`, that function can be useful on the i2c Master to read `Integer` values.
  -  `void byteInt(int val, byte *res)`
     Function used by storeInt() to build a `binary Word` from an `Integer`, can also be useful on the i2c Master to send `Integer` values.
  - `void storeFloat(byte registerAddr, float val)`
     Same as storeInt() with a `Float` value.
  -  `int readFloat(byte registerAddr)`
     Same as readInt() with a `Float` value.
  -  `int buildFloat(byte MSB, byte LSB)`
     Same as buildInt() with a `Float` value.
  -  `void byteFloat(float val, byte *res)`
     Same as byteInt() with a `Float` value.
  -  `void saveEEPROM()`
      Save the whole Register to the EEPROM of your AVR.
  -  `void readEEPROM()`
      Restore the whole Register from the EEPROM.
## Warnings
When using this library you have to remember that every `Float` cannot be stored as a `binary Word` so values are stored with only two digits and can only represent values in the range of [-327.68;327.67].
## Examples
If you want to get an example of an i2c Slave made using that library you can check my `TinyCapteur repository` https://github.com/JBrignon/TinyCapteur that used an AtTiny as an i2c interface for HCSR04 and PT100 sensors. However the code is only commented in French.
