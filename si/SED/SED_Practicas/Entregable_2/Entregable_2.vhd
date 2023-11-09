// Contador aleatorio ciclico (8,0,3,2,7,4,9,1,6,5)

library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity Entregable_2 is
    Port ( clk : in  STD_LOGIC;
           reset : in  STD_LOGIC;
           ce : in  STD_LOGIC;
           count : out  STD_LOGIC_VECTOR (3 downto 0));
end Entregable_2;

architecture Behavioral of Entregable_2 is

	COMPONENT ffD_preset
	PORT(
		clk : IN std_logic;
		preset : IN std_logic;
		ce : IN std_logic;
		d : IN std_logic;          
		q : OUT std_logic
		);
	END COMPONENT;
	
	COMPONENT ffD_reset
	PORT(
		clk : IN std_logic;
		reset : IN std_logic;
		ce : IN std_logic;
		d : IN std_logic;          
		q : OUT std_logic
		);
	END COMPONENT;
	
	COMPONENT ffT_reset
	PORT(
		reset : IN std_logic;
		clk : IN std_logic;
		ce : IN std_logic;
		t : IN std_logic;          
		q : OUT std_logic
		);
	END COMPONENT;
	
	signal qa, qb, qc, qd : std_logic;
	signal da, db, tc, td : std_logic;

begin
	unit_A: ffD_preset PORT MAP(
		clk => clk,
		preset => reset,
		ce => ce,
		d => da,
		q => qa);
	unit_B: ffD_reset PORT MAP(
		clk => clk,
		reset => reset,
		ce => ce,
		d => db,
		q => qb );
	unit_C: ffT_reset PORT MAP(
		reset => reset,
		clk => clk,
		ce => ce,
		t => tc,
		q => qc );
	unit_D: ffT_reset PORT MAP(
		reset => reset,
		clk => clk,
		ce => ce,
		t => td,
		q => qd);
		
	da <= (qb and not qc);
	db <= ((qc and not qd) or (qb and qc) or (not qa and not qb and not qc and qd));
	tc <= ((qb and qc) or (not qa and not qb and not qc));
	td <= not qa;
	
	count <= qa & qb & qc & qd;


end Behavioral;

