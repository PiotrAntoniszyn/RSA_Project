.data
.bss
    .comm textout, 64
.text
.global kod_ascii
.type kod_ascii, @function


kod_ascii:
    push %rbp
    mov %rsp, %rbp

    # Parametry wywo³ania funkcji umieszczone zostan¹
    # w rejestach RDI i RSI.
    # * W rejestrze RDI znajdzie sie wskaŸnik na pierwsz¹
    # komórkê liczby.


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
    ret # Powrót do miejsca wywo³ania funkcji




