/*
 * Bit_Bash.c
 *
 *  Created on: 20 Jul 2020
 *      Author: oliver
 */
#include "xbasic_types.h"
#include "xgpio.h"
//#include "sleep.h"
#include "Bit_Bash.h"



XGpio Gpio_SPI_TFT; /* The Instance of the GPIO Driver */

//command data found here:
//https://focuslcds.com/content/ILI9806E.pdf
// for commands 3 hex values 0xabc
//position a if 1 = read
//position a if 0 = write
int32_t commands[] = {
		// default starts at page 0
		// activates the parameters
		0x0ff,// pg 123, page 0,register address
		0x1ff, // pg 123, page 0,register address 1st parameter protect key
		0x198, // pg 123, page 0,register address 2nd parameter device code 1
		0x106, // pg 123, page 0,register address 3rd parameter device code 2
		0x104, // pg 123, page 0,register address 4th parameter device code 3
		0x101, // pg 124 go to page 1

		0x008, // pg 181, page 1 command IFMODE 1(Interface Mode Control 1)
		0x110, // pg 181, page 1 1st parameter IFMODE 1(Interface Mode Control 1) SDO_STATUS =1: always output , but without output tri-state. SEPT_SDIO =0: SPI interface transfer data through SDA pin
		//0x013, // pg 125, page 0, normal display mode on OF-S added

		// the 2 below 20 & 21 define the orientation top and bottom flipped
		// 0x020, // pg 125, page 0, display inversion off 0F-S added
		//0x01,

		0x021,// pg 184, page 1,  DISCTRL2 (Display Function Control 2)
		0x109, // pg 184, page 1, 1st parameter 9 = 1001,
		// bit 3 = 1 meaning VSPL: VS polarity      (“0”= Low level sync clock, “1”= High level sync clock)
		// bit 2 = 0 meaning HSPL: HS polarity      (“0”=Low level sync clock, “1”=High level sync clock)
		// bit 1 = 0 meaning DPL: PCLK polarity set (“0”=data fetched at the rising time, “1”=data fetched at the falling time)
		// bit 0 = 1 meaning EPL: DE polarity       (“0”= Low enable, “1”= High enable)
		//0x022, //pg 185, page 1, 22h : PANELCTRL1 (Set panel operation mode1)
		//0x100, //pg 185, page 1, 1st parameter = 0001

		0x030,// pg 129, page 1 resolution control command
		0x102, // pg 129, page 1 resolution control 1st parameter
		0x031, // pg 129, page 1 display inversion control command
		0x100, // pg 129, page 1 display inversion control 1st parameter
		0x040, // pg 129, page 1 power control 1 command
		0x110, // pg 129, page 1 power control 1 1st parameter
		0x041, // pg 130, page 1 power control 2 command
		0x155, // pg 130, page 1 power control 2 1st parameter 1 = read, 5 = 0101 = DDVDH clamp level  -5.6, 5 = 0101 = DDVDL clamp level  5.6,
		0x042, // pg 130, page 1 power control 3 command
		0x102, // pg 130, page 1 power control 3 1st parameter 1 = read, 0 = 0000 = 2DDVDH-DDVDL, 2 = 0010 = DDVDL+VCL -VCIP
		0x043, // pg 130, page 1 power control 4 command
		0x109, // pg 130, page 1 power control 4 1st parameter 1 = read, 0 = 0000 = VGH clamp function disabled , 9 = 1001 = vgh clamp level(V) 15.0 ,
		0x044, // pg 130, page 1 power control 5 command
		0x107, // pg 130, page 1 power control 5 1st parameter 1 = read, 0 = 0000 = VGH clamp function disabled , 9 = 0111 = vgh clamp level(V) -11.0 ,
		0x050, // pg 130, page 1 power control 9 command
		0x178, // pg 130, page 1 power control 9 1st parameter 1 = read, these 2 combined set the VREG1out for negative gamma 78 = 01111000 = VREG1OUT(V) 4.5000 ,
		0x051, // pg 130, page 1 power control 10 command
		0x178, // pg 130, page 1 power control 10 1st parameter 1 = read, these 2 combined set the VREG2out for negative gamma 78 = 01111000 = VREG2OUT(V) -4.5000 ,
		0x052, // pg 131, page 1 VMCTRL1 (VCOM Control 1) command
		0x100, // pg 131, page 1 : VMCTRL1 (VCOM Control 1) parameter 1 = 0,0 = 0000,0000 LSB only VCM1[8]
		0x053, // pg 131, page 1 VMCTRL2 (VCOM Control 2) command
		0x16d,
		0x060, // pg 131, page 1  Source Timing Adjust 1  command
		0x107,
		0x061, // pg 131, page 1  Source Timing Adjust 2  command
		0x100,
		0x062, // pg 131, page 1  Source Timing Adjust 3  command
		0x108,
		0x063, // pg 131, page 1  Source Timing Adjust 4  command
		0x100,

		//STARTS
		//pg 132, page 1  A0h~AFh : PGAMCTRL1~16 (Positive Gamma Control 1~16)  commands
		0x0a0, 0x100, 0x0a1, 0x107, 0x0a2, 0x10c, 0x0a3, 0x10b, 0x0a4, 0x103,
		0x0a5, 0x107, 0x0a6, 0x106, 0x0a7, 0x104, 0x0a8, 0x108, 0x0a9, 0x10c,
		0x0aa, 0x113, 0x0ab, 0x106, 0x0ac, 0x10d, 0x0ad, 0x119, 0x0ae, 0x110,
		0x0af, 0x100,
		//pg 132, page 1  A0h~AFh : PGAMCTRL1~16 (Positive Gamma Control 1~16)  commands
		// Finish

		//START
		//pg 132, page 1  C0h~CFh : NGAMCTRL1~16(Negative Gamma Correction 1~16)   commands
		0x0c0, 0x100, 0x0c1, 0x107, 0x0c2, 0x10c, 0x0c3, 0x10b, 0x0c4, 0x103,
		0x0c5, 0x107, 0x0c6, 0x107, 0x0c7, 0x104, 0x0c8, 0x108, 0x0c9, 0x10c,
		0x0ca, 0x113, 0x0cb, 0x106, 0x0cc, 0x10d, 0x0cd, 0x118, 0x0ce, 0x110,
		0x0cf, 0x100,
		//pg 132, page 1  C0h~CFh : NGAMCTRL1~16(Negative Gamma Correction 1~16)   commands
		//FINISH

		0x0ff,

		0x1ff, 0x198, 0x106, 0x104,
		0x106,	// page 6 ?
		0x000, 0x120, 0x001, 0x10a, 0x002, 0x100, 0x003, 0x100, 0x004, 0x101,
		0x005, 0x101, 0x006, 0x198, 0x007, 0x106, 0x008, 0x101, 0x009, 0x180,
		0x00a, 0x100, 0x00b, 0x100, 0x00c, 0x101, 0x00d, 0x101, 0x00e, 0x100,
		0x00f, 0x100, 0x010, 0x1f0, 0x011, 0x1f4, 0x012, 0x101, 0x013, 0x100,
		0x014, 0x100, 0x015, 0x1c0, 0x016, 0x108, 0x017, 0x100, 0x018, 0x100,
		0x019, 0x100, 0x01a, 0x100, 0x01b, 0x100, 0x01c, 0x100, 0x01d, 0x100,
		0x020, 0x101, 0x021, 0x123, 0x022, 0x145, 0x023, 0x167, 0x024, 0x101,
		0x025, 0x123, 0x026, 0x145, 0x027, 0x167, 0x030, 0x111, 0x031, 0x111,
		0x032, 0x100, 0x033, 0x1ee, 0x034, 0x1ff, 0x035, 0x1bb, 0x036, 0x1aa,
		0x037, 0x1dd, 0x038, 0x1cc, 0x039, 0x166, 0x03a, 0x177, 0x03b, 0x122,
		0x03c, 0x122, 0x03d, 0x122, 0x03e, 0x122, 0x03f, 0x122, 0x040, 0x122,
		0x052, 0x110, 0x053, 0x110,

		//swap page
		0x0ff, 0x1ff, 0x198, 0x106, 0x104, 0x107,	//page 7
		0x018, // pg 140 page 7 command  VREG12EN (VREG1/2OUT ENABLE)
		0x11d, // pg 140 page 7 parameter 1  enables the VREG EN
		0x017, // pg 140 page 7 command  VGLREGEN (VGL_REG EN)
		0x122, // pg 140 page 7 parameter 1  disables the VGLREGEN
		0x002, 0x177, 0x026, 0x1b2, 0x0e1, 0x179,

		//swap page
		0x0ff, 0x1ff, 0x198, 0x106, 0x104, 0x100, //change to page 0
		0x03a, // pg 126 page 0 command   COLMOD (Interface Pixel Format)
		0x160, // pg 126  page 0 parameter 1  DPI[2:0]= 101  RGB Interface Format =  18-bit / pixel
		0x035, // pg 125 page 0 command  35h : TEON (Tearing Effect Line ON)
		0x100, // no operation pg 87
		0x011, // sleep out pg 87
		0x100, // no operation pg 87
		-1, 0x029, // display on pg 87
		0x100, // no operation pg 87
		-1 };

