`timescale 1 ns / 10 ps //Directiva que fija la unidad de tiempo de simulaci�n y el paso de simulaci�n

module mux4_1_tb;
//declaracion de se�ales

reg a, b, c, d; //las se�ales de entrada al semisumador. Se han declarado reg porque queremos inicializarlas
reg[1:0] S;
wire out;
integer i;

//instancia del modulo a testear, con notaci�n de posiciones de argumentos 
mux4_1 mux(out, a, b, c, d, S);

//Lo siguiente comentado es una notaci�n alternativa para instanciar el m�dulo, los par�metros se denotan con un punto seguido del
//nombre del par�metro en la definici�n original del m�dulo y entre par�ntesis a qu� se conecta en el modulo actual
//no importa el orden de los par�metros definidos as� -?
//ha_v1 ha1(.a(test_a), .b(test_b), .sum(test_sum), .carry(test_carry)); 


initial
begin
  $monitor("tiempo=%0d d=%b c=%b b=%b a=%b S1=%b S0=%b out=%b", $time, d, c, b, a, S[1], S[0], out);
  $dumpfile("mux4_1_tb.vcd");
  $dumpvars;

  a = 1'b0;
  b = 1'b0;
  c = 1'b0;
  d = 1'b0;
  S[0] = 1'b0;
  S[1] = 1'b0;
  #5;

  //vector de test 0

  for (i = 6'd1; i < 64; i = i + 1) begin
    S[0] = ~S[0];
    if (i % 2 == 0) begin
      S[1] = !S[1];
    end
    if (i % 4 == 0) begin
      a = !a;
    end
    if (i % 8 == 0) begin
      b = !b;
    end
    if (i % 16 == 0) begin
      c = !c;
    end
    if (i % 32 == 0) begin
      d = !d;
    end
    #5;
  end
    
  $finish;  //fin simulacion

end
endmodule
