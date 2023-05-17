# Ejemplo que realiza la suma de elementos de una mariz
nfilas = 3          # numero de filas
ncolumnas = 5       # numero de columnas
tam_elemento = 4    # 4 bytes por elemento
size = nfilas * ncolumnas * tam_elemento - 4

                    # suponiemdo la matriz[0.nfilas-1, 0.ncolumnas-1]
                    # el desplazamiento de la matriz[i,j] sera:
                    # matriz[(i*ncolumnas+j)*tam_elemento]
        .data
matriz: .word 1, 1, 1, 1, 1  # 0 4 8 12 16
        .word 2, 2, 2, 2, 2  # 20 24 28 32 36
        .word 3, 3, 3, 3, 3  # 40 44 48 52 56
suma:   .word 0
        .text
main:
  move $s0, $zero             # $s0 contendra la suma de los elementos la inicializamos a 0

  la $s1, matriz              # $s1 contendra la direccion de la matriz
  move $t0, $zero             # $t0 = indice de la fila. Inicializamos a 0

bucle
  li $v0, 10
  syscall