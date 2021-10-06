/*
 *#####################################################################
 *					MsC Final Project
 *	@name:    FPGA Based Multimedia Player
 *  @uni:     University of York
 *  @Msc:  	  DSE Programme 2019/20
 *  @Authors: Oliver Forbes-Shaw & Bernard Guncic
 *
 *#####################################################################
 */


#include "xparameters.h"
#include "xiic.h"
#include "xiic_l.h"
#include "xscugic.h"
#include "xstatus.h"
#include "xil_exception.h"
#include "xil_printf.h"




//#include "sleep.h"
#include "stdio.h"
#include <math.h>
#include "xdebug.h"
#include "ffconf.h"		/* FatFs configuration options */
#include <stdlib.h>
#include "xil_types.h"
#include "xaxidma.h"
#include "ff.h"
#include "xgpio.h"
#include "xgpio_l.h"
//#include "xllfifo.h"
#include "audio.h"

//#include "adau_1761.h"
#include "interrupt_hand.h"
#include "sd_card.h"
#include "user_io.h"

#include "xaxivdma.h"
#include <stdlib.h>
#include "xil_cache.h"
#include "Graphics.h"
#include "Bit_Bash.h"
<<<<<<< HEAD

#include "VDMA_Setup.h"
#include "imageData.h"
#include "GPIO_LEDs.h"
=======

#include "VDMA_Setup.h"


>>>>>>> 732e8af... Removed audio functions
//#define DEBUG

/*
 * Device hardware build related constants.
 */
#define DMA_DEV_ID		XPAR_AXIDMA_0_DEVICE_ID

//#warning CHECK FOR THE VALID DDR ADDRESS IN XPARAMETERS.H,
//		DEFAULT SET TO 0x00100000
// base address for the DDR3 im memory map
#define MEM_BASE_ADDR	XPAR_PS7_DDR_0_S_AXI_BASEADDR	//	0x00100000

#define TX_AUDIO_DATA_BUFFER_BASE		(MEM_BASE_ADDR + 0x01000000)


#define IMAGE_BUFFER_SIZE 		(MEM_BASE_ADDR + 0x1A000000) //image address in RAM

//#define RX_BUFFER_BASE		    (MEM_BASE_ADDR + 0x00500000) // original 0x00300000)
//#define RX_BUFFER_HIGH		    (MEM_BASE_ADDR + 0x009FFFFF) // original 0x004FFFFF)

// interrupt device
#define INTC_DEVICE_ID XPAR_SCUGIC_0_DEVICE_ID
#define INTC_IIC_ID XPAR_FABRIC_IIC_0_VEC_ID
#define INTC_DMA_TX_ID XPAR_FABRIC_AXIDMA_0_VEC_ID
#define INTC_GPIO_ID XPAR_FABRIC_GPIO_0_VEC_ID
#define INTC_VDMA_ID XPAR_FABRIC_AXIVDMA_0_VEC_ID


// interrupt controller
#define INTC		XScuGic
#define INTC_HANDLER	XScuGic_InterruptHandler

/* Timeout loop counter for reset
 */
#define RESET_TIMEOUT_COUNTER	10000

//// for loop value for LED test
//#define LED_DELAY     10000000


//size of the audio block data sent to the RAM
//Must be below 8M because of the error in Simple DMA transfer function
#define MAX_AUDIO_BLOCK_SIZE 4000000//8000000
#define MAX_AUDIO_SIZE 100000000 // max size of the song
#define MAX_SONGS_ON_LIST 5 //array starts from 0 to 4

// GPIO controller
#define GPIO_LEDS_ID XPAR_GPIO_1_DEVICE_ID
#define GPIO_BTNSW_ID XPAR_GPIO_0_DEVICE_ID
//#define GPIO_LCD_ID XPAR_GPIO_2_DEVICE_ID
//#define GPIO_BTN_CHANNEL 0
//#define GPIO_SW_CHANNEL 1

#define SINGLE_LED_CHANNEL 1
#define RGB_LED_CHANNEL    2

#define BUTTONS_CHANNEL 1
#define SWITCH_CHANNEL  2


// I2C Controller
#define I2C_ID XPAR_IIC_0_DEVICE_ID
#define I2C_CH 1
#define I2C_BASE_ADDRESS XPAR_IIC_0_BASEADDR //required for XIIC_Send

//FIFO
//#define FIFO_ID XPAR_AXI_FIFO_0_DEVICE_ID
//#define FIFO_BASE_ADDRESS XPAR_AXI_FIFO_0_BASEADDR

#define dataCount 4
#define readData 10

//#define PERIODSAMPLES 64 //48kHz/64 = 750Hz freq  // 44.1k/64= 689Hz
//
// number of .wav file names that can be copied into array
//** NEEDS UPDATING FOR ARRAY TO INCREASE IN SIZE TO FIT AL WAV FILE NAMES **
//#define maxFiles 32

//FUNCTION PROTOTYPES
//**********************************************************************************************
extern void xil_printf(const char *format, ...);

// DMA functions
//static void TxIntrHandler(void *Callback);
//static void RxIntrHandler(void *Callback);
//static int SetupIntrSystem(INTC * IntcInstancePtr, XAxiDma * AxiDmaPtr, u16 TxIntrId, u16 RxIntrId);
//static void DisableIntrSystem(INTC * IntcInstancePtr, u16 TxIntrId, u16 RxIntrId);

int configure_I2C();
//int fifo_init(XLlFifo *fifo_instance, u16 fifo_ID);
int configureALL();
static int SetupInterruptSystem(XIic *IicInstPtr, XAxiDma *AxiDma, XGpio *Gpio_SWITCH_BUTTON, XAxiVdma *AxiVdmaPtr);
static void I2CSendHandler(XIic *InstancePtr);
static void I2CReceiveHandler(XIic *InstancePtr);
//static void I2CStatusHandler(XIic *InstancePtr, int Event); //unused

//int SetupIntrSystem(INTC * IntcInstancePtr, XAxiDma * AxiDmaPtr, u16 TxIntrId);
void BTN_SWITCH_Intr_Handler();
void TxIntrHandler(void *Callback);

void printData(u8 samples, u8 *data);
void I2SSend();
void I2C_send(u16 address, u8 datasend);
<<<<<<< HEAD
=======

>>>>>>> 732e8af... Removed audio functions

void Open_File_Directory(void);
void Copy_WAV_File_Names(void);
int Read_SD_Card_short(char *filename);

//void turnOffLEDS();
void FIFO_Intr_Handler();

int readFile(u32 AudioDataSizeToRead);


//void ReadCallBack(void *CallbackRef, u32 Mask);
//
//void ReadErrorCallBack(void *CallbackRef, u32 Mask);

//***********************************************************************************************

//INSTANCES
//I2C instance
XIic I2C;
//interrupt controller instance
INTC INTC_Inst;
//static INTC Intc; /* Instance of the Interrupt Controller */

//-----------FIFO----------
//XLlFifo fifo_audio;

//DMA instance
static XAxiDma AxiDma; /* Instance of the XAxiDma */
XAxiDma_Config *Config;


// instance of SD card directory
DIR directory;

// Instances of GPIOs
//XGpio Gpio_LEDs; /* The Instance of the GPIO Driver */
XGpio Gpio_SWITCH_BUTTON; /* The Instance of the GPIO Driver */

//VARIABLES

u8 txData[dataCount], rxData[readData], rxData1[readData];

output_t headphones; // structure for setting volume on L&R channel

FILINFO file_Info; // file names array
FIL file; // file structure information
// instance of fat file system
FATFS FS_instance;

songList_t **songList_ptr;



UINT nBytesRead = 0;


//SWITCH AND BUTTON enum
switch_t SW_STATE;
button_t BTN_STATE;

//VDMA INST
XAxiVdma AxiVdma;
//COLOUR RGB;

int numberOfScreens=10;
<<<<<<< HEAD
extern const struct register_values adau_1761_reg[12];


=======
extern unsigned char Test_Image_map[FrameSize];
extern unsigned char volume_screen[FrameSize];
extern unsigned char song_selection[FrameSize];
extern const struct register_values adau_1761_reg[12];
>>>>>>> 732e8af... Removed audio functions

volatile u8 TransmitComplete; /* Flag to check completion of Transmission i2c*/
volatile u8 ReceiveComplete; /* Flag to check completion of Reception i2c */
volatile int TxDone; //DMA Audio
volatile int RxDone; //DMA Audio
volatile int Error;  //DMA Audio

volatile u32 Button_Val = 0;  //GPIO interrupt
volatile u32 oldButton_Val = 0;  //GPIO interrupt
volatile u32 Switch_Val = 0;  //GPIO interrupt

