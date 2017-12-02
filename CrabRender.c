#include "CSCIx229.h"
#include "CrabRender.h"
#include "BasicShapes.h"

void crabBody(double x,double y,double z,double r, unsigned int crabShell)
{
   ErrCheck("CrabBody Start");
   notShiny();
   glPushMatrix();
   glTranslated(x,y,z);
   glScaled(r,r,r);
   Sphere(3, 1, crabShell, 360);
   glPopMatrix();
   ErrCheck("CrabBody End");
}


void claw(unsigned int crabBody) {
   ErrCheck("Claw Start");
   notShiny();
   if (causticsPass == 0) {
      glEnable(GL_TEXTURE_2D);
      glTexEnvi(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_MODULATE);
      glBindTexture(GL_TEXTURE_2D,crabBody);
   }
   glBegin(GL_QUADS);

   //  Front

   glNormal3f( 0, 0, 1);
   glColor3f(1, 1, 1); glTexCoord2d(0,0); glVertex3f(-1,-1, 1);
   glColor3f(1, 1, 1); glTexCoord2d(0,1); glVertex3f(+1,-1, 1);
   glColor3f(1, 1, 1); glTexCoord2d(1,1); glVertex3f(+1,+1, 1);
   glColor3f(1, 1, 1); glTexCoord2d(1,0); glVertex3f(-1,+1, 1);
   //  Back

   glNormal3f( 0, 0,-1);
   glColor3f(1, 1, 1); glTexCoord2d(0,0); glVertex3f(+1,-1,-1);
   glColor3f(1, 1, 1); glTexCoord2d(0,1); glVertex3f(-1,-1,-1);
   glColor3f(1, 1, 1); glTexCoord2d(1,1); glVertex3f(-1,+1,-1);
   glColor3f(1, 1, 1); glTexCoord2d(1,0); glVertex3f(+1,+1,-1);

   //  Right

   glNormal3f(+1, 0, 0);
   glColor3f(1, 1, 1); glTexCoord2d(0,0); glVertex3f(+1,-1,+1);
   glColor3f(1, 1, 1); glTexCoord2d(0,1); glVertex3f(+1,-1,-1);
   glColor3f(1, 1, 1); glTexCoord2d(1,1); glVertex3f(+1,+1,-1);
   glColor3f(1, 1, 1); glTexCoord2d(1,0); glVertex3f(+1,+1,+1);
   //  Left

   glNormal3f(-1, 0, 0);
   glColor3f(1, 1, 1); glTexCoord2d(0,0); glVertex3f(-1,-1,-1);
   glColor3f(1, 1, 1); glTexCoord2d(0,1); glVertex3f(-1,-1,+1);
   glColor3f(1, 1, 1); glTexCoord2d(1,1); glVertex3f(-1,+1,+1);
   glColor3f(1, 1, 1); glTexCoord2d(1,0); glVertex3f(-1,+1,-1);
   //  Top

   glNormal3f( 0,+1, 0);
   glColor3f(1, 1, 1); glTexCoord2d(0,0); glVertex3f(-1,+1,+1);
   glColor3f(1, 1, 1); glTexCoord2d(0,1); glVertex3f(+1,+1,+1);
   glColor3f(1, 1, 1); glTexCoord2d(1,1); glVertex3f(+1,+1,-1);
   glColor3f(1, 1, 1); glTexCoord2d(1,0); glVertex3f(-1,+1,-1);
   //  Bottom

   glNormal3f( 0,-1, 0);
   glColor3f(1, 1, 1); glTexCoord2d(0,0); glVertex3f(-1,-1,-1);
   glColor3f(1, 1, 1); glTexCoord2d(0,1); glVertex3f(+1,-1,-1);
   glColor3f(1, 1, 1); glTexCoord2d(1,1); glVertex3f(+1,-1,+1);
   glColor3f(1, 1, 1); glTexCoord2d(1,0); glVertex3f(-1,-1,+1);
   //  End
   glEnd();

   //Upper Pinscher
   glColor3f(1, 1, 1);
   glBegin(GL_TRIANGLES);

   normalV(0, 4, 0, 1, 1, 1, 1, 1, -1);
   glNormal3f(normalX, normalY, normalZ);
   glTexCoord2d(.5, .5); glVertex3f(0, 4, 0);
   glTexCoord2d(1,1); glVertex3f(1, 1, 1);
   glTexCoord2d(1,0); glVertex3f(1, 1, -1);

   normalV(0, 4, 0, 1, 1, -1, -1, 1, -1);
   glNormal3f(normalX, normalY, normalZ);
   glTexCoord2d(.5, .5); glVertex3f(0, 4, 0);
   glTexCoord2d(1,0); glVertex3f(1, 1, -1);
   glTexCoord2d(0,0); glVertex3f(-1, 1, -1);

   normalV(0, 4, 0, -1, 1, -1, -1, 1, 1);
   glNormal3f(normalX, normalY, normalZ);
   glTexCoord2d(.5, .5); glVertex3f(0, 4, 0);
   glTexCoord2d(0,0); glVertex3f(-1, 1, -1);
   glTexCoord2d(0,1); glVertex3f(-1, 1, 1);


   normalV(0, 4, 0, -1, 1, 1, 1, 1, 1);
   glNormal3f(normalX, normalY, normalZ);
   glTexCoord2d(.5, .5); glVertex3f(0, 4, 0);
   glTexCoord2d(0,1); glVertex3f(-1, 1, 1);
   glTexCoord2d(1,1); glVertex3f(1, 1, 1);

   glEnd();

   //Side Pinscher
   glBegin(GL_TRIANGLES);
   normalV(4, 0, 0, 1, 1, 1, 1, -1, 1);
   glNormal3f(normalX, normalY, normalZ);
   glTexCoord2d(.5, .5); glVertex3f(4, 0, 0);
   glTexCoord2d(1,1); glVertex3f(1, 1, 1);
   glTexCoord2d(0,1); glVertex3f(1, -1, 1);

   normalV(4, 0, 0, 1, -1, 1, 1, -1, -1);
   glNormal3f(normalX, normalY, normalZ);
   glTexCoord2d(.5, .5); glVertex3f(4, 0, 0);
   glTexCoord2d(0,1); glVertex3f(1, -1, 1);
   glTexCoord2d(0,0); glVertex3f(1, -1, -1);
   
   normalV(4, 0, 0, 1, -1, -1, 1, 1, -1);
   glNormal3f(normalX, normalY, normalZ);
   glTexCoord2d(.5, .5); glVertex3f(4, 0, 0);
   glTexCoord2d(0,0); glVertex3f(1, -1, -1);
   glTexCoord2d(1,0); glVertex3f(1, 1, -1);
   
   normalV(4, 0, 0, 1, 1, -1, 1, 1, 1);
   glNormal3f(normalX, normalY, normalZ);
   glTexCoord2d(.5, .5); glVertex3f(4, 0, 0);
   glTexCoord2d(1,0); glVertex3f(1, 1, -1);
   glTexCoord2d(1,1); glVertex3f(1, 1, 1);

   glEnd();
   if (causticsPass == 0) {
      glDisable(GL_TEXTURE_ENV);
   }
   ErrCheck("Claw End");
}

