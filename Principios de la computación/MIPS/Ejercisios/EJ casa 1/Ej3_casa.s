    .data
numero_1: .word 1
numero_2: .word 2
numero_3: .word 3

    .text
main:
    lw $t1, numero_1 #carga el valor de numero_1 en el registro $t1
    lw $t2, numero_2 #carga el valor de numero_2 en el registro $t2
    lw $t3, numero_3 #carga el valor de numero_3 en el registro $t3
    
    if:
        #($t1 < $t2) && ($t2 >= $t3)||(($t2 - $t3) == $t1)

        sub $t6, $t2, $t3 #se resta $t2 - $t3 y se carga el resultado en $t7
        seq $t5, $t6, $t1 #si $t7 es igual a $t1, se carga 1 en $t5, sino 0
        j fin_if #se salta a fin_if

        slt $t4, $t1, $t2 #si $t1 es menor que $t2, se carga 1 en $t4, sino 0
        sge $t5, $t2, $t3 #si $t2 es mayor o igual que $t3, se carga 1 en $t5, sino 0
        and $t5, $t4, $t5 #si $t4 y $t5 son 1, se carga 1 en $t6, sino 0
    fin_if: