//Semisumador de dos entradas de 1 bit realizado a partir de assign,
// operador concatenación y operador suma

module ha_v3(output wire sum, output wire carry, input wire a, input wire b);

assign {carry, sum} = a + b;	//operador suma junto con operador concatenación 

endmodule

