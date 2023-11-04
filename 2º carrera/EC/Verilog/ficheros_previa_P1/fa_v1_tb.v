//Test bench
//fa_v1_tb.v
//Se diferencia de fa_v1.v en que no tiene salidas

`timescale 1ns/10ps

module fa_v1_tb;
  reg t_a, t_b, t_c_in;
  wire t_sum,t_carry_c_out;

  //Vamos a declara el módulo fa_v1 en el tb con un initial

  fa_v1 fa1(t_sum, t_carry_c_out, t_a, t_b, t_c_in);
    initial 
      begin
        //Vamos a hacer un test bench para el sumador completo
        t_a = 0;
        t_b = 0;
        t_c_in = 0;
        #10;

        t_a = 0;
        t_b = 0;
        t_c_in = 1;
        #10;

        t_a = 0;
        t_b = 1;
        t_c_in = 0;
        #10;

        t_a = 0;
        t_b = 1;
        t_c_in = 1;
        #10;

        t_a = 1;
        t_b = 0;
        t_c_in = 0;
        #10;

        t_a = 1;
        t_b = 0;
        t_c_in = 1;
        #10;

        t_a = 1;
        t_b = 1;
        t_c_in = 0;
        #10;

        t_a = 1;
        t_b = 1;
        t_c_in = 1;
        #10;

        $finish;

      end

endmodule

//Compilar iverilog -o fa fa_v1_tb.v fa_v1.v ha_v1_1.v