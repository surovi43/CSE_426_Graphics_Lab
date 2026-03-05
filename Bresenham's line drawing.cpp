#define GL_SILENCE_DEPRECATION
#include <GL/glut.h>
#include <bits/stdc++.h>


using namespace std;

const int dashLen = 10;
const int gapLen = 10;

int X1, Y1, X2, Y2, nob;

void controlled_nob(int x, int y, int n)
{
    // draw pixel
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
    glFlush();

    // neighbor pixels
    if (n - 1 > 0)
    {
        controlled_nob(x + 1, y, n - 1);
        controlled_nob(x - 1, y, n - 1);
        controlled_nob(x, y + 1, n - 1);
        controlled_nob(x, y - 1, n - 1);
    }

    printf("*");
}

void draw_pixel(int x, int y)
{
    controlled_nob(x, y, nob);
}

void draw_line(int X1, int Y1, int X2, int Y2)
{
    int x = X1, y = Y1;
    int dx = abs(X2 - X1);
    int dy = abs(Y2 - Y1);
    int stepX = X2 > X1 ? 1 : -1;
    int stepY = Y2 > Y1 ? 1 : -1;

    bool steep = dy > dx;
    if (steep) swap(dx, dy);

    int pk = 2 * dy - dx; // p0 = 2∆y - ∆x

    for (int i = 0; i <= dx; i++)
    {
        if (i % (dashLen + gapLen) < dashLen) // to control dashed line
            draw_pixel(x, y);

        pk += 2 * dy; // pk = pk + 2∆y

        if (pk >= 0)
        {
            steep ? x += stepX : y += stepY;
            pk -= 2 * dx; // -2∆x
        }

        steep ? y += stepY : x += stepX;
    }
}

void init()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 500, 0, 500);
}

void display()
{
    draw_line(X1, Y1, X2, Y2);
    glFlush();
}

int main(int argc, char **argv)
{
    printf("Enter (X1, Y1, X2, Y2, nob)\n");
    scanf("%d %d %d %d %d", &X1, &Y1, &X2, &Y2, &nob);

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1000, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Bresenham's Line Drawing");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
}
