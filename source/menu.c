//Import de PAlib
#include <PA9.h>

#include "menu.h"

void menu()
{
	PA_Init2D();

	bool clic = 0;

	fadeOut(2);

	PA_Init16cBg(0, 2);
	PA_16cText(0, 66, 11, 189, 21, "              CHOISISSEZ...", 10, 2, 100); //screen; x1, y1, x2, y2 position; text; color (1-10); text size (0-4); maximum number of characters (use like 10000 if you don't know)
	PA_16cText(0, 66, 38, 189, 48, "               ... ET BIEN !", 10, 1, 100);
	PA_16cText(0, 72, 73, 196, 86, "JOUER A UN JEU !", 10, 2, 100);
	PA_16cText(0, 72, 104, 196, 117, "LES HIGHSCORES !", 10, 2, 100);
	PA_16cText(0, 72, 135, 196, 148, "COMMENT JOUER ?!", 10, 2, 100);
	PA_16cText(0, 72, 166, 196, 179, "VOIR LES CREDITS !", 10, 2, 100);

	PA_LoadTiledBg(1, 3, menu_up);	
	PA_LoadTiledBg(0, 3, menu_down);

	PA_LoadSpritePal(0, 0, (void*)cursorLeft_Pal); // Screen, Palette number, Palette name
	PA_CreateSprite(0, 0, (void*)cursorLeft_Sprite, OBJ_SIZE_16X32, 1, 0, 16, 16); // Screen, Sprite number, Sprite name, Sprite size, 256 color mode, Sprite palette number, X and Y position on the screen		   
	PA_LoadSpritePal(0, 1, (void*)cursorRight_Pal);
	PA_CreateSprite(0, 1, (void*)cursorRight_Sprite, OBJ_SIZE_16X32, 1, 1, 224, 16);	 

	fadeIn(2);    

	while(1)
	{   
		if(Stylus.Released) { clic = 1; }   
		if (PA_SpriteTouched(1) && clic) { clic = 0; menuJeu(); }  			
		if (PA_SpriteTouched(0) && clic) { clic = 0; menuInstructions(); }		 			
		if(PA_StylusInZone(72, 73, 196, 86) && clic) { clic = 0; menuJeu(); }
		if(PA_StylusInZone(72, 104, 196, 117) && clic) { clic = 0; menuHighscores(); }
		if(PA_StylusInZone(72, 135, 196, 148) && clic) { clic = 0; menuInstructions(); }
		if(PA_StylusInZone(72, 166, 196, 179) && clic) { clic = 0; credits(); }		  
		if(Pad.Newpress.Start) { credits(); }
			 	
		PA_WaitForVBL();  	
	}  
	PA_WaitForVBL();  	 		
}

void menuJeu()
{
	PA_Init2D();
	PA_InitText(1, 2);

	bool clic = 0;

	fadeOut(2);

	PA_Init16cBg(0, 2);
	PA_16cText(0, 66, 11, 189, 21, "    RETOUR AU MENU", 10, 2, 100); //screen; x1, y1, x2, y2 position; text; color (1-10); text size (0-4); maximum number of characters (use like 10000 if you don't know)
	PA_16cText(0, 66, 38, 189, 48, "   CHOIX DU JEU", 10, 1, 100);
	PA_16cText(0, 72, 73, 196, 86, "SIMPLE CLIC", 10, 2, 100);
	PA_16cText(0, 72, 104, 196, 117, "MICRO CLIC", 10, 2, 100);
	PA_16cText(0, 72, 135, 196, 148, "TOUCH MARIO", 10, 2, 100);
	PA_16cText(0, 72, 166, 196, 179, "", 10, 2, 100);

	PA_LoadTiledBg(1, 3, menu_up);	
	PA_LoadTiledBg(0, 3, sous_menu_down);

	PA_LoadSpritePal(0, 0, (void*)cursorLeft_Pal); // Screen, Palette number, Palette name
	PA_CreateSprite(0, 0, (void*)cursorLeft_Sprite, OBJ_SIZE_16X32, 1, 0, 16, 16); // Screen, Sprite number, Sprite name, Sprite size, 256 color mode, Sprite palette number, X and Y position on the screen		   
	PA_LoadSpritePal(0, 1, (void*)cursorRight_Pal);
	PA_CreateSprite(0, 1, (void*)cursorRight_Sprite, OBJ_SIZE_16X32, 1, 1, 224, 16);	 

	fadeIn(2); 

	while(1)
	{            
		if(Stylus.Released) { clic = 1; }   
		if(PA_StylusInZone(66, 11, 189, 21) && clic) { clic = 0; menu(); } 
		if (PA_SpriteTouched(1) && clic) { clic = 0; menuHighscores(); }  			
		if (PA_SpriteTouched(0) && clic) { clic = 0; menu(); }
		if(PA_StylusInZone(72, 73, 196, 86) && clic) { clic = 0; jouerSimpleClic(); }
		if(PA_StylusInZone(72, 104, 196, 117) && clic) { clic = 0; jouerMicroClic(); }
		else if(PA_StylusInZone(72, 135, 196, 148) && clic) { clic = 0; jouerTouchMario(); }
		else if(PA_StylusInZone(72, 166, 196, 179) && clic) { clic = 0; jouerMicroClic(); }
		PA_WaitForVBL();  
	} 	
	PA_WaitForVBL();  	
}

