----------------------------------------------------------------------------------
-- Company: ULL
-- Engineer: Eduardo Magdaleno Castell
-- 
-- Create Date:    11:35:57 02/28/2019 
-- Design Name: 	 
-- Module Name:    contador - Behavioral 
-- Project Name:   minicronometro
-- Target Devices: Artix7
-- Tool versions: ISE 14.7
-- Description: 
--
-- Dependencies: ninguna
--
-- Revision: 
-- Revision 0.01 - File Created
-- Additional Comments: 
-- Este contador tiene 2 genricos: el nmero hasta el que se quiere contar (module)
-- y el ancho en bits de la cuenta (evidentemente estos nmeros estn relacionados:
-- 2^width > module necesariamente
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.std_logic_unsigned.all; -- librera para usar "+" y sintetizar contadores

entity contador is
	 Generic (module : integer; -- los genricos permiten "parametrizar" circuitos
				 width : integer);
    Port ( clk : in  STD_LOGIC;
           reset : in  STD_LOGIC;
           count : out  STD_LOGIC_VECTOR (width-1 downto 0);
           ce : in  STD_LOGIC;
           top : out  STD_LOGIC);
end contador;

architecture Behavioral of contador is

signal q : std_logic_vector(width-1 downto 0) := (others => '0');

begin
------------- contador -------------
process (clk, reset) 
begin
   if reset='1' then 
      q <= (others => '0');
   elsif clk='1' and clk'event then
      if ce='1' then
			if q = module-1 then
				q <= (others => '0');
			else
				q <= q + 1;
			end if;
      end if;
   end if;
end process;

count <= q;
------------- contador -------------

---- generador de señal de tope ----
process(q)
begin
	if q = module-1 then
		top <= '1';
	else
		top <= '0';
	end if;
end process;
---- generador de señal de tope ----

end Behavioral;

