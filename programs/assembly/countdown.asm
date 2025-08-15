; Counts down from 10 to 0

LDI 10  ; Load immediate 10     (0000   0101 1010)
OUT     ; Output                (0001   1110 0000)
SUB 15  ; Subtract 1            (0010   0011 1111)
OUT     ; Output                (0011   1110 0000)
STA 14  ; Store result          (0100   0100 1110)
LDA 14  ; Load result           (0101   0001 1110)
JMP 2   ; Jump to address 2     (0110   0110 0010)

; Address 14: current number
; Address 15: 1 (constant)