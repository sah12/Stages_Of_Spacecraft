#include<stdio.h>
#include<GL/glut.h>
#include<math.h>
#define CIRCLE_RADIUS 150.0f
#define PI 3.14
GLfloat x=0.0,y=0.0;
GLfloat x_tri=0.0,y_tri=0.0;
GLfloat x3=0,y3=0,x4=0,y4=0,x5=0,y5=0,angle2=-(3.14/2);
GLint refreshMills=30,chMenu=0,winId1,winId2;
const int WIDTH=600, HEIGHT=600;
int circle_points =100;

void myinit(void)
{
	glClearColor(0.0,0.0,0.0,1.0);
	glColor3f(0.75f,0.35f,0.05f);
	glPointSize(5.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,600.0,0.0,600.0);
}

void drawCircleFilled (double centerX, double centerY, double radiusX, double radiusY)
{
    const float DEG2RAD = 3.14159 / 180;
    glBegin(GL_TRIANGLE_FAN);
        glVertex2d (centerX, centerY);
        for (int i = -1; i < 360; i++) {
            float degInRad = i * DEG2RAD;
            glVertex2d (centerX + cos (degInRad) * radiusX, 
                            centerY + sin (degInRad) * radiusY);
            
        }
        
    glEnd();
}
void drawCloud(int a,int b)
{
    int x =a,y=b;
    
        glColor3f(255.0, 255.0, 255.0);
        drawCircleFilled(x, y, 80, 45);
        glColor3f(255.0, 255.0, 255.0);
        drawCircleFilled(x + 25, y + 15, 35, 35);
        glColor3f(255.0, 255.0, 255.0);
        drawCircleFilled(x + 25, y - 15, 35, 35);
        glColor3f(255.0, 255.0, 255.0);
        drawCircleFilled(x - 25, y - 15, 35, 35);
        glColor3f(255.0, 255.0, 255.0);
        drawCircleFilled(x - 25, y + 15, 35, 35);
}

void display_rocket2()
{
	glPushMatrix();
	glTranslatef(0.0,-400.0,0.0);
	glRotatef(-30.0,0.0,0.0,1.0);
	glTranslatef(-30.0,-100.0,0.0);
        glScalef(0.8,0.8,0);
        glBegin(GL_POLYGON);
    glColor3f(0.7,0.7,0.7);
    glVertex2f(220.0,290.0);
    glVertex2f(200.0,270.0);
    glVertex2f(260.0,270.0);
    glVertex2f(240.0,290.0);
    glEnd();
    
    glBegin(GL_POLYGON);
    glColor3f(0.8,0.8,0.8);
    glVertex2f(200.0,270.0);
    glVertex2f(260.0,270.0);
    glVertex2f(260.0,70.0);
    glVertex2f(200.0,70.0);
    glEnd();
    
    glBegin(GL_TRIANGLES);
    glColor3f(0.7,0.7,0.7);
    glVertex2f(200.0,120.0);
    glVertex2f(200.0,100.0);
    glVertex2f(170.0,100.0);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.7,0.7,0.7);
    glVertex2f(260.0,120.0);
    glVertex2f(290.0,100.0);
    glVertex2f(260.0,100.0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.6,0.6,0.6);
    glVertex2f(170.0,100.0);
    glVertex2f(200.0,100.0);
    glVertex2f(200.0,50.0);
    glVertex2f(180.0,50.0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.6,0.6,0.6);
    glVertex2f(260.0,100.0);
    glVertex2f(290.0,100.0);
    glVertex2f(280.0,50.0);
    glVertex2f(260.0,50.0);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(1.0,0.8,0.0);
    glVertex2f(200.0,70.0);
    glVertex2f(260.0,70.0);
    glVertex2f(230.0,0.0);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.9,0.5,0.0);
    glVertex2f(200.0,70.0);
    glVertex2f(260.0,70.0);
    glVertex2f(230.0,40.0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.5,0.5,0.5);
    glVertex2f(220.0,250.0);
    glVertex2f(240.0,250.0);
    glVertex2f(240.0,210.0);
    glVertex2f(220.0,210.0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.5,0.5,0.5);
    glVertex2f(220.0,190.0);
    glVertex2f(240.0,190.0);
    glVertex2f(240.0,150.0);
    glVertex2f(220.0,150.0);
    glEnd();
   glBegin(GL_POLYGON);
    glColor3f(0.5,0.5,0.5);
    glVertex2f(220.0,130.0);
    glVertex2f(240.0,130.0);
    glVertex2f(240.0,90.0);
    glVertex2f(220.0,90.0);
    glEnd();
    glPopMatrix();
}

