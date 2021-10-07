/*
 * sd_card.c
 *
 *  Created on: 8 Jan 2021
 *      Author: oliver
 */
#include "ff.h"
#include "xil_printf.h"
#include "SD_card.h"

const char Drive0Path[3] = {'0', ':', '/'};
const char Drive1Path[3] = {'1', ':', '/'};

RIFF_Chunk_t RIFF_Info;
fmt_Chunk_t fmt_Chunk; //sampling rate ... etc.
Data_Chunk_t Data_Chunk;

//##################################################################################
void Check_SD_Card_Mounted(FATFS FS_instance) {

	//FATFS SDcard_files1;
	//FATFS FS_instance;
	FRESULT result = f_mount(&FS_instance, Drive0Path, DoNotMountSDCard);
	if (result != 0) {
		xil_printf("No SD Card mounted, please insert and restart program.\r\n");
	} else {
		xil_printf("SD Card is mounted\r\n");
	}
}

//#############################################################################
void Read_SD_Card(char *filename, size_t AudioBufferSize, u8 *AudioBuffer) {
//	RIFF_Chunk_t RIFF_Info;
//	fmt_Chunk_t fmt_Chunk;
//	Data_Chunk_t Data_Chunk;
	FIL file; // file structure information
	UINT nBytesRead = 0;

	//for testing
	printf("Read_SD_Card function entered\n\r");

	//File function return code (FRESULT)
	//result is the instance of (FRESULT) containing the result of the function f_open
	//FRESULT f_open (FIL* fp, const TCHAR* path, BYTE mode);/* Open or create a file */

	FRESULT result = f_open(&file, filename, FA_READ);
	if (result != 0) {
		printf("File not found result = %u\n\r", result);
	} else {
		printf("File: %s Found\r\n", filename);
	}

	// Read the RIFF header
	// read the file &file
	// (void*)&RIFF_Info address of array provided
	// sizeof(RIFF_Info) size of each element of array total
	//&nBytesRead number of bytes of the array to read
	result = f_read(&file, (void*) &RIFF_Info, sizeof(RIFF_Info), &nBytesRead);

	// check if read was successful
	if (result != 0) {
		printf("Failed to read file\n\r");
	} else {
		printf("file read for RIFF header successful\n\r");
	}

	//compares the first n bytes of structure element RIFF_Info.riff and character array "RIFF".
	// result
	if (memcmp(RIFF_Info.ChunkID, "RIFF", 4) != 0) {
		printf("Illegal file format. RIFF not found\n\r");
	} else {
		printf("RIFF_Chunk_t.ChunkID = %.4s\n\r", RIFF_Info.ChunkID);
	}

	printf("RIFF_Chunk_t.ChunkSize = %lu\n\r",
			(unsigned long) RIFF_Info.ChunkSize);

	if (memcmp(RIFF_Info.Format, "WAVE", 4) != 0) {
		printf("Illegal file format. WAVE not found\n\r");
	} else {
		printf("RIFF_Chunk_t.ChunkID = %.4s\n\r", RIFF_Info.Format);
	}

	//the RIFF Chunk reading is complete
	printf("the RIFF Chunk reading is completed\n\r\n\r\n\r\n\r\n\r\n\r");

	// Read the fmt_Chunk
	// read the file &file
	// (void*)&fmt_Info address of array provided
	// sizeof(fmt_Info) size of each element of array total
	//&nBytesRead number of bytes of the array to read

	result = f_read(&file, (void*) &fmt_Chunk, sizeof(fmt_Chunk), &nBytesRead);
	// check if read was successful
	if (result != 0) {
		printf("Failed to read file\n\r");
	} else {
		printf("file read for fmt header successful\n\r");
	}

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
	if (memcmp(fmt_Chunk.Subchunk1_ID, "fmt ", 4) != 0) {
		printf("'fmt' word not found.\n\r");
		printf("fmt_Chunk.Subchunk1_ID = %s\r\n", fmt_Chunk.Subchunk1_ID);
	} else {
		printf("fmt_Chunk.Subchunk1_ID = %.3s\r\n", fmt_Chunk.Subchunk1_ID);
	}

	//check the size of the sub chunk
	printf("Subchunk1_Size:\n\r");
	printf("Data_Chunk.Subchunk1_Size = %u\r\n",
			(int) Data_Chunk.Subchunk2_size);
	// https://en.wikipedia.org/wiki/Pulse-code_modulation
	printf("expected 16 which means PCM (Pulse Code Modulation)\n\r");

	// check the audio format
	//Type of format (1 is PCM) - 2 byte integer
	//Audio_Format
	printf("fmt_Chunk.Audio_Format = %u\n\r", (int) fmt_Chunk.Audio_Format);
	printf("expected 1 which means PCM \n\r");

	//Num_Channels
	// for stereo = 2
	// for mono = 1
	printf("fmt_Chunk.Num_Channels = %u\r\n", (int) fmt_Chunk.Num_Channels);
	printf("expected 2 which means stereo  \n\r");

	//Sample_Rate
	// Sample rate is the number of samples of audio carried per second, measured in Hz or kHz
	// (one kHz being 1000 Hz). For example, 44100 samples per second can be expressed as
	// either 44100 Hz, or 44.1 kHz. ... The sample rate determines the maximum audio frequency
	//that can be reproduced.
	printf("fmt_Chunk.Sample_Rate = %u\r\n", (int) fmt_Chunk.Sample_Rate);
	printf("best value should be 44100 that is maximum\n\r");

	//ByteRate
	//The audio data rate in bytes/sec.
	// == SampleRate * NumChannels * BitsPerSample/8
	printf("fmt_Chunk.ByteRate = %lu\r\n", (unsigned long) fmt_Chunk.ByteRate);

	// Block_Align
	// Block_Align == NumChannels * BitsPerSample/8
	// The number of bytes for one sample including all channels.
	// example : For 16-bit PCM format stereo audio, the block alignment value is 4.
	printf("fmt_Chunk.Block_Align = %u\r\n", (int) fmt_Chunk.Block_Align);
	printf("block align value should be 4\n\r");

	//u16 Bits_Per_Sample;
	// little endian    8 bits = 8, 16 bits = 16, etc.
	// number of bits per sample usually 16 for .WAV
	printf("fmt_Chunk.Bits_Per_Sample = %u \n\r",
			(int) fmt_Chunk.Bits_Per_Sample);
	printf("number of bits per sample = %u \n\r",
			(int) fmt_Chunk.Bits_Per_Sample);

	// reading Data Chunk file data
	// read chunk header
	//Data_Chunk_t Data_Chunk;

	// Read the Data_Chunk header
	// read the file &file
	// (void*)&Data_Chunk address of array provided
	// size of(Data_Chunk) size of each element of array total
	//&nBytesRead number of bytes of the array to read
	result = f_read(&file, (void*) &Data_Chunk, sizeof(Data_Chunk),
			&nBytesRead);
	if (result != 0) {
		printf("Failed to read file\n\r");
	} else {
		printf("file read\n\r");
	}

	// check for the word data in correct position
	if (memcmp(Data_Chunk.Subchunk2_ID, "data", 4) != 0) {
		printf("data word not found.\n\r");
		printf("Data_Chunk_t.Subchunk2_ID = %s\r\n", Data_Chunk.Subchunk2_ID);
	} else {
		printf("Data_Chunk_t.Subchunk2_ID = %.4s\n\r", Data_Chunk.Subchunk2_ID);
	}

	//check the size of the song data
	printf("size of the song data in bytes:\n\r");
	printf("Data_Chunk.Subchunk2_size = %lu\r\n",
			(unsigned long) Data_Chunk.Subchunk2_size);

	// audio data to the heap not the ddr

	// size of audio buffer = size of audio song data
	//AudioBuffer = malloc(Data_Chunk.Subchunk2_size);
	// if (!AudioBuffer){
	//	printf("Could not allocate memory\n\r");
	//}
	//else{
	//   printf("audio buffer size changed to match the audio data size as per header file\n\r");
	// }
	AudioBufferSize = Data_Chunk.Subchunk2_size;
	printf(
			"audio buffer size variable equal to audio data size as per header file\n\r");

	// read the file
	result = f_read(&file, (void*) AudioBuffer, AudioBufferSize, &nBytesRead);
	if (result != 0) {
		printf("Failed to read file\n\r");
	} else {
		printf("read file\n\r");
	}
	if (nBytesRead != AudioBufferSize) {
		printf("Didn't read the complete file");
	} else {
		printf("read the complete file");

	}

}
