//Import de PAlib
#include <PA9.h>

#include "jeu.h"

void jouerSimpleClic()
{
	PA_Init2D(); //On efface tout

	bool clic = 0, start = 0;

	fadeOut(2);

	PA_LoadTiledBg(1, 3, bg_up_jeu);
	PA_LoadTiledBg(0, 3, bg_down);

	PA_Init16cBg(1, 2);
	PA_16cText(1, 70, 145, 186, 170, "SIMPLE CLIC", 10, 3, 100);

	fadeIn(2);

	s32 tempsJeu = TEMPS_JEU;
	u32 compteurclicks = 0;
	u8 jeuDoing = JEU_SIMPLE_CLIC;
	char text[100] = "";

	while(1)
	{
		PA_16cText(1, 70, 145, 186, 170, "SIMPLE CLIC", 10, 3, 100);

		if(start)
		{
			if(Stylus.Released) { clic = 1; }

			if(PA_StylusInZone(0, 0, 69, 20) && clic)
			{
			clic = 0;
			menuJeu();
			}

			if(Stylus.Released && tempsJeu > 0)
				compteurclicks++;

			sprintf(text, "Score : %ld  ", compteurclicks);
			PA_16cText(1, 199, 176, 254, 190, text, 10, 1, 100);

			if(tempsJeu > 0)
			{
				tempsJeu--;
				sprintf(text, " Temps : %ld ", tempsJeu);
				PA_16cText(1, 0, 176, 56, 190, text, 10, 1, 100);
			}
			else if(tempsJeu <= 0) //C'est fini !
			{
				PA_16cText(1, 0, 176, 56, 190, " FINISH !!!", 10, 1, 100);
				sauverHighScores(compteurclicks, jeuDoing);
			}
		}
		else
		{
			if(Stylus.Released) clic = 1;
			if(PA_StylusInZone(0, 0, 69, 20) && clic) { clic = 0; menuJeu(); }
			if(Stylus.Released) start = 1;

			PA_16cText(1, 80, 160, 186, 170, "Touch to start !", 10, 2, 100);
		}
		PA_WaitForVBL();
		PA_16cErase(1);
	}
	PA_WaitForVBL();
}

void jouerMicroClic()
{
	PA_Init2D();

	bool clic = 0, start = 0;

	fadeOut(2);

	PA_LoadTiledBg(1, 3, bg_up_jeu);
	PA_LoadTiledBg(0, 3, bg_down);

	PA_Init16cBg(1, 2); PA_Init16cBg(0, 2);
	PA_16cText(1, 70, 145, 186, 170, "MICRO CLIC", 10, 3, 100);

	fadeIn(2);

	s32 tempsJeu = TEMPS_JEU;
	u32 compteurclicks = 0;
	u8 jeuDoing = JEU_MICRO_CLIC;
	char text[100] = "";

	while(1)
	{
		PA_16cText(1, 70, 145, 186, 170, "MICRO CLIC", 10, 3, 100);

		if(start)
		{
			if(Stylus.Released) { clic = 1; }

			if(PA_StylusInZone(0, 0, 69, 20) && clic)
			{
				clic = 0;
				menuJeu();
			}

			if(Stylus.Released && PA_MicGetVol() >= 128 && tempsJeu > 0)
				compteurclicks++;

			sprintf(text, "Score : %ld  ", compteurclicks);
			PA_16cText(1, 199, 176, 254, 190, text, 10, 1, 100);

			if(tempsJeu > 0)
			{
				tempsJeu--;
				sprintf(text, " Temps : %ld ", tempsJeu);
				PA_16cText(1, 0, 176, 56, 190, text, 10, 1, 100);
			}
			else if(tempsJeu <= 0) //C'est Fini !
			{
				PA_16cText(1, 1, 176, 56, 190, " FINISH !!!", 10, 1, 100);
				sauverHighScores(compteurclicks, jeuDoing);
			}

			sprintf(text, "Volume Microphone : %d     ", PA_MicGetVol());
			PA_16cText(0, 2, 12, 100, 24, text, 10, 1, 100);

		}
		else
		{
			if(Stylus.Released) { clic = 1; }
			if(PA_StylusInZone(0, 0, 69, 20) && clic) { clic = 0; menuJeu(); }

			if(Stylus.Released) { start = 1; }

			PA_16cText(1, 80, 160, 186, 170, "Touch to start !", 10, 2, 100);
		}

		PA_WaitForVBL();
		PA_16cErase(1); PA_16cErase(0);
	}
	PA_WaitForVBL();
}

