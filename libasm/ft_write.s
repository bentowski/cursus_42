global ft_write

segment .text
  ft_write:            ; ft_wirte(rdi, rsi, rdx)
    mov r8, rdx        ; save len
    mov rax, 1         ; write
    syscall            ; execution
      jc exit_error    ; if ()
    jmp exit

  exit_error:
    mov rax, -1
    ret

  exit:
    mov rax, r8
    ret
