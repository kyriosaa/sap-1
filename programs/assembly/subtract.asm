; Subtracts two numbers

LDA 15  ; Load addr 15              00: (0000   0001 1111)
SUB 14  ; Subtract using addr 14    01: (0001   0011 1110)
OUT     ; Output                    02: (0010   1110 0000)
HLT     ; Halt                      03: (0011   1111 0000)
        ;                           04: (0100            )
        ;                           05: (0101            )
        ;                           06: (0110            )
        ;                           07: (0111            )
        ;                           08: (1000            )
        ;                           09: (1001            )
        ;                           10: (1010            )
        ;                           11: (1011            )
        ;                           12: (1100            )
        ;                           13: (1101            )
        ; 2nd sub number            14: (1110   0000 0000) INPUT
        ; 1st sub number            15: (1111   0000 0000) INPUT