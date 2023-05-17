  .data
PI: .float 3.1416
Radio: .word 0
msg: .asciiz "Ingrese el radio: "
msg2: .asciiz "El area del circulo es: "

    .text
main:
  lwc1 $f20, PI #carga el valor de PI en el registro $f20
  lw $s1, Radio #carga el valor de Radio en el registro $f22

  li $v0, 4
  la $a0, msg
  syscall
  li $v0, 5
  syscall

  mtc1 $v0, $f4 #carga el valor de Radio en el registro $f22
  cvt.s.w $f6, $f4 #convierte el valor de Radio a float

  mul.s $f22, $f6, $f6 #multiplica el valor de Radio por si mismo
  mul.s $f22, $f22, $f20 #multiplica el valor de Radio por PI

  li $v0, 4
  la $a0, msg2
  syscall
  li $v0, 2
  mov.s $f12, $f22
  syscall

  li $v0, 10
  syscall