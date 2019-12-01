#ifndef DEF_JEU
#define DEF_JEU
 
#define TEMPS_JEU          1000
#define JEU_SIMPLE_CLIC    10
#define JEU_MICRO_CLIC     11
#define JEU_TOUCH_MARIO    12

#define MARIO_WIDTH  64
#define MARIO_HEIGHT 64

#include "highscores.h"
#include "effects.h"
#include "menu.h"

// Converti par PAGfxConverter
#include "gfx/all_gfx.h"

typedef struct {
	u32 x, y, vx, vy;
	bool touched;
} s_mario;

extern void jouerSimpleClic();
extern void jouerMicroClic();
extern void jouerTouchMario();
 
#endif