volatile u8 audioBlockCounter=0;
//volatile u8 nAudioBlocks;


int songCounterWAV = 0; // number of wav files stored on the SD card


// 2 dimensional character array
// name = files
// type = charachter
// value of maxFiles is number of rows
// value of columns = 32
// all contain the value 0
// this means that there can be value of max files names
// each name can be 32 characters long
//char files[maxFiles][32] = { 0 };

// memory that will hold the song audio data
// pointer to AudioBuffer memory space
//u8 *RxBufferPtr = (u8 *) RX_BUFFER_BASE;
u8 *AudioBuffer = (u8 *) TX_AUDIO_DATA_BUFFER_BASE;
size_t AudioBufferSize = 0;


// memory that will hold the image data
u8 *ImageBuffer=(u8 *) IMAGE_BUFFER_SIZE;

int Status;

XGpio Gpio_SPI_TFT;

int main(void) {
	int status;
	int tempVolume=defaultVolume;
	headphones.volume.left=defaultVolume;
	headphones.volume.right=defaultVolume;

	setup_pins();//LCD PINS
	setup_lcd();
	setup_VDMA((u32)ImageBuffer, AxiVdma);
	xil_printf("\r\n VDMA Setup\r\n");

	BitMap(ImageBuffer, Test_Image_map); //prints image to the screen

	//INITIALIZATION DELAY
	usleep(5000000);

	status = configureALL();
	if (status != XST_FAILURE) {
		xil_printf("\n\rI2C CODEC TEST --------->>>>>>>>");
		XGpio_DiscreteWrite(&Gpio_LEDs, RGB_LED_CHANNEL, LED_RGB1_G);

	} else {
		xil_printf("\n\rConfiguration ERROR!");
		XGpio_DiscreteWrite(&Gpio_LEDs, RGB_LED_CHANNEL, LED_RGB1_R);
		return 0;
	}

	turnOffLEDS(Gpio_LEDs); // set all LEDs to 0;


	XIic_SetSendHandler(&I2C, &I2C, (XIic_Handler) I2CSendHandler);
	XIic_SetRecvHandler(&I2C, &I2C, (XIic_Handler) I2CReceiveHandler);
	//XIic_SetStatusHandler(&I2C, &I2C, (XIic_StatusHandler) I2CStatusHandler);

	XIic_SetAddress(&I2C, XII_ADDR_TO_SEND_TYPE, CODEC_ADDRESS);

	//***************************SET PLL REGISTER*************************************************
	I2C_send(ADAU_1761_CLOCK_CONTROL, 0x0E); // core OFF

	setCodecPLL(&I2C, defaultSamplingFrequency); //Write PLL reg

	xil_printf("\n\r!!!PLL DONE!!!!");

	I2C_send(ADAU_1761_CLOCK_CONTROL, 0x0F); // core ON
	usleep(10 * 1000);  //required or BCLK and LCLK will stay low

	//****************SEND ENTIRE STRUCTURE******************************************************
	for (int i = 0; i < (sizeof(adau_1761_reg) / sizeof(adau_1761_reg[0]));	i++) {

		I2C_send(adau_1761_reg[i].addr, adau_1761_reg[i].value);
//		xil_printf("\n\rCODEC REG[%d]", i);

	}
	xil_printf("\n\r***** CODEC WRITING DONE *****");
	xil_printf("\n\rStart reading from CODEC...");

	//********************read FROM CODEC****************************************************
	CodecReadByte(I2C_BASE_ADDRESS, CODEC_ADDRESS, ADAU_1761_PLL_CONTROL, rxData, 7);
	xil_printf("\n\rRegister ADDRESS: %x",ADAU_1761_PLL_CONTROL);
	printData(7, rxData);	//print received data

	for (int i = 0; i < (sizeof(adau_1761_reg) / sizeof(adau_1761_reg[0]));
			i++) {

		CodecReadByte(I2C_BASE_ADDRESS, CODEC_ADDRESS,adau_1761_reg[i].addr, rxData, 2);
		xil_printf("\n\rRegister ADDRESS: %x \t DATA: 0x%02x ", adau_1761_reg[i].addr,rxData[0]);

	}
	xil_printf("\n\r***** CODEC READING DONE*****\n\r");

	// READ LEFT & RIGHT VOLUME REGISTER
	CodecReadByte(I2C_BASE_ADDRESS, CODEC_ADDRESS,ADAU_1761_PLAY_HP_LEFT_VOL,rxData,2);
	printData(2, rxData);	//print received data
	CodecReadByte(I2C_BASE_ADDRESS, CODEC_ADDRESS,ADAU_1761_PLAY_HP_RIGHT_VOL,rxData,2);
	printData(2, rxData);	//print received data

	xil_printf("\n\rCODEC CONFIGRUATION DONE!!!\n\r ");



	//*********************************************************************************************
	// DMA
	//for(;;) {
	//check SD card is mounted
	Check_SD_Card_Mounted(FS_instance);

	// instance of fat file system
	//	FATFS FS_instance;

	/*FRESULT result = */f_mount(&FS_instance, Drive0Path, MountSDCard);
	// open the file directory and check files
	Open_File_Directory();

//		     copy file names into array
	Copy_WAV_File_Names();


	xil_printf("\n\rMultimedia player Ready!!!\n\r ");

//	u32 lastStateButton=0, lastStateSwitch=0;
	int songCounter=0;
	int currentPlaying=-1; // first time press play only
	int error;
	int currentFS=defaultSamplingFrequency;
	int printSongListFLAG=1; // song selection screen print
	int StartPosY = 280;
	int StartPosX = 390;
	const int posY=630;

	//song list number calculation
	// calculates the number of lists(each have 5 songs)
	int songListsNumber=floor((float)songCounterWAV/MAX_SONGS_ON_LIST);
	int songlistsCounter= 0;
	int tempSongCNT=0;
	int cnt=0;

	//printing volume value to the screen
	int printVolumeScreenFLAG=1;
	char printVolume[4];
	int volumePosition_Y=volumeStartPos_Y;

	//print the number of songs and current list on the screen
	// on the screen ::: SONGS: 105
	//				     LIST:  3/21
	char totalSongsPrint[10], listNumberPrint[10];
	int totalSongStart_X=395, totalSongStart_Y=100;
	int listNumberPrintStart_X=363, listNumberPrintStart_Y=100;

	sprintf(totalSongsPrint,"%d",songCounterWAV);
	u32 currentButton;
	while (1) {

<<<<<<< HEAD
=======
//		currentButton = XGpio_DiscreteRead(&Gpio_SWITCH_BUTTON, BUTTONS_CHANNEL);// & 0x0F;
//		xil_printf("CURRENT_Button_Val = %lu\n\r", (unsigned long)currentButton);


>>>>>>> 732e8af... Removed audio functions
		//	tempSongCNT=(songCounterWAV-(songlistsCounter*MAX_SONGS_ON_LIST))+MAX_SONGS_ON_LIST; // top limit
		switch (SW_STATE) {
		case DEFAULT:
			if(printSongListFLAG==1){
				BitMap(ImageBuffer, song_selection); //prints image to the screen
				sprintf(listNumberPrint,"%d/%d",songlistsCounter+1,songListsNumber+1); // +1 so that printed nmbr starts from 1 not 0
			if(songListsNumber>0){ // more than 5 songs on the list => number of list increases
					if (songCounterWAV > (songlistsCounter + 1) * MAX_SONGS_ON_LIST) {
						tempSongCNT = (songlistsCounter + 1) * MAX_SONGS_ON_LIST; // top limit
					} else if (songListsNumber == songlistsCounter) { // last list, print only left songs
						tempSongCNT = songCounterWAV; // left songs, top limit
					}
					cnt = songlistsCounter * MAX_SONGS_ON_LIST; // bottom limit
				xil_printf("TEMP_SONG_CNT== %d,,,,, songlistCNT== %d, CNT=== %d \n\r",tempSongCNT,songlistsCounter,cnt);
			}
			else{ // less than 5 songs on the list, print exactly the number of songs
				tempSongCNT = songCounterWAV; // top limit
				cnt=0; // bottom limit
			}
			for(cnt;cnt<tempSongCNT;cnt++){
				 	for (int i=0; i < strlen(songList_ptr[cnt]->songName); i++) {
				 		Print_LCD_Txt(StartPosX,StartPosY, ImageBuffer,songList_ptr[cnt]->songName[i], BLACK);
				 		StartPosY = StartPosY + 25;
				 	}
				 	StartPosY = posY; // move on the Y position to print length in the same raw
				 	for (int i=0; i < strlen(songList_ptr[cnt]->songLength); i++) {
				 		Print_LCD_Txt(StartPosX, StartPosY, ImageBuffer,songList_ptr[cnt]->songLength[i], BLACK);
						StartPosY = StartPosY + 25;
					}
				 	StartPosX=StartPosX-47;
				 	StartPosY = 280;
				}
			StartPosX = 390;
			StartPosY = 280;
			printSongListFLAG=0; //prints code above only once
//######################################################################################################
			//print number of songs
			for (int i=0; i < strlen(totalSongsPrint); i++) {
				Print_LCD_Txt(totalSongStart_X,totalSongStart_Y, ImageBuffer,totalSongsPrint[i], BLACK);
				totalSongStart_Y = totalSongStart_Y + 25;
			}
			totalSongStart_X=395;
			totalSongStart_Y=100;

			//Print current list
			//new list has to be filled with white than print new (current) list on the screen
			drawRectangleFilled(listNumberPrintStart_X-10,listNumberPrintStart_Y,
								volumeStartPos_X+20,volumeStartPos_Y+100,ImageBuffer,WHITE);

			for (int i=0; i < strlen(listNumberPrint); i++) {
			Print_LCD_Txt(listNumberPrintStart_X,listNumberPrintStart_Y, ImageBuffer,listNumberPrint[i], BLACK);
			listNumberPrintStart_Y = listNumberPrintStart_Y + 25;
			}
			listNumberPrintStart_X=363;
			listNumberPrintStart_Y=100;

//######################################################################################################
			printVolumeScreenFLAG=1; // can print the volume screen next, when volume switch is triggered

			//draws first rectengular on top - First song selected, later draws the rectengular when returning from different
			//screen on the position where it was previously
			drawRectangleLine(songStartRECT_X-(songCounter*songRECT_Spacing), songStartRECT_Y,
							  songEndRECT_X-(songCounter*songRECT_Spacing),songEndRECT_Y, 3, BLUE, ImageBuffer);

			}



//			printf("DEFAULT STATE\n\r");
			if (Button_Val != 0) { //if button was pressed do it only once
				printf("\n\r BTN_STATE=== %x , Button_Val== %x ",(int)BTN_STATE,(int)Button_Val);
				switch (BTN_STATE) {
				case DOWN:
					songCounter++;
					//songcounter > 4 && there are more songs on sd_card than it's printed up to the current list
					if(songCounter>MAX_SONGS_ON_LIST-1 && songCounterWAV>(MAX_SONGS_ON_LIST-1)*(songlistsCounter+1)){//filesNumber //songCounterWAV

						songCounter=0; // array goes from 0
						songlistsCounter++;
						printSongListFLAG=1; // print new list
						break;
					}
					//if the next list is not full, stop at the last song
					if(songCounter>=songCounterWAV-(songlistsCounter*MAX_SONGS_ON_LIST)){
//						songCounter--; // for stopping at the end of the list

						//Rollover LIST - After reaches the last Song in the LAST LIST goes to the 1st song on 1st list
						songCounter=0; // array goes from 0
						songlistsCounter=0;
						printSongListFLAG=1; // print new list

						break;
					}



					drawRectangleLine(songStartRECT_X-((songCounter-1)*songRECT_Spacing), songStartRECT_Y,
									  songEndRECT_X-((songCounter-1)*songRECT_Spacing),songEndRECT_Y, 3, WHITE, ImageBuffer);
					drawRectangleLine(songStartRECT_X-(songCounter*songRECT_Spacing), songStartRECT_Y,
									  songEndRECT_X-(songCounter*songRECT_Spacing),songEndRECT_Y, 3, BLUE, ImageBuffer);

					printf("\n\r UP____SONG name: %s COUNTER:: %d ",songList_ptr[songCounter+MAX_SONGS_ON_LIST*songlistsCounter]->songName,songCounter);
//					XGpio_DiscreteWrite(&Gpio_LEDs, SINGLE_LED_CHANNEL, LED2); // LED 2 on when btn 1 pressed

					break;
				case UP:
					songCounter--;
					if(songCounter<0){
//						songCounter=0; // for list that goes from 1st song to the end, no ROLLOVER

						// if it's on the 2nd, 3rd or greater list, print one before
						if(songlistsCounter>0){
							songlistsCounter--;
							songCounter=MAX_SONGS_ON_LIST-1;
							printSongListFLAG = 1;
							break;
						}

						//Rollover LIST - when going up, first time songlistCounter=0 then it switches to last list = songListsNumber
						//(songCounterWAV-1) because array starts from 0
						songCounter = (songCounterWAV-1)- (songListsNumber * MAX_SONGS_ON_LIST);
						songlistsCounter = songListsNumber; //
						printSongListFLAG = 1;

					}

					drawRectangleLine(songStartRECT_X-((songCounter+1)*songRECT_Spacing), songStartRECT_Y, songEndRECT_X-((songCounter+1)*songRECT_Spacing),songEndRECT_Y, 3, WHITE, ImageBuffer);
					drawRectangleLine(songStartRECT_X-(songCounter*songRECT_Spacing), songStartRECT_Y, songEndRECT_X-(songCounter*songRECT_Spacing),songEndRECT_Y, 3, BLUE, ImageBuffer);


					printf("\n\r DOWN__SONG name: %s, COUNTER:: %d \n",songList_ptr[songCounter+MAX_SONGS_ON_LIST*songlistsCounter]->songName,songCounter);
//					XGpio_DiscreteWrite(&Gpio_LEDs, SINGLE_LED_CHANNEL, LED1); // LED 2 on when btn 1 pressed

					break;
				case PLAY:

					if(currentPlaying!=songCounter){ //if one song is playing and user selects new one, reset dma, play new one
						XAxiDma_Reset(&AxiDma);
						XAxiDma_IntrEnable(&AxiDma, XAXIDMA_IRQ_IOC_MASK, XAXIDMA_DMA_TO_DEVICE);
					}
					else {  // if the same song is selected wait for the first one to finish
						break;
					}
//					error=Read_SD_Card_short(files[songCounter]);
					error=Read_SD_Card_short(songList_ptr[songCounter+MAX_SONGS_ON_LIST*songlistsCounter]->songName);
					if(error != XST_FAILURE){
						if ((int) fmt_Chunk.Sample_Rate!= currentFS) { //if Fs is different first set codec PLL to new fs
							setCodecPLL(&I2C,(int) fmt_Chunk.Sample_Rate);
							currentFS=(int) fmt_Chunk.Sample_Rate;

						} else {
//							break; // ERROR in PLL STOP EXECUTING
						}
						printf("\n\r PLAYING SONG...");
						drawRectangleLine(songStartRECT_X-(songCounter*songRECT_Spacing), songStartRECT_Y, songEndRECT_X-(songCounter*songRECT_Spacing),songEndRECT_Y, 3, GREEN, ImageBuffer);
						XGpio_DiscreteWrite(&Gpio_LEDs, SINGLE_LED_CHANNEL, LED4); // LED 4 is on when playing song
						audioBlockCounter=0; //always start from block 0
						I2SSend();
						currentPlaying=songCounter;
					} else {
						//Error, song not supported because of the size or Sampling frequency
						drawRectangleLine(songStartRECT_X-(songCounter*songRECT_Spacing), songStartRECT_Y, songEndRECT_X-(songCounter*songRECT_Spacing),songEndRECT_Y, 3, YELLOW, ImageBuffer);
						break;
					}



					break;
				case STOP:
//					XAxiDma_Start(&AxiDma);
					if(currentPlaying==songCounter){ //can only stop if the selection is on the current playing song
					currentPlaying=-1; //next play can start the same song again
					XAxiDma_Reset(&AxiDma);
					XAxiDma_IntrEnable(&AxiDma, XAXIDMA_IRQ_IOC_MASK, XAXIDMA_DMA_TO_DEVICE);
//					XAxiDma_Pause(&AxiDma);
					drawRectangleLine(songStartRECT_X-(songCounter*songRECT_Spacing), songStartRECT_Y, songEndRECT_X-(songCounter*songRECT_Spacing),songEndRECT_Y, 3, RED, ImageBuffer);
					XGpio_DiscreteWrite(&Gpio_LEDs, SINGLE_LED_CHANNEL, LED4 & 0x00); // turn off LED 4
					}
					break;
				default:
//					printf("\n\r----- SONG name: %s, COUNTER:: %d \n",files[songCounter],songCounter);
//					printf("\n\rDEFAULT_SW_STATE_BTN_INVALID\n\r");

					break;

				}
				BTN_STATE=0;
				Button_Val=0;
				//with printf works fine, if commented song is incremented when play is pressed
				printf("\n\r 22_BTN_STATE=== %x , Button_Val== %x ",(int)BTN_STATE,(int)Button_Val);
//				XGpio_DiscreteWrite(&Gpio_LEDs, SINGLE_LED_CHANNEL, (LED1 | LED2)&0x00); // LED 2 on when btn 1 pressed
			}
//********************************************************************************************
//			READ THE REST OF THE FILE
			readFile(AudioBufferSize - MAX_AUDIO_BLOCK_SIZE);


			break;


		case VOLUME:
			if(printVolumeScreenFLAG==1){
				BitMap(ImageBuffer, volume_screen); //prints image to the screen
				snprintf(printVolume,3,"%d",headphones.volume.left/3);

				drawRectangleFilled(volumeStartPos_X,volumeStartPos_Y,volumeStartPos_X+50,volumeStartPos_Y+50,ImageBuffer,WHITE);

				for (int i = 0; i < strlen(printVolume); i++) {
					Print_LCD_Txt(volumeStartPos_X, volumePosition_Y,ImageBuffer, printVolume[i], BLACK);
					volumePosition_Y = volumePosition_Y + 25;
				}
				volumePosition_Y = volumeStartPos_Y; // starts from the beginning

				printVolumeScreenFLAG = 0; //prints above only once
				printSongListFLAG=1; //when returns from volume screen, print song selection screen once
			}

			if (Button_Val != 0) { //if button was pressed do it only once
				switch (Button_Val) {
				case UP:
					tempVolume += volumeStep;
					if (tempVolume <= MAX_Volume) {
						printf("\n\rUP VOLUME== %d", tempVolume);
						setVolume(&headphones, tempVolume);
						printVolumeScreenFLAG=1;
					} else {
						tempVolume = MAX_Volume;
					}
					break;
				case DOWN:
					tempVolume -= volumeStep;
					if (tempVolume >= MIN_Volume) {
						printf("\n\rDOWN VOLUME== %d", tempVolume);
						setVolume(&headphones, tempVolume);
						printVolumeScreenFLAG=1;
					} else {
						tempVolume = MIN_Volume;
					}
					break;
				case PLAY:
				case STOP:
					break;
				default:
//					printf("\n\rBTNS_PLAY_BACK_IN_VOLUME\n\r");
					break;
				}
				Button_Val=0;
			}


			break;
		case OPTIONAL1:
//			drawSquareFilled(0,0,100,RED,ImageBuffer);
//			DrawLetterA(350,280, 2,BLACK, ImageBuffer);
//			DrawLetterB(320,280, 2,BLACK, ImageBuffer);

			//			printf("OPT1 STATE\n\r");
			break;

		case OPTIONAL2:

			//			printf("OPT2 STATE\n\r");
			break;
		default:
			//			printf("ERROR_SW_VALUE_MAIN\n\r");
			break;
		}

	}  // end of while loop
	return 0;
}

