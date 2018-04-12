#include"Lights.h"
 int LightSource::NumberOfLights;

//----------------------- ----------------------------------
LightSource::LightSource(Vec3 pos, RGBf alight, RGBf dlight, RGBf slight)
        : LightNumber(NumberOfLights++)
    {
            GLfloat a[] = {alight.r,alight.g,alight.b,1};
            GLfloat d[] = {dlight.r,dlight.g,dlight.b,1};
            GLfloat s[] = {slight.r,slight.g,slight.b,1};
           
           glLightf(0,GL_AMBIENT, *pos.Coord);
           
           glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
           glEnable(GL_LIGHTING);
           glEnable(GL_LIGHT0+LightNumber);
           
           glLightfv(GL_LIGHT0+LightNumber, GL_AMBIENT,a);
           glLightfv(GL_LIGHT0+LightNumber, GL_DIFFUSE,d);
           glLightfv(GL_LIGHT0+LightNumber, GL_SPECULAR,s);
           
           SetPosition(pos, pos);
           glEnable(GL_COLOR_MATERIAL);
   }

 
 
    void LightSource::SetAmbient(RGBAf color)
    {
        glLightfv(GL_LIGHT0+LightNumber, GL_AMBIENT,color.Coords);
    }
    void LightSource::SetSpecular(RGBAf color)
    {
        glLightfv(GL_LIGHT0+LightNumber, GL_SPECULAR,color.Coords);
    }
    void LightSource::SetDiffuse(RGBAf color)
    {
        glLightfv(GL_LIGHT0+LightNumber, GL_DIFFUSE,color.Coords);
    }
    void LightSource::SetPosition(Vec3 position, Vec3 direction)
    {
        glLightfv(GL_LIGHT0 + LightNumber, GL_POSITION, position.Coord);
    }