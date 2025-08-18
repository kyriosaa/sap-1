// SAP-1 8-bit computer EEPROM Microcode Programmer (without flags)
// Arduino Nano

#define SHIFT_DATA  2
#define SHIFT_CLK   3
#define SHIFT_LATCH 4
#define EEPROM_D0   5
#define EEPROM_D7   12
#define WRITE_EN    13

// control word
#define HLT 0b1000000000000000  // Halt clock
#define MI  0b0100000000000000  // Memory In
#define RI  0b0010000000000000  // Ram In
#define RO  0b0001000000000000  // Ram Out
#define IO  0b0000100000000000  // Instruction register Out
#define II  0b0000010000000000  // Instruction register In
#define AI  0b0000001000000000  // A register In
#define AO  0b0000000100000000  // A register Out
#define EO  0b0000000010000000  // ALU (Sum) Out
#define SU  0b0000000001000000  // Subtract
#define BI  0b0000000000100000  // B register In
#define OI  0b0000000000010000  // Output register In
#define CE  0b0000000000001000  // Counter Enable
#define CO  0b0000000000000100  // Counter Out
#define J   0b0000000000000010  // Jump

uint16_t data[] = {
  MI|CO, RO|II|CE, 0,       0,      0,        0, 0, 0,  // 0000 - NOP
  MI|CO, RO|II|CE, IO|MI,   RO|AI,  0,        0, 0, 0,  // 0001 - LDA
  MI|CO, RO|II|CE, IO|MI,   RO|BI,  EO|AI,    0, 0, 0,  // 0010 - ADD
  MI|CO, RO|II|CE, IO|MI,   RO|BI,  EO|AI|SU, 0, 0, 0,  // 0011 - SUB
  MI|CO, RO|II|CE, IO|MI,   AO|RI,  0,        0, 0, 0,  // 0100 - STA
  MI|CO, RO|II|CE, IO|AI,   0,      0,        0, 0, 0,  // 0101 - LDI
  MI|CO, RO|II|CE, IO|J ,   0,      0,        0, 0, 0,  // 0110 - JMP
  MI|CO, RO|II|CE, 0,       0,      0,        0, 0, 0,  // 0111
  MI|CO, RO|II|CE, 0,       0,      0,        0, 0, 0,  // 1000
  MI|CO, RO|II|CE, 0,       0,      0,        0, 0, 0,  // 1001
  MI|CO, RO|II|CE, 0,       0,      0,        0, 0, 0,  // 1010
  MI|CO, RO|II|CE, 0,       0,      0,        0, 0, 0,  // 1011
  MI|CO, RO|II|CE, 0,       0,      0,        0, 0, 0,  // 1100
  MI|CO, RO|II|CE, 0,       0,      0,        0, 0, 0,  // 1101
  MI|CO, RO|II|CE, AO|OI,   0,      0,        0, 0, 0,  // 1110 - OUT
  MI|CO, RO|II|CE, HLT,     0,      0,        0, 0, 0,  // 1111 - HLT
};

// output address bits and outputEnable signal using shift registers
void setAddress(int address, bool outputEnable) {
  // since com is 8-bit, we need to account for numbers that are larger than 8-bits
  shiftOut(SHIFT_DATA, SHIFT_CLK, MSBFIRST, (address >> 8) | (outputEnable ? 0x00 : 0x80));  // ">> 8" shifts all bits to the right by 8 places
  shiftOut(SHIFT_DATA, SHIFT_CLK, MSBFIRST, address);         // outputs the remainding bits that were shifted out on the line above

  digitalWrite(SHIFT_LATCH, LOW);
  digitalWrite(SHIFT_LATCH, HIGH);
  digitalWrite(SHIFT_LATCH, LOW);
}

// read a byte from EEPROM at specific address
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

// write a byte to EEPROM at specific address
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

// read and print all EEPROM addresses
void printContents() {
  Serial.println("\nReading EEPROM");
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

// just printing dots to show the program hasnt hung
void printDot(int value) {
  if(value % 64 == 0) {
    Serial.print(".");
  }
}

void setup() {
  pinMode(SHIFT_DATA, OUTPUT);
  pinMode(SHIFT_CLK, OUTPUT);
  pinMode(SHIFT_LATCH, OUTPUT);

  digitalWrite(WRITE_EN, HIGH);
  pinMode(WRITE_EN, OUTPUT);

  Serial.begin(115200);
  Serial.println("\n");


  // program the 8 high-order bits of microcode into the first 128 bytes of EEPROM
  Serial.print("\nProgramming EEPROM");
  for(int address = 0; address < sizeof(data)/sizeof(data[0]); address += 1) {
    writeEEPROM(address, data[address] >> 8);
    printDot(address);
  }

  // program the 8 low-order bits of microcode into the second 128 bytes of EEPROM
  for(int address = 0; address < sizeof(data)/sizeof(data[0]); address += 1) {
    writeEEPROM(address + 128, data[address]);
    printDot(address);
  }

  // read and print out contents of EEPROM
  printContents();
}

void loop() {

}
