//Sumador de 4 bits que no use fa_v1 de 1 bit, sino una asignacion continua y operador concatenacion
module sum4_v2(output wire[3:0] S, output wire c_out, input wire[3:0] A, input wire[3:0] B, input wire c_in);
	
  // Asignamos las salidas
  assign S = A + B + c_in;
  assign c_out = (c_in & A) | (c_in & B) | (A & B);

endmodule
