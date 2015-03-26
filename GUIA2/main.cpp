
#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <stdlib.h>


void init(void)
{
glEnable(GL_LIGHTING);//Activar el modelo de iluminació
glEnable(GL_LIGHT0); //Activamos las luces en 0
glDepthFunc(GL_LESS); //comparación de profundidad
glEnable(GL_DEPTH_TEST); //activa GL_DEPTH_TEST

}
void ponerMaterial (GLfloat A1,GLfloat A2,GLfloat A3,GLfloat B1,GLfloat B2,GLfloat B3,GLfloat C1,GLfloat C2, GLfloat C3, GLfloat D)
{

GLfloat mat_ambient[]= {A1,A2,A3,1.0f};
GLfloat mat_diffuse[] = { B1,B2,B3,1.0f };
GLfloat mat_specular[] = { C1,C2,C3,1.0f };
GLfloat shine[] = {D};
 glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
glMaterialfv(GL_FRONT, GL_SHININESS, mat_specular);
glMaterialfv(GL_FRONT, GL_SHININESS, shine);


    glFlush();
}

void TECLADO(unsigned char key, int x, int y)
{
    //ABRIMOS UN SWITCH PARA PODER COLOCAR EVENTO EN CASO DE TECLEAR ALGUNO DE LAS LETRAS QUE SE MOSTRARA A CONTINUACION
    switch (key)
    {
            case 49:ponerMaterial( 0.135 ,0.2225,0.1575 ,0.54,0.89,0.63,0.316228, 0.316228,0.316228,0.1);
                    break;//JADE
            case 50:ponerMaterial( 0.05375, 0.05, 0.06625,0.18275,0.17,0.22525 ,0.332741, 0.328634,0.346435,0.3);
                    break;//obsidian
            case 51:ponerMaterial(0.25, 0.20725,0.20725,1,0.829,0.829,0.296648 ,0.296648 ,0.296648 ,0.088);
                    break;//pearl
            case 52:ponerMaterial( 0.1745 , 0.01175 , 0.01175,0.61424, 0.04136,0.04136,0.727811, 0.626959 ,0.626959 , 0.6);
                    break;//ruby
            case 53:ponerMaterial( 0.1, 0.18725,0.1745,0.396 ,0.74151,0.69102,0.297254 ,0.30829, 0.306678 ,0.1);
                    break;// turquoise
    }
    glutPostRedisplay();//ACTUALIZANDO VENTANA
}

void reshape(int w, int h)
{
    glViewport(0, 0,  (GLsizei) w, (GLsizei) h);
// Activamos la matriz de proyeccion.
    glMatrixMode(GL_PROJECTION);
// "limpiamos" esta con la matriz identidad.
    glLoadIdentity();
// Usamos proyeccion ortogonal
    glOrtho(-300, 300, -300, 300, -300, 300);
// Activamos la matriz de modelado/visionado.
    glMatrixMode(GL_MODELVIEW);
// "Limpiamos" la matriz
    glLoadIdentity();



}

void display(void)
{

// "Limpiamos" el frame buffer con el color de "Clear", en este
// caso negro.
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode( GL_MODELVIEW_MATRIX );
    glLoadIdentity();

// Rotacion de 25 grados en torno al eje x
    glRotated(25.0, 1.0, 0.0, 0.0);
// Rotacion de -30 grados en torno al eje y
    glRotated(-30.0, 0.0, 1.0, 0.0);
// Dibujamos una "Tetera" y le aplico el material
    glPushMatrix();
//setMaterial

//GLfloat matambient[] = { 0.329412f, 0.223529f, 0.027451f,1.0f };
//glMaterialfv(GL_FRONT, GL_AMBIENT, matambient);
//SE OBSERVA MAYOR PROFUNDIDAD Y DEFINICION DE LINEAS DE DIBUJO

//GLfloat matdiffuse[] = { 0.780392f, 0.568627f, 0.113725f, 1.0f };
//glMaterialfv(GL_FRONT, GL_DIFFUSE, matdiffuse);
//SE VE EL CAMBIO DECOLOR SE NOTA MASCLARO

//GLfloat matspecular[] = { 0.992157f, 0.941176f, 0.807843f, 1.0f };
//glMaterialfv(GL_FRONT, GL_SPECULAR, matspecular);
//ELCOLOR SE VUELVE MAS CLARO PERDIENDO EL DORADO QUE TENIA

//GLfloat shines[] = {27.8974f};
//glMaterialfv(GL_FRONT, GL_SHININESS, shines);
//SE VE QUE SE FORMA UNA ESPECIE DE BRILLO EN LA TASA Y ESTA RECUPERA EL TONO DORADO
    glutSolidTeapot(125.0);

    glFlush();

}


int main(int argc, char **argv)
{
// Inicializo OpenGL
    glutInit(&argc, argv);

// Activamos buffer simple y colores del tipo RGB
    glutInitDisplayMode (GLUT_RGB | GLUT_DEPTH);

// Definimos una ventana de medidas 800 x 600 como ventana
// de visualizacion en pixels
    glutInitWindowSize (800, 600);

// Posicionamos la ventana en la esquina superior izquierda de
// la pantalla.
    glutInitWindowPosition (0, 0);

// Creamos literalmente la ventana y le adjudicamos el nombre que se
// observara en su barra de titulo.
    glutCreateWindow ("Tetera");

// Inicializamos el sistema
    init();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(TECLADO);
    glutMainLoop();
   return 0;
}
