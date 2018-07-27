#include<gl/freeglut.h>
#include<math.h>
#include <SOIL.h>
#include <iostream>
using namespace std;
// angle of rotation for the camera direction
float angle = 0.0;
// actual vector representing the camera's direction
float lx = 0.0f, lz = -1.0f;
// XZ position of the camera
float x = 0.0f, z = 30.0f;

static GLint fogMode;
GLuint startList;
GLfloat ctrlpoints[4][3] = {
	{ -3, 2.7, -3 },{ -2.5, 3.0, -3 },
	{ -2, 0, -3 },{ 3, 2.7, -3 } };

GLfloat colctrlpoints[4][4] = {
	{ 1.0, 1.0, 0.0,1.0 },{ 0.9, 0.5, 0.0, 1.0 },
	{ 0.2, 0.4, 0.3, 1.0 },{ 0.0, 0.0, 1.0, 1.0 } };

void init(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glShadeModel(GL_SMOOTH);
	glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 4, &ctrlpoints[0][0]);
	glMap1f(GL_MAP1_COLOR_4, 0.0, 1.0, 4, 4, &colctrlpoints[0][0]);
	glEnable(GL_MAP1_VERTEX_3);
	glEnable(GL_MAP1_COLOR_4);
}

void changeSize(int w, int h)
{
	if (h == 0)
		h = 1;
	float ratio = w * 1.0 / h;

	// Use the Projection Matrix
	glMatrixMode(GL_PROJECTION);

	// Reset Matrix
	glLoadIdentity();

	// Set the viewport to be the entire window
	glViewport(0, 0, w, h);

	// Set the correct perspective.
	gluPerspective(45.0f, ratio, 0.1f, 300);

	// Get Back to the Modelview
	glMatrixMode(GL_MODELVIEW);
}

GLuint texture1;
GLuint texture2;
GLuint texture3;
GLuint texture4;
GLuint texture5;


void LoadTexture1(void)
{
	glGenTextures(1, &texture1);
	glBindTexture(GL_TEXTURE_2D, texture1);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);	// Set texture wrapping to GL_REPEAT
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	int width, height;
	unsigned char* image = SOIL_load_image("Daylight Box_Front.bmp", &width, &height, 0, SOIL_LOAD_RGB);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
	

}
void LoadTexture2(void)
{
	glGenTextures(1, &texture2);
	glBindTexture(GL_TEXTURE_2D, texture2);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);	// Set texture wrapping to GL_REPEAT
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	int width, height;
	unsigned char* image = SOIL_load_image("Daylight Box_Back.bmp", &width, &height, 0, SOIL_LOAD_RGB);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
	// SOIL_free_image_data(image);
	// glBindTexture(GL_TEXTURE_2D, 0);

}
void LoadTexture3(void)
{
	glGenTextures(1, &texture3);
	glBindTexture(GL_TEXTURE_2D, texture3);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);	// Set texture wrapping to GL_REPEAT
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	int width, height;
	unsigned char* image = SOIL_load_image("Daylight Box_Left.bmp", &width, &height, 0, SOIL_LOAD_RGB);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
	// SOIL_free_image_data(image);
	// glBindTexture(GL_TEXTURE_2D, 0);

}
void LoadTexture4(void)
{
	glGenTextures(1, &texture4);
	glBindTexture(GL_TEXTURE_2D, texture4);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);	// Set texture wrapping to GL_REPEAT
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	int width, height;
	unsigned char* image = SOIL_load_image("Daylight Box_Right.bmp", &width, &height, 0, SOIL_LOAD_RGB);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);

}
void LoadTexture5(void)
{
	glGenTextures(1, &texture5);
	glBindTexture(GL_TEXTURE_2D, texture5);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);	// Set texture wrapping to GL_REPEAT
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	int width, height;
	unsigned char* image = SOIL_load_image("g.jpg", &width, &height, 0, SOIL_LOAD_RGB);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
	// SOIL_free_image_data(image);
	// glBindTexture(GL_TEXTURE_2D, 0);

}
void drawFlowers() {

	glColor3f(1.0f, 1.0f, 1.0f);

	// tulpina
	glPushMatrix();
	glColor3f(0, 0.5, 0);

	glTranslatef(0, 0, 0);
	glRotatef(-90, 1, 0, 0);
	glutSolidCone(0.06f, 0.5f, 20, 2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, -0.1, 0.0);
	// mijloc
	glPushMatrix();
	glColor3f(0.85, 0.85, 0.10);
	glTranslatef(0.0f, 0.7f, 0.0f);
	glutSolidCylinder(0.055f, 0.115, 20, 10);
	glPopMatrix();

	// Draw petala
	glPushMatrix();
	glColor3f(0.858824, 0.439216, 0.858824);
	glTranslatef(0.0f, 0.8f, 0.0f);
	glutSolidSphere(0.125f, 20, 10);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.00, 0.43, 0.78);
	glTranslatef(0.1f, 0.6f, 0.0f);
	glutSolidSphere(0.125f, 20, 10);
	glPopMatrix();


	glPushMatrix();
	glColor3f(1.0f, 0.5f, 0.5f);
	glTranslatef(-0.1f, 0.6f, 0.0f);
	glutSolidSphere(0.125f, 20, 10);
	glPopMatrix();

	glPopMatrix();
}


