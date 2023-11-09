//ffT_preset
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity ffT_preset is
	Port ( preset : in STD_LOGIC;
			 clk : in STD_LOGIC;
			 ce : in STD_LOGIC;
			 t : in STD_LOGIC;
			 q : out STD_LOGIC);
end ffT_preset;

architecture Behavioral of ffT_preset is

	signal q_int : std_logic;

begin

process (clk, preset)
begin
	if preset='1' then
		q_int <= '0';
	 elsif (clk'event and clk='1') then
		 if ce = '1' then
			 if t = '1' then
				q_int <= not q_int;
			 end if;
		 end if;
	 end if;
end process;
q <= q_int;
end Behavioral;