void display_background2()
{
	glBegin(GL_POLYGON);
	glColor3f(0.3,1.0,1.0);
	glVertex2f(0.0,0.0);
	glVertex2f(0.0,600.0);
	glVertex2f(600.0,600.0);
	glVertex2f(600.0,0.0);
	glEnd();
	drawCloud(320,100);
	drawCloud(360,300);
	drawCloud(120,500);
	drawCloud(420,600);
	drawCloud(600,200);
	drawCloud(100,0);
	drawCloud(540,400);
	drawCloud(100,200);
}

void rocket_top()
{
	glPushMatrix();
	glTranslatef(300.0,280.0,0.0);
	glRotatef(180,0.0,0.0,1.0);
	glTranslatef(-230.0,-350.0,0.0);
	glBegin(GL_TRIANGLES);
    glColor3f(0.7,0.7,0.7);
    glVertex2f(230.0,450.0);
    glVertex2f(200.0,300.0);
    glVertex2f(260.0,300.0);
    glEnd();
       glPopMatrix();
}

void display_rocket1()
{
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glScalef(0.9,0.9,0);
	glTranslatef(60.0,0.0,0.0);
	
     glBegin(GL_TRIANGLES);
    glColor3f(0.7,0.7,0.7);
    glVertex2f(230.0,450.0);
    glVertex2f(200.0,300.0);
    glVertex2f(260.0,300.0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.8,0.8,0.8);
    glVertex2f(200.0,300.0);
    glVertex2f(260.0,300.0);
    glVertex2f(260.0,100.0);
    glVertex2f(200.0,100.0);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.7,0.7,0.7);
    glVertex2f(200.0,150.0);
    glVertex2f(200.0,130.0);
    glVertex2f(170.0,130.0);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.7,0.7,0.7);
    glVertex2f(260.0,150.0);
    glVertex2f(290.0,130.0);
    glVertex2f(260.0,130.0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.6,0.6,0.6);
    glVertex2f(170.0,130.0);
    glVertex2f(200.0,130.0);
    glVertex2f(200.0,80.0);
    glVertex2f(180.0,80.0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.6,0.6,0.6);
    glVertex2f(260.0,130.0);
    glVertex2f(290.0,130.0);
    glVertex2f(280.0,80.0);
    glVertex2f(260.0,80.0);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(1.0,0.8,0.0);
    glVertex2f(200.0,100.0);
    glVertex2f(260.0,100.0);
    glVertex2f(230.0,30.0);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.9,0.5,0.0);
    glVertex2f(200.0,100.0);
    glVertex2f(260.0,100.0);
    glVertex2f(230.0,70.0);
    glEnd();
    //window 1 up
    glBegin(GL_POLYGON);
    glColor3f(0.5,0.5,0.5);
    glVertex2f(220.0,280.0);
    glVertex2f(240.0,280.0);
    glVertex2f(240.0,240.0);
    glVertex2f(220.0,240.0);
    glEnd();
    //window 2 middle
    glBegin(GL_POLYGON);
    glColor3f(0.5,0.5,0.5);
    glVertex2f(220.0,220.0);
    glVertex2f(240.0,220.0);
    glVertex2f(240.0,180.0);
    glVertex2f(220.0,180.0);
    glEnd();
    //window 3 lower
   glBegin(GL_POLYGON);
    glColor3f(0.5,0.5,0.5);
    glVertex2f(220.0,160.0);
    glVertex2f(240.0,160.0);
    glVertex2f(240.0,120.0);
    glVertex2f(220.0,120.0);
    glEnd();
    glPopMatrix();
}

