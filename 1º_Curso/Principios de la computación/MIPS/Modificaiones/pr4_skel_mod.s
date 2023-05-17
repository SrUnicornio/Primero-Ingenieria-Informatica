# Autor: Álvaro Pérez Ramos
# Fecha inicio: 19/04/2023
# Fecha ultima modificacion: 22/04/2023

size = 4     # bytes que ocupa cada elemento
maxdim = 40  # dimension maxima que puede tener un vector

    .data
v1:         .space 160
v2:         .space 160 
n1:         .word 0 # numero eltos vector 1. Inicialmente suponemos vacios
n2:         .word 0 # numero eltos vector 2. Inicialmente suponemos vacios
space:      .asciiz " "
newline:    .asciiz "\n"
title:      .asciiz "\nPractica 4 de Principios de Computadores. Subrutinas.\n"
menu:       .ascii  "\n(1) Cambiar dimension de un vector\n(2) Cambiar un elemento de un vector\n"
            .ascii  "(3) Invertir un vector\n(4) Calcular el producto escalar de dos vectores\n"
            .asciiz "(5) Suma elemetos de v1 y el inverso de v2\n(0) Salir\n\nElija opcion: ";
cabvec:     .asciiz "\nVector con dimension "
error_op:   .asciiz "\nError: opcion incorrecta.\n"
elige_vec:  .asciiz "\nElija vector para realizar la operacion (1) para v1 (2) para v2: "
elige_elto: .asciiz "\nElija el indice del elemento a cambiar: "
newval:     .asciiz "\nIntroduce nuevo valor para el elemento elegido: "
newdim:     .asciiz "\nIntroduzca nueva dimension para el vector (1-40): "
error_dim:  .asciiz "\nError: Dimension incorrecta.\n"
error_ind:  .asciiz "\nError: Indice incorrecto.\n"
error_d_dim:    .asciiz "\nError: Los vectores tienen distinta dimension.\n"
msg_prodesc:    .asciiz "\nEl producto escalar de los vectores es: "
msg_fin:    .asciiz "\nFIN DEL PROGRAMA."

    .text
  # Subrutina para mostrar un vector
  # void print_vec(float *v, int n, std::string separador = " ")
  #   for (int i = 0; i < n; i++) {
  #     std::cout << v[i] << separador;
  #   }
  #}
print_vec:  # Funcion para imprimir un vector, recibe como parametros:
            # $a0: direccion del vector
            # $a1: dimension del vector
            # $a2: separador entre elementos

  add $sp $sp -24 # reservamos espacio para los registros $s0-$s4
  sw $ra, 20($sp) # guardamos el valor de $ra
  sw $s4, 16($sp)
  sw $s3, 12($sp)
  sw $s2, 8($sp)
  sw $s1, 4($sp)
  sw $s0, 0($sp)
    
  move $s0, $a0 # t0 = v
  move $s1, $a1 # t1 = n
  move $s2, $a2 # t2 = separador
  move $s3, $zero # i = 0
  For_print_vec: # for (int i = 0; i < n; i++) {
    mul $s4, $s3, 4 # i * size
    add $s4, $s4, $s0 # t4 = v + i
    l.s $f12, 0($s4) # t5 = v[i]
    #std::cout << v[i] << " ";

    li $v0, 2
    syscall
    li $v0, 4
    move $a0, $s2
    syscall

    addi $s3, $s3, 1 # i++
    blt $s3, $s1, For_print_vec # i < n

  Fin_for_print_vec: # }
  lw $s0, 0($sp)
  lw $s1, 4($sp)
  lw $s2, 8($sp)
  lw $s3, 12($sp)
  lw $s4, 16($sp)
  lw $ra, 20($sp)
  add $sp $sp 24 # liberamos espacio para los registros $s0-$s4
  jr $ra
print_vec_fin: # Correcto

  # Subrutina para cambiar un elemento de un vector
  # void change_elto(float* v, int n, float valor) {
  #   v[n] = valor;
  # }
