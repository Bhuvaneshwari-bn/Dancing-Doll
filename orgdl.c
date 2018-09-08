/*
 * rr.c
 *
 *  Created on: May 11, 2012
 *      Author: inet-46
 */

#include <stdio.h>
#include <GL/glut.h>                  //GLUT toolkit
#include <time.h>
#define INIT_VIEW_X 0.0    //Define initial camera position and viewing window values
#define INIT_VIEW_Y 0.0
#define INIT_VIEW_Z -4.5
#define VIEW_LEFT -2.0
#define VIEW_RIGHT 2.0
#define VIEW_BOTTOM -2.0
#define VIEW_TOP 2.0
#define VIEW_NEAR 1.0
#define VIEW_FAR 200.0
#define TEXTID 5
int f=1;
GLfloat AmbientLight[]={0.3,0.3,0.3,1.0};                  //Initialization values for lighting
GLfloat DiffuseLight[] ={0.8,0.8,0.8,1.0};
GLfloat SpecularLight[] ={1.0,1.0,1.0,1.0};
GLfloat SpecRef[] = {0.7,0.7,0.7,1.0};
GLfloat LightPos[] = {-50.0,50.0,100.0,1.0};
GLint Shine =128;
GLint walkX=0,walkY=0,lookX=0,lookY=0;
GLint world=1,oldX=-1,oldY=-1;
GLint chinku=-1,minku=-1,pinku=-1,rinku=-1;
void DrawTextXY(double x,double y,double z,double scale,char *s)
{
int i;
glPushMatrix();
glTranslatef(x,y,z);
glScalef(scale,scale,scale);
for (i=0;i < strlen(s);i++)
glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,s[i]);
glPopMatrix();
}

void cover()
{
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glLoadIdentity();
glClearColor(0.3,1.0,0.4,1.0);
glTranslatef(0.0,0.0,-6.0);
glTranslatef(0.0,-1.3,0.0);
glColor3f(1.00,0.0,0.0);
glLoadName(TEXTID);
glColor3f(0.9,0.1,0.3);
DrawTextXY(-4.7,3.5,0.0,0.0020," CHANNABASAVESHWARA INSTITUTE OF TECHNOLOGY ");
glColor3f(1.0,0.0,0.7);
DrawTextXY(-3.7,2.8,0.0,0.0015," MINI PROJECT ON GRAPHICAL IMPLEMENTATION OF ");

glColor3f(0.0,0.0,1.0);
DrawTextXY(-1.75,2,0.0,0.0014," DANCING DOLLS ");
glColor3f(1.0,0.0,0.0);
DrawTextXY(-3.7,1.5,0.0,0.0009," Submitted by :- ");
glColor3f(0.0,0.0,1.0);
DrawTextXY(-2.75,1.2,0.0,0.001," Jayachithra M ");
DrawTextXY(1,1.2,0.0,0.001," Bhuvaneshwari B N ");
glColor3f(0.0,0.0,1.0);
DrawTextXY(-2.75,0.95,0.0,0.001," (1CG15CS033) ");
DrawTextXY(1,0.95,0.0,0.001," (1CS15CS018) ");
glColor3f(1.0,0.0,0.0);
DrawTextXY(-2.25,0,0.0,0.0009," Under the guidance of : ");
glColor3f(0.0,0.0,1.0);
DrawTextXY(-2.0,-.2,0.0,0.001," DHARANESH KUMAR M.L");
DrawTextXY(-2.0,-.4.0,0,0.001," Assistant professor");
DrawTextXY(-1.75,-.6,0,0.001,"  Dept. of CSE ");
DrawTextXY(-1.65,-.8,0.0,0.001," CIT GUBBI");
glColor3f(0.0,0.0,0.0);
DrawTextXY(1.25,-1.25,0.0,0.0015," Press B to move on... ");
glFlush();
glutSwapBuffers();
}

