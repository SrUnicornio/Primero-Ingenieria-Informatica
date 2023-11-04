// Complementar o no a voluntad,  de forma que podamos dejar pasar un dato sin modificar o hacer su complemento a uno

module compl1(output wire [3:0] Out, input wire [3:0] Inp, input wire cpl);

  assign Out = cpl ? ~Inp : Inp;

endmodule