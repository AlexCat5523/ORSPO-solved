.section .text
.global _start

_start:
    # Кладём два числа на стек
    mov $10, %rax
    push %rax            
    mov $2, %rax
    push %rax           


    pop %rax
    # Читаем числа с помощью адресации, не меняем rsp
    mov (%rsp), %rbx      
    mov -8(%rsp), %rcx     

    # Вычитаем
    sub %rcx, %rbx        

    # Чистим стек
    add $8, %rsp         



    # Выход с кодом = rbx
    mov $60, %rax        
    mov %rbx, %rdi        
    syscall
    