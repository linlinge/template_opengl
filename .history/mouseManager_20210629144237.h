#pragma once
#include <stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <string.h>
#include <math.h>

bool rotacionando2;
GLfloat m2 [16]={1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1};
GLfloat mouseX_, mouseY_; //posicao inicial do cursor

void mouseAndandoCB2(int PX, int PY);


