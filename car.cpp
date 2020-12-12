
#include <GL/glut.h>
#include "Functions.h"

int main()
{
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(100, 100);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutCreateWindow("Semnan");

    glutKeyboardFunc(GL_Keyboard);
    glutReshapeFunc(GL_reshape);
    glutDisplayFunc(GL_display);

    init();

    glutMainLoop();
    return 0;
}

