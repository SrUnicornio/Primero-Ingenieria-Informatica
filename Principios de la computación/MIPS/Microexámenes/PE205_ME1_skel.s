# Autor: Juan Esteban Tamayo Marmolejo
# Fecha ultima modificacion: 


size=8
    .data
matriz:     .double 1.75, 10.0, 7.25, 6.25, 5.75
            .double 4.5, 4.25, 3.5, -10.0, -2.0
            .double -6.25, 7.5, 10.0, 1.25, -4.75
            .double 2.5, 3.5, 4.5, 7.75, -10.0
nfil:       .word 4
ncol:       .word 5
newline:    .asciiz "\n"
msgfin:     .asciiz "\nFIN DEL PROGRAMA\n"
    .text

# void printmat(std::array<std::array<double,ncol>,nfil> &m, const int nf, const int nc) {
#     for ( int i = 0;  i < nf ;  i++) {
#             for ( int j = 0; j < nc ; j++)
#                 std::cout << matriz[i][j] << " ";
#             std::cout << std::endl;
#     }
#     return;
# }
printmat: # $a0 = matriz, $a1 = nfil, $a2 = ncol
  addi $sp, $sp, -24
  sw $ra, 0($sp)
  sw $s0, 4($sp)
  sw $s1, 8($sp)
  sw $s2, 12($sp)
  sw $s3, 16($sp)
  sw $s4, 20($sp)


  move $s0, $a0 # $s0 = matriz
  move $s1, $a1 # $s1 = nfil
  move $s2, $a2 # $s2 = ncol

  move $s3, $zero # i = 0
  for_printmat: move $s4, $zero # j = 0
    for_printmat2:
      mul $t0, $s3, $s2 # i * ncol
      add $t0, $t0, $s4 # i * ncol + j
      mul $t0, $t0, 8 # (i * ncol + j) * 8
      add $t0, $t0, $s0 # matriz + (i * ncol + j) * 8
      l.d $f12, 0($t0) # $f12 = matriz[i][j]

      li $v0, 3 # imprimir un double
      syscall

      li $v0, 11 # imprimir un caracter espacio
      li $a0, 32
      syscall

      addi $s4, $s4, 1 # j++
      blt $s4, $s2, for_printmat2 # if (j < ncol) goto for_printmat2
    for_printmat2_fin:

    li $v0, 11 # imprimir un caracter newline
    li $a0, 13
    syscall

    addi $s3, $s3, 1 # j++
    blt $s3, $s1, for_printmat # if (i < ncol) goto for_printmat1
  for_printmat_fin:

  lw $ra, 0($sp)
  lw $s0, 4($sp)
  lw $s1, 8($sp)
  lw $s2, 12($sp)
  lw $s3, 16($sp)
  lw $s4, 20($sp)
  addi $sp, $sp, 24

  jr $ra
printmat_fin:

# double maximo(std::array<std::array<double,ncol>,nfil> &m, const int nf, const int nc, const int index){
#     int j;
#     double max = fabs(m[index][0]);
#     for ( j = 1; j < nc ; j++)
#         if (max < fabs(m[index][j])) max = fabs(m[index][j]);
#     return(max);
# }
maximo: # $a0 = matriz, $a1 = nfil, $a2 = ncol, $a3 = indice
  addi $sp, $sp, -24
  sw $ra, 0($sp)
  sw $s0, 4($sp)
  sw $s1, 8($sp)
  sw $s2, 12($sp)
  sw $s3, 16($sp)
  sw $s4, 20($sp)


  move $s0, $a0 # $s0 = matriz
  move $s1, $a1 # $s1 = nfil
  move $s2, $a2 # $s2 = ncol
  move $s3, $a3 # $s3 = indice

  move $s4, $zero # j = 0
  for_maximo: 
    mul $t0, $s3, $s2 # indice * ncol
    add $t0, $t0, $s4 # indice * ncol + j
    mul $t0, $t0, 8 # (indice * ncol + j) * 8
    add $t0, $t0, $s0 # matriz + (indice * ncol + j) * 8
    l.d $f4, 0($t0) # $f4 = matriz[indice][j]

    abs.d $f4, $f4 # $f4 = fabs(matriz[indice][j])

    maximo_if:
    c.lt.d $f20, $f4 # if (max < fabs(matriz[indice][j]))
    bc1f maximo_if_fin # goto maximo_if
    mov.d $f20, $f4 # max = fabs(matriz[indice][j])
    maximo_if_fin:

    add $s4, $s4, 1 # j++
    blt $s4, $s2, for_maximo # if (j < ncol) goto for_maximo
  for_maximo_fin:

  mov.d $f0, $f20 # $f0 = max

  lw $ra, 0($sp)
  lw $s0, 4($sp)
  lw $s1, 8($sp)
  lw $s2, 12($sp)
  lw $s3, 16($sp)
  lw $s4, 20($sp)
  addi $sp, $sp, 24

  jr $ra
