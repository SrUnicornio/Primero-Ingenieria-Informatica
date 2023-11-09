# Autor: 
# Correo electrónico: 
# Fecha: 9/03/2023
  .data
titulo: .asciiz "\n\nAproximación a sen(x) (-1 <= x <= 1) con un error máximo, usando Taylor\n"
petx:   .asciiz "\n\nIntroduzca el valor de x (-1 <= x <= 1): "
pete:   .asciiz "\nIntroduzca el error maximo permitido en la aproximación (0 < error < 1) (error <= 0 sale del programa): "
cadsen: .asciiz "\n\n\nsen(x) calculado: "
caderr: .asciiz "\nerror calculado: "
cadite: .asciiz "\nnumero de iteraciones calculadas: "
cadfin: .asciiz "\nFin del programa\n"
##include<iostream>
##include<cmath>
  .text
main:
#int main(void) {
#    std::cout << "\n\nAproximación a sen(x) (-1 <= x <= 1) con un error máximo, usando Taylor\n";
  li $v0, 4
  la $a0, titulo
  syscall
#    do {
  _do:
#     double x = $f20;
  li.d $f20, 0.0
#        do {
    _do2:
#        std::cout << "\n\nIntroduzca el valor de x (-1 <= x <= 1): ";
      li $v0, 4
      la $a0, petx
      syscall
  #        std::cin >> x;
      li $v0, 7
      syscall
      mov.d $f20, $f0
  #        } while ( (x < -1) || (x > 1));
      li.d $f4,1.0
      li.d $f6,-1.0
      c.lt.d $f20, $f6
      bc1t _do2
      c.le.d $f20, $f4
      bc1t _fin_do2
      j _do2
    _fin_do2:
#        double error = $f22;
    li.d $f22, 0.0
#        do {
    _do3:
#            std::cout << "\nIntroduzca el error maximo permitido en la aproximación (0 < error < 1) (error <= 0 sale del programa): ";
      li $v0, 4
      la $a0, pete
      syscall
#            std::cin >> error;
      li $v0, 7
      syscall
      mov.d $f22, $f0
#        } while (error >= 1);
      li.d $f4,1.0
      c.lt.d $f22, $f4
      bc1t _fin_do3
      j _do3
    _fin_do3:
#        if (error <= 0) break;
    li.d $f0, 0.0
    c.le.d $f22, $f0
    bc1t _fin_do
#-------------------------------------------------------------------------------------------------------------------
#        int n = 0 = $s0; // iteraciones
    li $s0, 0
#        double numerador = x  = $f24; // primer numerador del termino para n=0
    mov.d $f24, $f20
#        int denominador = 1 = $s1; // primer denominador del termino para n=0
    li $s1, 1
#        int signo = 1 = $s2;
    li $s2, 1
#        double sen_x = x = $f26; // primer termino
    mov.d $f26, $f20
#        double xx = x*x = $f6; // el numerador siempre se multiplica por x^2
    mul.d $f20, $f20, $f20
#        do {
    _do4:
#            double old_senx = sen_x = $f28;
      mov.d $f28, $f26
#            n++; // incremento el termino $s0++
      addi $s0, $s0, 1
#            signo = -signo =$s2; // el signo se alterna
      neg $s2, $s2
#            numerador *= xx = $f26;
      mul.d $f24, $f24, $f20
#            denominador = (2*n+1) * 2*n * denominador = $s1 = $f16;
      li $t0, 2
      mul $t1, $s0, $t0 # 2*n
      addi $t1, $t1, 1 # 2*n+1
      mul $t2, $s0, $t0 # 2*n
      mul $t3, $t1, $t2 # (2*n+1) * 2*n
      mul $s1, $s1, $t3 # (2*n+1) * 2*n * denominador
      mtc1 $s1, $f16
      cvt.d.w $f16, $f16
#            double termino = signo * numerador / denominador; = $f16// ultimo termino
      div.d $f16, $f24, $f16
      mtc1 $s2, $f18
      cvt.d.w $f18, $f18
      mul.d $f16, $f16, $f18
#---------------------------------------------------------------------------------
#            sen_x += termino;
      add.d $f26, $f26, $f16
#            error_calculado = fabs((sen_x - old_senx) / sen_x);
      sub.d $f28, $f26, $f28
      div.d $f28, $f28, $f26
      abs.d $f28, $f28
#        } while (error_calculado >= error);
      c.lt.d $f28, $f22
      bc1t _fin_do4
      j _do4
    _fin_do4:
#        std::cout << "\n\n\nsen(x) calculado: " << sen_x;
    li $v0, 4
    la $a0, cadsen
    syscall
    li $v0, 3
    mov.d $f12, $f26
    syscall
#        std::cout << "\nerror calculado: " << error_calculado;   
    li $v0, 4
    la $a0, caderr
    syscall
    li $v0, 3
    mov.d $f12, $f28
    syscall
#        std::cout << "\nnumero de iteraciones calculadas: " << n;
    li $v0, 4
    la $a0, cadite
    syscall
    li $v0, 1
    move $a0, $s0
    syscall
#    } while (true);
    j _do
  _fin_do:
#    std::cout << "\nFin del programa\n";
  li $v0, 4
  la $a0, cadfin
  syscall
#    return 0;
#}
  li $v0,10
  syscall
