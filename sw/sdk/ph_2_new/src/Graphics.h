/*
 * Graphics.h
 *
 *  Created on: 20 Jul 2020
 *      Author: oliver
 */

#ifndef SRC_GRAPHICS_H_
#define SRC_GRAPHICS_H_

// DMA Definitions
#define Horizontal_Size 480
#define Vertical_Size 800
#define FrameSize Horizontal_Size*Vertical_Size*3 // 3 because RGB each colour contains one byte of data

//Rectangular cursor size
#define songStartRECT_X 385
#define songStartRECT_Y 270
#define songEndRECT_X 425
#define songEndRECT_Y 735
#define songRECT_Spacing 47

//Start position of volume value text
#define volumeStartPos_X 300
#define volumeStartPos_Y 400

#define Textsize_Horizontal 20
#define Textsize_Vertical 20

#define BLACK           0
#define BLUE            1
#define GREEN           2
#define CYAN            3
#define RED             4
#define MAGENTA         5
#define BROWN           6
#define LIGHTGRAY       7
#define DARKGRAY        8
#define LIGHTBLUE       9
#define LIGHTGREEN      10
#define LIGHTCYAN       11
#define LIGHTRED        12
#define LIGHTMAGENTA    13
#define YELLOW          14
#define WHITE           15
#define GOLDENROD       16
#define GRASSGREEN      17
#define GRASSYELLOW     18
#define TEASTAINED      19
#define BRUSHEDCORDUROY 20
#define DARKGREY        21
#define LIGHTGREY       22

typedef struct colour_info
{
  unsigned r;
  unsigned g;
  unsigned b;
} COLOUR;


int drawStripeExample(unsigned char *Buffer_Image);

void drawBkGndEx(unsigned char *Buffer_Image, unsigned LineColour);

int drawRectangleFilled(int StartPosX, int StartPosY, int EndPosX,int EndPosY, unsigned char *Buffer_Image, int colour);

int drawRectangleLineFilled(int StartPosX, int StartPosY, int EndPosX, int EndPosY, int LineWidth, int LineColour, int FillColour,unsigned char *Buffer_Image);

int drawRectangleLine(int StartPosX, int StartPosY, int EndPosX, int EndPosY, int LineWidth, int LineColour, unsigned char *Buffer_Image);

int drawSquareFilled(int StartPosX,int StartPosY, int SideLength,int ShapeColour, unsigned char *Buffer_Image);

int drawSquareLineFilled(int StartPosX, int StartPosY, int SideLength, int LineWidth, unsigned LineColour, unsigned FillColour, unsigned char *Buffer_Image);

void drawSquareLine(int StartPosX, int StartPosY, int SideLength, int LineWidth, unsigned LineColour, unsigned char *Buffer_Image);

void drawline(int x0, int y0, int x1, int y1, int Width,  unsigned char *Buffer_Image, unsigned LineColour );

COLOUR setcolor(unsigned colour);

void BitMap(unsigned char *Buffer_Image, unsigned char *Test_Image_map );

void drawTriangleLine(int Point1PosX, int Point1PosY, int Point2PosX, int Point2PosY, int Point3PosX, int Point3PosY, int LineWidth, unsigned LineColour, unsigned char *Buffer_Image);

void Print_LCD_Txt(int StartPosX,int StartPosY, unsigned char *Buffer_Image,char string, unsigned LineColour);

