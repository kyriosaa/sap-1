# SAP-1 8-bit Breadboard Computer

[![Assembly](https://img.shields.io/badge/Assembly-525252?style=flat&logo=assemblyscript&logoColor=white)](https://en.wikipedia.org/wiki/Assembly_language)
[![C++](https://img.shields.io/badge/C%2B%2B-00599C?style=flat&logo=c%2B%2B&logoColor=white)](https://isocpp.org/)
[![Arduino](https://img.shields.io/badge/Arduino-00979D?style=flat&logo=arduino&logoColor=white)](https://www.arduino.cc/)
[![Electronics](https://img.shields.io/badge/Electronics-008C4A?style=flat&logo=data:image/svg+xml;base64,PHN2ZyB4bWxucz0iaHR0cDovL3d3dy53My5vcmcvMjAwMC9zdmciIHZpZXdCb3g9IjAgMCAyNCAyNCIgZmlsbD0ibm9uZSIgc3Ryb2tlPSIjZmZmZmZmIiBzdHJva2UtbGluZWNhcD0icm91bmQiIHN0cm9rZS1saW5lam9pbj0icm91bmQiIGlkPSJDaXJjdWl0LUJvYXJkLS1TdHJlYW1saW5lLUx1Y2lkZSIgaGVpZ2h0PSIyNCIgd2lkdGg9IjI0Ij4KICA8ZGVzYz4KICAgIENpcmN1aXQgQm9hcmQgU3RyZWFtbGluZSBJY29uOiBodHRwczovL3N0cmVhbWxpbmVocS5jb20KICA8L2Rlc2M+CiAgPHBhdGggZD0iTTUgM2gxNHMyIDAgMiAydjE0czAgMiAtMiAySDVzLTIgMCAtMiAtMlY1czAgLTIgMiAtMiIgc3Ryb2tlLXdpZHRoPSIyIj48L3BhdGg+CiAgPHBhdGggZD0iTTExIDloNGEyIDIgMCAwIDAgMiAtMlYzIiBzdHJva2Utd2lkdGg9IjIiPjwvcGF0aD4KICA8cGF0aCBkPSJNNyA5YTIgMiAwIDEgMCA0IDAgMiAyIDAgMSAwIC00IDAiIHN0cm9rZS13aWR0aD0iMiI+PC9wYXRoPgogIDxwYXRoIGQ9Ik03IDIxdi00YTIgMiAwIDAgMSAyIC0yaDQiIHN0cm9rZS13aWR0aD0iMiI+PC9wYXRoPgogIDxwYXRoIGQ9Ik0xMyAxNWEyIDIgMCAxIDAgNCAwIDIgMiAwIDEgMCAtNCAwIiBzdHJva2Utd2lkdGg9IjIiPjwvcGF0aD4KPC9zdmc+&logoColor=white)]()

SAP-1 (Simple As Possible - 1) is a fully functional 8-bit computer built entirely from scratch using basic logic chips and breadboards. My version is based on Ben Eater's design with power distribution changes along with IC placement and wiring differences.

The computer works without any code and can be manually programmed by using DIP switches and Arduino code is used to program EEPROM lookup tables so numbers can be displayed properly. More complex programs such as multiplication or sequencing are written in Assembly and manually entered via DIP switches.

## Core Components

**CPU Architecture**
- **A Register (Accumulator) -** The main register that stores data for math operations
- **B Register -** The secondary register to hold the second operand for ALU operations
- **Arithmetic Logic Unit (ALU) -** Does the addition and subtraction
- **Instruction Register -** Stores the current instruction being executed
- **Program Counter -** Keeps track of which instruction to execute next

**Memory & I/O**
- **16-byte RAM -** Stores both the program instructions and data
- **4-bit address -** Can access 16 memory locations (can store either instructions or data)
- **7-segment display -** Decimal display for output
- **Control switches -** Includes DIP switches and buttons for manual programming

## Instruction Set

I've programmed a complete instruction set in the [CPU microcode](./programs/sap1_cpu_microcode/sap1_cpu_microcode.ino)
- **NOP -** No operation
- **LDA -** Load from memory to A register
- **ADD -** Add memory to A register
- **SUB -** Subtract memory from A register
- **STA -** Store A register to memory
- **LDI -** Load immediate value to A register
- **JMP -** Jump to address
- **OUT -** Output A register to display
- **HLT -** Halt computer

## Operation Cycle

1. **Fetch -** The program counter addresses memory, then instruction is loaded into the instruction register
2. **Decode -** Control logic interprets the opcode to figure out which operation to perform
3. **Execute -** The control signals are activated to do the instruction
4. **Increment -** If there's no jump, the program counter advances to the next instruction

## Programming

**SAP-1 Programs**
- Programs (like multiplication, Fibonacci sequence, etc.) are written in Assembly and manually entered via DIP switches into the RAM

**Display Setup**
- [Arduino EEPROM programmers](./programs/sap1_decimal_counter_programmer/sap1_decimal_counter_programmer.ino) are used to prepare lookup tables for decoding the 7-segment display

**Example Programs**
- I put the [Assembly examples](./programs/assembly/) in the Assembly folder

<!-- 🎥 [Watch the demo video](LINK) 🎥 -->

## This project is not finished yet, but here are some WIP images

<img src='/images/sap-1.jpg'>
<img src='./images/clock.jpeg'>
<img src='./images/alu.jpeg'>
<img src='./images/instruction_reg.jpeg'>