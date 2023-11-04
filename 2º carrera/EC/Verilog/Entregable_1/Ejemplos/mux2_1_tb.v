// Testbench para modulos mux2_1
`timescale 1 ns / 10 ps //Directiva que fija la unidad de tiempo de simulación y el del paso de simulacion
module mux2_1_tb;
//declaracion de señales
reg test_s, test_a, test_b;
wire test_out;

//instancia del modulo a testear, con notación de posiciones de argumentos y con notación de nombres
mux2_1_i4 mat( test_out, test_a, test_b, test_s);
//mux2_1_i1 mat(.a(test_a), .b(test_b), .s(test_s), .out(test_out));

initial
begin
  $monitor("tiempo=%0d s=%b a=%b b=%b out=%b", $time, test_s, test_a, test_b, test_out);
  //vector de test 0
  test_s = 1'b0;
  test_a = 1'b0;
  test_b = 1'b0;
  # 20;
  //vector de test 1
  test_s = 1'b0;
  test_a = 1'b0;
  test_b = 1'b1;
  # 20;
  //vector de test 2
  test_s = 1'b0;
  test_a = 1'b1;
  test_b = 1'b0;
  # 20;
  //vector de test 3
  test_s = 1'b0;
  test_a = 1'b1;
  test_b = 1'b1;
  # 20;
  //vector de test 4
  test_s = 1'b1;
  test_a = 1'b0;
  test_b = 1'b0;
  # 20;
  //vector de test 5
  test_s = 1'b1;
  test_a = 1'b0;
  test_b = 1'b1;
  # 20;
  //vector de test 6
  test_s = 1'b1;
  test_a = 1'b1;
  test_b = 1'b0;
  # 20;
  //vector de test 7
  test_s = 1'b1;
  test_a = 1'b1;
  test_b = 1'b1;

  //fin simulacion
  $finish;
end

endmodule
