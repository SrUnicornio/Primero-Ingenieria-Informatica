// Celda logica

module cl(output wire out, input wire a, b, input wire [1:0] S);

  // Declaramos las conexiones internas
  wire out_and, out_or, out_xor, out_not;

  // Instanciamos las puertas
  and and1 (out_and, a, b);
  or or1 (out_or, a, b);
  xor xor1 (out_xor, a, b);
  not not1 (out_not, a);

  // Instanciamos en el mux 4 a 1
  mux4_1 mux1 (out, out_and, out_or, out_xor, out_not, S);

endmodule