//                                                                                                                                                                        
//                                                  OPENGL 2.0 Abstraction API
//                                                       January 27 2018
//                                                      -----------------                                                                                                                                                        
//                                                                                                                                                                        
//                                                                                                                                                                        
//                                               OPEN_GL 3D OBJECT MANAGEMENT LIB                                                                                                                     
//   MOSTLY EXPERIMENTAL WIP                                                                                                                                                                     
//============================================================================================================================================ 
#pragma once

#include<vector>
#include"vertex.h"
#include"Window.h"
#include"Renderer.h"
#include"Collision.h"
#include"Shader.h"
 
#define   WorldSizeX   20
#define   WorldSizeZ   20
#define   GridSizeX    50
#define   GridSizeZ    50
#define WX (WorldSizeX * GridSizeX)
#define WZ (WorldSizeZ * GridSizeZ)
//
//struct Vertex{
//    Vec3 Position;
//    Vec3 Normal;
//    Vec2 Texture;
//};
//
//
struct MetaData
{
    Vec3 Normals;
    Vec3 Color;
    Vec2 Texture;
}; // This should make the MetaData 32 Bit for easy compression


class CollisionSphere;

//============================================================================================================================================
//_______________________________________________ SPHERE CLASS _______________________________________________________________________________
//============================================================================================================================================
 

class Sphere{
public:
     Vec3 Position;
     Vec3 Rotation;
     Vec3 Scale;

     int Mesh_ID;
     int CollisionID;
     float Radius;

public:// OpenGL Stuff

     Sphere(){}  
     Sphere(Vec3 pos, float radius, int sectors);

     Vec3  Vertices[648];
     GLuint Indices[972];
     RGBf  Colors  [648];

     GLuint VertexCount;
     GLuint ColorCount;

//     Buffer Vbo;

     VAOBuffer VAO;

// Shader SHADER;

     void Set_Position(float x, float y, float z)    {Position = Vec3(x,y,z);}
     void Set_Position(Vec3 pos)                     {Position = pos;}
     void Set_Rotation(float x, float y, float z)    {Rotation = Vec3(x,y,z);}
     void Rotate(float x, float y, float z); 
     void SetRotation(Vec3 rot)                      {Rotation = rot;}

     Vec3 Get_Position(){return Position;}
     Vec3 Get_Rotation(){return Rotation;}

     Vec3 GetVert(int index){return Vertices[index];}
     void ChangeVert(int index, Vec3 newpos);
     void Submit(); // <---- Set this up to Update the Vertex or ColorBuffer

     void Update();
     void Render();

private:
     void CollisionDetection();

// Static object list
public:
     static std::vector<Sphere*> s_SphereList;

     static unsigned int SphereCount;
     static int MakeCollisionSphere(Vec3 pos, float rad, int p);

     static void Batch();
     static void BatchBuild();

     static std::vector<Vec3>   B_Vertices;
     static std::vector<GLuint> B_Indices;
     static std::vector<RGBf>   B_Colors; 

     static VAOBuffer BatchVAO;
     static bool BatchMade;

};



struct Poly{
    Vec3 *P1;
    Vec3 *P2;
    Vec3 *P3;
    Vec3 Normal;
};


//============================================================================================================================================
//__________________________________________ TERRAIN CLASS ___________________________________________________________________________________
//============================================================================================================================================


#include<memory>



 class Terrain
 {
 public:
     Terrain(){}
     Terrain(int w, int d, int gw, int gd);
     ~Terrain();
        int width; // x-axis
        int depth; // z-axis, y is up
        int gridw; // distance between heights on x-axis
        int gridd; // distance between heights on z-axis

        float *Heights;
        
int     VertexCount,
        ColorsCount;
        
        VAOBuffer VAO;
        
        Vec3 Position; 
        
//        MetaData *Data;
        
        int IndexCount;
        int NormalCount;

        int Get_Vertex(int x, int z){ return (x + width * z);}

        float Lerp(float a, float b, float c);
        float SampleTerrain(float x, float z, Sphere *Ball);
        Vec3  CollisionDetection(CollisionSphere ball);
        Vec3  TerrainNormal(float x, float y);
      
        void Delete();
        void Render();
        
        bool View;

static Terrain *GROUND;
 };
//==========================================================================================================================================
//__________________________________________________________________________________________________________________________________________
//==========================================================================================================================================
 
extern Vec3 GetNormal(Vec3 v1, Vec3 v2, Vec3 v3);


class Mesh
{
public:
        Mesh(){}
        Vec3 Rotation;
        Vec3 Position;
        Vec3 Scale;
        
        GLint List;
        Vec3  *Vertices;
        RGBf  *Colors  ;
        
        GLuint VertexCount;
        GLuint ColorCount;


        void Set_Position(float x, float y, float z)    { Position = Vec3(x,y,z);}
        void Set_Position(Vec3 pos)                     { Position = pos;}       
        void Set_Rotation(float x, float y, float z)    { Rotation = Vec3(x,y,z);}   
        void SetRotation(Vec3 rot)                      { Rotation = rot;} 

        void Rotate(float x, float y, float z);
        void Render();
        void RenderVBO();
        
        Vec3 Get_Position(){return Position;}
        Vec3 Get_Rotation(){return Rotation;}
        
        Vec3 GetVert(int index){return Vertices[index];}
        
        
        enum objecttype
        {
            Torus_t,
            Sphere_t,
            Cube_t
        }ObjectType;
};

class Torus: public Mesh
{
public:
    Torus(int numc, int numt, float x, float y, float z, float scale);
    Torus(int numc, int numt, float x, float y, float z);

   // Buffer *VBO;

    void Set_Position(float x, float y, float z);
    void Set_Rotation(float x, float y, float z);

    void Rotate(float x, float y, float z);
    void Render();
    void RenderVBO();
};
class Cube : public Mesh
{
public:
    Cube(Vec3 pos, float size);

    void Set_Position(float x, float y, float z);
    void Set_Rotation(float x, float y, float z);

    void Rotate(float x, float y, float z);
    void Render();
};