change_elto: # Funcion para cambiar un elemento de un vector, recibe como parametros:
            # $a0: direccion del vector
            # $a1: indice del elemento a cambiar
            # $f0: nuevo valor del elemento
  move $t0, $a0 # t0 = v
  move $t1, $a1 # t1 = n
  mov.s $f4, $f0 # f4 = valor

  mul $t2, $t1, 4 # n * size
  add $t2, $t2, $t0 # t2 = v + n
  s.s $f4, 0($t2) # v[n] = valor

  jr $ra
change_elto_fin: # Correcto

  # Subrutina mirror para invertir un vector de forma recursiva usando swap 
  # void swap(float* v, int i, int j)
  # {
  #   float aux = v[i];
  #   v[i] = v[j];
  #   v[j] = aux;
  # }
swap: # Funcion para intercambiar elementos, recibe como parámetros:
      # $a0: direccion del vector
      # $a2: indice del primer elemento
      # $a3: indice del segundo elemento
  move $t0, $a0 # t0 = v
  move $t1, $a1 # t1 = i
  move $t2, $a2 # t2 = j

  mov.s $f4, $f0 # f4 = aux

  mul $t3, $t1, 4 # i * size
  add $t3, $t3, $t0 # t3 = v + i
  l.s $f4, 0($t3) # f4 = v[i] (aux)

  mul $t4, $t2, 4 # j * size
  add $t4, $t4, $t0 # t4 = v + j
  l.s $f6, 0($t4) # f6 = v[j]

  s.s $f6, 0($t3) # v[i] = v[j]
  s.s $f4, 0($t4) # v[j] = aux
  jr $ra
swap_fin: # Correcto

  # void mirror(float* v, int n) 
  # {
  #   if (n == 0 || n == 1) {
  #     return;
  #   }
  #   swap(v, 0, n-1);
  #   mirror(v+1, n-2);
  # }
mirror: # Funcion para invertir un vector, recibe como parametros:
        # $a0: direccion del vector
        # $a1: dimension del vector
  add $sp $sp -12 # reservamos espacio para los registros $t0-$t2 y $ra
  sw $ra, 8($sp) # guardamos el valor de $ra
  sw $a0, 4($sp) # guardamos el valor de v
  sw $a1, 0($sp) # guardamos el valor de n

  IF_mirror: # if (n == 0 || n == 1) {
    beqz $a1, end # n == 0
    beq $a1, 1, end # n == 1
  IF_mirror_fin:

  intercambio:
    addi $sp, $sp, -12 # reservamos espacio para guardar el valor de $ra, v, n
    sw $ra, 8($sp) # guardamos el valor de $ra
    sw $a0, 4($sp) # guardamos el valor de v
    sw $a1, 0($sp) # guardamos el valor de n
    
    move $t0, $a1 # t0 = n

    # vector ya cargado en $a0
    move $a0, $a0 # v = v
    li $a1, 0 # i = 0
    add $a2, $t0, -1 # t0 = n - 1
    jal swap # swap(v, 0, n-1)

    lw $a1, 0($sp) # recuperamos el valor de n
    lw $a0, 4($sp) # recuperamos el valor de v
    lw $ra, 8($sp) # recuperamos el valor de $ra
    addi $sp, $sp, 12 # liberamos espacio para guardar el valor de $ra, v, n

    addi $a0, $a0, 4 # v = v + 1
    addi $a1, $a1, -2 # n = n - 1
    jal mirror # mirror(v+1, n-2)
    
    lw $a1, 0($sp) # recuperamos el valor de n
    lw $a0, 4($sp) # recuperamos el valor de v
    lw $ra, 8($sp) # recuperamos el valor de $ra
    addi $sp, $sp, 12 # liberamos espacio para guardar el valor de $ra, v, n
  
  end:
    jr $ra
mirror_fin: # Correcto

  # Subrutina para calcular el producto escalar de dos vectores de forma recursiva usando mult_add
  # float mult_add(float vec1, float vec2, int result) 
  # {
  #   return vec1 * vec2 + result;
  # }