/**
 * Configure all drivers for codec
 *
 *
 * @return  status			 	Success or Failure
 *
 * @note	I2C, I2S, FIFO, Interrupt system
 */
int configureALL() {
	int status;

	status = configure_I2C();
	if (status != XST_SUCCESS) {
		xil_printf("IIC Failed\r\n");
		return XST_FAILURE;
	}

	// read the DMA configuration for Xparameters copy those values to
	// Instance structure of this DMA and return result of if config
	// found
	Config = XAxiDma_LookupConfig(DMA_DEV_ID);
	if (!Config) {
		xil_printf("No config found for %d\r\n", DMA_DEV_ID);
		return XST_FAILURE;
	} else {
		xil_printf("Config found for %d\r\n", DMA_DEV_ID);
	}

	/* Initialize DMA engine */
	// configures the DMA hardware with the configuration previously looked up
	status = XAxiDma_CfgInitialize(&AxiDma, Config);
	if (status != XST_SUCCESS) {
		xil_printf("Initialization failed %d\r\n", status);
		return XST_FAILURE;
	} else {
		xil_printf("Initialization DMA Audio Complete\r\n");
	}

	// check if DMA is simple mode or scatter gather(we want simple)
	if (XAxiDma_HasSg(&AxiDma)) {
		xil_printf("Device configured as SG mode \r\n");
		return XST_FAILURE;
	} else {
		xil_printf("Device configured as Simple DMA mode \r\n");
	}

	/* Initialise the GPIO driver and check confirmation */
	status = XGpio_Initialize(&Gpio_LEDs, GPIO_LEDS_ID);
	if (status != XST_SUCCESS) {
		xil_printf("\r\nGPIO LEDs Initialisation Failed\r\n");
		return XST_FAILURE;
	} else {
		print("GPIO LEDs Initialisation Complete\n\r");
	}

	// set GPIO LED both channels to output
	XGpio_SetDataDirection(&Gpio_LEDs, SINGLE_LED_CHANNEL, 0x00);
	XGpio_SetDataDirection(&Gpio_LEDs, RGB_LED_CHANNEL, 0x00);

	/* Initialise the input GPIO driver for switch and buttons */
	status = XGpio_Initialize(&Gpio_SWITCH_BUTTON, GPIO_BTNSW_ID);
	if (status != XST_SUCCESS) {
		xil_printf("GPIO Buttons & Switches Initialisation Failed\r\n");
		return XST_FAILURE;
	} else {
		print("GPIO Buttons & Switches Initialisation Complete\n\r");
	}

	// set both channels of buttons and switches gpio as inputs
	// both buttons and switches (only 4 buttons and 2 switches)
	XGpio_SetDataDirection(&Gpio_SWITCH_BUTTON, BUTTONS_CHANNEL, 0x1F); //0x0F
	XGpio_SetDataDirection(&Gpio_SWITCH_BUTTON, SWITCH_CHANNEL, 0x03);


	status = SetupInterruptSystem(&I2C, &AxiDma, &Gpio_SWITCH_BUTTON, &AxiVdma);
	if (status != XST_SUCCESS) {
		return XST_FAILURE;
	}
	print("INTR_DONE\n\r");

	return status;
}