maximo_fin:

# void normaliza(std::array<std::array<double,ncol>,nfil> &m, const int nf, const int nc) {
#     int i,j;
#     double max;
#     for ( i = 0 ;  i < nf ;  i++) {
#         max = maximo(m,nf,nc,i);
#         for ( j = 0; j < nc ; j++)
#             m[i][j] /= max;
#     }
#     return;
# }
normaliza: # $a0 = matriz, $a1 = nfil, $a2 = ncol
  addi $sp, $sp, -32
  sw $ra, 0($sp)
  sw $s0, 4($sp)
  sw $s1, 8($sp)
  sw $s2, 12($sp)
  sw $s3, 16($sp)
  sw $s4, 20($sp)
  s.d $f20, 24($sp)

  move $s0, $a0 # $s0 = matriz
  move $s1, $a1 # $s1 = nfil
  move $s2, $a2 # $s2 = ncol

  li.d $f20, 0.0 # max = 0.0

  move $s3, $zero # i = 0
  for_normaliza: move $s4, $zero # j = 0

    # max = maximo(m,nf,nc,i);
    move $a0, $s0 # $a0 = matriz
    move $a1, $s1 # $a1 = nfil
    move $a2, $s2 # $a2 = ncol
    move $a3, $s3 # $a3 = i
    jal maximo # $f0 = maximo(m,nf,nc,i)

    # max = $f0
    mov.d $f20, $f0
    for_normaliza2:
    # m[i][j] /= max;
      mul $t0, $s3, $s2 # i * ncol
      add $t0, $t0, $s4 # i * ncol + j
      mul $t0, $t0, 8 # (i * ncol + j) * 8
      add $t0, $t0, $s0 # matriz + (i * ncol + j) * 8
      l.d $f12, 0($t0) # $f12 = matriz[i][j]

      div.d $f12, $f12, $f20 # $f12 = matriz[i][j] / max

      s.d $f12, 0($t0) # matriz[i][j] = $f12

      add $s4, $s4, 1 # j++
      blt $s4, $s2, for_normaliza2 # if (j < ncol) goto for_normaliza2
    for_normaliza2_fin:
    add $s3, $s3, 1 # i++
    blt $s3, $s1, for_normaliza # if (i < nfil) goto for_normaliza
  for_normaliza_fin:

  lw $ra, 0($sp)
  lw $s0, 4($sp)
  lw $s1, 8($sp)
  lw $s2, 12($sp)
  lw $s3, 16($sp)
  lw $s4, 20($sp)
  l.d $f20, 24($sp)
  addi $sp, $sp, 32

  jr $ra
normaliza_fin:

# int main(void) {
#     printmat(matriz,nfil,ncol);
#     normaliza(matriz,nfil,ncol);
#     std::cout << "\n";
#     printmat(matriz,nfil,ncol);
#     std::cout << "\nFIN DEL PROGRAMA\n";
#     return(0);
# }

  li $v0,11 # imprimir un caracter espacio
  li $a0,32
  syscall

  li $v0,11 # imprimir un caracter newline
  li $a0,13
  syscall

main:
  # printmat(matriz,nfil,ncol);
  la $a0, matriz
  lw $a1, nfil
  lw $a2, ncol
  jal printmat

  # normaliza(matriz,nfil,ncol);
  la $a0, matriz
  lw $a1, nfil
  lw $a2, ncol
  jal normaliza

  # std::cout << "\n";
  li $v0,11 # imprimir un caracter newline
  li $a0,13
  syscall

  # printmat(matriz,nfil,ncol);
  la $a0, matriz
  lw $a1, nfil
  lw $a2, ncol
  jal printmat

  # std::cout << "\nFIN DEL PROGRAMA\n";
  li $v0, 4
  la $a0, msgfin
  syscall


  li $v0, 10 # exit
  syscall