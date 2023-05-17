#Enunciado: Realiza un programa en ensamblador MIPS que evalúe un polinomio de segundo grado de la forma
#f(x) = a x^3 + b x^2 + c x + d en un rango de valores enteros [r,s] y devuelva aquellos valores que son mayores de 2.1
#El programa debe pedir por consola:
#- tres números flotantes en simple: a, b, c y d
#- dos números enteros r y s comprobando que r <= s

  .data
msgenun:    .asciiz "Evaluacion de un polinomio f(x) = a x^3 + b x^2 + c x + d en un rango [r, s] \n"
msgpid:     .asciiz "\nIntroduzca los valores de a, b, c y d (separado por ENTER): \n"
msgpid2:    .asciiz "Introduzca [r, s] (r y s enteros, r <=s) (sepaarados por ENTER) \n"
msgret:     .asciiz "\nf("
msgret2:    .asciiz ")= "
msgfin:     .asciiz "\n\nTermina el prorama \n"

  .text
main:
  #enta de del enunciado
  li $v0, 4
  la $a0, msgenun
  syscall
  #peticion de a b c y d 
  li $v0, 4 
  la $a0, msgpid
  syscall
  # Peticion de a  = $f20
  li $v0, 6
  syscall
  mov.s $f20, $f0
  # Peticion de b = $f21
  li $v0, 6
  syscall
  mov.s $f21, $f0
  # Peticion de c = $f22
  li $v0, 6
  syscall
  mov.s $f22, $f0
  # Peticion de d = $f23
  li $v0, 6
  syscall
  mov.s $f23, $f0
  
  while:
    # peticion de r y s
    li $v0, 4
    la $a0, msgpid2
    syscall
    # Peticion de r = $s1
    li $v0, 5
    syscall
    move $s0, $v0
    # Peticion de s = $s2 -> $f25
    li $v0, 5
    syscall
    move $s1, $v0
    bgt $s0, $s1, while
  fin_while:
  #for (x=r; x <= s; ++x)
  move $s2, $s0 # x=r
  #convercion de x a flotantes
  mtc1 $s2, $f0
  cvt.s.w $f24, $f0 
  #conversion de s a flotantes
  mtc1 $s1, $f0
  cvt.s.w $f25, $f0
  for:
    c.le.s $f24, $f25
    bc1f fin_for
    # f = a*x^3 + b*x^2 + c*x + d
    mul.s $f5, $f24, $f24
    mul.s $f5, $f5, $f24 
    mul.s $f26, $f20, $f5 #a*x^3 
    mul.s $f6, $f24, $f24
    mul.s $f27, $f21, $f6 #b*x^2
    mul.s $f28, $f22, $f24 # c*x
    add.s $f7, $f26, $f27 # a*x^3 + b*x^2
    add.s $f8, $f28, $f23 # c+x + d
    add.s $f12, $f7, $f8
    li.s $f0, 2.1
    if:
      c.lt.s $f12, $f0
      bc1t fin_if
      # Mensaje con resultado
      li $v0, 4
      la $a0, msgret
      syscall
      
      move $a0, $s0
      li $v0, 1
      syscall
      
      li $v0, 4
      la $a0, msgret2
      syscall

      li $v0,2
      syscall
    fin_if:
    li.s $f0, 1.0
    add.s $f24, $f24, $f0
    addi $s0, $s0, 1
    j for
    fin_for:
  # Mensaje fin programa
  li $v0, 4
  la $a0, msgfin
  syscall
  
  li $v0, 10
  syscall
