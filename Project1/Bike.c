//Nome: Vinícius Corrêa de Almeida
//Matricula: 11/0021401

#include <GL\freeglut.h>
#include <math.h>

#define GL_PI 3.1415f


static GLfloat xRot = 0.0f;
static GLfloat yRot = 0.0f;

static GLfloat deg = 0.0f;


void DesenhaPneu(){

	glColor3f(1.0,1.0,1.0);
	glutSolidTorus(2.0,30.0,8.0,1000.0);

}

void DesenhaBanco(){
	glColor3f(0.0,0.0,1.0);
	glutSolidCone(30.0,1.0,3.0,100.0);

}

void DesenhaBarra(GLfloat espessura,GLfloat tamanhoCilindro){
	
	glColor3f(0.0,1.0,0.0);
	glutSolidCylinder(espessura,tamanhoCilindro,100.0,1.0);

}

void DesenhaGuidon(GLfloat espessura,GLfloat tamanhoCilindro){
	
	glColor3f(1.0,1.0,1.0);
	glutSolidCylinder(espessura,tamanhoCilindro,100.0,1.0);

}

void DesenhaEngrenagen(){

	glColor3f(0.0,0.0,1.0);
	glutSolidCone(10.0,0.0,20.0,100.0);

}

void DesenhaEngrenagenRoda(){

	glColor3f(1.0,0.0,0.0);
	glutSolidCone(10.0,0.0,20.0,100.0);

}

void DesenhaRoda(GLfloat raio,GLfloat raiosRoda){
	GLfloat x,y,angle,z=0.0;  
	int iPivot = 1;		
	
	glBegin(GL_TRIANGLE_FAN);
	
	glVertex3f(0.0f, 0.0f, z);

	for(angle = 0.0f; angle < (2.0f*GL_PI); angle += (GL_PI/raiosRoda))
		{
		x = raio*sin(angle);
		y = raio*cos(angle);
	
		if((iPivot %2) == 0)
			glColor3f(0.0f, 0.0f, 1.0f);
		else
			glColor3f(0.0f, 0.0f, 1.0f);
			
		iPivot++;

		glVertex3f(x, y, z);
		}

	glEnd();
}

