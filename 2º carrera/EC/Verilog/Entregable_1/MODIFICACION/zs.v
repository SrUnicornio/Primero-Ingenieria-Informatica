module zs (output reg zero, sign, input wire[3:0] R);

  always @(R) 
  begin
    zero = ~|R;
    sign = R[3];
  end

endmodule