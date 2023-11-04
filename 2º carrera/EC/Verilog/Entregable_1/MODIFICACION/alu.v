// Implementación de la ALU en Verilog

module alu(output wire [3:0] R, output wire zero, c_out, sign, input wire [3:0] A, B, 
          input wire c_in, input wire [1:0] ALUOP, input wire l);

 // Declaramos las conexiones internas
  wire [3:0] OP1, OP2;
  wire [3:0] out_mux_1, out_mux_2;
  wire [3:0] out_sum4_1, out_ul4_1;

  // Asignación de las entradas de los multiplexores y el complemento
  wire cpl, add1, op1_A, op2_B;

  assign add1 = (~ALUOP[1] & ALUOP[0]);
  assign op1_A = ((l) | (ALUOP[1] & ~ALUOP[0]));
  assign op2_B = (l | ALUOP[1]);
  assign cpl = (~l & ALUOP[0]);

  // Declaramos los módulos que vamos a utilizar
  mux2_4 mux1 (out_mux_1, A, B, op2_B);
  compl1 compl (OP2, out_mux_1, cpl);

  mux2_4 mux2 (out_mux_2, 4'b0000, 4'b0001, add1);
  mux2_4 mux3 (OP1, out_mux_2, A, op1_A);
  
  //sum4 sum (out_sum4_1, c_out, OP1, OP2, c_in);
  sum4_v2 sum (out_sum4_1, c_out, OP1, OP2, c_in);
  ul4 ul (out_ul4_1, OP1, OP2, ALUOP);
  mux2_4 mux4 (R, out_sum4_1, out_ul4_1, l);

  // Asignamos las salidas
  zs zero_sign (zero, sign, R);
  

endmodule

/**
 * Compilación y ejecución de la simulación
 * iverilog iverilog -o alu alu_tb.v alu.v mux2_4.v compl1.v sum4.v fa_v1.v ul4.v cl.v mux4_1.v
 * iverilog iverilog -o alu alu_tb.v alu.v mux2_4.v compl1.v sum4_v2.v ul4.v cl.v mux4_1.v
 * vvp alu | grep -E -A10 "ERROR|operaciones" | grep -v OK > error.txt
 * Rediriigimos la salida a un fichero para poder analizarla solo con los errores en caso de que los haya
 * Visualizamos los resultados: gtkwave alu.vcd
*/
