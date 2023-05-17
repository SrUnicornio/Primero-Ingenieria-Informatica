# Esqueleto PR3
# Álvaro Pérez Ramos      30/03/2023      alu0101574042@ull.edu.es      1º GII    Universidad de La Laguna
#nfil = 20             # numero de filas de la matriz
#ncol = 10             # numero de columnas de la matriz
maximoElementos = 400     # numero de enteros maximo reservado para la matriz 1600 bytes
tam_elem = 4              # bytes que ocupa un entero
#size_salto = ncol * tam_elem   # bytes que ocupa una fila de la matriz
#sizeM = nfil * size_salto   # bytes que ocupa la matriz
    .data
mat:  .word   100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119    # 0 4 8 12 16 20 24 28 32 36 40 44 48 52 56 60 64 68 72 76
      .word   120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139    # 80 84 88 92 96 100 104 108 112 116 120 124 128 132 136 140 144 148 152 156
      .word   140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159    # 160 164 168 172 176 180 184 188 192 196 200 204 208 212 216 220 224 228 232 236
      .word   160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179    # 240 244 248 252 256 260 264 268 272 276 280 284 288 292 296 300 304 308 312 316
      .word   180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199    # 320 324 328 332 336 340 344 348 352 356 360 364 368 372 376 380 384 388 392 396
      .word   200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219    # 400 404 408 412 416 420 424 428 432 436 440 444 448 452 456 460 464 468 472 476
      .word   220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239    # 480 484 488 492 496 500 504 508 512 516 520 524 528 532 536 540 544 548 552 556
      .word   240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252, 253, 254, 255, 256, 257, 258, 259    # 560 564 568 572 576 580 584 588 592 596 600 604 608 612 616 620 624 628 632 636
      .word   260, 261, 262, 263, 264, 265, 266, 267, 268, 269, 270, 271, 272, 273, 274, 275, 276, 277, 278, 279    # 640 644 648 652 656 660 664 668 672 676 680 684 688 692 696 700 704 708 712 716
      .word   280, 281, 282, 283, 284, 285, 286, 287, 288, 289, 290, 291, 292, 293, 294, 295, 296, 297, 298, 299    # 720 724 728 732 736 740 744 748 752 756 760 764 768 772 776 780 784 788 792 796
      .word   300, 301, 302, 303, 304, 305, 306, 307, 308, 309, 310, 311, 312, 313, 314, 315, 316, 317, 318, 319    # 800 804 808 812 816 820 824 828 832 836 840 844 848 852 856 860 864 868 872 876
      .word   320, 321, 322, 323, 324, 325, 326, 327, 328, 329, 330, 331, 332, 333, 334, 335, 336, 337, 338, 339    # 880 884 888 892 896 900 904 908 912 916 920 924 928 932 936 940 944 948 952 956
      .word   340, 341, 342, 343, 344, 345, 346, 347, 348, 349, 350, 351, 352, 353, 354, 355, 356, 357, 358, 359    # 960 964 968 972 976 980 984 988 992 996 1000 1004 1008 1012 1016 1020 1024 1028 1032 1036
      .word   360, 361, 362, 363, 364, 365, 366, 367, 368, 369, 370, 371, 372, 373, 374, 375, 376, 377, 378, 379    # 1040 1044 1048 1052 1056 1060 1064 1068 1072 1076 1080 1084 1088 1092 1096 1100 1104 1108 1112 1116
      .word   380, 381, 382, 383, 384, 385, 386, 387, 388, 389, 390, 391, 392, 393, 394, 395, 396, 397, 398, 399    # 1120 1124 1128 1132 1136 1140 1144 1148 1152 1156 1160 1164 1168 1172 1176 1180 1184 1188 1192 1196
      .word   400, 401, 402, 403, 404, 405, 406, 407, 408, 409, 410, 411, 412, 413, 414, 415, 416, 417, 418, 419    # 1200 1204 1208 1212 1216 1220 1224 1228 1232 1236 1240 1244 1248 1252 1256 1260 1264 1268 1272 1276
      .word   420, 421, 422, 423, 424, 425, 426, 427, 428, 429, 430, 431, 432, 433, 434, 435, 436, 437, 438, 439    # 1280 1284 1288 1292 1296 1300 1304 1308 1312 1316 1320 1324 1328 1332 1336 1340 1344 1348 1352 1356
      .word   440, 441, 442, 443, 444, 445, 446, 447, 448, 449, 450, 451, 452, 453, 454, 455, 456, 457, 458, 459    # 1360 1364 1368 1372 1376 1380 1384 1388 1392 1396 1400 1404 1408 1412 1416 1420 1424 1428 1432 1436
      .word   460, 461, 462, 463, 464, 465, 466, 467, 468, 469, 470, 471, 472, 473, 474, 475, 476, 477, 478, 479    # 1440 1444 1448 1452 1456 1460 1464 1468 1472 1476 1480 1484 1488 1492 1496 1500 1504 1508 1512 1516
      .word   480, 481, 482, 483, 484, 485, 486, 487, 488, 489, 490, 491, 492, 493, 494, 495, 496, 497, 498, 499    # 1520 1524 1528 1532 1536 1540 1544 1548 1552 1556 1560 1564 1568 1572 1576 1580 1584 1588 1592 1596

