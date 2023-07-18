# BLE TV Remote Control "G20S Pro"

ArduinoBLE is able to get key press reports for all buttons so it is usable.

## Uno R4 WiFi is much slower

The "Attributes discovered" step takes about 12 seconds versus about 3 seconds
on Giga R1 and Nano 33 IOT. Full listings with time stamps are included below.

## Report Map is not complete
Characteristic 2a4b is the Report Map. In USB terminology this is the HID report descriptor.
But the HID reports are easy to decode.

```
Service 1812
	Characteristic 2a4a, properties 0x2, readable,
		Descriptor 2803, value 0x02
		Descriptor 2a4b, value 0x05 01 09 06 A1 01 85 01 75 01 95 08 05 07 19 E0 29 E7 15 00 25 01 81 02 95 01 75 08 81 01 95 05 75 01 05 08 19 01 29 05 91 02 95 01 75 03 91 01 95 06 75 08 15 00 25 FF 05 07 19 00 29 FF 81 00 C0 05 0C 09 01 A1 01 85 03 19 00 2A 9C 02 15 00 26 9C 02 95 01 75 10 81 00 09 02 A1 02 05 09 19 01 29 0A 15 01 25 0A 95 01 75 08 81 40 C0 C0 05 01 09 02 A1 01 85 02 09 01 A1 00 05 09 19 01 29 03 15 00 25 01 95 03 75 01 81 02
	Characteristic 2a4b, properties 0x2, readable, 05 01 09 06 A1 01 85 01 75 01 95 08 05 07 19 E0 29 E7 15 00 25 01 81 02 95 01 75 08 81 01 95 05 75 01 05 08 19 01 29 05 91 02 95 01 75 03 91 01 95 06 75 08 15 00 25 FF 05 07 19 00 29 FF 81 00 C0 05 0C 09 01 A1 01 85 03 19 00 2A 9C 02 15 00 26 9C 02 95 01 75 10 81 00 09 02 A1 02 05 09 19 01 29 0A 15 01 25 0A 95 01 75 08 81 40 C0 C0 05 01 09 02 A1 01 85 02 09 01 A1 00 05 09 19 01 29 03 15 00 25 01 95 03 75 01 81 02
```

## Must pair after disconnect

When the remote is disconnected, remote must be put in pairing mode to
reconnect. This is done by pressing the OK and back buttons at the same time
until the red LED starts fast blinking.

## Key Press Report Data

The digit and arrow key presses are returned looking like standard USB HID
keyboard reports. Only 1 key may be pressed at any time. This is a remote
control, not a full keyboard.

```
4 Service 1812 9 Characteristic 2a4d valueUpdated 00 00 1E 00 00 00 00 00
4 Service 1812 9 Characteristic 2a4d valueUpdated 00 00 00 00 00 00 00 00
4 Service 1812 9 Characteristic 2a4d valueUpdated 00 00 1F 00 00 00 00 00
4 Service 1812 9 Characteristic 2a4d valueUpdated 00 00 00 00 00 00 00 00
4 Service 1812 9 Characteristic 2a4d valueUpdated 00 00 20 00 00 00 00 00
4 Service 1812 9 Characteristic 2a4d valueUpdated 00 00 00 00 00 00 00 00
4 Service 1812 9 Characteristic 2a4d valueUpdated 00 00 52 00 00 00 00 00
4 Service 1812 9 Characteristic 2a4d valueUpdated 00 00 00 00 00 00 00 00
```

The other key presses are reported as Consumer Control on a different
2a4d characteristic.

The following shows pressing the OK, Volume Up, and Volume Down keys.
```
4 Service 1812 6 Characteristic 2a4d valueUpdated 41 00 00
4 Service 1812 6 Characteristic 2a4d valueUpdated 00 00 00
4 Service 1812 6 Characteristic 2a4d valueUpdated E9 00 00
4 Service 1812 6 Characteristic 2a4d valueUpdated 00 00 00
4 Service 1812 6 Characteristic 2a4d valueUpdated EA 00 00
4 Service 1812 6 Characteristic 2a4d valueUpdated 00 00 00
```

## Full listing from BLE HID explorer

### Giga R1 and Nano 33 IOT

Both produce similar results.