void menuHighscores()
{
	PA_Init2D();
	PA_InitText(1, 2);

	bool clic = 0;

	fadeOut(2);

	PA_Init16cBg(0, 2);
	PA_16cText(0, 66, 11, 189, 21, "    RETOUR AU MENU", 10, 2, 100); //screen; x1, y1, x2, y2 position; text; color (1-10); text size (0-4); maximum number of characters (use like 10000 if you don't know)
	PA_16cText(0, 66, 38, 189, 48, " CHOIX DES HIGHSCORES", 10, 1, 100);
	PA_16cText(0, 72, 73, 196, 86, "SIMPLE CLIC", 10, 2, 100);
	PA_16cText(0, 72, 104, 196, 117, "MICRO CLIC", 10, 2, 100);
	PA_16cText(0, 72, 135, 196, 148, "TOUCH MARIO", 10, 2, 100);
	PA_16cText(0, 72, 166, 196, 179, "", 10, 2, 100);

	PA_LoadTiledBg(1, 3, menu_up);	
	PA_LoadTiledBg(0, 3, sous_menu_down);

	PA_LoadSpritePal(0, 0, (void*)cursorLeft_Pal); // Screen, Palette number, Palette name
	PA_CreateSprite(0, 0, (void*)cursorLeft_Sprite, OBJ_SIZE_16X32, 1, 0, 16, 16); // Screen, Sprite number, Sprite name, Sprite size, 256 color mode, Sprite palette number, X and Y position on the screen		   
	PA_LoadSpritePal(0, 1, (void*)cursorRight_Pal);
	PA_CreateSprite(0, 1, (void*)cursorRight_Sprite, OBJ_SIZE_16X32, 1, 1, 224, 16);	 

	fadeIn(2); 

	while(1)
	{            
		if(Stylus.Released) { clic = 1; }   
		else if(PA_StylusInZone(66, 11, 189, 21) && clic) { clic = 0; menu(); } 
		else if(PA_SpriteTouched(1) && clic) { clic = 0; menuInstructions(); }  			
		else if(PA_SpriteTouched(0) && clic) { clic = 0; menuJeu(); }
		else if(PA_StylusInZone(72, 73, 196, 86) && clic) { clic = 0; voirHighscores(JEU_SIMPLE_CLIC); }
		else if(PA_StylusInZone(72, 104, 196, 117) && clic) { clic = 0; voirHighscores(JEU_MICRO_CLIC); }
		else if(PA_StylusInZone(72, 135, 196, 148) && clic) { clic = 0; voirHighscores(JEU_TOUCH_MARIO); }
		else if(PA_StylusInZone(72, 166, 196, 179) && clic) { clic = 0; voirHighscores(0); }
		PA_WaitForVBL();
	} 
	PA_WaitForVBL();  		
}   

void menuInstructions()
{
	PA_Init2D();
	PA_InitText(1, 1);
	bool clic = 0;

	fadeOut(2);

	PA_Init16cBg(0, 2);
	PA_16cText(0, 66, 11, 189, 21, "    RETOUR AU MENU", 10, 2, 100); //screen; x1, y1, x2, y2 position; text; color (1-10); text size (0-4); maximum number of characters (use like 10000 if you don't know)
	PA_16cText(0, 66, 38, 189, 48, "CHOIX DES INSTRUCTIONS", 10, 1, 100);
	PA_16cText(0, 72, 73, 196, 86, "SIMPLE CLIC", 10, 2, 100);
	PA_16cText(0, 72, 104, 196, 117, "MICRO CLIC", 10, 2, 100);
	PA_16cText(0, 72, 135, 196, 148, "TOUCH MARIO", 10, 2, 100);
	PA_16cText(0, 72, 166, 196, 179, "", 10, 2, 100);

	PA_LoadTiledBg(1, 3, menu_up);	
	PA_LoadTiledBg(0, 3, sous_menu_down);

	PA_LoadSpritePal(0, 0, (void*)cursorLeft_Pal); // Screen, Palette number, Palette name
	PA_CreateSprite(0, 0, (void*)cursorLeft_Sprite, OBJ_SIZE_16X32, 1, 0, 16, 16); // Screen, Sprite number, Sprite name, Sprite size, 256 color mode, Sprite palette number, X and Y position on the screen		   
	PA_LoadSpritePal(0, 1, (void*)cursorRight_Pal);
	PA_CreateSprite(0, 1, (void*)cursorRight_Sprite, OBJ_SIZE_16X32, 1, 1, 224, 16);	 

	fadeIn(2); 

	while(1)
	{            
		if(Stylus.Released) { clic = 1; }  
		if(PA_StylusInZone(66, 11, 189, 21) && clic) { clic = 0; menu(); } 
		else if(PA_SpriteTouched(1) && clic) { clic = 0; menu(); }  			
		else if(PA_SpriteTouched(0) && clic) { clic = 0; menuHighscores(); }
		else if(PA_StylusInZone(72, 73, 196, 86) && clic) { clic = 0; voirInstructions(JEU_SIMPLE_CLIC); }
		else if(PA_StylusInZone(72, 104, 196, 117) && clic) { clic = 0; voirInstructions(JEU_MICRO_CLIC); }
		else if(PA_StylusInZone(72, 135, 196, 148) && clic) { clic = 0; voirInstructions(JEU_TOUCH_MARIO); }
		else if(PA_StylusInZone(72, 166, 196, 179) && clic) { clic = 0; voirInstructions(0); }

		PA_WaitForVBL();	
	}
	PA_WaitForVBL();  	
} 


