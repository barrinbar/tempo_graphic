///////////////////////////////////////////////////////////////////////////
//								Draw cylinder							 //
///////////////////////////////////////////////////////////////////////////


// (1) add CONST :

// (2) add define : 

// (3) add GLOBAL varibles :
double offset =0;

// (4) add in init() :

// (5) add methods :
void DrawCylinder(int n, double topr, double bottomr, int spaces,
					double startAlpha, double endAlpha)
					//Default- for full cirle n=~80, spaces =1,startAlpha =0,endAlpha= 2*PI
{
	double alpha;
	double teta = 2*PI/n; 

	for(alpha=startAlpha;alpha<endAlpha;alpha+=spaces*teta)
	{
		glBegin(GL_POLYGON);
				glColor3d(fabs(sin(alpha+PI/2)),(1+cos(alpha+PI/2))/2,0.5*cos(alpha+PI/2));
			glVertex3d(topr*sin(alpha),1,topr*cos(alpha));
			glVertex3d(topr*sin(alpha+teta),1,topr*cos(alpha+teta));
				glColor3d(1-fabs(sin(alpha)),0.8*(1+cos(alpha))/2,0.6*cos(alpha));
			glVertex3d(bottomr*sin(alpha+teta),0,bottomr*cos(alpha+teta));
			glVertex3d(bottomr*sin(alpha),0,bottomr*cos(alpha));
		glEnd();
	}
}

// (6) add in showall() :
		glPushMatrix();
			glRotated(offset*180/PI,0,1,0);
			glTranslated(0,25,0);
			glScaled(1,4,1);
			DrawCylinder(80,20,20, 1, 0.5*PI, 2*PI);
		glPopMatrix();

// (7) add in display() :

// (8) add in idle() :
	offset+=0.00 ; 

// (9) add in mouse left click :

// (10) add in mouse right click :

// (11) add keyboard functions :

// (12) add keyboard special functions :

// (13) add in main :
