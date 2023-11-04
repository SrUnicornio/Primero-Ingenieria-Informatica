// Multiplexor 4 a 1 de 1 bit realizado a partir de puertas

module mux4_1(output reg out, input wire a, b, c, d, input wire [1:0] S);

  always @(*)
  begin
  case(S)
    2'b00: out = a;
    2'b01: out = b;
    2'b10: out = c;
    2'b11: out = d;
  endcase
  end

endmodule