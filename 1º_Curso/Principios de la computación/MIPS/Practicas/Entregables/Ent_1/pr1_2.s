# Autor:Álvaro Pérez Ramos
# Correo electrónico: alu0101574042@ull.edu.es
# Fecha:9/03/2023
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
      li.d $f4, -1.0
      c.lt.d $f20, $f4
      bc1t _do2
      neg.d $f4, $f4   
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
#   ZONA DE CALCULO DEL POLINOMIO DE TAYLOR
#        int n = 0 = $f0; // iteraciones
    li.d $f0, 0.0
#        double numerador = x  = $f24; // primer numerador del termino para n=0
    mov.d $f24, $f20
#        int denominador = 1 = $f2; // primer denominador del termino para n=0
    li.d $f2, 1.0
#        int signo = 1 = $f4;
    li.d $f4, 1.0
#        double sen_x = x = $f26; // primer termino
    mov.d $f26, $f20
#        double xx = x*x = $f6; // el numerador siempre se multiplica por x^2
    mul.d $f20, $f20, $f20
#        do {
    _do4:
#            double old_senx = sen_x = $f28;
      mov.d $f28, $f26
#            n++; // incremento el termino $f0++
      li.d $f6, 1.0
      add.d $f0, $f0, $f6
#            signo = -signo =$f4; // el signo se alterna
      neg.d $f4, $f4
#            numerador *= xx = $f26;
      mul.d $f24, $f24, $f20
#            denominador = (2*n+1) * 2*n * denominador = $f2 = $f16;
      li.d $f8, 2.0
      mul.d $f8, $f8, $f0
      li.d $f10, 1.0
      mov.d $f14, $f8
      add.d $f8, $f8, $f10
      mul.d $f8, $f8, $f14
      mul.d $f2, $f2, $f8
#            double termino = signo * numerador / denominador; = $f16// ultimo termino
      div.d $f16, $f24, $f2
      mul.d $f16, $f16, $f4
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
    mov.d $f20, $f0
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
    li $v0, 3
    mov.d $f12, $f20
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