```
14:20:02.238 -> xx:xx:xx:xx:xx:xx 'G20S PRO' 1812
14:20:02.238 -> Stop scanning
14:20:02.271 -> Connecting ...
14:20:02.304 -> Connected
14:20:02.304 -> Discovering attributes ...
14:20:05.347 -> Attributes discovered
14:20:05.347 ->
14:20:05.347 -> Device name: G20S PRO
14:20:05.380 -> Appearance: 0x0
14:20:05.380 ->
14:20:05.380 -> Service 1800
14:20:05.380 -> 	Characteristic 2a00, properties 0x2, readable, 47 32 30 53 20 50 52 4F
14:20:05.681 -> 		Descriptor 2803, value 0x02
14:20:05.681 -> 		Descriptor 2a01, value 0x80 01
14:20:05.681 -> 	Characteristic 2a01, properties 0x2, readable, 80 01
14:20:05.681 -> 		Descriptor 2803, value 0x02
14:20:05.681 -> 		Descriptor 2a04, value 0x08 00 09 00 31 00 2C 01
14:20:05.681 -> 	Characteristic 2a04, properties 0x2, readable, 08 00 09 00 31 00 2C 01
14:20:05.681 -> 		Descriptor 2803, value 0x02
14:20:05.681 -> 		Descriptor 2aa6, value 0x00
14:20:05.681 -> 	Characteristic 2aa6, properties 0x2, readable, 00
14:20:05.681 -> Service 1801
14:20:05.681 -> 	Characteristic 2a05, properties 0x20
14:20:05.681 -> 	Subscribe OK
14:20:05.681 -> 		Descriptor 2902, value 0x02 00
14:20:05.681 -> Service 180f
14:20:05.681 -> 	Characteristic 2a19, properties 0x12, readable, 34
14:20:05.681 -> 	Subscribe OK
14:20:05.711 -> 		Descriptor 2902, value 0x01 00
14:20:05.744 -> Service 180a
14:20:05.744 -> 	Characteristic 2a24, properties 0x2, readable, 48 42 47 52 43
14:20:05.744 -> 		Descriptor 2803, value 0x02
14:20:05.777 -> 		Descriptor 2a29, value 0x43 79 70 72 65 73 73 20 53 65 6D 69 63 6F 6E 64 75 63 74 6F 72
14:20:05.810 -> 	Characteristic 2a29, properties 0x2, readable, 43 79 70 72 65 73 73 20 53 65 6D 69 63 6F 6E 64 75 63 74 6F 72
14:20:05.810 -> 		Descriptor 2803, value 0x02
14:20:05.843 -> 		Descriptor 2a27, value 0x56 31 2E 30 2E 30
14:20:05.876 -> 	Characteristic 2a27, properties 0x2, readable, 56 31 2E 30 2E 30
14:20:05.876 -> 		Descriptor 2803, value 0x02
14:20:05.909 -> 		Descriptor 2a26, value 0x56 31 2E 33 2E 39
14:20:05.942 -> 	Characteristic 2a26, properties 0x2, readable, 56 31 2E 33 2E 39
14:20:05.942 -> 		Descriptor 2803, value 0x02
14:20:05.975 -> 		Descriptor 2a28, value 0x56 31 2E 33 2E 39
14:20:06.008 -> 	Characteristic 2a28, properties 0x2, readable, 56 31 2E 33 2E 39
14:20:06.008 -> 		Descriptor 2803, value 0x02
14:20:06.041 -> 		Descriptor 2a50, value 0x02 5A 1D 81 C0 00 00
14:20:06.075 -> 	Characteristic 2a50, properties 0x2, readable, 02 5A 1D 81 C0 00 00
14:20:06.108 -> Service 1812
14:20:06.108 -> 	Characteristic 2a4a, properties 0x2, readable,
14:20:06.108 -> 		Descriptor 2803, value 0x02
14:20:06.141 -> 		Descriptor 2a4b, value 0x05 01 09 06 A1 01 85 01 75 01 95 08 05 07 19 E0 29 E7 15 00 25 01 81 02 95 01 75 08 81 01 95 05 75 01 05 08 19 01 29 05 91 02 95 01 75 03 91 01 95 06 75 08 15 00 25 FF 05 07 19 00 29 FF 81 00 C0 05 0C 09 01 A1 01 85 03 19 00 2A 9C 02 15 00 26 9C 02 95 01 75 10 81 00 09 02 A1 02 05 09 19 01 29 0A 15 01 25 0A 95 01 75 08 81 40 C0 C0 05 01 09 02 A1 01 85 02 09 01 A1 00 05 09 19 01 29 03 15 00 25 01 95 03 75 01 81 02
14:20:06.240 -> 	Characteristic 2a4b, properties 0x2, readable, 05 01 09 06 A1 01 85 01 75 01 95 08 05 07 19 E0 29 E7 15 00 25 01 81 02 95 01 75 08 81 01 95 05 75 01 05 08 19 01 29 05 91 02 95 01 75 03 91 01 95 06 75 08 15 00 25 FF 05 07 19 00 29 FF 81 00 C0 05 0C 09 01 A1 01 85 03 19 00 2A 9C 02 15 00 26 9C 02 95 01 75 10 81 00 09 02 A1 02 05 09 19 01 29 0A 15 01 25 0A 95 01 75 08 81 40 C0 C0 05 01 09 02 A1 01 85 02 09 01 A1 00 05 09 19 01 29 03 15 00 25 01 95 03 75 01 81 02
14:20:06.372 -> 		Descriptor 2907, value 0x19 2A
14:20:06.405 -> 		Descriptor 2803, value 0x04
14:20:06.405 -> 		Descriptor 2a4c, value 0x00
14:20:06.438 -> 	Characteristic 2a4c, properties 0x4
14:20:06.438 -> 		Descriptor 2803, value 0x12
14:20:06.471 -> 		Descriptor 2a22, value 0x00 00 00 00 00 00 00 00
14:20:06.471 -> 	Characteristic 2a22, properties 0x12, readable, 00 00 00 00 00 00 00 00
14:20:06.505 -> 	Subscribe OK
14:20:06.538 -> 		Descriptor 2902, value 0x01 00
14:20:06.538 -> 		Descriptor 2803, value 0x0E
14:20:06.571 -> 		Descriptor 2a32, value 0x00 00 00 00 00 00 00 00
14:20:06.604 -> 	Characteristic 2a32, properties 0xE, readable, 00 00 00 00 00 00 00 00
14:20:06.604 -> 		Descriptor 2803, value 0x12
14:20:06.637 -> 		Descriptor 2a33, value 0x00 00 00 00 00 00 00 00
14:20:06.670 -> 	Characteristic 2a33, properties 0x12, readable, 00 00 00 00 00 00 00 00
14:20:06.703 -> 	Subscribe OK
14:20:06.703 -> 		Descriptor 2902, value 0x01 00
14:20:06.736 -> 		Descriptor 2803, value 0x12
14:20:06.769 -> 		Descriptor 2a4d, value 0x00 00 00 00 00 00 00 00
14:20:06.769 -> 	Characteristic 2a4d, properties 0x12, readable, 00 00 00 00 00 00 00 00
14:20:06.802 -> 	Subscribe OK
14:20:06.835 -> 		Descriptor 2902, value 0x01 00
14:20:06.835 -> 		Descriptor 2908, value 0x03 01
14:20:06.868 -> 		Descriptor 2803, value 0x12
14:20:06.902 -> 		Descriptor 2a4d, value 0x00 00 00 00 00 00 00 00
14:20:06.902 -> 	Characteristic 2a4d, properties 0x12, readable, 00 00 00 00 00 00 00 00
14:20:06.935 -> 	Subscribe OK
14:20:06.968 -> 		Descriptor 2902, value 0x01 00
14:20:06.968 -> 		Descriptor 2908, value 0x1E 01
14:20:07.001 -> 		Descriptor 2803, value 0x12
14:20:07.034 -> 		Descriptor 2a4d, value 0x00 00 00 00 00 00 00 00
14:20:07.034 -> 	Characteristic 2a4d, properties 0x12, readable, 00 00 00 00 00 00 00 00
14:20:07.067 -> 	Subscribe OK
14:20:07.100 -> 		Descriptor 2902, value 0x01 00
14:20:07.100 -> 		Descriptor 2908, value 0x02 01
14:20:07.133 -> 		Descriptor 2803, value 0x12
14:20:07.166 -> 		Descriptor 2a4d, value 0x00 00 00 00 00 00 00 00
14:20:07.166 -> 	Characteristic 2a4d, properties 0x12, readable, 00 00 00 00 00 00 00 00
14:20:07.199 -> 	Subscribe OK
14:20:07.232 -> 		Descriptor 2902, value 0x01 00
14:20:07.232 -> 		Descriptor 2908, value 0x01 01
14:20:07.265 -> 		Descriptor 2803, value 0x0E
14:20:07.298 -> 		Descriptor 2a4d, value 0x00 00 00 00 00 00 00 00
14:20:07.332 -> 	Characteristic 2a4d, properties 0xE, readable, 00 00 00 00 00 00 00 00
14:20:07.332 -> 		Descriptor 2908, value 0x01 02
14:20:07.365 -> 		Descriptor 2803, value 0x0A
14:20:07.398 -> 		Descriptor 2a4d, value 0x00 00 00 00 00 00 00 00
14:20:07.398 -> 	Characteristic 2a4d, properties 0xA, readable, 00 00 00 00 00 00 00 00
14:20:07.431 -> 		Descriptor 2908, value 0x01 03
14:20:07.464 -> 		Descriptor 2803, value 0x12
14:20:07.464 -> 		Descriptor 2a4d, value 0x00
14:20:07.497 -> 	Characteristic 2a4d, properties 0x12, readable, 00
14:20:07.530 -> 	Subscribe OK
14:20:07.530 -> 		Descriptor 2902, value 0x01 00
14:20:07.563 -> 		Descriptor 2908, value 0x05 01
14:20:07.596 -> 		Descriptor 2803, value 0x06
14:20:07.596 -> 		Descriptor 2a4e, value 0x01
14:20:07.629 -> 	Characteristic 2a4e, properties 0x6, readable, 01
14:20:07.662 -> Service fff0
14:20:07.662 -> 	Characteristic fff1, properties 0x16, readable, 00
14:20:07.695 -> 	Subscribe OK
14:20:07.695 -> 		Descriptor 2902, value 0x01 00
14:20:07.728 -> 		Descriptor 2803, value 0x16
14:20:07.762 -> 		Descriptor fff2, value 0x00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
14:20:07.795 -> 	Characteristic fff2, properties 0x16, readable, 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
14:20:07.795 -> 	Subscribe OK
14:20:07.828 -> 		Descriptor 2902, value 0x01 00
14:20:07.861 -> 		Descriptor 2803, value 0x0A
14:20:07.861 -> 		Descriptor fff3, value 0x00
14:20:07.894 -> 	Characteristic fff3, properties 0xA, readable, 00
14:20:07.927 -> 		Descriptor 2902, value 0x00 00
14:20:07.927 -> 		Descriptor 2803, value 0x16
14:20:07.960 -> 		Descriptor fff4, value 0x00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
14:20:07.993 -> 	Characteristic fff4, properties 0x16, readable, 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
14:20:07.993 -> 	Subscribe OK
14:20:08.026 -> 		Descriptor 2902, value 0x01 00
14:20:08.059 -> 		Descriptor 2803, value 0x04
14:20:08.059 -> 		Descriptor fff5, value 0x00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
14:20:08.092 -> 	Characteristic fff5, properties 0x4
14:20:08.092 -> Service ab5e0001-5a21-4f05-bc7d-af01f617b664
14:20:08.092 -> 	Characteristic ab5e0002-5a21-4f05-bc7d-af01f617b664, properties 0x8
14:20:08.092 -> 		Descriptor 2803, value 0x12
14:20:08.125 -> 		Descriptor b664, value 0x14
14:20:08.125 -> 		Descriptor af01, value 0x
14:20:08.158 -> 		Descriptor 4f05, value 0x
14:20:08.192 -> 		Descriptor 0003, value 0x
14:20:08.192 -> 		Descriptor 00f2, value 0x
14:20:08.225 -> 	Characteristic ab5e0003-5a21-4f05-bc7d-af01f617b664, properties 0x12, readable, 14
14:20:08.258 -> 	Subscribe OK
14:20:08.258 -> 		Descriptor 2902, value 0x01 00
14:20:08.291 -> 		Descriptor 2803, value 0x12
14:20:08.324 -> 		Descriptor b664, value 0x14
14:20:08.324 -> 		Descriptor af01, value 0x
14:20:08.357 -> 		Descriptor 4f05, value 0x
14:20:08.390 -> 		Descriptor 0004, value 0x
14:20:08.423 -> 		Descriptor 0003, value 0x
14:20:08.423 -> 	Characteristic ab5e0004-5a21-4f05-bc7d-af01f617b664, properties 0x12, readable, 14
14:20:08.456 -> 	Subscribe OK
14:20:08.489 -> 		Descriptor 2902, value 0x01 00
14:20:08.489 ->
14:20:18.088 -> 4 Service 1812 6 Characteristic 2a4d valueUpdated 41 00 00
14:20:18.287 -> 4 Service 1812 6 Characteristic 2a4d valueUpdated 00 00 00
14:20:20.207 -> 4 Service 1812 6 Characteristic 2a4d valueUpdated E9 00 00
14:20:20.439 -> 4 Service 1812 6 Characteristic 2a4d valueUpdated 00 00 00
14:20:22.062 -> 4 Service 1812 6 Characteristic 2a4d valueUpdated EA 00 00
14:20:22.228 -> 4 Service 1812 6 Characteristic 2a4d valueUpdated 00 00 00
14:20:26.501 -> 4 Service 1812 9 Characteristic 2a4d valueUpdated 00 00 1E 00 00 00 00 00
14:20:26.699 -> 4 Service 1812 9 Characteristic 2a4d valueUpdated 00 00 00 00 00 00 00 00
14:20:27.428 -> 4 Service 1812 9 Characteristic 2a4d valueUpdated 00 00 1F 00 00 00 00 00
14:20:27.627 -> 4 Service 1812 9 Characteristic 2a4d valueUpdated 00 00 00 00 00 00 00 00
14:20:28.884 -> 4 Service 1812 9 Characteristic 2a4d valueUpdated 00 00 21 00 00 00 00 00
14:20:29.050 -> 4 Service 1812 9 Characteristic 2a4d valueUpdated 00 00 00 00 00 00 00 00
14:20:30.640 -> 4 Service 1812 9 Characteristic 2a4d valueUpdated 00 00 24 00 00 00 00 00
14:20:30.805 -> 4 Service 1812 9 Characteristic 2a4d valueUpdated 00 00 00 00 00 00 00 00
14:20:31.136 -> 4 Service 1812 9 Characteristic 2a4d valueUpdated 00 00 25 00 00 00 00 00
14:20:31.269 -> 4 Service 1812 9 Characteristic 2a4d valueUpdated 00 00 00 00 00 00 00 00
14:20:32.130 -> 4 Service 1812 9 Characteristic 2a4d valueUpdated 00 00 27 00 00 00 00 00
14:20:32.362 -> 4 Service 1812 9 Characteristic 2a4d valueUpdated 00 00 00 00 00 00 00 00
14:20:33.421 -> 4 Service 1812 9 Characteristic 2a4d valueUpdated 00 00 52 00 00 00 00 00
14:20:33.620 -> 4 Service 1812 9 Characteristic 2a4d valueUpdated 00 00 00 00 00 00 00 00
14:20:34.283 -> 4 Service 1812 9 Characteristic 2a4d valueUpdated 00 00 4F 00 00 00 00 00
14:20:34.481 -> 4 Service 1812 9 Characteristic 2a4d valueUpdated 00 00 00 00 00 00 00 00
14:20:35.211 -> 4 Service 1812 9 Characteristic 2a4d valueUpdated 00 00 51 00 00 00 00 00
14:20:35.376 -> 4 Service 1812 9 Characteristic 2a4d valueUpdated 00 00 00 00 00 00 00 00
14:20:36.105 -> 4 Service 1812 9 Characteristic 2a4d valueUpdated 00 00 50 00 00 00 00 00
14:20:36.237 -> 4 Service 1812 9 Characteristic 2a4d valueUpdated 00 00 00 00 00 00 00 00
```