void display_background1()
{
        //1sky
	glBegin(GL_POLYGON);
	glColor3f(0.3,1.0,1.0);
	glVertex2f(0.0,0.0);
	glVertex2f(0.0,600.0);
	glVertex2f(600.0,600.0);
	glVertex2f(600.0,0.0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.3,0.3,1.0);
	glVertex2f(0.0,0.0);
	glVertex2f(0.0,480.0);
	glVertex2f(0.0,450.0);
	glVertex2f(600.0,450.0);
	glVertex2f(600.0,0.0);
	glEnd();
	glFlush();
	//1or	
	glBegin(GL_POLYGON);
	glColor3f(1.0,0.5,0.0);
	glVertex2f(0.0,0.0);
	glVertex2f(0.0,280.0);
	glVertex2f(80.0,300.0);
	glVertex2f(320.0,250.0);
	glVertex2f(600.0,280.0);
	glVertex2f(600.0,0.0);
	glEnd();
	glFlush();
	//1gr
	glBegin(GL_POLYGON);
	glColor3f(0.34,0.45,0.0);
	glVertex2f(0.0,0.0);
	glVertex2f(100.0,70.0);
	glVertex2f(130.0,70.0);
	glVertex2f(200.0,100.0);
	glVertex2f(230.0,100.0);
	glVertex2f(300.0,70.0);
	glVertex2f(330.0,70.0);
	glVertex2f(400.0,75.0);
	glVertex2f(430.0,75.0);
	glVertex2f(600.0,0.0);
	glEnd();
	glFlush();
	//2green
	glBegin(GL_POLYGON);
	glColor3f(0.44,0.65,0.0);
	glVertex2f(0.0,0.0);
	glVertex2f(100.0,30.0);
	glVertex2f(130.0,30.0);
	glVertex2f(200.0,50.0);
	glVertex2f(250.0,50.0);
	glVertex2f(300.0,30.0);
	glVertex2f(350.0,30.0);
	glVertex2f(600.0,0.0);
	glEnd();
	glFlush();
	//trunck
	glBegin(GL_POLYGON);
	glColor3f(0.5,0.35,0.05);
	glVertex2f(50.0,0.0);
	glVertex2f(50.0,85.0);
	glVertex2f(50.0,85.0);
	glVertex2f(75.0,85.0);
	glVertex2f(75.0,0.0);
	glEnd();
	glFlush();
	glBegin(GL_TRIANGLES);
	glColor3f(0.0,1.0,0.0);
	glVertex2f(10.0,85.0);
	glVertex2f(115.0,85.0);
	glVertex2f(55.0,200.0);
	glEnd();
	glFlush();
	//t2
	glBegin(GL_TRIANGLES);
	glColor3f(0.5,1.5,0.0);
	glVertex2f(15.0,130.0);
	glVertex2f(105.0,130.0);
	glVertex2f(55.0,220.0);
	glEnd();
	glFlush();
	//t3
	glBegin(GL_TRIANGLES);
	glColor3f(0.0,1.0,0.0);
	glVertex2f(25.0,175.0);
	glVertex2f(95.0,175.0);
	glVertex2f(55.0,250.0);
	glEnd();
	glFlush();
	//glBegin(GL_POLYGON);
	glBegin(GL_POLYGON);
	glColor3f(0.5,0.35,0.05);
	glVertex2f(450.0,0.0);
	glVertex2f(450.0,85.0);
	glVertex2f(475.0,85.0);
	glVertex2f(475.0,0.0);
	glEnd();
	glFlush();
	//t1
	glBegin(GL_TRIANGLES);
	glColor3f(0.6,1.0,0.02);
	glVertex2f(400.0,85.0);
	glVertex2f(525.0,85.0);
	glVertex2f(465.0,200.0);
	glEnd();
	glFlush();
	//t2
	glBegin(GL_TRIANGLES);
	glColor3f(0.0,1.0,0.0);
	glVertex2f(410.0,130.0);
	glVertex2f(520.0,130.0);
	glVertex2f(460.0,220.0);
	glEnd();
	glFlush();
	//t3
	glBegin(GL_TRIANGLES);
	glColor3f(0.0,1.0,0.0);
	glVertex2f(25.0,175.0);
	glVertex2f(95.0,175.0);
	glVertex2f(55.0,250.0);
	glEnd(); 
}

void translate_rocket1_scene2()
{
	glPushMatrix();
	glTranslatef(0.0,-400.0,0.0);
	glRotatef(-30.0,0.0,0.0,1.0);
	glTranslatef(-30.0,-100.0,0.0);
        glScalef(0.85,0.85,0);
	display_rocket1();
	glPopMatrix();
}

void display_stars_scene3()
{
	glBegin(GL_POINTS);
	glVertex2f(20,450);	
	glVertex2f(40,390);
	glVertex2f(45,580);
	glVertex2f(120,420);
	glVertex2f(160,480);
	glVertex2f(190,440);
	glVertex2f(250,550);
	glVertex2f(280,500);
	glVertex2f(380,470);
	glVertex2f(420,540);
	glVertex2f(420,540);
	glVertex2f(480,500);
	glVertex2f(500,590);
	glVertex2f(550,390);
	glVertex2f(580,370);
	glVertex2f(470,390);
	glVertex2f(350,410);
	glVertex2f(310,460);
	glVertex2f(280,580);
	glVertex2f(100,550);
	glVertex2f(200,500);
	glVertex2f(550,510);
	glEnd();
}

