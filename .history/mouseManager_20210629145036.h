#pragma once
#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
extern bool rotacionando2;
extern GLfloat m2[16];
extern GLfloat mouseX_, mouseY_;  // posicao inicial do cursor
void mouseAndandoCB2(int PX, int PY);