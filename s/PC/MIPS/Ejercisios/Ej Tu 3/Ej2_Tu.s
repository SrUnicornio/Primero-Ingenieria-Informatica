  .data
numerador: .float 0.0
denominador: .float 0.0
msgnumerador: .asciiz "Ingrese el numerador: "
msgdenominador: .asciiz "Ingrese el denominador: "
msgresultado: .asciiz "El resultado es: "
msgerror: .asciiz "Error: Se ha producido una indeterminación o el resultado es ±infinito\n"
  .text
main: 
	l.s $f2, numerador # Carga el numerador en $f2
  l.s $f4, denominador # Carga el denominador en $f4

  div.s $f14, $f2, $f4 # valor nan
  li.s $f2, 1.0 
  div.s $f16, $f2, $f4 # valor inf

  pide_numerador:
    li $v0, 4
    la $a0, msgnumerador
    syscall

    li $v0, 6
    syscall  

    mov.s $f2, $f0 # Mueve el dato ingresado a $f2
    li.s $f0, 0.0
  fin_pide_numerador:

  pide_denominador:
    li $v0, 4
    la $a0, msgdenominador
    syscall

    li $v0, 6
    syscall

    mov.s $f4, $f0 # Mueve el dato ingresado a $f4
    li.s $f0, 0.0
  fin_pide_denominador:

  posibles_errores:
    c.eq.s $f4, $f0 # Si el denominador es 0.0
    bc1t salir

    abs.s $f6, $f2 # Calcula el valor absoluto del numerador
    c.eq.s $f2, $f16 # Si el numerador es inf
    bc1t salir

    abs.s $f8, $f4 # Calcula el valor absoluto del denominador
    c.eq.s $f6, $f16 # Si el denominador es inf
    bc1t salir

    c.eq.s $f2, $f14 # Si el numerador es nan
    bc1t salir

    c.eq.s $f4, $f14 # Si el denominador es nan
    bc1t salir

    salir:
      li $v0, 4
      la $a0, msgerror
      syscall

      li $v0, 10
      syscall
    fin_salir:
  fin_posibles_errores:

  muestra_resultado:
  div.s $f12, $f2, $f4 # Realiza la división y la guarda en $f12

  li $v0, 4 
  la $a0, msgresultado
  syscall

  li $v0, 2
  syscall
  fin_muestra_resultado:

  li $v0, 10
  syscall