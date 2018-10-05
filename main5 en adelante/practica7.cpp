//Semestre 2017 - 2
//************************************************************//
//************************************************************//
//************** Alumno (s): Basilio Torres Carlos Alberto****//
//*************	Practica: 7							******//
//*************	Version de visual estudio: 2017         ******//
//************************************************************//
#include "Main.h"

/*
	flechas ariba y abajo hacen una rotacion en y
	flechas izquierda y derecha hacen rotacion en x
	a y d hacen traslacion en x
	s y w hacen traslacion en z
*/

// Variables used to calculate frames per second: (Windows)
DWORD dwFrames = 0;
DWORD dwCurrentTime = 0;
DWORD dwLastUpdateTime = 0;
DWORD dwElapsedTime = 0;


//Variables used to create movement

int sol = 0;
int venus = 0;
int mercurio = 0;
int marte = 0;
int tierra = 0;
int jupiter = 0;
int saturno = 0;
int urano = 0;
float ejey = 0.0f, ejex = 0.0f;
float camaraZ = 0.0;
float camaraX = 0.0;


GLfloat SunAmbiental[] = { 1.0f , 1.0f, 1.0f, 1.0f };
GLfloat SunDiffuse[] = { 1.0f, 0.0f, 0.0f, 1.0f };			// Diffuse Light Values
GLfloat SunSpecular[] = { 0.0, 0.0, 0.0, 1.0 };				// Specular Light Values
GLfloat SunPosition[] = { 0.0f, 0.0f, 0.0f, 0.0f };			// Light Position

GLfloat MercAmbient[] = { 0.39225f,0.29225f,0.29225f,1.0f };
GLfloat MercDiffuse[] = { 0.50754f, 0.50754f, 0.50754f, 1.0f };			// materiales de mercurio
GLfloat MercSpecular[] = { 0.908273f, 0.908273f, 0.908273f, 1.0f };
GLfloat MercShininess[] = { 1.0 };

GLfloat VenAmbient[] = { 0.2125f,0.1275f,0.054f,1 };
GLfloat VenDiffuse[] = { .714f, 0.4284f, 0.18144f, 1.0f };			// materiales de venus
GLfloat VenSpecular[] = { 0.393548f, 0.271906f, 0.166721f, 1.0 };
GLfloat VenShininess[] = { 20 };

GLfloat EarthAmbient[] = { 0.0f,.65f,1.0f,1.0f };
GLfloat EarthDiffuse[] = { 0.2f, 0.2f, 1.0f, 1.0f };			// Materiales de la tierra
GLfloat EarthSpecular[] = { 0.8f, 0.8f, 0.8f, 1.0f };
GLfloat EarthShininess[] = { 50.0f };

GLfloat MoonAmbient[] = { 1.0f,1.0f,1.0f,1.0f };
GLfloat MoonDiffuse[] = { 0.2f, 0.2f, 1.0f, 1.0f };			// Materiales de la luna
GLfloat MoonSpecular[] = { 0.8f, 0.8f, 0.8f, 1.0f };
GLfloat MoonShininess[] = { 50.0 };

GLfloat MarsAmbient[] = { 1,1,1,1 };
GLfloat MarsDiffuse[] = { 0.8f, 0.4f, 0.1f, 1.0f };			// Materiales de marte
GLfloat MarsSpecular[] = { 1.0, 0.5, 0.0, 1.0 };
GLfloat MarsShininess[] = { 50.0 };

void InitGL(GLvoid)     // Inicializamos parametros
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	//Acondicionamos la luz que vamos a utilizar
	glLightfv(GL_LIGHT1, GL_AMBIENT, SunAmbiental);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, SunDiffuse);
	glLightfv(GL_LIGHT1, GL_SPECULAR, SunSpecular);
	glEnable(GL_LIGHT1);
}


