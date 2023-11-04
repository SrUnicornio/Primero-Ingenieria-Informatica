//Sumador de 4 bits  de forma estructural utilizando los fa_v1
module sum4(output wire[3:0] S, output wire c_out, 
						input wire[3:0] A, input wire[3:0] B, input wire c_in);
	
	// Declaramos las conexiones internas
	wire c1, c2, c3, c4;
	wire s0, s1, s2, s3;

	// Instanciamos los fa_v1
	fa fa1 (s0, c1, A[0], B[0], c_in);
	fa fa2 (s1, c2, A[1], B[1], c1);
	fa fa3 (s2, c3, A[2], B[2], c2);
	fa fa4 (s3, c4, A[3], B[3], c3);

	// Asignamos las salidas
	assign S[0] = s0, S[1] = s1, S[2] = s2, S[3] = s3;
	assign c_out = c4;

endmodule

