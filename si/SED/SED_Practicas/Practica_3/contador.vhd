library IEEE;
use IEEE.STD_LOGIC_1164.ALL;


entity contador is
    Port ( clk : in  STD_LOGIC;
           reset : in  STD_LOGIC;
           ce : in  STD_LOGIC;
           count : out  STD_LOGIC_VECTOR (3 downto 0));
end contador;

architecture Behavioral of contador is

	COMPONENT ffD_reset
	PORT(
		clk : IN std_logic;
		reset : IN std_logic;
		ce : IN std_logic;
		d : IN std_logic;          
		q : OUT std_logic
		);
	END COMPONENT;
	
	signal qa, qb, qc, qd : std_logic;
	signal da, db, dc, dd : std_logic;

begin
	unit_A: ffD_reset PORT MAP(
		clk => clk,
		reset => reset,
		ce => ce,
		d => da,
		q => qa );
	unit_B: ffD_reset PORT MAP(
		clk => clk,
		reset => reset,
		ce => ce,
		d => db,
		q => qb );	
	unit_C: ffD_reset PORT MAP(
		clk => clk,
		reset => reset,
		ce => ce,
		d => dc,
		q => qc );
	unit_D: ffD_reset PORT MAP(
		clk => clk,
		reset => reset,
		ce => ce,
		d => dd,
		q => qd );
		
		dd <= not qd;
		dc <= (not qa) and (qc xor qd);
		db <= (qb and (not qc or not qd)) or (not qb and(qc and qd));
		da <= (qa and not qd) or ((qb and qc) and qd);
		
		count <= qa & qb & qc & qd;

end Behavioral;