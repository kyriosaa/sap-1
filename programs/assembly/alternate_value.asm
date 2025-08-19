; Alternate displaying values X and Y

LDA 15  ; Load from addr 15             00: (0000   0001 1111)
OUT     ; Output                        01: (0001   1110 0000)
LDA 14  ; Load from addr 14             02: (0010   0001 1110)
OUT     ; Output                        03: (0011   1110 0000)
JMP 0   ; Jump to addr 0                04: (0100   0110 0000)
        ;                               05: (0101            )
        ;                               06: (0110            )
        ;                               07: (0111            )
        ;                               08: (1000            )
        ;                               09: (1001            )
        ;                               10: (1010            )
        ;                               11: (1011            )
        ;                               12: (1100            )
        ;                               13: (1101            )
        ; Y                             14: (1110   0000 0000) INPUT
        ; X                             15: (1111   0000 0000) INPUT