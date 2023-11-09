    .data
operando_1: .word 7
operando_2: .word 5
resultado:  .word 0

    .text
main:

    lw $t0,operando_1  # carga en el registro $t0 un 7 que es el contenido de la memoria en operando_1
    lw $t1,operando_2  # carga en el registro $t1 un 5 que es el contenido de la memoria en operando_2
    li $t3,9   # carga en el registro $t3 el valor inmediato 9

    # ejemplo de operacion de suma $t5 = $t0 + $t1
    add $t5,$t0,$t1
    sw $t5,resultado # almacena el registro $t5 en la memoria señalada por la etiqueta resultado 

    # HAZ PRUEBAS EN LAS SIGUIENTES LINEAS CON TODAS LAS INSTRUCCIONES ENTERAS QUE TE HEMOS DEJADO


    # estas dos lineas sirven para decir al sistema operativo que el programa ha terminado
    # los programas que hagas deben terminar con estas dos lineas
    li $v0,10
    syscall