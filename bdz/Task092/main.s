 .global _start

.data
mes:
    .ascii "equal\n"

        .text
_start:

        movq     $5, %rax
        cmp      $5, %rax
        jne N_EQ
        je EQ
                     

N_EQ:
        movq    $60, %rax
        syscall 

EQ:
        movq    $mes, %rsi
        movq    $1, %rdi
        movq    $6, %rdx
        movq    $1, %rax
        syscall

        movq    $60, %rax
        syscall 
        
