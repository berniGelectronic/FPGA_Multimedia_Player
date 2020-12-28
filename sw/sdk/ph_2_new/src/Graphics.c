/*
 * Graphics.c
 *
 *  Created on: 20 Jul 2020
 *      Author: oliver
 */


#include "xbasic_types.h"
#include "Graphics.h"
#include "xil_cache.h"
#include <stdlib.h>
#include "xil_printf.h"

//unsigned char Buffer_Image[FrameSize];
// draw the image in the image buffer array for ram
//COLOUR    RGB;
/* It writes the RGB value to a global that can be used by
   graphics drawing wrapper functions */
COLOUR setcolor(unsigned colour)
{
	//COLOUR RGB;
    //RGB = make_RGB(x);
	   COLOUR result;
	    switch(colour)
	    {
	        case BLACK: result.r = 0; result.g = 0; result.b = 0;
	        break;
	        case BLUE: result.r = 0; result.g = 0; result.b = 255;
	        break;
	        case GREEN: result.r = 0; result.g = 255; result.b = 0;
	        break;
	        case CYAN: result.r = 0; result.g = 255; result.b = 255;
	        break;
	        case RED: result.r = 255; result.g = 0; result.b = 0;
	        break;
	        case MAGENTA: result.r = 255; result.g = 0; result.b = 255;
	        break;
	        case BROWN: result.r = 139; result.g = 69; result.b = 19;
	        break;
	        case LIGHTGRAY: result.r = 200; result.g = 200; result.b = 200;
	        break;
	        case DARKGRAY: result.r = 100; result.g = 100; result.b = 100;
	        break;
	        case LIGHTBLUE: result.r = 200; result.g = 200; result.b = 255;
	        break;
	        case LIGHTGREEN: result.r = 200; result.g = 255; result.b = 200;
	        break;
	        case LIGHTCYAN: result.r = 200; result.g = 255; result.b = 255;
	        break;
	        case LIGHTRED: result.r = 255; result.g = 200; result.b = 200;
	        break;
	        case LIGHTMAGENTA: result.r = 255; result.g = 200; result.b = 200;
	        break;
	        case YELLOW: result.r = 255; result.g = 255; result.b = 0;
	        break;
	        case WHITE: result.r = 255; result.g = 255; result.b = 255;
	        break;
	        case GOLDENROD: result.r = 250; result.g = 214; result.b = 165;
	        break;
	        case GRASSGREEN: result.r = 34; result.g = 69; result.b = 0;
	        break;
	        case GRASSYELLOW: result.r = 216; result.g = 207; result.b = 76;
	        break;
	        case TEASTAINED: result.r = 226; result.g = 220; result.b = 186;
	        break;
	        case BRUSHEDCORDUROY: result.r = 153; result.g = 76; result.b = 0;
	        break;
	        case DARKGREY: result.r = 67; result.g = 70; result.b = 75;
	        break;
	        case LIGHTGREY: result.r = 167; result.g = 166; result.b = 157;
	        break;
	    }
	    return result;
}


/**********************************************************************/
// draw the image in the image buffer in the ram
int drawStripeExample(unsigned char *Buffer_Image){

	for(int i=0;i<Vertical_Size;i++){
		for(int j=0;j<Horizontal_Size;j++){
			if(i<100){// black bar
				//blue
				Buffer_Image[(i*Horizontal_Size*3)+(j*3)]   = 0x00;
				//green
				Buffer_Image[(i*Horizontal_Size*3)+(j*3)+1] = 0x00;
				//red
				Buffer_Image[(i*Horizontal_Size*3)+(j*3)+2] = 0x00;
			}
			else if((i>=100)& (i<200)){// white bar
				//blue
				Buffer_Image[(i*Horizontal_Size*3)+(j*3)]   = 0xFF;
				//green
				Buffer_Image[(i*Horizontal_Size*3)+(j*3)+1] = 0xFF;
				//red
				Buffer_Image[(i*Horizontal_Size*3)+(j*3)+2] = 0xFF;
			}
			else if((i>=200)& (i<300)){// red bar
				//blue
				Buffer_Image[(i*Horizontal_Size*3)+(j*3)]   = 0x00;
				//green
				Buffer_Image[(i*Horizontal_Size*3)+(j*3)+1] = 0x00;
				//red
				Buffer_Image[(i*Horizontal_Size*3)+(j*3)+2] = 0xFF;
						}
			else if((i>=300)& (i<400)){// lime green bar
				//blue
				Buffer_Image[(i*Horizontal_Size*3)+(j*3)]   = 0x00;
				//green
				Buffer_Image[(i*Horizontal_Size*3)+(j*3)+1] = 0xFF;
				//red
				Buffer_Image[(i*Horizontal_Size*3)+(j*3)+2] = 0x00;
				}
			else if((i>=400)& (i<500)){// blue bar
				//blue
				Buffer_Image[(i*Horizontal_Size*3)+(j*3)]   = 0xFF;
				//green
				Buffer_Image[(i*Horizontal_Size*3)+(j*3)+1] = 0x00;
				//red
				Buffer_Image[(i*Horizontal_Size*3)+(j*3)+2] = 0x00;
				}
			else if((i>=500)& (i<600)){//yellow bar
				//blue
				Buffer_Image[(i*Horizontal_Size*3)+(j*3)]   = 0x00;
				//green
				Buffer_Image[(i*Horizontal_Size*3)+(j*3)+1] = 0xFF;
				//red
				Buffer_Image[(i*Horizontal_Size*3)+(j*3)+2] = 0xFF;
				}
			else if((i>=600)& (i<700)){//cyan bar
				//blue
				Buffer_Image[(i*Horizontal_Size*3)+(j*3)]   = 0xFF;
				//green
				Buffer_Image[(i*Horizontal_Size*3)+(j*3)+1] = 0xFF;
				//red
				Buffer_Image[(i*Horizontal_Size*3)+(j*3)+2] = 0x00;
				}
			else if((i>=700)& (i<800)){// magenta bar
				//blue
				Buffer_Image[(i*Horizontal_Size*3)+(j*3)]   = 0xFF;
				//green
				Buffer_Image[(i*Horizontal_Size*3)+(j*3)+1] = 0x00;
				//red
				Buffer_Image[(i*Horizontal_Size*3)+(j*3)+2] = 0xFF;
				}
			else {
				//blue
				Buffer_Image[(i*Horizontal_Size*3)+j*3]     = 0xFF;
				//green
				Buffer_Image[(i*Horizontal_Size*3)+(j*3)+1] = 0x00;
				//red
				Buffer_Image[(i*Horizontal_Size*3)+(j*3)+2] = 0x00;
			}
		}
	}
	Xil_DCacheFlush();
	return 0;
}

/**********************************************************************/
void drawBkGndEx(unsigned char *Buffer_Image, unsigned LineColour){

	COLOUR RGB;
		//line colour
		RGB = setcolor(LineColour);
for(int h=0;h<3;h++){
	for(int i=0;i<Vertical_Size;i++){
			for(int j=0;j<Horizontal_Size*3;j++){

					//blue
					Buffer_Image[(i*Vertical_Size*3)+(j*3)]   = RGB.b;
					//green
					Buffer_Image[(i*Vertical_Size*3)+(j*3)+1] = RGB.g;
					//red
					Buffer_Image[(i*Vertical_Size*3)+(j*3)+2] = RGB.r;

			}
		}
		//Xil_DCacheFlush();
		//return 0;
      }
	}

/**********************************************************************/
int drawRectangleFilled(
		int StartPosX,
		int StartPosY,
		int EndPosX,
		int EndPosY,
unsigned char *Buffer_Image,
		int colour){
	COLOUR RGB;


	RGB=setcolor(colour);
	// vertical pixels
	for(int i=0;i<Vertical_Size;i++){
				//Horizontal Pixels
				for(int j=0;j<Horizontal_Size;j++){
				  if (( i >= StartPosY ) && ( i <= EndPosY )){


					if( (( j >= StartPosX ) && ( j <= EndPosX )) ){
						//blue
						Buffer_Image[(i*Horizontal_Size*3)+(j*3)]   = RGB.b;
						//green
						Buffer_Image[(i*Horizontal_Size*3)+(j*3)+1] = RGB.g;
						//red
						Buffer_Image[(i*Horizontal_Size*3)+(j*3)+2] = RGB.r;
					}
				  }
				}
			}
			Xil_DCacheFlush();
			return 0;
}

/*******************************************************************************/
int drawRectangleLineFilled(int StartPosX, int StartPosY, int EndPosX, int EndPosY, int LineWidth, int LineColour, int FillColour,unsigned char *Buffer_Image){
	COLOUR RGB;
	//line colour
	RGB = setcolor(LineColour);
	drawRectangleFilled(StartPosX, StartPosY, EndPosX, EndPosY, Buffer_Image, FillColour);
	//fill colour
	RGB = setcolor(FillColour);
	drawRectangleFilled((StartPosX+LineWidth), (StartPosY+LineWidth), (EndPosX-LineWidth), (EndPosY-LineWidth), Buffer_Image, FillColour);
	return 0;
}

/*******************************************************************************/
int drawSquareFilled(int StartPosX,int StartPosY, int SideLength,int ShapeColour, unsigned char *Buffer_Image){

	COLOUR RGB;

	RGB = setcolor(ShapeColour);
	// vertical pixels
		for(int i=StartPosY;i<(Vertical_Size+SideLength);i++){
					//Horizontal Pixels
					for(int j=StartPosX;j<(StartPosX+SideLength) ;j++){
					  if (( i >= StartPosY ) && ( i <= (StartPosY+SideLength) )){
						if( (( j >= StartPosX ) && ( j <= (StartPosX+SideLength) )) ){
							//blue
							Buffer_Image[(i*Horizontal_Size*3)+(j*3)]   = RGB.b;
							//green
							Buffer_Image[(i*Horizontal_Size*3)+(j*3)+1] = RGB.g;
							//red
							Buffer_Image[(i*Horizontal_Size*3)+(j*3)+2] = RGB.r;

						}
					  }
					}
				}
				Xil_DCacheFlush();
				return 0;
}

/*******************************************************************************/
void BitMap(unsigned char *Buffer_Image, unsigned char *Test_Image_map){

  for(int h=0;h<=1;h++){
	for(int i=0;i<Vertical_Size;i++){
			for(int j=0;j<(Horizontal_Size*3);j++){

					//blue
					Buffer_Image[(i*Vertical_Size*3)+(j*3)]   = Test_Image_map[(i*Vertical_Size*4)+(j*4)];
					//green
					Buffer_Image[(i*Vertical_Size*3)+(j*3)+1] = Test_Image_map[(i*Vertical_Size*4)+(j*4)+1];
					//red
					Buffer_Image[(i*Vertical_Size*3)+(j*3)+2] = Test_Image_map[(i*Vertical_Size*4)+(j*4)+2];

			}
		}
	}
  //return Buffer_Image[];
}

/*******************************************************************************/
int drawRectangleLine(int StartPosX, int StartPosY, int EndPosX, int EndPosY, int LineWidth, int LineColour, unsigned char *Buffer_Image){

	// difference in x
	int dx=abs(EndPosX-StartPosX);
	// difference in y
	int dy=abs(EndPosY-StartPosY);

	setcolor(LineColour);
	drawline(StartPosX, StartPosY, StartPosX+dx, StartPosY, LineWidth,Buffer_Image, LineColour);
	drawline(StartPosX, StartPosY, StartPosX, StartPosY+dy, LineWidth, Buffer_Image, LineColour);
	drawline(StartPosX+dx, StartPosY, StartPosX+dx, StartPosY+dy, LineWidth, Buffer_Image, LineColour);
	drawline(StartPosX, StartPosY+dy, StartPosX+dx, StartPosY+dy, LineWidth, Buffer_Image, LineColour);
	return 0;
}

/*******************************************************************************/
int drawSquareLineFilled(int StartPosX, int StartPosY, int SideLength, int LineWidth, unsigned LineColour, unsigned FillColour, unsigned char *Buffer_Image) {
	// draw lined square
	drawSquareFilled(StartPosX, StartPosY, SideLength, LineColour, Buffer_Image);


	// draw middle square
	drawSquareFilled((StartPosX+LineWidth), (StartPosY+LineWidth), (SideLength - (2*LineWidth)), FillColour, Buffer_Image);
	Xil_DCacheFlush();
	return 0;
}
/********************************************************************************/

void drawSquareLine(int StartPosX, int StartPosY, int SideLength, int LineWidth, unsigned LineColour, unsigned char *Buffer_Image){
	setcolor(LineColour);
	drawline(StartPosX, StartPosY, (StartPosX + SideLength), StartPosY, LineWidth,Buffer_Image, LineColour);
	drawline(StartPosX, (StartPosY+ SideLength), (StartPosX + SideLength), (StartPosY + SideLength), LineWidth,Buffer_Image, LineColour);
	drawline(StartPosX, StartPosY, StartPosX , (StartPosY + SideLength), LineWidth,Buffer_Image, LineColour);
	drawline((StartPosX + SideLength- LineWidth), StartPosY, (StartPosX + SideLength- LineWidth) , (StartPosY + SideLength), LineWidth,Buffer_Image, LineColour);
}

/********************************************************************************/

void drawTriangleLine(int Point1PosX, int Point1PosY,
					  int Point2PosX, int Point2PosY,
					  int Point3PosX, int Point3PosY,
					  int LineWidth,
					  unsigned LineColour,
					  unsigned char *Buffer_Image){


}

/********************************************************************************/
//Bresenham’s Line Drawing Algorithm in C and straight lines in the x and Y direction
void drawline(int x0, int y0, int x1, int y1,int Width, unsigned char *Buffer_Image, unsigned LineColour )
{
	COLOUR RGB;
	RGB = setcolor(LineColour);

    int dx, dy, p, x, y, endx, endy;

    // difference in x
	dx=abs(x1-x0);
	// difference in y
	dy=abs(y1-y0);

    if (dx == 0){
       drawRectangleFilled(x0,y0, x1+Width,y1, Buffer_Image, LineColour);
    }
    else if(dy == 0){
        drawRectangleFilled(x0,y0, x1,y1+Width, Buffer_Image, LineColour);
    }
    else if( (x0 != x1)&&(y0 != y1) ){


    	// p = (2 * difference in x) - difference in y
    	p=2*dy-dx;


    	//draws lines left to right, top to bottom
    	if((x0>x1)&&(y1>y0)){

    		//x = initial position of x
    		x=x0;
    		//y = initial position of y
    		y=y0;
    		//mark the end
    		endy = y1;
    		endx = x1;

    		while((x>=endx)){
    			//printf("\n\r draws lines left to right, top to bottom ");
    		    	if(p<0)
    		    	{
    		    		x--;
    		    		p=p+dy;
    		    	}
    		    	else
    		    	{
    		    		x--;
    		    		y++;
    		    		p=p+(dy-dx);
    		    	}
    		    //	printf("\n\r diagonal  x = %u , y = %u ",x,y);
    		    	drawSquareFilled(x,y, Width, LineColour, Buffer_Image);
    		}
    	}

    	//draws lines left to right, bottom to top
    	else if( (x1>x0)&&(y1>y0) ){
    		//x = initial position of x
    		x=x0;
    		//y = initial position of y
    		y=y0;
    		//mark the end
    		endx = x1;

    		while((x<=endx)){

    			if(p<0)
    			{
    				x++;
    				p=p+2*dy;
    			}
    			else
    			{
    				x++;
    				y++;
    				p=p+2*(dy-dx);
    			}
    			//printf("\n\r diagonal  x = %u , y = %u ",x,y);
    			drawSquareFilled(x,y, Width, LineColour, Buffer_Image);
    		}
    	}


    	/*********************************/

    	/*********************************/
    	//printf("\n\r straight x = %u , y = %u ",x,y);
    	//drawSquareFilled(x,y, Width, LineColour, Buffer_Image );



   }

   else{
    	xil_printf("\r\n something is wrong with the values you input probably trying to do backwards line \r\n");
   }
}


/***************************************************************/
void DrawLetterA(int StartPosX,int StartPosY, int SideLength,int LineColour, unsigned char *Buffer_Image){

	//COLOUR RGB;
	//RGB = setcolor(LineColour);

	drawline(StartPosX, StartPosY, StartPosX+30, StartPosY+10,2, Buffer_Image, LineColour );

	drawline(StartPosX+10, StartPosY+5, StartPosX+10, StartPosY+17,2, Buffer_Image, LineColour );

	drawline(StartPosX+30, StartPosY+10, StartPosX, StartPosY+20,2, Buffer_Image, LineColour );

}

void DrawLetterB(int StartPosX,int StartPosY, int SideLength,int LineColour, unsigned char *Buffer_Image){

	// left side top to bottom
	drawline(StartPosX, StartPosY, StartPosX+30, StartPosY,2, Buffer_Image, LineColour );
	// bottom horizontal
	drawline(StartPosX, StartPosY, StartPosX, StartPosY+12,2, Buffer_Image, LineColour );
	// middle horizontal
	drawline(StartPosX+15, StartPosY, StartPosX+15, StartPosY+10,2, Buffer_Image, LineColour );
	// top hotizontal
	drawline(StartPosX+30, StartPosY, StartPosX+30, StartPosY+12,2, Buffer_Image, LineColour );

	// top curve, top to middle
	drawline(StartPosX+30, StartPosY+11, StartPosX+28, StartPosY+20,2, Buffer_Image, LineColour );
	drawline(StartPosX+21, StartPosY+17, StartPosX+27, StartPosY+17,2, Buffer_Image, LineColour );
	drawline(StartPosX+15, StartPosY+10, StartPosX+19, StartPosY+20,2, Buffer_Image, LineColour );

	// bottom curve middle to bottom
	// straight line vertical of curve
	drawline(StartPosX+5, StartPosY+17, StartPosX+11, StartPosY+17,2, Buffer_Image, LineColour );
	// bottom of curve
	drawline(StartPosX, StartPosY+10, StartPosX+4, StartPosY+20,2, Buffer_Image, LineColour );
	// top of curve
	drawline(StartPosX+15, StartPosY+11, StartPosX+12, StartPosY+20,2, Buffer_Image, LineColour );
}

void DrawLetterC(int StartPosX,int StartPosY, int SideLength,int LineColour, unsigned char *Buffer_Image){
	// left bottom to top
	drawline(StartPosX+10, StartPosY, StartPosX+20, StartPosY,2, Buffer_Image, LineColour );
	// bottom left to right
	drawline(StartPosX, StartPosY+10, StartPosX, StartPosY+20,2, Buffer_Image, LineColour );
	// top line left to right
	drawline(StartPosX+30, StartPosY+10, StartPosX+30, StartPosY+20,2, Buffer_Image, LineColour );
	// top left curve
	drawline(StartPosX+20, StartPosY, StartPosX+30, StartPosY+8,2, Buffer_Image, LineColour );
	// bottom left curve
	drawline(StartPosX+10, StartPosY, StartPosX+1, StartPosY+7,2, Buffer_Image, LineColour );

}

