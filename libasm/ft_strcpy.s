global ft_strcpy

segment .text
  ft_strcpy:
    xor rdx, rdx    ; initializing rdx for counting with

  cpy:
    mov al, BYTE [rsi + rdx]   ;al is tmp, place in a part of rsi (second arg, src)
    mov BYTE [rdi + rdx], al   ; place in the 'same part' al in rdi (first arg, dst)
    inc rdx                    ; rdx++
    cmp al, 0
    jne cpy                    ; if al != 0, carry on
    mov rax, rdi               ; else place rdi in rax for the return
    ret
