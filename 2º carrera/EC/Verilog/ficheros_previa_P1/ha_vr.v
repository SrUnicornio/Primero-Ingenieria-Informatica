//Semisumador de dos entradas de 1 bit realizado a partir de puertas
module ha_vr(output wire sum, carry, input wire a, b);

//Declaracion de conexiones internas: no hay ninguna

//Estructura interna: Instancias de puertas y sus conexiones, se incluyen retardos
xor #1 xor1(sum, a, b); //el retardo va entre el nombre del modulo (solo en primitivas) y el de la instancia
and #1 and1(carry, a, b);

endmodule
