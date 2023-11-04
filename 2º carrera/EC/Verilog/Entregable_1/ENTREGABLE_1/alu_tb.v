// Testbench para modulo alu
`timescale 1 ns / 10 ps //Directiva que fija la unidad de tiempo de simulación y la precision de la unidad
module alu_tb;
//declaracion de señales
reg [1:0] t_Op;
reg t_l, t_cin;
reg [3:0] t_A, t_B; 
wire [3:0] t_R;
wire t_z, t_c, t_s;
integer errores;

// error de cualquier tipo, de resultado, de linea zero, de signo y carry
reg error, error_R, error_z, error_s, error_c; 

//instancia del modulo a testear
alu mat(t_R, t_z, t_c, t_s, t_A, t_B, t_cin, t_Op, t_l);


initial
begin
	$dumpfile("alu.vcd");
	$dumpvars;

	errores = 0;
	t_l = 1'b0;
	repeat(2)
	begin
		t_Op = 2'b0;
		repeat(4)
		begin
			t_cin = 1'b0;
			repeat(2)
			begin
		    	t_A = 4'b0;
		    	repeat(16) 
		    	begin
					t_B = 4'b0;
					repeat(16) 
			  		begin
						#0.01 check;
						#9.99;
						t_B = t_B + 1;
			  		end
			  		t_A = t_A + 1;
		    	end
				t_cin = t_cin + 1;
			end
			t_Op = t_Op + 1;
		end
		t_l = t_l + 1;
	end
	$display("Encontradas %d operaciones erroneas", errores);
  	//fin simulacion
  	$finish;
end

// Tarea para hacer la comprobación automática de resultados
task check;
reg [4:0] expected_R;
reg expected_z, expected_c, expected_s;

begin
	$write("tiempo=%0d A=%b B=%b c_in=%b L=%b OP=%b R=%b, Z=%b, C=%b, S=%b.", $time, t_A, t_B, t_cin, t_l, t_Op, t_R, t_z, t_c, t_s);

	// Si las operaciones son lógicas
	if (t_l)
	begin
		case (t_Op)
			2'b00: expected_R[3:0] = t_A & t_B;
			2'b01: expected_R[3:0] = t_A | t_B;
			2'b10: expected_R[3:0] = t_A ^ t_B;
			2'b11: expected_R[3:0] = ~t_A;
			default: $display("ERROR. Valor no esperado para t_Op: %b", t_Op);
		endcase
		// Se establece a 0, pero realmente es un "don't care"
		expected_c = 1'b0;
		expected_s = expected_R[3];
		// las operaciones lógicas no pueden tener error de signo o acarreo
		error_s = 0;
	 	error_c = 0;
	end
	else
	begin
		case (t_Op)
			2'b00: expected_R = t_A + t_cin;
			2'b01: expected_R = (t_A ^4'b1111) + 4'b0001 + t_cin;
			2'b10: expected_R = t_A + t_B + t_cin;
			2'b11: expected_R = t_A + 1 + t_cin;
			default: $display("ERROR. Valor no esperado para t_Op: %b", t_Op);
		endcase
		expected_c = expected_R[4];
		expected_s = expected_R[3];
		// generacion señales error específicas operaciones aritmeticas
		error_s = (expected_s !== t_s);
	 	error_c = (expected_c !== t_c);
	end

	expected_z = ~| expected_R[3:0];
	// generacion señales error generales para toda la ALU
	error_R = (expected_R[3:0] !== t_R); 
	error_z = (expected_z !== t_z);
	error = error_R | error_z | error_s | error_c;
	if (error)
	begin
		errores = errores + 1;
		$display(" ---- ERROR");
		if (error_R)
			$display("\tResultado esperado %b, obtenido %b", expected_R[3:0], t_R);
		if (error_z)
			$display("\tFlag de cero esperado %b, obtenido %b", expected_z, t_z);
		if (error_s)
			$display("\tFlag de signo esperado %b, obtenido %b", expected_s, t_s);
		if (error_c)
			$display("\tFlag de acarreo esperado %b, obtenido %b", expected_c, t_c);
	end
	else
		$display(" ---- OK");
end
endtask
endmodule