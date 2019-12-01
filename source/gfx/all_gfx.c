//Gfx converted using Mollusk's PAGfx Converter

//This file contains all the .c, for easier inclusion in a project

#ifdef __cplusplus
extern "C" {
#endif

#include "all_gfx.h"


// Sprite files : 
#include "cursorRight.c"
#include "cursorLeft.c"

// Background files : 
#include "menu_down.c"
#include "menu_up.c"
#include "bg_down.c"
#include "sous_menu_down.c"
#include "bg_up_jeu.c"
#include "bg_up_highscores.c"
#include "bg_up_instructions.c"
#include "bg_down_highscores.c"
#include "bg_down_instructions.c"

// Palette files : 
#include "cursorRight.pal.c"
#include "cursorLeft.pal.c"
#include "menu_down.pal.c"
#include "menu_up.pal.c"
#include "bg_down.pal.c"
#include "sous_menu_down.pal.c"
#include "bg_up_jeu.pal.c"
#include "bg_up_highscores.pal.c"
#include "bg_up_instructions.pal.c"
#include "bg_down_highscores.pal.c"
#include "bg_down_instructions.pal.c"

// Background Pointers :
PAGfx_struct menu_down = {(void*)menu_down_Map, 768, (void*)menu_down_Tiles, 19584, (void*)menu_down_Pal, (int*)menu_down_Info };
PAGfx_struct menu_up = {(void*)menu_up_Map, 768, (void*)menu_up_Tiles, 37760, (void*)menu_up_Pal, (int*)menu_up_Info };
PAGfx_struct bg_down = {(void*)bg_down_Map, 768, (void*)bg_down_Tiles, 33792, (void*)bg_down_Pal, (int*)bg_down_Info };
PAGfx_struct sous_menu_down = {(void*)sous_menu_down_Map, 768, (void*)sous_menu_down_Tiles, 19584, (void*)sous_menu_down_Pal, (int*)sous_menu_down_Info };
PAGfx_struct bg_up_jeu = {(void*)bg_up_jeu_Map, 768, (void*)bg_up_jeu_Tiles, 34624, (void*)bg_up_jeu_Pal, (int*)bg_up_jeu_Info };
PAGfx_struct bg_up_highscores = {(void*)bg_up_highscores_Map, 768, (void*)bg_up_highscores_Tiles, 36224, (void*)bg_up_highscores_Pal, (int*)bg_up_highscores_Info };
PAGfx_struct bg_up_instructions = {(void*)bg_up_instructions_Map, 768, (void*)bg_up_instructions_Tiles, 36992, (void*)bg_up_instructions_Pal, (int*)bg_up_instructions_Info };
PAGfx_struct bg_down_highscores = {(void*)bg_down_highscores_Map, 768, (void*)bg_down_highscores_Tiles, 20544, (void*)bg_down_highscores_Pal, (int*)bg_down_highscores_Info };
PAGfx_struct bg_down_instructions = {(void*)bg_down_instructions_Map, 768, (void*)bg_down_instructions_Tiles, 13696, (void*)bg_down_instructions_Pal, (int*)bg_down_instructions_Info };


#ifdef __cplusplus
}
#endif