void DrawLetterD(int StartPosX,int StartPosY, int SideLength,int LineColour, unsigned char *Buffer_Image){
	 // left bottom to top
	 drawline(StartPosX, StartPosY, StartPosX+30, StartPosY,2, Buffer_Image, LineColour );
	 // bottom left to right
	 drawline(StartPosX, StartPosY, StartPosX, StartPosY+13,2, Buffer_Image, LineColour );
	 // top line left to right
	 drawline(StartPosX+30, StartPosY, StartPosX+30, StartPosY+13,2, Buffer_Image, LineColour );
	 // higher curve top to right
	drawline(StartPosX+29, StartPosY+13, StartPosX+29, StartPosY+14,2, Buffer_Image, LineColour );
	drawline(StartPosX+28, StartPosY+14, StartPosX+28, StartPosY+15,2, Buffer_Image, LineColour );
	drawline(StartPosX+27, StartPosY+15, StartPosX+27, StartPosY+16,2, Buffer_Image, LineColour );
	drawline(StartPosX+26, StartPosY+16, StartPosX+26, StartPosY+17,2, Buffer_Image, LineColour );
	drawline(StartPosX+25, StartPosY+17, StartPosX+25, StartPosY+18,2, Buffer_Image, LineColour );
	drawline(StartPosX+24, StartPosY+18, StartPosX+24, StartPosY+19,2, Buffer_Image, LineColour );
	drawline(StartPosX+23, StartPosY+19, StartPosX+23, StartPosY+19,2, Buffer_Image, LineColour );
	drawline(StartPosX+22, StartPosY+19, StartPosX+22, StartPosY+19,2, Buffer_Image, LineColour );
	// straight line right middle of curves
	drawline(StartPosX+9, StartPosY+18, StartPosX+24, StartPosY+18,2, Buffer_Image, LineColour );
	// lower curve right to bottom
	drawline(StartPosX+8, StartPosY+19, StartPosX+8, StartPosY+19,2, Buffer_Image, LineColour );
	drawline(StartPosX+7, StartPosY+17, StartPosX+7, StartPosY+18,2, Buffer_Image, LineColour );
	drawline(StartPosX+6, StartPosY+16, StartPosX+6, StartPosY+17,2, Buffer_Image, LineColour );
	drawline(StartPosX+5, StartPosY+15, StartPosX+5, StartPosY+16,2, Buffer_Image, LineColour );
	drawline(StartPosX+4, StartPosY+14, StartPosX+4, StartPosY+15,2, Buffer_Image, LineColour );
	drawline(StartPosX+3, StartPosY+13, StartPosX+3, StartPosY+14,2, Buffer_Image, LineColour );
	drawline(StartPosX+2, StartPosY+12, StartPosX+2, StartPosY+13,2, Buffer_Image, LineColour );
	drawline(StartPosX+1, StartPosY+11, StartPosX+1, StartPosY+12,2, Buffer_Image, LineColour );
	drawline(StartPosX, StartPosY+11, StartPosX, StartPosY+12,2, Buffer_Image, LineColour );
}
void DrawLetterE(int StartPosX,int StartPosY, int SideLength,int LineColour, unsigned char *Buffer_Image){

	drawline(StartPosX, StartPosY, StartPosX+30, StartPosY,2, Buffer_Image, LineColour );
	drawline(StartPosX, StartPosY, StartPosX, StartPosY+12,2, Buffer_Image, LineColour );
	drawline(StartPosX+15, StartPosY, StartPosX+15, StartPosY+10,2, Buffer_Image, LineColour );
	drawline(StartPosX+30, StartPosY, StartPosX+30, StartPosY+12,2, Buffer_Image, LineColour );
}

void DrawLetterF(int StartPosX,int StartPosY, int SideLength,int LineColour, unsigned char *Buffer_Image){

	// left side top to bottom
	drawline(StartPosX, StartPosY, StartPosX+30, StartPosY,2, Buffer_Image, LineColour );
	// bottom horizontal
	//drawline(StartPosX, StartPosY, StartPosX, StartPosY+12,2, Buffer_Image, LineColour );
	// middle horizontal
	drawline(StartPosX+15, StartPosY, StartPosX+15, StartPosY+10,2, Buffer_Image, LineColour );
	// top hotizontal
	drawline(StartPosX+30, StartPosY, StartPosX+30, StartPosY+12,2, Buffer_Image, LineColour );

}

void DrawLetterG(int StartPosX,int StartPosY, int SideLength,int LineColour, unsigned char *Buffer_Image){
	// left bottom to top
	drawline(StartPosX, StartPosY, StartPosX+30, StartPosY,2, Buffer_Image, LineColour );
	// bottom left to right
	drawline(StartPosX, StartPosY, StartPosX, StartPosY+15,2, Buffer_Image, LineColour );
	// top line left to right
	drawline(StartPosX+30, StartPosY, StartPosX+30, StartPosY+15,2, Buffer_Image, LineColour );
	// right bottom to top
	drawline(StartPosX, StartPosY+15, StartPosX+15, StartPosY+15,2, Buffer_Image, LineColour );
	// crossed T of G
	drawline(StartPosX+15, StartPosY+10, StartPosX+15, StartPosY+17,2, Buffer_Image, LineColour );
}
void DrawLetterH(int StartPosX,int StartPosY, int SideLength,int LineColour, unsigned char *Buffer_Image){
	// left side top to bottom
	drawline(StartPosX, StartPosY, StartPosX+30, StartPosY,2, Buffer_Image, LineColour );
	// middle horizontal
	drawline(StartPosX+15, StartPosY, StartPosX+15, StartPosY+15,2, Buffer_Image, LineColour );
	// right side top to bottom
	drawline(StartPosX, StartPosY+15, StartPosX+30, StartPosY+15,2, Buffer_Image, LineColour );
}

void DrawLetterI(int StartPosX,int StartPosY, int SideLength,int LineColour, unsigned char *Buffer_Image){

	drawline(StartPosX, StartPosY+9, StartPosX+30, StartPosY+9,2, Buffer_Image, LineColour );
	drawline(StartPosX, StartPosY, StartPosX, StartPosY+20,2, Buffer_Image, LineColour );
	drawline(StartPosX+30, StartPosY, StartPosX+30, StartPosY+20,2, Buffer_Image, LineColour );

}


void DrawLetterJ(int StartPosX,int StartPosY, int SideLength,int LineColour, unsigned char *Buffer_Image){
	// middle top to bottom
	drawline(StartPosX, StartPosY+9, StartPosX+30, StartPosY+9,2, Buffer_Image, LineColour );
	//top left to right
	drawline(StartPosX+30, StartPosY, StartPosX+30, StartPosY+20,2, Buffer_Image, LineColour );
	// bottom line left to right
	drawline(StartPosX, StartPosY, StartPosX, StartPosY+8,2, Buffer_Image, LineColour );
	// left vertical line
	drawline(StartPosX+2, StartPosY, StartPosX+8, StartPosY,2, Buffer_Image, LineColour );
}

void DrawLetterK(int StartPosX,int StartPosY, int SideLength,int LineColour, unsigned char *Buffer_Image){

	// left side top to bottom
	drawline(StartPosX, StartPosY, StartPosX+30, StartPosY,2, Buffer_Image, LineColour );
	// top diagonal towards top right
	drawline(StartPosX+15, StartPosY, StartPosX+30, StartPosY+17,2, Buffer_Image, LineColour );
	// bottom diagonal towards bottom right
	drawline(StartPosX+15, StartPosY, StartPosX, StartPosY+17,2, Buffer_Image, LineColour );
}
void DrawLetterL(int StartPosX,int StartPosY, int SideLength,int LineColour, unsigned char *Buffer_Image){
	// left side top to bottom
	drawline(StartPosX, StartPosY, StartPosX+30, StartPosY,2, Buffer_Image, LineColour );
	// bottom left to right
	drawline(StartPosX, StartPosY, StartPosX, StartPosY+20,2, Buffer_Image, LineColour );

}

void DrawLetterM(int StartPosX,int StartPosY, int SideLength,int LineColour, unsigned char *Buffer_Image){

	drawline(StartPosX, StartPosY, StartPosX+30, StartPosY+5,2, Buffer_Image, LineColour );

	drawline(StartPosX+20, StartPosY+10, StartPosX+30, StartPosY+15,1, Buffer_Image, LineColour );
	// leg 2 going down
	drawSquareFilled(StartPosX+29,StartPosY+6, 2, LineColour, Buffer_Image );
	drawSquareFilled(StartPosX+27,StartPosY+7, 2, LineColour, Buffer_Image );
	drawSquareFilled(StartPosX+25,StartPosY+8, 2, LineColour, Buffer_Image );
	drawSquareFilled(StartPosX+23,StartPosY+9, 2, LineColour, Buffer_Image );
	drawSquareFilled(StartPosX+21,StartPosY+10, 2, LineColour, Buffer_Image );


	drawSquareFilled(StartPosX+30,StartPosY+16, 2, LineColour, Buffer_Image );
	drawSquareFilled(StartPosX+28,StartPosY+16, 2, LineColour, Buffer_Image );
	drawSquareFilled(StartPosX+26,StartPosY+16, 2, LineColour, Buffer_Image );
	drawSquareFilled(StartPosX+24,StartPosY+16, 2, LineColour, Buffer_Image );
	drawSquareFilled(StartPosX+22,StartPosY+16, 2, LineColour, Buffer_Image );
	drawSquareFilled(StartPosX+20,StartPosY+17, 2, LineColour, Buffer_Image );
	drawSquareFilled(StartPosX+18,StartPosY+17, 2, LineColour, Buffer_Image );
	drawSquareFilled(StartPosX+16,StartPosY+18, 2, LineColour, Buffer_Image );
	drawSquareFilled(StartPosX+14,StartPosY+18, 2, LineColour, Buffer_Image );
	drawSquareFilled(StartPosX+12,StartPosY+18, 2, LineColour, Buffer_Image );
	drawSquareFilled(StartPosX+10,StartPosY+19, 2, LineColour, Buffer_Image );
	drawSquareFilled(StartPosX+8,StartPosY+19, 2, LineColour, Buffer_Image );
	drawSquareFilled(StartPosX+6,StartPosY+19, 2, LineColour, Buffer_Image );
	drawSquareFilled(StartPosX+4,StartPosY+20, 2, LineColour, Buffer_Image );
	drawSquareFilled(StartPosX+2,StartPosY+20, 2, LineColour, Buffer_Image );
	drawSquareFilled(StartPosX,StartPosY+20, 2, LineColour, Buffer_Image );
}

void DrawLetterN(int StartPosX,int StartPosY, int SideLength,int LineColour, unsigned char *Buffer_Image){

	drawline(StartPosX, StartPosY, StartPosX+30, StartPosY,2, Buffer_Image, LineColour );
	drawline(StartPosX, StartPosY+15, StartPosX+30, StartPosY+15,2, Buffer_Image, LineColour );

	drawSquareFilled(StartPosX+30,StartPosY, 2, LineColour, Buffer_Image );
	drawSquareFilled(StartPosX+28,StartPosY+1, 2, LineColour, Buffer_Image );
	drawSquareFilled(StartPosX+26,StartPosY+2, 2, LineColour, Buffer_Image );
	drawSquareFilled(StartPosX+24,StartPosY+3, 2, LineColour, Buffer_Image );
	drawSquareFilled(StartPosX+22,StartPosY+4, 2, LineColour, Buffer_Image );
	drawSquareFilled(StartPosX+20,StartPosY+5, 2, LineColour, Buffer_Image );
	drawSquareFilled(StartPosX+18,StartPosY+6, 2, LineColour, Buffer_Image );
	drawSquareFilled(StartPosX+16,StartPosY+7, 2, LineColour, Buffer_Image );
	drawSquareFilled(StartPosX+14,StartPosY+8, 2, LineColour, Buffer_Image );
	drawSquareFilled(StartPosX+12,StartPosY+9, 2, LineColour, Buffer_Image );
	drawSquareFilled(StartPosX+10,StartPosY+10, 2, LineColour, Buffer_Image );
	drawSquareFilled(StartPosX+8,StartPosY+11, 2, LineColour, Buffer_Image );
	drawSquareFilled(StartPosX+6,StartPosY+12, 2, LineColour, Buffer_Image );
	drawSquareFilled(StartPosX+4,StartPosY+13, 2, LineColour, Buffer_Image );
	drawSquareFilled(StartPosX+2,StartPosY+14, 2, LineColour, Buffer_Image );
	drawSquareFilled(StartPosX,StartPosY+15, 2, LineColour, Buffer_Image );
}

void DrawLetterO(int StartPosX,int StartPosY, int SideLength,int LineColour, unsigned char *Buffer_Image){

	//diagonal top left
	drawline(StartPosX+22, StartPosY, StartPosX+29, StartPosY+7,2, Buffer_Image, LineColour );
	// top horizontal line
	drawline(StartPosX+30, StartPosY+9, StartPosX+30, StartPosY+12,2, Buffer_Image, LineColour );
	// left vertical
	drawline(StartPosX+9, StartPosY, StartPosX+24, StartPosY,2, Buffer_Image, LineColour );
	// bottom horizontal
	drawline(StartPosX, StartPosY+9, StartPosX, StartPosY+12,2, Buffer_Image, LineColour );
	// bottom left curve
	drawline(StartPosX+8, StartPosY, StartPosX+8, StartPosY+1,2, Buffer_Image, LineColour );
	drawline(StartPosX+7, StartPosY+1, StartPosX+7, StartPosY+2,2, Buffer_Image, LineColour );
	drawline(StartPosX+6, StartPosY+2, StartPosX+6, StartPosY+3,2, Buffer_Image, LineColour );
	drawline(StartPosX+5, StartPosY+3, StartPosX+5, StartPosY+4,2, Buffer_Image, LineColour );
	drawline(StartPosX+4, StartPosY+4, StartPosX+4, StartPosY+5,2, Buffer_Image, LineColour );
	drawline(StartPosX+3, StartPosY+5, StartPosX+3, StartPosY+6,2, Buffer_Image, LineColour );
	drawline(StartPosX+2, StartPosY+6, StartPosX+2, StartPosY+7,2, Buffer_Image, LineColour );
	drawline(StartPosX+1, StartPosY+7, StartPosX+1, StartPosY+8,2, Buffer_Image, LineColour );
	drawline(StartPosX, StartPosY+8, StartPosX, StartPosY+9,2, Buffer_Image, LineColour );

	// higher curve top to right
	drawline(StartPosX+29, StartPosY+13, StartPosX+29, StartPosY+14,2, Buffer_Image, LineColour );
	drawline(StartPosX+28, StartPosY+14, StartPosX+28, StartPosY+15,2, Buffer_Image, LineColour );
	drawline(StartPosX+27, StartPosY+15, StartPosX+27, StartPosY+16,2, Buffer_Image, LineColour );
	drawline(StartPosX+26, StartPosY+16, StartPosX+26, StartPosY+17,2, Buffer_Image, LineColour );
	drawline(StartPosX+25, StartPosY+17, StartPosX+25, StartPosY+18,2, Buffer_Image, LineColour );
	drawline(StartPosX+24, StartPosY+18, StartPosX+24, StartPosY+19,2, Buffer_Image, LineColour );
	drawline(StartPosX+23, StartPosY+19, StartPosX+23, StartPosY+19,2, Buffer_Image, LineColour );
	drawline(StartPosX+22, StartPosY+19, StartPosX+22, StartPosY+19,2, Buffer_Image, LineColour );
	// straight line right middle of curves
	drawline(StartPosX+9, StartPosY+18, StartPosX+24, StartPosY+18,2, Buffer_Image, LineColour );
	// lower curve right to bottom
	drawline(StartPosX+8, StartPosY+19, StartPosX+8, StartPosY+19,2, Buffer_Image, LineColour );
	drawline(StartPosX+7, StartPosY+17, StartPosX+7, StartPosY+18,2, Buffer_Image, LineColour );
	drawline(StartPosX+6, StartPosY+16, StartPosX+6, StartPosY+17,2, Buffer_Image, LineColour );
	drawline(StartPosX+5, StartPosY+15, StartPosX+5, StartPosY+16,2, Buffer_Image, LineColour );
	drawline(StartPosX+4, StartPosY+14, StartPosX+4, StartPosY+15,2, Buffer_Image, LineColour );
	drawline(StartPosX+3, StartPosY+13, StartPosX+3, StartPosY+14,2, Buffer_Image, LineColour );
	drawline(StartPosX+2, StartPosY+12, StartPosX+2, StartPosY+13,2, Buffer_Image, LineColour );
	drawline(StartPosX+1, StartPosY+11, StartPosX+1, StartPosY+12,2, Buffer_Image, LineColour );
	drawline(StartPosX, StartPosY+11, StartPosX, StartPosY+12,2, Buffer_Image, LineColour );

}

void DrawLetterP(int StartPosX,int StartPosY, int SideLength,int LineColour, unsigned char *Buffer_Image){

	// left side top to bottom
	drawline(StartPosX, StartPosY, StartPosX+30, StartPosY,2, Buffer_Image, LineColour );
	// middle horizontal
	drawline(StartPosX+15, StartPosY, StartPosX+15, StartPosY+10,2, Buffer_Image, LineColour );
	// top hotizontal
	drawline(StartPosX+30, StartPosY, StartPosX+30, StartPosY+12,2, Buffer_Image, LineColour );

	// top curve, top to middle
	drawline(StartPosX+30, StartPosY+11, StartPosX+28, StartPosY+20,2, Buffer_Image, LineColour );
	drawline(StartPosX+21, StartPosY+17, StartPosX+27, StartPosY+17,2, Buffer_Image, LineColour );
	drawline(StartPosX+15, StartPosY+10, StartPosX+19, StartPosY+20,2, Buffer_Image, LineColour );

}

