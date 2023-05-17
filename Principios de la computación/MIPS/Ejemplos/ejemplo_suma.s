	.data 	# Seccion declaracion de datos
cadpet:	  .asciiz	"Introduza un entero: "
cadsuma:  .asciiz	"La suma es: ";
cadrc:    .asciiz	"\n";

	.text   # Seccion de codigo de usuario
main:
	
	# la funcion print_string es $v0=4
	li $v0,4		# $v0=4 funcion print string
	la $a0,cadpet   # $a0= direccion de la cadena a imprimir
	syscall
	# leo el primer entero y lo almaceno en $t0
	li $v0,5		# $v0=5 funcion leer un entero.
	syscall			# el entero leido se queda en $v0
	move $t0,$v0	# almaceno en $t0 el primer entero leido.
	# la funcion print_string es $v0=4
	li $v0,4		# $v0=4 funcion print string
	la $a0,cadpet	# $a0= direccion de la cadena a imprimir
	syscall
	# leo el segundo entero y lo almaceno en $t1
	li $v0,5		# $v0=5 funcion print string
	syscall			# el entero leido se queda en $v0
	move $t1,$v0	#almaceno en $t1 el segundo entero leido.
	
	add $t3,$t0,$t1 #almaceno en $t3 la suma de los dos enteros
	# la funcion print_int es $v0=1 y la funcion print_string es $v0=4
	li $v0,4		# $v0=4 funcion print_string
	la $a0,cadsuma  # $a0= direccion de la cadena a imprimir
	syscall
	li $v0,1		# $v0=4 funcion print_int
	move $a0,$t3	# $a0=entero a imprimir
	syscall
	li $v0,4		# $v0=4 funcion print string
	la $a0,cadrc	# $a0=direccion de la cadena a imprimir
	syscall
	# se hace una salida limpia del sistema (exit es codigo 10)
	li $v0,10
	syscall
# END

