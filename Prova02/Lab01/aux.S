.data

// char c = -20
    .globl  c
    .align  1
c:  .byte   -20

// int c = -256
    .globl  i
    .align  4
i:  .int    -256

// int j = 512
    .globl  j
    .align  4
j:  .int    512

// long l = 128
    .globl  l
    .align  8
l:  .quad   128

// unsigned short us = 111
    .globl  us
    .align  2
us: .short  111

// unsigned int = 1024
    .globl  ui
    .align  4
ui: .int    1024

// unsigned long = 2048
    .globl  ul
    .align  8
ul: .quad   2048

.text


.globl aux

aux:

    pushq %rbp

    movq  %rsp, %rbp

    # Se necessário, usar apenas os registradores (ou suas variações) abaixo:

    # %rax, %rcx, %rdx, %rdi, %rsi, %r8, %r9, %r10, %r11

    // j = 68000
    movl    $68000, j

    // l = 4096
    movq    $4096,  l

    // i = j
    movl    j,      %eax
    movl    %eax,   i
    
    // j = 10 + i - 5
    addl    $10,    %eax
    subl    $5,     %eax
    movl    %eax,   j

    // i = (i * 2) - (j + 5)
    movl    i,      %eax
    imull   $2,     %eax
    movl    j,      %ebx
    addl    $5,     %ebx
    subl    %ebx,   %eax
    movl    %eax,   i

    // ui = i
    movl    %eax,   ui



    leave

    ret