#include <iostream>
#include <cmath>

// En C++ para poder utilizar el indexado de una matriz (bidimensional)
// mediante dos pares de corchetes el número de filas y columnas no pude cambiar,
// debe ser constante y conocido desde el principio.
//
// En esta práctica queremos cambiar el número de filas y columnas de la matriz
// considerada.
// Para poder emular en C++ lo que podemos hacer en ensamblador
// vamos a manejar la matriz como un vector.
// Para acceder al elenemto en la fila de índice `f` y columna de índice `c`
// no podemos hacer `mat[f][c]` sino que debemos hacer `mat[f*ncol+c]`

// Hecho
void EscribirMatriz(int nfil, int ncol, int *mat){
    std::cout << "\nLa matriz es " << nfil << "x" << ncol << "\n";
  for ( int f = 0; f < nfil; f++) {
    for (int c = 0; c < ncol; c++ ) {
      std::cout << mat[f*ncol+c] << "  "; // equivalente a acceso `mat[f][c]`
    }
    std::cout << "\n";
  }
}

void IntercambiarElementos(int nfil, int ncol, int *mat, int f1, int c1, int f2, int c2){
  int aux = mat[f1*ncol+c1];
  mat[f1*ncol+c1] = mat[f2*ncol+c2];
  mat[f2*ncol+c2] = aux;
  EscribirMatriz(nfil, ncol, mat);
}

//Hecho
int SumaPerimetro(int nfil, int ncol, int *mat){
  int suma = 0;
  for ( int f = 0; f < nfil; f++) {
    for (int c = 0; c < ncol; c++ ) {
      if (f == 0 || f == nfil-1 || c == 0 || c == ncol-1) {
        suma += mat[f*ncol+c];
      }
    }
  }
  return suma;
}

void MaxMinDiagonal(int nfil, int ncol, int *mat){
  int max = mat[0];
  int min = mat[0];
  int valor = nfil;

  if (nfil > ncol) {
    valor = ncol;
  } else {
    valor = nfil;
  }
  for (int i = 0; i < valor; i++) {
    if (mat[i*ncol+i] > max) {
      max = mat[i*ncol+i];
    }
    if (mat[i*ncol+i] < min) {
      min = mat[i*ncol+i];
    }
  }

std::cout << "El maximo de la diagonal es: " << max << " y el minimo es: " << min << std::endl;
}

void SumaDoble(int nfil, int ncol, int *mat){
  int suma1 = 0;
  int suma2 = 0;
  for ( int f = 0; f < nfil; f++) {
    for (int c = 0; c < ncol; c++ ) {
      if (f == 0) {
        suma1 += mat[f*ncol+c];
      }
      if (f == nfil-1) {
        suma2 += mat[f*ncol+c];
      }
    }
  }
  if (suma1 > suma2){
    std::cout << "La suma de la primera fila es mayor que la de la ultima" << suma1 << " >  " << suma2 << std::endl;
  } else if (suma1 < suma2) {
    std::cout << "La suma de la primera fila es menor que la de la ultima" << suma1 << " <  " << suma2 << std::endl;
  } else {
    std::cout << "La suma de la primera fila es igual que la de la ultima" << suma1 << " =  " << suma2 << std::endl;
  }
}

// Suma de los valores por encima de la diagonal principal sin incluirla
void SumaEncimaDiagonal(int nfil, int ncol, int *mat){
  int suma = 0;
  for ( int f = 0; f < nfil; f++) {
    for (int c = 0; c < ncol; c++ ) {
      if (f < c) {
        suma += mat[f*ncol+c];
      }
    }
  }
  std::cout << "La suma de los valores por encima de la diagonal principal sin incluirla es: " << suma << std::endl;
}

