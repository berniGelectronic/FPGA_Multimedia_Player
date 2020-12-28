
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;
use work.DigEng.ALL;

-- Debounce implementation
-- recives limit value from higher entity, passes it to counter
-- after button is pressed, inverts input signal, and waits for counter to reach 50 mil clock cycles
-- counter enable is 1 until counter reaches 10 mil, 
-- then set feedback to 1 and save 1 to D type flipflop, 
-- resets counter and sets the output - debounced signal to 1 

entity deb_new_20 is
    generic (limit  : natural := 1000000;
             test : natural:=300); -- value for counter
    Port ( clk      : in  STD_LOGIC;
           deb_sig  : out STD_LOGIC;  -- debounced output signal
           sig      : in  STD_LOGIC); -- input signal
end deb_new_20;

architecture Behavioral of deb_new_20 is
-- Internal signals
signal int_feedback          : STD_LOGIC;-- combinational logic output, '1' if couner reached limit value, else 0
Signal int_cnt_out           : UNSIGNED(log2(limit)-1 downto 0); -- size required to store 10 mil (26 bits)
signal int_out_DFF           : STD_LOGIC;-- D FlipFlop output 
signal int_sig_in            : STD_LOGIC;-- input signal
signal int_en_cnt            : STD_LOGIC;-- counter enable

-- Counter component
component counter_3A is
    generic(limit_val: natural);
    port(clk,rst,en : in STD_LOGIC;
         cnt_out : out  UNSIGNED(log2(limit)-1 downto 0));-- size required to store 10 mil (26 bits)
end component;

-- D type flip flop compoennt 
component D_type_FF is
    port(clk,rst,D : in STD_LOGIC;
         Q :out  STD_LOGIC);
end component;

begin
int_sig_in <= not sig;
int_en_cnt <= sig and (not int_feedback);
int_feedback <= '1' when (int_cnt_out = (limit -1)) else
                '0';
deb_sig<=(not int_out_DFF) and int_feedback;

COUNTER_LIMIT: counter_3A
    generic map(limit_val => limit)
    port map( clk =>clk,
              rst =>int_sig_in,
              en => int_en_cnt,
              cnt_out => int_cnt_out);
DFF: D_type_FF
    port map( clk => clk,
              rst => '0', -- no reset possible 
              D => int_feedback,
              Q => int_out_DFF );              

end Behavioral;
