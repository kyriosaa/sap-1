; Displays Fibonacci sequence: 0, 1, 1, 2, 3, 5, 8, 13...
; Using decimal lookup table programmed by the Arduino

LDA #0      ; First Fibonacci number
OUT         ; Display 0
STA TEMP    ; Store in temporary location

LDA #1      ; Second Fibonacci number  
OUT         ; Display 1

LOOP:
ADD TEMP    ; Add previous number
OUT         ; Display result
STA TEMP2   ; Store new result
LDA TEMP    ; Load previous number
STA TEMP2   ; Shift values for next iteration
LDA TEMP2   ; Load new result
JMP LOOP    ; Continue sequence

TEMP: 0     ; Temporary storage
TEMP2: 0    ; Second temporary storage