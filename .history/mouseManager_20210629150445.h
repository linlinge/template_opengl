#ifndef _OPENGL_TRACK_H_
#define _OPENGL_TRACK_H_
#include <GL/glut.h>
#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;
#define FPS 30
#define ESC 27
#define IDLE -2
#define MODIFIED -1
struct Quadrado {
    GLfloat lado, x, y, r, g, b;
    Quadrado(GLfloat lado = 0.0, GLfloat x = 0.0, GLfloat y = 0.0,
             GLfloat r = 0.0, GLfloat g = 0.0, GLfloat b = 0.0) :
        lado(lado),
        x(x), y(y), r(r), g(g), b(b) {}
};
void loop(int id);
#endif