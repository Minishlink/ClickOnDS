//Import de PAlib
#include <PA9.h>

#include "highscores.h"

void voirHighscores(u8 nbJeu)
{
	PA_Init2D();

	PA_InitText(0, 2);

	bool clic = 0;

	u32 score[10] = {0};
	recupHighScores(score);

	char text[100] = "";

	fadeOut(2);

	PA_LoadTiledBg(1, 3, bg_up_highscores);
	PA_LoadTiledBg(0, 3, bg_down_highscores);

	PA_Init16cBg(1, 2);
	PA_Init16cBg(0, 2);
	
	if(nbJeu == JEU_SIMPLE_CLIC)
	{
		PA_16cText(1, 70, 145, 186, 170, "SIMPLE CLIC", 10, 3, 100);

		sprintf(text, " [1] : %ld ", score[0]);
		PA_16cText(0, 80, 50, 180, 65, text, 10, 3, 100);
		sprintf(text, " [2] : %ld ", score[1]);
		PA_16cText(0, 80, 70, 180, 85, text, 10, 3, 100);
		sprintf(text, " [3] : %ld ", score[2]);
		PA_16cText(0, 80, 90, 180, 105, text, 10, 3, 100);
		sprintf(text, " [4] : %ld ", score[3]);
		PA_16cText(0, 80, 110, 180, 125, text, 10, 3, 100);
		sprintf(text, " [5] : %ld ", score[4]);
		PA_16cText(0, 80, 130, 180, 145, text, 10, 3, 100);
	}
	else if(nbJeu == JEU_SIMPLE_CLIC)
	{
		PA_16cText(1, 70, 145, 186, 170, "MICRO CLIC", 10, 3, 100);
		
		sprintf(text, " [1] : %ld ", score[5]);
		PA_16cText(0, 80, 50, 180, 65, text, 10, 3, 100);
		sprintf(text, " [2] : %ld ", score[6]);
		PA_16cText(0, 80, 70, 180, 85, text, 10, 3, 100);
		sprintf(text, " [3] : %ld ", score[7]);
		PA_16cText(0, 80, 90, 180, 105, text, 10, 3, 100);
		sprintf(text, " [4] : %ld ", score[8]);
		PA_16cText(0, 80, 110, 180, 125, text, 10, 3, 100);
		sprintf(text, " [5] : %ld ", score[9]);
		PA_16cText(0, 80, 130, 180, 145, text, 10, 3, 100);
	}
	else
	{
		PA_16cText(1, 70, 145, 186, 170, "UNKNOWN", 10, 3, 100);

		PA_16cText(0, 40, 50, 215, 165, "Sorry, but scores are not available.", 10, 2, 200);
	}

	fadeIn(2);

	while(1)
	{
		if(Stylus.Released) { clic = 1; }
		if(PA_StylusInZone(0, 0, 69, 20) && clic) { clic = 0; menuHighscores();  }

		PA_WaitForVBL();
	}
	PA_WaitForVBL();
}

void recupHighScores(u32 *score)
{
	FILE *fichier = NULL;
	fichier = fopen("/ClickOnDS.sav", "r"); //On ouvre le fichier en mode lecture

	//Si l'ouverture a fonctionnée
	if (fichier != NULL)
	{
		//On prend les valeurs des HighScores
		fscanf(fichier, "%ld %ld %ld %ld %ld\r\n%ld %ld %ld %ld %ld", &score[0], &score[1], &score[2],  &score[3],  &score[4], &score[5], &score[6], &score[7],  &score[8],  &score[9]);
		fclose(fichier); //On ferme le fichier
	}
	//Si l'ouverture n'a pas fonctionnée
	else
	{
		// On affiche un message d'erreur
		fprintf(stderr, "Erreur Fichier: Ouverture du fichier échouée lors de la récupération des HighScores");
	}
}

