; Multiply any two numbers

LDA 14  ; Load addr 14                  00: (0000   0001 1110)
SUB 12  ; Sub using addr 12             01: (0001   0011 1100)
JC  6   ; If carry, jump to addr 6      02: (0010   0111 0110)
LDA 13  ; Load addr 13                  03: (0011   0001 1101)
OUT     ; Output                        04: (0100   1110 0000)
HLT     ; Halt                          05: (0101   1111 0000)
STA 14  ; Store in addr 14              06: (0110   0100 1110)
LDA 13  ; Load addr 13                  07: (0111   0001 1101)
ADD 15  ; Add using addr 15             08: (1000   0010 1111)
STA 13  ; Store in addr 13              09: (1001   0100 1101)
JMP 0   ; Jump to addr 0                10: (1010   0110 0000)
        ;                               11: (1011            )
        ; 1 (constant)                  12: (1100   0000 0001)
        ; product                       13: (1101   0000 0000)
        ; X                             14: (1110            ) input
        ; Y                             15: (1111            ) input