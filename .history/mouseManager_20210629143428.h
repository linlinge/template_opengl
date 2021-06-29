#pragma once
#include <stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <string.h>
#include <math.h>
class MouseManager{
 public:
    static bool rotacionando2;
	GLfloat m2 [16];
    GLfloat mouseX_, mouseY_; //posicao inicial do cursor

    MouseManager(){

        GLfloat mtmp []= {1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1};
        memcpy(mtmp,m2,sizeof(mtmp));
    }
    static void mouseAndandoCB2(int PX, int PY);
};

extern MouseManager mm;