nfil:   .word   20 # nuemro de filas de la matriz
ncol:   .word   10 # numero de columnas de la matriz

titulo:     .asciiz "\nPráctica PR3 de Principios de Computadores. Manejo de Matrices.\n"
msg_matriz: .asciiz "\nLa matriz es "
msg_x:      .asciiz "x"
separador:  .asciiz "  " # separador entre numeros
newline:    .asciiz "\n"
menu:       .ascii  "\n\n(1) Cambiar dimensiones\n(2) Intercambiar dos elemento\n"
            .ascii  "(3) Suma elementos del perimetro\n(4) Calcula max y min de la diagonal\n"
            .asciiz "(0) Salir\n\nElija opcion: "

error_op:   .asciiz "\nError: opcion incorrecta.\n"
msg_nfilas: .asciiz "Introduzca numero de filas: "
msg_ncols:  .asciiz "Introduzca numero de columnas: "
error_nfilas:   .asciiz "\nError: dimension incorrecta. Numero de fila incorrecto.\n"
error_ncols:    .asciiz "\nError: dimension incorrecta. Numero de columna incorrecto.\n"
error_dime:     .asciiz "\nError: dimension incorrecta. Excede el maximo numero de elementos (400).\n"
msg_i:      .asciiz "Introduzca fila del primer elemento a cambiar: "
msg_j:      .asciiz "Introduzca columna del primer elemento a cambiar: "
msg_r:      .asciiz "Introduzca fila del segundo elemento a cambiar: "
msg_s:      .asciiz "Introduzca columna del segundo elemento a cambiar: "
msg_suma:   .asciiz "\n\nSuma de los elementos del perímetro: "
msg_max:    .asciiz "\nEl máximo de la diagonal principal es "
msg_min:    .asciiz " y el mínimo "
msg_fin:    .asciiz "\nFin del programa.\n"

    .text
