
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;

-- D Type Flip Flop Entity
-- without enable 

entity D_type_FF is
    Port ( 
           -- Inputs
           rst : in STD_LOGIC;
           clk : in STD_LOGIC;
           D   : in STD_LOGIC;
           -- Output 
           Q   : out STD_LOGIC);
end D_type_FF;

architecture Behavioral of D_type_FF is

begin
 process(clk)
   begin
     if(rising_edge(clk)) then
         if(rst = '1') then
             Q <= '0';
         else if(clk='1') then
                 Q <= D;
              End if;
         End if;
     End if;
   end process;
end Behavioral;