void drawBrad() {

	glColor3f(1.0f, 1.0f, 1.0f);

	// tulpina
	glPushMatrix();
	glColor3f(0.545, 0.271, 0.075);

	glTranslatef(0, 0, 0);
	glRotatef(-90, 1, 0, 0);
	glutSolidCone(0.1f, 2, 4, 2);
	glPopMatrix();

	//frunza1
	glPushMatrix();
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	GLfloat pozitial0[] = { 10, 10, 200.0, 0.0 };
	glLightfv(GL_LIGHT0, GL_POSITION, pozitial0);
	GLfloat alb[] = { 0.000, 0.392, 0.000, 0.0 };
	glLightfv(GL_LIGHT0, GL_DIFFUSE, alb);

	glColor3f(0.000, 0.392, 0.000);

	glTranslatef(0, 1.8, 0);
	glRotatef(-90, 1, 0, 0);
	glutSolidCone(0.5f, 1, 7, 2);
	glDisable(GL_LIGHTING);
	glPopMatrix();

	//frunza2
	glPushMatrix();
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	//GLfloat pozitial0[] = { 10, 10, 200.0, 0.0 };
	glLightfv(GL_LIGHT0, GL_POSITION, pozitial0);
	//GLfloat alb[] = { 0.000, 0.392, 0.000, 0.0 };
	glLightfv(GL_LIGHT0, GL_DIFFUSE, alb);
	glColor3f(0.000, 0.392, 0.000);

	glTranslatef(0, 1, 0);
	glRotatef(-90, 1, 0, 0);
	glutSolidCone(0.8f, 1.2, 7, 2);
	glDisable(GL_LIGHTING);
	glPopMatrix();

	//frunza3
	glPushMatrix();
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	//GLfloat pozitial0[] = { 10, 10, 200.0, 0.0 };
	glLightfv(GL_LIGHT0, GL_POSITION, pozitial0);
	//GLfloat alb[] = { 0.000, 0.392, 0.000, 0.0 };
	glLightfv(GL_LIGHT0, GL_DIFFUSE, alb);
	glColor3f(0.000, 0.392, 0.000);

	glTranslatef(0, 0.5, 0);
	glRotatef(-90, 1, 0, 0);
	glutSolidCone(0.9, 1.3, 8, 2);
	glDisable(GL_LIGHTING);
	glPopMatrix();

}

