`timescale 1ns / 10ps

module compl1_tb;

    // Declaración de señales
    reg [3:0] t_Inp;
    reg t_cpl;
    wire [3:0] t_Out;

    // Instancia del módulo a testear
    compl1 mat(t_Out, t_Inp, t_cpl);

    initial begin
        // Habilita el monitor para mostrar las señales en la simulación
        $monitor("tiempo=%0d Inp=%b cpl=%b Out=%b", $time, t_Inp, t_cpl, t_Out);

        // Abre el archivo de volcado VCD para simulación
        $dumpfile("compl1_tb.vcd");
        $dumpvars;

        // Prueba 1: Inp = 0000, cpl = 1
        t_Inp = 4'b0000;
        t_cpl = 1;
        #10;
        // Deberíamos obtener el complemento a uno de 0000, que es 1111

        // Prueba 2: Inp = 1100, cpl = 1
        t_Inp = 4'b1100;
        t_cpl = 1;
        #10;
        // Deberíamos obtener el complemento a uno de 1100, que es 0011

        // Prueba 3: Inp = 1111, cpl = 0
        t_Inp = 4'b1111;
        t_cpl = 0;
        #10;
        // Deberíamos obtener la salida igual a la entrada, que es 1111

        // Prueba 4: Inp = 0101, cpl = 1
        t_Inp = 4'b0101;
        t_cpl = 1;
        #10;
        // Deberíamos obtener el complemento a uno de 0101, que es 1010

        // Fin de la simulación
        $finish;
    end

endmodule
