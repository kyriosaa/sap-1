; 3 numbers: Add first and second, then subtract with third

LDA 13  ; Load addr 13                      00: (0000   0001 1101)
ADD 14  ; Add using addr 14                 01: (0001   0010 1110)
SUB 15  ; Subtract using addr 15            02: (0010   0011 1111)
OUT     ; Output                            03: (0011   1110 0000)
HLT     ; Halt                              04: (0100   1111 0000)
        ;                                   05: (0101            )
        ;                                   06: (0110            )
        ;                                   07: (0111            )
        ;                                   08: (1000            )
        ;                                   09: (1001            )
        ;                                   10: (1010            )
        ;                                   11: (1011            )
        ;                                   12: (1100            )
        ; Add number                        13: (1101   0000 0000) INPUT 
        ; Add number                        14: (1110   0000 0000) INPUT
        ; Subtract number                   15: (1111   0000 0000) INPUT