int main(void) {

  int mat[] = {
    100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119,
    120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139,
    140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159,
    160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179,
    180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199,
    200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219,
    220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239,
    240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252, 253, 254, 255, 256, 257, 258, 259,
    260, 261, 262, 263, 264, 265, 266, 267, 268, 269, 270, 271, 272, 273, 274, 275, 276, 277, 278, 279,
    280, 281, 282, 283, 284, 285, 286, 287, 288, 289, 290, 291, 292, 293, 294, 295, 296, 297, 298, 299,
    300, 301, 302, 303, 304, 305, 306, 307, 308, 309, 310, 311, 312, 313, 314, 315, 316, 317, 318, 319,
    320, 321, 322, 323, 324, 325, 326, 327, 328, 329, 330, 331, 332, 333, 334, 335, 336, 337, 338, 339,
    340, 341, 342, 343, 344, 345, 346, 347, 348, 349, 350, 351, 352, 353, 354, 355, 356, 357, 358, 359,
    360, 361, 362, 363, 364, 365, 366, 367, 368, 369, 370, 371, 372, 373, 374, 375, 376, 377, 378, 379,
    380, 381, 382, 383, 384, 385, 386, 387, 388, 389, 390, 391, 392, 393, 394, 395, 396, 397, 398, 399,
    400, 401, 402, 403, 404, 405, 406, 407, 408, 409, 410, 411, 412, 413, 414, 415, 416, 417, 418, 419,
    420, 421, 422, 423, 424, 425, 426, 427, 428, 429, 430, 431, 432, 433, 434, 435, 436, 437, 438, 439,
    440, 441, 442, 443, 444, 445, 446, 447, 448, 449, 450, 451, 452, 453, 454, 455, 456, 457, 458, 459,
    460, 461, 462, 463, 464, 465, 466, 467, 468, 469, 470, 471, 472, 473, 474, 475, 476, 477, 478, 479,
    480, 481, 482, 483, 484, 485, 486, 487, 488, 489, 490, 491, 492, 493, 494, 495, 496, 497, 498, 499,
  };

  const int maximoElementos=400;
  int nfil = 20;
  int ncol = 10;
  int opcion;

  // se imprimie el título
  std::cout << "\nPráctica PR3 de Principios de Computadores. Matrices.\n";

  // se imprime la matriz
  EscribirMatriz(nfil, ncol, mat);

  // Menu de opciones
  do{
    std::cout << "\n\n(1) Cambiar dimensiones\n(2) Intercambiar dos elemento\n3)Suma elementos del perimetro \
                \n(4) Calcula max y min de la diagonal\n(5)Saber si la suma de la fila superior es mayor, menor o igual qeu la inferior \
                \n(6)Suma de la submatriz superior\n(0) Salir\n\nElija opcion: ";
    std::cin >> opcion;
    switch(opcion){
      case 1: {
        std::cout << "Introduzca el numero de filas: ";
        std::cin >> nfil;
        // se comprueba que el numero de filas no sea negativo ni mayor que el maximo permitido
        if(nfil < 0 || nfil > maximoElementos){
          std::cout << "Error: dimension incorrecta. Numero de fila incorrecto." << std::endl;
          break;
        }
        std::cout << "Introduzca el numero de columnas: ";
        std::cin >> ncol;
        // se comprueba que el numero de columnas no sea negativo ni mayor que el maximo permitido
        if(ncol < 0 || ncol > maximoElementos){
          std::cout << "Error: dimension incorrecta. Numero de fila incorrecto." << std::endl;
          break;
        }
        // se comprueba que el numero de elementos no sea mayor que el maximo permitido
        if (nfil*ncol > maximoElementos){
          std::cout << "Error: el numero de elementos supera el maximo permitido" << std::endl;
          break;
        }
        EscribirMatriz(nfil, ncol, mat);
        break;
      }
      case 2: {
        int fil1, col1, fil2, col2;
        std::cout << "Introduzca la fila del primer elemento: ";
        std::cin >> fil1;
        std::cout << "Introduzca la columna del primer elemento: ";
        std::cin >> col1;
        std::cout << "Introduzca la fila del segundo elemento: ";
        std::cin >> fil2;
        std::cout << "Introduzca la columna del segundo elemento: ";
        std::cin >> col2;

        fil1 = fil1 - 1;
        col1 = col1 - 1;
        fil2 = fil2 - 1;
        col2 = col2 - 1;
        // se comprueba que los indices estan dentro de la matriz
        if(fil1 < 0 || fil1 >= nfil || col1 < 0 || col1 >= ncol || fil2 < 0 || fil2 >= nfil || col2 < 0 || col2 >= ncol){
          std::cout << "Error: indice fuera de rango" << std::endl;
          break;
        }
        IntercambiarElementos(nfil, ncol, mat, fil1, col1, fil2, col2);
        EscribirMatriz(nfil, ncol, mat);
        break;
      }
      case 3:{
        EscribirMatriz(nfil, ncol, mat);
        std::cout << "La suma de los elementos del perimetro es: " << SumaPerimetro(nfil, ncol, mat) << std::endl;
        break;
      }
      case 4:{
        EscribirMatriz(nfil, ncol, mat);
        MaxMinDiagonal(nfil, ncol, mat);
        break;
      }
      case 5:{
        EscribirMatriz(nfil, ncol, mat);
        SumaDoble(nfil, ncol, mat);
        break;
      }
      case 6:{
        EscribirMatriz(nfil, ncol, mat);
        SumaEncimaDiagonal(nfil, ncol, mat);
        break;
      }
      case 0:{
        std::cout << "Fin del Programa\n";
        return 0;
      }
      default:{
        std::cout << "Opcion no valida\n";
        break;
      }
    }
  }while(true);
  
  return 0;
}