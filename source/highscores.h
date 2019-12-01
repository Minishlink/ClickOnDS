#ifndef DEF_HIGHSCORES
#define DEF_HIGHSCORES

#include <stdio.h>  // nécessaire pour la gestion fichier
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "fat.h"

#include "effects.h"
#include "menu.h"

// Converti par PAGfxConverter
#include "gfx/all_gfx.h"

extern void voirHighscores(u8 nbJeu);
extern void recupHighScores(u32 *score);
extern void sauverHighScores(u8 clics, u8 jeu);
 
#endif



