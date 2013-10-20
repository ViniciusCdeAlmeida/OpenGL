#include <GL/freeglut.h>


// Rotation amounts
static GLfloat xRot = 0.0f;
static GLfloat yRot = 0.0f;

void DesenhaPiramide() {
  glBegin(GL_TRIANGLE_FAN);
  glColor3f(1.0f, 1.0f, 0.0f);  
  glVertex3f( 0.0,   50.0, 0.0);   //V0 ápice
  glVertex3f(-50.0,   0.0, 50.0);  //V1
  glVertex3f( 50.0,   0.0, 50.0);  //V2 fim face frontal
  glColor3f(0.0f, 1.0f, 1.0f);
  glVertex3f( 50.0,   0.0, -50.0); //V3 face lateral direita
  glColor3f(0.2f, 1.2f, 0.0f);
  glVertex3f(-50.0,   0.0, -50.0); //V4 face posterior
  glColor3f(1.0f, 0.0f, 1.0f); 
  glVertex3f(-50.0,   0.0,  50.0); //V5 face lateral esquerda
  glEnd();

  glBegin(GL_QUADS);// início da base da pirâmide
  glColor3ub(75, 215, 125);
  glVertex3f(-50, 0,  50);
  glVertex3f(-50, 0, -50);
  glVertex3f( 50, 0, -50);
  glVertex3f( 50, 0,  50);
  glEnd();

  glBegin(GL_TRIANGLE_FAN);
  glColor3f(1.0f, 0.0f, 0.0f);  
  glVertex3f( 0.0,   -50.0, 0.0);   //V0 ápice
  glVertex3f(50.0,   0.0, -50.0);  //V1
  glVertex3f( -50.0,   0.0, -50.0);  //V2 fim face frontal
  glColor3f(0.0f, 1.0f, 0.0f);
  glVertex3f( -50.0,   0.0, 50.0); //V3 face lateral direita
  glColor3f(0.0f, 0.0f, 1.0f);
  glVertex3f(50.0,   0.0, 50.0); //V4 face posterior
  glColor3f(1.0f, 0.0f, 1.0f); 
  glVertex3f(50.0,   0.0,  -50.0); //V5 face lateral esquerda
  glEnd();
}

//----------------------------MEXER NO PLANO 'Z'.-----------------------------------------------

/*void DesenhaPiramide(void) {
  glBegin(GL_TRIANGLE_STRIP);
  glColor3f(1.0f, 1.0f, 0.0f);  
  glVertex3f( 50.0, 0.0, 0.0);   //V0 ápice
  glVertex3f( 0.0, 50.0, 0.0);  //V1
  glVertex3f( 0.0, 0.0, 0.0);  //V2 fim face frontal
  glColor3f(0.0f, 1.0f, 1.0f);
  glVertex3f(-50.0, 0.0, 0.0); //V3 face lateral direita
  glColor3f(0.2f, 1.2f, 0.0f);
  glVertex3f(0.0, -50.0, 0.0); //V4 face posterior
  glColor3f(1.0f, 0.0f, 1.0f); 
  glVertex3f(50.0, 0.0, 0.0); //V5 face lateral esquerda 
  glEnd();

  glBegin(GL_QUADS);// início da base da pirâmide
  glColor3ub(75, 215, 125);
  glVertex3f(-50, 0,  50);
  glVertex3f(-50, 0, -50);
  glVertex3f( 50, 0, -50);
  glVertex3f( 50, 0,  50);
  glEnd();

  glBegin(GL_TRIANGLE_FAN);
  glColor3f(1.0f, 0.0f, 0.0f);  
  glVertex3f( 0.0,   -50.0, 0.0);   //V0 ápice
  glVertex3f(50.0,   0.0, -50.0);  //V1
  glVertex3f( -50.0,   0.0, -50.0);  //V2 fim face frontal
  glColor3f(0.0f, 1.0f, 0.0f);
  glVertex3f( -50.0,   0.0, 50.0); //V3 face lateral direita
  glColor3f(0.0f, 0.0f, 1.0f);
  glVertex3f(50.0,   0.0, 50.0); //V4 face posterior
  glColor3f(1.0f, 0.0f, 1.0f); 
  glVertex3f(50.0,   0.0,  -50.0); //V5 face lateral esquerda
  glEnd();
}*/


// Called to draw scene
void RenderScene() {

  // Clear the window and the depth buffer
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glPolygonMode(GL_BACK,GL_LINE);
  glPolygonMode(GL_FRONT,GL_LINE);
	
  
  glPushMatrix();
  glTranslatef(70.0, -0.5, 0.0);

  glRotatef(xRot, 1.0f, 0.0f, 0.0f);
  //glRotatef(yRot, 0.0f, 1.0f, 0.0f);
  glRotatef(yRot, 0.0f, 0.0f, 1.0f); //TRAVAR NO EIXO 'Z'.
  //****************
  DesenhaPiramide();
  //****************
  glPopMatrix();
  

  glPushMatrix();
  glTranslatef(-70.0, -0.5, 0.0);

  glRotatef(xRot, 1.0f, 0.0f, 0.0f);
  //glRotatef(yRot, 0.0f, 1.0f, 0.0f);
  glRotatef(yRot, 0.0f, 0.0f, 1.0f); //TRAVAR NO EIXO 'Z'.
  //****************
  DesenhaPiramide();
  //****************
  glPopMatrix();

   
  glutSwapBuffers();
}


// This function does any needed initialization 
// on the rendering context. 
void SetupRC()	{
  // Cor de fundo cinza médio
  //glClearColor(0.5f, 0.5f, 0.5f, 1.0f );
  // Chaveia o modo de colorir para "cor única"
  glShadeModel(GL_FLAT);
  // Habilita o teste de profundidade
  glEnable(GL_DEPTH_TEST);

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


void ChangeSize(int w, int h){
  GLfloat nRange = 100.0f;

  // Evita a divisão por zero
  if(h == 0)
    h = 1;

  // Set Viewport to window dimensions
  glViewport(0, 0, w, h);

  // Reset projection matrix stack
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  // Establish clipping volume (left, right, bottom, top, near, far)
  if (w <= h) 
    glOrtho (-nRange, nRange, -nRange*h/w, nRange*h/w, -nRange, nRange);
  else  
    glOrtho (-nRange*w/h, nRange*w/h, -nRange, nRange, -nRange, nRange);

  // Reset Model view matrix stack
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
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

void TimerFunction (int value) {
  static GLfloat deg = 0.0f;

  if (value == 1)   
    {
      glRotatef(deg, 0.0f, 0.0f, 1.0f);
      if (deg == 3600) 
	{
	  value = 1;
	  deg = 10.0;
	}
    }
  else 
    {
      glRotatef(deg, 0.0f, 0.0f, 0.0f);
      if (deg == 36) 
	{
	  value = 1;
	  deg = 0.0;
	}
    }
  //DesenhaPiramide();
  deg++;
  //deg = deg + 1.0;
  // Redraw the scene with new coordinates
  glutPostRedisplay();
  glutTimerFunc(33,TimerFunction, value);

}


int main(int argc, char* argv[]) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize(800,640);
  glutCreateWindow("Triangulos 3D Automaticos");
	

  glutReshapeFunc(ChangeSize);
  glutKeyboardFunc(keyboard);
  glutSpecialFunc(SpecialKeys);
  glutDisplayFunc(RenderScene);
  glutTimerFunc(33, TimerFunction, 1);



  SetupRC();


  glutMainLoop();

  return 0;
}