   .data
numero_1: .word 1 #declara la variable numero_1 y le asigna el valor 4
numero_2: .word 5 

    .text
main:
    lw $t0, numero_1 #carga el valor de numero_1 en el registro $t0
    lw $t1, numero_2 #carga el valor de numero_2 en el registro $t1
    j if #salta a la etiqueta if

    if:
        bgt $t0, $t1, else #si el valor de $t0 es mayor que el de $t1, salta a la etiqueta else
        move $t3, $t0 #mueve el valor de $t0 a $t3
        move $t4, $t1 #mueve el valor de $t1 a $t4
        j fin #salta a la etiqueta fin

    else:
        move $t3, $t1 #mueve el valor de $t1 a $t3
        move $t4, $t0 #mueve el valor de $t0 a $t4

    fin:

    #suma los valores de $t3 y $t4 ambos incluidos y los guarda en $t5
    move $t2, $t3
    for:
        bgt $t2, $t4, fin_for #si el valor de $t3 es mayor que el de $t4, salta a la etiqueta fin_for
        add $t5, $t5, $t2 #suma el valor de $t5 y $t2 y lo guarda en $t5
        addi $t2, $t2 1 #incrementa el valor de $t3 en 1
        b for #si el valor de $t3 es distinto al de $t4, salta a la etiqueta for
    fin_for:
    li $v0, 1
    syscall