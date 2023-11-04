//Semisumador de dos entradas de 1 bit realizado a partir sentencias assign

module ha_v2(output wire sum, output wire carry, input wire a, input wire b);

// semisumador con asignaciones continuas (assign)

assign sum = a ^ b;	//operador xor (bit a bit)
assign carry = a & b;	//operador and (bit a bit)

endmodule

