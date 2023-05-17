library IEEE;
use IEEE.STD_LOGIC_1164.ALL;


entity minicronometro is
    Port ( clk : in  STD_LOGIC;
           reset : in  STD_LOGIC;
			  led : out std_logic_vector(6 downto 0);
			  an : out std_logic_vector(7 downto 0);
           ce : in  STD_LOGIC;
			  );
end minicronometro;

architecture Behavioral of minicronometro is

signal ce_centesimas, ce_decimas, ce_useg, ce_dseg, ce_uminutos, ce_dminutos, ce_uhoras, ce_dhoras : std_logic;
signal top_divisor, top_centesimas, top_decimas, top_useg, top_dseg, top_uminutos, top_dminutos, top_uhoras, top_dhoras : std_logic;
signal hex, centesimas, decimas, useg, dseg, uminutos, dminutos, uhoras, dhoras : std_logic_vector(3 downto 0);
signal divisor : std_logic_vector(19 downto 0);
signal sel : std_logic_vector(2 downto 0);
signal reset_int, reset_counter : std_logic;

	COMPONENT contador
	 Generic (
		module : integer;
		width : integer);
	PORT(
		clk : IN std_logic;
		reset : IN std_logic;
		ce : IN std_logic;          
		count : OUT std_logic_vector(width-1 downto 0);
		top : OUT std_logic
		);
	END COMPONENT;

begin

	reset_counter <= reset or reset_int;

	divisorfrec_unit: contador 
	generic map(
		module => 1000000,
		width => 20)
	PORT MAP(
		clk => clk,
		reset => '0',
		count => divisor,
		ce => '1',
		top => top_divisor
	);
	ce_centesimas <= top_divisor and ce;
	sel <= divisor(18 downto 16); -- señal de refresco 100MHz/2^16
	
	centesimas_unit: contador 
	generic map(
		module => 10,
		width => 4)
	PORT MAP(
		clk => clk,
		reset => reset_counter,
		count => centesimas,
		ce => ce_centesimas,
		top => top_centesimas
	);
	ce_decimas <= top_centesimas and top_divisor and ce;
	
	decimas_unit: contador 
	generic map(
		module => 10,
		width => 4)
	PORT MAP(
		clk => clk,
		reset => reset_counter,
		count => decimas,
		ce => ce_decimas,
		top => top_decimas
	);
	ce_useg <= top_centesimas and top_decimas and top_divisor and ce;
	
	useg_unit: contador 
	generic map(
		module => 10,
		width => 4)
	PORT MAP(
		clk => clk,
		reset => reset_counter,
		count => useg,
		ce => ce_useg,
		top => top_useg
	);
	ce_dseg <= top_centesimas and top_decimas and top_useg and top_divisor and ce;
	
	dseg_unit: contador 
	generic map(
		module => 6,
		width => 4)
	PORT MAP(
		clk => clk,
		reset => reset_counter,
		count => dseg,
		ce => ce_dseg,
		top => top_dseg
	);
	ce_uminutos <= top_centesimas and top_decimas and top_useg and top_dseg and top_divisor and ce;
	
	uminutos_unit: contador 
	generic map(
		module => 10,
		width => 4)
	PORT MAP(
		clk => clk,
		reset => reset_counter,
		count => uminutos,
		ce => ce_uminutos,
		top => top_uminutos
	);
	ce_dminutos <= top_centesimas and top_decimas and top_useg and top_dseg and top_uminutos and top_divisor and ce;
	
	dminutos_unit: contador 
	generic map(
		module => 6,
		width => 4)
	PORT MAP(
		clk => clk,
		reset => reset_counter,
		count => dminutos,
		ce => ce_dminutos,
		top => top_dminutos
	);
	ce_uhoras <= top_centesimas and top_decimas and top_useg and top_dseg and top_uminutos and top_dminutos and top_divisor and ce;

	uhoras_unit: contador 
	generic map(
		module => 10,
		width => 4)
	PORT MAP(
		clk => clk,
		reset => reset_counter,
		count => uhoras,
		ce => ce_uhoras,
		top => top_uhoras
	);
	ce_dhoras <= top_centesimas and top_decimas and top_useg and top_dseg and top_uminutos and top_dminutos and top_uhoras and top_divisor and ce;

	dhoras_unit: contador 
	generic map(
		module => 2,
		width => 4)
	PORT MAP(
		clk => clk,
		reset => reset_counter,
		count => dhoras,
		ce => ce_dhoras,
		top => top_dhoras
	);
	
process(clk)
begin
   if (clk'event and clk ='1') then   
      if ((dhoras="0010") and (uhoras="0011") and top_dminutos='1') then 
         reset_int <= '1';
      else 
         reset_int <= '0';
      end if;
   end if; 
end process; 

-- MUX 8a1 para seleccionar que digito mostramos en el display

process (sel,centesimas,decimas,useg,dseg, 
         uminutos,dminutos,uhoras,dhoras)
begin
   case sel is
      when "000" => hex <= centesimas;
      when "001" => hex <= decimas;
      when "010" => hex <= useg;
      when "011" => hex <= dseg;
      when "100" => hex <= uminutos;
      when "101" => hex <= dminutos;
      when "110" => hex <= uhoras;
      when "111" => hex <= dhoras;
      when others => hex <= centesimas;
   end case;
end process;

--decodificador 3a8 para seleccionar el display en cuestion
       with sel SELect
   an <= "11111110" when "000",   --0
         "11111101" when "001",   --1
         "11111011" when "010",   --2
         "11110111" when "011",   --3
         "11101111" when "100",   --4
         "11011111" when "101",   --5
         "10111111" when "110",   --7
         "01111111" when "111",   --8
         "11111111" when others;  --0
 
--HEX-to-seven-segment decoder
--   HEX:   in    STD_LOGIC_VECTOR (3 downto 0);
--   LED:   out   STD_LOGIC_VECTOR (6 downto 0);
-- 
-- segment encoinputg
--      0
--     ---  
--  5 |   | 1
--     ---   <- 6
--  4 |   | 2
--     ---
--      3
   
    with HEX SELect
   LED<= "1111001" when "0001",   --1
         "0100100" when "0010",   --2
         "0110000" when "0011",   --3
         "0011001" when "0100",   --4
         "0010010" when "0101",   --5
         "0000010" when "0110",   --6
         "1111000" when "0111",   --7
         "0000000" when "1000",   --8
         "0010000" when "1001",   --9
         "0001000" when "1010",   --A
         "0000011" when "1011",   --b
         "1000110" when "1100",   --C
         "0100001" when "1101",   --d
         "0000110" when "1110",   --E
         "0001110" when "1111",   --F
         "1000000" when others;   --0
 
end Behavioral;

