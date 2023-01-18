# Nebula-openwatch
Nebula is a ESP32 based smartwatch proof of concept that features a rotating bezel encoder along with a suite of sensors and parts. This includes:

-ESP32-S3-MINI with wifi and bluetooth LE capabilities
-3 pushbuttons, 2 programmable
-I2C Ambient light sensor for automatic screen dimming
-Onboard lipo charging
-Onboard ldo regulator with voltage supervisor

-I2S amplifier for audio output (BLUETOOTH LE DOES NOT SUPPORT STREAMING AUDIO,CHANGES ARE NEEDED TO BOARD TO ENABLE USE OF THIS CHIP)

-I2S Mems microphone for  audio input(BLUETOOTH LE DOES NOT SUPPORT STREAMING AUDIO)

-I2C RTC module (HASNT BEEN SUFFICENTLY TESTED)

-Haptic vibration motor for user feedback

-4 pin dock connector (2.54 female header) for use with dock that provides serial programming and power.

-I2C 3 axis gyroscope and accelerometer

-200mah lipo battery

Total size is ~44mm diameter, ~12mm height

DO NOT BUILD PROOF OF CONCEPT FOR REFERENCE ONLY