void sauverHighScores(u8 clics, u8 jeu)
{
	FILE* fichier = NULL;
	s32 score[10] = {0}; // Tableau des 5 meilleurs scores
	char texteAffiche[100] = "";

	fichier = fopen("/ClickOnDS.sav", "w+"); //On ouvre le fichier en mode lecture + écriture

	//Si l'ouverture a fonctionnée
	if (fichier != NULL)
	{
	   //On prend les anciennes valeurs des HighScores
	   fscanf(fichier, "%ld %ld %ld %ld %ld\n%ld %ld %ld %ld %ld", &score[0], &score[1], &score[2],  &score[3],  &score[4], &score[5], &score[6], &score[7],  &score[8],  &score[9]);

	   if(jeu == 10)
	   {
	      if (clics > score[0])
	      {
	         //PREMIER !
	         rewind(fichier);
	         sprintf(texteAffiche, "%d %ld %ld %ld %ld\n%ld %ld %ld %ld %ld", clics, score[0], score[1], score[2], score[3], score[5], score[6], score[7], score[8], score[9]); //Enregistrement des HighScores
	         fwrite(texteAffiche, 100, 1, fichier);

	      }
	      else if (clics > score[1] && clics < score[0])
	      {
	         //DEUXIEME !
	         rewind(fichier);
	         sprintf(texteAffiche, "%ld %d %ld %ld %ld\n%ld %ld %ld %ld %ld", score[0], clics, score[1], score[2], score[3], score[5], score[6], score[7], score[8], score[9]); //Enregistrement des HighScores
	         fwrite(texteAffiche, 100, 1, fichier);
	      }
	        else if (clics > score[2] && clics < score[1])
	      {
	         //TROSIEME !
	         rewind(fichier);
	         sprintf(texteAffiche, "%ld %ld %d %ld %ld\n%ld %ld %ld %ld %ld", score[0], score[1], clics, score[2], score[3], score[5], score[6], score[7], score[8], score[9]); //Enregistrement des HighScores
	         fwrite(texteAffiche, 100, 1, fichier);
	      }
	      else if (clics > score[3] && clics < score[2])
	      {
	         //QUATRIEME !
	         rewind(fichier);
	         sprintf(texteAffiche, "%ld %ld %ld %d %ld\n%ld %ld %ld %ld %ld", score[0], score[1], score[2], clics, score[3], score[5], score[6], score[7], score[8], score[9]); //Enregistrement des HighScores
	         fwrite(texteAffiche, 100, 1, fichier);
	      }
	      else if (clics < score[3])
	      {
	         //CINQUIEME !
	         rewind(fichier);
	         sprintf(texteAffiche, "%ld %ld %ld %ld %d\n%ld %ld %ld %ld %ld", score[0], score[1], score[2], score[3], clics, score[5], score[6], score[7], score[8], score[9]); //Enregistrement des HighScores
	         fwrite(texteAffiche, 100, 1, fichier);
	      }
		}

	   else if(jeu == 11)
	   {
	      if (clics > score[5])
	      {
	         //PREMIER !
	         rewind(fichier);
	         sprintf(texteAffiche, "%ld %ld %ld %ld %ld\n%d %ld %ld %ld %ld", score[0], score[1], score[2], score[3], score[4], clics, score[5], score[6], score[7], score[8]); //Enregistrement des HighScores
	        	fwrite(texteAffiche, 100, 1, fichier);
	      }
	      else if (clics > score[6] && clics < score[5])
	      {
	           //DEUXIEME !
	         rewind(fichier);
	         sprintf(texteAffiche, "%ld %ld %ld %ld %ld\n%ld %d %ld %ld %ld", score[0], score[1], score[2], score[3], score[4], score[5], clics, score[6], score[7], score[8]); //Enregistrement des HighScores
	        	fwrite(texteAffiche, 100, 1, fichier);
	      }
	      else if (clics > score[7] && clics < score[6])
	      {
	         //TROSIEME !
	         rewind(fichier);
	         sprintf(texteAffiche, "%ld %ld %ld %ld %ld\n%ld %ld %d %ld %ld", score[0], score[1], score[2], score[3], score[4], score[5], score[6], clics, score[7], score[8]); //Enregistrement des HighScores
	        	fwrite(texteAffiche, 100, 1, fichier);
	      }
	      else if (clics > score[8] && clics < score[7])
	      {
	         //QUATRIEME !
	         rewind(fichier);
	         sprintf(texteAffiche, "%ld %ld %ld %ld %ld\n%ld %ld %ld %d %ld", score[0], score[1], score[2], score[3], score[4], score[5], score[6], score[7], clics, score[8]); //Enregistrement des HighScores
	        	fwrite(texteAffiche, 100, 1, fichier);
	      }
	      else if (clics < score[8])
	      {
	         //CINQUIEME !
	         rewind(fichier);
	         sprintf(texteAffiche, "%ld %ld %ld %ld %ld\n%ld %ld %ld %ld %d", score[0], score[1], score[2], score[3], score[4], score[5], score[6], score[7], score[8], clics); //Enregistrement des HighScores
	        	fwrite(texteAffiche, 100, 1, fichier);
	      }
	   }

	   fclose(fichier); //On ferme le fichier
	}
	  //Si l'ouverture n'a pas fonctionnée
	else
	{
	   // On affiche un message d'erreur
	   PA_OutputSimpleText(1, 0, 10, "Fichier: Ouverture du fichier échouée lors de la sauvegarde des HighScores");
	}
}



