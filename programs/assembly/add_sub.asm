; 3 numbers: Add first and second, then subtract with third

LDA 13  ; Load address 13                   (0000   0001 1101)
ADD 14  ; Add using address 14              (0001   0010 1110)
SUB 15  ; Subtract using address 15         (0010   0011 1111)
OUT     ; Output                            (0011   1110 0000)
HLT     ; Halt                              (0100   1111 0000)

; Also input numbers into address 13, 14, 15
; Address 13: ADD number
; Address 14: ADD number
; Address 15: SUB number