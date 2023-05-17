    .data    # segmento de datos del programa

v_inicio:           .word   1  
v_fin:              .word   11
acumulado:          .word   0

num_real:           .float  3.1416   # codificado en IEEE754 para 32 bits es 0x40490FF9
num_double:         .double 123456.763 # codificado en IEEE754 para 64 bits es 0x40FE240C 353F7CEE
                    # tienes una calculadora online de IEEE754 en https://babbage.cs.qc.cuny.edu/IEEE-754.old/Decimal.html

cadena:             .asciiz "Valor acumulado: "

    .text
main:

    lw $t0,v_inicio     # carga en el registro $t0 el dato de la memoria que está en v_inicio
    lw $t1,v_fin        # carga en el registro $t1 el dato de la memoria que está en v_fin
    lw $t2,acumulado    # carga en el registro $t2 el dato de la memoria que está en acumulado

    # en el siguiente bucle se van acumulando en $t2 los numeros entre v_inicio y v_fin
    bucle:  bgt $t0,$t1,fin_bucle
            add $t2,$t2,$t0
            addi $t0,1
            b bucle

    fin_bucle:

    # almaceno en la zona de memoria etiquetada como acumulado el valor actualizado del registro $t2
    sw $t2,acumulado

    # Las siguientes 6 lineas son el equivalen a hacer un printf("Valor acumulado %d",acumulado)
    la $a0,cadena
    li $v0,4
    syscall
    lw $a0,acumulado
    li $v0,1
    syscall

    # las siguientes dos instrucciones no tienen ningun efecto en el programa simplemente se
    # cargan los flotantes en registros para mostrar el banco de registros de punto flotante
    l.s $f16,num_real   # carga en el registro f16 el flotante simple precision num_real
    l.d $f18,num_double # carga en el registro (f18-f19) el flotante doble precision num_double
    
    # las siguientes dos instrucciones terminan el programa y devuelven el control al S.O.
    li $v0,10
    syscall
