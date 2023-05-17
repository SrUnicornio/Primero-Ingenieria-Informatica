  .data
dividendo: .double 0.0
divisor: .double 2.0
constante: .double 0.00005
msgdividendo: .asciiz "Introduzca el dividendo: "
msgrespuesta: .asciiz "El numero de iteraciones ha sido: "
  .text

main: 
	l.d $f20, dividendo #carga el dividendo
  l.d $f22, divisor #carga el divisor
  l.d $f24, constante #carga la constante
  li $s2, 0 #contador de iteraciones

  li $v0, 4
  la $a0, msgdividendo
  syscall

  li $v0, 7
  syscall

  mov.d $f20, $f0
  li.d $f0, 0.0

  while:
    # $f24 <= $20
    c.lt.d $f20, $f24
    bc1t end_while

    div.d $f20, $f20, $f22
    addi $s2, $s2, 1
    j while

  end_while:

  li $v0, 4
  la $a0, msgrespuesta
  syscall

  li $v0, 1
  move $a0, $s2
  syscall

  li $v0, 10
  syscall