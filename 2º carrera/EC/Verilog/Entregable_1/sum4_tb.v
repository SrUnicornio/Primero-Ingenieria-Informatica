// Testbench para sumador con prediccion de acarreo
`timescale 1 ns / 10 ps //Directiva que fija la unidad de tiempo de simulacion y el del paso de simulacion
module sum4_tb;

//declaracion de senales
reg[3:0] test_A, test_B;
reg test_c_in;
wire[3:0] test_S;
wire test_C_out;

//instancia del modulo a testear
sum4 sum(test_S, test_C_out, test_A, test_B, test_c_in);

initial
begin
  $monitor("tiempo=%0d A=%b B=%b cin=%b S=%b cout=%b", $time, test_A, test_B, test_c_in, test_S, test_C_out);
  $dumpfile("sum4_tb.vcd");
  $dumpvars;
  //Algunos valores de prueba
  test_c_in = 1'b1;
  test_A = 4'b0000;
  test_B = 4'b0000;
  # 20;
  
  test_c_in = 1'b0;
  test_A = 4'b1111;
  test_B = 4'b0001;
  # 20;
  
  test_c_in = 1'b1;
  test_A = 4'b1111;
  test_B = 4'b1111;
  # 20;
 
  test_c_in = 1'b1;
  test_A = 4'b0000;
  test_B = 4'b1111;
  # 20;
  
  test_c_in = 1'b0;
  test_A = 4'b0101;
  test_B = 4'b1010;
  # 20;
  
  //fin simulacion
  $finish;
end

endmodule