void display_rocket3(){
   
    glPushMatrix();
    glTranslatef(0.0,145.0,0.0);
    glRotatef(-70.0,0.0,0.0,1.0);
    glTranslatef(-230.0,-225.0,0.0);
   // glScalef(0.6,0.6,0);
    glBegin(GL_POLYGON);
    glColor3f(0.7,0.7,0.7);
    glVertex2f(220.0,320.0);
    glVertex2f(200.0,300.0);
    glVertex2f(260.0,300.0);
    glVertex2f(240.0,320.0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.8,0.8,0.8);
    glVertex2f(200.0,300.0);
    glVertex2f(260.0,300.0);
    glVertex2f(260.0,150.0);
    glVertex2f(200.0,150.0);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.9,0.5,0.0);
    glVertex2f(200.0,150.0);
    glVertex2f(260.0,150.0);
    glVertex2f(230.0,120.0);
    glEnd();
    
    glBegin(GL_POLYGON);
    glColor3f(0.5,0.5,0.5);
    glVertex2f(220.0,280.0);
    glVertex2f(240.0,280.0);
    glVertex2f(240.0,240.0);
    glVertex2f(220.0,240.0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.5,0.5,0.5);
    glVertex2f(220.0,220.0);
    glVertex2f(240.0,220.0);
    glVertex2f(240.0,180.0);
    glVertex2f(220.0,180.0);
    glEnd();
    glPopMatrix();
    //glFlush();
}

void display_rocket4(){
    //glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    glTranslatef(0.0,145.0,0.0);
    glRotatef(-70.0,0.0,0.0,1.0);
    glTranslatef(-230.0,-225.0,0.0);
   // glScalef(0.6,0.6,0);
    glBegin(GL_POLYGON);
    glColor3f(0.7,0.7,0.7);
    glVertex2f(220.0,320.0);
    glVertex2f(200.0,300.0);
    glVertex2f(260.0,300.0);
    glVertex2f(240.0,320.0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.8,0.8,0.8);
    glVertex2f(200.0,300.0);
    glVertex2f(260.0,300.0);
    glVertex2f(260.0,200.0);
    glVertex2f(200.0,200.0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.5,0.5,0.5);
    glVertex2f(220.0,280.0);
    glVertex2f(240.0,280.0);
    glVertex2f(240.0,240.0);
    glVertex2f(220.0,240.0);
    glEnd();
    glBegin(GL_POLYGON); //bars
    glColor3f(0.5,0.5,0.5);
    glVertex2f(260.0,250.0);
    glVertex2f(280.0,250.0);
    glVertex2f(280.0,240.0);
    glVertex2f(260.0,240.0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.5,0.5,0.5);
    glVertex2f(180.0,250.0);
    glVertex2f(200.0,250.0);
    glVertex2f(200.0,240.0);
    glVertex2f(180.0,240.0);
    glEnd();
    glBegin(GL_POLYGON);//wings
    glColor3f(0.3,0.3,0.3);
    glVertex2f(280.0,280.0);
    glVertex2f(350.0,280.0);
    glVertex2f(350.0,220.0);
    glVertex2f(280.0,220.0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.3,0.3,0.3);
    glVertex2f(180.0,280.0);
    glVertex2f(110.0,280.0);
    glVertex2f(110.0,220.0);
    glVertex2f(180.0,220.0);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(0.5,0.5,0.5);
    glVertex2f(180.0,250.0);
    glVertex2f(110.0,250.0);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(0.5,0.5,0.5);
    glVertex2f(280.0,250.0);
    glVertex2f(350.0,250.0);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(0.5,0.5,0.5);
    glVertex2f(160.0,280.0);
    glVertex2f(160.0,220.0);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(0.5,0.5,0.5);
    glVertex2f(130.0,280.0);
    glVertex2f(130.0,220.0);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(0.5,0.5,0.5);
    glVertex2f(300.0,280.0);
    glVertex2f(300.0,220.0);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(0.5,0.5,0.5);
    glVertex2f(330.0,280.0);
    glVertex2f(330.0,220.0);
    glEnd();
    glPopMatrix();
    glFlush();
}

