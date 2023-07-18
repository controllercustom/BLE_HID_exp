/*
   BLE HID Explorer

   This example scans for Bluetooth® Low Energy peripherals until one with
   the HID service is found. Then connects, and discovers + prints all
   the device's attributes. In addition subscribe to all available
   characteristics and dump notifications/indications. When disconnected,
   resume scanning for new devices.

   This example is based on the ArduinoBLE PerhiperalExplorer example.

   This example code is in the public domain.
*/
#include <ArduinoBLE.h>

typedef struct __attribute__((__packed__)) {
  uint8_t buttons;
  int8_t  x;
  int8_t  y;
  int8_t  wheel;
} vr_fortune_mouse_t;

typedef struct __attribute__((__packed__)) {
  uint8_t x;
  uint8_t y;
  uint8_t z;
  uint8_t rz;
  uint8_t brake;
  uint8_t gas;
  uint8_t hat:4;
  uint8_t filler:4;
  uint16_t buttons;
} vr_fortune_t;

static const String HID_SERVICE_alt("1812");
static const String HID_SERVICE("1812");
static const char HID_REPORT_MAP[] = "2A4B";
static const char HID_REPORT[] = "2A4D";

void setup() {
  Serial.begin(115200);
  while (!Serial) delay(1);
  Serial.println();
  Serial.println("BLE HID Host");
  Serial.flush();
  //Serial.print("HID_SERVICE_alt ");
  //Serial.println(HID_SERVICE_alt);
  Serial.print("HID_SERVICE ");
  Serial.println(HID_SERVICE);

  // begin initialization
  if (!BLE.begin()) {
    Serial.println("starting Bluetooth® Low Energy module failed!");

    while (1);
  }
  Serial.println("BLE.begin() OK");

  // start scanning for peripherals without duplicates
  BLE.scan(false);
}

void loop() {
  // check if a peripheral has been discovered
  BLEDevice peripheral = BLE.available();

  if (peripheral) {
    // discovered a peripheral, print out address, local name, and advertised service
    Serial.print(peripheral.address());
    Serial.print(" '");
    Serial.print(peripheral.localName());
    Serial.print("' ");
    String service;
    for (int i = 0; ; i++) {
      service = peripheral.advertisedServiceUuid(i);
      if (service == "") {
        break;
      }
      Serial.print(service);
      Serial.println();
      if (service.equals(HID_SERVICE)) {
        Serial.println("Stop scanning");
        BLE.stopScan();

        explorerPeripheral(peripheral);

        Serial.println("Start scanning");
        BLE.scan(false);
      }
    }
    Serial.println();
  }
}

void explorerPeripheral(BLEDevice peripheral) {
  // connect to the peripheral
  Serial.println("Connecting ...");

  if (peripheral.connect()) {
    Serial.println("Connected");
  } else {
    Serial.println("Failed to connect!");
    return;
  }

  // discover peripheral attributes
  Serial.println("Discovering attributes ...");
  if (peripheral.discoverAttributes()) {
    Serial.println("Attributes discovered");
  } else {
    Serial.println("Attribute discovery failed!");
    peripheral.disconnect();
    return;
  }

  // read and print device name of peripheral
  Serial.println();
  Serial.print("Device name: ");
  Serial.println(peripheral.deviceName());
  Serial.print("Appearance: 0x");
  Serial.println(peripheral.appearance(), HEX);
  Serial.println();

  // loop the services of the peripheral and explore each
  for (int i = 0; i < peripheral.serviceCount(); i++) {
    BLEService service = peripheral.service(i);

    exploreService(service);
  }

  Serial.println();

  while (peripheral.connected()) {
    // for each service
    for (int service_i = 0; service_i < peripheral.serviceCount(); service_i++) {
      BLEService service = peripheral.service(service_i);

      // for each characteristic
      for (int char_i = 0; char_i < service.characteristicCount(); char_i++) {
        BLECharacteristic characteristic = service.characteristic(char_i);

        // check if the characteristic supports Notification or Indication
        if (characteristic.canSubscribe()) {
          // Check for new values
          if (characteristic.valueUpdated()) {
            uint8_t report[32];
            size_t report_len;
            Serial.print(service_i);
            Serial.print(" Service ");
            Serial.print(service.uuid());
            Serial.print(' ');
            Serial.print(char_i);
            Serial.print(" Characteristic ");
            Serial.print(characteristic.uuid());
            Serial.print(" valueUpdated ");
            report_len = characteristic.readValue(report, sizeof(report));
            printData(report, report_len);
            switch (report_len) {
              case sizeof(vr_fortune_t):
                {
                  vr_fortune_t *joy = (vr_fortune_t *)report;
                  Serial.print("x: "); Serial.print(joy->x);
                  Serial.print(" y: "); Serial.print(joy->y);
                  Serial.print(" buttons: 0x"); Serial.print(joy->buttons, HEX);
                  break;
                }
              case sizeof(vr_fortune_mouse_t):
                {
#if 0
                  vr_fortune_mouse_t *joy = (vr_fortune_mouse_t *)report;
                  Serial.print("x: "); Serial.print(joy->x);
                  Serial.print(" y: "); Serial.print(joy->y);
                  Serial.print(" buttons: 0x"); Serial.print(joy->buttons, HEX);
#endif
                  break;
                }
              default:
                break;
            }
            Serial.println();
          }
        }
      }
    }
    delay(1);
  }

  // we are done exploring, disconnect
  Serial.println("Disconnecting ...");
  peripheral.disconnect();
  Serial.println("Disconnected");
}

void exploreService(BLEService service) {
  // print the UUID of the service
  Serial.print("Service ");
  Serial.println(service.uuid());

  // loop the characteristics of the service and explore each
  for (int i = 0; i < service.characteristicCount(); i++) {
    BLECharacteristic characteristic = service.characteristic(i);

    exploreCharacteristic(characteristic);
  }
}

void exploreCharacteristic(BLECharacteristic characteristic) {
  // print the UUID and properties of the characteristic
  Serial.print("\tCharacteristic ");
  Serial.print(characteristic.uuid());
  Serial.print(", properties 0x");
  Serial.print(characteristic.properties(), HEX);

  // check if the characteristic is readable
  if (characteristic.canRead()) {
    Serial.print(", readable, ");
    // read the characteristic value
    characteristic.read();
    if (characteristic.valueLength() > 0) {
      // print out the value of the characteristic
      printData(characteristic.value(), characteristic.valueLength());
    }
  }
  Serial.println();

  // check if the characteristic supports Notification or Indication
  if (characteristic.canSubscribe()) {
    Serial.print("\tSubscribe ");
    if (characteristic.subscribe()) {
      Serial.println("OK");
    } else {
      Serial.println("Fail");
    }
  }

  // loop the descriptors of the characteristic and explore each
  for (int i = 0; i < characteristic.descriptorCount(); i++) {
    BLEDescriptor descriptor = characteristic.descriptor(i);

    exploreDescriptor(descriptor);
  }
}

void exploreDescriptor(BLEDescriptor descriptor) {
  // print the UUID of the descriptor
  Serial.print("\t\tDescriptor ");
  Serial.print(descriptor.uuid());

  // read the descriptor value
  descriptor.read();

  // print out the value of the descriptor
  Serial.print(", value 0x");
  printData(descriptor.value(), descriptor.valueLength());

  Serial.println();
}

void printData(const unsigned char data[], int length) {
  for (int i = 0; i < length; i++) {
    unsigned char b = data[i];

    if (b < 16) {
      Serial.print("0");
    }

    Serial.print(b, HEX);
    Serial.print(' ');
  }
}