void menu2()
{
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glLoadIdentity();
glClearColor(0,0,0,1.0);
glTranslatef(0.0,0.0,-6.0);
glTranslatef(0.0,-1.3,0.0);
glColor3f(0.6,0.8,0.7);
DrawTextXY(-3.7,3.5,0.0,0.003," HELP ");
glColor3f(1.0,0.8,0.4);
DrawTextXY(-1.75,3.2,0.0,0.0014," Keyboard Controls : ");
glColor3f(0.9,0.8,0.9);
DrawTextXY(-1.25,3.0,0.0,0.001," KEY_UP -> zoom out ");
DrawTextXY(-1.25,2.8,0.0,0.001," KEY_DOWN -> zoom in ");
DrawTextXY(-1.25,2.6,0.0,0.001," KEY_RIGHT -> moves right ");
DrawTextXY(-1.25,2.4,0.0,0.001," KEY_LEFT -> moves left ");
//DrawTextXY(-1.25,2.2,0.0,0.001," Fn 7 -> Reposition the dolls to intial position ");
//DrawTextXY(-1.25,0.1,0.0,0.001," Open MENU -> B ");
glColor3f(1.0,0.8,0.4);
DrawTextXY(-1.75,1.5,0.0,0.0014," Dolls details: ");
glColor3f(0.9,0.8,0.9);
DrawTextXY(-1.25,1.3,0.0,0.001," Fn 11 -> minku ");
DrawTextXY(-1.25,1.1,0.0,0.001," Fn 8 -> pinku ");
DrawTextXY(-1.25,0.9,0.0,0.001," Fn 9 -> rinku");
DrawTextXY(-1.25,0.7,0.0,0.001," Fn 10 -> chinku ");
glColor3f(0.9,0.9,0.8);
DrawTextXY(1,0.3,0.0,0.001," Press D to move on.... ");
glFlush();
glutSwapBuffers();
}
void menu3()
{
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glLoadIdentity();
glClearColor(1,0.7,1,0.02);
glTranslatef(0.0,0.0,-6.0);
glTranslatef(0.0,-1.3,0.0);
glColor3f(0.0,0.1,1.0);
DrawTextXY(-2.25,1.1,1.5,0.003," Thank You............ ");
glFlush();
glutSwapBuffers();
}

void NormalKey(GLubyte key, GLint x, GLint y)
{
	switch(key)
	{
	case 'f': f=1;
		break;
	case 'b':f=2;
		break;
	case 'd':f=3;
		break;
	case 'e':f=4;
		break;
	case 'r':f=2;
		break;
	default:exit(0);
		break;
	}
}




void eyeright()
{
    //function for the right eye
    glPushMatrix();
    glTranslatef(.17,1.1,.75);     //Specify the coordinates for the right eye
    glRotatef(-45,0,0,1);
    glScalef(.9,.7,.7);            //Specify the size of the right eye
    glColor3f(1.0,1.0,1.0);       //Specify the color of the eye
    gluSphere(gluNewQuadric(),.3,100,100);
    glPopMatrix();
}
void eyeleft()
{
    glPushMatrix();
    glTranslatef(-.17,1.1,.75);     //Specify the position for the left eye
    glRotatef(45,0,0,1);
    glScalef(.9,.7,.7);
    glColor3f(1.0,1.0,1.0);
    gluSphere(gluNewQuadric(),.3,100,100);
    glPopMatrix();
}

void legleft()
{
    glPushMatrix();
    glTranslatef(.3,-.5,0);     //Specify the position for the left leg
    glRotatef(-90.0,1,0,0);
    glScalef(.8,.8,.8);
    gluCylinder(gluNewQuadric(),.5,.5,.5,30,6);
    glPopMatrix();
}

void legright()
{
    glPushMatrix();
    glTranslatef(-.3,-.5,0);     //Specify the position for the right leg
    glRotatef(-90.0,1,0,0);
    glScalef(.8,.8,.8);
    gluCylinder(gluNewQuadric(),.5,.5,.5,30,6);
    glPopMatrix();
}




