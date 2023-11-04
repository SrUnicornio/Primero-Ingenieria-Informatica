module mux2_1_i4(output reg out, input wire a, b, s);
// mux con construcción always (procedural), las asignaciones deben ser a variables con estado ('out' ahora es tipo reg)
// en el caso de un modulo combinacional, se debe usar la asignación procedural 'con bloqueo' que equivale al "=" de C  

always @(a or b or s) //alternativamente, always @(a, b, s) o always @* (automático, considera todas las var)
                      //no hace falta begin...end porque el always contiene una sola sentencia, el case
  case (s)              
    0: out = a;
    1: out = b;
    default: out = 'bx; //desconocido en cualquier otro caso (x ó z), no se especifica el tamaño en la cte, si 'out' fuera mayor
                        // de un bit, el bit más sigificativo si es x ó z se extiende hasta completar el tamaño total
  endcase
  
endmodule