mult_add: # Funcion para calcular el producto escalar de dos vectores, recibe como parametros:
          # $f12: primer elemento del vector 1
          # $f13: primer elemento del vector 2
          # $f14: resultado parcial del producto escalar

  mul.s $f4, $f12, $f13 # f4 = vec1 * vec2
  add.s $f14, $f14, $f4 # f14 = vec1 * vec2 + result

  mov.s $f0, $f14 # f0 = f14

  jr $ra
mult_add_fin: # Correcto

  # float prod_esc(float* v1, float* v2, int n) {
  #   if (n == 0) {
  #     return 0;
  #   }
  #   // sin recursividad
  #   float result = 0;
  #   for (int i = 0; i < n; i++) {
  #     result = mult_add(v1[i], v2[i], result);
  #   }
  #   return result;
  # }
prod_esc: # Funcion para calcular el producto escalar de dos vectores, recibe como parametros:
          # $a0: direccion del vector 1
          # $a1: direccion del vector 2
          # $a2: dimension de los vectores

  IF_prod_esc: # if (n == 0) {
    li.s $f4, 0.0 # f4 = 0 (result)
    beqz $a2, end_prod_esc # n == 0
  IF_prod_esc_fin:

  # for (int i = 0; i < n; i++) {
  move $t0, $zero # i = 0
  For_prod_esc:
    add $sp, $sp, -20 # reservamos espacio para guardar el valor de $t0
    sw $ra, 16($sp) # guardamos el valor de $t0
    sw $a0, 12($sp) # guardamos el valor de $t0
    sw $a1 8($sp) # guardamos el valor de v1
    sw $a2 4($sp) # guardamos el valor de v2
    sw $t0, 0($sp) # guardamos el valor de $t0

    # result = mult_add(v1[i], v2[i], result);
    l.s $f12, 0($a0) # f12 = v1[i]
    l.s $f13, 0($a1) # f13 = v2[i]
    mov.s $f14, $f4 # f14 = result
    jal mult_add # f0 = mult_add(v1[i], v2[i], result)
    mov.s $f4, $f0 # result = f0

    lw $t0, 0($sp) # recuperamos el valor de $t0
    lw $a2, 4($sp) # recuperamos el valor de v2
    lw $a1, 8($sp) # recuperamos el valor de v1
    lw $a0, 12($sp) # recuperamos el valor de $ra
    lw $ra, 16($sp) # recuperamos el valor de $ra
    add $sp, $sp, 20 # liberamos espacio para guardar el valor de $t0

    addi $a0, $a0, 4 # v1 = v1 + 1
    addi $a1, $a1, 4 # v2 = v2 + 1
    addi $t0, $t0, 1 # i = i + 1
    blt $t0, $a2, For_prod_esc # i < n
  For_prod_esc_fin:

  end_prod_esc:
    mov.s $f0, $f4 # f0 = f4
    jr $ra
prod_esc_fin: # Correcto


Suma_Reverso: # Función que suma a los elementos de un vector el reverso de un segundo vector
              # $a0 V1
              # $a1 v2
              # $a2 n1
  add $sp, $sp, -16
  sw $ra, 12($sp)
  sw $a2, 8($sp)
  sw $a1, 4($sp)
  sw $a0, 0($sp)

  move $a0, $a1
  move $a1, $a2
  jal mirror
  
  lw $a0, 0($sp)
  lw $a1, 4($sp)
  lw $a2, 8($sp)
  lw $ra, 12($sp)
  add $sp, $sp, 16
  
  move $t0, $a0
  move $t1, $a1
  move $t2, $a2
  
  move $t3, $zero
  For_Sum_vec: # for (int i = 0; i < n; i++) {
    mul $t4, $t3, 4 # i * size
    add $t4, $t4, $a0 # t4 = v + i
    l.s $f12, 0($t4) # t5 = v1[i]
    
    mul $t5, $t3, 4 # i * size
    add $t5, $t5, $a1 # t4 = v + i
    l.s $f14, 0($t5) # t5 = v2[i]
    
    add.s $f4, $f12, $f14
    s.s $f4, 0($t4)
    
    addi $t3, $t3, 1 # i++
    blt $t3, $t2, For_Sum_vec # i < n

  Fin_for_sum_vec: # }
  

  add $sp, $sp, -16
  sw $ra, 12($sp)
  sw $a2, 8($sp)
  sw $a1, 4($sp)
  sw $a0, 0($sp)

  move $a0, $a1
  move $a1, $a2
  jal mirror
  
  lw $a0, 0($sp)
  lw $a1, 4($sp)
  lw $a2, 8($sp)
  lw $ra, 12($sp)
  add $sp, $sp, 16
  
  jr $ra
