// All you need to the main body (3d graphics program)

// add to project properties->configuration ->linker->input
//->additional dependences-> opengl32.lib;glu32.lib;glut.lib;

#include "GLUT.H"
#include <math.h>
#include <time.h>

#define HEIGHT 600
#define WIDTH 600

const int GSIZE = 150;  			// size to paint the ground
const double PI = 4 * atan(1.0);  	// define PI
// (1) PUT  CONST HERE

// (2) PUT define HERE 

// (3) PUT GLOBAL varibles HERE 
double eyex = 2, eyez = 35, eyey = 30; // camera - eye
double dirx, diry, dirz;			// camera - look at
double dx = 0, dy = 0, dz = 0; 				// change position 
double speed = 0;					// change position
double angular_speed = 0;			// change position
double sight = PI; 					// helps to calculate the change of position

double ground[GSIZE][GSIZE];  		// simple ground

void init()
{
	int i, j;

	// optional set random values
	srand(time(0));

	// set ground
	for (i = 0; i<GSIZE; i++)
		for (j = 0; j<GSIZE; j++)
			ground[i][j] = 0;

	// (4) PUT CONTENT HERE

	// set background color
	glClearColor(0, 1, 1, 0);
	glEnable(GL_DEPTH_TEST);
}


void DrawGround()
{

	// draw Y axis
	glColor3d(1, 0, 0);
	glBegin(GL_LINES);
	glVertex3d(0, 0, 0);
	glVertex3d(0, 4, 0);
	glEnd();

	int i, j;

	glColor3d(0.5, 1, 0.5);

	
	for (i = 0; i<GSIZE - 1; i++)
		for (j = 0; j<GSIZE - 1; j++)
		{
			glBegin(GL_POLYGON);// GL_LINE_LOOP);
			glVertex3d(j - GSIZE / 2, 0, i - GSIZE / 2);
			glVertex3d(j - GSIZE / 2, 0, i + 1 - GSIZE / 2);
			glVertex3d(j + 1 - GSIZE / 2, 0, i + 1 - GSIZE / 2);
			glVertex3d(j + 1 - GSIZE / 2, 0, i - GSIZE / 2);
			glEnd();
		}
}

// (5) PUT METHODS HERE

// addone to display
void ShowAll()
{
	glEnable(GL_DEPTH_TEST);
	// start of the transformations
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	DrawGround();
	// (6) PUT CONTENT HERE
}

// refresh
void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glViewport(0, 0, WIDTH, HEIGHT); // splits window into subwindows
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glFrustum(-1, 1, -1, 1, 0.7, 300); // perspective projection(left,right,bottom,top,near,far)
	gluLookAt(eyex, eyey, eyez, eyex + dirx, eyey - 0.5, eyez + dirz, 0, 1, 0);// (eye,dir,up)

	ShowAll();

	// (7) PUT CONTENT HERE

	glEnable(GL_DEPTH_TEST); // Return back to 3d 
	glutSwapBuffers();
}

void idle() // WRITE OFFSETS IN THIS METHOD
{
	// change position with keyboard
	sight += angular_speed;
	dirx = sin(sight);
	dirz = cos(sight);
	eyex += dirx*speed;
	eyey += dy;
	eyez += dirz*speed;

	// (8) PUT CONTENT HERE

	glutPostRedisplay(); //-> display
}

// mouse control
void mouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//(9) mouse left click
	}
	else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//(10) mouse right click
	}

}

// keyboard regular
void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case ' ': //stop moving
		angular_speed = 0;
		speed = 0;
		dy = 0;
		dx = 0;
		break;
		// (11) add here 
	default:
		// do nothing
		break;
	}
}


// keyboard special
void special(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_LEFT:
		angular_speed += 0.005;
		break;
	case GLUT_KEY_RIGHT:
		angular_speed -= 0.005;
		break;
	case GLUT_KEY_UP:
		speed += 0.005;
		break;
	case GLUT_KEY_DOWN:
		speed -= 0.005;
		break;
	case GLUT_KEY_PAGE_UP:
		dy += 0.005;
		break;
	case GLUT_KEY_PAGE_DOWN:
		dy -= 0.005;
		break;
		// (12) add here
	}

}

void main(int argc, char* argv[])
{
	// windowing
	glutInit(&argc, argv);
	// GLUT_DOUBLE stands for double buffer
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutInitWindowPosition(100, 100);

	glutCreateWindow("excercise name");
	// set refresh function
	glutDisplayFunc(display);
	glutIdleFunc(idle);

	glutMouseFunc(mouse);
	glutKeyboardFunc(keyboard); // for ascii keys
	glutSpecialFunc(special); // for special keys

	// (13) CALL TO NEW METHOD HERE (like menu)

	init();

	glutMainLoop();
}