void DrawLetterQ(int StartPosX,int StartPosY, int SideLength,int LineColour, unsigned char *Buffer_Image){

	//diagonal top left
		drawline(StartPosX+22, StartPosY, StartPosX+29, StartPosY+7,2, Buffer_Image, LineColour );
		// top horizontal line
		drawline(StartPosX+30, StartPosY+9, StartPosX+30, StartPosY+12,2, Buffer_Image, LineColour );
		// left vertical
		drawline(StartPosX+9, StartPosY, StartPosX+24, StartPosY,2, Buffer_Image, LineColour );
		// bottom horizontal
		drawline(StartPosX, StartPosY+9, StartPosX, StartPosY+12,2, Buffer_Image, LineColour );
		// bottom left curve
		drawline(StartPosX+8, StartPosY, StartPosX+8, StartPosY+1,2, Buffer_Image, LineColour );
		drawline(StartPosX+7, StartPosY+1, StartPosX+7, StartPosY+2,2, Buffer_Image, LineColour );
		drawline(StartPosX+6, StartPosY+2, StartPosX+6, StartPosY+3,2, Buffer_Image, LineColour );
		drawline(StartPosX+5, StartPosY+3, StartPosX+5, StartPosY+4,2, Buffer_Image, LineColour );
		drawline(StartPosX+4, StartPosY+4, StartPosX+4, StartPosY+5,2, Buffer_Image, LineColour );
		drawline(StartPosX+3, StartPosY+5, StartPosX+3, StartPosY+6,2, Buffer_Image, LineColour );
		drawline(StartPosX+2, StartPosY+6, StartPosX+2, StartPosY+7,2, Buffer_Image, LineColour );
		drawline(StartPosX+1, StartPosY+7, StartPosX+1, StartPosY+8,2, Buffer_Image, LineColour );
		drawline(StartPosX, StartPosY+8, StartPosX, StartPosY+9,2, Buffer_Image, LineColour );

		// higher curve top to right
		drawline(StartPosX+29, StartPosY+13, StartPosX+29, StartPosY+14,2, Buffer_Image, LineColour );
		drawline(StartPosX+28, StartPosY+14, StartPosX+28, StartPosY+15,2, Buffer_Image, LineColour );
		drawline(StartPosX+27, StartPosY+15, StartPosX+27, StartPosY+16,2, Buffer_Image, LineColour );
		drawline(StartPosX+26, StartPosY+16, StartPosX+26, StartPosY+17,2, Buffer_Image, LineColour );
		drawline(StartPosX+25, StartPosY+17, StartPosX+25, StartPosY+18,2, Buffer_Image, LineColour );
		drawline(StartPosX+24, StartPosY+18, StartPosX+24, StartPosY+19,2, Buffer_Image, LineColour );
		drawline(StartPosX+23, StartPosY+19, StartPosX+23, StartPosY+19,2, Buffer_Image, LineColour );
		drawline(StartPosX+22, StartPosY+19, StartPosX+22, StartPosY+19,2, Buffer_Image, LineColour );
		// straight line right middle of curves
		drawline(StartPosX+9, StartPosY+18, StartPosX+24, StartPosY+18,2, Buffer_Image, LineColour );
		// lower curve right to bottom
		drawline(StartPosX+8, StartPosY+19, StartPosX+8, StartPosY+19,2, Buffer_Image, LineColour );
		drawline(StartPosX+7, StartPosY+17, StartPosX+7, StartPosY+18,2, Buffer_Image, LineColour );
		drawline(StartPosX+6, StartPosY+16, StartPosX+6, StartPosY+17,2, Buffer_Image, LineColour );
		drawline(StartPosX+5, StartPosY+15, StartPosX+5, StartPosY+16,2, Buffer_Image, LineColour );
		drawline(StartPosX+4, StartPosY+14, StartPosX+4, StartPosY+15,2, Buffer_Image, LineColour );
		drawline(StartPosX+3, StartPosY+13, StartPosX+3, StartPosY+14,2, Buffer_Image, LineColour );
		drawline(StartPosX+2, StartPosY+12, StartPosX+2, StartPosY+13,2, Buffer_Image, LineColour );
		drawline(StartPosX+1, StartPosY+11, StartPosX+1, StartPosY+12,2, Buffer_Image, LineColour );
		drawline(StartPosX, StartPosY+11, StartPosX, StartPosY+12,2, Buffer_Image, LineColour );

		// bottom diagonal towards bottom right
		drawline(StartPosX+11, StartPosY+11, StartPosX+11, StartPosY+12,2, Buffer_Image, LineColour );
		drawline(StartPosX+10, StartPosY+11, StartPosX+10, StartPosY+12,2, Buffer_Image, LineColour );
		drawline(StartPosX+9,  StartPosY+12, StartPosX+9, StartPosY+13,2, Buffer_Image, LineColour );
		drawline(StartPosX+8,  StartPosY+12, StartPosX+8, StartPosY+13,2, Buffer_Image, LineColour );
		drawline(StartPosX+7,  StartPosY+13, StartPosX+7, StartPosY+14,2, Buffer_Image, LineColour );
		drawline(StartPosX+6,  StartPosY+14, StartPosX+6, StartPosY+15,2, Buffer_Image, LineColour );
		drawline(StartPosX+5,  StartPosY+15, StartPosX+5, StartPosY+16,2, Buffer_Image, LineColour );
		drawline(StartPosX+4,  StartPosY+16, StartPosX+4, StartPosY+17,2, Buffer_Image, LineColour );
		drawline(StartPosX+3,  StartPosY+17, StartPosX+3, StartPosY+18,2, Buffer_Image, LineColour );
		drawline(StartPosX+2,  StartPosY+18,StartPosX+2, StartPosY+19,2, Buffer_Image, LineColour );
		drawline(StartPosX+1,  StartPosY+18,StartPosX+1, StartPosY+19,2, Buffer_Image, LineColour );
		drawline(StartPosX,    StartPosY+19,StartPosX, StartPosY+20,2, Buffer_Image, LineColour );
}
void DrawLetterR(int StartPosX,int StartPosY, int SideLength,int LineColour, unsigned char *Buffer_Image){

	// left side top to bottom
	drawline(StartPosX, StartPosY, StartPosX+30, StartPosY,2, Buffer_Image, LineColour );
	// middle horizontal
	drawline(StartPosX+15, StartPosY, StartPosX+15, StartPosY+10,2, Buffer_Image, LineColour );
	// top horizontal
	drawline(StartPosX+30, StartPosY, StartPosX+30, StartPosY+12,2, Buffer_Image, LineColour );
	// leg of R
	drawline(StartPosX+15, StartPosY, StartPosX, StartPosY+20,2, Buffer_Image, LineColour );

	// top curve, top to middle
	drawline(StartPosX+30, StartPosY+11, StartPosX+28, StartPosY+20,2, Buffer_Image, LineColour );
	drawline(StartPosX+21, StartPosY+17, StartPosX+27, StartPosY+17,2, Buffer_Image, LineColour );
	drawline(StartPosX+15, StartPosY+10, StartPosX+19, StartPosY+20,2, Buffer_Image, LineColour );


}

void DrawLetterS(int StartPosX,int StartPosY, int SideLength,int LineColour, unsigned char *Buffer_Image){
	// top horizontal
	drawline(StartPosX+30, StartPosY+7, StartPosX+30, StartPosY+20,2, Buffer_Image, LineColour );
	// middle horizontal
	drawline(StartPosX+15, StartPosY+8, StartPosX+15, StartPosY+15,2, Buffer_Image, LineColour );
	// bottom horizontal
	drawline(StartPosX, StartPosY+1, StartPosX, StartPosY+15,2, Buffer_Image, LineColour );

	// top curve
	// top half
	drawline(StartPosX+22, StartPosY, StartPosX+30, StartPosY+5,2, Buffer_Image, LineColour );
	// bottom half
	drawline(StartPosX+22, StartPosY, StartPosX+15, StartPosY+5,2, Buffer_Image, LineColour );

	// bottom curve
	// top half
	drawline(StartPosX+15, StartPosY+14, StartPosX+7, StartPosY+19,2, Buffer_Image, LineColour );
	// bottom half
	drawline(StartPosX, StartPosY+15, StartPosX+7, StartPosY+19,2, Buffer_Image, LineColour );

}
void DrawLetterT(int StartPosX,int StartPosY, int SideLength,int LineColour, unsigned char *Buffer_Image){
	// middle top to bottom
	drawline(StartPosX, StartPosY+9, StartPosX+30, StartPosY+9,2, Buffer_Image, LineColour );
	//top left to right
	drawline(StartPosX+30, StartPosY, StartPosX+30, StartPosY+20,2, Buffer_Image, LineColour );
}

void DrawLetterU(int StartPosX,int StartPosY, int SideLength,int LineColour, unsigned char *Buffer_Image){
	// left vertical
	drawline(StartPosX+9, StartPosY, StartPosX+30, StartPosY,2, Buffer_Image, LineColour );
	// bottom left curve
	drawline(StartPosX+9, StartPosY, StartPosX, StartPosY+10,2, Buffer_Image, LineColour );
	// straight line right  top to bottom
	drawline(StartPosX+9, StartPosY+20, StartPosX+30, StartPosY+20,2, Buffer_Image, LineColour );
	// lower curve right to bottom
	drawline(StartPosX, StartPosY+10, StartPosX+9, StartPosY+20,2, Buffer_Image, LineColour );
}

void DrawLetterV(int StartPosX,int StartPosY, int SideLength,int LineColour, unsigned char *Buffer_Image){

	// right diagonal bottom to top
	drawline(StartPosX, StartPosY+10, StartPosX+30, StartPosY+20,2, Buffer_Image, LineColour );
	// left diagonal top to bottom
	drawline(StartPosX+30, StartPosY, StartPosX, StartPosY+10,2, Buffer_Image, LineColour );

}

void DrawLetterW(int StartPosX,int StartPosY, int SideLength,int LineColour, unsigned char *Buffer_Image){
	//1st line top to bottom, left to right
	drawline(StartPosX+30, StartPosY, StartPosX, StartPosY+5,2, Buffer_Image, LineColour );
	// 2nd line from left to right, bottom to middle/top
	drawline(StartPosX, StartPosY+5, StartPosX+15, StartPosY+9,2, Buffer_Image, LineColour );
	//3rd line bottom to top middle, left to right
	drawline(StartPosX+15, StartPosY+10, StartPosX, StartPosY+15,2, Buffer_Image, LineColour );
	// 4th line from left to right, bottom to middle/top
	drawline(StartPosX, StartPosY+15, StartPosX+30, StartPosY+20,2, Buffer_Image, LineColour );
}

void DrawLetterX(int StartPosX,int StartPosY, int SideLength,int LineColour, unsigned char *Buffer_Image){

	// left to right bottom to top
	drawline(StartPosX, StartPosY, StartPosX+30, StartPosY+20,2, Buffer_Image, LineColour );
	// left to right top to bottom
	drawline(StartPosX+30, StartPosY, StartPosX, StartPosY+20,2, Buffer_Image, LineColour );

}


void DrawLetterY(int StartPosX,int StartPosY, int SideLength,int LineColour, unsigned char *Buffer_Image){
	// middle top to bottom
	drawline(StartPosX, StartPosY, StartPosX+30, StartPosY+20,2, Buffer_Image, LineColour );
	// left to right top to middle connection
		drawline(StartPosX+30, StartPosY, StartPosX+15, StartPosY+8,2, Buffer_Image, LineColour );
}

void DrawLetterZ(int StartPosX,int StartPosY, int SideLength,int LineColour, unsigned char *Buffer_Image){
	// middle top to bottom
	drawline(StartPosX, StartPosY, StartPosX+30, StartPosY+20,2, Buffer_Image, LineColour );
	//top left to right horizontal
	drawline(StartPosX+30, StartPosY, StartPosX+30, StartPosY+20,2, Buffer_Image, LineColour );
	//bottom left to right horizontal
	drawline(StartPosX, StartPosY, StartPosX, StartPosY+20,2, Buffer_Image, LineColour );
}

void DrawNumber0(int StartPosX,int StartPosY, int SideLength,int LineColour, unsigned char *Buffer_Image){

	// left bottom to top
	drawline(StartPosX+9, StartPosY, StartPosX+24, StartPosY,2, Buffer_Image, LineColour );
	// bottom left to right
	drawline(StartPosX, StartPosY+8, StartPosX, StartPosY+13,2, Buffer_Image, LineColour );
	// top line left to right
	drawline(StartPosX+30, StartPosY+8, StartPosX+30, StartPosY+13,2, Buffer_Image, LineColour );
	// higher curve top to right
	drawline(StartPosX+30, StartPosY+12, StartPosX+22, StartPosY+19,2, Buffer_Image, LineColour );

	// straight line right middle of curves
	drawline(StartPosX+9, StartPosY+20, StartPosX+24, StartPosY+20,2, Buffer_Image, LineColour );
	// lower curve right to bottom
	drawline(StartPosX, StartPosY+12, StartPosX+8, StartPosY+19,2, Buffer_Image, LineColour );

	// left lower curve
	drawline(StartPosX+8, StartPosY+1, StartPosX+1, StartPosY+7,2, Buffer_Image, LineColour );
	// left higher curve
	drawline(StartPosX+24, StartPosY, StartPosX+29, StartPosY+7,2, Buffer_Image, LineColour );

	// middle diagonal left to right bottom to top
	drawline(StartPosX+7, StartPosY+6, StartPosX+23, StartPosY+13,2, Buffer_Image, LineColour );//
}

void DrawNumber1(int StartPosX,int StartPosY, int SideLength,int LineColour, unsigned char *Buffer_Image){
	// bottom line horizontal left to right
	drawline(StartPosX, StartPosY, StartPosX, StartPosY+20,2, Buffer_Image, LineColour );
	// middle line top to bottom vertical
	drawline(StartPosX, StartPosY+9, StartPosX+30, StartPosY+9,2, Buffer_Image, LineColour );
	// diagonal lfet to right
	drawline(StartPosX+20, StartPosY, StartPosX+30, StartPosY+9,2, Buffer_Image, LineColour );
}

void DrawNumber2(int StartPosX,int StartPosY, int SideLength,int LineColour, unsigned char *Buffer_Image){

	// bottom line horizontal left to right
	drawline(StartPosX, StartPosY, StartPosX, StartPosY+20,2, Buffer_Image, LineColour );
	// bottom line horizontal left to right
	drawline(StartPosX, StartPosY, StartPosX+15, StartPosY+20,2, Buffer_Image, LineColour );

	// right vertical
	drawline(StartPosX+16, StartPosY+18, StartPosX+24, StartPosY+18,2, Buffer_Image, LineColour );

	// top Horizontal
	drawline(StartPosX+29, StartPosY+5, StartPosX+29, StartPosY+13,2, Buffer_Image, LineColour );
	// top right curve
	drawline(StartPosX+29, StartPosY+12, StartPosX+25, StartPosY+18,2, Buffer_Image, LineColour );
	// top left curve
	drawline(StartPosX+20, StartPosY, StartPosX+29, StartPosY+4,2, Buffer_Image, LineColour );
}

void DrawNumber3(int StartPosX,int StartPosY, int SideLength,int LineColour, unsigned char *Buffer_Image){

	//Bottom horizontal
	drawline(StartPosX, StartPosY, StartPosX, StartPosY+12,2, Buffer_Image, LineColour );
	//Middle Horizontal
	drawline(StartPosX+15, StartPosY, StartPosX+15, StartPosY+12,2, Buffer_Image, LineColour );
	// Top Horizontal
	drawline(StartPosX+30, StartPosY, StartPosX+30, StartPosY+12,2, Buffer_Image, LineColour );

	//Top curve
	// top left to right
	drawline(StartPosX+30, StartPosY+11, StartPosX+22, StartPosY+17,2, Buffer_Image, LineColour );
	// bottom left to right
	drawline(StartPosX+15, StartPosY+12, StartPosX+22, StartPosY+17,2, Buffer_Image, LineColour );


	//Bottom curve
	// top left to right
	drawline(StartPosX, StartPosY+11, StartPosX+8, StartPosY+17,2, Buffer_Image, LineColour );
	// bottom left to right
	drawline(StartPosX+15, StartPosY+12, StartPosX+8, StartPosY+17,2, Buffer_Image, LineColour );
}

void DrawNumber4(int StartPosX,int StartPosY, int SideLength,int LineColour, unsigned char *Buffer_Image){
	// horizontal middle
	drawline(StartPosX+10, StartPosY, StartPosX+10, StartPosY+19,2, Buffer_Image, LineColour );
	// middle vertical
	drawline(StartPosX, StartPosY+13, StartPosX+30, StartPosY+13,2, Buffer_Image, LineColour );

	// Diagonal left to right
	drawline(StartPosX+11, StartPosY+1, StartPosX+29, StartPosY+12,2, Buffer_Image, LineColour );
}

void DrawNumber5(int StartPosX,int StartPosY, int SideLength,int LineColour, unsigned char *Buffer_Image){
	// left vertical
	drawline(StartPosX+15, StartPosY, StartPosX+30, StartPosY,2, Buffer_Image, LineColour );
	// middle horizontal
	drawline(StartPosX+15, StartPosY, StartPosX+15, StartPosY+17,2, Buffer_Image, LineColour );
	// top horizontal
	drawline(StartPosX+30, StartPosY, StartPosX+30, StartPosY+19,2, Buffer_Image, LineColour );


	// middle right curve
	drawline(StartPosX+15, StartPosY+16, StartPosX+10, StartPosY+20,2, Buffer_Image, LineColour );
	// left lower curve
	drawline(StartPosX+5, StartPosY, StartPosX+1, StartPosY+5,2, Buffer_Image, LineColour );
	// straight line right middle of curves
	drawline(StartPosX, StartPosY+6, StartPosX, StartPosY+15,2, Buffer_Image, LineColour );
	// lower curve right to bottom
	drawline(StartPosX, StartPosY+15, StartPosX+5, StartPosY+20,2, Buffer_Image, LineColour );


}

void DrawNumber6(int StartPosX,int StartPosY, int SideLength,int LineColour, unsigned char *Buffer_Image){

	// left vertical
	drawline(StartPosX+5, StartPosY, StartPosX+25, StartPosY,2, Buffer_Image, LineColour );
	// middle horizontal
	drawline(StartPosX+15, StartPosY, StartPosX+15, StartPosY+17,2, Buffer_Image, LineColour );
	// top horizontal
	drawline(StartPosX+30, StartPosY+4, StartPosX+30, StartPosY+14,2, Buffer_Image, LineColour );
	// middle right curve
	drawline(StartPosX+15, StartPosY+16, StartPosX+10, StartPosY+20,2, Buffer_Image, LineColour );
	// left lower curve
	drawline(StartPosX+5, StartPosY, StartPosX+1, StartPosY+5,2, Buffer_Image, LineColour );
	// straight line right middle of curves
	drawline(StartPosX, StartPosY+6, StartPosX, StartPosY+15,2, Buffer_Image, LineColour );
	// lower curve right to bottom
	drawline(StartPosX, StartPosY+15, StartPosX+5, StartPosY+20,2, Buffer_Image, LineColour );
	// top right curve
	drawline(StartPosX+30, StartPosY+13, StartPosX+25, StartPosY+20,2, Buffer_Image, LineColour );
	// top left curve
	drawline(StartPosX+25, StartPosY, StartPosX+30, StartPosY+5,2, Buffer_Image, LineColour );
}

void DrawNumber7(int StartPosX,int StartPosY, int SideLength,int LineColour, unsigned char *Buffer_Image){
	// middle top to bottom
	drawline(StartPosX, StartPosY, StartPosX+30, StartPosY+20,2, Buffer_Image, LineColour );
	//top left to right horizontal
	drawline(StartPosX+30, StartPosY, StartPosX+30, StartPosY+20,2, Buffer_Image, LineColour );
}

void DrawNumber8(int StartPosX,int StartPosY, int SideLength,int LineColour, unsigned char *Buffer_Image){

	// left vertical
	//drawline(StartPosX+5, StartPosY, StartPosX+25, StartPosY,2, Buffer_Image, LineColour );
	// middle horizontal
	//drawline(StartPosX+15, StartPosY, StartPosX+15, StartPosY+17,2, Buffer_Image, LineColour );
	// top horizontal
	drawline(StartPosX+30, StartPosY+4, StartPosX+30, StartPosY+14,2, Buffer_Image, LineColour );

	// middle left to right diagonal top to bottom
	drawline(StartPosX+25, StartPosY, StartPosX+10, StartPosY+26,2, Buffer_Image, LineColour );
	// middle left to tight diagonal bottom to top
	drawline(StartPosX+7, StartPosY, StartPosX+23, StartPosY+22,2, Buffer_Image, LineColour );

	// left lower curve
	drawline(StartPosX+7, StartPosY, StartPosX+1, StartPosY+5,2, Buffer_Image, LineColour );
	// straight line right middle of curves
	drawline(StartPosX, StartPosY+6, StartPosX, StartPosY+15,2, Buffer_Image, LineColour );
	// lower curve right
	drawline(StartPosX, StartPosY+15, StartPosX+7, StartPosY+18,2, Buffer_Image, LineColour );

	// top right curve
	drawline(StartPosX+30, StartPosY+13, StartPosX+26, StartPosY+18,2, Buffer_Image, LineColour );
	// top left curve
	drawline(StartPosX+25, StartPosY, StartPosX+30, StartPosY+5,2, Buffer_Image, LineColour );

}

void DrawNumber9(int StartPosX,int StartPosY, int SideLength,int LineColour, unsigned char *Buffer_Image){

	// Diagonal line left to right
	drawline(StartPosX, StartPosY+20, StartPosX+15, StartPosY+20,2, Buffer_Image, LineColour );
	// right vertical
	drawline(StartPosX+16, StartPosY+18, StartPosX+27, StartPosY+18,2, Buffer_Image, LineColour );
	// left vertical
	drawline(StartPosX+16, StartPosY, StartPosX+24, StartPosY,2, Buffer_Image, LineColour );
	// top Horizontal
	drawline(StartPosX+29, StartPosY+5, StartPosX+29, StartPosY+13,2, Buffer_Image, LineColour );
	// top right curve
	drawline(StartPosX+29, StartPosY+12, StartPosX+25, StartPosY+18,2, Buffer_Image, LineColour );
	// top left curve
	drawline(StartPosX+20, StartPosY, StartPosX+29, StartPosY+4,2, Buffer_Image, LineColour );
	// bottom left curve
	drawline(StartPosX+15, StartPosY, StartPosX+12, StartPosY+5,2, Buffer_Image, LineColour );
	// middle horizontal
	drawline(StartPosX+12, StartPosY+6, StartPosX+12, StartPosY+15,2, Buffer_Image, LineColour );

	// middle right curve
	drawline(StartPosX+12, StartPosY+15, StartPosX+15, StartPosY+20,2, Buffer_Image, LineColour );
}