Suma_Reverso_fin:
  # uso de registros: // al ser simple precison podemos usar 32 registros de flotantes
  # $s0: direccion del vector 1
  # $s1: direccion del vector 2
  # $s2: dimension del vector 1
  # $s3: dimension del vector 2
  # $s4: opcion elegida en el menu
main:
  li $v0, 4
  la $a0, title
  syscall
  llenar_vectores:
    # Llenar v1 con valores del 10 al 49
    la  $s0, v1
    lw $s2, n1
    move $t1, $zero # i = 0
    # for (int i = 0; i < 40; i++) {
    For:
      mul $t2, $t1, size # i * size
      add $t2, $t2, $s0 # t2 = v1 + i
      add $t3, $t1, 10 # t3 = v1[i] + 10 + i

      mtc1 $t3, $f4
      cvt.s.w $f4, $f4
      s.s $f4, 0($t2) # v1[i] = t3

      add $t6, $t1, 1 # i++
      move $s2, $t6 # n1 = i
      sw $s2, n1 # n1 = i

      add $t1, $t1, 1 # i++
      blt $t1, maxdim, For # i < n
    Fin_for: # }

    # Llenar v2 con valores del 40 al 1
    la $s1, v2
    lw $s3, n2
    move $t1, $zero # i = 0
    # for (int i = 0; i < 40; i++) {
    For2:
      mul $t2, $t1, size # i * size
      add $t2, $t2, $s1 # t2 = v1 + i
      sub $t3, $t1, 40# t3 = v1[i] + 40 - i
      neg $t3, $t3

      mtc1 $t3, $f4
      cvt.s.w $f4, $f4
      s.s $f4, 0($t2) # v1[i] = t3

      add $t6, $t1, 1 # i++
      move $s3, $t6 # n2 = i
      sw $s3, n2
      
      addi $t1, $t1, 1 # i++
      blt $t1, maxdim, For2 # i < maxdim
    Fin_for2: # }
  llenar_vectores_fin:
  Menu: # Bucle principal del programa
    Show_vectors:
      #std::cout << "Vector con dimension " << n1 << std::endl;
      li $v0, 4
      la $a0, cabvec
      syscall
      li $v0, 1
      move $a0, $s2
      syscall
      li $v0, 4
      la $a0, newline
      syscall
      # print_vec(v1, n1, " ");
      la $a0, v1 # v1
      lw $a1, n1 # n1
      la $a2, space # separador
      jal print_vec # print_vec(v1, n1, " ");
      #std::cout << std::endl;
      li $v0, 4
      la $a0, newline
      syscall

      #std::cout << "Vector con dimension " << n2 << std::endl;
      li $v0, 4
      la $a0, cabvec
      syscall
      li $v0, 1
      move $a0, $s3
      syscall
      li $v0, 4
      la $a0, newline
      syscall
      # print_vec(v2, n2, " ");
      la $a0, v2 # v2
      lw $a1, n2 # n2
      la $a2, space # separador
      jal print_vec # print_vec(v2, n2, " ");
      #std::cout << std::endl;
      li $v0, 4
      la $a0, newline
      syscall
    Show_vectors_fin:
    li $v0, 4
    la $a0, menu
    syscall
    li $v0, 5
    syscall
    move $s0, $v0 # Guardamos la opcion elegida en $s0
    Switch: # Bucle para elegir la opcion elegida
      beq $s0, 1, CambiarDimension # case1
      beq $s0, 2, CambiarElemento # case2
      beq $s0, 3, InvertirVector # case3
      beq $s0, 4, ProductoEscalar # case4
      beq $s0, 5, Modificacion # case5
      beq $s0, 0, FinPrograma # case0
      # default
      li $v0, 4
      la $a0, error_op
      syscall
      j Menu

      CambiarDimension:

        # $t0 = vector     int vector;
        # $t1 = dimencion  int dimension;
        li $v0, 4 #std::cout << "\nElija vector para realizar la operacion (1) para v1 (2) para v2: ";
        la $a0, elige_vec
        syscall
        li $v0, 5 #std::cin >> vector;
        syscall
        move $t0, $v0 # vector = opcion
        if_vec_error: # if (vector <= 0 || vector > 2) {
          blez $t0, Vector_error # vector <= 0
          bgt $t0, 2, Vector_error # vector > 2
        if_vec_error_fin: # }
        li $v0, 4 #std::cout << "\nElija dimension para realizar la operacion: ";
        la $a0, newdim
        syscall
        li $v0, 5 #std::cin >> dimension;
        syscall
        move $t1, $v0 # dimension = opcion

        If_Dimen: # if (dimension <= 0 || dimension > 40) {
          blez $t1, Dimen_error # dimension <= 0
          bgt $t1, maxdim, Dimen_error # dimension > 40
        If_Dimen_fin: # }

        # if (vector == 1) {
        If_Vector: # if (vector == 1) {
          beq $t0, 1, CambiarDimension1 # vector == 1
          beq $t0, 2, CambiarDimension2 # vector == 2
        If_Vector_fin: # }
        #   n1 = dimension;
        CambiarDimension1:
          move $s2, $t1 # n1 = dimension
          sw $s2, n1 # n1 = dimension
          j Menu
        CambiarDimension2:
          move $s3, $t1 # n2 = dimension
          sw $s3, n2 # n2 = dimension
          j Menu
        Vector_error:
          li $v0, 4
          la $a0, error_op
          syscall
          j Menu
        Dimen_error:
          li $v0, 4
          la $a0, error_dim
          syscall
          j Menu
        Dimen_error_fin:
      CambiarDimension_fin:
      # Cambiar dimension de los vectores perfecto

      CambiarElemento:
        # $t0 = vector     int vector;
        # $t1 = posicion  int posicion;
        # $f4 = valor     float valor;
        # std::cout << "\nElija vector para realizar la operacion (1) para v1 (2) para v2: ";
        li $v0, 4
        la $a0, elige_vec
        syscall
        # std::cin >> vector;
        li $v0, 5
        syscall
        move $t0, $v0 # vector = opcion

        if_vec_error2: # if (vector <= 0 || vector > 2) {
          blez $t0, Vector_error2 # vector <= 0
          bgt $t0, 2, Vector_error2 # vector > 2
        if_vec_error2_fin: # }

        # std::cout << "\nElija el indice del elemento a cambiar: ";
        li $v0, 4
        la $a0, elige_elto
        syscall
        # std::cin >> posicion;
        li $v0, 5
        syscall
        move $t1, $v0 # posicion = opcion

        If_bad_pos: # if (vector == 1 && (posicion < 0 || posicion >= n1)) {
          beq $t0, 1, If_bad_pos1 # vector == 1
          beq $t0, 2, If_bad_pos2 # vector == 2
          If_bad_pos1: # if (vector == 1 && (posicion < 0 || posicion >= n1)) {
            bltz $t1, Bad_pos_error # posicion < 0
            bge $t1, $s2, Bad_pos_error # posicion >= n1
            j If_bad_pos_fin
          If_bad_pos1_fin: # }
          If_bad_pos2: # if (vector == 2 && (posicion < 0 || posicion >= n2)) {
            bltz $t1, Bad_pos_error # posicion < 0
            bge $t1, $s3, Bad_pos_error # posicion >= n2
          If_bad_pos2_fin: # }
        If_bad_pos_fin: # }
        # std::cout << "\nElija el valor del elemento a cambiar: ";
        li $v0, 4
        la $a0, newval
        syscall
        # std::cin >> valor;
        li $v0, 6
        syscall
        mov.s $f4, $f0 # valor = opcion
        # if (vector == 1) {
        If_Vector2: # if (vector == 1) {
          beq $t0, 1, CambiarElemento1 # vector == 1
          beq $t0, 2, CambiarElemento2 # vector == 2
        If_Vector2_fin: # }

        CambiarElemento1:
          la $a0, v1 # $a0 = v1
          move $a1, $t1;
          mov.s $f0, $f4 # $a2 = posicion
          jal change_elto
          j Menu
        CambiarElemento1_fin:
        CambiarElemento2:
          la $a0, v2 # $a0 = v2
          move $a1, $t1;
          mov.s $f0, $f4 # $a2 = posicion
          jal change_elto
          j Menu
        CambiarElemento2_fin:

        Bad_pos_error:
          li $v0, 4
          la $a0, error_ind
          syscall
          j Menu
        Bad_pos_error_fin:
        Vector_error2:
          li $v0, 4
          la $a0, error_op
          syscall
          j Menu
        Vector_error2_fin:
      CambiarElemento_fin:
      # Cambiar elemento de los vectores perfecto

      InvertirVector:
        # $t0 = vector     int vector;
        # std::cout << "\nElija vector para realizar la operacion (1) para v1 (2) para v2: ";
        li $v0, 4
        la $a0, elige_vec
        syscall
        # std::cin >> vector;
        li $v0, 5
        syscall
        move $t0, $v0 # vector = opcion
        If_Vector3: # if (vector <= 0 || vector > 2) {
          blez $t0, Vector_error3 # vector <= 0
          bgt $t0, 2, Vector_error3 # vector > 2
        If_Vector3_fin: # }
        # if (vector == 1) {
        If_Vector4: # if (vector == 1) {
          beq $t0, 1, InvertirVector1 # vector == 1
          beq $t0, 2, InvertirVector2 # vector == 2
        If_Vector4_fin: # }
        
        InvertirVector1:
          la $a0, v1 # $a0 = v1
          lw $a1, n1 # $a1 = n1
          jal mirror
          j Menu
        InvertirVector1_fin:
        InvertirVector2:
          la $a0, v2 # $a0 = v2
          lw $a1, n2 # $a1 = n2
          jal mirror
          j Menu
        InvertirVector2_fin:

        Vector_error3:
          li $v0, 4
          la $a0, error_op
          syscall
          j Menu
        Vector_error3_fin:
      InvertirVector_fin:
      # Invertir vector perfecto

      ProductoEscalar:
        # $f12 = resultado
        If_not_equal: # if (n1 != n2) {
          bne $s2, $s3, error_prod # n1 != n2
        If_not_equal_fin: # }

        la $a0, v1 # $a0 = v1
        la $a1, v2 # $a1 = v2
        lw $a2, n1 # tamaño de los vectores
        jal prod_esc

        mov.s $f12, $f0 # producto = $f0

        li $v0, 4
        la $a0, msg_prodesc
        syscall
        li $v0, 2
        syscall

        j Menu

        error_prod:
          li $v0, 4
          la $a0, error_d_dim
          syscall
          j Menu
        error_prod_fin:
      ProductoEscalar_fin:
      
      # Modificacion
      Modificacion:
        lw $s2, n1
        lw $s3, n2
        If_not_equal3: # if (n1 != n2) {
          bne $s2, $s3, error_mod # n1 != n2
        If_not_equal3_fin: # }

        la $a0, v1 # $a0 = v1
        la $a1, v2 # $a1 = v2
        lw $a2, n1 # tamaño de los vectores
        jal Suma_Reverso
        
        j Menu
        
        error_mod:
          li $v0, 4
          la $a0, error_d_dim
          syscall
          j Menu
        error_mod_fin:
      Modificacion_fin:
    Switch_fin:
  Menu_fin:
FinPrograma:
li $v0, 4
la $a0, msg_fin
syscall
li $v0, 10
syscall