void display(void)   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	glTranslatef(camaraX, 0.0, -5.0 + camaraZ);			//camara

	glLightfv(GL_LIGHT1, GL_POSITION, SunPosition);
	glRotatef(ejey, 0, 0, 1);
	glRotatef(ejex, 1, 0, 0);

	glPushMatrix();

	glRotatef(sol, 0.0, 1.0, 0.0);	//El Sol gira sobre su eje

	glPushMatrix();
	glDisable(GL_LIGHTING);
	glColor3f(1.0, 1.0, 0.0);	//Sol amarillo
	glutSolidSphere(2.0, 12, 12);  //radio de 2 unidades;
	glEnable(GL_LIGHTING);


	glPushMatrix();//mercurio
		glRotatef(2 * sol, 0.0, 1.0, 0.0); //traslacion a una velocidad de 2 veces la velocidad del sol
		glTranslatef(-3.2, 0, 0);
		glRotatef(mercurio, 0.0, 1.0, 0.0);
		//definimos los  materiales de nuestro planeta
		glMaterialfv(GL_FRONT, GL_AMBIENT, MercAmbient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE,MercDiffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, MercSpecular);
		glMaterialfv(GL_FRONT, GL_SHININESS, MercShininess);
		glutSolidSphere(.3, 30, 30);  //radio de .3 unidades
	glPopMatrix();

	glPushMatrix();//venus
	glRotatef(3 * sol, 0.0, 1.0, 0.0);//traslacion a una velocidad de 3 veces la velocidad del sol
	glTranslatef(4.5, 0, 0);
	glRotatef(venus, 0.0, 1.0, 0.0);
	//definimos los  materiales de nuestro planeta
	glMaterialfv(GL_FRONT, GL_AMBIENT, VenAmbient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, VenDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, VenSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, VenShininess);
	glutSolidSphere(.5, 15, 15);  //radio de .5 unidades;
	glPopMatrix();

	glPushMatrix();//tierra
	glRotatef(4 * sol, 0.0, 1.0, 0.0);//traslacion a una velocidad de 4 veces la velocidad del sol
	glTranslatef(-7, 0, 0);
	glRotatef(tierra, 0.0, 1.0, 0.0);
	glColor3f(0, 0.6, 1);	//planeta azul
	//definimos los  materiales de nuestro planeta
	glMaterialfv(GL_FRONT, GL_AMBIENT, EarthAmbient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, EarthDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, EarthSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, EarthShininess);
	glutSolidSphere(.5, 10, 10);  //radio de .5 unidades;

		glPushMatrix();//luna de la tierra
			glRotatef(.4 * tierra, 0.0, 1.0, 0.0);//traslacion a una velocidad de .4 veces la velocidad de la tierra
			glTranslatef(.9, 0, 0);
			glRotatef(tierra, 0.0, 1.0, 0.0);
			//definimos los  materiales de nuestra luna
			glMaterialfv(GL_FRONT, GL_AMBIENT, MoonAmbient);
			glMaterialfv(GL_FRONT, GL_DIFFUSE, MoonDiffuse);
			glMaterialfv(GL_FRONT, GL_SPECULAR, MoonSpecular);
			glMaterialfv(GL_FRONT, GL_SHININESS, MoonShininess);
			glutSolidSphere(.15, 10, 10);  //radio de .15 unidades;	
		glPopMatrix();
	glPopMatrix();

	glPushMatrix();//marte
	glRotatef(1.6*sol, 0.0, 1.0, 0.0);//traslacion a una velocidad de 1.6 veces la velocidad del sol
	glTranslatef(11, 0, 0);
	glRotatef(marte, 0.0, 1.0, 0.0);
	glColor3f(1, 0.2, 0);	//planeta rojo
	glutSolidSphere(.4, 9, 9);  //radio de .4 unidades;

	glPushMatrix();//luna de marte
	glRotatef(.00001 * marte, 0.0, 1.0, 0.0); //traslacion a una velocidad de .00001 veces la velocidad de marte
	glTranslatef(.9, 0, 0);
	glRotatef(marte, 0.0, 1.0, 0.0);
	glColor3f(1, 1, 1);	//luna blanca
	glutSolidSphere(.15, 10, 10);  //radio de .15 unidades	
	glPopMatrix();

	glPushMatrix();//luna de marte
	glRotatef(.0001 * marte, 0.0, 1.0, 0.0);  //traslacion a una velocidad de .0001 veces la velocidad de marte
	glTranslatef(-1.8, 0, 0);
	glRotatef(tierra, 0.0, 1.0, 0.0);
	glColor3f(1, 1, 1);	//luna blanca
	glutSolidSphere(.15, 10, 10);  //radio de .15 unidades	
	glPopMatrix();

	glPopMatrix();

	glPushMatrix();//jupiter
	glRotatef(5 * sol, 0.0, 1.0, 0.0); //traslacion a una velocidad de 5 veces la velocidad del sol
	glTranslatef(-16, 0, 0);
	glRotatef(jupiter, 0.0, 1.0, 0.0);
	glColor3f(1, .85, 0.7);	//planeta cafe
	glutSolidSphere(1.0, 8, 8);  //radio una unidad

	glPushMatrix();//luna de jupiter
	glRotatef(.1 * jupiter, 0.0, 1.0, 0.0);//traslacion a una velocidad de .1 veces la velocidad de jupiter
	glTranslatef(-1.5, 0, 0);
	glRotatef(tierra, 0.0, 1.0, 0.0);
	glColor3f(1, 1, 1);	//luna blanca
	glutSolidSphere(.15, 10, 10);  //radio de .15 unidades 
	glPopMatrix();

	glPushMatrix();//luna de jupiter
	glRotatef(.5 * jupiter, 0.0, 1.0, 0.0); //traslacion a una velocidad de .5 veces la velocidad de jupiter
	glTranslatef(1.9, 0, 0);
	glRotatef(tierra, 0.0, 1.0, 0.0);
	glColor3f(1, 1, 1);	//luna blanca
	glutSolidSphere(.15, 10, 10);  //rdio de .15 unidades	
	glPopMatrix();

	glPushMatrix();//luna de jupiter
	glRotatef(.3 * jupiter, 0.0, 1.0, 0.0);//traslacion a una velocidad de .3 veces la velocidad de jupiter
	glTranslatef(2.1, 0, 2);
	glRotatef(tierra, 0.0, 1.0, 0.0);
	glColor3f(1, 1, 1);	//luna blanca
	glutSolidSphere(.15, 10, 10);  //radio de .15 unidades
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();//saturno
	glRotatef(2.0*sol, 0.0, 1.0, 0.0);//traslacion a una velocidad de 2 veces la velocidad del sol
	glTranslatef(21, 0, 0);
	glRotatef(saturno, 0.0, 1.0, 0.0);
	glColor3f(0.713, 0.427, 0.2186);	//planeta cafe
	glutSolidSphere(.9, 20, 20);  //radio de .9 unidades

	glPushMatrix();
	glRotated(90, 1, 0, 0); // se rota 90 grados
	glColor3f(1, 1, 1);//color blanco
	glutSolidTorus(.03, 1.3, 20, 20); //toroide de .03 unidades de radio interno y 1.3 unidades de radio externo
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();//urano
	glRotatef(sol, 0.0, 1.0, 0.0);//traslacion a la velocidad del sol
	glTranslatef(-25.6, 0, 0);
	glRotatef(urano, 0.0, 1.0, 0.0);
	glColor3f(0.02745, 0.8, 0.9215);	//planeta azul
	glutSolidSphere(.8, 100, 100);  //radio de .8 unidades
	glPopMatrix();
	glPopMatrix();
	glutSwapBuffers();

}

