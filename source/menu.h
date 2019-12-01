#ifndef DEF_MENU
#define DEF_MENU
 
#define C_MAIN                  0
#define C_JEU                   1
#define C_HIGHSCORES            2
#define C_HIGHSCORES_CLASSIC    20
#define C_HIGHSCORES_ADVANCED   21
#define C_INSTRUCTIONS          3
#define C_INSTRUCTIONS_CLASSIC  30
#define C_INSTRUCTIONS_ADVANCED 31
#define C_CREDITS               4

#include "effects.h"
#include "main.h"
#include "highscores.h"
#include "jeu.h"
#include "instructions.h"

// Converti par PAGfxConverter
#include "gfx/all_gfx.h"

extern void menu(void);
extern void menuJeu(void);
extern void menuHighscores(void);
extern void menuInstructions(void);
 
#endif

