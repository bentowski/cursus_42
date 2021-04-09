global ft_read

segment .text
  ft_read:
    xor rax, rax    ;initialisation rax for read (xor is better than mov)
    syscall         ; call the reading
    cmp rax, 0
    jl exit_error   ; if (rax != 0) -> error
    ret

  exit_error:
    mov rax, -1
    ret