void jouerTouchMario()
{
	PA_Init2D();
	
	bool clic = 0, start = 0;
	s_mario mario;
	s16 rand_tpsAvantChangement, 
	u8 rand_direction;

	fadeOut(2);

	PA_LoadTiledBg(1, 3, bg_up_jeu);
	PA_LoadTiledBg(0, 3, bg_down);

	PA_Init16cBg(1, 2); PA_Init16cBg(0, 2);
	PA_16cText(1, 70, 145, 186, 170, "TOUCH MARIO", 10, 3, 100);

	fadeIn(2);

	s32 tempsJeu = TEMPS_JEU;
	u32 compteurclicks = 0;
	u8 jeuDoing = JEU_TOUCH_MARIO;
	char text[100] = "";

	while(1)
	{
		PA_16cText(1, 70, 145, 186, 170, "TOUCH MARIO", 10, 3, 100);

		if(start)
		{
			if(Stylus.Released) { clic = 1; }

			if(PA_StylusInZone(0, 0, 69, 20) && clic)
			{
				clic = 0;
				menuJeu();
			}

			if(Stylus.Released && tempsJeu > 0)
			{
				if((Stylus.X >= mario.x && Stylus.Y <= mario.x + MARIO_WIDTH) && (Stylus.Y >= mario.y && Stylus.Y <= mario.y + MARIO_HEIGHT))
				{
					compteurclicks++;
					// afficher anim bravo
				}
				else
				{
					// afficher anim réessai
				}
			}

			sprintf(text, "Score : %ld  ", compteurclicks);
			PA_16cText(1, 199, 176, 254, 190, text, 10, 1, 100);

			if(tempsJeu > 0)
			{
				tempsJeu--;
				sprintf(text, " Temps : %ld ", tempsJeu);
				PA_16cText(1, 0, 176, 56, 190, text, 10, 1, 100);
				
				if(rand_tpsEntreChangement <= 0) rand_direction = PA_RandMax(8); rand_tpsEntreChangement = PA_RandMinMax(80, 200);
				if(rand_direction == 1) mario.x++;
				else if(rand_direction == 2) mario.x--;
				else if(rand_direction == 3) mario.y++;
				else if(rand_direction == 4) mario.y--;
				else if(rand_direction == 5) mario.x++; mario.y++;
				else if(rand_direction == 6) mario.x--; mario.y++;
				else if(rand_direction == 7) mario.x++; mario.y--;
				else if(rand_direction == 8) mario.x--; mario.y--;
			}
			else if(tempsJeu <= 0) //C'est Fini !
			{
				PA_16cText(1, 1, 176, 56, 190, " FINISH !!!", 10, 1, 100);
				sauverHighScores(compteurclicks, jeuDoing);
			}
		}
		else
		{
			if(Stylus.Released) { clic = 1; }
			if(PA_StylusInZone(0, 0, 69, 20) && clic) { clic = 0; menuJeu(); }

			if(Stylus.Released) { start = 1; }

			PA_16cText(1, 80, 160, 186, 170, "Touch to start !", 10, 2, 100);
		}

		PA_WaitForVBL();
		PA_16cErase(1); PA_16cErase(0);
	}
	PA_WaitForVBL();
}

