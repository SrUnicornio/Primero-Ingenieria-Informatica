`timescale 1 ns / 10 ps //Directiva que fija la unidad de tiempo de simulaci�n y el paso de simulaci�n

module mux2_4_tb;
//declaracion de se�ales

reg[3:0] A, B; //las se�ales de entrada al semisumador. Se han declarado reg porque queremos inicializarlas
reg s;
wire[3:0] Out;
integer i;

//instancia del modulo a testear, con notaci�n de posiciones de argumentos 
mux2_4 mux(Out, A, B, s);

//Lo siguiente comentado es una notaci�n alternativa para instanciar el m�dulo, los par�metros se denotan con un punto seguido del
//nombre del par�metro en la definici�n original del m�dulo y entre par�ntesis a qu� se conecta en el modulo actual
//no importa el orden de los par�metros definidos as� -?
//ha_v1 ha1(.a(test_a), .b(test_b), .sum(test_sum), .carry(test_carry)); 


initial
begin
  $monitor("tiempo=%0d B=%b A=%b s=%b Out=%b", $time, B, A, s, Out);
  $dumpfile("mux2_4_tb.vcd");
  $dumpvars;

  A = 4'b0000;
  B = 4'b0000;
  s = 1'b0;
  #5;

  //vector de test 0

  for (i = 6'd1; i < 32; i = i + 1) begin
    s = ~s;
    if (i % 2 == 0) begin
      A[0] = ~A[0];
    end
    if (i % 4 == 0) begin
      B[0] = ~B[0];
    end
    if (i % 8 == 0) begin
      A[1] = ~A[1];
    end
    if (i % 16 == 0) begin
      B[1] = ~B[1];
    end
    #5;
  end
    
  $finish;  //fin simulacion

end
endmodule
