#include <gl/glut.h>
#include "Functions.h"
#include <math.h>


static GLfloat start[100] ;
static GLfloat color_r[100] , color_g[100] , color_b[100];
static GLint count = 0 , turn = 0; 
GLboolean r_check = true, g_check = true , b_check = true;


void init()
{
	glClearColor(0.0, 1.0, 1.0, 0.3);
	glMatrixMode(GL_PROJECTION);

}

void GL_display()
{

	glClear(GL_COLOR_BUFFER_BIT);


	glPushMatrix();
	glColor3f(1, 1, 1);
	glutSolidSphere(1.0, 100, 50);


	paint_circle();

	glRotatef(start[count], 0.0, 0.0, 1.0);


/////////////////paint Rectangle
	const GLfloat x1 = .9, x2 = -.25, y1 = .05, y2 = -.25;
	glPushMatrix();
	   glTranslatef(1.15, 0, 0.0);
	   glRotatef(105, 0, 0, 1);

	      glBegin(GL_POLYGON);
	          glColor3f(1.0, 0.0, 1.0);
	          glVertex2f(x1, y1);
	          glVertex2f(x1, y2);
	          glVertex2f(y2, x2);
	          glVertex2f(x2, y1);
	      glEnd();

	glPopMatrix();


//////////////////////// paint wheel_1

	      glPushMatrix();
	          glTranslatef(1.17, 0.0, 0.0);
		 	  glRotatef(turn, 0, 0, 1);

	          glColor3f(0.0, 0.0, 0.0);
	          glutSolidSphere(0.15, 100, 100);
			  for (int i = 0; i < 8; i++)
			  {
				  glRotatef(45 * i, 0, 0, 1);
				  glBegin(GL_LINES);

				  if (!r_check)
					  glColor3f(1, 0, 0);

				   else if (!g_check)
					  glColor3f(0, 0.5, 0);

				        else 
					       glColor3f(0, 0, 1);

				  glVertex2d(0, 0);
				  glVertex2d(0.15, 0);
				  glEnd();
			  }
			  
	      glPopMatrix();


//////////////////////// paint wheel_2
	      glPushMatrix();
	          glTranslatef(1.00, .6, 0.0);
			  glRotatef(turn, 0, 0, 1);

	          glColor3f(0.0, 0.0, 0.0);
	          glutSolidSphere(0.15, 100, 100);

			  for (int i = 0; i < 8; i++)
			  {
				  glRotatef(45 * i, 0, 0, 1);
				  glBegin(GL_LINES);

				  if (!r_check)
					  glColor3f(1, 0, 0);

				  else if (!g_check)
					  glColor3f(0, 0.5, 0);

				  else
					  glColor3f(0, 0, 1);

				  glVertex2d(0, 0);
				  glVertex2d(0.15, 0);
				  glEnd();
			  }
	     glPopMatrix();

	glPopMatrix();

	glutSwapBuffers();
}

void GL_reshape(GLsizei w, GLsizei h)
{

	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();

	gluPerspective(60.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);

	glMatrixMode(GL_MODELVIEW);

	glLoadIdentity();

	gluLookAt(0.0, 0.0, 5.0,
		0.0, 0.0, 0.0,
		0.0, 1.0, 0.0);

}



void GL_Keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{


	case 'r':
	
		b_check = g_check = true;
		turn+=5;
		if (r_check)
		{
			
			r_check = false;
			color_r[count] = 1;
			color_g[count] = 0;
			color_b[count] = 0;
			count++;
			start[count] = start[count-1];
			
		}

	  start[count]++;

		glutPostRedisplay();

		break;

	case 'g':

		b_check = r_check = true;
		turn+=5;
		if (g_check)
		{
			
			g_check = false;
			color_r[count] = 0;
			color_g[count] = 0.5;
			color_b[count] = 0;
			count++;
			start[count] = start[count-1];

		}

		start[count]++;

		glutPostRedisplay();
		break;



	case 'b':

		g_check = r_check = true;
		turn+=50;
		if (b_check)
		{

			b_check = false;
			color_r[count] = 0;
			color_g[count] = 0;
			color_b[count] = 1;
			count++;
			start[count] = start[count - 1];

		}

		start[count]++;

		glutPostRedisplay();
		break;
	}
}


void paint_circle()
{
	GLfloat angle, raioX = 1.02f, raioY = 1.02f;
	GLfloat circle_points = 360.0f;

	

	
	for (int j = 0; j < count; j++)
	{
		glBegin(GL_TRIANGLE_FAN);
		glColor3f(color_r[j], color_g[j], color_b[j]);
	    glVertex2f(0.0f, 0.0f);

		for (int i = start[j]; i <= start[j + 1]; i++)
		{
            angle = 2 * 3.1415 * i / circle_points;
			glVertex2f(0.0 + cos(angle) * raioX, 0.0 + sin(angle) * raioY);
		}

		glEnd();
	}
}
