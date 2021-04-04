global _start

segment .data
 message db 'Hello World !', 10

segment .text
  _start:
    mov rax, 1
    mov rdi, 1
    mov rsi, message
    mov rdx, 13+1
    syscall

    mov rax, 60
    mov rdi, 0
    syscall


    segment .text
      global ft_write

      ft_write:
        mov r8, rdx
        mov rax, 0x2000004
        syscall
          jc exit_error
        jmp exit

      exit_error:
        mov rax, -1
        ret

      exit:
        mov rax, r8
        ret
