global ft_strlen

segment .text
  ft_strlen:
    push rdx        ; take in the rdx register
    mov rdx, 0      ; initialiation 'cause rdx is for compting here

  cpy:
    mov al, BYTE [rdi + rdx]   ;this 3lines check if BYTE read is end of str
    inc rdx
    cmp al, 0
    jne cpy                     ; if isn't end of str, carry on
    mov rax, rdx                ; if is end of str, ret len (rdx - 1) in rax
    dec rax
    pop rdx                     ; "free" rdx
    ret
