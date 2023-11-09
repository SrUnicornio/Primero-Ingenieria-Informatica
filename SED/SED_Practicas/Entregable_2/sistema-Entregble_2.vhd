library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity sistema-Entregable_2 is
    Port ( clk : in  STD_LOGIC;
           ce : in  STD_LOGIC;
           reset : in  STD_LOGIC;
           count : inout  STD_LOGIC_VECTOR (3 downto 0);
           led : out  STD_LOGIC_VECTOR (6 downto 0));
end sistema-Entregable_2;

architecture Behavioral of sistema-Entregable_2 is
	
	COMPONENT Entregable_2
	PORT(
		clk : IN std_logic;
		reset : IN std_logic;
		ce : IN std_logic;          
		count : OUT std_logic_vector(3 downto 0)
		);
	END COMPONENT;
	
	COMPONENT dec7seg
	PORT(
		bcd : IN std_logic_vector(3 downto 0);          
		led : OUT std_logic_vector(6 downto 0)
		);
	END COMPONENT;
	
	signal int : std_logic_vector(3 downto 0);

begin
	
	Inst_Entregable_2: Entregable_2 PORT MAP(
		clk => clk,
		reset => reset,
		ce => ce,
		count => int );

	Inst_dec7seg: dec7seg PORT MAP(
		bcd => int,
		led => led );
		
	count <= int;
end Behavioral;

