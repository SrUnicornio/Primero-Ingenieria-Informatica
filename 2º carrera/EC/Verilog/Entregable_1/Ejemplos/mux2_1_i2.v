module mux2_1_i2(output wire out, input wire a, b, s);
// mux con asignación continua

assign out = s ? b : a; //oper. condicional de C, sintaxis [condicion ? valor_si_cierta : valor_si_falsa] 

endmodule
