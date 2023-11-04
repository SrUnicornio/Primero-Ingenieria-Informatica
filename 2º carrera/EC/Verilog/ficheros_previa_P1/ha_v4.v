//Semisumador de dos entradas de 1 bit realizado con sentencia always

module ha_v4(output reg sum, output reg carry, input wire a, input wire b);

// construcción always (procedural), las asignaciones deben ser a variables con
// estado ('sum' y ‘carry’ ahora son de tipo reg)

always @(a, b) //alternativamente, always @(a or b)
               // o always @* (automático, considera todas las var. que intervienen)
begin  //always
  sum = a ^ b;
  carry = a & b;
end    //always

endmodule
