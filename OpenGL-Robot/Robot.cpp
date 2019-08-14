
//@author : Mohamed Hesham Hamda   mohamed.hesham.badawy@gmail.com
//This code is a C++ code to draw a basic 2D robot using openGL and apply some geometric transformations on it using keyboard

#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h>

void Init() {
	glClearColor(0.0, 0.0, 0.0, 0.0); // set display-window color to white
	glMatrixMode(GL_PROJECTION); // set the projection to be 2D
	gluOrtho2D(0.0, 200.0, 0.0, 150.0); // set place where I can draw in the window (first 2 param: X, second 2 param: y)

	glMatrixMode(GL_MODELVIEW); // stating that I'm going to use matrix multiplications
	glLoadIdentity();
}


void HeadPart() {

	//The head part
	glColor3f(1, 0.0, 0.0); // setting colour of the quad

	glBegin(GL_QUADS);

	glVertex2i(100, 200);
	glVertex2i(100, 111);
	glVertex2i(50, 111);
	glVertex2i(50, 200);

	glEnd();
	glFlush();
}

void EyesPart() {

	glColor3f(1, 1, 0.0);
	glBegin(GL_TRIANGLES);
	//The two eyes
	
	//left eye
	glVertex2i(70, 145);
	glVertex2i(55, 145);
	glVertex2i(60, 127);
	//right eye
	glVertex2i(80, 145);
	glVertex2i(95, 145);
	glVertex2i(85, 127);

	glEnd();
	glFlush();

}

void MouthPart() {
	//The mouth part
	glBegin(GL_POLYGON);

	glColor3f(0.0, 1.0, 0.0); // setting colour of the polygon

	glVertex2i(82, 122);
	glVertex2i(77, 115);
	glVertex2i(65, 115);
	glVertex2i(70, 122);

	glEnd();
	glFlush();
}

void Borders() {
	
	//borders between body parts
	glEnable(GL_LINE_STIPPLE); //Enable Line Stipple
	glLineStipple(1, 0x00FF); //Draw dashed lines

	glLineWidth(20); // to change the size of the line
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0); // setting colour to be black
	
	//head and neck
	glVertex2i(50, 110);
	glVertex2i(120, 110);
	glEnd();
	glFlush();
}

void NeckPart() {

	//The part of the neck
	glBegin(GL_QUAD_STRIP);

	glColor3f(1.0, 0.0, 0.0);
	glVertex2i(65, 110);
	glVertex2i(65, 93);

	glVertex2i(80, 110);
	glVertex2i(80, 93);
	glEnd();
	glFlush();
}
void BodyPart() {
	//The body part
	glBegin(GL_QUAD_STRIP);

	glVertex2f(40, 93);
	glVertex2f(110, 93);
	glVertex2f(40, 50);
	glVertex2f(110, 50);

	glEnd();
	glFlush();
}

void LegPart() {

	//The left leg part
	glBegin(GL_TRIANGLE_STRIP);
	
	glVertex2f(50, 50);
	glVertex2f(60, 50);
	glVertex2f(50, 5);
	glVertex2f(60, 5);

	glEnd();

	//The right leg part
	glBegin(GL_TRIANGLE_STRIP);
	
	glVertex2f(90, 50);
	glVertex2f(100, 50);
	glVertex2f(90, 5);
	glVertex2f(100, 5);

	glEnd();
	glFlush();
}
void UpperLeft() {

	glRecti(40, 93, 20, 85); // left arm
	glRecti(130, 85, 125, 70); // left hand
}

void UpperRight() {

	glRecti(110, 93, 130, 85); // right arm
	glRecti(20, 85, 25, 70); // right hand
}

void PointsOnFace() {
	glColor3f(1, 1, 1);
	glPointSize(1.5); //to set the new size of the points 
	glBegin(GL_POINTS);

	glVertex2f(55, 123);
	glVertex2f(95, 123);
	glVertex2f(54.5, 123);
	glVertex2f(94.5, 123);
	glVertex2f(55, 122.6);
	glVertex2f(95, 122.6);
	glVertex2f(54.5, 122.6);
	glVertex2f(94.5, 122.6);
	glEnd();
}

void NecklacePart() {

	//The triangle under the neck
	glBegin(GL_LINE_STRIP);

	glColor3f(0.0, 0.0, 0.0);
	glVertex2i(60, 100);
	glVertex2i(72, 80);
	glVertex2i(80, 93);
	glEnd();

	//drawing the circle to represent a necklace (The equation's from the OpenGL forum)
	const int triangles = 20; // number of triangles
	const float twoPi = 2.0f * 3.14159f;
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.8, 0.498039, 0.196078);
	glVertex2f(72, 80); // origin
	float delta = twoPi / triangles;
	for (int i = 0; i <= triangles; i++)
		glVertex2f(72 + (2 * cos(i *  delta)), 80 + (3 * sin(i * delta)));
	glEnd();
	glFlush(); // flush everything to be executed
}
void DisplayMyDrawing() {
	glClear(GL_COLOR_BUFFER_BIT); // clearing the buffer to draw new things

	//calling all functions
	HeadPart();
	EyesPart();
	MouthPart();
	Borders();
	NeckPart();
	BodyPart();
	LegPart();
	UpperLeft();
	UpperRight();
	PointsOnFace();
	NecklacePart();

	glFlush();

}

bool scaled = false; // scalled or not
void TakeKey(unsigned char key, int x, int y) {
	// a function to read keys from the keyboard

	switch (key) {
	case 's': // if 's' is pressed it will scale the robot 

		if (scaled) {
			glScalef(0.66666666666, 1, 1); // scaling the robot
			scaled = false;
		}else {
			glScalef(1.5, 1, 1); // scaling the robot
			scaled = true;
		}
		DisplayMyDrawing();
		break;

	case 'd': // if 'D' is pressed, the robot's place will change

		glTranslatef(1.5, 0, 0); // changing the place of the robot
		DisplayMyDrawing();
		break;

	case 'a': // if 'A' is pressed, the robot's place will change

		glTranslatef(-1.5, 0, 0); // changing the place of the robot
		DisplayMyDrawing();
		break;

	default:
		break;
	}
	glutPostRedisplay(); // redraw after applying one of the transformations
}

void main(int argc, char** argv) {

	glutInit(&argc, argv); // initialize GLUT
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // setting display mode, single buffer
	glutInitWindowPosition(0, 0);  // window position on the screen (1st quad)
	glutInitWindowSize(1300, 700); // size of the window
	glutCreateWindow("Robot"); // creating a window with a title Robot
	Init(); // calling function
	glutDisplayFunc(DisplayMyDrawing); // calling function
	glutKeyboardFunc(TakeKey); // keyboard listeners
	std::cout << "Press 'S' to scale, 'A' and 'D' to move left and right,"; // printing in the console
	glutMainLoop(); // loop to keep frams come on the screen
}