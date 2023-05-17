#include<iostream>
#include<cmath>

int main(void) {
  std::cout << "\n\nAproximación a sen(x) (-1 <= x <= 1) con un error máximo, usando Taylor\n";
  do {
    double x;
    do {
      std::cout << "\n\nIntroduzca el valor de x (-1 <= x <= 1): ";
      std::cin >> x;
    } while ( (x < -1) || (x > 1));
    double error;
    do {
      std::cout << "\nIntroduzca el error maximo permitido en la aproximación (0 < error < 1) (error <= 0 sale del programa): ";
      std::cin >> error;
    } while (error >= 1);
    if (error <= 0) break;
    int n = 0; // iteraciones
    double numerador = x; // primer numerador del termino para n=0
    int denominador = 1; // primer denominador del termino para n=0
    int signo = 1;
    double sen_x = x; // primer termino
    double xx = x*x; // el numerador siempre se multiplica por x^2 
    double error_calculado;
    do {
      double old_senx = sen_x;
      n++; // incremento el termino
      signo = -signo; // el signo se alterna
      numerador *= xx; 
      denominador = (2*n+1) * 2*n * denominador;
      double termino = signo * numerador / denominador; // ultimo termino
      sen_x += termino;
      error_calculado = fabs((sen_x - old_senx) / sen_x);
    } while (error_calculado >= error);
    std::cout << "\n\n\nsen(x) calculado: " << sen_x;
    std::cout << "\nerror calculado: " << error_calculado;
    std::cout << "\nnumero de iteraciones calculadas: " << n;
  } while (true);
  std::cout << "\nFin del programa\n";
return 0;
}