void Print_LCD_Txt(int StartPosX,int StartPosY, unsigned char *Buffer_Image,char string, unsigned LineColour){

	int SideLength = 2;
	//int LineColour = BLACK;
	COLOUR RGB;
	RGB = setcolor(LineColour);

	switch(string)
	    {
	case 'a':
	case 'A':
		DrawLetterA_New(StartPosX, StartPosY, LineColour, Buffer_Image);
		break;

	case 'b':
	case 'B':
//		DrawLetterB(StartPosX, StartPosY, SideLength, LineColour, Buffer_Image);
		DrawLetterB_New(StartPosX, StartPosY, LineColour, Buffer_Image);
		break;

	case 'c':
	case 'C':
//		DrawLetterC(StartPosX, StartPosY, SideLength, LineColour, Buffer_Image);
		DrawLetterC_New(StartPosX, StartPosY, LineColour, Buffer_Image);
		break;

	case 'd':
	case 'D':
//		DrawLetterD(StartPosX, StartPosY, SideLength, LineColour, Buffer_Image);
		DrawLetterD_New(StartPosX, StartPosY, LineColour, Buffer_Image);
		break;

	case 'e':
	case 'E':
//		DrawLetterE(StartPosX, StartPosY, SideLength, LineColour, Buffer_Image);
		DrawLetterE_New(StartPosX, StartPosY, LineColour, Buffer_Image);
		break;

	case 'f':
	case 'F':
//		DrawLetterF(StartPosX, StartPosY, SideLength, LineColour, Buffer_Image);
		DrawLetterF_New(StartPosX, StartPosY, LineColour, Buffer_Image);
		break;

	case 'g':
	case 'G':
//		DrawLetterG(StartPosX, StartPosY, SideLength, LineColour, Buffer_Image);
		DrawLetterG_New(StartPosX, StartPosY, LineColour, Buffer_Image);
		break;

	case 'h':
	case 'H':
//		DrawLetterH(StartPosX, StartPosY, SideLength, LineColour, Buffer_Image);
		DrawLetterH_New(StartPosX, StartPosY, LineColour, Buffer_Image);
		break;

	case 'i':
	case 'I':
//		DrawLetterI(StartPosX, StartPosY, SideLength, LineColour, Buffer_Image);
		DrawLetterI_New(StartPosX, StartPosY, LineColour, Buffer_Image);
		break;

	case 'j':
	case 'J':
		DrawLetterJ_New(StartPosX, StartPosY, LineColour, Buffer_Image);
//		DrawLetterJ(StartPosX, StartPosY, SideLength, LineColour, Buffer_Image);
		break;

	case 'k':
	case 'K':
		DrawLetterK_New(StartPosX, StartPosY, LineColour, Buffer_Image);
//		DrawLetterK(StartPosX, StartPosY, SideLength, LineColour, Buffer_Image);
		break;

	case 'l':
	case 'L':
		DrawLetterL_New(StartPosX, StartPosY, LineColour, Buffer_Image);
//		DrawLetterL(StartPosX, StartPosY, SideLength, LineColour, Buffer_Image);
		break;

	case 'm':
	case 'M':
		DrawLetterM_New(StartPosX, StartPosY, LineColour, Buffer_Image);
//		DrawLetterM(StartPosX, StartPosY, SideLength, LineColour, Buffer_Image);
		break;

	case 'n':
	case 'N':
		DrawLetterN_New(StartPosX, StartPosY, LineColour, Buffer_Image);
//		DrawLetterN(StartPosX, StartPosY, SideLength, LineColour, Buffer_Image);
		break;

	case 'o':
	case 'O':
		DrawLetterO_New(StartPosX, StartPosY, LineColour, Buffer_Image);
//		DrawLetterO(StartPosX, StartPosY, SideLength, LineColour, Buffer_Image);
		break;

	case 'p':
	case 'P':
		DrawLetterP_New(StartPosX, StartPosY, LineColour, Buffer_Image);
//		DrawLetterP(StartPosX, StartPosY, SideLength, LineColour, Buffer_Image);
		break;

	case 'q':
	case 'Q':
		DrawLetterQ_New(StartPosX, StartPosY, LineColour, Buffer_Image);
//		DrawLetterQ(StartPosX, StartPosY, SideLength, LineColour, Buffer_Image);
		break;

	case 'r':
	case 'R':
		DrawLetterR_New(StartPosX, StartPosY, LineColour, Buffer_Image);
//		DrawLetterR(StartPosX, StartPosY, SideLength, LineColour, Buffer_Image);
		break;

	case 's':
	case 'S':
		DrawLetterS_New(StartPosX, StartPosY, LineColour, Buffer_Image);
//		DrawLetterS(StartPosX, StartPosY, SideLength, LineColour, Buffer_Image);
		break;

	case 't':
	case 'T':
		DrawLetterT_New(StartPosX, StartPosY, LineColour, Buffer_Image);
//		DrawLetterT(StartPosX, StartPosY, SideLength, LineColour, Buffer_Image);
		break;

	case 'u':
	case 'U':
		DrawLetterU_New(StartPosX, StartPosY, LineColour, Buffer_Image);
//		DrawLetterU(StartPosX, StartPosY, SideLength, LineColour, Buffer_Image);
		break;

	case 'v':
	case 'V':
		DrawLetterV_New(StartPosX, StartPosY, LineColour, Buffer_Image);
//		DrawLetterV(StartPosX, StartPosY, SideLength, LineColour, Buffer_Image);
		break;

	case 'w':
	case 'W':
		DrawLetterW_New(StartPosX, StartPosY, LineColour, Buffer_Image);
//		DrawLetterW(StartPosX, StartPosY, SideLength, LineColour, Buffer_Image);
		break;

	case 'x':
	case 'X':
		DrawLetterX_New(StartPosX, StartPosY, LineColour, Buffer_Image);
//		DrawLetterX(StartPosX, StartPosY, SideLength, LineColour, Buffer_Image);
		break;

	case 'y':
	case 'Y':
		DrawLetterY_New(StartPosX, StartPosY, LineColour, Buffer_Image);
//		DrawLetterY(StartPosX, StartPosY, SideLength, LineColour, Buffer_Image);
		break;

	case 'z':
	case 'Z':
		DrawLetterZ_New(StartPosX, StartPosY, LineColour, Buffer_Image);
//		DrawLetterZ(StartPosX, StartPosY, SideLength, LineColour, Buffer_Image);
		break;

	case '0':
//		DrawNumber0(StartPosX, StartPosY, SideLength, LineColour, Buffer_Image);
		DrawNumber0_New(StartPosX, StartPosY, LineColour, Buffer_Image);
		break;

	case '1':
//		DrawNumber1(StartPosX, StartPosY, SideLength, LineColour, Buffer_Image);
		DrawNumber1_New(StartPosX, StartPosY, LineColour, Buffer_Image);
		break;

	case '2':
//		DrawNumber2(StartPosX, StartPosY, SideLength, LineColour, Buffer_Image);
		DrawNumber2_New(StartPosX, StartPosY, LineColour, Buffer_Image);
		break;

	case '3':
//		DrawNumber3(StartPosX, StartPosY, SideLength, LineColour, Buffer_Image);
		DrawNumber3_New(StartPosX, StartPosY, LineColour, Buffer_Image);
		break;

	case '4':
//		DrawNumber4(StartPosX, StartPosY, SideLength, LineColour, Buffer_Image);
		DrawNumber4_New(StartPosX, StartPosY, LineColour, Buffer_Image);
		break;

	case '5':
//		DrawNumber5(StartPosX, StartPosY, SideLength, LineColour, Buffer_Image);
		DrawNumber5_New(StartPosX, StartPosY, LineColour, Buffer_Image);
		break;

	case '6':
//		DrawNumber6(StartPosX, StartPosY, SideLength, LineColour, Buffer_Image);
		DrawNumber6_New(StartPosX, StartPosY, LineColour, Buffer_Image);
		break;

	case '7':
//		DrawNumber7(StartPosX, StartPosY, SideLength, LineColour, Buffer_Image);
		DrawNumber7_New(StartPosX, StartPosY, LineColour, Buffer_Image);
		break;

	case '8':
//		DrawNumber8(StartPosX, StartPosY, SideLength, LineColour, Buffer_Image);
		DrawNumber8_New(StartPosX, StartPosY, LineColour, Buffer_Image);
		break;

	case '9':
//		DrawNumber9(StartPosX, StartPosY, SideLength, LineColour, Buffer_Image);
		DrawNumber9_New(StartPosX, StartPosY, LineColour, Buffer_Image);
		break;

	case '.':
		DrawLetterFullStop_New(StartPosX, StartPosY, LineColour, Buffer_Image);
		break;
	case ',':
		DrawLetterComma_New(StartPosX, StartPosY, LineColour, Buffer_Image);
		break;
	case ':':
		DrawLetterColon_New(StartPosX, StartPosY, LineColour, Buffer_Image);
		break;
	case '_':
		DrawLetterUnderscore_New(StartPosX, StartPosY, LineColour, Buffer_Image);
		break;
	case '~':
		DrawLetterTilda_New(StartPosX, StartPosY, LineColour, Buffer_Image);
		break;
	case '/':
		DrawLetterFWSlash_New(StartPosX, StartPosY, LineColour, Buffer_Image);
		break;
	        // operator doesn't match any current choice /
	    default:
//	            printf("Error! Unknown operator ");
	        	;
	    }

}



void DrawNumber1Test(int StartPosX,int StartPosY,int LineColour, unsigned char *Buffer_Image){
	// set colour of number
	COLOUR RGB;
	RGB = setcolor(LineColour);

	int StartPosX_internal = StartPosX;
	int StartPosY_internal = StartPosY;
	   printf("Error! Unknown operator ");
	// reminder about data limit sections
	//Textsize_Horizontal 20
	//Textsize_Vertical 20

	// for loops iterate through the entire block of area where txt can be contained
	// vertical = i
	for(int i=StartPosY;i<(StartPosY+Textsize_Vertical);i++){
		//Horizontal = j
		for(int j=StartPosX;j<(StartPosX+(Textsize_Horizontal*3));j++){

		// draw horizontal bottom section of line
		//
		//	/|
		//	_|_
			if (( i >= StartPosY ) && ( i <= (StartPosY+19) )){
				if( (( j >= StartPosX ) && ( j <= (StartPosX+3) )) ){
						//blue
						Buffer_Image[(i*Horizontal_Size*3)+(j*3)]   = RGB.b;
						//green
						Buffer_Image[(i*Horizontal_Size*3)+(j*3)+1] = RGB.g;
						//red
						Buffer_Image[(i*Horizontal_Size*3)+(j*3)+2] = RGB.r;
				}
			}
		}

	}
}

/*****************************************************************************************************/
void DrawNumber0_New(int StartPosX,int StartPosY,int LineColour, unsigned char *Buffer_Image){
	int y = StartPosY;
	int x = StartPosX;

	int horizontal_mulitplyer = Horizontal_Size * 3;
	// set colour of number
	COLOUR RGB;
	RGB = setcolor(LineColour);

	int COLUMN = 20;
	const u8 Number_0[20][20] = {
			{ 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,16,17 },
			{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17,18 },
			{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16,17,18, 19 },
			{ 0, 1, 18, 19 },
			{ 0, 1, 5, 6, 7, 18, 19 },
			{ 0, 1, 7, 8, 9, 10, 18, 19 },
			{ 0, 1, 9, 10, 11, 12, 18, 19 },
			{ 0, 1, 12, 13, 14, 18, 19 },
			{ 0, 1, 18, 19 },
			{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16,17,18, 19 },
			{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17,18 },
			{ 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,16,17 },
			{ 0, 0 },
	};

	for (int columnCNT = 0; columnCNT < COLUMN; columnCNT++) {

		if (Number_0[columnCNT][0] + Number_0[columnCNT][1] == 0)
					break;

		for (int rowCNT = 0;
				rowCNT
						< sizeof(Number_0[columnCNT])
								/ sizeof(Number_0[columnCNT][rowCNT]);
				rowCNT++) {

			if (Number_0[columnCNT][rowCNT] == 0 && rowCNT > 0) {
				break;
			}
			//letter_Z[COLUMN][ROW]
			// row 0 --> column 0
			//blue
			Buffer_Image[(y * horizontal_mulitplyer)
					+ ((Number_0[columnCNT][rowCNT] + x) * 3)] = RGB.b;
			//green
			Buffer_Image[(y * horizontal_mulitplyer)
					+ ((Number_0[columnCNT][rowCNT] + x) * 3) + 1] = RGB.g;
			//red
			Buffer_Image[(y * horizontal_mulitplyer)
					+ ((Number_0[columnCNT][rowCNT] + x) * 3) + 2] = RGB.r;


		}
		x = StartPosX;

		y++;



	}
	Xil_DCacheFlush();

}

/*****************************************************************************************************/
void DrawNumber1_New(int StartPosX,int StartPosY,int LineColour, unsigned char *Buffer_Image){
	int y = StartPosY;
	int x = StartPosX;

	int horizontal_mulitplyer = Horizontal_Size * 3;
	// set colour of number
	COLOUR RGB;
	RGB = setcolor(LineColour);

	int COLUMN = 20;
	const u8 Number_1[20][20] = {
			{0, 1, 2, 15, 16, 17 },
			{0, 1, 2, 15, 16, 17},
			{0, 1, 2, 16, 17, 18 },
			{0, 1, 2, 16, 17, 18 },
			{0, 1, 2, 17, 18, 19 },
			{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16,17,18, 19 },
			{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16,17,18, 19 },
			{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16,17,18, 19 },
			{0, 1, 2},
			{0, 1, 2},
			{0, 1, 2},
			{0, 1, 2},
			{ 0, 0 },
	};

	for (int columnCNT = 0; columnCNT < COLUMN; columnCNT++) {

		if (Number_1[columnCNT][0] + Number_1[columnCNT][1] == 0)
					break;

		for (int rowCNT = 0;
				rowCNT
						< sizeof(Number_1[columnCNT])
								/ sizeof(Number_1[columnCNT][rowCNT]);
				rowCNT++) {

			if (Number_1[columnCNT][rowCNT] == 0 && rowCNT > 0) {
				break;
			}
			//letter_Z[COLUMN][ROW]
			// row 0 --> column 0
			//blue
			Buffer_Image[(y * horizontal_mulitplyer)
					+ ((Number_1[columnCNT][rowCNT] + x) * 3)] = RGB.b;
			//green
			Buffer_Image[(y * horizontal_mulitplyer)
					+ ((Number_1[columnCNT][rowCNT] + x) * 3) + 1] = RGB.g;
			//red
			Buffer_Image[(y * horizontal_mulitplyer)
					+ ((Number_1[columnCNT][rowCNT] + x) * 3) + 2] = RGB.r;


		}
		x = StartPosX;

		y++;



	}
	Xil_DCacheFlush();

}

/*****************************************************************************************************/
void DrawNumber2_New(int StartPosX,int StartPosY,int LineColour, unsigned char *Buffer_Image){
	int y = StartPosY;
	int x = StartPosX;

	int horizontal_mulitplyer = Horizontal_Size * 3;
	// set colour of number
	COLOUR RGB;
	RGB = setcolor(LineColour);

	int COLUMN = 20;
	const u8 Number_2[20][20] = {
			{0,1,2,3,4,5,6,16,17},
			{0,1,2,3,4,5,6,7,16,17,18},
			{0,1,2,6,7,8,17,18,19},
			{0,1,2,7,8,9,18,19},
			{0,1,2,8,9,10,18,19},
			{0,1,2,9,10,11,18,19},
			{0,1,2,10,11,12,18,19},
			{0,1,2,11,12,13,18,19},
			{0,1,2,12,13,14,18,19},
			{0,1,2,13,14,15,18,19},
			{0,1,2,14,15,16,17,18},
			{0,1,2,16,17},

			{ 0, 0 },
	};

	for (int columnCNT = 0; columnCNT < COLUMN; columnCNT++) {


		if (Number_2[columnCNT][0] + Number_2[columnCNT][1] == 0)
			break;

		for (int rowCNT = 0;rowCNT< sizeof(Number_2[columnCNT])	/ sizeof(Number_2[columnCNT][rowCNT]);rowCNT++) {
			if (Number_2[columnCNT][rowCNT] == 0 && rowCNT > 0) {
				break;
			}
			//letter_Z[COLUMN][ROW]
			// row 0 --> column 0
			//blue
			Buffer_Image[(y * horizontal_mulitplyer)
					+ ((Number_2[columnCNT][rowCNT] + x) * 3)] = RGB.b;
			//green
			Buffer_Image[(y * horizontal_mulitplyer)
					+ ((Number_2[columnCNT][rowCNT] + x) * 3) + 1] = RGB.g;
			//red
			Buffer_Image[(y * horizontal_mulitplyer)
					+ ((Number_2[columnCNT][rowCNT] + x) * 3) + 2] = RGB.r;


		}
		x = StartPosX;

		y++;


	}
	Xil_DCacheFlush();

}

/*****************************************************************************************************/
void DrawNumber3_New(int StartPosX,int StartPosY,int LineColour, unsigned char *Buffer_Image){
	int y = StartPosY;
	int x = StartPosX;

	int horizontal_mulitplyer = Horizontal_Size * 3;
	// set colour of number
	COLOUR RGB;
	RGB = setcolor(LineColour);

	int COLUMN = 20;
	const u8 Number_3[20][20] = {
			{2,3,16,17},
			{1,2,3,16,17,18},
			{0,1,18,19},
			{0,1,18,19},
			{0,1,9,10,18,19},
			{0,1,9,10,18,19},
			{0,1,9,10,18,19},
			{0,1,9,10,18,19},
			{0,1,9,10,18,19},
			{0,1,9,10,18,19},
			{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18},
			{2,3,4,5,6,7,8,11,12,13,14,15,16,17 },
			{ 0, 0 },
	};

	for (int columnCNT = 0; columnCNT < COLUMN; columnCNT++) {

		if (Number_3[columnCNT][0] + Number_3[columnCNT][1] == 0)
				break;
		for (int rowCNT = 0;
				rowCNT
						< sizeof(Number_3[columnCNT])
								/ sizeof(Number_3[columnCNT][rowCNT]);
				rowCNT++) {

			if (Number_3[columnCNT][rowCNT] == 0 && rowCNT > 0) {
				break;
			}
			//letter_Z[COLUMN][ROW]
			// row 0 --> column 0
			//blue
			Buffer_Image[(y * horizontal_mulitplyer)
					+ ((Number_3[columnCNT][rowCNT] + x) * 3)] = RGB.b;
			//green
			Buffer_Image[(y * horizontal_mulitplyer)
					+ ((Number_3[columnCNT][rowCNT] + x) * 3) + 1] = RGB.g;
			//red
			Buffer_Image[(y * horizontal_mulitplyer)
					+ ((Number_3[columnCNT][rowCNT] + x) * 3) + 2] = RGB.r;


		}
		x = StartPosX;

		y++;



	}
	Xil_DCacheFlush();

}

