# Programa que convierte pesetas a euros
		.data
	msgentrada: .asciiz	"Introduzca el importe en pesetas: "
	msgsalida: .asciiz	"\nImporte en euros: "
	
		.text
main:
	la $a0, msgentrada
	li $v0,4
	syscall	# escribo el mensaje por pantalla
	
	li $v0,5
	syscall # leo un entero y lo deja en $v0
	
	mtc1 $v0,$f4 # realizo una copia cruda del entero en un registro flotante
	
	cvt.s.w $f6,$f4 # $f6 = convierto $f4 al formato flotante IEEE754
	li.s $f8,166.386 # Sf8 1 € en pesetas
	div.s $f10,$f6,$f8 # $f10 impote en €
	
	la $a0, msgsalida
	li $v0,4
	syscall #escribo el mensaje de salida por pantalla
	
	mov.s $f12,$f10 #
	li $v0,2
	syscall #escribo el flotante simple por pantalla
	
	li $v0,10
	syscall