main:
  # std::cout << "\nPráctica PR3 de Principios de Computadores. Matrices.\n";
  li $v0, 4
  la $a0, titulo
  syscall
  la $s0, mat # Carga la direccion de la matriz[nfil][ncol] en $a0

    # std::cout << "\nLa matriz es ";
    MostrarMatriz:
      li $v0, 4
      la $a0, msg_matriz
      syscall
      # std::cout << nfil << "x" << ncol << std::endl;
      lw $t0, nfil
      li $v0, 1
      move $a0, $t0
      syscall
      li $v0, 4
      la $a0, msg_x
      syscall
      lw $t0, ncol
      li $v0, 1
      move $a0, $t0
      syscall
      li $v0, 4
      la $a0, newline
      syscall

      lw $t0, nfil
      lw $t1, ncol
      mul $s4, $t1, tam_elem # ncol * tam_elem = size_salto
      mul $s5, $t0, $s4 # nfil * size_salto = size_matriz
      # Comienza el bucle para mostrar la matriz
      move $s1, $zero # i = 0
      For1: move $s2, $zero # j = 0
        # std::cout << std::endl;
        li $v0, 4
        la $a0, newline
        syscall
        For2: addu $t2, $s1, $s2 # i * nculm + j
              addu $t2, $t2, $s0 # i * nculm + j + matriz
              lw $t3, 0($t2)
          # std::cout << matriz[i][j] << " ";
          li $v0, 1
          move $a0, $t3
          syscall
          li $v0, 4
          la $a0, separador
          syscall
          addu $s2, $s2, tam_elem # j++
          blt $s2, $s4, For2
        Fin_For2:
        addu $s1, $s1, $s4 # i++
        blt $s1, $s5, For1
      Fin_For1:
    MostrarMatriz_Fin:


  Menu:

    # std::cout << "\n(1) Cambiar dimensiones\n(2) Intercambiar dos elemento\n";
    # std::cout << "(3) Suma elementos del perimetro\n(4) Calcula max y min de la diagonal\n";
    # std::cout << "(0) Salir\n\nElija opcion: ";
    li $v0, 4
    la $a0, menu
    syscall
    # std::cin >> opcion;
    li $v0, 5
    syscall
    move $s1, $v0 # $s1 = opcion = v0
    # switch (opcion) {
    switch:
      #   case 1:
        beq $s1, 1, CambiarDimensiones
      #  case 2:
        # beq $s1, 2, IntercambiarElementos
      #   case 3:
        #beq $s1, 3, SumaPerimetro
      #   case 4:
        beq $s1, 4, MaxMinDiagonal
      #   case 0:
        beq $s1, 0, Fin
      #   default:
        blt, $s1, 0, ErrorOpcion
        bgt, $s1, 4, ErrorOpcion
      
      # Case1: CambiarDimensiones();
      CambiarDimensiones:
        Introduzca_valores:
          # std::cout << "Introduzca numero de filas: ";
          li $v0, 4
          la $a0, msg_nfilas
          syscall
          # std::cin >> nfil;
          li $v0, 5
          syscall
          move $s1, $v0 # $s2 = nfil = v0
          sw $s1, nfil
          # std::cout << "Introduzca numero de columnas: ";
          li $v0, 4
          la $a0, msg_ncols
          syscall
          # std::cin >> ncol;
          li $v0, 5
          syscall
          move $s2, $v0 # $s2 = ncol = v0
          sw $s2, ncol
        Fin_Introduzca_valores:

        # Comprobamos que las dimensiones de las filas sean correctas
        # if (nfil <= 0 || nfil > maximoElementos) {
        blez $s1 Error_Dimensiones1
        bgt $s1, maximoElementos, Error_Dimensiones1
        # }

        # Comprobamos que las dimensiones de las columnas sean correctas
        # if (ncol <= 0 || ncol > maximoElementos) {
        blez $s2 Error_Dimensiones2
        bgt $s2, maximoElementos, Error_Dimensiones2
        # }
        # Comprobamos que las dimensiones sean correctas
        # if (nfil * ncol > maximoElementos) {
        mul $s3, $s2, $s1
        bgt $s3, maximoElementos, Error_Dimensiones3
        # }

        j MostrarMatriz

        # Error_Dimensiones
          Error_Dimensiones1:
            # std::cout << "\nError: dimension incorrecta. Numero de filas incorrecto.\n";
            li $v0, 4
            la $a0, error_nfilas
            syscall
            # break;
            j switch_fin
          Error_Dimensiones2:
            # std::cout << "\nError: dimension incorrecta. Numero de columnas incorrecto.\n";
            li $v0, 4
            la $a0, error_ncols
            syscall
            # break;
            j switch_fin
          Error_Dimensiones3:
            # std::cout << "\nError: dimensiones incorrectas.\n";
            li $v0, 4
            la $a0, error_dime
            syscall
          # break;
          j switch_fin
      CambiarDimensiones_Fin:

            # Case 4: MaxMinDiagonal();
      MaxMinDiagonal:

        # Carga de variables, matriz ya cargada en $s0
        lw $t0, nfil
        lw $t1, ncol
        lw $s1, 0($s0) # max = matriz[0]
        lw $s2, 0($s0) # min = matriz[0]
        move $s3, $t0 # valor = nfil

        # if (nfil > ncol) {
        bgt $t0, $t1, If3
        j Else
        If3:
          # valor = ncol;
          move $s3, $t1
          j If3_Fin
        Else:
          # valor = nfil;
          move $s3, $t0
        If3_Fin:

        # BUSQUEDA DEL MAXIMO Y MINIMO mediante un bucle for
        mul $s3, $s3, tam_elem # Adaptar a bytes el valor de la variable
        move $s4, $zero # i = 0
        For5:
          mul $t2, $s4, $t1 #  i * ncol
          addu $t2, $t2, $s4 #  i * ncol + i
          addu $t2, $t2, $s0 #  i * ncol + i + matriz
          lw $t3, 0($t2) # matriz[i * ncol + i]

          # if (matriz[i * ncol + i] > max) {
          Maximo:
            bgt $s1, $t3, Minimo
            # max = matriz[i * ncol + i];
            move $s1, $t3
            # }
            j Fin_Minimo
          Fin_Maximo:
          # if (matriz[i * ncol + i] < min) {
          Minimo:
            move $s2, $t3
          Fin_Minimo:

          addu $s4, $s4, tam_elem # i++
          bgt $s3, $s4, For5 # i < valor
        Fin_For5:

        # std::cout << "\nMaximo: " << max << "\n";
        li $v0, 4
        la $a0, msg_max
        syscall
        li $v0, 1
        move $a0, $s1
        syscall
        # std::cout << "Minimo: " << min << "\n";
        li $v0, 4
        la $a0, msg_min
        syscall
        li $v0, 1
        move $a0, $s2
        syscall
        # break;
        j MostrarMatriz
      Fin_MaxMinDiagonal:
      # Case 3: SumaPerimetro();
      # Case 4: MaxMinDiagonal();
      #  default:
      ErrorOpcion:
        # std::cout << "\nError: opcion incorrecta.\n";
        li $v0, 4
        la $a0, error_op
        syscall
        # break;
        j switch_fin
      ErrorOpcion_Fin:
      # }
    switch_fin:
    j Menu
  Menu_Fin:

  # return 0;
  Fin:
  li $v0, 4
  la $a0, msg_fin
  syscall

  li $v0, 10
  syscall
# }