void RenderScene(void){
	

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	
	glDisable(GL_CULL_FACE);

	glEnable(GL_DEPTH_TEST);

	glPolygonMode(GL_BACK,GL_LINE);
    glPolygonMode(GL_FRONT,GL_LINE);

	glPushMatrix();
	glRotatef(yRot, 0.0f, 1.0f, 0.0f);
	glRotatef(xRot, 1.0f, 0.0f, 0.0f);
	
	glPushMatrix();

	glTranslatef(-85.0, -60.0, -10.0);
	glRotatef(30*deg, 0.0f, 0.0f, 1.0f);

	//********************

	// Primeiro parametro para o tamanho da roda e o segundo para aquantidade de raios da roda.
	DesenhaRoda(30.0,8.0);
	DesenhaPneu();
	
	glPopMatrix();
	/////////////////////--------------------///////////////////////
	glPushMatrix();
	
	glTranslatef(-87.0, -60.0, -6.0);
	glRotatef(86.0,0.0,1.0,0.0);
	DesenhaBarra(2.0,83.5);

	glTranslatef(0.0, 0.0, 1.3);
	glRotatef(-20.0,1.0,0.0,0.0);
	DesenhaBarra(2.0,88.0);

	glTranslatef(5.0, 36.4, 100.0);
	glRotatef(110.0,1.0,0.0,0.0);
	DesenhaBarra(4.0,70.3);

	glPopMatrix();
	/////////////----------------------------////////////////////////
	glPushMatrix();

	glTranslatef(-87.0, -60.0, -17.0);
	glRotatef(86.0,0.0,1.0,0.0);
	DesenhaBarra(2.0,83.5);

	glTranslatef(0.0, 0.0, 1.3);
	glRotatef(-20.0,1.0,0.0,0.0);
	DesenhaBarra(2.0,88.0);

	glPopMatrix();
	///////////////////------------------------////////////////////////
	glPushMatrix();

	glTranslatef(85.0, -62.0, -6.0);
	glRotatef(-90.0,1.0,0.0,0.0);
	DesenhaBarra(3.0,90.5);

	glTranslatef(0.0, -10.0, 0.0);
	DesenhaBarra(3.0,90.5);

	glPopMatrix();

	glPushMatrix();

	glTranslatef(-5.0, -30.0, -3.0);
	glRotatef(90.0,0.0,1.0,0.0);
	glRotatef(-20.0,1.0,0.0,0.0);
	DesenhaBarra(3.0,93.5);

	glTranslatef(0.0,-28.0, -6.0);
	glRotatef(-10.0,1.0,0.0,0.0);
	DesenhaBarra(3.0,100.5);
	
	glPopMatrix();

	
	//**************************Outra roda.*************************************\\
	
	glPushMatrix();
	
	glTranslatef(85.0, -60.0, -2.0);
    glRotatef(30*deg, 0.0f, 0.0f, 1.0f);
	DesenhaRoda(30.0,8.0);
	DesenhaPneu();

	glPopMatrix();

	glPushMatrix();

	glTranslatef(0.0,9.5,-3.0);
	glRotatef(90.0,1.0,0.0,0.0);
	DesenhaBanco();

	glPopMatrix();
	
	glPushMatrix();

	glTranslatef(85.0,30.0,-40.0);	
	DesenhaGuidon(2.0,80.0);

	glPopMatrix();

	glPushMatrix();

	glTranslatef(0.0,-60.0,2.0);
	DesenhaEngrenagenRoda();

	glPopMatrix();

	glPushMatrix();

	glTranslatef(85.0,-60.0,-2.0);
	DesenhaEngrenagenRoda();

	glPopMatrix();

	glPushMatrix();

	glTranslatef(-85.0,-60.0,-10.0);
	DesenhaEngrenagenRoda();

	glPopMatrix();

	glPushMatrix();

	glTranslatef(-85.0,-60.0,-15.0);
	DesenhaBarra(2.0,7.5);

	glPopMatrix();

	glPushMatrix();

	glTranslatef(85.0,-60.0,-7.0);
	DesenhaBarra(2.0,7.5);

	glPopMatrix();

	glPopMatrix();
	
	glutSwapBuffers();
}

void SetupRC(){

	// Black background
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f );

	// Set drawing color to green
	glColor3f(0.0f, 1.0f, 0.0f);

	// Set color shading model to flat
	glShadeModel(GL_FLAT);
	
}

void SpecialKeys(int key, int x, int y)
	{
	if(key == GLUT_KEY_UP)
		xRot -= 1.0f;

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


void ChangeSize(int w, int h){

	GLfloat nRange = 100.0f;

	if(h == 0)
		h = 1;

	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	if (w <= h) 
		glOrtho (-nRange, nRange, -nRange*h/w, nRange*h/w, -nRange, nRange);
    else 
		glOrtho (-nRange*w/h, nRange*w/h, -nRange, nRange, -nRange, nRange);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y)
{
   switch (key) {
   case 27:
   case 113:
   case 'Q':
     exit(0);
     break;
   }
}


void TimerFunction (int value) {
  
  deg++;
  glutPostRedisplay();
  glutTimerFunc(33,TimerFunction, value);

}


int main(int argc, char* argv[])
	{
	glutInit(&argc, argv);
	glutInitWindowSize(800,640);
  
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("Roda Automatica");
	
	glutReshapeFunc(ChangeSize);
	glutSpecialFunc(SpecialKeys);
	glutKeyboardFunc(keyboard);
	glutDisplayFunc(RenderScene);
	//glutTimerFunc(330, TimerFunction, 1);

	SetupRC();
	glutMainLoop();

	return 0;
}