void armleft()
{
    glPushMatrix();
    glTranslatef(-.82,0,.1);     //Specify the position for the left arm
    glRotatef(90,0,1,0);
    glRotatef(-50,1,0,0);
    gluCylinder(gluNewQuadric(),.15,.15,.48,30,6);
    glPopMatrix();
}

void armright()
{
    glPushMatrix();
    glTranslatef(.82,0,.1);      //Specify the position for the right arm
    glRotatef(90,0,1,0);
    glRotatef(-130,1,0,0);
    gluCylinder(gluNewQuadric(),.15,.15,.48,30,6);
    glPopMatrix();
}

void handleft()
{
    glPushMatrix();
    glTranslatef(.82,0,.1);     //Specify the position for the left hand
    glScalef(.4,.3,.3);
    gluSphere(gluNewQuadric(),.4,100,100);
    glPopMatrix();
}






void handright()
{
    glPushMatrix();
    glTranslatef(-.82,0,.1);    //Specify the position for the right hand
    glScalef(.4,.3,.3);
    gluSphere(gluNewQuadric(),.4,100,100);
    glPopMatrix();
}

void mouth()
{
    glPushMatrix();
    glTranslatef(0,.78,.74);
    glScalef(.4,.4,.1);
    glColor3f(0.0,0.0,0.0);
    gluSphere(gluNewQuadric(),.4,100,100);
    glPopMatrix();
}

void teeth()
{
    glPushMatrix();
    glColor3f(1.0,1.0,1.0);
    glTranslatef(-.08,.72,.76);
    glTranslatef(.055,0,.005 );
    glutSolidCube(.035);
    glTranslatef(.055,0,0 );
    glutSolidCube(.035);
    glPopMatrix();
}




void eyebrowleft()
{
    glPushMatrix();
    glTranslatef(-.3,1.5,.97);;
    glRotatef(90,0,1,0);
    glRotatef(45,1,0,0);
    glColor3f(0.0,0.0,0.0);
    gluCylinder(gluNewQuadric(),.05,.01,.3,4,6);
    glPopMatrix();
}

void eyebrowright()
{
    glPushMatrix();
    glTranslatef(.3,1.5,.97);
    glRotatef(270,0,1,0);
    glRotatef(45,1,0,0);
    gluCylinder(gluNewQuadric(),.05,.01,.3,4,6);
    glPopMatrix();
}

void neckring()
{
    glPushMatrix();
    glTranslatef(0,.5,0);
    glScalef(.59,.59,.59);
    glRotatef(90.0,1,0,0);
    glutSolidTorus(.1,1.0,20,20);
    glPopMatrix();
}




void head()
{
    glPushMatrix();
    glTranslatef(0,1.2,0);
    glScalef(.9 ,.9,.9 );
    glColor3f(1.0,0.8,0.6);
    gluSphere(gluNewQuadric(),1,100,100);
    glPopMatrix();
}

void hatmain()
{
    glPushMatrix();
    glTranslatef(0,1.3,0);
    glScalef(.98,.98,.98);
    gluSphere(gluNewQuadric(),.9,100,100);
    glPopMatrix();
}

void maintopball()
{
    glPushMatrix();
    glTranslatef(0,2.2,0);
    glScalef(.9,.9,.9);
    gluSphere(gluNewQuadric(),.18,100,100);
    glPopMatrix() ;
}







void hatring()
{
    glPushMatrix();
    glTranslatef(0,1.4,0);
    glScalef(.84,.84,.84);
    glRotatef(90.0,1,0,0);
    glutSolidTorus(.1,1.0,20,20);
    glPopMatrix();
}

void footleft()
{
    glPushMatrix();
    glTranslatef(-.3,-.5,0);
    glScalef(1.5,.3,1.5);
    glColor3f(0.0,0.0,0.0);
    gluSphere(gluNewQuadric(),.3,100,100);
    glPopMatrix();
}

