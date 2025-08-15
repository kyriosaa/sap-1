; 3 numbers: Add first and second, then subtract with third

LDA 15  ; Load address 15 into register A   (0000   0001 1111)
ADD 14  ; Add address 14 into register      (0001   0010 1110)
SUB 13  ; Subtract address 13 into register (0010   0011 1101)
OUT     ; Output                            (0011   1110 0000)
HLT     ; Halt                              (0100   1111 0000)

        ; Then put any number into address 15, 14, 13 (in this case i'll do 7, 6, 5)
7       ; 7 into address 15                 (1101   0000 0111)
6       ; 6 into address 14                 (1110   0000 0110)
5       ; 5 into address 13                 (1111   0000 0101)