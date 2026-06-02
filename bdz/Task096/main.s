.section .text
.global _start

func:
    push %rbp
    mov %rsp, %rbp

    mov 16(%rbp), %rax     
    mov 24(%rbp), %rbx     
    add %rbx, %rax         

    mov 32(%rbp), %rcx
    add %rcx, %rax

    pop %rbp
    ret

_start:
    mov $3, %rax
    push %rax
    mov $7, %rax
    push %rax              
    mov $5, %rax
    push %rax  

    call func
    
    mov %rax, %rbx

    add $24, %rsp           
    mov $60, %rax
    mov %rbx, %rdi
    syscall