/**
 * Configures I2C driver
 *
 * @return  status			 	Success or Failure
 *
 * @note	None
 */
int configure_I2C() {
	int Status;
	XIic_Config *ConfigPtr; /* Pointer to configuration data */

	/*
	 * Initialize the IIC driver so that it is ready to use.
	 */
	ConfigPtr = XIic_LookupConfig(I2C_ID);
	if (ConfigPtr == NULL) {
		return XST_FAILURE;
	}
	Status = XIic_CfgInitialize(&I2C, ConfigPtr, ConfigPtr->BaseAddress);
	if (Status != XST_SUCCESS) {
		return XST_FAILURE;
	}
	return Status;

}


/**
 * I2C writes data to the specific register
 *
 * @param 	Address	 	Address of register in Codec
 * @param 	datasend	data to be written to the codec
 *
 * @return  None
 *
 * @note	Delay required after each write
 */
void I2C_send(u16 address, u8 datasend) {
	int byte = 4;
	// 4016, data[0]=0x40 (2bytes), data[1]=0x16, data[2]=0xdata (1 byte)
	u8 data[] = { address >> 8, (u8) address, datasend };

	TransmitComplete=1;

	//Must start I2C before send function
	XIic_Start(&I2C);

	XIic_MasterSend(&I2C, &data, byte); // interrupts work
//	XIic_Send(I2C_BASE_ADDRESS, CODEC_ADDRESS, &data, byte, XIIC_STOP); // without interrupts

	XIic_Stop(&I2C);
	//Must stop I2C after send function

//	xil_printf("\n\r COMPLETE:: %d \n\r",TransmitComplete);


	/*while(TransmitComplete == 1 ){
	 //usleep(2000);
	 xil_printf("\n\r Wait for Complete transaction::");
	 }
	 */
	usleep(2000); //required after each send according to the codec example
}


/**
 * Setup interrupt system
 *
 * @param 	IicInstPtr	 	points to the Xiic Driver data
 *
 * @return  Status 			Success or Failure
 *
 * @note	None
 */