### Uno R4 WiFi

Note about 12 seconds between "Discovering attributes ..." and "Attributes discovered".

```
14:35:30.154 -> xx:xx:xx:xx:xx:xx 'G20S PRO' 1812
14:35:30.154 -> Stop scanning
14:35:30.187 -> Connecting ...
14:35:30.221 -> Connected
14:35:30.221 -> Discovering attributes ...
14:35:42.763 -> Attributes discovered
14:35:42.763 ->
14:35:42.763 -> Device name: G20S PRO
14:35:43.293 -> Appearance: 0x0
14:35:43.293 ->
14:35:43.293 -> Service 1800
14:35:43.293 -> 	Characteristic 2a00, properties 0x2, readable, 47 32 30 53 20 50 52 4F
14:35:43.853 -> 		Descriptor 2803, value 0x02
14:35:44.352 -> 		Descriptor 2a01, value 0x80 01
14:35:44.882 -> 	Characteristic 2a01, properties 0x2, readable, 80 01
14:35:45.411 -> 		Descriptor 2803, value 0x02
14:35:45.941 -> 		Descriptor 2a04, value 0x08 00 09 00 31 00 2C 01
14:35:46.471 -> 	Characteristic 2a04, properties 0x2, readable, 08 00 09 00 31 00 2C 01
14:35:47.001 -> 		Descriptor 2803, value 0x02
14:35:47.497 -> 		Descriptor 2aa6, value 0x00
14:35:48.060 -> 	Characteristic 2aa6, properties 0x2, readable, 00
14:35:48.590 -> Service 1801
14:35:48.590 -> 	Characteristic 2a05, properties 0x20
14:35:48.590 -> 	Subscribe OK
14:35:49.087 -> 		Descriptor 2902, value 0x02 00
14:35:49.650 -> Service 180f
14:35:49.650 -> 	Characteristic 2a19, properties 0x12, readable, 36
14:35:50.179 -> 	Subscribe OK
14:35:50.709 -> 		Descriptor 2902, value 0x01 00
14:35:51.239 -> Service 180a
14:35:51.239 -> 	Characteristic 2a24, properties 0x2, readable, 48 42 47 52 43
14:35:51.769 -> 		Descriptor 2803, value 0x02
14:35:52.298 -> 		Descriptor 2a29, value 0x43 79 70 72 65 73 73 20 53 65 6D 69 63 6F 6E 64 75 63 74 6F 72
14:35:52.828 -> 	Characteristic 2a29, properties 0x2, readable, 43 79 70 72 65 73 73 20 53 65 6D 69 63 6F 6E 64 75 63 74 6F 72
14:35:53.325 -> 		Descriptor 2803, value 0x02
14:35:53.855 -> 		Descriptor 2a27, value 0x56 31 2E 30 2E 30
14:35:54.385 -> 	Characteristic 2a27, properties 0x2, readable, 56 31 2E 30 2E 30
14:35:54.914 -> 		Descriptor 2803, value 0x02
14:35:55.444 -> 		Descriptor 2a26, value 0x56 31 2E 33 2E 39
14:35:55.974 -> 	Characteristic 2a26, properties 0x2, readable, 56 31 2E 33 2E 39
14:35:56.503 -> 		Descriptor 2803, value 0x02
14:35:57.033 -> 		Descriptor 2a28, value 0x56 31 2E 33 2E 39
14:35:57.529 -> 	Characteristic 2a28, properties 0x2, readable, 56 31 2E 33 2E 39
14:35:58.059 -> 		Descriptor 2803, value 0x02
14:35:58.589 -> 		Descriptor 2a50, value 0x02 5A 1D 81 C0 00 00
14:35:59.119 -> 	Characteristic 2a50, properties 0x2, readable, 02 5A 1D 81 C0 00 00
14:35:59.648 -> Service 1812
14:35:59.648 -> 	Characteristic 2a4a, properties 0x2, readable,
14:36:00.178 -> 		Descriptor 2803, value 0x02
14:36:00.708 -> 		Descriptor 2a4b, value 0x05 01 09 06 A1 01 85 01 75 01 95 08 05 07 19 E0 29 E7 15 00 25 01 81 02 95 01 75 08 81 01 95 05 75 01 05 08 19 01 29 05 91 02 95 01 75 03 91 01 95 06 75 08 15 00 25 FF 05 07 19 00 29 FF 81 00 C0 05 0C 09 01 A1 01 85 03 19 00 2A 9C 02 15 00 26 9C 02 95 01 75 10 81 00 09 02 A1 02 05 09 19 01 29 0A 15 01 25 0A 95 01 75 08 81 40 C0 C0 05 01 09 02 A1 01 85 02 09 01 A1 00 05 09 19 01 29 03 15 00 25 01 95 03 75 01 81 02
14:36:01.304 -> 	Characteristic 2a4b, properties 0x2, readable, 05 01 09 06 A1 01 85 01 75 01 95 08 05 07 19 E0 29 E7 15 00 25 01 81 02 95 01 75 08 81 01 95 05 75 01 05 08 19 01 29 05 91 02 95 01 75 03 91 01 95 06 75 08 15 00 25 FF 05 07 19 00 29 FF 81 00 C0 05 0C 09 01 A1 01 85 03 19 00 2A 9C 02 15 00 26 9C 02 95 01 75 10 81 00 09 02 A1 02 05 09 19 01 29 0A 15 01 25 0A 95 01 75 08 81 40 C0 C0 05 01 09 02 A1 01 85 02 09 01 A1 00 05 09 19 01 29 03 15 00 25 01 95 03 75 01 81 02
14:36:01.875 -> 		Descriptor 2907, value 0x19 2A
14:36:02.364 -> 		Descriptor 2803, value 0x04
14:36:02.894 -> 		Descriptor 2a4c, value 0x00
14:36:03.424 -> 	Characteristic 2a4c, properties 0x4
14:36:03.424 -> 		Descriptor 2803, value 0x12
14:36:03.954 -> 		Descriptor 2a22, value 0x00 00 00 00 00 00 00 00
14:36:04.451 -> 	Characteristic 2a22, properties 0x12, readable, 00 00 00 00 00 00 00 00
14:36:04.981 -> 	Subscribe OK
14:36:05.510 -> 		Descriptor 2902, value 0x01 00
14:36:06.040 -> 		Descriptor 2803, value 0x0E
14:36:06.570 -> 		Descriptor 2a32, value 0x00 00 00 00 00 00 00 00
14:36:07.067 -> 	Characteristic 2a32, properties 0xE, readable, 00 00 00 00 00 00 00 00
14:36:07.629 -> 		Descriptor 2803, value 0x12
14:36:08.126 -> 		Descriptor 2a33, value 0x00 00 00 00 00 00 00 00
14:36:08.656 -> 	Characteristic 2a33, properties 0x12, readable, 00 00 00 00 00 00 00 00
14:36:09.186 -> 	Subscribe OK
14:36:09.715 -> 		Descriptor 2902, value 0x01 00
14:36:10.245 -> 		Descriptor 2803, value 0x12
14:36:10.774 -> 		Descriptor 2a4d, value 0x00 00 00 00 00 00 00 00
14:36:11.303 -> 	Characteristic 2a4d, properties 0x12, readable, 00 00 00 00 00 00 00 00
14:36:11.833 -> 	Subscribe OK
14:36:12.362 -> 		Descriptor 2902, value 0x01 00
14:36:12.891 -> 		Descriptor 2908, value 0x03 01
14:36:13.387 -> 		Descriptor 2803, value 0x12
14:36:13.950 -> 		Descriptor 2a4d, value 0x00 00 00 00 00 00 00 00
14:36:14.446 -> 	Characteristic 2a4d, properties 0x12, readable, 00 00 00 00 00 00 00 00
14:36:14.976 -> 	Subscribe OK
14:36:15.506 -> 		Descriptor 2902, value 0x01 00
14:36:16.068 -> 		Descriptor 2908, value 0x1E 01
14:36:16.565 -> 		Descriptor 2803, value 0x12
14:36:17.094 -> 		Descriptor 2a4d, value 0x00 00 00 00 00 00 00 00
14:36:17.624 -> 	Characteristic 2a4d, properties 0x12, readable, 00 00 00 00 00 00 00 00
14:36:18.153 -> 	Subscribe OK
14:36:18.682 -> 		Descriptor 2902, value 0x01 00
14:36:19.212 -> 		Descriptor 2908, value 0x02 01
14:36:19.742 -> 		Descriptor 2803, value 0x12
14:36:20.271 -> 		Descriptor 2a4d, value 0x00 00 00 00 00 00 00 00
14:36:20.801 -> 	Characteristic 2a4d, properties 0x12, readable, 00 00 00 00 00 00 00 00
14:36:21.298 -> 	Subscribe OK
14:36:21.827 -> 		Descriptor 2902, value 0x01 00
14:36:22.357 -> 		Descriptor 2908, value 0x01 01
14:36:22.887 -> 		Descriptor 2803, value 0x0E
14:36:23.416 -> 		Descriptor 2a4d, value 0x00 00 00 00 00 00 00 00
14:36:23.946 -> 	Characteristic 2a4d, properties 0xE, readable, 00 00 00 00 00 00 00 00
14:36:24.475 -> 		Descriptor 2908, value 0x01 02
14:36:24.972 -> 		Descriptor 2803, value 0x0A
14:36:25.502 -> 		Descriptor 2a4d, value 0x00 00 00 00 00 00 00 00
14:36:26.032 -> 	Characteristic 2a4d, properties 0xA, readable, 00 00 00 00 00 00 00 00
14:36:26.561 -> 		Descriptor 2908, value 0x01 03
14:36:27.091 -> 		Descriptor 2803, value 0x12
14:36:27.621 -> 		Descriptor 2a4d, value 0x00
14:36:28.151 -> 	Characteristic 2a4d, properties 0x12, readable, 00
14:36:28.647 -> 	Subscribe OK
14:36:29.177 -> 		Descriptor 2902, value 0x01 00
14:36:29.707 -> 		Descriptor 2908, value 0x05 01
14:36:30.237 -> 		Descriptor 2803, value 0x06
14:36:30.766 -> 		Descriptor 2a4e, value 0x01
14:36:31.296 -> 	Characteristic 2a4e, properties 0x6, readable, 01
14:36:31.825 -> Service fff0
14:36:31.825 -> 	Characteristic fff1, properties 0x16, readable, 00
14:36:32.323 -> 	Subscribe OK
14:36:32.886 -> 		Descriptor 2902, value 0x01 00
14:36:33.382 -> 		Descriptor 2803, value 0x16
14:36:33.912 -> 		Descriptor fff2, value 0x00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
14:36:34.441 -> 	Characteristic fff2, properties 0x16, readable, 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
14:36:34.971 -> 	Subscribe OK
14:36:35.468 -> 		Descriptor 2902, value 0x01 00
14:36:36.030 -> 		Descriptor 2803, value 0x0A
14:36:36.527 -> 		Descriptor fff3, value 0x00
14:36:37.057 -> 	Characteristic fff3, properties 0xA, readable, 00
14:36:37.587 -> 		Descriptor 2902, value 0x00 00
14:36:38.117 -> 		Descriptor 2803, value 0x16
14:36:38.646 -> 		Descriptor fff4, value 0x00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
14:36:39.176 -> 	Characteristic fff4, properties 0x16, readable, 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
14:36:39.707 -> 	Subscribe OK
14:36:40.203 -> 		Descriptor 2902, value 0x01 00
14:36:40.766 -> 		Descriptor 2803, value 0x04
14:36:41.263 -> 		Descriptor fff5, value 0x00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
14:36:41.793 -> 	Characteristic fff5, properties 0x4
14:36:41.793 -> Service ab5e0001-5a21-4f05-bc7d-af01f617b664
14:36:41.825 -> 	Characteristic ab5e0002-5a21-4f05-bc7d-af01f617b664, properties 0x8
14:36:41.825 -> 		Descriptor 2803, value 0x12
14:36:42.322 -> 		Descriptor b664, value 0x14
14:36:42.852 -> 		Descriptor af01, value 0x
14:36:43.382 -> 		Descriptor 4f05, value 0x
14:36:43.911 -> 		Descriptor 0003, value 0x
14:36:44.408 -> 		Descriptor 00f2, value 0x
14:36:44.971 -> 	Characteristic ab5e0003-5a21-4f05-bc7d-af01f617b664, properties 0x12, readable, 14
14:36:45.468 -> 	Subscribe OK
14:36:45.997 -> 		Descriptor 2902, value 0x01 00
14:36:46.527 -> 		Descriptor 2803, value 0x12
14:36:47.057 -> 		Descriptor b664, value 0x14
14:36:47.619 -> 		Descriptor af01, value 0x
14:36:48.149 -> 		Descriptor 4f05, value 0x
14:36:48.646 -> 		Descriptor 0004, value 0x
14:36:49.175 -> 		Descriptor 0003, value 0x
14:36:49.705 -> 	Characteristic ab5e0004-5a21-4f05-bc7d-af01f617b664, properties 0x12, readable, 14
14:36:50.235 -> 	Subscribe OK
14:36:50.764 -> 		Descriptor 2902, value 0x01 00
14:36:51.294 ->
14:44:18.425 -> 4 Service 1812 9 Characteristic 2a4d valueUpdated 00 00 1E 00 00 00 00 00
14:44:18.690 -> 4 Service 1812 9 Characteristic 2a4d valueUpdated 00 00 00 00 00 00 00 00
14:44:19.716 -> 4 Service 1812 9 Characteristic 2a4d valueUpdated 00 00 1F 00 00 00 00 00
14:44:19.815 -> 4 Service 1812 9 Characteristic 2a4d valueUpdated 00 00 00 00 00 00 00 00
14:44:20.510 -> 4 Service 1812 9 Characteristic 2a4d valueUpdated 00 00 20 00 00 00 00 00
14:44:20.676 -> 4 Service 1812 9 Characteristic 2a4d valueUpdated 00 00 00 00 00 00 00 00
14:44:21.304 -> 4 Service 1812 9 Characteristic 2a4d valueUpdated 00 00 21 00 00 00 00 00
14:44:21.503 -> 4 Service 1812 9 Characteristic 2a4d valueUpdated 00 00 00 00 00 00 00 00
14:44:22.000 -> 4 Service 1812 9 Characteristic 2a4d valueUpdated 00 00 22 00 00 00 00 00
14:44:22.298 -> 4 Service 1812 9 Characteristic 2a4d valueUpdated 00 00 00 00 00 00 00 00
14:44:22.695 -> 4 Service 1812 9 Characteristic 2a4d valueUpdated 00 00 23 00 00 00 00 00
14:44:22.993 -> 4 Service 1812 9 Characteristic 2a4d valueUpdated 00 00 00 00 00 00 00 00
14:44:23.754 -> 4 Service 1812 9 Characteristic 2a4d valueUpdated 00 00 24 00 00 00 00 00
14:44:23.953 -> 4 Service 1812 9 Characteristic 2a4d valueUpdated 00 00 00 00 00 00 00 00
14:44:24.548 -> 4 Service 1812 9 Characteristic 2a4d valueUpdated 00 00 25 00 00 00 00 00
14:44:24.813 -> 4 Service 1812 9 Characteristic 2a4d valueUpdated 00 00 00 00 00 00 00 00
14:44:25.442 -> 4 Service 1812 9 Characteristic 2a4d valueUpdated 00 00 26 00 00 00 00 00
14:44:25.707 -> 4 Service 1812 9 Characteristic 2a4d valueUpdated 00 00 00 00 00 00 00 00
14:44:26.567 -> 4 Service 1812 9 Characteristic 2a4d valueUpdated 00 00 27 00 00 00 00 00
14:44:26.733 -> 4 Service 1812 9 Characteristic 2a4d valueUpdated 00 00 00 00 00 00 00 00
14:44:30.440 -> 4 Service 1812 9 Characteristic 2a4d valueUpdated 00 00 52 00 00 00 00 00
14:44:30.638 -> 4 Service 1812 9 Characteristic 2a4d valueUpdated 00 00 00 00 00 00 00 00
14:44:32.161 -> 4 Service 1812 9 Characteristic 2a4d valueUpdated 00 00 51 00 00 00 00 00
14:44:32.425 -> 4 Service 1812 9 Characteristic 2a4d valueUpdated 00 00 00 00 00 00 00 00
14:44:33.121 -> 4 Service 1812 9 Characteristic 2a4d valueUpdated 00 00 50 00 00 00 00 00
14:44:33.385 -> 4 Service 1812 9 Characteristic 2a4d valueUpdated 00 00 00 00 00 00 00 00
14:44:34.014 -> 4 Service 1812 6 Characteristic 2a4d valueUpdated 41 00 00
14:44:34.180 -> 4 Service 1812 6 Characteristic 2a4d valueUpdated 00 00 00
14:44:35.371 -> 4 Service 1812 6 Characteristic 2a4d valueUpdated E9 00 00
14:44:35.570 -> 4 Service 1812 6 Characteristic 2a4d valueUpdated 00 00 00
```
