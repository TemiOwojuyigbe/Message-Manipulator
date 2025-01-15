; caesar.asm
; Description: Assembly implementation of Caesar cipher for CMSC313 Project 4
; Authors: Temi and Grant

section .data
    ; Messages for user interaction
    current_msg db "Current message: ", 0
    current_msg_len equ $ - current_msg

    edited_msg db "Edited message: ", 0
    edited_msg_len equ $ - edited_msg

section .bss
    ; Buffers for input/output
    input_buffer resb 100              ; Reserved space for the input string
    shift_value resd 1                 ; Reserved space for the shift value
    output_buffer resb 100             ; Buffer for storing the encrypted message

section .text
    global encrypt_caesar              ; Function to be called from C

encrypt_caesar:
    ; Function inputs:
    ; rdi = pointer to input string (null-terminated)
    ; rsi = pointer to output string (pre-allocated buffer)
    ; edx = shift value (as integer)

    push rbx                           ; Preserve registers
    mov rbx, rdi                       ; Load input string pointer
    mov rdi, rsi                       ; Load output string pointer
    mov ecx, edx                       ; Load shift value into ecx

    ; Encryption loop
caesar_loop:
    mov al, byte [rbx]                 ; Load the current character
    cmp al, 0                          ; Check for null terminator
    je caesar_done                     ; Exit loop if end of string

    ; Check if the character is uppercase
    cmp al, 'A'
    jl copy_non_alpha                  ; If below 'A', copy as is
    cmp al, 'Z'
    jle uppercase_encrypt              ; If within range, encrypt as uppercase

    ; Check if the character is lowercase
    cmp al, 'a'
    jl copy_non_alpha                  ; If below 'a', copy as is
    cmp al, 'z'
    jle lowercase_encrypt              ; If within range, encrypt as lowercase

copy_non_alpha:
    ; Non-alphabetic characters are copied directly
    mov byte [rdi], al
    jmp next_char

uppercase_encrypt:
    ; Encrypt uppercase character
    sub al, 'A'                        ; Shift to 0-25 range
    add al, cl                         ; Apply the shift
    cmp al, 0
    jge wrap_upper                     ; No wrapping needed for positive
    add al, 26                         ; Wrap around for negative shift

wrap_upper:
    cmp al, 26
    jl store_uppercase
    sub al, 26                         ; Wrap around for overflow

store_uppercase:
    add al, 'A'                        ; Shift back to ASCII range
    jmp store_char

lowercase_encrypt:
    ; Encrypt lowercase character
    sub al, 'a'                        ; Shift to 0-25 range
    add al, cl                         ; Apply the shift
    cmp al, 0
    jge wrap_lower                     ; No wrapping needed for positive
    add al, 26                         ; Wrap around for negative shift

wrap_lower:
    cmp al, 26
    jl store_lowercase
    sub al, 26                         ; Wrap around for overflow

store_lowercase:
    add al, 'a'                        ; Shift back to ASCII range

store_char:
    mov byte [rdi], al                 ; Store encrypted character in output buffer

next_char:
    inc rbx                            ; Move to next character in input
    inc rdi                            ; Move to next position in output
    jmp caesar_loop

caesar_done:
    mov byte [rdi], 0                  ; Null-terminate the output string

    pop rbx                            ; Restore registers
    ret                                ; Return to caller
