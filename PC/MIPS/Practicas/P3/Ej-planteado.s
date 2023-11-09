nfil = 5                        # numero de filas
nculm = 6                       # numero de columnas
tam_elem = 4                    # tamaño de cada elemento en 4 bytes
size_salto = nculm * tam_elem   # Salto de una fila a otra
size_salto2 = nfil * tam_elem   # Salto de una columna a otra
sizeM = nfil * nculm * tam_elem # tamaño de la matriz
  .data
msgpid:     .asciiz   "\n\nIngrese un numero \n"
msginitial: .asciiz   "\n\nMatriz es: "
msgmres:    .asciiz   "\nLa suma de la columna elegida es: "
matriz:     .word     1, 2, 3, 4, 5, 6 # 0 4 8 12 16 20
            .word     7, 8, 9, 10, 11, 12 # 24 28 32 36 40 44
            .word     13, 14, 15, 16, 17, 18 # 48 52 56 60 64 68
            .word     19, 20, 21, 22, 23, 24 # 72 76 80 84 88 92
            .word     25, 26, 27, 28, 29, 30 # 96 100 104 108 112 116
suma:       .word     0
msgfin:     .asciiz   "\n\nPrograma finalizado"
msgendl:    .asciiz   "\n"
msgespace:  .asciiz   "\t"
  .text
main:
  la $s0, matriz # matriz[n][m]
  Show_Matriz:
    li $v0, 4
    la $a0, msginitial
    syscall
    move $s1, $zero # i = 0
    For1: move $s2, $zero # j = 0
      # std::cout << std::endl;
      li $v0, 4
      la $a0, msgendl
      syscall
      For2: addu $t1, $s1, $s2 # i * nculm + j
            addu $t1, $t1, $s0 # i * nculm + j + matriz
            lw $s3, 0($t1)
        # std::cout << matriz[i][j] << " ";
        li $v0, 1
        move $a0, $s3
        syscall
        li $v0, 4
        la $a0, msgespace
        syscall
        addu $s2, $s2, tam_elem # j++
        blt $s2, size_salto, For2
      Fin_For2:
      addu $s1, $s1, size_salto # i++
      blt $s1, sizeM, For1
    Fin_For1:
  move $s1, $zero
  move $s2, $zero
  # while (number > nfil){std::cin >> number;}
  Pid_N:
    li $v0, 4
    la $a0, msgpid
    syscall
    li $v0, 5
    syscall
    move $s1, $v0
    if: ble $s1, $zero, Pid_N
    if2: bgt $s1, nculm, Pid_N
  fin_Pid_N:
  # int suma = 0;
  li $s2, 0 # suma
  # for (int i = 0; i < nfil; i++){
  li $t1, 0 # i = 0
  sub $s1, $s1, 1
  mul $s1, $s1, tam_elem # number * tam_elem
  li $t3, 0
  For3:
    addu $t3, $s0, $t1 # i * tam_elem + matriz
    addu $t3, $t3, $s1 # matriz[i][number -1]
    lw $t2, 0($t3) # matriz[i][0]	
    add $s2, $s2, $t2 # suma = suma + matriz[i][number -1]
    
    addu $t1, $t1, size_salto # i++
    blt $t1, sizeM, For3
  Fin_For3:
  sw $s2, suma
  li $v0, 4
  la $a0, msgmres
  syscall
  li $v0, 1
  lw $a0, suma
  syscall

  fin_programa:
  li $v0, 4
  la $a0, msgfin
  syscall
  li $v0, 10
  syscall
Fin_Main: