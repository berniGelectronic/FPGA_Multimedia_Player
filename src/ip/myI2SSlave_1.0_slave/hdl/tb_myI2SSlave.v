`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 30.12.2017 15:36:00
// Design Name: 
// Module Name: tb_myI2SSlave
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module tb_myI2SSlave();

    reg bclk = 1;
    reg lrclk = 1;
    wire sdata;
    
    reg s00_axis_aclk = 0;
    reg s00_axis_aresetn = 0;
    wire s00_axis_tready;
    reg [31:0]s00_axis_tdata=0;
    //reg [3:0]s00_axis_tstrb=0;
    reg s00_axis_tlast=0;
    reg s00_axis_tvalid=0; 

	myI2SSlave_v1_0 # (
		.C_S00_AXIS_TDATA_WIDTH(32)
	) myI2SSlave_v1_0_inst (
        .bclk(bclk),
        .lrclk(lrclk),
        .sdata(sdata),
		.s00_axis_aclk(s00_axis_aclk),
		.s00_axis_aresetn(s00_axis_aresetn),
		.s00_axis_tready(s00_axis_tready),
		.s00_axis_tdata(s00_axis_tdata),
		//.s00_axis_tstrb(s00_axis_tstrb),
		.s00_axis_tlast(s00_axis_tlast),
		.s00_axis_tvalid(s00_axis_tvalid)
	);

    always begin
        #1 s00_axis_aclk=~s00_axis_aclk;
    end   

    initial begin
        #200;
        while (1) begin
            bclk = 0;
            #40 bclk = 1;
            #40;        
        end
    end

    initial begin
        #200;
        while (1) begin
            lrclk = 0;
            #2560 lrclk = 1;
            #2560;        
        end
    end
    
    initial begin
        #200;
        while (1) begin
            @ (posedge s00_axis_aclk) s00_axis_tdata = 32'hAA558001;s00_axis_tvalid = 1;
            while (s00_axis_tready==0) begin
                @ (posedge s00_axis_aclk) ;
            end
            @ (posedge s00_axis_aclk) s00_axis_tdata = 32'hA5A58001;s00_axis_tvalid = 1;
            while (s00_axis_tready==0) begin
                @ (posedge s00_axis_aclk) ;
            end
        end
        //@ (posedge s00_axis_aclk) s00_axis_tdata = 32'h00000000;s00_axis_tvalid = 0;
    end

endmodule