void footright()
{
    glPushMatrix();
    glTranslatef(.3,-.5,0);
    glScalef(1.5,.3,1.5);
    glColor3f(0.0,0.0,0.0);
    gluSphere(gluNewQuadric(),.3,100,100);
    glPopMatrix();
}





void coatline()
{
    glPushMatrix();
    glTranslatef(0,.12,.67);
    glRotatef(-17.0,1,0,0);
    glScalef(.05,.7,.1);
    glutSolidCube(1);
    glPopMatrix();
}

void bellyCoatbottom()
{
    glPushMatrix();
    glTranslatef(0,-.2,0);
    glScalef(1,.7,1);
    glRotatef(90.0,1,0,0);
    gluDisk(gluNewQuadric(),0,.8,30,30);
    glPopMatrix();
}

void BellyCoat()
{
    glPushMatrix();
    glTranslatef(0,.5,0);
    glScalef(1,.7,1);
    glRotatef(90.0,1,0,0);
    gluCylinder(gluNewQuadric(),.6,.8,1,100,100);
    glPopMatrix();
}





void pupilleft()
{
    glPushMatrix();
    glTranslatef(-.17,1.1,.88);
    glScalef(.9,.9,.9);
    gluSphere(gluNewQuadric(),.1,100,100);
    glPopMatrix();
}

void pupilright()
{
    glPushMatrix();
    glTranslatef(.17,1.1,.88);
    glScalef(.9,.9,.9);
    gluSphere(gluNewQuadric(),.1,100,100);
    glPopMatrix();
}

void topbutton()
{
    glPushMatrix();
    glTranslatef(-.1,.4,.85);
    glScalef(1.9,1.9,1.9);
    gluSphere(gluNewQuadric(),.04,100,100);
    glPopMatrix();
}
void middlebutton()
{
    glPushMatrix()  ;
    glTranslatef(-.1,.15,.98);
    glScalef(1.9,1.9,1.9);
    gluSphere(gluNewQuadric(),.04,100,100);
    glPopMatrix();
}
void bottombutton()
{
    glPushMatrix();
    glTranslatef(-.1,-.1,.92);
    glScalef(1.9,1.9,1.9);
    glColor3f(0.0,0.0,0.0);
    gluSphere(gluNewQuadric(),.04,100,100);
    glPopMatrix();
}

void Display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);//Clear the window
    glColor3ub(50, 50, 150);//Change the draw color to slate blue
    glPushMatrix();//Save viewing matrix state
    if(world==1)
	{
       	      glTranslatef(walkX,-1,walkY);
                  glRotatef(lookY,0,1,0);
                  glRotatef(lookX,1,0,0);
	}

