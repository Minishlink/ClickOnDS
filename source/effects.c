#include <PA9.h>

#include "effects.h"

void fadeOut(u8 screen)
{
	s8 i = 0;
	
	for(i = 0; i <= 16; i++) 
	{
		PA_WaitForVBL();
		if(screen == 0 || screen == 2) { PA_SetBrightness(0, i); }
		if(screen == 1 || screen == 2) { PA_SetBrightness(1, i); }
	}
}
 
 
void fadeIn(u8 screen)
{
	s8 i = 0;
	
	for(i = 16; i >= 0; i--) 
	{
		PA_WaitForVBL();
		if(screen == 0 || screen == 2) { PA_SetBrightness(0, i); }
		if(screen == 1 || screen == 2) { PA_SetBrightness(1, i); }
	}
}
