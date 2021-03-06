#include <math.h>
#include <stdlib.h>
#include "PCLExtend.h"
#include "mouseManager.h"
GLfloat vertices[][3] = {
    {-1.0, -1.0, -1.0}, {1.0, -1.0, -1.0}, {1.0, 1.0, -1.0}, {-1.0, 1.0, -1.0},
    {-1.0, -1.0, 1.0},  {1.0, -1.0, 1.0},  {1.0, 1.0, 1.0},  {-1.0, 1.0, 1.0}};
GLfloat normals[][3] = {{-1.0, -1.0, -1.0}, {1.0, -1.0, -1.0}, {1.0, 1.0, -1.0},
                        {-1.0, 1.0, -1.0},  {-1.0, -1.0, 1.0}, {1.0, -1.0, 1.0},
                        {1.0, 1.0, 1.0},    {-1.0, 1.0, 1.0}};
GLfloat colors[][3] = {{0.0, 0.0, 0.0}, {1.0, 0.0, 0.0}, {1.0, 1.0, 0.0},
                       {0.0, 1.0, 0.0}, {0.0, 0.0, 1.0}, {1.0, 0.0, 1.0},
                       {1.0, 1.0, 1.0}, {0.0, 1.0, 1.0}};
void polygon(int a, int b, int c, int d) {
    /* draw a polygon via list of vertices */
    glBegin(GL_POLYGON);
    glColor3fv(colors[a]);
    // glNormal3fv(normals[a]);
    glVertex3fv(vertices[a]);
    glColor3fv(colors[b]);
    // glNormal3fv(normals[b]);
    glVertex3fv(vertices[b]);
    glColor3fv(colors[c]);
    // glNormal3fv(normals[c]);
    glVertex3fv(vertices[c]);
    glColor3fv(colors[d]);
    // glNormal3fv(normals[d]);
    glVertex3fv(vertices[d]);
    glEnd();
}
void colorcube(void) {
    /*polygon(0,3,2,1);
    polygon(2,3,7,6);
    polygon(0,4,7,3);
    polygon(1,2,6,5);
    polygon(4,5,6,7);
    polygon(0,1,5,4);*/
    glutWireTeapot(1.0);
}
static GLfloat theta[] = {0.0, 0.0, 0.0};
static GLint axis = 2;
void display(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    colorcube();
    glFlush();
    glutSwapBuffers();
}
void spinCube() {
    theta[axis] += 0.1;
    if (theta[axis] > 360.0)
        theta[axis] -= 360.0;
    glutPostRedisplay();
}
void myReshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (w <= h)
        glOrtho(-2.0, 2.0, -2.0 * (GLfloat)h / (GLfloat)w,
                2.0 * (GLfloat)h / (GLfloat)w, -10.0, 10.0);
    else
        glOrtho(-2.0 * (GLfloat)w / (GLfloat)h, 2.0 * (GLfloat)w / (GLfloat)h,
                -2.0, 2.0, -10.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
}
void Init() {
    pcl::io::loadPLYFile("/home/llg/work", ) glewInit();
    //??????
    glGenBuffers(NUM_BUFFERS, buffers);
    // glGenBuffers(1, &bufferId);
    glBindBuffer(GL_ARRAY_BUFFER, buffers[VERTEX]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * 3 * 8, vertexs,
                 GL_STATIC_DRAW);
    glVertexPointer(3, GL_FLOAT, 0, (GLvoid*)0);
    glEnableClientState(GL_VERTEX_ARRAY);
}
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    /* need both double buffering and z buffer */
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutCreateWindow("colorcube");
    glutReshapeFunc(myReshape);
    glutDisplayFunc(display);
    // glutIdleFunc(spinCube);
    glutMouseFunc(mouseCB);
    glutMotionFunc(mouseAndandoCB2);
    glEnable(GL_DEPTH_TEST); /* Enable hidden--surface--removal */
    Init();
    glutMainLoop();
    return 0;
}