static int SetupInterruptSystem(XIic *IicInstPtr, XAxiDma *AxiDma, XGpio *Gpio_SWITCH_BUTTON, XAxiVdma *AxiVdmaPtr) {
	int Status;
	XScuGic_Config *IntcConfig;

	/*
	 * Initialize the interrupt controller driver so that it is ready to
	 * use.
	 */
	IntcConfig = XScuGic_LookupConfig(INTC_DEVICE_ID);
	if (NULL == IntcConfig) {
		return XST_FAILURE;
	}

	Status = XScuGic_CfgInitialize(&INTC_Inst, IntcConfig,
			IntcConfig->CpuBaseAddress);
	if (Status != XST_SUCCESS) {
		return XST_FAILURE;
	}

//I2C interrupt connection:
	XScuGic_SetPriorityTriggerType(&INTC_Inst, INTC_IIC_ID, 0x40, 0x3);
	/*
	 * Connect the interrupt handler that will be called when an
	 * interrupt occurs for the device.
	 */
	Status = XScuGic_Connect(&INTC_Inst, INTC_IIC_ID,
			(Xil_InterruptHandler) XIic_InterruptHandler, IicInstPtr);
	if (Status != XST_SUCCESS) {
		return Status;
	}
	/*
	 * Enable the interrupt for the IIC device.
	 */
	XScuGic_Enable(&INTC_Inst, INTC_IIC_ID);
//
//DMA interrupt connection:
	XScuGic_SetPriorityTriggerType(&INTC_Inst, INTC_DMA_TX_ID, 0x20, 0x3);
	/*
	 * Connect the interrupt handler that will be called when an
	 * interrupt occurs for the device.
	 */
	Status = XScuGic_Connect(&INTC_Inst, INTC_DMA_TX_ID,
			(Xil_InterruptHandler) TxIntrHandler, AxiDma);
	if (Status != XST_SUCCESS) {
		return Status;
	}
	/*
	 * Enable the interrupt for the DMA device.
	 */
	XScuGic_Enable(&INTC_Inst, INTC_DMA_TX_ID);



// GPIO Switch and buttons interrupt connection

	XScuGic_SetPriorityTriggerType(&INTC_Inst, INTC_GPIO_ID, 0x08, 0x1);
   /*
	* Connect the interrupt handler that will be called when an
    * interrupt occurs for the device.
	*/
	Status = XScuGic_Connect(&INTC_Inst, INTC_GPIO_ID,
			(Xil_ExceptionHandler)BTN_SWITCH_Intr_Handler, Gpio_SWITCH_BUTTON);
	if (Status != XST_SUCCESS) {
		return Status;
	}//
	/*
	 * Enable the interrupt for the GPIO device.
	 */
	XScuGic_Enable(&INTC_Inst, INTC_GPIO_ID);

	print("VDMA LEFT\n\r");
// VDMA INTERRUPT
//	XScuGic_SetPriorityTriggerType(&INTC_Inst, INTC_VDMA_ID, 0x30, 0x1);
//
//	Status = XScuGic_Connect(&INTC_Inst,INTC_VDMA_ID,(Xil_InterruptHandler)XAxiVdma_ReadIntrHandler,(void *)AxiVdmaPtr);
//		if (Status != XST_SUCCESS) {
//			xil_printf("Failed read channel connect intc %d\r\n", Status);
//			return XST_FAILURE;
//		}
//
//	XScuGic_Enable(&INTC_Inst,INTC_VDMA_ID);

	/*
	 * Initialize the exception table and register the interrupt
	 * controller handler with the exception table
	 */
	Xil_ExceptionInit();

	Xil_ExceptionRegisterHandler(XIL_EXCEPTION_ID_INT,
			(Xil_ExceptionHandler) INTC_HANDLER, &INTC_Inst);
	/* Enable non-critical exceptions */
    Xil_ExceptionEnable();


	// DMA Interrupt start:
		XAxiDma_IntrDisable(AxiDma, XAXIDMA_IRQ_IOC_MASK, XAXIDMA_DMA_TO_DEVICE);
		XAxiDma_IntrEnable(AxiDma, XAXIDMA_IRQ_IOC_MASK, XAXIDMA_DMA_TO_DEVICE);


		//XGpio_InterruptGlobalDisable(&Gpio_SWITCH_BUTTON);
	//	//GPIO interrupt enables
    //	 Enable GPIO interrupts interrupt
		XGpio_InterruptEnable(Gpio_SWITCH_BUTTON, XGPIO_IR_MASK);
	//	//Needs to enable Global Interrupt Enable to pass the interrupt to the
		XGpio_InterruptGlobalEnable(Gpio_SWITCH_BUTTON);



	/* Register call-back functions */
//	XAxiVdma_SetCallBack(AxiVdmaPtr, XAXIVDMA_HANDLER_GENERAL, ReadCallBack,
//			(void *) AxiVdmaPtr, XAXIVDMA_READ);
//
//	XAxiVdma_SetCallBack(AxiVdmaPtr, XAXIVDMA_HANDLER_ERROR, ReadErrorCallBack, (void *)AxiVdmaPtr, XAXIVDMA_READ);

	print("VDMA CALLBACK\n\r");
	return XST_SUCCESS;
}

static void I2CSendHandler(XIic *InstancePtr) {
	TransmitComplete = 0;
//	xil_printf("\n\r 1111COMPLETE TRANS:: %d",TransmitComplete);
//	xil_printf("\n\r 222INTERRUPT OCCURED RESET IER:: %x\n\r",XIic_ReadIier(I2C_BASE_ADDRESS));

}

static void I2CReceiveHandler(XIic *InstancePtr) {
	ReceiveComplete = 0;

}


/**
 * Prints data to the serial monitor from array
 *
 * @param 	*samples	 	points to the variable number of samples to print
 * @param 	*data 	     	points to the data array
 *
 * @return  None
 *
 * @note	None
 */
void printData(u8 samples, u8 *data) {

	//xil_printf("\n\rREAD bytes %d ",*samples);
	//***************************************** samples - 1  to print
	for (int i = 0; i < samples-1; i++) {
		xil_printf("\n\rbyte[%d] = 0x%02x ", i+1, data[i]);
	}

}

void I2SSend() {
	/* Flush the SrcBuffer before the DMA transfer, in case the Data Cache
	 * is enabled
	 */
	Xil_DCacheFlushRange((UINTPTR) AudioBuffer, Data_Chunk.Subchunk2_size);
	//CHECK FOR SIZE
	u8 nAudioBlocks=0;
	u32 lastBlockSize=0;
	if(Data_Chunk.Subchunk2_size > MAX_AUDIO_BLOCK_SIZE){ //if audio data is bigger than 8M bytes, divide into blocks
		nAudioBlocks=floor((double)Data_Chunk.Subchunk2_size/MAX_AUDIO_BLOCK_SIZE); //round to the lowest
		printf("\n\r------------------------------------\n\r");
		printf("\nAUDIO SIZE LARGER THAN 8M:: \n\r");
		if(audioBlockCounter<nAudioBlocks){//if current playing block is not the last calculated, send normal block of 4M
		Status = XAxiDma_SimpleTransfer(&AxiDma, (UINTPTR) AudioBuffer+(MAX_AUDIO_BLOCK_SIZE*audioBlockCounter),
					MAX_AUDIO_BLOCK_SIZE, XAXIDMA_DMA_TO_DEVICE);
		printf("CURRENT AUDIO BLOCK:: %d \n\r",audioBlockCounter);
		}
		else if(audioBlockCounter==nAudioBlocks){ //if this is the last block of data, calculate rest of the data to send
			lastBlockSize=Data_Chunk.Subchunk2_size-(audioBlockCounter*MAX_AUDIO_BLOCK_SIZE);
			printf("LAST BLOCK SIZE:: %d \n\r",(int)lastBlockSize);
			Status = XAxiDma_SimpleTransfer(&AxiDma, (UINTPTR) AudioBuffer+(MAX_AUDIO_BLOCK_SIZE*audioBlockCounter),
					lastBlockSize, XAXIDMA_DMA_TO_DEVICE);
			}
		else{ // when the song longer than 40M samples are finished, set block counter to 0, turn off playing LED
			audioBlockCounter=0;
			XGpio_DiscreteWrite(&Gpio_LEDs, SINGLE_LED_CHANNEL, LED4 & 0x00); // turn off LED 4
			printf("RESET & EXIT:: %d \n\r",audioBlockCounter);
			return; //returns from function
		}
	}
	else{
		if(audioBlockCounter>=1){
			audioBlockCounter=0;
			XGpio_DiscreteWrite(&Gpio_LEDs, SINGLE_LED_CHANNEL, LED4 & 0x00); // turn off LED 4
			return;
		}
		else{
			Status = XAxiDma_SimpleTransfer(&AxiDma, (UINTPTR) AudioBuffer,
					Data_Chunk.Subchunk2_size, XAXIDMA_DMA_TO_DEVICE);
			printf("\n\rRESET & EXIT ONE BLOCK ONLY:: %d \n\r",audioBlockCounter);
		}
	}
	printf("TOTAL AUDIO BLOCKS:: %d \n\r",nAudioBlocks);
	printf("DMA Status: %d \n\r", Status);
	printf("------------------------------------\n\r");
}

