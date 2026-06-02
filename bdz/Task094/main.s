.section .text
.global _start

_start:
    mov $42, %rax        
    push $1
    push $2
    push $3
    push $4
    push $5
    push $6
    push $7
    push $8
    push $9
    push $10

    pop %r10             
    pop %r9             
    pop %r8             
    pop %rdi             
    pop %rsi            
    pop %rdx             
    pop %rcx            
    pop %rbx             
    pop %rax             
    pop %rbp             

    mov $60, %rax       
    mov %rbx, %rdi        
    syscall              

