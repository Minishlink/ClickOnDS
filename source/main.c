//Import de PAlib
#include <PA9.h>

// Converti par PAGfxConverter
#include "gfx/all_gfx.c"
#include "gfx/all_gfx.h"

#include "main.h"

int main(void)
{
	PA_Init();     //Init de PAlib
	PA_InitVBL(); // Init de la VBL
	PA_InitRand();

	if(!fatInitDefault())
	{
		while(1)
		{
			PA_InitText(1, 2);

			PA_OutputSimpleText(1, 0, 8, "An error occured, please patch this file with a dldi tool.");
			PA_WaitForVBL();
		}
	}
	else credits();
	
	return 0;
}

void credits(void)
{
	PA_Init2D();

 	bool continuer = 1;

 	PA_SplashBlue();

	while(continuer)
	{
		if(Stylus.Released)
			continuer = 0;
			
		PA_WaitForVBL();
	}

   	PA_WaitForVBL();

   	PA_Init2D();

   	continuer = 1;

   	PA_InitText(1, 2);

   	fadeOut(2);
		PA_OutputSimpleText(1, 0, 2, "Creator : Minishlink");
		PA_OutputSimpleText(1, 0, 3, "Special Thanks to :");
		PA_OutputSimpleText(1, 0, 4, "- Naouak;");
		PA_OutputSimpleText(1, 0, 5, "- Mollusk;");
		PA_OutputSimpleText(1, 0, 6, "- Birslip;");
		PA_OutputSimpleText(1, 0, 7, "- Sam101;");
		PA_OutputSimpleText(1, 0, 8, "- Dev-fr forums and #dev-fr.");
	fadeIn(2);

	while(continuer)
	{
		if(Stylus.Released)
			menu();
		
		PA_WaitForVBL();
	}
	PA_WaitForVBL();
}