void brazi(void) {
	for (int i = -50; i < 50; i = i + 2)
	{

		glPushMatrix();
		glTranslated(i, 0, 50);
		drawBrad();
		glPopMatrix();

		glPushMatrix();
		glTranslated(i + 1, 0, 53);
		drawBrad();
		glPopMatrix();
	}

	for (int i = -50; i < 50; i = i + 2)
	{

		glPushMatrix();
		glTranslated(i, 0, -50);
		drawBrad();
		glPopMatrix();

		glPushMatrix();
		glTranslated(i + 1, 0, -53);
		drawBrad();
		glPopMatrix();
	}
	for (int i = -50; i < 50; i = i + 2)
	{

		glPushMatrix();
		glTranslated(50, 0, i);
		drawBrad();
		glPopMatrix();

		glPushMatrix();
		glTranslated(53, 0, i + 1);
		drawBrad();
		glPopMatrix();
	}
	for (int i = -50; i <= 50; i = i + 2)
	{

		glPushMatrix();
		glTranslated(-50, 0, i);
		drawBrad();
		glPopMatrix();

		glPushMatrix();
		glTranslated(-53, 0, i + 3);
		drawBrad();
		glPopMatrix();
	}
}
void gard(int r) {

	if (r == 1)
	{
		glColor3f(0.545, 0.271, 0.075);
		glBegin(GL_QUADS);
		glVertex3f(0, 1, 0);
		glVertex3f(0.2, 1, 0);
		glVertex3f(0.2, 0, 0);
		glVertex3f(0, 0, 0);//7.05
		glEnd();
	}
	if (r == 2) {
		glColor3f(0.545, 0.271, 0.075);
		glBegin(GL_QUADS);
		glVertex3f(0, 1, 0);
		glVertex3f(0, 1, 0.2);
		glVertex3f(0, 0, 0.2);
		glVertex3f(0, 0, 0);//7.05
		glEnd();
	}
	if (r == 3) {
		glColor3f(0.545, 0.271, 0.075);
		glBegin(GL_QUADS);
		glVertex3f(0, 0.7, 0);
		glVertex3f(0.7, 0.7, 0);
		glVertex3f(0.7, 0.6, 0);
		glVertex3f(0, 0.6, 0);//7.05

		glVertex3f(0, 0.4, 0);
		glVertex3f(0.7, 0.4, 0);
		glVertex3f(0.7, 0.3, 0);
		glVertex3f(0, 0.3, 0);//7.05
		glEnd();
	}
	if (r == 4) {
		glColor3f(0.545, 0.271, 0.075);
		glBegin(GL_QUADS);
		glVertex3f(0, 0.4, 0);
		glVertex3f(0, 0.4, 0.7);
		glVertex3f(0, 0.3, 0.7);
		glVertex3f(0, 0.3, 0);//7.05

		glVertex3f(0, 0.7, 0);
		glVertex3f(0, 0.7, 0.7);
		glVertex3f(0, 0.6, 0.7);
		glVertex3f(0, 0.6, 0);//7.05
		glEnd();
	}
}

