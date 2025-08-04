; Displays signed numbers using two's complement
; Using decimal lookup table programmed by the Arduino

LDA #-5     ; Load -5 (in two's complement)
OUT         ; Display "-5" using signed lookup table

LDA #127    ; Load positive 127
OUT         ; Display "127"

LDA #-128   ; Load -128 (most negative 8-bit number)
OUT         ; Display "-128"

HLT         ; Halt program