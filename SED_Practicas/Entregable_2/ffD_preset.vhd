// ffD_preset
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity ffD_preset is
    Port ( clk : in  STD_LOGIC;
           preset : in  STD_LOGIC;
           ce : in  STD_LOGIC;
           d : in  STD_LOGIC;
           q : out  STD_LOGIC);
end ffD_preset;

architecture Behavioral of ffD_preset is

begin

process (clk, preset)
begin
	 if preset='1' then
		q <= '1';
	 elsif (clk'event and clk='1') then
		if ce = '1' then
			q <= d;
		end if;
	 end if;
end process;

end Behavioral;