// Solar.cpp
// OpenGL SuperBible
// Demonstrates OpenGL nested coordinate transformations
// and perspective
// Program by Richard S. Wright Jr.

#include <GL\freeglut.h>
#include <math.h>


static GLfloat xRot = 0.0f;
static GLfloat yRot = 0.0f;


// Lighting values
GLfloat  whiteLight[] = { 0.2f, 0.2f, 0.2f, 1.0f };
GLfloat  sourceLight[] = { 0.8f, 0.8f, 0.8f, 1.0f };
GLfloat	 lightPos[] = { 0.0f, 0.0f, 0.0f, 1.0f };


// Called to draw scene
void RenderScene(void)
	{
	// Earth and Moon angle of revolution
	static float fMoonRot = 0.0f;
	static float fEarthRot = 0.0f;

	// Clear the window with current clearing color
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Save the matrix state and do the rotations
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	 glRotatef(xRot, 1.0f, 0.0f, 0.0f);
  //glRotatef(yRot, 0.0f, 1.0f, 0.0f);
	 glRotatef(yRot, 0.0f, 0.0f, 1.0f); //TRAVAR NO EIXO 'Z'.
 

	// Translate the whole scene out and into view	
	glTranslatef(0.0f, 0.0f, -300.0f);	
	
	// Set material color, Red
	// Sun
        //glDisable(GL_LIGHTING);
	glColor3ub(0, 0, 255);
	glutSolidSphere(15.0f, 30, 17);
      //  glEnable(GL_LIGHTING);

	// Move the light after we draw the sun!
	//glLightfv(GL_LIGHT0,GL_POSITION,lightPos);

	// Rotate coordinate system
	glRotatef(fEarthRot, 0.0f, 1.0f, 0.0f);

	// Draw the Earth
	glDisable(GL_LIGHTING);
	glColor3ub(255, 255,0);
	glTranslatef(105.0f,0.0f,0.0f);
	glutSolidSphere(15.0f, 30, 17);
	glEnable(GL_LIGHTING);

	glLightfv(GL_LIGHT0,GL_POSITION,lightPos);


	// Rotate from Earth based coordinates and draw Moon
	glColor3ub(200,200,200);
	glRotatef(fMoonRot,0.0f, 1.0f, 0.0f);
	glTranslatef(30.0f, 0.0f, 0.0f);
	//fMoonRot+= 15.0f;
	//if(fMoonRot > 360.0f)
	//	fMoonRot = 0.0f;

	glutSolidSphere(6.0f, 30, 17);

	// Restore the matrix state
	glPopMatrix();	// Modelview matrix


	// Step earth orbit 5 degrees
	fEarthRot += 5.0f;
	if(fEarthRot > 360.0f)
		fEarthRot = 0.0f;

	// Show the image
	glutSwapBuffers();
	}


// This function does any needed initialization on the rendering
// context. 
void SetupRC()
	{
	// Light values and coordinates
	glEnable(GL_DEPTH_TEST);	// Hidden surface removal
	glFrontFace(GL_CCW);		// Counter clock-wise polygons face out
	glEnable(GL_CULL_FACE);		// Do not calculate inside of jet

	// Enable lighting
	glEnable(GL_LIGHTING);

	// Setup and enable light 0
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT,whiteLight);
	glLightfv(GL_LIGHT0,GL_DIFFUSE,sourceLight);
	glLightfv(GL_LIGHT0,GL_POSITION,lightPos);
	glEnable(GL_LIGHT0);

	// Enable color tracking
	glEnable(GL_COLOR_MATERIAL);
	
	// Set Material properties to follow glColor values
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

	// Black blue background
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f );
    }


void TimerFunc(int value)
    {
    glutPostRedisplay();
    glutTimerFunc(100, TimerFunc, 1);
    }

void ChangeSize(int w, int h)
    {
    GLfloat fAspect;

    // Prevent a divide by zero
    if(h == 0)
        h = 1;

    // Set Viewport to window dimensions
    glViewport(0, 0, w, h);

    // Calculate aspect ratio of the window
    fAspect = (GLfloat)w/(GLfloat)h;

    // Set the perspective coordinate system
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // field of view of 45 degrees, near and far planes 1.0 and 425
    gluPerspective(45.0f, fAspect, 1.0, 425.0);

    // Modelview matrix reset
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    }

void SpecialKeys(int key, int x, int y)	{
  if(key == GLUT_KEY_UP)
    xRot -= 1.0f;

  if(key == GLUT_KEY_DOWN)
    xRot += 1.0f;

  if(key == GLUT_KEY_LEFT)
    yRot -= 1.0f;

  if(key == GLUT_KEY_RIGHT)
    yRot += 1.0f;

  if(xRot > 356.0f)
    xRot = 0.0f;

  if(xRot < -1.0f)
    xRot = 355.0f;

  if(yRot > 356.0f)
    yRot = 0.0f;

  if(yRot < -1.0f)
    yRot = 355.0f;

  // Redesenha a janela
   glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y)
{
   switch (key) {
   case 27:
   case 113:// letra q minúscula
   case 'Q':
     exit(0);
     break;
   }
}


int main(int argc, char* argv[])
	{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
        glutInitWindowSize(800, 600);
	glutCreateWindow("Sistema de Iluminacao");
	glutReshapeFunc(ChangeSize);
	glutKeyboardFunc(keyboard);
    glutSpecialFunc(SpecialKeys);
	glutDisplayFunc(RenderScene);
        glutTimerFunc(250, TimerFunc, 1);
	SetupRC();
	glutMainLoop();

	return 0;
	}
