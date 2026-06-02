.section .text
.global _start

_start:
    movq $60, %rax
    movq $42, %rdi
    syscall                   