; Displays multiples of 3

LDI 3   ; Load immediate 3      (0000   0101 0011)
STA 15  ; Store A 15            (0001   0100 1111)
LDI 0   ; Load immediate 0      (0010   0101 0000)
ADD 15  ; Add 15 to register    (0011   0010 1111)
OUT     ; Output                (0100   1110 0000)
JMP 3   ; Jump to address 3     (0101   0110 0011)