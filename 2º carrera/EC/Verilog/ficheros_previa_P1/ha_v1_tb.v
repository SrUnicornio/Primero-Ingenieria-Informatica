// Testbench para modulo semisumador visto antes

`timescale 1 ns / 10 ps //Directiva que fija la unidad de tiempo de simulacion y el paso de simulacion

module ha_v1_tb;
  //declaracion de senales

  reg test_a, test_b; //las senales de entrada al semisumador. Se han declarado reg porque queremos inicializarlas
  wire test_sum, test_carry; //senales de salida, se declaran como wire porque sus valores se fijan por el semisumador

  //instancia del modulo a testear, con notacion de posiciones de argumentos 
  ha_v1 ha1(test_sum, test_carry, test_a, test_b);

  //Lo siguiente comentado es una notacion alternativa para instanciar el modulo, los parametros se denotan con un punto seguido del
  //nombre del parametro en la definicion original del modulo y entre parentesis a que se conecta en el modulo actual
  //no importa el orden de los parametros definidos asi -?
  //ha_v1 ha1(.a(test_a), .b(test_b), .sum(test_sum), .carry(test_carry)); 


  initial
  begin
    $monitor("tiempo=%0d a=%b b=%b suma=%b acarreo=%b", $time, test_a, test_b, test_sum, test_carry);
    $dumpfile("ha_v1_tb.vcd");
    $dumpvars;

    //vector de test 0
    test_a = 1'b0;
    test_b = 1'b0;
    #20;

    //vector de test 1
    test_a = 1'b0;
    test_b = 1'b1;
    #20;

    //vector de test 2
    test_a = 1'b1;
    test_b = 1'b0;
    #20;
    //vector de test 3
    test_a = 1'b1;
    test_b = 1'b1;
    #20;
    
    $finish;  //fin simulacion

  end
endmodule