void setup_pins() {
	// checks status of drivers
	int Status;
	u32 read_mask;

	// this function is used for pin setup translated from  BCM2835 Library
	// all three pins set to ouput and the Control signal set to high
	// ## bcm2835_gpio_fsel(CLK, BCM2835_GPIO_FSEL_OUTP);
	// ## bcm2835_gpio_fsel(MOSI, BCM2835_GPIO_FSEL_OUTP);
	// ## bcm2835_gpio_fsel(CS, BCM2835_GPIO_FSEL_OUTP);

	/* Initialise the GPIO driver and check confirmation */
	Status = XGpio_Initialize(&Gpio_SPI_TFT, XPAR_GPIO_2_DEVICE_ID);
	if (Status != XST_SUCCESS) {
		xil_printf("\r\nGPIO_SPI_TFT Initialisation Failed\r\n");
		//return XST_FAILURE;
	} else {
		xil_printf("GPIO_SPI_TFT Initialisation Complete\n\r");
	}

	usleep(WAIT);

	// set GPIO channel 1 all to output
	XGpio_SetDataDirection(&Gpio_SPI_TFT, GPIO_CHANNEL_1, 0x00);

	// ## bcm2835_gpio_write(CS, HIGH);
	// set the CS signal high
	XGpio_DiscreteWrite(&Gpio_SPI_TFT, GPIO_CHANNEL_1, TFT_CS);

	usleep(WAIT);

	// turn on back light
	read_mask = XGpio_DiscreteRead(&Gpio_SPI_TFT, GPIO_CHANNEL_1);
	XGpio_DiscreteWrite(&Gpio_SPI_TFT, GPIO_CHANNEL_1, read_mask | TFT_BL);

	usleep(WAIT);

}