int Read_SD_Card_short(char *filename) {
	// move below to be not local to Read_SD_Card_short ONLY

//	FIL file; // file structure information
//	UINT nBytesRead = 0;


	//for testing
	//printf("Read_SD_Card function entered\n\r");

	//File function return code (FRESULT)
	//result is the instance of (FRESULT) containing the result of the function f_open
	//FRESULT f_open (FIL* fp, const TCHAR* path, BYTE mode);/* Open or create a file */

	FRESULT result = f_open(&file, filename, FA_READ);
	if (result != 0) {
		printf("File not found result = %u\n\r", result);
	}
	/*
	 else{
	 printf("File: %s Found\r\n",filename);
	 }
	 */

	// Read the RIFF header
	// read the file &file
	// (void*)&RIFF_Info address of array provided
	// sizeof(RIFF_Info) size of each element of array total
	//&nBytesRead number of bytes of the array to read
	result = f_read(&file, (void*) &RIFF_Info, sizeof(RIFF_Info), &nBytesRead);

	// check if read was successful
	/*
	 if (result!=0) {
	 printf("Failed to read file\n\r");
	 }
	 else{
	 printf("file read for RIFF header successful\n\r");
	 }
	 */
	//compares the first n bytes of structure element RIFF_Info.riff and character array "RIFF".
	// result
	// if (memcmp(RIFF_Info.ChunkID,"RIFF",4)!=0) {
	//	printf("Illegal file format. RIFF not found\n\r");
	// }
	// else{
	printf("RIFF_Chunk_t.ChunkID = %.4s\n\r", RIFF_Info.ChunkID);
	//}

	printf("RIFF_Chunk_t.ChunkSize = %lu\n\r",
			(unsigned long) RIFF_Info.ChunkSize);

	//if (memcmp(RIFF_Info.Format,"WAVE",4)!=0) {
	//	 printf("Illegal file format. WAVE not found\n\r");
	//}
	//else{
	printf("RIFF_Chunk_t.ChunkID = %.4s\n\r", RIFF_Info.Format);
	//}

	//the RIFF Chunk reading is complete
	//printf("the RIFF Chunk reading is completed\n\r\n\r\n\r\n\r\n\r\n\r");

	// Read the fmt_Chunk
	// read the file &file
	// (void*)&fmt_Info address of array provided
	// sizeof(fmt_Info) size of each element of array total
	//&nBytesRead number of bytes of the array to read

	result = f_read(&file, (void*) &fmt_Chunk, sizeof(fmt_Chunk), &nBytesRead);
	// check if read was successful
	//if (result!=0) {
	//	   printf("Failed to read file\n\r");
	//}
	//else{
	//	   printf("file read for fmt header successful\n\r");
	//}

	//check the fmt section via the structure fmt_Chunk_t;
	// this section holds all of the sampling informtaion for the music

	//u32 Subchunk1_ID;   // big endian       Should contain the letters "fmt " note the extra empty charachter value
	//u32 Subchunk1_Size; // little endian    16 for PCM.  This is the size of the  rest of the Subchunk which follows this number.
	//u16 Audio_Format;   // little endian    PCM = 1 (i.e. Linear quantization) Values other than 1 indicate some form of compression.
	//u16 Num_Channels;   // little endian    Mono = 1, Stereo = 2, etc.
	//u32 Sample_Rate;    // little endian    8000, 44100, etc.
	//u32 ByteRate;       // little endian    == SampleRate * NumChannels * BitsPerSample/8
	//u16 Block_Align;    // little endian    == NumChannels * BitsPerSample/8
	// The number of bytes for one sample including
	// all channels.
	//u16 Bits_Per_Sample;// little endian    8 bits = 8, 16 bits = 16, etc.

	//fmt_Chunk_t fmt_Chunk;
	// check for the word data in correct position
	//if (memcmp(fmt_Chunk.Subchunk1_ID,"fmt ",4)!=0) {
	//	  printf("'fmt' word not found.\n\r");
	//	  printf("fmt_Chunk.Subchunk1_ID = %s\r\n",fmt_Chunk.Subchunk1_ID);
	//}
	//else{
	printf("fmt_Chunk.Subchunk1_ID = %.3s\r\n", fmt_Chunk.Subchunk1_ID);
	//}

	//check the size of the sub chunk
	//printf("Subchunk1_Size:\n\r");
	printf("Data_Chunk.Subchunk1_Size = %u\r\n",
			(int) Data_Chunk.Subchunk2_size);
	// https://en.wikipedia.org/wiki/Pulse-code_modulation
	//printf("expected 16 which means PCM (Pulse Code Modulation)\n\r");

	// check the audio format
	//Type of format (1 is PCM) - 2 byte integer
	//Audio_Format
	printf("fmt_Chunk.Audio_Format = %u\n\r", (int) fmt_Chunk.Audio_Format);
	//printf("expected 1 which means PCM \n\r");

	//Num_Channels
	// for stereo = 2
	// for mono = 1
	printf("fmt_Chunk.Num_Channels = %u\r\n", (int) fmt_Chunk.Num_Channels);
	//printf("expected 2 which means stereo  \n\r");

	//Sample_Rate
	// Sample rate is the number of samples of audio carried per second, measured in Hz or kHz
	// (one kHz being 1000 Hz). For example, 44100 samples per second can be expressed as
	// either 44100 Hz, or 44.1 kHz. ... The sample rate determines the maximum audio frequency
	//that can be reproduced.
	printf("fmt_Chunk.Sample_Rate = %u\r\n", (int) fmt_Chunk.Sample_Rate);
	//printf("best value should be 44100 that is maximum\n\r");

	//ByteRate
	//The audio data rate in bytes/sec.
	// == SampleRate * NumChannels * BitsPerSample/8
	printf("fmt_Chunk.ByteRate = %lu\r\n", (unsigned long) fmt_Chunk.ByteRate);

	// Block_Align
	// Block_Align == NumChannels * BitsPerSample/8
	// The number of bytes for one sample including all channels.
	// example : For 16-bit PCM format stereo audio, the block alignment value is 4.
	printf("fmt_Chunk.Block_Align = %u\r\n", (int) fmt_Chunk.Block_Align);
	//printf("block align value should be 4\n\r");

	//u16 Bits_Per_Sample;
	// little endian    8 bits = 8, 16 bits = 16, etc.
	// number of bits per sample usually 16 for .WAV
	printf("fmt_Chunk.Bits_Per_Sample = %u \n\r",
			(int) fmt_Chunk.Bits_Per_Sample);
	//printf("number of bits per sample = %u \n\r",(int)fmt_Chunk.Bits_Per_Sample);

	// reading Data Chunk file data
	// read chunk header
	//Data_Chunk_t Data_Chunk;

	// Read the Data_Chunk header
	// read the file &file
	// (void*)&Data_Chunk address of array provided
	// size of(Data_Chunk) size of each element of array total
	//&nBytesRead number of bytes of the array to read

int nchar=50, nbytes=4, j;
int k=0,m=0,p;
char array[nchar], subchunk_ID[nbytes];
u8 subchunk_SIZE_mid[nbytes];
u8 subchunk_SIZE[nbytes];

	result = f_read(&file, (void*) &array, sizeof(array),&nBytesRead);
	for(int i=0;i<nchar;i++){
		//when "data" is found, save the current position and extract data and size
		if(array[i]=='d' && array[i+1]=='a'&& array[i+2]=='t'&& array[i+3]=='a'){
			j=i;
//			printf("\n\r array[%d]= %c",i,array[i]);
			for(j;j<nchar;j++){ // goes from the found position to the end of char array
				if(k<nbytes){  // works for only defined number of bytes, starts from 'd' char (position)
					subchunk_ID[k]=array[j]; //saves 'data' to the array from position zero '0'
//					printf("\n\r subchunk_ID[%d]= %c",k,subchunk_ID[k]);
					k++;
				}
					if(array[j-1]=='a' && (array[j-2]=='t' || array[j]==0x00)){ // check if "ta" are the last one or "a0" is the last
						p=j;
						for(p;p<nchar;p++){
							if(m<nbytes){
							subchunk_SIZE_mid[m]=array[p];//saves size to the array from position zero '0'
//							printf("\n\r subchunk_SIZE[%d]= %x",m,subchunk_SIZE[m]);
							m++;
							}

						}
					}
//					break;
				}
//			snprintf(subchunk_ID,5,"%s",data_chunk);
			strncpy(Data_Chunk.Subchunk2_ID,subchunk_ID,4);
//			strncpy(Data_Chunk.Subchunk2_size,subchunk_SIZE,4);
//			printf("\n\r subchunk_ID== %s \n\r",subchunk_ID);
//			printf("\n\r subchunk_SIZE_MID== %d \n\r",subchunk_SIZE_mid);
//			break;
		}

	}
	//check values stored inside u32 arrays
//	for(int i=0;i<nbytes;i++){
//		printf("\n\r subchunk_ID[%d]= %c",i,subchunk_ID[i]);
//	}
//	for(int i=0;i<nbytes;i++){
//			printf("\n\r subchunk_SIZE_mid[%d]= %x\n",i,subchunk_SIZE_mid[i]);
//		}

	//Reversing subchunk size to big endian
	for(int i=0;i<nbytes+1;i++){
			subchunk_SIZE[i]=subchunk_SIZE_mid[nbytes-i-1];
	}
	//print big endian
//	for(int i=0;i<nbytes;i++){
//				printf("\n\r CHANGED subchunk_SIZE[%d]= %x\n",i,subchunk_SIZE[i]);
//			}

	u32 temp=0;
	//Sets the size hex into one variable for data_chunk.subchunk2_size struct
	temp=(subchunk_SIZE[0]<<8 | subchunk_SIZE[1])<<16 | subchunk_SIZE[2]<<8 |subchunk_SIZE[3];
//	printf("\n\r Temp= %x\n", temp);
	Data_Chunk.Subchunk2_size=temp;


//	 check for the word data in correct position
//	 if (memcmp(Data_Chunk.Subchunk2_ID,"data",4)!=0) {
//	 	     	 printf("data word not found.\n\r");
//		     	 printf("Data_Chunk_t.Subchunk2_ID = %s\r\n",Data_Chunk.Subchunk2_ID);
//	}
	// else{
	printf("Data_Chunk_t.Subchunk2_ID = %.4s\n\r", Data_Chunk.Subchunk2_ID);
	// }

	//check the size of the song data
	// printf("size of the song data in bytes:\n\r");
	printf("Data_Chunk.Subchunk2_size = %lu\r\n",
			(unsigned long) Data_Chunk.Subchunk2_size);

	printf("\n\r AFTER_DATA_SUBCHUNK_2\n\r");

	// normal version
	// size of audio buffer = size of audio song data
	//AudioBuffer = malloc(Data_Chunk.Subchunk2_size);
	//	printf("\n\r\n\r");
	// if (!AudioBuffer){
	// 	printf("Could not allocate memory\n\r");
	// }
	//else{
	//   printf("audio buffer size changed to match the audio data size as per header file\n\r");
	// }
	if((int)fmt_Chunk.Sample_Rate != samplingFrequency1 && (int)fmt_Chunk.Sample_Rate != samplingFrequency2)
	{
		printf("\n\n\n!!!!SAMPLING RATE NOT SUPPORTED!!!! \n\r");
		printf("!!!!CAN NOT PLAY THE SONG!!!! \n\r");
		return XST_FAILURE;
	}

	if(Data_Chunk.Subchunk2_size <= MAX_AUDIO_SIZE){
		printf("\n\r BEFORE_FILE_READ \n\r");

		AudioBufferSize = Data_Chunk.Subchunk2_size;
		//AudioBufferSize = MAX_AUDIO_BLOCK_SIZE;
//		printf("audio buffer size variable equal to audio data size as per header file\n\r");
		printf("\n\r AUDIO_BUFFER_SIZE<<>> \n\r");

		// read the WAV file
		result= readFile(MAX_AUDIO_BLOCK_SIZE);

//		result = f_read(&file, (void*) AudioBuffer, AudioBufferSize,&nBytesRead);
		if (result != 0) {
			printf("Failed to read file\n\r");
		} else {
			printf("read the file\n\r");
		}

		//number of bytes read
		printf("\n\r NbytesRead== %d \n\r", nBytesRead);

//***********************************************************************************************************
		// read 8 bytes less than one stored in the Data_Chunk.Subchunk2_size for mambo no5.wav and all stars.wav
		//
		if (nBytesRead < AudioBufferSize - 10) {
			printf("Didn't read the complete file\n\r");
		} else {
			printf("read the complete file\n\r");
//		int i = 0;
//		for (i = 0; i < (AudioBufferSize); i++) {
//			//nop
//		}
//		printf("number of buffer size = %u\n\r", i);
//		printf("Address of Audio buffer= %p\n\r", AudioBuffer);
		}


	}


	else{
		printf("Song is too long!!!\n\r");
		return XST_FAILURE;
	}

}