void drawGard(void) {
	for (float i = -4; i < 4; i = i + 0.5)
	{

		glPushMatrix();
		glTranslated(i, 0, 7.05);
		gard(1);
		gard(3);
		glPopMatrix();
	}
	for (float i = -4; i < 4; i = i + 0.5)
	{

		glPushMatrix();
		glTranslated(i, 0, -7.05);
		gard(1);
		gard(3);
		glPopMatrix();
	}

	for (float i = -7; i < 7; i = i + 0.5)
	{

		glPushMatrix();

		glTranslated(-4, 0, i);
		gard(2);
		gard(4);
		glPopMatrix();
	}
	for (float i = -7; i < 7; i = i + 0.5)
	{

		glPushMatrix();

		glTranslated(4, 0, i);
		gard(2);
		gard(4);
		glPopMatrix();
	}

	glColor3f(0.545, 0.271, 0.075);
	glBegin(GL_QUADS);
	glVertex3f(1, 1, 7.05);
	glVertex3f(2, 1, 7.05);
	glVertex3f(2, 0, 7.05);
	glVertex3f(1, 0, 7.05);//7.05
	glEnd();
}
void drawCasa()
{

	glBegin(GL_QUADS);                // Begin drawing the color cube with 6 quads
	glPushMatrix();
	glColor3f(0.933, 0.910, 0.667); // Top face (y = 1.0f)
	glTranslated(-20, 0, -20);
	// Green
	glVertex3f(3.0f, 3.0f, -3.0f);
	glVertex3f(-3.0f, 3.0f, -3.0f);
	glVertex3f(-3.0f, 3.0f, 3.0f);
	glVertex3f(3.0f, 3.0f, 3.0f);

	glPopMatrix();

	// Bottom face (y = -1.0f)
	glColor3f(0.933, 0.910, 0.667);     // Orange
	glVertex3f(3.0f, -3.0f, 3.0f);
	glVertex3f(-3.0f, -3.0f, 3.0f);
	glVertex3f(-3.0f, -3.0f, -3.0f);
	glVertex3f(3.0f, -3.0f, -3.0f);

	// Front face  (z = 1.0f)
	glColor3f(0.933, 0.910, 0.667);     // Red
	glVertex3f(3.0f, 3.0f, 3.0f);
	glVertex3f(-3.0f, 3.0f, 3.0f);
	glVertex3f(-3.0f, -3.0f, 3.0f);
	glVertex3f(3.0f, -3.0f, 3.0f);

	// Back face (z = -1.0f)
	glColor3f(0.933, 0.910, 0.667);     // Yellow
	glVertex3f(3.0f, -3.0f, -3.0f);
	glVertex3f(-3.0f, -3.0f, -3.0f);
	glVertex3f(-3.0f, 3.0f, -3.0f);
	glVertex3f(3.0f, 3.0f, -3.0f);

	// Left face (x = -1.0f)
	glColor3f(0.933, 0.910, 0.667);     // Blue
	glVertex3f(-3.0f, 3.0f, 3.0f);
	glVertex3f(-3.0f, 3.0f, -3.0f);
	glVertex3f(-3.0f, -3.0f, -3.0f);
	glVertex3f(-3.0f, -3.0f, 3.0f);

	// Right face (x = 1.0f)
	glColor3f(0.933, 0.910, 0.667);     // Magenta
	glVertex3f(3.0f, 3.0f, -3.0f);
	glVertex3f(3.0f, 3.0f, 3.0f);
	glVertex3f(3.0f, -3.0f, 3.0f);
	glVertex3f(3.0f, -3.0f, -3.0f);
	// End of drawing color-cube


	glColor3f(0.467, 0.533, 0.600);     // Blue
	glVertex3f(-2.3, 2, 3.1f);
	glVertex3f(-0.5, 2, 3.1f);
	glColor3f(0.686, 0.933, 0.933);
	glVertex3f(-0.5, 1, 3.1f);
	glVertex3f(-2.3, 1, 3.1f);



	//usa
	glColor3f(0.627, 0.322, 0.176);
	glVertex3f(1, 2, 3.05f);
	glVertex3f(2, 2, 3.05f);
	glVertex3f(2, 0.03, 3.05f);
	glVertex3f(1, 0.03, 3.05f);

	glEnd();

	glPopMatrix();

	glPushMatrix();
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	GLfloat pozitial1[] = { 10, 10, 200.0, 0.0 };
	glLightfv(GL_LIGHT0, GL_POSITION, pozitial1);
	GLfloat red[] = { 0.698, 0.133, 0.133, 0.0 };
	glLightfv(GL_LIGHT0, GL_DIFFUSE, red);
	glColor3f(0.698, 0.133, 0.133);

	glTranslatef(0, 3, 0);
	glRotatef(-90, 1, 0, 0);
	glutSolidCone(6, 2.5, 6, 2);

	glDisable(GL_LIGHTING);
	glPopMatrix();





}