//*******************PINKU***********************
    glPushMatrix();
    glTranslatef(-3,0,-6);
    if(pinku==1)
	{
                  glTranslatef(walkX,-1,walkY);
                  glRotatef(lookY,0,1,0);
                  glRotatef(lookX,1,0,0);
	}
    eyeright();
    eyeleft();


    glColor3f(0.0,0.0,1.0);
    legleft();
    legright();
    hatmain();
    glColor3ub(160,82,45);
    armleft();
   armright();
    mouth();
    teeth();
    eyebrowleft();
    eyebrowright();
    head();
    glColor3f(1.0,0.0,0.0);
    maintopball();
    hatring();
    neckring();
    handleft();
    handright();
    glColor3f(0.0,0.0,0.0);
    footleft();
    footright();
    coatline();
    pupilleft();
    pupilright();
    glColor3ub(160,82,45);
    BellyCoat();
    bellyCoatbottom();
    glPopMatrix();

    //*******************RINKU***********************
    glPushMatrix();
    glTranslatef(-1,0,-6);



     if(rinku==1)
	{
                  glTranslatef(walkX,-1,walkY);
                  glRotatef(lookY,0,1,0);
                  glRotatef(lookX,1,0,0);
	}
    eyeright();
    eyeleft();
    eyebrowleft();
    eyebrowright();
    glColor3f(0.0,1.0,0.0);
    neckring();
    glColor3ub(50,40,60);
    legright();
    legleft();
    glColor3ub(255,90,0);
    armleft();
    armright();
    BellyCoat();
    bellyCoatbottom();
    glColor3ub(0,185,0);
    handleft();
    handright();
    mouth();
    teeth();
    glColor3ub(255,222,173);
    head();
    glColor3f(0.0,0.0,0.0);
    footleft();
    footright();
    topbutton();
    middlebutton();
    bottombutton();
    pupilleft();
    pupilright();
    glPopMatrix();

    //*******************MINKU***********************
    glPushMatrix();
    glTranslatef(4,0,-6);
    if(minku==1)
	{
                  glTranslatef(walkX,-1,walkY);
                  glRotatef(lookY,0,1,0);
                  glRotatef(lookX,1,0,0);
	}
    eyeleft();
    eyeright();
    glColor3f(0.0,0.0,0.0);
    pupilleft();
    pupilright();
    glColor3ub(255,127,0);
    legleft();
    legright();
    armleft();
    armright();
    BellyCoat();
    mouth();
    teeth();
    eyebrowleft();
    eyebrowright();
    glColor3ub(139,69,0);
    handright();
    handleft();
    head();
    glColor3f(0.3,0.2,0.1);
    hatmain();
    footleft();
    footright();
    coatline();
    neckring();
    glColor3f(1.0,0.7,0.0);
    hatring();
    maintopball();
    glPopMatrix();

    //*******************CHINKU****************************
    glPushMatrix();
    glTranslatef(1.5,0,-6);
    if(chinku==1)
	{
                  glTranslatef(walkX,-1,walkY);
                  glRotatef(lookY,0,1,0);
                 glRotatef(lookX,1,0,0);
	}
    eyeright();
    eyeleft();
    glColor3f(0.0,0.0,0.0);
    pupilleft();
    pupilright();
    glColor3f(0.5,0.2,0.4);
    legright();
    legleft();
    glPushMatrix();                                    //****Arm left****
    glTranslatef(-.9,.2,.1);
    glRotatef(90,0,1,0);
    glRotatef(-45,1,0,0);
    glColor3f(1.0,0.0,0.0);
    glutSolidCone(.3,.55,30,30);
    glPopMatrix();

     glPushMatrix();                                   //****Arm right****
    glTranslatef(.9,.2,.1);
    glRotatef(90,0,1,0);
    glRotatef(-135,1,0,0);
    glColor3f(1.0,0.0,0.0);
    glutSolidCone(.3,.55,30,30);
    glPopMatrix();
    glPushMatrix();                                    //****Hand left****
    glTranslatef(.9,.22,.1);
    glScalef(.5,.3,.4);
    glColor3f(1.0,1.0,0.0);
    gluSphere(gluNewQuadric(),.6,100,100);
    glPopMatrix();
    glPushMatrix();                                    //****Hand right****
    glTranslatef(-.9,.22,.1);
    glScalef(.5,.3,.4);
    glColor3f(1.0,1.0,0.0);
    gluSphere(gluNewQuadric(),.6,100,100);
    glPopMatrix();
    glPushMatrix();                                    //****Mouth****
    glTranslatef(0,.78,.8);
    glScalef(.4,.4,.1);
    glColor3f(0.0,0.0,0.0);
    gluSphere(gluNewQuadric(),.4,100,100);
    glPopMatrix();
    glPushMatrix();                                    //****Teeth****
    glColor3f(1.0,1.0,1.0);
    glTranslatef(-.08,.72,.817 );
    glutSolidCube(.035);
    glTranslatef(.055,0,.005 );
    glutSolidCube(.035);
    glTranslatef(.055,0,0 );
    glutSolidCube(.035);
    glTranslatef(.055,0,-.005 );
    glutSolidCube(.035);
    glPopMatrix();
    glPushMatrix();                                    //****Head****
    glTranslatef(0,1,0);
    glScalef(.9,.7,.9);
    glColor3ub(255,222,173);
    gluSphere(gluNewQuadric(),1,100,100);
    glPopMatrix();
    glPushMatrix();                                    //****Hat main****
    glTranslatef(0,1,0);
    glScalef(.9,.9,.9);
    glColor3ub(30,144,255);
    gluSphere(gluNewQuadric(),.9,100,100);
    glPopMatrix();
    glColor3f(1.0,1.0,0.0);
    hatring();
    footleft();
    footright();
    topbutton();
    middlebutton();
    bottombutton();
    glPushMatrix();                                    //****BellyCoat****
    glTranslatef(0,.1,0) ;
    glScalef(1,.6,1);
    glColor3f(1.0,0.0,0.0);
    gluSphere(gluNewQuadric(),1,100,100);
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();                                     //****Restore matrix state****
    glutSwapBuffers();                             //****Flush drawing commands****
}



