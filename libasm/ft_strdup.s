global ft_strdup
extern ft_strlen
extern ft_strcpy
extern malloc

segment .text
  ft_strdup:
    push rdi          ;save rdi (=str)
    call ft_strlen    ;get len (in rax)
    mov rdi, rax      ;rdi <- len
    inc rdi           ;add \0
    call malloc       ;malloc rax by sizeof(rdi)
    pop rsi           ;pull str to rsi
    mov rdi, rax      ;pull rax size in rdi
    call ft_strcpy
    ret
