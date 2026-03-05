#include <GL/glut.h>
#include <bits/stdc++.h>

using namespace std;

int centerX, centerY, r;

void plot(int x, int y)
{
   glBegin(GL_POINTS);
   glVertex2i(x + centerX, y + centerY);
   glEnd();
   glFlush();
}

void midPointCircleAlgo()
{
   int x = 0, y = r;
   plot(x, y);

   int pk = 1 - r;

   while (y > x)
   {
      if (pk < 0)
      {
         x++;
         pk += 2 * x + 3;
      }
      else
      {
         y--;
         x++;
         pk += 2 * (x - y) + 5;
      }

      Sleep(50);

      glColor3f(1.0, 0.0, 0.0);
      plot(x, y);

      glColor3f(0.0, 1.0, 0.0);
      plot(x, -y);

      glColor3f(0.0, 0.0, 1.0);
      plot(-x, y);

      glColor3f(1.0, 1.0, 0.0);
      plot(-x, -y);

      glColor3f(0.0, 1.0, 1.0);
      plot(y, x);

      glColor3f(1.0, 0.0, 0.0);
      plot(-y, x);

      glColor3f(1.0, 0.0, 1.0);
      plot(y, -x);

      glColor3f(0.0, 0.0, 0.0);
      plot(-y, -x);
   }
}

void init(void)
{
   glClearColor(1.0, 1.0, 1.0, 0.0);
   glColor3f(0.0f, 0.0f, 0.0f);
   glPointSize(5.0);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

void display(void)
{
   glClear(GL_COLOR_BUFFER_BIT);
   glClearColor(1.0, 1.0, 1.0, 1.0);
   glColor3f(0.0, 0.0, 0.0);
   glPointSize(5.0);
   midPointCircleAlgo();
   glFlush();
}

int main(int argc, char **argv)
{
   cout << "Enter the center coordinates and radius (x y r): ";
   cin >> centerX >> centerY >> r;

   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
   glutInitWindowSize(640, 480);
   glutInitWindowPosition(100, 150);
   glutCreateWindow("Line Drawing Alogrithms");
   glutDisplayFunc(display);
   init();
   glutMainLoop();
}
