global ft_write

segment .text
  ft_write:            ; ft_wirte(rdi, rsi, rdx)
    mov r8, rdx        ; save len
    mov rax, 1         ; write
    syscall            ; execution
    cmp rax, 0
    jl exit_error      ; if (rax - 0 > 0)
    jmp exit           ; else

  exit_error:
    mov rax, -1
    ret

  exit:
    mov rax, r8
    ret