/********************************************************************************/
void send_bits(uint16_t data, uint16_t count) {
	int x;
	int mask = 1 << (count - 1);
	u32 read_mask;
	//u32 read_mask_PRINT;
	//volatile u32 Delay = 0;
	for (x = 0; x < count; x++) {
		//print("send bits attempts \n\r");
		read_mask = XGpio_DiscreteRead(&Gpio_SPI_TFT, GPIO_CHANNEL_1);

		//bcm2835_gpio_write(MOSI, (data & mask) > 0);
		if ((data & mask) > 0) {
			XGpio_DiscreteWrite(&Gpio_SPI_TFT, GPIO_CHANNEL_1,
					read_mask | TFT_MOSI);
			//read_mask_PRINT = (read_mask | TFT_MOSI);
			//printf("%lu\n\r",read_mask_PRINT);
			//printf("TFT_MOSI = 1\n\r");
		} else {

			XGpio_DiscreteWrite(&Gpio_SPI_TFT, GPIO_CHANNEL_1, read_mask &=
					~(TFT_MOSI));
			//read_mask_PRINT = (read_mask &= ~(TFT_MOSI));
			//printf("%lu\n\r",read_mask_PRINT);
			//printf("TFT_MOSI = 0\n\r");

		}

		data <<= 1;

		read_mask = XGpio_DiscreteRead(&Gpio_SPI_TFT, GPIO_CHANNEL_1);

		//bcm2835_gpio_write(CLK, LOW);
		XGpio_DiscreteWrite(&Gpio_SPI_TFT, GPIO_CHANNEL_1, read_mask &=
				~(TFT_CLK));

		// bcm2835_delayMicroseconds(DELAY);
		usleep(DELAY);

		read_mask = XGpio_DiscreteRead(&Gpio_SPI_TFT, GPIO_CHANNEL_1);

		// bcm2835_gpio_write(CLK, HIGH);
		XGpio_DiscreteWrite(&Gpio_SPI_TFT, GPIO_CHANNEL_1, read_mask | TFT_CLK);

		// bcm2835_delayMicroseconds(DELAY);
		usleep(DELAY);
	}

	read_mask = XGpio_DiscreteRead(&Gpio_SPI_TFT, GPIO_CHANNEL_1);

	// bcm2835_gpio_write(MOSI, LOW);
	XGpio_DiscreteWrite(&Gpio_SPI_TFT, GPIO_CHANNEL_1, read_mask &=
			~(TFT_MOSI));

}

/********************************************************************************/
// write the bit out of the GPIO
void write(uint16_t command) {
	u32 read_mask;

	read_mask = XGpio_DiscreteRead(&Gpio_SPI_TFT, GPIO_CHANNEL_1);

	//bcm2835_gpio_write(CS, LOW);
	XGpio_DiscreteWrite(&Gpio_SPI_TFT, GPIO_CHANNEL_1, read_mask &= ~(TFT_CS));

	send_bits(command, 9);
	//printf("%Xu\n\r", command);
	read_mask = XGpio_DiscreteRead(&Gpio_SPI_TFT, GPIO_CHANNEL_1);

	//bcm2835_gpio_write(CS, HIGH);
	XGpio_DiscreteWrite(&Gpio_SPI_TFT, GPIO_CHANNEL_1, read_mask | TFT_CS);
}


// sets up the sending of the commands from the array to the screen via the SPI/GPIO
void setup_lcd() {
	int count = sizeof(commands) / sizeof(int32_t);
	int x;
	for (x = 0; x < count; x++) {
		//print("setup lcd attempts \n\r");
		int32_t command = commands[x];

		if (command == -1) {
			//print("command = -1 \n\r");
			//bcm2835_delay(WAIT);
			usleep(WAIT);
			continue;
		}
		// xil_printf("command = %lu\n\r", (unsigned long)command );
		write((uint16_t) command);
	}
}
