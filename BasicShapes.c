#include "CSCIx229.h"
#include "BasicShapes.h"


void normalV(double x1, double y1, double z1, double x2, double y2, double z2, double x3, double y3,  double z3){
   normalX = (y2-y1)*(z3-z1)-(z2-z1)*(y3-y1);
   normalY = (z2-z1)*(x3-x1)-(x2-x1)*(z3-z1); 
   normalZ = (x2-x1)*(y3-y1)-(y2-y1)*(x3-x1);
}

void shinyMetal(){
   float white[] = {1,1,1,1};
   glMaterialf(GL_FRONT,GL_SHININESS,100);
   glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,white);
   diffuse = 10; specular = 90;
   float Diffuse[]   = {0.01*diffuse ,0.01*diffuse ,0.01*diffuse ,1.0};
   float Specular[]  = {0.01*specular,0.01*specular,0.01*specular,1.0};

   glLightfv(GL_LIGHT0,GL_DIFFUSE ,Diffuse);
   glLightfv(GL_LIGHT0,GL_SPECULAR,Specular);
}

void notShiny(){
   float white[] = {1,1,1,1};
   glMaterialf(GL_FRONT,GL_SHININESS,10);
   glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,white);
   diffuse = 90; specular = 10;
   float Diffuse[]   = {0.01*diffuse ,0.01*diffuse ,0.01*diffuse ,1.0};
   float Specular[]  = {0.01*specular,0.01*specular,0.01*specular,1.0};

   glLightfv(GL_LIGHT0,GL_DIFFUSE ,Diffuse);
   glLightfv(GL_LIGHT0,GL_SPECULAR,Specular);
}

static void TexVertex(int th,int ph, float degrees, int scaleFactor)
{
   double x = -Sin(th)*Cos(ph);
   double y =  Cos(th)*Cos(ph);
   double z =          Sin(ph);
   glNormal3d(x,y,z);

   if (causticsPass == 0) glTexCoord2d(th/degrees * scaleFactor,ph/(degrees/2) * scaleFactor + 0.5);
   glVertex3d(x,y,z);
}

void Sphere(int textureIndex, int scaleFactor, unsigned int tex, float degrees)
{
   ErrCheck("Sphere Start");
   int th,ph;

   /*
    *  Draw surface of the planet
    */
   //  Set texture
   if (causticsPass == 0) {
      glEnable(GL_TEXTURE_2D);
      glTexEnvi(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_MODULATE);
      glBindTexture(GL_TEXTURE_2D,tex);
   }
   //  Latitude bands
   //glColor3f(1,1,1);
   for (ph=-90;ph<90;ph+=5)
   {
      glBegin(GL_QUAD_STRIP);
      for (th=0;th<=degrees;th+=5)
      {
         TexVertex(th,ph, degrees, scaleFactor);
         TexVertex(th,ph+5, degrees, scaleFactor);
      }
      glEnd();
   }
   if (causticsPass == 0) {
      glDisable(GL_TEXTURE_2D);
   }
      ErrCheck("Sphere End");
}

void drawCylinder(int numMajor, int numMinor, float height, float radius, unsigned int crabTexture) {
   ErrCheck("Cylinder Start");
   //Based off this source but modified greatly for lighting: http://www.unix.com/programming/124875-draw-3d-cylinder-using-opengl.html
   notShiny();
   double majorStep = height / numMajor;
   double minorStep = 2.0 * M_PI / numMinor;
   int i, j;
   if (causticsPass == 0) {
      glEnable(GL_TEXTURE_2D);
      glTexEnvi(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_MODULATE);
      glBindTexture(GL_TEXTURE_2D,crabTexture);
   }
   for (i = 0; i < numMajor; ++i) {
      float z0 = 0.5 * height - i * majorStep;
      float z1 = z0 - majorStep;

      glBegin(GL_TRIANGLE_STRIP);
      for (j = 0; j <= numMinor; j++) {
         double a = j * minorStep;
         double b = (j+1) * minorStep;

         float x1 = radius * cos(a);
         float y1 = radius * sin(a);
         float x2 = radius * cos(b);
         float y2 = radius * sin(b);

         glTexCoord2f(i/minorStep/32, i/minorStep/32); glVertex3f(x1, y1, z0);
         glTexCoord2f(i/minorStep/32, j/majorStep/32); glVertex3f(x1, y1, z1);
         glTexCoord2f(j/majorStep/32, i/minorStep/32); glVertex3f(x2, y2, z0);
         normalV(x1, y1, z0, x1, y1, z1, x2, y2, z0);
         glNormal3f(normalX, normalY, normalZ);

         glTexCoord2f(j/majorStep/32, i/minorStep/32); glVertex3f(x2, y2, z0);
         glTexCoord2f(j/majorStep/32, j/majorStep/32); glVertex3f(x2, y2, z1);
         glTexCoord2f(i/minorStep/32, j/majorStep/32); glVertex3f(x1, y1, z1);
         normalV(x2, y2, z0, x1, y1, z1, x2, y2, z1);
         glNormal3f(normalX, normalY, normalZ);
      }
   }
   glEnd();
   if (causticsPass == 0) {
      glDisable(GL_TEXTURE_2D);
   }
      ErrCheck("Cylinder End");
      
}

void eyeball(double x,double y,double z,double r, unsigned int eyeTexture) {
   ErrCheck("Eyeball Start");
   shinyMetal();
   //Whites of eye
   //ball(x, y, z, r, 2);

   //Pupil
   //ball(x, y, 2*z + r * 3 / 4, r/2, 3);
   glPushMatrix();
   glTranslated(x,y,z);
   glRotated(-90, 1, 0, 0);
   glScaled(r,r,r);
   //BlueEye();
   Sphere(1, 1, eyeTexture, 360);
   glPopMatrix();
   ErrCheck("Eyeball End");
}