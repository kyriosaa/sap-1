; Adds until overflow, then subtracts until underflow - repeat

OUT     ; Output                        00: (0000   1110 0000)
ADD 15  ; Add using addr 15             01: (0001   0010 1111)
JC  4   ; If carry, jump to addr 4      02: (0010   0111 0100)
JMP 0   ; Jump to addr 0                03: (0011   0110 0000)
SUB 15  ; Subtract using addr 15        04: (0100   0011 1111)
OUT     ; Output                        05: (0101   1110 0000)
JZ  0   ; If zero, jump to addr 0       06: (0110   1000 0000)
JMP 4   ; Jump to addr 4                07: (0111   0110 0100)
        ;                               08: (1000            )
        ;                               09: (1001            )
        ;                               10: (1010            )
        ;                               11: (1011            )
        ;                               12: (1100            )
        ;                               13: (1101            )
        ;                               14: (1110            )
        ; Add/Sub number                15: (1111   0000 0000) INPUT