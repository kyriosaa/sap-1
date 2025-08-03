// SAP-1 8-bit computer EEPROM Hex Decoder Programmer
// Arduino Nano

#define SHIFT_DATA  2
#define SHIFT_CLK   3
#define SHIFT_LATCH 4
#define EEPROM_D0   5
#define EEPROM_D7   12
#define WRITE_EN    13

void setAddress(int address, bool outputEnable) {
  // since com is 8-bit, we need to account for numbers that are larger than 8-bits
  shiftOut(SHIFT_DATA, SHIFT_CLK, MSBFIRST, (address >> 8) | (outputEnable ? 0x00 : 0x80));  // ">> 8" shifts all bits to the right by 8 places
  shiftOut(SHIFT_DATA, SHIFT_CLK, MSBFIRST, address);         // outputs the remainding bits that were shifted out on the line above

  digitalWrite(SHIFT_LATCH, LOW);
  digitalWrite(SHIFT_LATCH, HIGH);
  digitalWrite(SHIFT_LATCH, LOW);
}

void writeEEPROM(int address, byte data) {
  for(int pin = EEPROM_D0; pin <= EEPROM_D7; pin += 1) {
    pinMode(pin, OUTPUT);
  }

  setAddress(address, /*outputEnable*/ false);
  for(int pin = EEPROM_D0; pin <= EEPROM_D7; pin += 1) {
    digitalWrite(pin, data & 1);
    data = data >> 1;
  }
  // pulse
  digitalWrite(WRITE_EN, LOW);
  delayMicroseconds(1);
  digitalWrite(WRITE_EN, HIGH);
  delay(5);   // if reading doesnt work properly change it to 10
}

// print all EEPROM addresses
void printContents() {
  Serial.println("Reading EEPROM");
  for(int base = 0; base <= 255; base += 16 /*read 16 EEPROM bytes at a time*/) {
    byte data[16];
    for(int offset = 0; offset <= 15; offset += 1) {
      data[offset] = readEEPROM(base + offset);
    }

    char buf[80];
    sprintf(buf, "%03x:   %02x %02x %02x %02x %02x %02x %02x %02x   %02x %02x %02x %02x %02x %02x %02x %02x",
            base, data[0], data[1], data[2], data[3], data[4], data[5], data[6], data[7],
            data[8], data[9], data[10], data[11], data[12], data[13], data[14], data[15]);
    
    Serial.println(buf);
  }
}

// 4-bit hex decoder for 7-seg display (common cathode)
byte data[] = {0x7e, 0x30, 0x6d, 0x79, 0x33, 0x5b, 0x5f, 0x70, 0x7f, 0x7b, 0x77, 0x1f, 0x4e, 0x3d, 0x4f, 0x47};

// 4-bit hex decoder for 7-seg display (common anode)
// byte data[] = {0x81, 0xcf, 0x92, 0x86, 0xcc, 0xa4, 0xa0, 0x8f, 0x80, 0x84, 0x88, 0xe0, 0xb1, 0xc2, 0xb0, 0xb8};

void setup() {
  pinMode(SHIFT_DATA, OUTPUT);
  pinMode(SHIFT_CLK, OUTPUT);
  pinMode(SHIFT_LATCH, OUTPUT);

  digitalWrite(WRITE_EN, HIGH);
  pinMode(WRITE_EN, OUTPUT);

  Serial.begin(115200);
  Serial.println("\n");

  // clear EEPROM
  Serial.print("Clearing EEPROM");
  int clearTimeStart = millis();
  for(int address = 0; address <= 2047; address += 1) {
    writeEEPROM(address, 0xff);

    if(address % 64 == 0) {
      Serial.print(".");
    }
  }
  int clearTimeEnd = millis() - clearTimeStart;
  Serial.println(" done (" + String(clearTimeEnd) + " ms)");

  // program 16 bytes
  Serial.print("Programming EEPROM");
  int programTimeStart = millis();
  for(int address = 0; address <= 15; address += 1) {
    writeEEPROM(address, data[address]);

    if(address % 64 == 0) {
      Serial.print(".");
    }
  }
  int programTimeEnd = millis() - programTimeStart;
  Serial.println(" done (" + String(programTimeEnd) + " ms)");

  printContents();
}

byte readEEPROM(int address) {
  for(int pin = EEPROM_D0; pin <= EEPROM_D7; pin += 1) {
    pinMode(pin, INPUT);
  }

  setAddress(address, /*outputEnable*/ true);
  byte data = 0;
  for(int pin = EEPROM_D7; pin >= EEPROM_D0; pin -= 1) {
    data = (data << 1) + digitalRead(pin);
  }
  return data;
}

void loop() {

}
