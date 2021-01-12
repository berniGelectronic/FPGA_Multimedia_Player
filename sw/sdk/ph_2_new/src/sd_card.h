/*
 * sd_card.h
 *
 *  Created on: 3 Jul 2020
 *      Author: admin
 */

#ifndef SRC_SD_CARD_H_
#define SRC_SD_CARD_H_


#include "xil_types.h"
//#include "IP_defines.h"
//#include "ff.h"

# define DoNotMountSDCard 0
# define MountSDCard 1




//the RIFF Chunk
typedef struct {
	char ChunkID[4]; // big endian should contain "RIFF"
	u32 ChunkSize;   // little endian
	char Format[4];  // big endian should contain "WAVE"
} RIFF_Chunk_t;



//the fmt sub-chunk
typedef struct {
	char Subchunk1_ID[4];   // big endian
	u32 Subchunk1_Size; // little endian
	u16 Audio_Format;   // little endian
	u16 Num_Channels;   // little endian
	u32 Sample_Rate;    // little endian
	u32 ByteRate;       // little endian
	u16 Block_Align;    // little endian
	u16 Bits_Per_Sample;// little endian
} fmt_Chunk_t;

// the data sub chunk
typedef struct {
	char Subchunk2_ID[4]; // big endian
	u32 Subchunk2_size; // little endian

} Data_Chunk_t;


typedef struct{
	char songName[20];
	char songSizeMb[12];
	char songLength[7];
	u32 songSamplingRate;
	u8  songNChannels;
	u32 songAverageBytePerSec;

}songList_t;

extern RIFF_Chunk_t RIFF_Info;
extern fmt_Chunk_t fmt_Chunk; //sampling rate ... etc.
extern Data_Chunk_t Data_Chunk;

extern const char Drive0Path[3] ;
extern const char Drive1Path[3];


//SD card functions
void Check_SD_Card_Mounted(FATFS);
void Read_SD_Card(char *filename, size_t AudioBufferSize, u8 *AudioBuffer);


#endif /* SRC_SD_CARD_H_ */
