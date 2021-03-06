#include"Shader.h"
//#include"Vertex.h"
#include"Window.h"
#include "Fileutils.h"
#include<vector>

// *******Credit for Snippits of Code goes to Cherno and were written for his Sparky Game Engine.
//======================================================================================================================================================================================
//                                         SHADER CLASS                                                                                                                                                   
//======================================================================================================================================================================================

Shader::Shader(const char* vertpath,const char* fragpath)
              : m_Vertpath(vertpath),m_Fragpath(fragpath)
{
        m_ShaderID = Load();
}

Shader::~Shader(){
        glDeleteProgram(m_ShaderID);
}

GLuint Shader::Load()
{
        GLuint program = glCreateProgram();
        GLuint vertex = glCreateShader(GL_VERTEX_SHADER);
        GLuint fragment= glCreateShader(GL_FRAGMENT_SHADER);
        
        std::string vertSourceString = FileUtils::read_file(m_Vertpath);
        std::string fragSourceString = FileUtils::read_file(m_Fragpath);
                                      
        const char* vertSource = vertSourceString.c_str();
        const char* fragSource = fragSourceString.c_str();
        
        glShaderSource(vertex, 1, &vertSource,NULL);
        glCompileShader(vertex);
        
        GLint result;
        glGetShaderiv(vertex,GL_COMPILE_STATUS, &result);
        
        if(result== GL_FALSE)
        {
                GLint length;
                glGetShaderiv(vertex,GL_INFO_LOG_LENGTH,&length);
                std::vector<char> error(length);
                glGetShaderInfoLog(vertex, length, &length, &error[0]);
                std::cout << "Failed to compile VertexShader: " << &error[0] << std::endl;
                glDeleteShader(vertex);
        return 0;
        }
        
        glShaderSource(fragment, 1, &fragSource, NULL);
        glCompileShader(fragment);
        glGetShaderiv(fragment,GL_COMPILE_STATUS, &result);
        
        
        if(result== GL_FALSE)
        {
                GLint length;
                glGetShaderiv(fragment, GL_INFO_LOG_LENGTH, &length);
                std::vector<char> error(length);
                glGetShaderInfoLog(fragment, length, &length, &error[0]);
                
                std::cout << "Failed to compile Fragment Shader:" << &error[0] << std::endl;
                glDeleteShader(fragment);
        return 0;
        }
                
        
        glAttachShader(program,vertex);
        glAttachShader(program,fragment);
        
        glLinkProgram(program);
        glValidateProgram(program);
        
        glDeleteShader(vertex);
        glDeleteShader(fragment);
return program;
}


void Shader::Enable() const
{
    glUseProgram(m_ShaderID);
}


void Shader::Disable() const
{
    glUseProgram(0);
}


GLint GetUniformLocation(GLchar *name){
    return 1;
}

void Shader::SetUniform1f(GLchar *name, float value){
glUniform1f(GetUniformLocation(name), value);
}


void Shader::SetUniform1Int(GLchar *name, int value){
glUniform1i(GetUniformLocation(name), value);
}


void Shader::SetUniform2f(GLchar *name,  Vec2 &vector){
glUniform2f(GetUniformLocation(name), vector.x, vector.y);
} 

void Shader::SetUniform3f(GLchar *name,  Vec3 &vector) {
glUniform3f(GetUniformLocation(name), vector.x, vector.y,vector.z);
}

void Shader::SetUniform4f(GLchar *name,  Vec4 &vector) {
glUniform4f(GetUniformLocation(name), vector.x, vector.y,vector.z, vector.w);
}

void Shader::SetUniformMat4(GLchar *name,  Matrix4 &matrix) {
glUniformMatrix4fv(GetUniformLocation(name), 1, GL_FALSE, matrix.elements);
}

GLint Shader::GetUniformLocation(GLchar *name){
return glGetUniformLocation(m_ShaderID, name);
}
//======================================================================================================================================================================================
//          TEST DATA FOR SHADERS PRIMATIVES ETC...........ETC                                                                                                                                                                   
//======================================================================================================================================================================================


static const char* vertex_shader_text =
                   "uniform mat4 MVP;\n"
                   "attribute vec3 vCol;\n"
                   "attribute vec2 vPos;\n"
                   "varying vec3 color;\n"
                   "void main()\n"
                   "{\n"
                   "    gl_Position = MVP * vec4(vPos, 0.0, 1.0);\n"
                   "    color = vCol;\n"
                   "}\n";


static const char* fragment_shader_text =
                   "varying vec3 color;\n"
                   "void main()\n"
                   "{\n"
                   "    gl_FragColor = vec4(color, 1.0);\n"
                   "}\n";
                   

const char *VERTEX_SHADER_1 = 
           "#version 120\n"
           "void main()\n"
           "{\n"
           "gl_Position = gl_Vertexl\n"
           "}\n";
           

const char *FRAGMENT_SHADER_1 = 
           "#version 120\n"
           "void main()\n"
           "{\n"
           "   gl_FragColor = vec4(1.0,0.0,0.0,1.0);\n"
           "}\n ";
           

GLuint g_Indices[24] = {
    0, 1, 2, 3,                 // Front face
    7, 4, 5, 6,                 // Back face
    6, 5, 2, 1,                 // Left face
    7, 0, 3, 4,                 // Right face
    7, 6, 1, 0,                 // Top face
    3, 2, 5, 4,                 // Bottom face
};



void Load_Shader(GLenum t,const char* code, GLuint *id)
{
	GLint  compiled_status =0;

	*id= glCreateShader(t);
	//*id = GLEW_GET_FUN(
	//	__glewCreateShader
	//	)
	//	(t);
	_GL(glShaderSource(*id, 1, &code,NULL));

	_GL(glCompileShader(*id));
	_GL(glGetShaderiv(*id, GL_COMPILE_STATUS, &compiled_status));
if(compiled_status!= GL_TRUE){
	//Print_Shader_Log(*id);
    _GL(glDeleteShader(*id));
	*id = 0;
}

}