void DrawLetterA(int StartPosX,int StartPosY, int SideLength, int LineColour, unsigned char *Buffer_Image);
void DrawLetterB(int StartPosX,int StartPosY, int SideLength,int LineColour, unsigned char *Buffer_Image);
void DrawLetterC(int StartPosX,int StartPosY, int SideLength,int LineColour, unsigned char *Buffer_Image);
void DrawLetterD(int StartPosX,int StartPosY, int SideLength,int LineColour, unsigned char *Buffer_Image);
void DrawLetterE(int StartPosX,int StartPosY, int SideLength,int LineColour, unsigned char *Buffer_Image);
void DrawLetterF(int StartPosX,int StartPosY, int SideLength,int LineColour, unsigned char *Buffer_Image);
void DrawLetterG(int StartPosX,int StartPosY, int SideLength,int LineColour, unsigned char *Buffer_Image);
void DrawLetterH(int StartPosX,int StartPosY, int SideLength,int LineColour, unsigned char *Buffer_Image);
void DrawLetterI(int StartPosX,int StartPosY, int SideLength,int LineColour, unsigned char *Buffer_Image);
void DrawLetterJ(int StartPosX,int StartPosY, int SideLength,int LineColour, unsigned char *Buffer_Image);
void DrawLetterK(int StartPosX,int StartPosY, int SideLength,int LineColour, unsigned char *Buffer_Image);
void DrawLetterL(int StartPosX,int StartPosY, int SideLength,int LineColour, unsigned char *Buffer_Image);
void DrawLetterM(int StartPosX,int StartPosY, int SideLength,int LineColour, unsigned char *Buffer_Image);
void DrawLetterN(int StartPosX,int StartPosY, int SideLength,int LineColour, unsigned char *Buffer_Image);
void DrawLetterO(int StartPosX,int StartPosY, int SideLength,int LineColour, unsigned char *Buffer_Image);
void DrawLetterP(int StartPosX,int StartPosY, int SideLength,int LineColour, unsigned char *Buffer_Image);
void DrawLetterQ(int StartPosX,int StartPosY, int SideLength,int LineColour, unsigned char *Buffer_Image);
void DrawLetterR(int StartPosX,int StartPosY, int SideLength,int LineColour, unsigned char *Buffer_Image);
void DrawLetterS(int StartPosX,int StartPosY, int SideLength,int LineColour, unsigned char *Buffer_Image);
void DrawLetterT(int StartPosX,int StartPosY, int SideLength,int LineColour, unsigned char *Buffer_Image);
void DrawLetterU(int StartPosX,int StartPosY, int SideLength,int LineColour, unsigned char *Buffer_Image);
void DrawLetterV(int StartPosX,int StartPosY, int SideLength,int LineColour, unsigned char *Buffer_Image);
void DrawLetterW(int StartPosX,int StartPosY, int SideLength,int LineColour, unsigned char *Buffer_Image);
void DrawLetterX(int StartPosX,int StartPosY, int SideLength,int LineColour, unsigned char *Buffer_Image);
void DrawLetterY(int StartPosX,int StartPosY, int SideLength,int LineColour, unsigned char *Buffer_Image);
void DrawLetterZ(int StartPosX,int StartPosY, int SideLength,int LineColour, unsigned char *Buffer_Image);


void DrawLetterA_New(int StartPosX,int StartPosY,int LineColour, unsigned char *Buffer_Image);
void DrawLetterB_New(int StartPosX,int StartPosY,int LineColour, unsigned char *Buffer_Image);
void DrawLetterC_New(int StartPosX,int StartPosY,int LineColour, unsigned char *Buffer_Image);
void DrawLetterD_New(int StartPosX,int StartPosY,int LineColour, unsigned char *Buffer_Image);
void DrawLetterE_New(int StartPosX,int StartPosY,int LineColour, unsigned char *Buffer_Image);
void DrawLetterF_New(int StartPosX,int StartPosY,int LineColour, unsigned char *Buffer_Image);
void DrawLetterG_New(int StartPosX,int StartPosY,int LineColour, unsigned char *Buffer_Image);
void DrawLetterH_New(int StartPosX,int StartPosY,int LineColour, unsigned char *Buffer_Image);
void DrawLetterI_New(int StartPosX,int StartPosY,int LineColour, unsigned char *Buffer_Image);
void DrawLetterJ_New(int StartPosX,int StartPosY,int LineColour, unsigned char *Buffer_Image);
void DrawLetterK_New(int StartPosX,int StartPosY,int LineColour, unsigned char *Buffer_Image);
void DrawLetterL_New(int StartPosX,int StartPosY,int LineColour, unsigned char *Buffer_Image);
void DrawLetterM_New(int StartPosX,int StartPosY,int LineColour, unsigned char *Buffer_Image);
void DrawLetterN_New(int StartPosX,int StartPosY,int LineColour, unsigned char *Buffer_Image);
void DrawLetterO_New(int StartPosX,int StartPosY,int LineColour, unsigned char *Buffer_Image);
void DrawLetterP_New(int StartPosX,int StartPosY,int LineColour, unsigned char *Buffer_Image);
void DrawLetterQ_New(int StartPosX,int StartPosY,int LineColour, unsigned char *Buffer_Image);
void DrawLetterR_New(int StartPosX,int StartPosY,int LineColour, unsigned char *Buffer_Image);
void DrawLetterS_New(int StartPosX,int StartPosY,int LineColour, unsigned char *Buffer_Image);
void DrawLetterT_New(int StartPosX,int StartPosY,int LineColour, unsigned char *Buffer_Image);
void DrawLetterU_New(int StartPosX,int StartPosY,int LineColour, unsigned char *Buffer_Image);
void DrawLetterV_New(int StartPosX,int StartPosY,int LineColour, unsigned char *Buffer_Image);
void DrawLetterW_New(int StartPosX,int StartPosY,int LineColour, unsigned char *Buffer_Image);
void DrawLetterX_New(int StartPosX,int StartPosY,int LineColour, unsigned char *Buffer_Image);
void DrawLetterY_New(int StartPosX,int StartPosY,int LineColour, unsigned char *Buffer_Image);
void DrawLetterZ_New(int StartPosX,int StartPosY,int LineColour, unsigned char *Buffer_Image);