/*****************************************************************************************************/
void DrawNumber4_New(int StartPosX,int StartPosY,int LineColour, unsigned char *Buffer_Image){
	int y = StartPosY;
	int x = StartPosX;

	int horizontal_mulitplyer = Horizontal_Size * 3;
	// set colour of number
	COLOUR RGB;
	RGB = setcolor(LineColour);

	int COLUMN = 20;
	const u8 Number_4[20][20] = {
			 {7,8,9,10},
			 {7,8,9,10,11},
			 {7,8,10,11,12},
			 {7,8,11,12,13},
			 {7,8,12,13,14},
			 {7,8,13,14,15},
			 {7,8,14,15,16},
			 {7,8,15,16,17},
			 {7,8,16,17,18},
			 {7,8,17,18,19},
			 {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19},
			 {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19},
			 {7,8},
			 {7,8},
			 {7,8},
			 {7,8},

			{ 0, 0 },
	};

	for (int columnCNT = 0; columnCNT < COLUMN; columnCNT++) {

		if (Number_4[columnCNT][0] + Number_4[columnCNT][1] == 0)
					break;

		for (int rowCNT = 0;
				rowCNT
						< sizeof(Number_4[columnCNT])
								/ sizeof(Number_4[columnCNT][rowCNT]);
				rowCNT++) {

			if (Number_4[columnCNT][rowCNT] == 0 && rowCNT > 0) {
				break;
			}
			//letter_Z[COLUMN][ROW]
			// row 0 --> column 0
			//blue
			Buffer_Image[(y * horizontal_mulitplyer)
					+ ((Number_4[columnCNT][rowCNT] + x) * 3)] = RGB.b;
			//green
			Buffer_Image[(y * horizontal_mulitplyer)
					+ ((Number_4[columnCNT][rowCNT] + x) * 3) + 1] = RGB.g;
			//red
			Buffer_Image[(y * horizontal_mulitplyer)
					+ ((Number_4[columnCNT][rowCNT] + x) * 3) + 2] = RGB.r;


		}
		x = StartPosX;

		y++;



	}
	Xil_DCacheFlush();

}

/*****************************************************************************************************/
void DrawNumber5_New(int StartPosX,int StartPosY,int LineColour, unsigned char *Buffer_Image){
	int y = StartPosY;
	int x = StartPosX;

	int horizontal_mulitplyer = Horizontal_Size * 3;
	// set colour of number
	COLOUR RGB;
	RGB = setcolor(LineColour);

	int COLUMN = 20;
	const u8 Number_5[20][20] = {

			{0,1,10,11,12,13,14,15,16,17,18,19},
			{0,1,10,11,12,13,14,15,16,17,18,19},
			{0,1,10,11,18,19},
			{0,1,10,11,18,19},
			{0,1,10,11,18,19},
			{0,110,11,18,19},
			{0,110,11,18,19},
			{0,110,11,18,19},
			{0,110,11,18,19},
			{0,110,11,18,19},
			{1,2,3,4,5,6,7,8,9,10,18,19},
			{2,3,4,5,6,7,8,9,18,19},
			{ 0, 0 },
	};

	for (int columnCNT = 0; columnCNT < COLUMN; columnCNT++) {

		if (Number_5[columnCNT][0] + Number_5[columnCNT][1] == 0)
				break;

		for (int rowCNT = 0;
				rowCNT
						< sizeof(Number_5[columnCNT])
								/ sizeof(Number_5[columnCNT][rowCNT]);
				rowCNT++) {

			if (Number_5[columnCNT][rowCNT] == 0 && rowCNT > 0) {
				break;
			}
			//letter_Z[COLUMN][ROW]
			// row 0 --> column 0
			//blue
			Buffer_Image[(y * horizontal_mulitplyer)
					+ ((Number_5[columnCNT][rowCNT] + x) * 3)] = RGB.b;
			//green
			Buffer_Image[(y * horizontal_mulitplyer)
					+ ((Number_5[columnCNT][rowCNT] + x) * 3) + 1] = RGB.g;
			//red
			Buffer_Image[(y * horizontal_mulitplyer)
					+ ((Number_5[columnCNT][rowCNT] + x) * 3) + 2] = RGB.r;


		}
		x = StartPosX;

		y++;



	}
	Xil_DCacheFlush();

}

/*****************************************************************************************************/
void DrawNumber6_New(int StartPosX,int StartPosY,int LineColour, unsigned char *Buffer_Image){
	int y = StartPosY;
	int x = StartPosX;

	int horizontal_mulitplyer = Horizontal_Size * 3;
	// set colour of number
	COLOUR RGB;
	RGB = setcolor(LineColour);

	int COLUMN = 20;
	const u8 Number_6[20][20] = {

			 {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18},
			{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19},
			{0,1,10,11,18,19},
			{0,1,10,11,18,19},
			{0,1,10,11,18,19},
			{0,1,10,11,18,19},
			{0,1,10,11,18,19},
			{0,1,10,11,18,19},
			{0,1,10,11,18,19},
			{0,1,10,11,18,19},
			{1,2,3,4,5,6,7,8,9,10,18,19},
			{2,3,4,5,6,7,8,9,18,19},
			{ 0, 0 },
	};

	for (int columnCNT = 0; columnCNT < COLUMN; columnCNT++) {

		if (Number_6[columnCNT][0] + Number_6[columnCNT][1] == 0)
					break;

		for (int rowCNT = 0;
				rowCNT
						< sizeof(Number_6[columnCNT])
								/ sizeof(Number_6[columnCNT][rowCNT]);
				rowCNT++) {

			if (Number_6[columnCNT][rowCNT] == 0 && rowCNT > 0) {
				break;
			}
			//letter_Z[COLUMN][ROW]
			// row 0 --> column 0
			//blue
			Buffer_Image[(y * horizontal_mulitplyer)
					+ ((Number_6[columnCNT][rowCNT] + x) * 3)] = RGB.b;
			//green
			Buffer_Image[(y * horizontal_mulitplyer)
					+ ((Number_6[columnCNT][rowCNT] + x) * 3) + 1] = RGB.g;
			//red
			Buffer_Image[(y * horizontal_mulitplyer)
					+ ((Number_6[columnCNT][rowCNT] + x) * 3) + 2] = RGB.r;


		}
		x = StartPosX;

		y++;



	}
	Xil_DCacheFlush();

}

/*****************************************************************************************************/
void DrawNumber7_New(int StartPosX,int StartPosY,int LineColour, unsigned char *Buffer_Image){
	int y = StartPosY;
	int x = StartPosX;

	int horizontal_mulitplyer = Horizontal_Size * 3;
	// set colour of number
	COLOUR RGB;
	RGB = setcolor(LineColour);

	int COLUMN = 20;
	const u8 Number_7[20][20] = {

			{18,19 },
			{18,19 },
			{0,1,2,3,4,5,6,7,18,19 },
			{0,1,2,3,4,5,6,7,8,18,19 },
			{ 8,9,18,19 },
			{ 9,10,18,19 },
			{ 10,11,18,19 },
			{ 11,12,18,19 },
			{12,13,18,19 },
			{ 13,14,18,19 },
			{ 14,15,16,17,18,19 },
			{ 14,15,16,17,18,19 },
			{ 0, 0 },
	};

	for (int columnCNT = 0; columnCNT < COLUMN; columnCNT++) {

		if (Number_7[columnCNT][0] + Number_7[columnCNT][1] == 0)
					break;

		for (int rowCNT = 0;
				rowCNT
						< sizeof(Number_7[columnCNT])
								/ sizeof(Number_7[columnCNT][rowCNT]);
				rowCNT++) {

			if (Number_7[columnCNT][rowCNT] == 0 && rowCNT > 0) {
				break;
			}
			//letter_Z[COLUMN][ROW]
			// row 0 --> column 0
			//blue
			Buffer_Image[(y * horizontal_mulitplyer)
					+ ((Number_7[columnCNT][rowCNT] + x) * 3)] = RGB.b;
			//green
			Buffer_Image[(y * horizontal_mulitplyer)
					+ ((Number_7[columnCNT][rowCNT] + x) * 3) + 1] = RGB.g;
			//red
			Buffer_Image[(y * horizontal_mulitplyer)
					+ ((Number_7[columnCNT][rowCNT] + x) * 3) + 2] = RGB.r;


		}
		x = StartPosX;

		y++;



	}
	Xil_DCacheFlush();

}

/*****************************************************************************************************/
void DrawNumber8_New(int StartPosX,int StartPosY,int LineColour, unsigned char *Buffer_Image){
	int y = StartPosY;
	int x = StartPosX;

	int horizontal_mulitplyer = Horizontal_Size * 3;
	// set colour of number
	COLOUR RGB;
	RGB = setcolor(LineColour);

	int COLUMN = 20;
	const u8 Number_8[20][20] = {

			{ 2,3,4,5,6,7,8,9,13,14,15,16,17},
			{ 1,2,3,4,5,6,7,8,9,10,12,13,14,15,16,17,18},
			{0,1,10,11,12,18,19},
			{0,1,10,11,12,18,19},
			{0,1,10,11,12,18,19},
			{0,1,10,11,12,18,19},
			{0,1,10,11,12,18,19},
			{0,1,10,11,12,18,19},
			{0,1, 10,11,12,18,19},
			{0,1,10,11,12,18,19},
			{ 1,2,3,4,5,6,7,8,9,10,12,13,14,15,16,17,18},
			{ 2,3,4,5,6,7,8,9,13,14,15,16,17},
			{ 0, 0 },
	};

	for (int columnCNT = 0; columnCNT < COLUMN; columnCNT++) {

		if (Number_8[columnCNT][0] + Number_8[columnCNT][1] == 0)
					break;

		for (int rowCNT = 0;
				rowCNT
						< sizeof(Number_8[columnCNT])
								/ sizeof(Number_8[columnCNT][rowCNT]);
				rowCNT++) {

			if (Number_8[columnCNT][rowCNT] == 0 && rowCNT > 0) {
				break;
			}
			//letter_Z[COLUMN][ROW]
			// row 0 --> column 0
			//blue
			Buffer_Image[(y * horizontal_mulitplyer)
					+ ((Number_8[columnCNT][rowCNT] + x) * 3)] = RGB.b;
			//green
			Buffer_Image[(y * horizontal_mulitplyer)
					+ ((Number_8[columnCNT][rowCNT] + x) * 3) + 1] = RGB.g;
			//red
			Buffer_Image[(y * horizontal_mulitplyer)
					+ ((Number_8[columnCNT][rowCNT] + x) * 3) + 2] = RGB.r;


		}
		x = StartPosX;

		y++;



	}
	Xil_DCacheFlush();

}

/*****************************************************************************************************/
void DrawNumber9_New(int StartPosX,int StartPosY,int LineColour, unsigned char *Buffer_Image){
	int y = StartPosY;
	int x = StartPosX;

	int horizontal_mulitplyer = Horizontal_Size * 3;
	// set colour of number
	COLOUR RGB;
	RGB = setcolor(LineColour);

	int COLUMN = 20;
	const u8 Number_9[20][20] = {
			{13,14,15,16,17},
			{12,13,14,15,16,17,18},
			{11,12,18,19},
			{11,12,18,19},
			{11,12,18,19},
			{11,12,18,19},
			{11,12,18,19},
			{11,12,18,19},
			{11,12,18,19},
			{11,12,18,19},
			{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18},
			{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17},
			{ 0, 0 },
	};

	for (int columnCNT = 0; columnCNT < COLUMN; columnCNT++) {
		if (Number_9[columnCNT][0] + Number_9[columnCNT][1] == 0)
					break;

		for (int rowCNT = 0;
				rowCNT
						< sizeof(Number_9[columnCNT])
								/ sizeof(Number_9[columnCNT][rowCNT]);
				rowCNT++) {

			if (Number_9[columnCNT][rowCNT] == 0 && rowCNT > 0) {
				break;
			}
			//letter_Z[COLUMN][ROW]
			// row 0 --> column 0
			//blue
			Buffer_Image[(y * horizontal_mulitplyer)
					+ ((Number_9[columnCNT][rowCNT] + x) * 3)] = RGB.b;
			//green
			Buffer_Image[(y * horizontal_mulitplyer)
					+ ((Number_9[columnCNT][rowCNT] + x) * 3) + 1] = RGB.g;
			//red
			Buffer_Image[(y * horizontal_mulitplyer)
					+ ((Number_9[columnCNT][rowCNT] + x) * 3) + 2] = RGB.r;


		}
		x = StartPosX;

		y++;



	}
	Xil_DCacheFlush();

}

/*****************************************************************************************************/
void DrawLetterA_New(int StartPosX,int StartPosY,int LineColour, unsigned char *Buffer_Image){
	int y = StartPosY;
	int x = StartPosX;

	int horizontal_mulitplyer = Horizontal_Size * 3;
	// set colour of number
	COLOUR RGB;
	RGB = setcolor(LineColour);

	int COLUMN = 20;
	const u8 letter_A[20][20] = {
			{0,1,2,3,4,5,6,7,8,9,10,11,12,13},
			{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14},
			{6,7,13,14,15},
			{6,7,14,15,16},
			{6,7,15,16,17},
			{6,7,16,17,18},
			{6,7,17,18,19},
		    {6,7,17,18,19},
			{6,7,16,17,18},
			{6,7,15,16,17},
			{6,7,14,15,16},
			{6,7,13,14,15},
			{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14},
			{0,1,2,3,4,5,6,7,8,9,10,11,12,13},
			{ 0, 0 },
	};

	for (int columnCNT = 0; columnCNT < COLUMN; columnCNT++) {

		if (letter_A[columnCNT][0] + letter_A[columnCNT][1] == 0)
					break;
		for (int rowCNT = 0;
				rowCNT
						< sizeof(letter_A[columnCNT])
								/ sizeof(letter_A[columnCNT][rowCNT]);
				rowCNT++) {

			if (letter_A[columnCNT][rowCNT] == 0 && rowCNT > 0) {
				break;
			}
			//letter_Z[COLUMN][ROW]
			// row 0 --> column 0
			//blue
			Buffer_Image[(y * horizontal_mulitplyer)
					+ ((letter_A[columnCNT][rowCNT] + x) * 3)] = RGB.b;
			//green
			Buffer_Image[(y * horizontal_mulitplyer)
					+ ((letter_A[columnCNT][rowCNT] + x) * 3) + 1] = RGB.g;
			//red
			Buffer_Image[(y * horizontal_mulitplyer)
					+ ((letter_A[columnCNT][rowCNT] + x) * 3) + 2] = RGB.r;


		}
		x = StartPosX;

		y++;



	}
	Xil_DCacheFlush();

}

/*****************************************************************************************************/
void DrawLetterB_New(int StartPosX,int StartPosY,int LineColour, unsigned char *Buffer_Image){
	int y = StartPosY;
	int x = StartPosX;

	int horizontal_mulitplyer = Horizontal_Size * 3;
	// set colour of number
	COLOUR RGB;
	RGB = setcolor(LineColour);

	int COLUMN = 20;
	const u8 letter_B[20][20] = {
			{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19},
			{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19},
			{0,1,9,10,11,18,19},
			{0,1,9,10,11,18,19},
			{0,1,9,10,11,18,19},
			{0,1,9,10,11,18,19},
			{0,1,9,10,11,18,19},
			{0,1,9,10,11,18,19},
			{0,1,9,10,11,18,19},
			{0,1,9,10,11,18,19},
			{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18},
			{2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17},
			{ 0, 0 },
	};

	for (int columnCNT = 0; columnCNT < COLUMN; columnCNT++) {

		if (letter_B[columnCNT][0] + letter_B[columnCNT][1] == 0)
					break;
		for (int rowCNT = 0;
				rowCNT
						< sizeof(letter_B[columnCNT])
								/ sizeof(letter_B[columnCNT][rowCNT]);
				rowCNT++) {

			if (letter_B[columnCNT][rowCNT] == 0 && rowCNT > 0) {
				break;
			}
			//letter_Z[COLUMN][ROW]
			// row 0 --> column 0
			//blue
			Buffer_Image[(y * horizontal_mulitplyer)
					+ ((letter_B[columnCNT][rowCNT] + x) * 3)] = RGB.b;
			//green
			Buffer_Image[(y * horizontal_mulitplyer)
					+ ((letter_B[columnCNT][rowCNT] + x) * 3) + 1] = RGB.g;
			//red
			Buffer_Image[(y * horizontal_mulitplyer)
					+ ((letter_B[columnCNT][rowCNT] + x) * 3) + 2] = RGB.r;


		}
		x = StartPosX;

		y++;



	}
	Xil_DCacheFlush();

}


/*****************************************************************************************************/
void DrawLetterC_New(int StartPosX,int StartPosY,int LineColour, unsigned char *Buffer_Image){
	int y = StartPosY;
	int x = StartPosX;

	int horizontal_mulitplyer = Horizontal_Size * 3;
	// set colour of number
	COLOUR RGB;
	RGB = setcolor(LineColour);

	int COLUMN = 20;
	const u8 letter_C[20][20] = {
			{2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17},
			{2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18 },
			{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19},
			{0,1,2,3,16,17,18,19},
			{0,1,2,17,18,19},
			{0,1,18,19},
			{0,1,18,19},
			{0,1,18,19},
			{0,1,18,19},
			{0,1,2,17,18,19},
			{0,1,2,3,16,17,18,19},
			{0,1,2,3,4,15,16,17,18,19},
			{1,2,3,4,15,16,17,18},
			{2,3,4,15,16,17},
			{ 0, 0 },
	};

	for (int columnCNT = 0; columnCNT < COLUMN; columnCNT++) {

		if (letter_C[columnCNT][0] + letter_C[columnCNT][1] == 0)
					break;

		for (int rowCNT = 0;
				rowCNT
						< sizeof(letter_C[columnCNT])
								/ sizeof(letter_C[columnCNT][rowCNT]);
				rowCNT++) {

			if (letter_C[columnCNT][rowCNT] == 0 && rowCNT > 0) {
				break;
			}
			//letter_Z[COLUMN][ROW]
			// row 0 --> column 0
			//blue
			Buffer_Image[(y * horizontal_mulitplyer)
					+ ((letter_C[columnCNT][rowCNT] + x) * 3)] = RGB.b;
			//green
			Buffer_Image[(y * horizontal_mulitplyer)
					+ ((letter_C[columnCNT][rowCNT] + x) * 3) + 1] = RGB.g;
			//red
			Buffer_Image[(y * horizontal_mulitplyer)
					+ ((letter_C[columnCNT][rowCNT] + x) * 3) + 2] = RGB.r;


		}
		x = StartPosX;

		y++;



	}
	Xil_DCacheFlush();

}

/*****************************************************************************************************/
void DrawLetterD_New(int StartPosX,int StartPosY,int LineColour, unsigned char *Buffer_Image){
	int y = StartPosY;
	int x = StartPosX;

	int horizontal_mulitplyer = Horizontal_Size * 3;
	// set colour of number
	COLOUR RGB;
	RGB = setcolor(LineColour);

	int COLUMN = 20;
	const u8 letter_D[20][20] = {
			{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19},
			{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19},
			{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19},
			{0,1,2,17,18,19},
			{0,1,2,17,18,19},
			{0,1,2,17,18,19},
			{0,1,2,17,18,19},
			{0,1,2,17,18,19},
			{0,1,2,17,18,19},
			{0,1,2,3,16,17,18,19},
			{1,2,3,4,15,16,17,18},
			{2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17},
			{3,4,5,6,7,8,9,10,11,12,13,14,15,16,17},
			{4,5,6,7,8,9,10,11,12,13,14,15,16},
			{ 0, 0 },
	};

	for (int columnCNT = 0; columnCNT < COLUMN; columnCNT++) {

		if (letter_D[columnCNT][0] + letter_D[columnCNT][1] == 0)
					break;

		for (int rowCNT = 0;
				rowCNT
						< sizeof(letter_D[columnCNT])
								/ sizeof(letter_D[columnCNT][rowCNT]);
				rowCNT++) {

			if (letter_D[columnCNT][rowCNT] == 0 && rowCNT > 0) {
				break;
			}
			//letter_Z[COLUMN][ROW]
			// row 0 --> column 0
			//blue
			Buffer_Image[(y * horizontal_mulitplyer)
					+ ((letter_D[columnCNT][rowCNT] + x) * 3)] = RGB.b;
			//green
			Buffer_Image[(y * horizontal_mulitplyer)
					+ ((letter_D[columnCNT][rowCNT] + x) * 3) + 1] = RGB.g;
			//red
			Buffer_Image[(y * horizontal_mulitplyer)
					+ ((letter_D[columnCNT][rowCNT] + x) * 3) + 2] = RGB.r;


		}
		x = StartPosX;

		y++;



	}
	Xil_DCacheFlush();

}


