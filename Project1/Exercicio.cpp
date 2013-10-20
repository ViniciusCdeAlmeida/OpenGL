#include <GL/freeglut.h> 
 
// Tamanho da estrela 
static GLfloat size = 0.6f; 
 
 
// Called to draw scene 
void RenderScene(void) { 
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
 
  // Reset the modelview matrix 
  glMatrixMode(GL_MODELVIEW); 
  glLoadIdentity();
 
  // Translate the whole scene out and into view	 
  // This is the initial viewing transformation 
  //glTranslatef(0.0f, 0.0f, -100.0f);	 
  glutSolidSphere(size, 50, 50);
  //Mostre a imagem da estrela de tamanho size 
  glutSwapBuffers();
}
 
 

void SetupRC() { 
  glEnable(GL_DEPTH_TEST);	
  glFrontFace(GL_CCW);		
  glEnable(GL_CULL_FACE);	  
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f );
  glColor3f(85.0,95.0,0.0);	 
} 
 
 
void TimerFunc(int value) { 
  size++;
  glutPostRedisplay();
  glutTimerFunc(100, TimerFunc, 1); 
}
 
 
void ChangeSize(int w, int h) { 
  // Previne a divisao por zero 
  if(h == 0) h = 1; 
 
  // Redimensiona as dimensoes da janela de visualizacao
  glViewport(0, 0, w, h);
  GLfloat aspecto =  (GLfloat) w/(GLfloat) h;
 
  // Resseta o sistema de coordenadas
  glMatrixMode(GL_PROJECTION); 
  glLoadIdentity(); 
 // gluPerspective(45.0, aspecto, 1.0, 500.0);
 
  glMatrixMode(GL_MODELVIEW); 
  glLoadIdentity(); 
}
 
int main(int argc, char* argv[]) {
  glutInit(&argc, argv); 
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); 
  glutInitWindowSize(800, 600);
  glutCreateWindow("Iluminacao"); 
  glutReshapeFunc(ChangeSize); 
  glutDisplayFunc(RenderScene);
  glutTimerFunc(500, TimerFunc, 1); 
  SetupRC();
  glutMainLoop(); 
 
  return 0;
}