void DrawPlanet()
{
    double angle = 2*  PI/circle_points ;
    glPolygonMode( GL_FRONT, GL_FILL );
    //glColor3f(0.5, 0.3, 0.2 );
    glColor3f(0.7,0.7,0.6);
    glBegin(GL_POLYGON);
    double angle1 = 0.0;        
    glVertex2d( CIRCLE_RADIUS * cos(0.0) , CIRCLE_RADIUS * sin(0.0));

    int i;
    for (i = 0; i < circle_points; i++)
    {
	glColor3f(0.5,0.3,0.1);
        glVertex2d(CIRCLE_RADIUS * cos(angle1), CIRCLE_RADIUS *sin(angle1));
        angle1 += angle ;
    }

    glEnd();
    //glFlush();
}

void draw_satellite()
{
	double angle=2*PI/circle_points;
	glPushMatrix();
	glTranslatef(x4,y4,0.0f);
	glTranslatef(0.0,90.0,0.0);
	glScalef(0.6,0.6,0.0);
	glTranslatef(0.0,-145.0,0.0);
	display_rocket4();
	glPopMatrix();
	if(x4<270)
		x4+=1;		
}

void rotate_satellite()
{ 
	double angle=2*PI/(10*circle_points);
	glPushMatrix();
	glTranslatef(x5,y5,0.0f);
	glTranslatef(x4,y4,0.0f);
	glTranslatef(0.0,90.0,0.0);
	glScalef(0.6,0.6,0.0);
	glTranslatef(0.0,-145.0,0.0);
	display_rocket4();
	glPopMatrix();
	if(angle2<-0.03)
	{
		x5=20 + (CIRCLE_RADIUS + 50)*(cos(angle2));
		y5=200 + (CIRCLE_RADIUS + 50)*(sin(angle2));	
		angle2+=angle;
	}
}
void display1(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	display_background1();
     //rocket start
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();
	glTranslatef(x,y,0.0f); //moves the rocket upwards
        glScalef(0.7,0.7,0);
        display_rocket1();
	glPopMatrix(); 
	glutSwapBuffers();
	y+=2;
    	glFlush();
}

void display2(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	display_background2();
	//rocket start 
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();
	//glTranslatef(-30.0,-100.0,0.0);
	glTranslatef(x,y-1,0.0f);
        glScalef(0.85,0.85,0);
    	translate_rocket1_scene2();
	glPopMatrix();
	glutSwapBuffers();
	y+=2;
	x+=2;
	glFlush();
}

void display3(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	display_background2();
	//rocket start 
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();
	//glTranslatef(30.0,100.0,0.0);
	glTranslatef(x,y-1,0.0f);
        glScalef(0.85,0.85,0);
    	display_rocket2();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(100.0,50.0,0.0f);
	glTranslatef(x_tri,y_tri,0.0f);
        glScalef(0.85,0.85,0);
	rocket_top();
	glPopMatrix();
	glutSwapBuffers();
	y_tri-=3;
	y+=2;
	x+=2;
	glFlush();
}
void display4()
{
	glClear(GL_COLOR_BUFFER_BIT);
	//glClearColor(0.184314,0.18434,0.309804,0.0);
	//1sky
	glBegin(GL_POLYGON);
	glColor3f(0.184314,0.18434,0.309804);
	glVertex2f(0.0,0.0);
	glVertex2f(0.0,600.0);
	glVertex2f(600.0,600.0);
	glVertex2f(600.0,0.0);
	glEnd();
	glColor3f(1.0,1.0,1.0);
	//glColor3f(0.184314,0.18434,0.309804);
	glPointSize(5.0);
	display_stars_scene3();
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();
	glTranslatef(0.0,-290.0,0.0);
	display_stars_scene3();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(x3,y3+1,0.0f);
	display_rocket3();
	glPopMatrix();
	glutSwapBuffers();
	y3+=0.364;
	x3+=1;
	//printf("x=%d, y=%d\n",x,y);
	glFlush();
}

void display5()
{
	glClear(GL_COLOR_BUFFER_BIT);
	//1sky
	glBegin(GL_POLYGON);
	glColor3f(0.184314,0.18434,0.309804);
	glVertex2f(0.0,0.0);
	glVertex2f(0.0,600.0);
	glVertex2f(600.0,600.0);
	glVertex2f(600.0,0.0);
	glEnd();
	glColor3f(1.0,1.0,1.0);
	//glColor3f(0.184314,0.18434,0.309804);
	glPointSize(5.0);
	display_stars_scene3();
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();
	glTranslatef(0.0,-290.0,0.0);
	display_stars_scene3();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(x3,y3+1,0.0f);
	display_rocket4();
	glPopMatrix();
	glutSwapBuffers();
	y3+=0.364;
	x3+=1;
	//printf("x=%d, y=%d\n",x,y);
	glFlush();
}

