#pragma once
#include <stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <string.h>
#include <math.h>

    static bool rotacionando2;
	static GLfloat m2 [16];
    static GLfloat mouseX_, mouseY_; //posicao inicial do cursor

    static void Init(){

        GLfloat mtmp []= {1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1};
        memcpy(mtmp,m2,sizeof(mtmp));
    }
    static void mouseAndandoCB2(int PX, int PY);
};