void cer(void) {
	glColor3f(1, 1, 1);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture1);
	glBegin(GL_QUADS);

	glTexCoord2f(0.0, 1.0); glVertex3f(-100.0f, -100.0f, -100);
	glTexCoord2f(1.0, 1.0); glVertex3f(100, -100, -100);
	glTexCoord2f(1.0, 0.0); glVertex3f(100, 100, -100);
	glTexCoord2f(0.0, 0.0); glVertex3f(-100, 100, -100);

	glEnd();




	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture2);
	glBegin(GL_QUADS);
	glTexCoord2f(1.0, 1.0); glVertex3f(-100.0f, -100.0, 100);
	glTexCoord2f(0.0, 1.0); glVertex3f(100, -100, 100);
	glTexCoord2f(0.0, 0.0); glVertex3f(100, 100, 100);
	glTexCoord2f(1.0, 0.0); glVertex3f(-100, 100, 100);
	glEnd();


	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture3);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0); glVertex3f(-100, 100, -100);
	glTexCoord2f(1.0, 0.0); glVertex3f(-100, 100, 100);
	glTexCoord2f(1.0, 1.0); glVertex3f(-100, -100, 100);
	glTexCoord2f(0.0, 1.0); glVertex3f(-100, -100, -100);
	glEnd();


	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture4);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0); glVertex3f(100, 100, 100);
	glTexCoord2f(1.0, 0.0); glVertex3f(100, 100, -100);
	glTexCoord2f(1.0, 1.0); glVertex3f(100, -100, -100);
	glTexCoord2f(0.0, 1.0); glVertex3f(100, -100, 100);
	glEnd();

	glDisable(GL_TEXTURE_2D);
}
void renderScene(void) {

	// Clear Color and Depth Buffers

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Reset transformations
	glLoadIdentity();
	// Set the camera
	gluLookAt(x, 2.0f, z,
		x + lx, 1.8f, z + lz,
		0.0f, 1.0f, 0.0f);

	glColor3f(1.0, 0.0, 0.0);
	glLineWidth(10);
	glBegin(GL_LINE_STRIP);
	for (int i = 0; i <= 30; i++)
	{
		glEvalCoord1f((GLfloat)i / 30.0);
	}
	glEnd();

	// Draw ground
	glColor3f(0.196, 0.804, 0.196);

	//glEnable(GL_TEXTURE_2D);
	//glBindTexture(GL_TEXTURE_2D, texture5);
	glBegin(GL_QUADS);

	glTexCoord2f(0.0, 1.0); glVertex3f(-100.0f, 0.0f, -100.0f);
	glTexCoord2f(1.0, 1.0); glVertex3f(-100.0f, 0.0f, 100.0f);
	glTexCoord2f(1.0, 0.0); glVertex3f(100.0f, 0.0f, 100.0f);
	glTexCoord2f(0.0, 0.0); glVertex3f(100.0f, 0.0f, -100.0f);

	glEnd();

	//draw sky
	cer();
	// Draw 36 flowers
	for (int i = -3; i < 3; i++)
		for (int j = -3; j < 3; j++) {
			if (i != 0 && j != 0) {
				glPushMatrix();
				glTranslatef(i*10.0, 0, j * 10.0);
				drawFlowers();


				glPopMatrix();
			}
		}


	brazi();
	drawCasa();
	drawGard();
	glPushMatrix();
	glTranslatef(-2, 0, -1);
	drawFlowers();
	glPopMatrix();

	//quadric objects


	GLUquadricObj *qobj;
	GLfloat mat_ambient[] = { 0.545, 0.271, 0.075, 1.0 };
	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_shininess[] = { 50.0 };
	GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };
	GLfloat model_ambient[] = { 0.5, 0.5, 0.5, 1.0 };

	//glClearColor(0.0, 0.0, 0.0, 0.0);

	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, model_ambient);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);

	/*  Create 5 display lists, each with a different quadric object.
	*  Different drawing styles and surface normal specifications
	*  are demonstrated.
	*/
	startList = glGenLists(5);
	qobj = gluNewQuadric();
	// gluQuadricCallback(qobj, GLU_ERROR, errorCallback);


	///gluQuadricDrawStyle(qobj, GLU_FILL); /* flat shaded */
	gluQuadricNormals(qobj, GLU_FLAT);
	glNewList(startList + 1, GL_COMPILE);

	gluCylinder(qobj, 0.1, 0.3, 0.7, 15, 5);
	glEndList();



	glEnable(GL_LIGHTING);
	glShadeModel(GL_SMOOTH);
	glRotatef(-25, 1.0, 0.0, 0.0);
	glTranslatef(-2, -0.8, -1);

	glCallList(startList);


	glShadeModel(GL_SMOOTH);
	glPushMatrix();
	glTranslatef(0.0, -1.0, 0.0);

	glRotatef(30, 1.0, 0.0, 0.0);
	glCallList(startList + 1);
	glPopMatrix();

	glShadeModel(GL_FLAT);
	glPushMatrix();
	glTranslatef(0.0, 1.0, 0.0);

	glRotatef(300.0, 1.0, 0.0, 0.0);
	glCallList(startList + 1);
	glPopMatrix();

	glShadeModel(GL_FLAT);
	glTranslatef(2.0, 0.0, 0.0);
	glPushMatrix();
	glRotatef(0, 1.0, 0.0, 0.0);
	glCallList(startList + 4);
	glPopMatrix();

	glShadeModel(GL_SMOOTH);
	glTranslatef(0.0, 1.0, 0.0);
	glPushMatrix();
	glRotatef(0, 1.0, 0.0, 0.0);
	glCallList(startList + 4);
	glPopMatrix();

	glDisable(GL_LIGHTING);
	glColor3f(0.0, 1.0, 1.0);
	glTranslatef(2.0, -2.0, 0.0);
	glCallList(startList + 2);

	glColor3f(1.0, 1.0, 0.0);
	glTranslatef(0.0, 2.0, 0.0);
	glCallList(startList + 3);

	glClearColor(0.5, 0.5, 0.5, 1.0);

	glutSwapBuffers();
}

