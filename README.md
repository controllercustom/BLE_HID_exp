# BLE HID Explorer for ArduinoBLE

BLE_HID_exp dumps out information about BLE HID devices to find HID devices
that work with ArduinoBLE. The Arduino board plays the role of BLE Central.
This program should work any ArduinoBLE supported board.

The following devices are usable.

## BLE Gamepad/Joystick with analog joystick and 7 buttons

https://www.amazon.com/gp/product/B09QJLV6JJ/

The X, Y, and buttons can be decoded after subscribing to the Report Data
characteristics.

## BLE TV Remote Control "G20S Pro"

ArduinoBLE is able to get key press reports for all buttons so it is usable.

[TV Remote Control G20S Pro](./TV_remote.md)

## Sample output for BLE joystick

The small slide switch must be in the GAME position to get analog values for
the thumb joystick.

Note 1: The Report Map is never returned. The joystick does send a Report Map
because it works fine with a Raspberry Pi. hcidump shows the Report Map works.

Note 2: Subscribe reports failure on the HID service (1812) characteristics but
valuesUpdated() return true so it is usable.

```
xx:xx:xx:xx:xx:xx 'Fortune-KEY/GAME' 1812
Stop scanning
Connecting ...
Connected
Discovering attributes ...
Attributes discovered

Device name: Fortune-KEY/GAME
Appearance: 0x0

Service 1800
	Characteristic 2a00, properties 0x2, readable, 46 6F 72 74 75 6E 65 2D 4B 45 59 2F 47 41 4D 45 
		Descriptor 2803, value 0x02 05 00 01 2A 
		Descriptor 2a01, value 0x00 00 
	Characteristic 2a01, properties 0x2, readable, 00 00 
		Descriptor 2803, value 0x02 07 00 04 2A 
		Descriptor 2a04, value 0x50 00 A0 00 00 00 E8 03 
	Characteristic 2a04, properties 0x2, readable, 50 00 A0 00 00 00 E8 03 
		Descriptor 2803, value 0x02 09 00 A6 2A 
		Descriptor 2aa6, value 0x01 
	Characteristic 2aa6, properties 0x2, readable, 01 
Service 1801
	Characteristic 2a05, properties 0x20
	Subscribe OK
		Descriptor 2902, value 0x02 00 
Service 180a
	Characteristic 2a23, properties 0x2, readable, 00 00 00 00 00 00 00 00 
		Descriptor 2803, value 0x02 12 00 24 2A 
		Descriptor 2a24, value 0x4D 6F 64 65 6C 20 4E 75 6D 62 65 72 
	Characteristic 2a24, properties 0x2, readable, 4D 6F 64 65 6C 20 4E 75 6D 62 65 72 
		Descriptor 2803, value 0x02 14 00 25 2A 
		Descriptor 2a25, value 0x30 30 38 30 30 
	Characteristic 2a25, properties 0x2, readable, 30 30 38 30 30 
		Descriptor 2803, value 0x02 16 00 26 2A 
		Descriptor 2a26, value 0x46 69 72 6D 77 61 72 65 20 52 65 76 69 73 69 6F 6E 
	Characteristic 2a26, properties 0x2, readable, 46 69 72 6D 77 61 72 65 20 52 65 76 69 73 69 6F 6E 
		Descriptor 2803, value 0x02 18 00 27 2A 
		Descriptor 2a27, value 0x48 61 72 64 77 61 72 65 20 52 65 76 69 73 69 6F 6E 
	Characteristic 2a27, properties 0x2, readable, 48 61 72 64 77 61 72 65 20 52 65 76 69 73 69 6F 6E 
		Descriptor 2803, value 0x02 1A 00 28 2A 
		Descriptor 2a28, value 0x53 6F 66 74 77 61 72 65 20 52 65 76 69 73 69 6F 6E 
	Characteristic 2a28, properties 0x2, readable, 53 6F 66 74 77 61 72 65 20 52 65 76 69 73 69 6F 6E 
		Descriptor 2803, value 0x02 1C 00 29 2A 
		Descriptor 2a29, value 0x4D 4F 43 55 54 45 
	Characteristic 2a29, properties 0x2, readable, 4D 4F 43 55 54 45 
		Descriptor 2803, value 0x02 1E 00 2A 2A 
		Descriptor 2a2a, value 0xFE 00 65 78 70 65 72 69 6D 65 6E 74 61 6C 
	Characteristic 2a2a, properties 0x2, readable, FE 00 65 78 70 65 72 69 6D 65 6E 74 61 6C 
		Descriptor 2803, value 0x02 20 00 50 2A 
		Descriptor 2a50, value 0x01 D7 07 00 00 10 01 
	Characteristic 2a50, properties 0x2, readable, 01 D7 07 00 00 10 01 
Service 1812
	Characteristic 2a4a, properties 0x2, readable, 
		Descriptor 2803, value 0x04 25 00 4C 2A 
		Descriptor 2a4c, value 0x
	Characteristic 2a4c, properties 0x4
		Descriptor 2803, value 0x06 27 00 4E 2A 
		Descriptor 2a4e, value 0x
	Characteristic 2a4e, properties 0x6, readable, 
		Descriptor 2803, value 0x02 29 00 4B 2A 
		Descriptor 2a4b, value 0x
	Characteristic 2a4b, properties 0x2, readable, 
		Descriptor 2907, value 0x19 2A 
		Descriptor 2803, value 0x12 2C 00 4D 2A 
		Descriptor 2a4d, value 0x
	Characteristic 2a4d, properties 0x12, readable, 
	Subscribe Fail
		Descriptor 2902, value 0x00 00 
		Descriptor 2908, value 0x01 01 
		Descriptor 2803, value 0x12 30 00 4D 2A 
		Descriptor 2a4d, value 0x
	Characteristic 2a4d, properties 0x12, readable, 
	Subscribe Fail
		Descriptor 2902, value 0x00 00 
		Descriptor 2908, value 0x02 01 
		Descriptor 2803, value 0x12 34 00 4D 2A 
		Descriptor 2a4d, value 0x
	Characteristic 2a4d, properties 0x12, readable, 
	Subscribe Fail
		Descriptor 2902, value 0x00 00 
		Descriptor 2908, value 0x03 01 
		Descriptor 2803, value 0x12 38 00 4D 2A 
		Descriptor 2a4d, value 0x
	Characteristic 2a4d, properties 0x12, readable, 
	Subscribe Fail
		Descriptor 2902, value 0x00 00 
		Descriptor 2908, value 0x04 01 
		Descriptor 2803, value 0x0A 3C 00 4D 2A 
		Descriptor 2a4d, value 0x
	Characteristic 2a4d, properties 0xA, readable, 
		Descriptor 2908, value 0x00 03 

3 Service 1812 7 Characteristic 2a4d valueUpdated 
3 Service 1812 7 Characteristic 2a4d valueUpdated 80 80 80 80 00 00 09 00 00 x: 128 y: 128 buttons: 0x0
3 Service 1812 7 Characteristic 2a4d valueUpdated 80 80 80 80 00 00 09 00 00 x: 128 y: 128 buttons: 0x0
3 Service 1812 7 Characteristic 2a4d valueUpdated 80 80 7F 7F 00 00 09 80 00 x: 128 y: 128 buttons: 0x80
3 Service 1812 4 Characteristic 2a4d valueUpdated 01 00 00 00 
3 Service 1812 7 Characteristic 2a4d valueUpdated 80 80 7F 7F 00 00 09 00 00 x: 128 y: 128 buttons: 0x0
3 Service 1812 4 Characteristic 2a4d valueUpdated 00 00 00 00 
3 Service 1812 7 Characteristic 2a4d valueUpdated 80 66 80 80 00 00 09 00 00 x: 128 y: 102 buttons: 0x0
3 Service 1812 7 Characteristic 2a4d valueUpdated 80 80 80 80 00 00 09 00 00 x: 128 y: 128 buttons: 0x0
3 Service 1812 7 Characteristic 2a4d valueUpdated AF C8 80 80 00 00 09 00 00 x: 175 y: 200 buttons: 0x0
3 Service 1812 7 Characteristic 2a4d valueUpdated 7D FC 80 80 00 00 09 00 00 x: 125 y: 252 buttons: 0x0
3 Service 1812 7 Characteristic 2a4d valueUpdated 51 AF 80 80 00 00 09 00 00 x: 81 y: 175 buttons: 0x0
3 Service 1812 7 Characteristic 2a4d valueUpdated 80 80 80 80 00 00 09 00 00 x: 128 y: 128 buttons: 0x0
3 Service 1812 7 Characteristic 2a4d valueUpdated 7B 73 80 80 00 00 09 00 00 x: 123 y: 115 buttons: 0x0
3 Service 1812 7 Characteristic 2a4d valueUpdated 80 80 80 80 00 00 09 00 00 x: 128 y: 128 buttons: 0x0
```
