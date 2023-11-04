//Sumador completo (full-adder) de tres entradas de 1 bit realizado a partir de puertas logicas 
module fa_v1(output wire sum, output wire c_out, input wire a, input wire b, input wire c_in);
  
  wire carry_ha1;
  wire carry_ha2;
  wire sum_ha1;

  ha_v1 ha1(sum_ha1, carry_ha1, a, b);
  ha_v1 ha2(sum, carry_ha2, c_in, sum_ha1);
  or or1(c_out, carry_ha1, carry_ha2);

endmodule
