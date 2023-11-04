//  Multiplexor de 2 entradas a una salida en el que las entradas son de 4 bits. 

module mux2_4(output wire [3:0] Out, input wire [3:0] A, input wire [3:0] B, input wire s);
  
  assign Out = s ? B : A;

endmodule