void SetupRend()
{
    glClearColor(0.7,0.7,1.0,1.0);
    glEnable(GL_DEPTH_TEST);         //Enable depth testing
    glEnable(GL_LIGHTING);             //Enable lighting
    glLightfv(GL_LIGHT0,GL_AMBIENT,AmbientLight);//Set up and enable light zero
    glLightfv(GL_LIGHT0,GL_DIFFUSE,DiffuseLight);
    glLightfv(GL_LIGHT0,GL_SPECULAR,SpecularLight);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);                   //Enable color tracking
    glColorMaterial(GL_FRONT,GL_AMBIENT_AND_DIFFUSE);//Set material to follow
    glMaterialfv(GL_FRONT,GL_SPECULAR,SpecRef);//Set specular reflectivity and shine
    glMateriali(GL_FRONT,GL_SHININESS,Shine);
}

void walk(int key,int x,int y)                                      //change positions using arrow keys
{
    if(key==GLUT_KEY_UP)    walkY+=1;
    if(key==GLUT_KEY_DOWN)  walkY-=1;
    if(key==GLUT_KEY_RIGHT) walkX+=1;
    if(key==GLUT_KEY_LEFT)  walkX-=1;
    if(key==GLUT_KEY_F7)    world=-world;
    if(key==GLUT_KEY_F11)   minku=-minku;
    if(key==GLUT_KEY_F8)    pinku=-pinku;
    if(key==GLUT_KEY_F9)    rinku=-rinku;
    if(key==GLUT_KEY_F10)   chinku=-chinku;
}

void gaze(int x,int y)
{
    if((oldX<0) || (oldY<0))
	{

      oldX=x;
                  oldY=y;
	}
    lookX+=y-oldY;lookY+=x-oldX;oldX=x;oldY=y;
}

void myReshape(int w, int h)
{
    GLfloat Ratio;
    glViewport(0,0,w,h);
    Ratio=1.0*w/h;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(50.0,Ratio,VIEW_NEAR,VIEW_FAR);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(INIT_VIEW_X,INIT_VIEW_Y,INIT_VIEW_Z);
    glLightfv(GL_LIGHT0, GL_POSITION, LightPos);
}

void Dis()
{
if(f==1)
cover();
if(f==2)
menu2();
if(f==3)
Display();
if(f==4)
menu3();
}

void main(int argc, char ** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
    glutCreateWindow("Dancing dolls");
	glutInitWindowPosition(0,0);
	glutInitWindowSize(1400,800);
    glutReshapeFunc(myReshape);
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
glEnable(GL_LINE_SMOOTH);
glEnable(GL_BLEND);
glutKeyboardFunc(NormalKey);
    glutDisplayFunc(Dis);
    glutIdleFunc(Dis);
    glutSpecialFunc(walk);
    glutPassiveMotionFunc(gaze);
    SetupRend();
    glEnable(GL_NORMALIZE);
	glEnable(GL_DEPTH_TEST);
    glutMainLoop();
}