/*****************************************************************************************************/
void DrawLetterE_New(int StartPosX,int StartPosY,int LineColour, unsigned char *Buffer_Image){
	int y = StartPosY;
	int x = StartPosX;

	int horizontal_mulitplyer = Horizontal_Size * 3;
	// set colour of number
	COLOUR RGB;
	RGB = setcolor(LineColour);

	int COLUMN = 20;
	const u8 letter_E[20][20] = {
			{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19},
			{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19},
			{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19},
			{0,1,2,9,10,11,17,18,19},
			{0,1,2,9,10,11,17,18,19},
			{0,1,2,9,10,11,17,18,19},
			{0,1,2,9,10,11,17,18,19},
			{0,1,2,9,10,11,17,18,19},
			{0,1,2,9,10,11,17,18,19},
			{0,1,2,9,10,11,17,18,19},
			{0,1,2,9,10,11,17,18,19},
			{0,1,2,17,18,19},
			{0,1,2,17,18,19},
			{0,1,2,17,18,19},
			{ 0, 0 },
	};

	for (int columnCNT = 0; columnCNT < COLUMN; columnCNT++) {
		if (letter_E[columnCNT][0] + letter_E[columnCNT][1] == 0)
					break;

		for (int rowCNT = 0;
				rowCNT
						< sizeof(letter_E[columnCNT])
								/ sizeof(letter_E[columnCNT][rowCNT]);
				rowCNT++) {

			if (letter_E[columnCNT][rowCNT] == 0 && rowCNT > 0) {
				break;
			}
			//letter_Z[COLUMN][ROW]
			// row 0 --> column 0
			//blue
			Buffer_Image[(y * horizontal_mulitplyer)
					+ ((letter_E[columnCNT][rowCNT] + x) * 3)] = RGB.b;
			//green
			Buffer_Image[(y * horizontal_mulitplyer)
					+ ((letter_E[columnCNT][rowCNT] + x) * 3) + 1] = RGB.g;
			//red
			Buffer_Image[(y * horizontal_mulitplyer)
					+ ((letter_E[columnCNT][rowCNT] + x) * 3) + 2] = RGB.r;


		}
		x = StartPosX;

		y++;



	}
	Xil_DCacheFlush();

}

/*****************************************************************************************************/
void DrawLetterF_New(int StartPosX,int StartPosY,int LineColour, unsigned char *Buffer_Image){
	int y = StartPosY;
	int x = StartPosX;

	int horizontal_mulitplyer = Horizontal_Size * 3;
	// set colour of number
	COLOUR RGB;
	RGB = setcolor(LineColour);

	int COLUMN = 20,ROW=20;
	const u8 letter_F[20][20] = {
			{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19 },
			{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19 },
			{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19 },
			{9,10,11,17,18,19 },
			{9,10,11,17,18,19 },
			{9,10,11,17,18,19 },
			{9,10,11,17,18,19 },
			{9,10,11,17,18,19 },
			{9,10,11,17,18,19 },
			{9,10,11,17,18,19 },
			{17,18,19 },
			{17,18,19 },
			{17,18,19 },
			{17,18,19 },
			{ 0, 0 },
	};

	for (int columnCNT = 0; columnCNT < COLUMN; columnCNT++) {
		if (letter_F[columnCNT][0] + letter_F[columnCNT][1] == 0){
			break;
		}


		for (int rowCNT = 0;rowCNT< ROW;
				rowCNT++) {

			if (letter_F[columnCNT][rowCNT] == 0 && rowCNT > 0) {
				break;
			}
			//letter_Z[COLUMN][ROW]
			// row 0 --> column 0
			//blue
			Buffer_Image[(y * horizontal_mulitplyer)
					+ ((letter_F[columnCNT][rowCNT] + x) * 3)] = RGB.b;
			//green
			Buffer_Image[(y * horizontal_mulitplyer)
					+ ((letter_F[columnCNT][rowCNT] + x) * 3) + 1] = RGB.g;
			//red
			Buffer_Image[(y * horizontal_mulitplyer)
					+ ((letter_F[columnCNT][rowCNT] + x) * 3) + 2] = RGB.r;


		}
		x = StartPosX;

		y++;



	}
	Xil_DCacheFlush();

}

/*****************************************************************************************************/
void DrawLetterG_New(int StartPosX,int StartPosY,int LineColour, unsigned char *Buffer_Image){
	int y = StartPosY;
	int x = StartPosX;

	int horizontal_mulitplyer = Horizontal_Size * 3;
	// set colour of number
	COLOUR RGB;
	RGB = setcolor(LineColour);

	int COLUMN = 20;
	const u8 letter_G[20][20] = {
			{2,3,4,5,6,7,8,9,10,11,12,13,14,15,16},
			{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17},
			{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18},
			{0,1,2,3,17,18,19},
			{0,1,2,18,19},
			{0,1,18,19},
			{0,1,9,10,11,18,19},
			{0,1,9,10,11,18,19},
			{0,1,9,10,11,18,19},
			{0,1,9,10,11,18,19},
			{0,1,2,9,10,11,18,19},
			{0,1,2,3,9,10,11,17,18,19},
			{1,2,3,4,5,6,7,8,9,10,11,16,17,18 },
			{2,3,4,5,6,7,8,9,10,11,16,17},
			{ 0, 0 },
	};

	for (int columnCNT = 0; columnCNT < COLUMN; columnCNT++) {

		if (letter_G[columnCNT][0] + letter_G[columnCNT][1] == 0)
				break;

		for (int rowCNT = 0;
				rowCNT
						< sizeof(letter_G[columnCNT])
								/ sizeof(letter_G[columnCNT][rowCNT]);
				rowCNT++) {

			if (letter_G[columnCNT][rowCNT] == 0 && rowCNT > 0) {
				break;
			}
			//letter_Z[COLUMN][ROW]
			// row 0 --> column 0
			//blue
			Buffer_Image[(y * horizontal_mulitplyer)
					+ ((letter_G[columnCNT][rowCNT] + x) * 3)] = RGB.b;
			//green
			Buffer_Image[(y * horizontal_mulitplyer)
					+ ((letter_G[columnCNT][rowCNT] + x) * 3) + 1] = RGB.g;
			//red
			Buffer_Image[(y * horizontal_mulitplyer)
					+ ((letter_G[columnCNT][rowCNT] + x) * 3) + 2] = RGB.r;


		}
		x = StartPosX;

		y++;



	}
	Xil_DCacheFlush();

}

/*****************************************************************************************************/
void DrawLetterH_New(int StartPosX,int StartPosY,int LineColour, unsigned char *Buffer_Image){
	int y = StartPosY;
	int x = StartPosX;

	int horizontal_mulitplyer = Horizontal_Size * 3;
	// set colour of number
	COLOUR RGB;
	RGB = setcolor(LineColour);

	int COLUMN = 20;
	const u8 letter_H[20][20] = {
			{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19},
			{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19},
			{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19},
			{9,10,11},
			{9,10,11},
			{9,10,11},
			{9,10,11},
			{9,10,11},
			{9,10,11},
			{9,10,11},
			{9,10,11},
			{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19},
			{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19},
			{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19},
			{ 0, 0 },
	};

	for (int columnCNT = 0; columnCNT < COLUMN; columnCNT++) {


		if (letter_H[columnCNT][0] + letter_H[columnCNT][1] == 0){
			break;
		}

		for (int rowCNT = 0;
				rowCNT
						< sizeof(letter_H[columnCNT])
								/ sizeof(letter_H[columnCNT][rowCNT]);
				rowCNT++) {

			if (letter_H[columnCNT][rowCNT] == 0 && rowCNT > 0) {
				break;
			}
			//letter_Z[COLUMN][ROW]
			// row 0 --> column 0
			//blue
			Buffer_Image[(y * horizontal_mulitplyer)
					+ ((letter_H[columnCNT][rowCNT] + x) * 3)] = RGB.b;
			//green
			Buffer_Image[(y * horizontal_mulitplyer)
					+ ((letter_H[columnCNT][rowCNT] + x) * 3) + 1] = RGB.g;
			//red
			Buffer_Image[(y * horizontal_mulitplyer)
					+ ((letter_H[columnCNT][rowCNT] + x) * 3) + 2] = RGB.r;


		}
		x = StartPosX;

		y++;


	}
	Xil_DCacheFlush();

}

/*****************************************************************************************************/
void DrawLetterI_New(int StartPosX,int StartPosY,int LineColour, unsigned char *Buffer_Image){
	int y = StartPosY;
	int x = StartPosX;

	int horizontal_mulitplyer = Horizontal_Size * 3;
	// set colour of number
	COLOUR RGB;
	RGB = setcolor(LineColour);

	int COLUMN = 20;
	const u8 letter_I[20][20] = {
			{0,1,2,17,18,19},
			{0,1,2,17,18,19},
			{0,1,2,17,18,19},
			{0,1,2,17,18,19},
			{0,1,2,17,18,19},
			{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19},
			{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19},
			{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19},
			{0,1,2,17,18,19},
			{0,1,2,17,18,19},
			{0,1,2,17,18,19},
			{0,1,2,17,18,19},
			{0,1,2,17,18,19},
			{0,1,2,17,18,19},
			{ 0, 0 },
	};

	for (int columnCNT = 0; columnCNT < COLUMN; columnCNT++) {
		if (letter_I[columnCNT][0] + letter_I[columnCNT][1] == 0)
					break;

		for (int rowCNT = 0;rowCNT< sizeof(letter_I[columnCNT])	/ sizeof(letter_I[columnCNT][rowCNT]);	rowCNT++) {

			if (letter_I[columnCNT][rowCNT] == 0 && rowCNT > 0) {
				break;
			}
			//letter_Z[COLUMN][ROW]
			// row 0 --> column 0
			//blue
			Buffer_Image[(y * horizontal_mulitplyer)
					+ ((letter_I[columnCNT][rowCNT] + x) * 3)] = RGB.b;
			//green
			Buffer_Image[(y * horizontal_mulitplyer)
					+ ((letter_I[columnCNT][rowCNT] + x) * 3) + 1] = RGB.g;
			//red
			Buffer_Image[(y * horizontal_mulitplyer)
					+ ((letter_I[columnCNT][rowCNT] + x) * 3) + 2] = RGB.r;


		}
		x = StartPosX;

		y++;



	}
	Xil_DCacheFlush();

}

/*****************************************************************************************************/



void DrawLetterJ_New(int StartPosX,int StartPosY,int LineColour, unsigned char *Buffer_Image){

	int y = StartPosY;
	int x = StartPosX;

	int horizontal_mulitplyer = Horizontal_Size * 3;
	// set colour of number
	COLOUR RGB;
	RGB = setcolor(LineColour);


		int COLUMN=20, ROW=20;
			const u8 letter_J[20][20]=
			{
					 {3,4,5},
					 {2,3,4,5},
					 {1,2,3,4,5},
					{0,1,2},
					{0,1,2},
					{0,1,2},
					{0,1,2},
					{0,1,2},
					 {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19},
					 {2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19},
					 {3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19},
				{0,0}, //14 end flag
			};



		for (int columnCNT = 0; columnCNT < COLUMN; columnCNT++) {
//			for (int rowCNT = 0; rowCNT <sizeof(letter_Y[columnCNT])/sizeof(letter_Y[columnCNT][rowCNT]) ; rowCNT++) {

			if(letter_J[columnCNT][0]+letter_J[columnCNT][1]==0){//two elements in the same column can't be 0
				break;
			}
			for (int rowCNT = 0; rowCNT <ROW ; rowCNT++) {

				if (letter_J[columnCNT][rowCNT] == 0 && rowCNT > 0) {
				break;
			}
				//letter_Z[COLUMN][ROW]
				// row 0 --> column 0
					//blue
					Buffer_Image[(y* horizontal_mulitplyer)+ ((letter_J[columnCNT][rowCNT]+x) * 3)] = RGB.b;
					//green
					Buffer_Image[(y* horizontal_mulitplyer)+ ((letter_J[columnCNT][rowCNT]+x) * 3) + 1] = RGB.g;
					//red
					Buffer_Image[(y* horizontal_mulitplyer)+ ((letter_J[columnCNT][rowCNT]+x) * 3) + 2] = RGB.r;
				}
			x = StartPosX;
			y++;
		}


		Xil_DCacheFlush();


}

void DrawLetterK_New(int StartPosX,int StartPosY,int LineColour, unsigned char *Buffer_Image){

	int y = StartPosY;
	int x = StartPosX;

	int horizontal_mulitplyer = Horizontal_Size * 3;
	// set colour of number
	COLOUR RGB;
	RGB = setcolor(LineColour);


		int COLUMN=20, ROW=20;
			const u8 letter_K[20][20]=
			{
					{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19},
					{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19},
					{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19},
					{7,8,9,10,11,12},
					{7,8,9,10,11,12},
					{6,7,8,9,10,11,12,13},
					{5,6,7,8,11,12,13,14},
					{4,5,6,7,12,13,14,15},
					{3,4,5,6,13,14,15,16},
					{2,3,4,5,14,15,16,17},
					{1,2,3,4,15,16,17,18},
					{0,1,2,3,16,17,18,19},
					{0,1,2,17,18,19},
					{0,1,18,19},
				{0,0}, //14 end flag
			};



		for (int columnCNT = 0; columnCNT < COLUMN; columnCNT++) {
//			for (int rowCNT = 0; rowCNT <sizeof(letter_Y[columnCNT])/sizeof(letter_Y[columnCNT][rowCNT]) ; rowCNT++) {

			if(letter_K[columnCNT][0]+letter_K[columnCNT][1]==0){//two elements in the same column can't be 0
				break;
			}
			for (int rowCNT = 0; rowCNT <ROW ; rowCNT++) {

				if (letter_K[columnCNT][rowCNT] == 0 && rowCNT > 0) {
				break;
			}
				//letter_Z[COLUMN][ROW]
				// row 0 --> column 0
					//blue
					Buffer_Image[(y* horizontal_mulitplyer)+ ((letter_K[columnCNT][rowCNT]+x) * 3)] = RGB.b;
					//green
					Buffer_Image[(y* horizontal_mulitplyer)+ ((letter_K[columnCNT][rowCNT]+x) * 3) + 1] = RGB.g;
					//red
					Buffer_Image[(y* horizontal_mulitplyer)+ ((letter_K[columnCNT][rowCNT]+x) * 3) + 2] = RGB.r;
				}
			x = StartPosX;
			y++;
		}


		Xil_DCacheFlush();


}

void DrawLetterL_New(int StartPosX,int StartPosY,int LineColour, unsigned char *Buffer_Image){

	int y = StartPosY;
	int x = StartPosX;

	int horizontal_mulitplyer = Horizontal_Size * 3;
	// set colour of number
	COLOUR RGB;
	RGB = setcolor(LineColour);


		int COLUMN=20, ROW=20;
			const u8 letter_L[20][20]=
			{
					{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19},
					{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19},
					{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19},
					{0,1,2},
					{0,1,2},
					{0,1,2},
					{0,1,2},
					{0,1,2},
					{0,1,2},
					{0,1,2},
					{0,1,2},
					{0,1,2},
					{0,1,2},
					{0,1,2},

				{0,0}, //14 end flag
			};



		for (int columnCNT = 0; columnCNT < COLUMN; columnCNT++) {
//			for (int rowCNT = 0; rowCNT <sizeof(letter_Y[columnCNT])/sizeof(letter_Y[columnCNT][rowCNT]) ; rowCNT++) {

			if(letter_L[columnCNT][0]+letter_L[columnCNT][1]==0){//two elements in the same column can't be 0
				break;
			}
			for (int rowCNT = 0; rowCNT <ROW ; rowCNT++) {

				if (letter_L[columnCNT][rowCNT] == 0 && rowCNT > 0) {
				break;
			}
				//letter_Z[COLUMN][ROW]
				// row 0 --> column 0
					//blue
					Buffer_Image[(y* horizontal_mulitplyer)+ ((letter_L[columnCNT][rowCNT]+x) * 3)] = RGB.b;
					//green
					Buffer_Image[(y* horizontal_mulitplyer)+ ((letter_L[columnCNT][rowCNT]+x) * 3) + 1] = RGB.g;
					//red
					Buffer_Image[(y* horizontal_mulitplyer)+ ((letter_L[columnCNT][rowCNT]+x) * 3) + 2] = RGB.r;
				}
			x = StartPosX;
			y++;
		}


		Xil_DCacheFlush();


}

void DrawLetterM_New(int StartPosX,int StartPosY,int LineColour, unsigned char *Buffer_Image){

	int y = StartPosY;
	int x = StartPosX;

	int horizontal_mulitplyer = Horizontal_Size * 3;
	// set colour of number
	COLOUR RGB;
	RGB = setcolor(LineColour);


		int COLUMN=20, ROW=20;
			const u8 letter_M[20][20]=
			{
					{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19},
					{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19},
					{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19},
					{13,14,15,16,17,18},
					{12,13,14,15,16},
					{11,12,13,14,15},
					{10,11,12,13},
				    {10,11,12,13},
					{11,12,13,14,15},
					{12,13,14,15,16},
					{13,14,15,16,17,18},
					{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19},
					{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19},
					{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19},
				{0,0}, //14 end flag
			};



		for (int columnCNT = 0; columnCNT < COLUMN; columnCNT++) {
//			for (int rowCNT = 0; rowCNT <sizeof(letter_Y[columnCNT])/sizeof(letter_Y[columnCNT][rowCNT]) ; rowCNT++) {

			if(letter_M[columnCNT][0]+letter_M[columnCNT][1]==0){//two elements in the same column can't be 0
				break;
			}
			for (int rowCNT = 0; rowCNT <ROW ; rowCNT++) {

				if (letter_M[columnCNT][rowCNT] == 0 && rowCNT > 0) {
				break;
			}
				//letter_Z[COLUMN][ROW]
				// row 0 --> column 0
					//blue
					Buffer_Image[(y* horizontal_mulitplyer)+ ((letter_M[columnCNT][rowCNT]+x) * 3)] = RGB.b;
					//green
					Buffer_Image[(y* horizontal_mulitplyer)+ ((letter_M[columnCNT][rowCNT]+x) * 3) + 1] = RGB.g;
					//red
					Buffer_Image[(y* horizontal_mulitplyer)+ ((letter_M[columnCNT][rowCNT]+x) * 3) + 2] = RGB.r;
				}
			x = StartPosX;
			y++;
		}


		Xil_DCacheFlush();


}


void DrawLetterN_New(int StartPosX,int StartPosY,int LineColour, unsigned char *Buffer_Image){

	int y = StartPosY;
	int x = StartPosX;

	int horizontal_mulitplyer = Horizontal_Size * 3;
	// set colour of number
	COLOUR RGB;
	RGB = setcolor(LineColour);


		int COLUMN=20, ROW=20;
			const u8 letter_N[20][20]=
			{
					{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19},
					{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19},
					{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19},
					{10,11,12,13,14,15,16},
					{9,10,11,12,13,14,15},
					{8,9,10,11,12,13,14},
					{7,8,9,10,11,12,13},
					{6,7,8,9,10,11,12},
					{5,6,7,8,9,10,11},
					{4,5,6,7,8,9,10},
					{3,4,5,6,7,8,9},
					{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19},
					{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19},
					{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19},

				{0,0}, //14 end flag
			};



		for (int columnCNT = 0; columnCNT < COLUMN; columnCNT++) {
//			for (int rowCNT = 0; rowCNT <sizeof(letter_Y[columnCNT])/sizeof(letter_Y[columnCNT][rowCNT]) ; rowCNT++) {

			if(letter_N[columnCNT][0]+letter_N[columnCNT][1]==0){//two elements in the same column can't be 0
				break;
			}
			for (int rowCNT = 0; rowCNT <ROW ; rowCNT++) {

				if (letter_N[columnCNT][rowCNT] == 0 && rowCNT > 0) {
				break;
			}
				//letter_Z[COLUMN][ROW]
				// row 0 --> column 0
					//blue
					Buffer_Image[(y* horizontal_mulitplyer)+ ((letter_N[columnCNT][rowCNT]+x) * 3)] = RGB.b;
					//green
					Buffer_Image[(y* horizontal_mulitplyer)+ ((letter_N[columnCNT][rowCNT]+x) * 3) + 1] = RGB.g;
					//red
					Buffer_Image[(y* horizontal_mulitplyer)+ ((letter_N[columnCNT][rowCNT]+x) * 3) + 2] = RGB.r;
				}
			x = StartPosX;
			y++;
		}


		Xil_DCacheFlush();


}


