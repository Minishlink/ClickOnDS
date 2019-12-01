//Import de PAlib
#include <PA9.h>

#include "instructions.h"

void voirInstructions(u8 nbJeu)
{
	PA_Init2D();

	PA_InitText(1, 2);
	bool clic = 0;
	char *char_jeu = NULL, *char_instructions = NULL;
	
	if(nbJeu == JEU_SIMPLE_CLIC) 
	{
		char_jeu = "SIMPLE CLIC";
		char_instructions = "Vous devez \"cliquer\" sur l'écran le plus possible avant la fin du temps !!! C'est simple et c'est SIMPLE CLIC !";
	}
	else if(nbJeu == JEU_MICRO_CLIC) 
	{
		char_jeu = "MICRO CLIC";
		char_instructions = "Cette fois-ci, vous devez souffler et \"cliquer\" sur l'écran le plus possible avant la fin du temps !!! Attention tout de même à ne pas tomber dans les pommes, si vous ne vous sentez pas bien, faites une pause. ;)";
	}
	else if(nbJeu == JEU_TOUCH_MARIO)
	{
		char_jeu = "TOUCH MARIO";
		char_instructions ="Votre but est de toucher le plus de fois la mascotte de Nintendo (non ce n'est pas Link, désolé :-( ...) pendant que celle-ci bouge; le temps coule !";
	}
	else
	{
		char_jeu = "Unknown";
		char_instructions = "Unknown";
	}

	fadeOut(2);

	PA_LoadTiledBg(1, 3, bg_up_instructions);	
	PA_LoadTiledBg(0, 3, bg_down_instructions);

	PA_Init16cBg(1, 2);
	PA_16cText(1, 70, 145, 186, 170, char_jeu, 10, 3, 100);
	
	PA_Init16cBg(0, 2);
	PA_16cText(0, 40, 50, 215, 165, char_instructions, 10, 2, 500);

	fadeIn(2);

	while(1)
	{
		if(Stylus.Released) { clic = 1; }   
		if(PA_StylusInZone(0, 0, 69, 20) && clic) { clic = 0; menuInstructions(); }	

		PA_WaitForVBL();  	
	} 
	PA_WaitForVBL();  
}	