void DrawLetterFullStop_New(int StartPosX,int StartPosY,int LineColour, unsigned char *Buffer_Image);
void DrawLetterColon_New(int StartPosX,int StartPosY,int LineColour, unsigned char *Buffer_Image);
void DrawLetterComma_New(int StartPosX,int StartPosY,int LineColour, unsigned char *Buffer_Image);
void DrawLetterUnderscore_New(int StartPosX,int StartPosY,int LineColour, unsigned char *Buffer_Image);
void DrawLetterTilda_New(int StartPosX,int StartPosY,int LineColour, unsigned char *Buffer_Image);
void DrawLetterFWSlash_New(int StartPosX,int StartPosY,int LineColour, unsigned char *Buffer_Image);


void DrawNumber0_New(int StartPosX,int StartPosY,int LineColour, unsigned char *Buffer_Image);
void DrawNumber1_New(int StartPosX,int StartPosY,int LineColour, unsigned char *Buffer_Image);
void DrawNumber2_New(int StartPosX,int StartPosY,int LineColour, unsigned char *Buffer_Image);
void DrawNumber3_New(int StartPosX,int StartPosY,int LineColour, unsigned char *Buffer_Image);
void DrawNumber4_New(int StartPosX,int StartPosY,int LineColour, unsigned char *Buffer_Image);
void DrawNumber5_New(int StartPosX,int StartPosY,int LineColour, unsigned char *Buffer_Image);
void DrawNumber6_New(int StartPosX,int StartPosY,int LineColour, unsigned char *Buffer_Image);
void DrawNumber7_New(int StartPosX,int StartPosY,int LineColour, unsigned char *Buffer_Image);
void DrawNumber8_New(int StartPosX,int StartPosY,int LineColour, unsigned char *Buffer_Image);
void DrawNumber9_New(int StartPosX,int StartPosY,int LineColour, unsigned char *Buffer_Image);


void DrawNumber0(int StartPosX,int StartPosY, int SideLength,int LineColour, unsigned char *Buffer_Image);
void DrawNumber1(int StartPosX,int StartPosY, int SideLength,int LineColour, unsigned char *Buffer_Image);
void DrawNumber2(int StartPosX,int StartPosY, int SideLength,int LineColour, unsigned char *Buffer_Image);
void DrawNumber3(int StartPosX,int StartPosY, int SideLength,int LineColour, unsigned char *Buffer_Image);
void DrawNumber4(int StartPosX,int StartPosY, int SideLength,int LineColour, unsigned char *Buffer_Image);
void DrawNumber5(int StartPosX,int StartPosY, int SideLength,int LineColour, unsigned char *Buffer_Image);
void DrawNumber6(int StartPosX,int StartPosY, int SideLength,int LineColour, unsigned char *Buffer_Image);
void DrawNumber7(int StartPosX,int StartPosY, int SideLength,int LineColour, unsigned char *Buffer_Image);
void DrawNumber8(int StartPosX,int StartPosY, int SideLength,int LineColour, unsigned char *Buffer_Image);
void DrawNumber9(int StartPosX,int StartPosY, int SideLength,int LineColour, unsigned char *Buffer_Image);


void DrawNumber1_New(int StartPosX,int StartPosY,int LineColour, unsigned char *Buffer_Image);
#endif /* SRC_GRAPHICS_H_ */
