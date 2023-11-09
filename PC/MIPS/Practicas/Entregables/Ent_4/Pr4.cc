#include <iostream>
#include <iomanip>

void print_vec(float* v, int n, std::string separador = " ") {
  for (int i = 0; i < n; i++) {
    std::cout << std::setprecision(8) << std::fixed << v[i] << separador;
  }
}

void change_elto(float* v, int n, float valor) {
  v[n] = valor;
}

// use recursividad de una funcion mirror que llame a la funcion swap para intercambiar los valores de los elementos
// de un vector de forma que el primero se intercambia con el ultimo, el segundo con el penultimo, etc.
void swap(float* v, int i, int j)
{
  float aux = v[i];
  v[i] = v[j];
  v[j] = aux;
}

void mirror(float* v, int n) {
  if (n == 0 || n == 1) {
    return;
  }
  swap(v, 0, n-1);
  mirror(v+1, n-2);
}

// Funcion llamada prod_esc de dos vectores llamando a la funcion mult_add
// para realizar la suma de los productos de los elementos de los vectores
float mult_add(float vec1, float vec2, float result) {
  return vec1 * vec2 + result;
}

float prod_esc(float* v1, float* v2, int n) {
  if (n == 0) {
    return 0;
  }
  // sin recursividad
  float result = 0;
  for (int i = 0; i < n; i++) {
    result = mult_add(v1[i], v2[i], result);

  }
  
  return result;
}

int main() {
  float v1[40], v2[40];
  int n1, n2;
  for (int i = 0; i < 40; i++) {
    v1[i] = i + 10;
    n1 = i + 1;

    v2[i] = 40 - i;
    n2 = i + 1;
  }

  int opcion;
  do {
    std::cout << "Vector con dimension " << n1 << std::endl;
    print_vec(v1, n1);
    std::cout << std::endl;
    std::cout << "Vector con dimension " << n2 << std::endl;
    print_vec(v2, n2);
    std::cout << std::endl;

    std::cout << "\n(1) Cambiar dimension de un vector\n(2) Cambiar un elemento de un vector\n"
              << "(3) Invertir un vector\n(4) Calcular el producto escalar de dos vectores\n"
              << "(0) Salir\n\nElija opcion: ";
    std::cin >> opcion;

    switch (opcion) {
      case 1: {
        int vector;
        int dimension;
        std::cout << "\nElija vector para realizar la operacion (1) para v1 (2) para v2: ";
        std::cin >> vector;
        std::cout << "Introduzca la nueva dimension: ";
        std::cin >> dimension;
        if (dimension <= 0 || dimension > 40) {
          std::cout << "\nError: Dimension incorrecta.\n" << std::endl;
          break;
        }

        if (vector == 1) {
          n1 = dimension;
        } else if (vector == 2) {
          n2 = dimension;
        } else {
          std::cout << "\nError: opcion incorrecta.\n" << std::endl;
        }
        break; 
      }
      case 2: {
        int vector;
        int posicion;
        float valor;
        std::cout << "\nElija vector para realizar la operacion (1) para v1 (2) para v2: ";
        std::cin >> vector;
        if (vector != 1 && vector != 2) {
          std::cout << "\nError: opcion incorrecta.\n" << std::endl;
          break;
        }

        std::cout << "Introduzca la posicion del elemento a cambiar: ";
        std::cin >> posicion;
        if (vector == 1 && (posicion < 0 || posicion >= n1)) {
          std::cout << "\nError: Indice incorrecto.\n" << std::endl;
          break;
        } else if (vector == 2 && (posicion < 0 || posicion >= n2)) {
          std::cout << "\nError: Indice incorrecto.\n" << std::endl;
          break;
        }

        std::cout << "Introduzca el nuevo valor: ";
        std::cin >> valor;

        if (vector == 1) {
          change_elto(v1, posicion-1, valor);
        } else {
          change_elto(v2, posicion-1, valor);
        }
        break; 
      }
      case 3: {
        int vector;
        std::cout << "\nElija vector para realizar la operacion (1) para v1 (2) para v2: ";
        std::cin >> vector;
        if (vector != 1 && vector != 2) {
          std::cout << "\nError: opcion incorrecta.\n" << std::endl;
          break;
        }

        if (vector == 1) {
          mirror(v1, n1);
        } else {
          mirror(v2, n2);
        }
        break; 
      }
      case 4: {
        if (n1 != n2) {
          std::cout << "\nError: Los vectores tienen distinta dimension.\n" << std::endl;
          break;
        }
        std::cout << "\nEl producto escalar de los vectores es: " << prod_esc(v1, v2, n1) << std::endl;
        break; }
      case 0: {
        std::cout << "\nFIN DEL PROGRAMA." << std::endl;
        return 0; }
      default:{
        std::cout << "\nError: opcion incorrecta.\n" << std::endl;
        break; }
    }
  } while (true);

  return 0;
}