//#############################################################################
void Open_File_Directory(void) {
	// Look for *.wav files and copy file names to files[]
	//DIR structure for file directory
	//DIR directory;
	//FRESULT f_opendir (DIR* dp, const TCHAR* path);
	// argument 1 = instance of directory
	// argument 2 = file path
	FRESULT result = f_opendir(&directory, "0:/");
	if (result != FR_OK) {
		print("Couldn't read root directory. Press RETURN to try again\r\n");
		getchar();
		//continue;
	} else {
		print("Could read root directory for files on the SD card\r\n");
	}
}
//#############################################################################
void Copy_WAV_File_Names(void) {
	// 2 dimensional character array
	// name = files
	// type = charachter
	// value of maxFiles is number of rows
	// value of columns = 32
	// all contain the value 0
	// this means that there can be value of max files names
	// each name can be 32 characters long
	// moved to global
	//char files[maxFiles][32] = {0};

	// number of .WAV files within the  SD card
//	int filesNumber = 0;

	songList_ptr[0]=(songList_t *)malloc(sizeof(songList_t)); //allocate memory for one song

	for (;;) {
		// structure containing file information:
		/* File size            .fsize
		 * Last modified date   .fdate
		 * Last modified time   .ftime
		 * Attribute            .fattrib
		 * Short file name      .fname[13];
		 */
//		FILINFO file_Info;

		FRESULT result = f_readdir(&directory, &file_Info);
		// if there are no more files it jumps out of for loop
		if (result != FR_OK || file_Info.fname[0] == 0) {
			print("no more files jumping from loop\r\n");
			free(songList_ptr[songCounterWAV]); // Free last allocated memory because there is no more WAV files
			break;
		}

		// checks file attribute and if its a file directory it enters and does nothing
		if (file_Info.fattrib & AM_DIR) {
			// its a directory to further files do nothing
			print("directory ignored\r\n");
		}
		// checks if the files name makes it a wav file
		else if (strstr(file_Info.fname, ".wav") != NULL
				|| strstr(file_Info.fname, ".WAV") != NULL) {

			// It's a WAV file
			//copies the file name into the files array
			// increments the current row number within files
//			strcpy(files[filesNumber], file_Info.fname);
			// file name has 12 charachters max
//			xil_printf("%s  file name copied \r\n", file_Info.fname);
			//xil_printf("file name that we will test will be %s\r\n", files[0]);
			//PIANO1~1.WAV is the current file test name

			strcpy(songList_ptr[songCounterWAV]->songName,file_Info.fname);

			result = f_open(&file, songList_ptr[songCounterWAV]->songName, FA_READ);
			if (result != 0) {
				printf("File not found result = %u\n\r", result);
			}
			result = f_read(&file, (void*) &RIFF_Info, sizeof(RIFF_Info), &nBytesRead);
			if (result != 0) {
				printf("ERROR READING RIFF_INFO = %u\n\r", result);
			}

			result = f_read(&file, (void*) &fmt_Chunk, sizeof(fmt_Chunk), &nBytesRead);
			if (result != 0) {
				printf("ERROR READING FMT_CHUNK = %u\n\r", result);
			}


			int nchar=50, nbytes=4, j;
			int k=0,m=0,p;
			char array[nchar], subchunk_ID[nbytes];
			u8 subchunk_SIZE_mid[nbytes];
			u8 subchunk_SIZE[nbytes];

			result = f_read(&file, (void*) &array, sizeof(array), &nBytesRead);

			for (int i = 0; i < nchar; i++) {
				//when "data" is found, save the current position and extract data and size
				if (array[i] == 'd' && array[i + 1] == 'a'
						&& array[i + 2] == 't' && array[i + 3] == 'a') {
					j = i;
					//			printf("\n\r array[%d]= %c",i,array[i]);
					for (j; j < nchar; j++) { // goes from the found position to the end of char array
						if (k < nbytes) { // works for only defined number of bytes, starts from 'd' char (position)
							subchunk_ID[k] = array[j]; //saves 'data' to the array from position zero '0'
							//					printf("\n\r subchunk_ID[%d]= %c",k,subchunk_ID[k]);
							k++;
						}
						if (array[j - 1] == 'a'
								&& (array[j - 2] == 't' || array[j] == 0x00)) { // check if "ta" are the last one or "a0" is the last
							p = j;
							for (p; p < nchar; p++) {
								if (m < nbytes) {
									subchunk_SIZE_mid[m] = array[p]; //saves size to the array from position zero '0'
									//							printf("\n\r subchunk_SIZE[%d]= %x",m,subchunk_SIZE[m]);
									m++;
								}

							}
						}
						//					break;
					}
					//			snprintf(subchunk_ID,5,"%s",data_chunk);
					strncpy(Data_Chunk.Subchunk2_ID, subchunk_ID, 4);
					//			strncpy(Data_Chunk.Subchunk2_size,subchunk_SIZE,4);
					//			printf("\n\r subchunk_ID== %s \n\r",subchunk_ID);
					//			printf("\n\r subchunk_SIZE_MID== %d \n\r",subchunk_SIZE_mid);
					//			break;
				}

			}
			//Reversing subchunk size to big endian
			for (int i = 0; i < nbytes + 1; i++) {
				subchunk_SIZE[i] = subchunk_SIZE_mid[nbytes - i - 1];

			}
			u32 temp = 0;
			//Sets the size hex into one variable for data_chunk.subchunk2_size struct
			temp = (subchunk_SIZE[0] << 8 | subchunk_SIZE[1]) << 16
					| subchunk_SIZE[2] << 8 | subchunk_SIZE[3];
			//	printf("\n\r Temp= %x\n", temp);
			Data_Chunk.Subchunk2_size = temp;


//			xil_printf("DATA_SIZE_READ == %d\n\r",Data_Chunk.Subchunk2_size);



			//Calculate minutes and seconds of the song
			u32 min, seconds;
			seconds=Data_Chunk.Subchunk2_size/fmt_Chunk.ByteRate;
			if(seconds>59){
				min=seconds/60;
				seconds=seconds-min*60;
			}
			else{
				min=0;
			}

			//CALCULATE THE SIZE OF THE SONG IN Mb
			u32 bytes,megaBytes=0;
			char sizeDesignator[3];
			bytes=file_Info.fsize/1000 ;
			if(bytes>1024){
				megaBytes=bytes/1024;
				bytes=bytes-megaBytes*1024;
				snprintf(sizeDesignator,3,"%s","MB");
			}

			snprintf(songList_ptr[songCounterWAV]->songLength, 7, "%d:%.2d", (int)min,(int)seconds);
			snprintf(songList_ptr[songCounterWAV]->songSizeMb, 12, "%d.%.3d %s",(int)megaBytes, (int)bytes, sizeDesignator);
			songList_ptr[songCounterWAV]->songAverageBytePerSec = fmt_Chunk.ByteRate;
			songList_ptr[songCounterWAV]->songNChannels = fmt_Chunk.Num_Channels;
			songList_ptr[songCounterWAV]->songSamplingRate = fmt_Chunk.Sample_Rate;

//			xil_printf("SONG_PTR_LIST=== %s, samplingrate==%d\r\n",songList_ptr[filesNumber]->songName,
//								songList_ptr[filesNumber]->songSamplingRate );

//			xil_printf("test_VALL=== %d:%d, BUFFER:: %s \r\n",min,seconds,songList[filesNumber].songLength);
//			xil_printf("SIZZEOFF=== %x \r\n",sizeof(songList_ptr));
			xil_printf("SONG LIST:\n song[%d] \tname: %s \tsize: %s \tlength: %s \r\n",
					songCounterWAV+1,
					songList_ptr[songCounterWAV]->songName,
					songList_ptr[songCounterWAV]->songSizeMb,
					songList_ptr[songCounterWAV]->songLength);

			songCounterWAV++;

			//Allocate another memory location for new song info
			songList_ptr[songCounterWAV] = (songList_t *) realloc(songList_ptr,sizeof(songList_t));


		} else {
			// It's a file that is not a WAV/wav file so does nothing and ignores is
			print("file that is not .wav type ignored\r\n");
		}

//		if (filesNumber == maxFiles) {
//			print("\r\n\r\nMAX number of .wav names copied\r\n");
//			break;
//
//		}
	}
	// closes the file directory
	f_closedir(&directory);
	print("\r\nfile directory closed\r\n");

	if (songCounterWAV == 0) {
		print("No WAV files found. Press RETURN to try again\r\n");
		//getchar();
		//continue;
	}
}
//#############################################################################
//
/******************************************************************************/
void TxIntrHandler(void *Callback) {
	print("DMA AUDIO Transmit complete\r\n");
	u32 IrqStatus;
	int TimeOut;


	XAxiDma *AxiDmaInst = (XAxiDma *) Callback;

	/* Read pending interrupts */
	IrqStatus = XAxiDma_IntrGetIrq(AxiDmaInst, XAXIDMA_DMA_TO_DEVICE);

	/* Acknowledge pending interrupts */

	XAxiDma_IntrAckIrq(AxiDmaInst, IrqStatus, XAXIDMA_DMA_TO_DEVICE);

	/*
	 * If no interrupt is asserted, we do not do anything
	 */
	if (!(IrqStatus & XAXIDMA_IRQ_ALL_MASK)) {

		return;
	}

	/*
	 * If error interrupt is asserted, raise error flag, reset the
	 * hardware to recover from the error, and return with no further
	 * processing.
	 */
	if ((IrqStatus & XAXIDMA_IRQ_ERROR_MASK)) {

		Error = 1;

		/*
		 * Reset should never fail for transmit channel
		 */
		XAxiDma_Reset(AxiDmaInst);

		TimeOut = RESET_TIMEOUT_COUNTER;

		while (TimeOut) {
			if (XAxiDma_ResetIsDone(AxiDmaInst)) {
				break;
			}

			TimeOut -= 1;
		}

		return;
	}

	/*
	 * If Completion interrupt is asserted, then set the TxDone flag
	 */
	if ((IrqStatus & XAXIDMA_IRQ_IOC_MASK)) {
		TxDone = 1;
		audioBlockCounter++;
		I2SSend();
	}
}

