`timescale 1 ns / 10 ps //Directiva que fija la unidad de tiempo de simulaci�n y el paso de simulaci�n

module ul4_tb;
//declaracion de se�ales

reg[3:0] A, B; //las se�ales de entrada al semisumador. Se han declarado reg porque queremos inicializarlas
reg[1:0] S;
wire[3:0] Out;
integer i;

//instancia del modulo a testear, con notaci�n de posiciones de argumentos 
ul4 ul(Out, A, B, S);

//Lo siguiente comentado es una notaci�n alternativa para instanciar el m�dulo, los par�metros se denotan con un punto seguido del
//nombre del par�metro en la definici�n original del m�dulo y entre par�ntesis a qu� se conecta en el modulo actual
//no importa el orden de los par�metros definidos as� -?
//ha_v1 ha1(.a(test_a), .b(test_b), .sum(test_sum), .carry(test_carry)); 


initial
begin
  $monitor("tiempo=%0d B=%b A=%b S1=%b S0=%b Out=%b", $time, B, A, S[1], S[0], Out);
  $dumpfile("ul4_tb.vcd");
  $dumpvars;

  A = 4'b0;
  B = 4'b0;
  S[0] = 1'b0;
  S[1] = 1'b0;
  #5;

  //vector de test 0

  for (i = 10'd1; i < 1024; i = i + 1) begin
    S[0] = ~S[0];
    if (i % 2 == 0) begin
      S[1] = !S[1];
    end
    if (i % 4 == 0) begin
      A[0] = !A[0];
    end
    if (i % 8 == 0) begin
      B[0] = !B[0];
    end
    if (i % 16 == 0) begin
      A[1] = !A[1];
    end
    if (i % 32 == 0) begin
      B[1] = !B[1];
    end
    if (i % 64 == 0) begin
      A[2] = !A[2];
    end
    if (i % 128 == 0) begin
      B[2] = !B[2];
    end
    if (i % 256 == 0) begin
      A[3] = !A[3];
    end
    if (i % 512 == 0) begin
      B[3] = !B[3];
    end
    #5;
  end
    
  $finish;  //fin simulacion

end
endmodule
