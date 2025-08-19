; Counts normally, but shows 255 when reaching threshold

OUT     ; Output                        00: (0000   1110 0000)
ADD 15  ; Add using addr 15             01: (0001   0010 1111)
STA 14  ; Store in addr 14              02: (0010   0100 1110)
SUB 13  ; Subtract threshold            03: (0011   0011 1101)
JZ  7   ; If zero, jump to addr 7       04: (0100   1000 0111)
LDA 14  ; Load counter storage          05: (0101   0001 1110)
JMP 0   ; Jump to addr 0                06: (0110   0110 0000)
LDI 12  ; Load alert value              07: (0111   0101 1100)
OUT     ; Output                        08: (1000   1110 0000)
HLT     ; Halt                          09: (1001   1111 0000)
        ;                               10: (1010            )
        ;                               11: (1011            )
        ; Alert value                   12: (1100   0000 0000) INPUT
        ; Threshold number              13: (1101   0000 0000) INPUT
        ; Counter storage               14: (1110   0000 0000)
        ; Increment number              15: (1111   0000 0000) INPUT