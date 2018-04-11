#pragma once
#include<vector>
#include"Vertex.h"
#include"Window.h"

using namespace std;

class Buffer{
public:
        Buffer();
       ~Buffer();
        Buffer(GLfloat *data,GLsizei count,GLint componentcount);
        
        void Bind();
        void Unbind();
public:
        inline GLuint Get_Component(){return NUM_COMPONENTS;}
        inline GLint Get_Count(){return COUNT;}
private:
        GLuint COUNT;
        GLuint BUFFER_ID;
        GLuint NUM_COMPONENTS; //How many vertex per count
};

class IndexBuffer{
public:
        IndexBuffer();
       ~IndexBuffer();
        IndexBuffer(GLushort *data,GLsizei count);
public:
        void Bind();
        void Unbind();
      inline GLushort Get_Count(){return COUNT;}
  
private:
        GLsizei COUNT; // Number of Indices
        GLuint  BUFFER_ID;
};


class VertexArray{/*      THIS MOTHER FUCKER RIGHT HERE HAS WASTED A WEEK OR SO OF MY FUCKING LIFE RESEARCHING SHIT !!! FUCK YOU VAO !!!*/
public:
    VertexArray();
   ~VertexArray();

    GLuint ARRAY_ID;
    vector<Buffer*> BUFFERS;

    void Bind();
    void Unbind();
    void Addbuffer (Buffer *buffer, GLuint index);
};




class Renderer{
public: 
     
     void Submit();
     void Flush_Renderer();

   private:
       vector<Matrix4> Transformation_Stack;

       void Push(Matrix4 mat4);
       Matrix4 Pop();
};



















/*

//=============================================================================================================================================
//_______________________________________________________________________________________________________________________________________________________________



//=============================================================================================================================================
//________________TEST STRUCTURES TO HANDLE THE VAO Issues___________________________________________________________________________________________________________________________

struct VertexFormat
{
  bool enabled;
  int attribute_index;
  float data_type; //Is f32, f64, or int32.
  int num_components;
  bool normalized;
  GLenum type;
  int binding;    //The `bindings` index this attribute gets its data from.
  int *offset;
};

struct VertexBufferBinding// Mesh
{
  Buffer buffer;// VBO
  int  *offset; // Number of Vertices 
  int  *stride;
  int instancing;
};

struct VertexArrayObject
{
  VertexFormat formats[16];
  VertexBufferBinding bindings[16];
};



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////





// Renderable2d = BatchSprite
class Renderable2D{
public:
    Renderable2D::Renderable2D();
    Renderable2D::~Renderable2D();

    Vec3 Position;
    Vec2 Size;
    Vec4 Color;
    vector<VertexData> VertexArray;
    IndexBuffer *IBO;
    GLuint VBO;

    unsigned int IndexCount;
    Shader &SHADER;


};



class Renderer2D{
public:
    virtual void submit(const Renderable2D *renderable);
    virtual void flush();
};














#define RENDERER_MAX_SPRITES 10000
#define RENDERER_VERTEX_SIZE   sizeof(VertexData)
#define RENDERER_SPRITE_SIZE RENDERER_VERTEX_SIZE * 4
#define RENDERER_BUFFER_SIZE RENDERER_SPRITE_SIZE * RENDERER_MAX_SPRITES
#define RENDERER_INDICES_SIZE RENDERER_MAX_SPRITES * 6
struct VertexData{
    Vec3 Vertex;
    Vec3 Color;
}; // 28 Bytes Currently
 


class BatchRender2D: public Renderer2D{
private:
    //VertexArray VAO;
    IndexBuffer IBO;
    GLsizei IndexCount;
    GLuint VBO;
public:
    void submit(const Renderable2D *BatchSprite) override;
    void flush() override;

};




BatchSprite::BatchSprite(){}

BatchSprite::~BatchSprite(){
    delete(IBO);
}




void BatchSprite::Init(){
    
}
*/