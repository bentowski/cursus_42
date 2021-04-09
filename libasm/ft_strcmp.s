global ft_strcmp

segment .text
  ft_strcmp:
    xor rcx, rcx
    xor rax, rax

  read:
    mov al, BYTE [rsi + rcx]
    cmp BYTE [rdi + rcx], al
    jne exit
    inc rcx
    jmp read

  exit:
    movzx rax, BYTE [rdi + rcx]
    movzx rdx, BYTE [rsi + rcx]
    sub rax, rdx
    ret
