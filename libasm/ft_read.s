global ft_read

segment .text
  ft_read
    mov rax, 0
      syscall
    cmp rax, rsi
      jge exit_error
    cmp rax, 0
      jl exit_error
    ret

  exit_error
    mov rax, -1
    ret