void DrawLetterO_New(int StartPosX,int StartPosY,int LineColour, unsigned char *Buffer_Image){

	int y = StartPosY;
	int x = StartPosX;

	int horizontal_mulitplyer = Horizontal_Size * 3;
	// set colour of number
	COLOUR RGB;
	RGB = setcolor(LineColour);


		int COLUMN=20, ROW=20;
			const u8 letter_O[20][20]=
			{
					{2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17},
					{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18},
					{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19},
					{0,1,2,316,17,18,19},
					{0,1,2,17,18,19},
					{0,1,18,19},
					{0,1,18,19},
					{0,1,18,19},
					{0,1,18,19},
					{0,1,2,17,18,19},
					{0,1,2,3,16,17,18,19},
					{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19},
					{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18},
					{2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17},
				{0,0}, //14 end flag
			};



		for (int columnCNT = 0; columnCNT < COLUMN; columnCNT++) {
//			for (int rowCNT = 0; rowCNT <sizeof(letter_Y[columnCNT])/sizeof(letter_Y[columnCNT][rowCNT]) ; rowCNT++) {

			if(letter_O[columnCNT][0]+letter_O[columnCNT][1]==0){//two elements in the same column can't be 0
				break;
			}
			for (int rowCNT = 0; rowCNT <ROW ; rowCNT++) {

				if (letter_O[columnCNT][rowCNT] == 0 && rowCNT > 0) {
				break;
			}
				//letter_Z[COLUMN][ROW]
				// row 0 --> column 0
					//blue
					Buffer_Image[(y* horizontal_mulitplyer)+ ((letter_O[columnCNT][rowCNT]+x) * 3)] = RGB.b;
					//green
					Buffer_Image[(y* horizontal_mulitplyer)+ ((letter_O[columnCNT][rowCNT]+x) * 3) + 1] = RGB.g;
					//red
					Buffer_Image[(y* horizontal_mulitplyer)+ ((letter_O[columnCNT][rowCNT]+x) * 3) + 2] = RGB.r;
				}
			x = StartPosX;
			y++;
		}


		Xil_DCacheFlush();


}

void DrawLetterP_New(int StartPosX,int StartPosY,int LineColour, unsigned char *Buffer_Image){

	int y = StartPosY;
	int x = StartPosX;

	int horizontal_mulitplyer = Horizontal_Size * 3;
	// set colour of number
	COLOUR RGB;
	RGB = setcolor(LineColour);


		int COLUMN=20, ROW=20;
			const u8 letter_P[20][20]=
			{
					{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19},
					{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19},
					{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19},
					{8,9,10,17,18,19},
					{8,9,10,17,18,19},
					{8,9,10,17,18,19},
					{8,9,10,17,18,19},
					{8,9,10,17,18,19},
					{8,9,10,17,18,19},
					{8,9,10,17,18,19},
					{8,9,10,17,18,19},
					{8,9,10,11,12,13,14,15,16,17,18,19},
					{9,10,11,12,13,14,15,16,17,18},
					{10,11,12,13,14,15,16,17},


				{0,0}, //14 end flag
			};



		for (int columnCNT = 0; columnCNT < COLUMN; columnCNT++) {
//			for (int rowCNT = 0; rowCNT <sizeof(letter_Y[columnCNT])/sizeof(letter_Y[columnCNT][rowCNT]) ; rowCNT++) {

			if(letter_P[columnCNT][0]+letter_P[columnCNT][1]==0){//two elements in the same column can't be 0
				break;
			}
			for (int rowCNT = 0; rowCNT <ROW ; rowCNT++) {

				if (letter_P[columnCNT][rowCNT] == 0 && rowCNT > 0) {
				break;
			}
				//letter_Z[COLUMN][ROW]
				// row 0 --> column 0
					//blue
					Buffer_Image[(y* horizontal_mulitplyer)+ ((letter_P[columnCNT][rowCNT]+x) * 3)] = RGB.b;
					//green
					Buffer_Image[(y* horizontal_mulitplyer)+ ((letter_P[columnCNT][rowCNT]+x) * 3) + 1] = RGB.g;
					//red
					Buffer_Image[(y* horizontal_mulitplyer)+ ((letter_P[columnCNT][rowCNT]+x+1) * 3) + 2] = RGB.r;

			}
			x = StartPosX;
			y++;
		}


		Xil_DCacheFlush();


}


void DrawLetterQ_New(int StartPosX,int StartPosY,int LineColour, unsigned char *Buffer_Image){

	int y = StartPosY;
	int x = StartPosX;

	int horizontal_mulitplyer = Horizontal_Size * 3;
	// set colour of number
	COLOUR RGB;
	RGB = setcolor(LineColour);


		int COLUMN=20, ROW=20;
			const u8 letter_Q[20][20]=
			{
					{2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17},
					{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18},
					{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19},
					{0,1,18,19},
					{0,1,18,19},
					{0,1,18,19},
					{0,1,18,19},
					{0,1,8,9,18,19},
					{0,1,7,8,9,18,19},
					{0,1, 6,7,8,18,19},
					{0,1,5,6,7,18,19},
					{0,1,2,4,5,6,8,9,10,11,12,13,14,15,16,17,18,19},
					{1,3,4,5,7,8,9,10,11,12,13,14,15,16,17,18},
					{2,3,4,6,7,8,9,10,11,12,13,14,15,16,17},
					{1,2,3},
					{0,1,2},
					{0,1},

				{0,0}, //14 end flag
			};



		for (int columnCNT = 0; columnCNT < COLUMN; columnCNT++) {
//			for (int rowCNT = 0; rowCNT <sizeof(letter_Y[columnCNT])/sizeof(letter_Y[columnCNT][rowCNT]) ; rowCNT++) {

			if(letter_Q[columnCNT][0]+letter_Q[columnCNT][1]==0){//two elements in the same column can't be 0
				break;
			}
			for (int rowCNT = 0; rowCNT <ROW ; rowCNT++) {

				if (letter_Q[columnCNT][rowCNT] == 0 && rowCNT > 0) {
				break;
			}
				//letter_Z[COLUMN][ROW]
				// row 0 --> column 0
					//blue
					Buffer_Image[(y* horizontal_mulitplyer)+ ((letter_Q[columnCNT][rowCNT]+x) * 3)] = RGB.b;
					//green
					Buffer_Image[(y* horizontal_mulitplyer)+ ((letter_Q[columnCNT][rowCNT]+x) * 3) + 1] = RGB.g;
					//red
					Buffer_Image[(y* horizontal_mulitplyer)+ ((letter_Q[columnCNT][rowCNT]+x) * 3) + 2] = RGB.r;
				}
			x = StartPosX;
			y++;
		}


		Xil_DCacheFlush();


}

void DrawLetterR_New(int StartPosX,int StartPosY,int LineColour, unsigned char *Buffer_Image){

	int y = StartPosY;
	int x = StartPosX;

	int horizontal_mulitplyer = Horizontal_Size * 3;
	// set colour of number
	COLOUR RGB;
	RGB = setcolor(LineColour);


		int COLUMN=20, ROW=20;
			const u8 letter_R[20][20]=
			{
					{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19},
					{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19},
					{7,8,9,10,18,19},
					{6,7,8,9,10,18,19},
					{5,6,7,9,10,18,19},
					{4,5,6,9,10,18,19},
					{3,4,5,9,10,18,19},
					{2,3,4,9,10,18,19},
					{1,2,3,9,10,18,19},
					{0,1,2,9,10,18,19},
					{0,1,9,10,18,19},
					{10,11,12,13,14,15,16,17,18},
					{11,12,13,14,15,16,17},


				{0,0}, //14 end flag
			};



		for (int columnCNT = 0; columnCNT < COLUMN; columnCNT++) {
//			for (int rowCNT = 0; rowCNT <sizeof(letter_Y[columnCNT])/sizeof(letter_Y[columnCNT][rowCNT]) ; rowCNT++) {

			if(letter_R[columnCNT][0]+letter_R[columnCNT][1]==0){//two elements in the same column can't be 0
				break;
			}
			for (int rowCNT = 0; rowCNT <ROW ; rowCNT++) {

				if (letter_R[columnCNT][rowCNT] == 0 && rowCNT > 0) {
				break;
			}
				//letter_Z[COLUMN][ROW]
				// row 0 --> column 0
					//blue
					Buffer_Image[(y* horizontal_mulitplyer)+ ((letter_R[columnCNT][rowCNT]+x) * 3)] = RGB.b;
					//green
					Buffer_Image[(y* horizontal_mulitplyer)+ ((letter_R[columnCNT][rowCNT]+x) * 3) + 1] = RGB.g;
					//red
					Buffer_Image[(y* horizontal_mulitplyer)+ ((letter_R[columnCNT][rowCNT]+x) * 3) + 2] = RGB.r;
				}
			x = StartPosX;
			y++;
		}


		Xil_DCacheFlush();


}


void DrawLetterS_New(int StartPosX,int StartPosY,int LineColour, unsigned char *Buffer_Image){

	int y = StartPosY;
	int x = StartPosX;

	int horizontal_mulitplyer = Horizontal_Size * 3;
	// set colour of number
	COLOUR RGB;
	RGB = setcolor(LineColour);


		int COLUMN=20, ROW=20;
			const u8 letter_S[20][20]=
			{
					{2,3,11,12,13,14,15,16},
					{1,2,3,10,11,12,13,14,15,16,1},
					{0,1,2,9,10,11,12,13,16,17,18},
					{0,1,9,10,11,12,17,18,19},
					{0,1,9,10,11,18,19},
					{0,1,9,10,11,18,19},
					{0,1,9,10,11,18,19},
					{0,1,9,10,11,18,19},
					{0,1,9,10,11,18,19},
					{0,1,9,10,11,18,19},
					{0,1,2,8,9,10,11,18,19},
					{0,1,2,3,7,8,9,10,17,18,19},
				    {1,2,3,4,5,6,7,8,9,16,17,18},
					{2,3,4,5,6,7,8,16,17},

				{0,0}, //14 end flag
			};



		for (int columnCNT = 0; columnCNT < COLUMN; columnCNT++) {
//			for (int rowCNT = 0; rowCNT <sizeof(letter_Y[columnCNT])/sizeof(letter_Y[columnCNT][rowCNT]) ; rowCNT++) {

			if(letter_S[columnCNT][0]+letter_S[columnCNT][1]==0){//two elements in the same column can't be 0
				break;
			}
			for (int rowCNT = 0; rowCNT <ROW ; rowCNT++) {

				if (letter_S[columnCNT][rowCNT] == 0 && rowCNT > 0) {
				break;
			}
				//letter_Z[COLUMN][ROW]
				// row 0 --> column 0
					//blue
					Buffer_Image[(y* horizontal_mulitplyer)+ ((letter_S[columnCNT][rowCNT]+x) * 3)] = RGB.b;
					//green
					Buffer_Image[(y* horizontal_mulitplyer)+ ((letter_S[columnCNT][rowCNT]+x) * 3) + 1] = RGB.g;
					//red
					Buffer_Image[(y* horizontal_mulitplyer)+ ((letter_S[columnCNT][rowCNT]+x) * 3) + 2] = RGB.r;
				}
			x = StartPosX;
			y++;
		}


		Xil_DCacheFlush();


}


void DrawLetterT_New(int StartPosX,int StartPosY,int LineColour, unsigned char *Buffer_Image){

	int y = StartPosY;
	int x = StartPosX;

	int horizontal_mulitplyer = Horizontal_Size * 3;
	// set colour of number
	COLOUR RGB;
	RGB = setcolor(LineColour);


		int COLUMN=20, ROW=20;

			const u8 letter_T[20][20]=
			{
															 {17,18,19},
					 	 	 	 	 	 	 	 	 	 	 {17,18,19},
					 	 	 	 	 	 	 	 	 	 	 {17,18,19},
					 	 	 	 	 	 	 	 	 	 	 {17,18,19},
								 	 	 	 	 	 	 	 {17,18,19},
					 	 	 	 	 	 	 	 	 	 	 {17,18,19},
					{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19},
					{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19},
					{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19},
					{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19},
															 {17,18,19},
															 {17,18,19},
															 {17,18,19},
					 	 	 	 	 	 	 	 	 	 	 {17,18,19},
															 {17,18,19},
															 {17,18,19},
															 {0,0}, //end flag
			};



		for (int columnCNT = 0; columnCNT < COLUMN; columnCNT++) {
			if(letter_T[columnCNT][0]+letter_T[columnCNT][1]==0){//two elements in the same column can't be 0
				break;
			}
			for (int rowCNT = 0; rowCNT <sizeof(letter_T[columnCNT])/sizeof(letter_T[columnCNT][rowCNT]) ; rowCNT++) {
				if (letter_T[columnCNT][rowCNT] == 0 && rowCNT > 0) {// pixel 0 can be found only in ROW element 0
				break;
			}
				//letter_Z[COLUMN][ROW]
				// row 0 --> column 0
					//blue
					Buffer_Image[(y* horizontal_mulitplyer)+ ((letter_T[columnCNT][rowCNT]+x) * 3)] = RGB.b;
					//green
					Buffer_Image[(y* horizontal_mulitplyer)+ ((letter_T[columnCNT][rowCNT]+x) * 3) + 1] = RGB.g;
					//red
					Buffer_Image[(y* horizontal_mulitplyer)+ ((letter_T[columnCNT][rowCNT]+x) * 3) + 2] = RGB.r;
				}
			x = StartPosX;
			y++;
		}
		Xil_DCacheFlush();
}


void DrawLetterU_New(int StartPosX,int StartPosY,int LineColour, unsigned char *Buffer_Image){

	int y = StartPosY;
	int x = StartPosX;

	int horizontal_mulitplyer = Horizontal_Size * 3;
	// set colour of number
	COLOUR RGB;
	RGB = setcolor(LineColour);


		int COLUMN=20, ROW=20;
			const u8 letter_U[20][20]=
			{
					 {2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19},
					 {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19},
					{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19},
					{0,1,2},
					{0,1,2},
					{0,1,2},
					{0,1,2},
					{0,1,2},
					{0,1,2},
					{0,1,2},
					{0,1,2},
					{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19},
					 {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19},
					 {2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19},

				{0,0}, //14 end flag
			};



		for (int columnCNT = 0; columnCNT < COLUMN; columnCNT++) {
//			for (int rowCNT = 0; rowCNT <sizeof(letter_Y[columnCNT])/sizeof(letter_Y[columnCNT][rowCNT]) ; rowCNT++) {

			if(letter_U[columnCNT][0]+letter_U[columnCNT][1]==0){//two row elements in the same column can't be 0
				break;
			}
			for (int rowCNT = 0; rowCNT <ROW ; rowCNT++) {

				if (letter_U[columnCNT][rowCNT] == 0 && rowCNT > 0) {
				break;
			}
				//letter_Z[COLUMN][ROW]
				// row 0 --> column 0
					//blue
					Buffer_Image[(y* horizontal_mulitplyer)+ ((letter_U[columnCNT][rowCNT]+x) * 3)] = RGB.b;
					//green
					Buffer_Image[(y* horizontal_mulitplyer)+ ((letter_U[columnCNT][rowCNT]+x) * 3) + 1] = RGB.g;
					//red
					Buffer_Image[(y* horizontal_mulitplyer)+ ((letter_U[columnCNT][rowCNT]+x) * 3) + 2] = RGB.r;
				}
			x = StartPosX;
			y++;
		}


		Xil_DCacheFlush();


}

void DrawLetterV_New(int StartPosX,int StartPosY,int LineColour, unsigned char *Buffer_Image){

	int y = StartPosY;
	int x = StartPosX;

	int horizontal_mulitplyer = Horizontal_Size * 3;
	// set colour of number
	COLOUR RGB;
	RGB = setcolor(LineColour);


		int COLUMN=20, ROW=20;
			const u8 letter_V[20][20]=
			{
					 {7,8,9,10,11,12,13,14,15,16,17,18,19},
					 {6,7,8,9,10,11,12,13,14,15,16,17,18,19},
					 {5,6,7},
					 {4,5,6},
					 {3,4,5},
					 {2,3,4},
					{0,1,2,3},
					{0,1,2,3},
					 {2,3,4},
					 {3,4,5},
					 {4,5,6},
					 {5,6,7},
					 {6,7,8,9,10,11,12,13,14,15,16,17,18,19},
					 {7,8,9,10,11,12,13,14,15,16,17,18,19},
				{0,0}, //14 end flag
			};



		for (int columnCNT = 0; columnCNT < COLUMN; columnCNT++) {
			if(letter_V[columnCNT][0]+letter_V[columnCNT][1]==0){//two row elements in the same column can't be 0
				break;
			}
			for (int rowCNT = 0; rowCNT <sizeof(letter_V[columnCNT])/sizeof(letter_V[columnCNT][rowCNT]) ; rowCNT++) {
				if (letter_V[columnCNT][rowCNT] == 0 && rowCNT > 0) { // pixel 0 can be found only in ROW element 0
				break;
			}
				//letter_V[COLUMN][ROW]
				// row 0 --> column 0
					//blue
					Buffer_Image[(y* horizontal_mulitplyer)+ ((letter_V[columnCNT][rowCNT]+x) * 3)] = RGB.b;
					//green
					Buffer_Image[(y* horizontal_mulitplyer)+ ((letter_V[columnCNT][rowCNT]+x) * 3) + 1] = RGB.g;
					//red
					Buffer_Image[(y* horizontal_mulitplyer)+ ((letter_V[columnCNT][rowCNT]+x) * 3) + 2] = RGB.r;
				}
			x = StartPosX;
			y++;
		}


		Xil_DCacheFlush();


}

void DrawLetterW_New(int StartPosX,int StartPosY,int LineColour, unsigned char *Buffer_Image){

	int y = StartPosY;
	int x = StartPosX;

	int horizontal_mulitplyer = Horizontal_Size * 3;
	// set colour of number
	COLOUR RGB;
	RGB = setcolor(LineColour);


		int COLUMN=20, ROW=20;
			const u8 letter_W[20][20]=
			{
					 {8,9,10,11,12,13,14,15,16,17,18,19},
					 {5,6,7,8,9,10,11,12,13,14,15,16,17,18,19},
					 {5,6,7},
					 {2,3,4},
					{0,1,2,3,4},
					{0,1,2,3,4},
					 {2,3,4},
					 {5,6,7},
					 {5,6,7},
					 {8,9,10,11,12,13},
					 {8,9,10,11,12,13},
					 {5,6,7},
					 {5,6,7},
					 {2,3,4},
					{0,1,2,3,4},
					{0,1,2,3,4},
					 {2,3,4},
					 {5,6,7},
					 {5,6,7,8,9,10,11,12,13,14,15,16,17,18,19},
					 {8,9,10,11,12,13,14,15,16,17,18,19},

				{0,0}, //14 end flag
			};



		for (int columnCNT = 0; columnCNT < COLUMN; columnCNT++) {
//			for (int rowCNT = 0; rowCNT <sizeof(letter_Y[columnCNT])/sizeof(letter_Y[columnCNT][rowCNT]) ; rowCNT++) {

			if(letter_W[columnCNT][0]+letter_W[columnCNT][1]==0){//two row elements in the same column can't be 0
				break;
			}
			for (int rowCNT = 0; rowCNT <ROW ; rowCNT++) {

				if (letter_W[columnCNT][rowCNT] == 0 && rowCNT > 0) {
				break;
			}
				//letter_Z[COLUMN][ROW]
				// row 0 --> column 0
					//blue
					Buffer_Image[(y* horizontal_mulitplyer)+ ((letter_W[columnCNT][rowCNT]+x) * 3)] = RGB.b;
					//green
					Buffer_Image[(y* horizontal_mulitplyer)+ ((letter_W[columnCNT][rowCNT]+x) * 3) + 1] = RGB.g;
					//red
					Buffer_Image[(y* horizontal_mulitplyer)+ ((letter_W[columnCNT][rowCNT]+x) * 3) + 2] = RGB.r;
				}
			x = StartPosX;
			y++;
		}


		Xil_DCacheFlush();


}

