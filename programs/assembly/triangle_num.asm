; Displays triangle numbers (1+2=3, 1+2+3=6, etc)

LDI 1   ; Load immediate 1          (0000   0101 0001)
OUT     ; Output                    (0001   1110 0000)
STA 14  ; Store sum                 (0010   0100 1110)
STA 15  ; Store increment           (0011   0100 1111)
LDA 15  ; Load increment            (0100   0001 1111)
ADD 13  ; Add 1                     (0101   0010 1101)
STA 15  ; Store new increment       (0110   0100 1111)
ADD 14  ; Add to running sum        (0111   0010 1110)
OUT     ; Output                    (1000   1110 0000)
STA 14  ; Store new sum             (1001   0100 1110)
JMP 4   ; Jump to address 4         (1010   0110 0100)

; Address 13: 1 (constant)
; Address 14: running sum
; Address 15: current increment