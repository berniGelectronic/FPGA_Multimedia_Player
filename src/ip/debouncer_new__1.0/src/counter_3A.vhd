library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;
use work.DigEng.ALL;

-- Counter up user passed generic limit_val
-- On every press of button counter starts counting to the user passed generic value 

entity counter_3A is
        generic (limit_val : natural:= 14); --max count value
        Port(
           --Inputs
           rst   : in STD_LOGIC;
           en    : in STD_LOGIC;
           clk   : in STD_LOGIC;
           --Outputs
           cnt_out  : out UNSIGNED(log2(limit_val)-1 downto 0)); -- gives size of output required to store 50 milion (26 bits)
end counter_3A;

architecture Behavioral of counter_3A is
-- internal signal to store counter value
Signal int_cnt : UNSIGNED(log2(limit_val)-1 downto 0);

begin
COUN_to_LIMIT: process(clk)
begin
    if(rising_edge(clk)) then    
        if(rst = '1') then               -- sync reset
            int_cnt <= (others => '0');    
        else        
            if(en = '1') then              -- if the push button is pressed
                int_cnt <= (int_cnt + 1);  -- sum clock cycles              
                if(int_cnt = limit_val-1) then -- chechk if limit is reached 
                    int_cnt <= (others => '0');-- set everything to zero  
                end if;
            end if;           
        end if;       
    end if;    
end process;     
cnt_out <= int_cnt; 
end Behavioral;
