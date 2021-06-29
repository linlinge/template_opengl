#ifndef _OPENGL_TRACK_H_
#define _OPENGL_TRACK_H_
#include <GL/glut.h>
#include <math.h>
#include <cstdio>
extern GLfloat mouseX_, mouseY_;  // posicao inicial do cursor
extern bool rotacionando2;
extern GLfloat m2[];
void mouseAndandoCB2(int PX, int PY);
#endif