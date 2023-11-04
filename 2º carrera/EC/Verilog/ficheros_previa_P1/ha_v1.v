//Semisumador de dos entradas de 1 bit realizado a partir de puertas

module ha_v1(output wire sum, output wire carry, input wire a, input wire b);

//Declaracion de conexiones internas: no hay ninguna

//Estructura interna: Instancias de puertas y sus conexiones

xor xor1(sum, a, b);
and and1(carry, a, b);

endmodule
