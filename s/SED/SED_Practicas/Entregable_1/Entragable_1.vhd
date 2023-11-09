library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
entity Entregable_1 is
	Port ( a : in  STD_LOGIC;
       	b : in  STD_LOGIC;
       	c : in  STD_LOGIC;
       	d : in  STD_LOGIC;
       	f1_C63B : out  STD_LOGIC;
       	f2_753E : out  STD_LOGIC);
end Entregable_1;
architecture Behavioral of Entregable_1 is
begin
 	f1_C63B <= (not a and not c) or (not a and not b and d) or (not b and not c and not d) or (a and c and not d) or (a and b and c);
 	f2_753E <= ((b and not c) or (a and not d) or (not a and not b and d) or (not a and not b and c));
end Behavioral;
