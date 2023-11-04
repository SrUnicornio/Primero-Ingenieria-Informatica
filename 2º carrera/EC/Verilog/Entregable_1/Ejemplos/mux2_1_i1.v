//Mux de dos entradas de 1 bit realizado a partir de puertas 
module mux2_1_i1(output wire out, input wire a, b, s);

//Declaración de conexiones internas
wire  s_n, sa, sb;	   

//Instancias de puertas y sus conexiones
not inv1 (s_n, s);
and and1 (sa, a, s_n);
and and2 (sb, b, s);
or or1 (out, sa, sb);

endmodule
