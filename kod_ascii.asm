.data
.bss
    .comm textout, 64
.text
.global kod_ascii
.type kod_ascii, @function


kod_ascii:
    push %rbp
    mov %rsp, %rbp

    # Parametry wywo�ania funkcji umieszczone zostan�
    # w rejestach RDI i RSI.
    # * W rejestrze RDI znajdzie sie wska�nik na pierwsz�
    # kom�rk� liczby.


        movq $10, %r10
        movq %rdi, %rax
        movq $0, %rdi
        to_stack:
            div %r10
            add $'0', %rdx
            push %rdx
            movq $0, %rdx
            inc %r8
            cmp $0, %rax
            jg to_stack

        movq $0, %rdi

        to_text:
            pop textout(, %%rdi, 1)
            inc %rdi
            cmp %r8, %rdi
            jl to_text

        mov $textout, %rax

        mov %rbp, %rsp
        pop %rbp
    ret # Powr�t do miejsca wywo�ania funkcji




