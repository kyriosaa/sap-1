; Displays powers of 2

LDI 1   ; Load immediate 1      (0000   0101 0001)
OUT     ; Output                (0001   1110 0000)
STA 15  ; Store number          (0010   0100 1111)
ADD 15  ; Add value to itself   (0011   0010 1111)
OUT     ; Output                (0100   1110 0000)
STA 15  ; Store sum             (0101   0100 1111)
JMP 3   ; Jump to address 3     (0110   0110 0011)

; Address 15: current power of 2