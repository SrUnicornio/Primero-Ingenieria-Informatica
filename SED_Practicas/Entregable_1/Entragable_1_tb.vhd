LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
ENTITY Entregable_1_tb IS
END Entregable_1_tb;
ARCHITECTURE behavior OF Entregable_1_tb IS
     -- Component Declaration for the Unit Under Test (UUT)
	COMPONENT Entregable_1
	PORT(
     	a : IN  std_logic;
     	b : IN  std_logic;
     	c : IN  std_logic;
     	d : IN  std_logic;
     	f1_C63B : OUT  std_logic;
     	f2_753E : OUT  std_logic
    	);
	END COMPONENT;
   --Inputs
   signal a : std_logic := '0';
   signal b : std_logic := '0';
   signal c : std_logic := '0';
   signal d : std_logic := '0';
   --Outputs
   signal f1_C63B : std_logic;
   signal f2_753E : std_logic;
   --Control
   constant Tb_semiPeriod : time := 10 ns;
   signal   TbSimEnded    : std_logic := '0';

BEGIN
   -- Instantiate the Unit Under Test (UUT)
   uut: Entregable_1 PORT MAP (
      	a => a,
      	b => b,
      	c => c,
      	d => d,
      	f1 => f1,
      	f2 => f2
    	);
d <= not d after Tb_semiPeriod  when TbSimEnded /= '1' else '0';
c <= not c after Tb_semiPeriod*2 when TbSimEnded /= '1' else '0';
b <= not b after Tb_semiPeriod*4 when TbSimEnded /= '1' else '0';
a <= not a after Tb_semiPeriod*8 when TbSimEnded /= '1' else '0';
   -- Stimulus process
   stim_proc: process
   begin   	
  	wait for Tb_semiPeriod*16;
      	TbSimEnded <= '1';
  	wait;
   end process;
END;