void crab(unsigned int crabShell, unsigned int eyeTexture) {
   ErrCheck("Crab Start");
   //Body
   glPushMatrix();
   glScalef(1, .5, 1);
   //crabBody(0, 0, 0, 1);
   crabBody(0, 0, 0, 1, crabShell);
   glPopMatrix();
   ErrCheck("Body");
   //Arms
   glColor3f(1,0,0);
   glPushMatrix();
   glTranslatef(.9, .3, 0);
   glRotatef(90, 1, 0, 0);
   glRotatef(-20, 0, 1, 0);
   drawCylinder(30, 20, 1, .1, crabShell);
   glPopMatrix();
   ErrCheck("Arm1");
   glPushMatrix();
   glTranslatef(-.9, .3, 0);
   glRotatef(90, 1, 0, 0);
   glRotatef(20, 0, 1, 0);
   drawCylinder(30, 20, 1, .1, crabShell);
   glPopMatrix();
   ErrCheck("Arm2");

   //Claws
   glPushMatrix();
   glTranslatef(-1.1, 1, 0);
   glRotatef(25, 0,0,1);
   glScalef(.2, .3, .2);
   claw(crabShell);
   glPopMatrix();
   ErrCheck("Claw1");

   glPushMatrix();
   glTranslatef(1.1, 1, 0);
   glRotatef(-25, 0,0,1);
   glRotatef(180, 0, 1, 0);
   glScalef(.2, .3, .2);
   claw(crabShell);
   glPopMatrix();
   ErrCheck("Claw2");

   //Antenna
   glPushMatrix();
   glTranslatef(.2, .325, 0);
   glRotatef(90, 1, 0, 0);
   drawCylinder(30, 20, 1.4, .03, crabShell);
   glPopMatrix();
      ErrCheck("Antenna1");


   glPushMatrix();
   glTranslatef(-.2, .325, 0);
   glRotatef(90, 1, 0, 0);
   drawCylinder(30, 20, 1.4, .03, crabShell);
   glPopMatrix();
      ErrCheck("Antenna2");


   //Eyes
   glPushMatrix();
   glTranslatef(.2, 1.125, 0);
   glRotatef(90, 0, 0, 1);
   eyeball(0, 0, 0, .2, eyeTexture);
   glPopMatrix();
      ErrCheck("Eyeball1");


   glPushMatrix();
   glTranslatef(-.2, 1.125, 0);
   glRotatef(90, 0, 0, 1);
   eyeball(0, 0, 0, .2, eyeTexture);
   glPopMatrix();
      ErrCheck("Eyeball2");


   //Legs
   glColor3f(1, 0, .4);
   glPushMatrix();
   glTranslatef(.9, -.3, 0);
   glRotatef(90, 1, 0, 0);
   glRotatef(-340, 0, 1, 0);
   drawCylinder(30, 20, 1, .05, crabShell);
   glPopMatrix();
      ErrCheck("Leg1");


   glPushMatrix();
   glTranslatef(-.9, -.3, 0);
   glRotatef(90, 1, 0, 0);
   glRotatef(340, 0, 1, 0);
   drawCylinder(30, 20, 1, .05, crabShell);
   glPopMatrix();
      ErrCheck("Leg2");


   glPushMatrix();
   glTranslatef(-.9, -.3, .6);
   glRotatef(60, 1, 0, 0);
   glRotatef(340, 0, 1, 0);
   drawCylinder(30, 20, 1, .05, crabShell);
   glPopMatrix();
      ErrCheck("Leg3");


   glPushMatrix();
   glTranslatef(.9, -.3, .6);
   glRotatef(60, 1, 0, 0);
   glRotatef(-340, 0, 1, 0);
   drawCylinder(30, 20, 1, .05, crabShell);
   glPopMatrix();
      ErrCheck("Leg4");


   glPushMatrix();
   glTranslatef(.9, -.3, -.6);
   glRotatef(300, 1, 0, 0);
   glRotatef(340, 0, 1, 0);
   drawCylinder(30, 20, 1, .05, crabShell);
   glPopMatrix();
      ErrCheck("Leg5");


   glPushMatrix();
   glTranslatef(-.9, -.3, -.6);
   glRotatef(300, 1, 0, 0);
   glRotatef(-340, 0, 1, 0);
   drawCylinder(30, 20, 1, .05, crabShell);
   glPopMatrix();
   ErrCheck("Crab End");
}