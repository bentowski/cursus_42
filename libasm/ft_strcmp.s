global ft_strcmp

segment .text
  ft_strcmp:
    xor rdx, rdx
    xor rax, rax

  read:
    cmp BYTE [rdi + rdx], 0
    je exit
    mov al, BYTE [rsi + rdx]
    cmp BYTE [rdi + rdx], al
    jne exit
    inc rdx
    jmp read

  exit:
    movzx rax, BYTE [rdi + rcx]
    movzx rdx, BYTE [rsi + rcx]
    sub rax, rdx
    ret
