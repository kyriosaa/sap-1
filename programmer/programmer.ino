// SAP-1 8-bit computer EEPROM Programmer
// Arduino Nano

#define SHIFT_DATA  2
#define SHIFT_CLK   3
#define SHIFT_LATCH 4

void setAddress(int address, bool outputEnable) {
  // since com is 8-bit, we need to account for numbers that are larger than 8-bits
  shiftOut(SHIFT_DATA, SHIFT_CLK, MSBFIRST, (address >> 8) | (outputEnable ? 0x00 : 0x80));  // ">> 8" shifts all bits to the right by 8 places
  shiftOut(SHIFT_DATA, SHIFT_CLK, MSBFIRST, address);         // outputs the remainding bits that were shifted out on the line above

  digitalWrite(SHIFT_LATCH, LOW);
  digitalWrite(SHIFT_LATCH, HIGH);
  digitalWrite(SHIFT_LATCH, LOW);
}

void setup() {
  pinMode(SHIFT_DATA, OUTPUT);
  pinMode(SHIFT_CLK, OUTPUT);
  pinMode(SHIFT_LATCH, OUTPUT);

  setAddress(1234, false);
}

void loop() {

}
