; Simple decimal counter (1, 2, 3, ...) for 7-seg display
; Using decimal lookup table programmed by the Arduino

LDA #0      ; Load 0 into accumulator
LOOP:
OUT         ; Display current value (uses EEPROM lookup table)
ADD #1      ; Add 1 to accumulator  
JMP LOOP    ; Jump back to display next number
HLT         ; Halt (never reached)