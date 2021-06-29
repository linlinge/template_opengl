#include "mouseManager.h"
GLfloat mouseX_, mouseY_;  // posicao inicial do cursor
bool mouseLeftDown;
bool mouseRightDown;
bool mouseMiddleDown;
float times = 1;
bool rotacionando2 = true;
GLfloat m2[] = {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1};
GLfloat anguloRotacao;
GLfloat eixoRotacao[3];  // vector product "mouse X P"
void mouseAndandoCB2(int PX, int PY) {
    // mouse = last position
    // P = current position
    printf("px %d", PX);
    if (rotacionando2) {
        GLint W = glutGet(GLUT_WINDOW_WIDTH);
        GLint H = glutGet(GLUT_WINDOW_HEIGHT);
        GLfloat raio;  // for a while, we don't need the radius square root
        if (W > H)
            raio = W * W / 2;
        else
            raio = H * H / 2;
        mouseX_ -= W / 2;  //
        GLfloat px = PX - W / 2;  // uses the screen center as origin
        mouseY_ = H / 2 - mouseY_;  //
        GLfloat py = H / 2 - PY;  //
        // Finds the Z coordinate of the sphere centered at the origin
        GLfloat mouseX_Y2 = mouseX_ * mouseX_ + mouseY_ * mouseY_;
        GLfloat pXY2 = px * px + py * py;
        if (mouseX_Y2 < raio && pXY2 < raio) {  // this trackball only works for
                                                // points inside the sphere
            GLfloat mouseZ = sqrt(raio - mouseX_Y2);
            GLfloat pz = sqrt(raio - pXY2);
            eixoRotacao[0] = -mouseZ * py + mouseY_ * pz;
            eixoRotacao[1] = mouseZ * px - mouseX_ * pz;
            eixoRotacao[2] = -mouseY_ * px + mouseX_ * py;
            anguloRotacao = atan(sqrt(eixoRotacao[0] * eixoRotacao[0] +
                                      eixoRotacao[1] * eixoRotacao[1] +
                                      eixoRotacao[2] * eixoRotacao[2]));
            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();
            glRotatef(anguloRotacao, eixoRotacao[0], eixoRotacao[1],
                      eixoRotacao[2]);
            glMultMatrixf(m2);
            glGetFloatv(GL_MODELVIEW_MATRIX, m2);
        }
    }
    mouseX_ = PX;
    mouseY_ = PY;
    glutPostRedisplay();
}
float gscale = 1.0;
void mouseCB(int button, int state, int x, int y) {
    mouseX_ = x;
    mouseY_ = y;
    times = 1;
    float lscale = 0;
    if (button == GLUT_LEFT_BUTTON) {
        if (state == GLUT_DOWN) {
            mouseLeftDown = true;
        } else if (state == GLUT_UP)
            mouseLeftDown = false;
    } else if (button == GLUT_RIGHT_BUTTON) {
        if (state == GLUT_DOWN) {
            mouseRightDown = true;
        } else if (state == GLUT_UP)
            mouseRightDown = false;
    }
    /*
     * 鼠标滚轮控制图形缩放
     */
    else if (state == GLUT_UP && button == 3) {
        cout << "scroll up" << endl;
        lscale = 1.1;
        glutPostRedisplay();
    } else if (state == GLUT_UP && button == 4) {
        cout << "scroll down" << endl;
        lscale = 0.909;
        glutPostRedisplay();
    }
    gscale = gscale * lscale;
    glMatrixMode(GL_MODELVIEW);
    glScalef(gscale, gscale, gscale);
}
