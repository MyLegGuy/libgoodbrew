#ifndef GOODBREWGRAPHICSINCLUDED_H
#define GOODBREWGRAPHICSINCLUDED_H
#ifdef __cplusplus
extern "C" {
#endif

#if GBREND==GBREND_SDL
	#include <SDL2/SDL.h>
	extern SDL_Window* mainWindow;
	extern SDL_Renderer* mainWindowRenderer;
#elif GBREND==GBREND_QUICK
	#include <allegro5/allegro.h>
#endif
#if DOFIXCOORDS == 1
	float fixX(float x);
	float fixY(float y);
#endif
#define EASYFIXCOORDS(x, y) FixCoords(x,y)

#define WINDOWFLAG_FULLSCREEN 1
#define WINDOWFLAG_RESIZABLE 2
#define WINDOWFLAG_EXTRAFEATURES 4

extern int _goodbrewRealScreenWidth;
extern int _goodbrewRealScreenHeight;

void gbCoverUnused(int _usedWidth, int _usedHeight, int r, int g, int b); // Assuming that _usedWidth and _usedHeight are the dimensions of the space you're using, and you've centered everything
void drawRectangle(float x, float y, int w, int h, int r, int g, int b, int a);
void endDrawing();
int getScreenHeight();
int getScreenWidth();
// _windowWidth and _windowHeight are recommendations for the Window size. Will be ignored on many platforms. Need to use getScreenWidth and getScreenHeight after calling.
void initGraphics(int _windowWidth, int _windowHeight, long _passedFlags);
void quitGraphics();
void setClearColor(int r, int g, int b);
void getClearColor(unsigned char* r, unsigned char* g, unsigned char* b);
void setWindowTitle(char* _newTitle);
void startDrawingBottom();
void startDrawing();
void FixCoords(float* _x, float* _y);
void initImages();
void enableClipping(int x, int y, int w, int h);
void disableClipping();
int gbGetDrawOffX();
int gbGetDrawOffY();
void gbSetDrawOffX(int _passed);
void gbSetDrawOffY(int _passed);
#ifdef __cplusplus
}
#endif
#endif // GOODBREWGRAPHICSINCLUDED_H