void processNormalKeys(unsigned char key, int x, int y)
{
	float fraction = 0.5f;

	switch (key) {
	case 'a':
		angle -= 0.03f;
		lx = sin(angle);
		lz = -cos(angle);
		break;

	case 'd':
		angle += 0.03f;
		lx = sin(angle);
		lz = -cos(angle);
		break;

	case 'w':

		x += lx * fraction;
		z += lz * fraction;
		break;

	case 's':
		x -= lx * fraction;
		z -= lz * fraction;
		break;


	}
	if (key == 27)
		exit(0);

	switch (key) {
	case 'f':
	case 'F':
		glEnable(GL_FOG);
		{
			GLfloat fogColor[4] = { 0.5, 0.5, 0.5, 1.0 };

			fogMode = GL_EXP;
			glFogi(GL_FOG_MODE, fogMode);
			glFogfv(GL_FOG_COLOR, fogColor);
			glFogf(GL_FOG_DENSITY, 0.035);
			glHint(GL_FOG_HINT, GL_DONT_CARE);
			glFogf(GL_FOG_START, 1.0);
			glFogf(GL_FOG_END, 5.0);
		}
		break;
	case 'g':
		glDisable(GL_FOG);
		break;
	case 27:
		exit(0);
		break;
	default:
		break;
	}

}

void processSpecialKeys(int key, int xx, int yy) {

	float fraction = 0.3f;

	switch (key) {
	case GLUT_KEY_LEFT:
		angle -= 0.03f;
		lx = sin(angle);
		lz = -cos(angle);
		break;
	case GLUT_KEY_RIGHT:
		angle += 0.03f;
		lx = sin(angle);
		lz = -cos(angle);
		break;
	case GLUT_KEY_UP:
		x += lx * fraction;
		z += lz * fraction;
		break;
	case GLUT_KEY_DOWN:
		x -= lx * fraction;
		z -= lz * fraction;
		break;
	}
}


int main(int argc, char **argv) {

	// init GLUT and create window

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(320, 320);
	glutCreateWindow("Lighthouse3D - GLUT Tutorial");
	init();
	// register callbacks
	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);
	glutIdleFunc(renderScene);
	glutKeyboardFunc(processNormalKeys);
	glutSpecialFunc(processSpecialKeys);
	//LoadTexture5();
	LoadTexture1();
	LoadTexture2();
	LoadTexture3();
	LoadTexture4();

	// OpenGL init
	glEnable(GL_DEPTH_TEST);
	cout << "use arrow keys to move." << endl;
	cout << "press f to enable fog and g to disable it";
	// enter GLUT event processing cycle
	glutMainLoop();

	return 1;
}