/*****************************************************************************/

void BTN_SWITCH_Intr_Handler() {
	u32 currentButton;
	// Disable further GPIO interrupts
	XGpio_InterruptDisable(&Gpio_SWITCH_BUTTON, XGPIO_IR_MASK);

	/* Wait a small amount of time to remove debounce */
	//	    	for (Delay = 0; Delay < ISR_DELAY; Delay++);
	if ((XGpio_InterruptGetStatus(&Gpio_SWITCH_BUTTON)) == 2) {

		// read the switch value
		Switch_Val = XGpio_DiscreteRead(&Gpio_SWITCH_BUTTON, SWITCH_CHANNEL);
//		xil_printf("Switch_Val = %lu\n\r", (unsigned long) Switch_Val);
		SW_STATE=Switch_Val;
		switch (Switch_Val) {

		case 0:

			xil_printf("switch val = 0\n\r");

			break;

		case 1:
			xil_printf("switch val = 1\n\r");
			break;

		case 2:
			xil_printf("switch val = 2\n\r");
			break;

		case 3:
			xil_printf("switch val = 3\n\r");
			break;

		default:
			xil_printf("switch val default error\n\r");
			break;

		}  // end of case statement

	}

	if ((XGpio_InterruptGetStatus(&Gpio_SWITCH_BUTTON)) == 1) {

		// read the button value
		// And with 0x0F due to 0x10 is SD_CARD DETECT which will be used inside the main
		currentButton = XGpio_DiscreteRead(&Gpio_SWITCH_BUTTON, BUTTONS_CHANNEL);// & 0x0F;
//		xil_printf("CURRENT_Button_Val = %lu\n\r", (unsigned long)currentButton);
//		if(Button_Val==0) break;

		// testing current button value

#ifdef TESTING
		xil_printf("Button_Val = %lu\n\r", (unsigned long)Button_Val);
#endif

		switch (currentButton) {

		case 0:
			goto end; // 2nd interrupt (release of the button) go to end, line 1875

#ifdef TESTING
			xil_printf("Button Released\n\r");
#endif

			break;

		case 1:
			Button_Val=1;
			xil_printf("Button 0 pressed\n\r");
			break;

		case 2:
			Button_Val=2;
			xil_printf("Button 1 pressed\n\r");
			break;

		case 4:
			Button_Val=4;
			xil_printf("Button 2 pressed\n\r");
			break;

		case 8:
			Button_Val=8;
			xil_printf("Button 3 pressed\n\r");
			break;

		default:
			xil_printf("Button pressed Default error\n\r");
			break;

		}  // end of case statement

	} // else if end
	BTN_STATE=Button_Val;
	xil_printf("Button val:::: %dx\n\r",Button_Val);

//2nd interrupt skip everything, jump here
end:

	//clear the interrupt flag
	(void) XGpio_InterruptClear(&Gpio_SWITCH_BUTTON, XGPIO_IR_MASK);

	// Enable GPIO interrupts at the exit of the ISR
	XGpio_InterruptEnable(&Gpio_SWITCH_BUTTON, XGPIO_IR_MASK);


}



int readFile(u32 AudioDataSizeToRead){
	return f_read(&file, (void*) AudioBuffer, AudioDataSizeToRead,&nBytesRead);
}
