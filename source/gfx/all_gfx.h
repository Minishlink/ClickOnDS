//Gfx converted using Mollusk's PAGfx Converter

//This file contains all the .h, for easier inclusion in a project

#ifndef ALL_GFX_H
#define ALL_GFX_H

#ifndef PAGfx_struct
    typedef struct{
    void *Map;
    int MapSize;
    void *Tiles;
    int TileSize;
    void *Palette;
    int *Info;
} PAGfx_struct;
#endif


// Sprite files : 
extern const unsigned char cursorRight_Sprite[512] __attribute__ ((aligned (4))) ;  // Pal : cursorRight_Pal
extern const unsigned char cursorLeft_Sprite[512] __attribute__ ((aligned (4))) ;  // Pal : cursorLeft_Pal

// Background files : 
extern const int menu_down_Info[3]; // BgMode, Width, Height
extern const unsigned short menu_down_Map[768] __attribute__ ((aligned (4))) ;  // Pal : menu_down_Pal
extern const unsigned char menu_down_Tiles[19584] __attribute__ ((aligned (4))) ;  // Pal : menu_down_Pal
extern PAGfx_struct menu_down; // background pointer

extern const int menu_up_Info[3]; // BgMode, Width, Height
extern const unsigned short menu_up_Map[768] __attribute__ ((aligned (4))) ;  // Pal : menu_up_Pal
extern const unsigned char menu_up_Tiles[37760] __attribute__ ((aligned (4))) ;  // Pal : menu_up_Pal
extern PAGfx_struct menu_up; // background pointer

extern const int bg_down_Info[3]; // BgMode, Width, Height
extern const unsigned short bg_down_Map[768] __attribute__ ((aligned (4))) ;  // Pal : bg_down_Pal
extern const unsigned char bg_down_Tiles[33792] __attribute__ ((aligned (4))) ;  // Pal : bg_down_Pal
extern PAGfx_struct bg_down; // background pointer

extern const int sous_menu_down_Info[3]; // BgMode, Width, Height
extern const unsigned short sous_menu_down_Map[768] __attribute__ ((aligned (4))) ;  // Pal : sous_menu_down_Pal
extern const unsigned char sous_menu_down_Tiles[19584] __attribute__ ((aligned (4))) ;  // Pal : sous_menu_down_Pal
extern PAGfx_struct sous_menu_down; // background pointer

extern const int bg_up_jeu_Info[3]; // BgMode, Width, Height
extern const unsigned short bg_up_jeu_Map[768] __attribute__ ((aligned (4))) ;  // Pal : bg_up_jeu_Pal
extern const unsigned char bg_up_jeu_Tiles[34624] __attribute__ ((aligned (4))) ;  // Pal : bg_up_jeu_Pal
extern PAGfx_struct bg_up_jeu; // background pointer

extern const int bg_up_highscores_Info[3]; // BgMode, Width, Height
extern const unsigned short bg_up_highscores_Map[768] __attribute__ ((aligned (4))) ;  // Pal : bg_up_highscores_Pal
extern const unsigned char bg_up_highscores_Tiles[36224] __attribute__ ((aligned (4))) ;  // Pal : bg_up_highscores_Pal
extern PAGfx_struct bg_up_highscores; // background pointer

extern const int bg_up_instructions_Info[3]; // BgMode, Width, Height
extern const unsigned short bg_up_instructions_Map[768] __attribute__ ((aligned (4))) ;  // Pal : bg_up_instructions_Pal
extern const unsigned char bg_up_instructions_Tiles[36992] __attribute__ ((aligned (4))) ;  // Pal : bg_up_instructions_Pal
extern PAGfx_struct bg_up_instructions; // background pointer

extern const int bg_down_highscores_Info[3]; // BgMode, Width, Height
extern const unsigned short bg_down_highscores_Map[768] __attribute__ ((aligned (4))) ;  // Pal : bg_down_highscores_Pal
extern const unsigned char bg_down_highscores_Tiles[20544] __attribute__ ((aligned (4))) ;  // Pal : bg_down_highscores_Pal
extern PAGfx_struct bg_down_highscores; // background pointer

extern const int bg_down_instructions_Info[3]; // BgMode, Width, Height
extern const unsigned short bg_down_instructions_Map[768] __attribute__ ((aligned (4))) ;  // Pal : bg_down_instructions_Pal
extern const unsigned char bg_down_instructions_Tiles[13696] __attribute__ ((aligned (4))) ;  // Pal : bg_down_instructions_Pal
extern PAGfx_struct bg_down_instructions; // background pointer


// Palette files : 
extern const unsigned short cursorRight_Pal[5] __attribute__ ((aligned (4))) ;
extern const unsigned short cursorLeft_Pal[5] __attribute__ ((aligned (4))) ;
extern const unsigned short menu_down_Pal[29] __attribute__ ((aligned (4))) ;
extern const unsigned short menu_up_Pal[187] __attribute__ ((aligned (4))) ;
extern const unsigned short bg_down_Pal[50] __attribute__ ((aligned (4))) ;
extern const unsigned short sous_menu_down_Pal[29] __attribute__ ((aligned (4))) ;
extern const unsigned short bg_up_jeu_Pal[92] __attribute__ ((aligned (4))) ;
extern const unsigned short bg_up_highscores_Pal[91] __attribute__ ((aligned (4))) ;
extern const unsigned short bg_up_instructions_Pal[94] __attribute__ ((aligned (4))) ;
extern const unsigned short bg_down_highscores_Pal[34] __attribute__ ((aligned (4))) ;
extern const unsigned short bg_down_instructions_Pal[34] __attribute__ ((aligned (4))) ;


#endif