void DrawLetterX_New(int StartPosX,int StartPosY,int LineColour, unsigned char *Buffer_Image){

	int y = StartPosY;
	int x = StartPosX;

	int horizontal_mulitplyer = Horizontal_Size * 3;
	// set colour of number
	COLOUR RGB;
	RGB = setcolor(LineColour);


		int COLUMN=20, ROW=20;
			const u8 letter_X[20][20]=
			{
					{0,1,2,17,18,19},
					{0,1,2,3,16,17,18,19},
					 {2,3,4,15,16,17},
					 {3,4,5,14,15,16},
					 {4,5,6,13,14,15},
					 {5,6,7,12,13,14},
					 {6,7,8,11,12,13},
					 {7,8,9,10,11,12},
					 {8,9,10,11},
					 {8,9,10,11},
					 {7,8,9,10,11,12},
					 {6,7,8,11,12,13},
					 {5,6,7,12,13,14},
					 {4,5,6,13,14,15},
					 {3,4,5,14,15,16},
					 {2,3,4,15,16,17},
					{0,1,2,3,16,17,18,19},
					{0,1,2,17,18,19},
				{0,0}, //14 end flag
			};



		for (int columnCNT = 0; columnCNT < COLUMN; columnCNT++) {
//			for (int rowCNT = 0; rowCNT <sizeof(letter_Y[columnCNT])/sizeof(letter_Y[columnCNT][rowCNT]) ; rowCNT++) {

			if(letter_X[columnCNT][0]+letter_X[columnCNT][1]==0){//two row elements in the same column can't be 0
				break;
			}
			for (int rowCNT = 0; rowCNT <ROW ; rowCNT++) {

				if (letter_X[columnCNT][rowCNT] == 0 && rowCNT > 0) {
				break;
			}
				//letter_Z[COLUMN][ROW]
				// row 0 --> column 0
					//blue
					Buffer_Image[(y* horizontal_mulitplyer)+ ((letter_X[columnCNT][rowCNT]+x) * 3)] = RGB.b;
					//green
					Buffer_Image[(y* horizontal_mulitplyer)+ ((letter_X[columnCNT][rowCNT]+x) * 3) + 1] = RGB.g;
					//red
					Buffer_Image[(y* horizontal_mulitplyer)+ ((letter_X[columnCNT][rowCNT]+x) * 3) + 2] = RGB.r;
				}
			x = StartPosX;
			y++;
		}


		Xil_DCacheFlush();


}


void DrawLetterY_New(int StartPosX,int StartPosY,int LineColour, unsigned char *Buffer_Image){

	int y = StartPosY;
	int x = StartPosX;

	int horizontal_mulitplyer = Horizontal_Size * 3;
	// set colour of number
	COLOUR RGB;
	RGB = setcolor(LineColour);


		int COLUMN=20, ROW=20;
			const u8 letter_Y[20][20]=
			{
				{16,17,18,19},
				{15,16,17,18,19},
				{14,15,16},
				{13,14,15},
				{12,13,14},
				{11,12,13},
				{0,1,2,3,4,5,6,7,8,9,10,11,12},
				{0,1,2,3,4,5,6,7,8,9,10,11,12},
				{11,12,13},
			    {12,13,14},
			    {13,14,15},
			    {14,15,16},
				{15,16,17,18,19},
				{16,17,18,19},
				{0,0}, //14 end flag
			};



		for (int columnCNT = 0; columnCNT < COLUMN; columnCNT++) {
//			for (int rowCNT = 0; rowCNT <sizeof(letter_Y[columnCNT])/sizeof(letter_Y[columnCNT][rowCNT]) ; rowCNT++) {

			if(letter_Y[columnCNT][0]+letter_Y[columnCNT][1]==0){//two row elements in the same column can't be 0
				break;
			}
			for (int rowCNT = 0; rowCNT <ROW ; rowCNT++) {
				//letter_Z[COLUMN][ROW]
				// row 0 --> column 0
					//blue

				if (letter_Y[columnCNT][rowCNT] == 0 && rowCNT > 0) {
				break;
			}
					Buffer_Image[(y* horizontal_mulitplyer)+ ((letter_Y[columnCNT][rowCNT]+x) * 3)] = RGB.b;
					//green
					Buffer_Image[(y* horizontal_mulitplyer)+ ((letter_Y[columnCNT][rowCNT]+x) * 3) + 1] = RGB.g;
					//red
					Buffer_Image[(y* horizontal_mulitplyer)+ ((letter_Y[columnCNT][rowCNT]+x) * 3) + 2] = RGB.r;
				}
			x = StartPosX;
			y++;
		}


		Xil_DCacheFlush();


}

void DrawLetterZ_New(int StartPosX,int StartPosY,int LineColour, unsigned char *Buffer_Image){
	int y = StartPosY;
	int x = StartPosX;

	int horizontal_mulitplyer = Horizontal_Size * 3;
	// set colour of number
	COLOUR RGB;
	RGB = setcolor(LineColour);


	int COLUMN=20, ROW=20;
		const u8 letter_Z[20][20]=
		{
			{0,1,2,3,4,5,17,18,19},
			{0,1,2,3,4,5,6,17,18,19},
			{0,1,2,3,4,5,6,7,17,18,19},
			{0,1,2,4,5,6,7,8,17,18,19},
			{0,1,2,5,6,7,8,9,17,18,19},
			{0,1,2,6,7,8,9,10,17,18,19},
			{0,1,2,7,8,9,10,11,17,18,19},
			{0,1,2,8,9,10,11,12,17,18,19},
			{0,1,2,9,10,11,12,13,17,18,19},
			{0,1,2,10,11,12,13,14,17,18,19}, //9
			{0,1,2,11,12,13,14,15,17,18,19},
			{0,1,2,12,13,14,15,16,17,18,19}, //11
			{0,1,2,13,14,15,16,16,17,18,19}, //12
			{0,1,2,14,15,16,16,17,18,19}, //13
			{0,0}, //14 flag
		};


	for (int columnCNT = 0; columnCNT < COLUMN; columnCNT++) {

		if(letter_Z[columnCNT][0]+letter_Z[columnCNT][1]==0){ //two row elements in the same column can't be 0
			break;
		}

		for (int rowCNT = 0; rowCNT <sizeof(letter_Z[columnCNT])/sizeof(letter_Z[columnCNT][rowCNT]) ; rowCNT++) {
			//letter_Z[COLUMN][ROW]
			// row 0 --> column 0

			if (letter_Z[columnCNT][rowCNT] == 0 && rowCNT > 0) {
				break;
			}
				//blue
				Buffer_Image[(y* horizontal_mulitplyer)+ ((letter_Z[columnCNT][rowCNT]+x) * 3)] = RGB.b;
				//green
				Buffer_Image[(y* horizontal_mulitplyer)+ ((letter_Z[columnCNT][rowCNT]+x) * 3) + 1] = RGB.g;
				//red
				Buffer_Image[(y* horizontal_mulitplyer)+ ((letter_Z[columnCNT][rowCNT]+x) * 3) + 2] = RGB.r;
//				x++;
			}
		x = StartPosX;
//		y = StartPosY;
		y++;
		}
	Xil_DCacheFlush();

	}


void DrawLetterFullStop_New(int StartPosX,int StartPosY,int LineColour, unsigned char *Buffer_Image){

	int y = StartPosY;
	int x = StartPosX;

	int horizontal_mulitplyer = Horizontal_Size * 3;
	// set colour of number
	COLOUR RGB;
	RGB = setcolor(LineColour);


		int COLUMN=20, ROW=20;
			const u8 letter_FS[20][20]=
			{
					{0,1,2},
					{0,1,2},
					{0,1,2},

				{0,0}, //14 end flag
			};



		for (int columnCNT = 0; columnCNT < COLUMN; columnCNT++) {
//			for (int rowCNT = 0; rowCNT <sizeof(letter_Y[columnCNT])/sizeof(letter_Y[columnCNT][rowCNT]) ; rowCNT++) {

			if(letter_FS[columnCNT][0]+letter_FS[columnCNT][1]==0){//two row elements in the same column can't be 0
				break;
			}
			for (int rowCNT = 0; rowCNT <ROW ; rowCNT++) {
				//letter_Z[COLUMN][ROW]
				// row 0 --> column 0
			if (letter_FS[columnCNT][rowCNT] == 0 && rowCNT > 0) {
				break;
			}

				//blue
					Buffer_Image[(y* horizontal_mulitplyer)+ ((letter_FS[columnCNT][rowCNT]+x) * 3)] = RGB.b;
					//green
					Buffer_Image[(y* horizontal_mulitplyer)+ ((letter_FS[columnCNT][rowCNT]+x) * 3) + 1] = RGB.g;
					//red
					Buffer_Image[(y* horizontal_mulitplyer)+ ((letter_FS[columnCNT][rowCNT]+x) * 3) + 2] = RGB.r;
				}
			x = StartPosX;
			y++;
		}


		Xil_DCacheFlush();


}

void DrawLetterColon_New(int StartPosX,int StartPosY,int LineColour, unsigned char *Buffer_Image){

	int y = StartPosY;
	int x = StartPosX;

	int horizontal_mulitplyer = Horizontal_Size * 3;
	// set colour of number
	COLOUR RGB;
	RGB = setcolor(LineColour);


		int COLUMN=20, ROW=20;
			const u8 letter_COLON[20][20]=
			{
					{6,7,8,12,13,14},
					{6,7,8,12,13,14},
					{6,7,8,12,13,14},
				{0,0}, //14 end flag
			};



		for (int columnCNT = 0; columnCNT < COLUMN; columnCNT++) {
//			for (int rowCNT = 0; rowCNT <sizeof(letter_Y[columnCNT])/sizeof(letter_Y[columnCNT][rowCNT]) ; rowCNT++) {

			if(letter_COLON[columnCNT][0]+letter_COLON[columnCNT][1]==0){//two row elements in the same column can't be 0
				break;
			}
			for (int rowCNT = 0; rowCNT <ROW ; rowCNT++) {
				//letter_Z[COLUMN][ROW]
				// row 0 --> column 0
			if (letter_COLON[columnCNT][rowCNT] == 0 && rowCNT > 0) {
				break;
			}
				//blue
					Buffer_Image[(y* horizontal_mulitplyer)+ ((letter_COLON[columnCNT][rowCNT]+x) * 3)] = RGB.b;
					//green
					Buffer_Image[(y* horizontal_mulitplyer)+ ((letter_COLON[columnCNT][rowCNT]+x) * 3) + 1] = RGB.g;
					//red
					Buffer_Image[(y* horizontal_mulitplyer)+ ((letter_COLON[columnCNT][rowCNT]+x) * 3) + 2] = RGB.r;
				}
			x = StartPosX;
			y++;
		}


		Xil_DCacheFlush();


}

void DrawLetterComma_New(int StartPosX,int StartPosY,int LineColour, unsigned char *Buffer_Image){

	int y = StartPosY;
	int x = StartPosX;

	int horizontal_mulitplyer = Horizontal_Size * 3;
	// set colour of number
	COLOUR RGB;
	RGB = setcolor(LineColour);


		int COLUMN=20, ROW=20;
			const u8 letter_COMMA[20][20]=
			{
					{0,1},
					{0,1,2},
					{1,2,3,4,5},
					{2,3,4,5},
					{3,4,5},
					{0,1,2},

				{0,0}, //14 end flag
			};



		for (int columnCNT = 0; columnCNT < COLUMN; columnCNT++) {
//			for (int rowCNT = 0; rowCNT <sizeof(letter_Y[columnCNT])/sizeof(letter_Y[columnCNT][rowCNT]) ; rowCNT++) {

			if(letter_COMMA[columnCNT][0]+letter_COMMA[columnCNT][1]==0){//two row elements in the same column can't be 0
				break;
			}
			for (int rowCNT = 0; rowCNT <ROW ; rowCNT++) {
				//letter_Z[COLUMN][ROW]
				// row 0 --> column 0
			if (letter_COMMA[columnCNT][rowCNT] == 0 && rowCNT > 0) {
				break;
			}
					//blue
					Buffer_Image[(y* horizontal_mulitplyer)+ ((letter_COMMA[columnCNT][rowCNT]+x) * 3)] = RGB.b;
					//green
					Buffer_Image[(y* horizontal_mulitplyer)+ ((letter_COMMA[columnCNT][rowCNT]+x) * 3) + 1] = RGB.g;
					//red
					Buffer_Image[(y* horizontal_mulitplyer)+ ((letter_COMMA[columnCNT][rowCNT]+x) * 3) + 2] = RGB.r;
				}
			x = StartPosX;
			y++;
		}


		Xil_DCacheFlush();


}

void DrawLetterUnderscore_New(int StartPosX,int StartPosY,int LineColour, unsigned char *Buffer_Image){

	int y = StartPosY;
	int x = StartPosX;

	int horizontal_mulitplyer = Horizontal_Size * 3;
	// set colour of number
	COLOUR RGB;
	RGB = setcolor(LineColour);


		int COLUMN=21, ROW=20;
			const u8 letter_US[20][20]=
			{
					{0,1,2},
					{0,1,2},
					{0,1,2},
					{0,1,2},
					{0,1,2},
					{0,1,2},
					{0,1,2},
					{0,1,2},
					{0,1,2},
					{0,1,2},
					{0,1,2},
					{0,1,2},
					{0,1,2},
					{0,1,2},
					{0,1,2},
					{0,1,2},
					{0,1,2},
					{0,1,2},
					{0,1,2},
					{0,1,2},

				{0,0}, //14 end flag
			};



		for (int columnCNT = 0; columnCNT < COLUMN; columnCNT++) {
//			for (int rowCNT = 0; rowCNT <sizeof(letter_Y[columnCNT])/sizeof(letter_Y[columnCNT][rowCNT]) ; rowCNT++) {

			if(letter_US[columnCNT][0]+letter_US[columnCNT][1]==0){//two elements in the same column can't be 0
				break;
			}
			for (int rowCNT = 0; rowCNT <ROW ; rowCNT++) {
				//letter_Z[COLUMN][ROW]
				// row 0 --> column 0
			if (letter_US[columnCNT][rowCNT] == 0 && rowCNT > 0) {
				break;
								}
					//blue
					Buffer_Image[(y* horizontal_mulitplyer)+ ((letter_US[columnCNT][rowCNT]+x) * 3)] = RGB.b;
					//green
					Buffer_Image[(y* horizontal_mulitplyer)+ ((letter_US[columnCNT][rowCNT]+x) * 3) + 1] = RGB.g;
					//red
					Buffer_Image[(y* horizontal_mulitplyer)+ ((letter_US[columnCNT][rowCNT]+x) * 3) + 2] = RGB.r;
				}
			x = StartPosX;
			y++;
		}


		Xil_DCacheFlush();


}
void DrawLetterTilda_New(int StartPosX,int StartPosY,int LineColour, unsigned char *Buffer_Image){

	int y = StartPosY;
	int x = StartPosX;

	int horizontal_mulitplyer = Horizontal_Size * 3;
	// set colour of number
	COLOUR RGB;
	RGB = setcolor(LineColour);


		int COLUMN=21, ROW=20;
			const u8 letter_TILDA[21][5]=
			{
					{ 6,7},
							 {6,7,8,9,0},
							 {8,9,10,11,0},
							 {10,11,12,13},
							 {12,13,0,0,0},
							 {10,11,12,13,0},
							 {8,9,10,11,12},
							 {6,7,8,9,10},
							 {4,5,6,7,8},
							 {3,4,5,6,0},
							 {3,4,0,0,0},
							 {3,4,0,0,0},
							 {3,4,5,0,0},
							 {4,5,6,0,0},
							 {5,6,7,0,0},
							 {6,7,8,0,0},
							 {7,8,9,0,0},
							 {8,9,10,0,0},
							 {9,10,11,12,13},
							 {10,11,12,13,0},
				{0,0}, //14 end flag
			};



		for (int columnCNT = 0; columnCNT < COLUMN; columnCNT++) {
//			for (int rowCNT = 0; rowCNT <sizeof(letter_Y[columnCNT])/sizeof(letter_Y[columnCNT][rowCNT]) ; rowCNT++) {

			if(letter_TILDA[columnCNT][0]+letter_TILDA[columnCNT][1]==0){//two elements in the same column can't be 0
				break;
			}
			for (int rowCNT = 0; rowCNT <ROW ; rowCNT++) {
				//letter_Z[COLUMN][ROW]
				// row 0 --> column 0
				if(letter_TILDA[columnCNT][rowCNT]==0 && rowCNT>0){ //non initialized values are all ZEROS,
					break;
				}
					//blue
					Buffer_Image[(y* horizontal_mulitplyer)+ ((letter_TILDA[columnCNT][rowCNT]+x) * 3)] = RGB.b;
					//green
					Buffer_Image[(y* horizontal_mulitplyer)+ ((letter_TILDA[columnCNT][rowCNT]+x) * 3) +1] = RGB.g;
					//red
					Buffer_Image[(y* horizontal_mulitplyer)+ ((letter_TILDA[columnCNT][rowCNT]+x) * 3) +2] = RGB.r;

			}
			x = StartPosX;
			y++;
		}


		Xil_DCacheFlush();


}
void DrawLetterFWSlash_New(int StartPosX,int StartPosY,int LineColour, unsigned char *Buffer_Image){

int y = StartPosY;
int x = StartPosX;

int horizontal_mulitplyer = Horizontal_Size * 3;
// set colour of number
COLOUR RGB;
RGB = setcolor(LineColour);


	int COLUMN=21, ROW=20;
		const u8 letter_FWSLASH[20][20]=
		{
				{0,1,2},
				{0,1,2,3,4,5},
				{0,1,2,3,4,5,6,7,8},
				{3,4,5,6,7,8,9,10,11},
				{6,7,8,9,10,11,12,13,14},
				{9,10,11,12,13,14,15,16,17},
				{12,13,14,15,16,17,18,19},
				{15,16,17,18,19},
				{18,19},

			{0,0}, //14 end flag
		};



	for (int columnCNT = 0; columnCNT < COLUMN; columnCNT++) {
//			for (int rowCNT = 0; rowCNT <sizeof(letter_Y[columnCNT])/sizeof(letter_Y[columnCNT][rowCNT]) ; rowCNT++) {

		if(letter_FWSLASH[columnCNT][0]+letter_FWSLASH[columnCNT][1]==0){//two elements in the same column can't be 0
			break;
		}
		for (int rowCNT = 0; rowCNT <ROW ; rowCNT++) {
			//letter_Z[COLUMN][ROW]
			// row 0 --> column 0
			if(letter_FWSLASH[columnCNT][rowCNT]==0 && rowCNT>0){ //non initialized values are all ZEROS,
				break;
			}
				//blue
				Buffer_Image[(y* horizontal_mulitplyer)+ ((letter_FWSLASH[columnCNT][rowCNT]+x) * 3)] = RGB.b;
				//green
				Buffer_Image[(y* horizontal_mulitplyer)+ ((letter_FWSLASH[columnCNT][rowCNT]+x) * 3) +1] = RGB.g;
				//red
				Buffer_Image[(y* horizontal_mulitplyer)+ ((letter_FWSLASH[columnCNT][rowCNT]+x) * 3) +2] = RGB.r;

		}
		x = StartPosX;
		y++;
	}


	Xil_DCacheFlush();


}
