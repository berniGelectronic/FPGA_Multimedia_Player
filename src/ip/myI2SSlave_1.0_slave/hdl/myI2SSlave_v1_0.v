
`timescale 1 ns / 1 ps

// s00_axis_aclk = 100 MHz
// MCLK = 10 cycles => 10 MHz
// BCLK = 40 cycles => 2.5MHz
// => 32 bit = 1280 cycles => f_sample = 1/(1280*2*10e-9) = 39.0625 kHz
// A single transfer is 32 bit wide:
//     The left channel is in the upper 16 bits, the right channel is in the lower 16 bits.
	module myI2SSlave_v1_0 #
	(
		// Users to add parameters here

		// User parameters ends
		// Do not modify the parameters beyond this line


		// Parameters of Axi Slave Bus Interface S00_AXIS
		parameter integer C_S00_AXIS_TDATA_WIDTH	= 32
	)
	(
        // I2S Slave Interface
        input bclk,
        input lrclk,
        output reg sdata = 0,

		// User ports ends
		// Do not modify the ports beyond this line


		// Ports of Axi Slave Bus Interface S00_AXIS
		input wire  s00_axis_aclk,
		input wire  s00_axis_aresetn,
		output reg  s00_axis_tready = 0,
		input wire [C_S00_AXIS_TDATA_WIDTH-1 : 0] s00_axis_tdata,
		//input wire [(C_S00_AXIS_TDATA_WIDTH/8)-1 : 0] s00_axis_tstrb,
		input wire  s00_axis_tlast,
		input wire  s00_axis_tvalid
	);

    reg bclkdelay = 0;
    reg bclkdebounced = 0;
    reg bclkdebounced_last = 0;
    reg lrclkdelay = 0;
    reg lrclkdebounced = 0;
    
    reg halfclk = 0;
    reg [0:0]counter = 0;
    
    reg [15:0]ramp = 16'hFFFF;
    reg [15:0]shiftreg = 0;
    reg [4:0]bitcounter = 0;
    reg [2:0] state = 0;
	
    reg [31:0] buffer = 0;
	reg bufvalid = 0;
    
    localparam S0 = 0;
    localparam S1 = 1;
    localparam S2 = 2;
    localparam S3 = 3;
    localparam S4 = 4;

    always @(posedge s00_axis_aclk) begin
        if (bclk==1 && bclkdelay==1) begin
            bclkdebounced=1;
        end else if (bclk==0 && bclkdelay==0) begin
            bclkdebounced=0;
        end
        bclkdelay <= bclk;
        bclkdebounced_last <= bclkdebounced;
        
        if (lrclk==1 && lrclkdelay==1) begin
            lrclkdebounced=1;
        end else if (lrclk==0 && lrclkdelay==0) begin
            lrclkdebounced=0;
        end
        lrclkdelay <= lrclk;
        
		if (bufvalid==0 && s00_axis_tready==0) begin
			s00_axis_tready <= 1;
		end else if (bufvalid==0 && s00_axis_tready==1 && s00_axis_tvalid==1) begin
			s00_axis_tready <= 0;
			buffer <= s00_axis_tdata;
			bufvalid <= 1;
		end
		
        case(state)
            S0:     begin
                        // Wait for rising BCLK edge and LRCLK beging low
                        if (bclkdebounced==1 && bclkdebounced_last==0 && lrclkdebounced==0 && bufvalid==1) begin
                            bufvalid <= 0;
                            bitcounter <= 0;
                            sdata <= 0;
                            state <= S1;
                            shiftreg <= buffer[31:16];
                        end
                    end
            S1:     begin
                        // Wait for falling BCLK edge
                        if (bclkdebounced==0 && bclkdebounced_last==1) begin
                            sdata <= shiftreg[15];
                            shiftreg <= shiftreg<<1;
                            if (bitcounter==23) begin
                                state <= S2;
                            end else begin
                                bitcounter <= bitcounter+1;
                            end
                        end
                    end
            S2:     begin
                        // Wait for rising BCLK edge and LRCLK beging high
                        if (bclkdebounced==0 && bclkdebounced_last==1 && lrclkdebounced==1) begin
                            bitcounter <= 0;
                            sdata <= 0;
                            state <= S3;
                            shiftreg <= buffer[15:0];
                        end
                    end
            S3:     begin
                        // Wait for falling BCLK edge
                        if (bclkdebounced==0 && bclkdebounced_last==1) begin
                            sdata <= shiftreg[15];
                            shiftreg <= shiftreg<<1;
                            if (bitcounter==23) begin
                                state <= S0;
                            end else begin
                                bitcounter <= bitcounter+1;
                            end
                        end
                    end
            default:begin
                        state <= S0;
                    end
        endcase
    end

	endmodule
