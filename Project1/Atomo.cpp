#include <GL\freeglut.h>


static GLfloat xRot = 0.0f;
static GLfloat yRot = 0.0f;


void RenderScene(void)
{

	// Angle of revolution around the nucleus

	static GLfloat fElect1 = 0.0f;

	// Clear the window with current clearing color

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Reset the modelview matrix

	glMatrixMode(GL_MODELVIEW);

	glLoadIdentity();

	// Translate the whole scene out and into view
	// This is the initial viewing transformation

	glTranslatef(0.0f, 0.0f, -100.0f);

	// Red Nucleus

	glColor3ub(255, 0, 0);

	glutSolidSphere(10.0f, 15, 15);

	// Yellow Electrons
	glColor3ub(255,255,0);

	// First Electron Orbit
	// Save viewing transformation

	glPushMatrix();
	
	// Rotate by angle of revolution
	glRotatef(fElect1, 0.0f, 1.0f, 0.0f);
	
	// Translate out from origin to orbit distance
	glTranslatef(90.0f, 0.0f, 0.0f);
	
	// Draw the electron
	glutSolidSphere(6.0f, 15, 15);

	// Restore the viewing transformation

	glPopMatrix();


	// Second Electron Orbit
	glPushMatrix();
	glRotatef(45.0f, 0.0f, 0.0f, 1.0f);
	glRotatef(fElect1, 0.0f, 1.0f, 0.0f);
	glTranslatef(-70.0f, 0.0f, 0.0f);
	glutSolidSphere(6.0f, 15, 15);
	glPopMatrix();

	// Third Electron Orbit
	glPushMatrix();
	glRotatef(360.0f-45.0f, 0.0f, 0.0f, 1.0f);
	glRotatef(fElect1, 0.0f, 1.0f, 0.0f);
	glTranslatef(0.0f, 0.0f, 60.0f);
	glutSolidSphere(6.0f, 15, 15);
	glPopMatrix();

// Increment the angle of revolution
	fElect1 += 10.0f;
	if(fElect1 > 360.0f)
		fElect1 = 0.0f;
// Show the image
glutSwapBuffers();

}

void SetupRC()
	{
	// Black background
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f );

	// Set drawing color to green
	glColor3f(0.0f, 1.0f, 0.0f);

	// Set color shading model to flat
	glShadeModel(GL_FLAT);

	// Clock wise wound polygons are front facing 
	glFrontFace(GL_CW);
	
}

void SpecialKeys(int key, int x, int y)
	{
	if(key == GLUT_KEY_UP)
		xRot -= 50.0f;

	if(key == GLUT_KEY_DOWN)
		xRot += 1.0f;

	if(key == GLUT_KEY_LEFT)
		yRot -= 1.0f;

	if(key == GLUT_KEY_RIGHT)
		yRot += 1.0f;

	if(key > 356.0f)
		xRot = 0.0f;

	if(key < -1.0f)
		xRot = 355.0f;

	if(key > 356.0f)
		yRot = 0.0f;

	if(key < -1.0f)
		yRot = 355.0f;

	// Refresh the Window
	glutPostRedisplay();
	}


/*void ChangeSize(int w, int h)
	{
	GLfloat nRange = 100.0f;

	// Prevent a divide by zero
	if(h == 0)
		h = 1;

	// Set Viewport to window dimensions
	glViewport(0, 0, w, h);

	// Reset projection matrix stack
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// Establish clipping volume (left, right, bottom, top, near, far)
    if (w <= h) 
		glOrtho (-nRange, nRange, -nRange*h/w, nRange*h/w, -nRange*2.0f, nRange*2.0f);
    else 
		glOrtho (-nRange*w/h, nRange*w/h, -nRange, nRange, -nRange*2.0f, nRange*2.0f);

	// Reset Model view matrix stack
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	}
*/

void ChangeSizePersp(int w, int h){
	GLfloat fAspect;

	// Prevent a divide by zero
	if(h == 0)
		h = 1;

	// Set Viewport to window dimensions
	glViewport(0, 0, w, h);

	// Reset projection matrix stack
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	fAspect= (float)w/(float)h;
	gluPerspective(45.0 , fAspect, 1.0 ,500.0);
	
	// Reset Model view matrix stack
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.0f ,0.0f ,-250.0f);
	}


void TimerFunction (int value) {
  
  glutPostRedisplay();
  glutTimerFunc(33,TimerFunction, value);

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
	glutInitWindowSize(800,640);
  
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("Roda Automatica");
	
	glutReshapeFunc(ChangeSizePersp);
	glutSpecialFunc(SpecialKeys);
	glutKeyboardFunc(keyboard);
	glutDisplayFunc(RenderScene);
	glutTimerFunc(330, TimerFunction, 1);

	SetupRC();
	glutMainLoop();

	return 0;
}