void display6()
{ 
	glClear(GL_COLOR_BUFFER_BIT);
	//1sky
	glBegin(GL_POLYGON);
	glColor3f(0.184314,0.18434,0.309804);
	glVertex2f(0.0,0.0);
	glVertex2f(0.0,600.0);
	glVertex2f(600.0,600.0);
	glVertex2f(600.0,0.0);
	glEnd();
	glColor3f(1.0,1.0,1.0);
	//glColor3f(0.184314,0.18434,0.309804);
	glPointSize(5.0);
	display_stars_scene3();
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();
	glTranslatef(0.0,-290.0,0.0);
	display_stars_scene3();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(300.0,300.0,0.0);
	DrawPlanet();
	glPopMatrix();
	glPushMatrix();
	draw_satellite();
	glutSwapBuffers();
	glFlush();
}

void display7()
{ 
	glClear(GL_COLOR_BUFFER_BIT);
	//1sky
	glBegin(GL_POLYGON);
	glColor3f(0.184314,0.18434,0.309804);
	glVertex2f(0.0,0.0);
	glVertex2f(0.0,600.0);
	glVertex2f(600.0,600.0);
	glVertex2f(600.0,0.0);
	glEnd();
	glColor3f(1.0,1.0,1.0);
	//glColor3f(0.184314,0.18434,0.309804);
	glPointSize(5.0);
	display_stars_scene3();
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();
	glTranslatef(0.0,-290.0,0.0);
	display_stars_scene3();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(300.0,300.0,0.0);
	DrawPlanet();
	glPopMatrix();
	glPushMatrix();
	rotate_satellite();
	glutSwapBuffers();
	glFlush();
}
void reshapeScene(GLint width, GLint height)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    float ASPECT=(float)GLUT_SCREEN_WIDTH/GLUT_SCREEN_HEIGHT;
    int w = height * ASPECT;           // w is width adjusted for aspect ratio
    int left = (width - w) / 2;
    glViewport(left, 0, w, height);       // fix up the viewport to maintain aspect ratio
    gluOrtho2D(0, WIDTH,0, HEIGHT);   // only the window is changing, not the camera
    glMatrixMode(GL_MODELVIEW);

    glutPostRedisplay();
}


void reshape(int w,int h)
{
        glViewport(0,0,w,h);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        if(w<=h)
                gluOrtho2D(0.0,600.0,0.0 * (GLfloat)h/(GLfloat)w,600.0 * (GLfloat)h/(GLfloat)w);
        else
                gluOrtho2D(0.0 * (GLfloat)w/(GLfloat)h,600.0 * (GLfloat)w/(GLfloat)h,0.0,600.0);
        glMatrixMode(GL_MODELVIEW);
	glutPostRedisplay();
}

void Timer(int value) {

	switch(value)
	{
        	case 0: break;
		case 1:	glutDisplayFunc(display2);
                        break;
		case 2: glutDisplayFunc(display3);
			break;
		case 3: glutDisplayFunc(display4);
			break;
		case 4: glutDisplayFunc(display5);
			break;
		case 5: glutDisplayFunc(display6);
			break;
		case 6: glutDisplayFunc(display7);
			break;
		case 7: exit(0);
	}
	glutPostRedisplay();      // Post re-paint request to activate display()
   	glutTimerFunc(refreshMills, Timer, 0); // next Timer call milliseconds later
}

int main(int argc, char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(600.0,600.0);
	glutInitWindowPosition(0,0);
	winId1=glutCreateWindow("Scene 1");
	glutFullScreen();
	myinit();
	//glViewport(0,0,600,600);
	glutDisplayFunc(display1);
	glutReshapeFunc(reshapeScene);
        glutTimerFunc(0,Timer,0);
	x=y=0.0;
	glutTimerFunc(9000,Timer,1);
	glutTimerFunc(9900,Timer,2);
	glutTimerFunc(14000,Timer,3);
	glutTimerFunc(20000,Timer,4);
	glutTimerFunc(26000,Timer,5);
	glutTimerFunc(30000,Timer,6);
	glutTimerFunc(36000,Timer,7);
	glutMainLoop();
	return 0;
}



