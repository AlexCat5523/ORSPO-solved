 .global _start

.data
mes_eq:
    .ascii "equal\n" 

mes_no_eq:
    .ascii "no equal\n"

.text
_start:

        movq     $0, %rbx
N_EQ:
        inc %rax
        cmp $5, %rax
        jne N_EQ


        movq $mes_eq, %rsi
        movq $1, %rdi
        movq $6, %rdx
        movq $1, %rax
        syscall


        mov     $60, %rax               
        mov     $0, %rdi                
        syscall                         
        

