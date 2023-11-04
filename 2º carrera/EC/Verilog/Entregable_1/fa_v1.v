//Sumador completo (full-adder) de tres entradas de 1 bit realizado a partir de puertas logicas 
module fa(output wire c_out, sum, input wire a, b, c_in); 

  assign {cout, sum} = a + b + cin; 

endmodule