void animacion()
{
	// Calculate the number of frames per one second:
	//dwFrames++;
	dwCurrentTime = GetTickCount(); // Even better to use timeGetTime()
	dwElapsedTime = dwCurrentTime - dwLastUpdateTime;

	if (dwElapsedTime >= 60)
	{
		/*
		Para las rotaciones, para evitar un desborde de memoria se realizo lo siguiente
		se decrementa el valor de la variable sol constntemente en uno, hsta llegar en -360 grados,
		al llegar a dicho valor se resetean todas las varibles.
		*/
		if (sol > -360)
		{
			sol = ( sol - 1);
			mercurio = (mercurio - 5);
			venus = (venus - 5);
			tierra = (tierra - 8);
			marte = (marte - 20);
			jupiter = (jupiter - 8);
			saturno = (saturno - 9);
			urano = (urano - 10);
		}
		else {
			sol = 0;
			mercurio = 0;
			venus = 0;
			tierra = 0;
			marte = 0;
			jupiter = 0;
			saturno = 0;
			urano = 0;
		}


		dwLastUpdateTime = dwCurrentTime;
	}

	glutPostRedisplay();
}

void reshape(int width, int height)   // Creamos funcion Reshape
{
	if (height == 0)										// Prevenir division entre cero
	{
		height = 1;
	}

	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista

	glFrustum(-0.1, 0.1, -0.1, 0.1, 0.1, 50.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
														//glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y)  // Create Keyboard Function
{
	switch (key) {
	case 'w':   //Movimientos de camara
	case 'W':
		camaraZ += 0.5f;
		break;
	case 's':
	case 'S':
		camaraZ -= 0.5f;
		break;
	case 'a':
	case 'A':
		camaraX -= 0.5f;
		break;
	case 'd':
	case 'D':
		camaraX += 0.5f;
		break;

	case 'i':		//Movimientos de Luz
	case 'I':

		break;
	case 'k':
	case 'K':

		break;

	case 'l':   //Activamos/desactivamos luz
	case 'L':
		break;
	case 27:        // Cuando Esc es presionado...
		exit(0);   // Salimos del programa
		break;
	default:        // Cualquier otra
		break;
	}
	glutPostRedisplay();
}

void arrow_keys(int a_keys, int x, int y)  // Funcion para manejo de teclas especiales (arrow keys)
{
	switch (a_keys) {
	case GLUT_KEY_UP:
		// Presionamos tecla ARRIBA...
		ejex += 1.0f;
		break;
	case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
		ejex -= 1.0f;
		break;
	case GLUT_KEY_LEFT:
		ejey -= 1.0f;
		break;
	case GLUT_KEY_RIGHT:
		ejey += 1.0f;
		break;
	default:
		break;
	}
	glutPostRedisplay();
}


int main(int argc, char** argv)   // Main Function
{
	glutInit(&argc, argv); // Inicializamos OpenGL
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
	glutInitWindowSize(500, 500);	// Tamaño de la Ventana
	glutInitWindowPosition(20, 60);	//Posicion de la Ventana
	glutCreateWindow("Practica 6"); // Nombre de la Ventana
	InitGL();						// Parametros iniciales de la aplicacion
	glutDisplayFunc(display);  //Indicamos a Glut función de dibujo
	glutReshapeFunc(reshape);	//Indicamos a Glut función en caso de cambio de tamano
	glutKeyboardFunc(keyboard);	//Indicamos a Glut función de manejo de teclado
	glutSpecialFunc(arrow_keys);	//Otras
	glutIdleFunc(animacion);
	glutMainLoop();          // 

	return 0;
}
