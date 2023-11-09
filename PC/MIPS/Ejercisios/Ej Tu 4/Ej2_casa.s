  .data
nuemero_1: .word 20
nuemero_2: .word 2
resultado: .word 0
  .text
main: 
	# if(($t1 => 0)and ($t2 => 0)) {
	#   for(int i = 1, i <= $t1, i++) {
	#       if (i % t2 == 0){
	#           resultado ++;
	#       }
	#   }
	# }
	lw $t1, nuemero_1 # carga el valor de la variable numero_1 en el registro $t1
	lw $t2, nuemero_2 # carga el valor de la variable numero_2 en el registro $t2
	lw $t3, resultado # carga el valor de la variable resultado en el registro $t3
	
	move $t0, $zero #inicializa el contador en 0

	if:
		sge $t4, $t1, $zero # guarda 1 si es mayor o igual a 0
		sge $t5, $t2, $zero # guarda 1 si es mayor o igual a 0
		and $t6, $t4, $t5 # guarda 1 si ambos son mayores o iguales a 0
		beqz $t6, fin_if # si no es 0, salta a la etiqueta fin_if
		
		for:
			bge $t0, $t1, fin_for # si el contador es mayor que el numero_1, salta a la etiqueta fin_for
			
			div $t0, $t2 # divide el contador entre el numero_2
			mfhi $t7 # guarda el resto en el registro $t7
			
			bnez $t7, no_sumar # si el resto es diferente de 0, salta a la etiqueta no_sumar
			add $t3, $t3, 1 # incrementa el resultado en 1
			no_sumar:
			addi $t0, $t0, 1 # incrementa el contador en 1
			
			j for # salta a la etiqueta for
		fin_for:
	fin_if:

	li $v0, 10
	syscall