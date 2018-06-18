#include "shader.h"
#include <SDL2/SDL.h>

using namespace std;

const int bufferWidth = 320;
const int bufferHeight = 180;

unsigned char buffer[bufferWidth * bufferHeight * 3 / 2];
unsigned char* plane[3];

GLuint textureY, textureU, textureV;
GLuint VBO;

GLfloat vertices[] = {
    1.0f, 1.0f, 0.0f, 1.0f, 1.0f,
    1.0f, -1.0f, 0.0f, 1.0f, 0.0f,
    -1.0f, 1.0f, 0.0f, 0.0f, 1.0f,
    1.0f, -1.0f, 0.0f, 1.0f, 0.0f,
    -1.0f, -1.0f, 0.0f, 0.0f, 0.0f,
    -1.0f, 1.0f, 0.0f, 0.0f, 1.0f
};

void setGLAttibute()
{
    SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_ES);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
    
}

void setTexture()
{
    glGenTextures(1, &textureY); 
    glBindTexture(GL_TEXTURE_2D, textureY);    
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    
    glGenTextures(1, &textureU);
    glBindTexture(GL_TEXTURE_2D, textureU);   
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    
    glGenTextures(1, &textureV); 
    glBindTexture(GL_TEXTURE_2D, textureV);    
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
}

void setVertex( Shader& shader)
{
    glGenBuffers(1, &VBO);
//    if(VBO == 0)
//    {
//        cout << "Fail to create VBO" << endl;
//        return false;
//    }
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    GLuint vertexLoc = glGetUniformLocation(shader.ID, "aPos");
    GLuint texLoc = glGetUniformLocation(shader.ID, "aTexcoord");

    glVertexAttribPointer(vertexLoc, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GL_FLOAT), (void*)NULL);
    glEnableVertexAttribArray(vertexLoc);

    glVertexAttribPointer(texLoc, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GL_FLOAT), (void*)(3*sizeof(GL_FLOAT)));
    glEnableVertexAttribArray(texLoc);
    
}

void display(FILE* fp, Shader& shader)
{
    if(fread(buffer, 1, bufferWidth*bufferHeight*3/2, fp) != bufferWidth*bufferHeight*3/2)
    {
        fseek(fp, 0, SEEK_SET);
        fread(buffer, 1, bufferWidth*bufferHeight*3/2, fp);
    }

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //Y
    glActiveTexture(GL_TEXTURE0);
    shader.setInt("textureY", 0);

    glBindTexture(GL_TEXTURE_2D, textureY);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_LUMINANCE, bufferWidth, bufferHeight, 0, GL_LUMINANCE, GL_UNSIGNED_BYTE, plane[0]);

    //U
    glActiveTexture(GL_TEXTURE1);
    shader.setInt("textureU", 1);

    glBindTexture(GL_TEXTURE_2D, textureU);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_LUMINANCE, bufferWidth/2, bufferHeight/2, 0, GL_LUMINANCE, GL_UNSIGNED_BYTE, plane[1]);

    //V
    glActiveTexture(GL_TEXTURE2);
    shader.setInt("textureV", 2);

    glBindTexture(GL_TEXTURE_2D, textureV);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_LUMINANCE, bufferWidth/2, bufferHeight/2, 0, GL_LUMINANCE, GL_UNSIGNED_BYTE, plane[2]);

    glDrawArrays(GL_TRIANGLES, 0, 6);
}

int main()
{
    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO))
    {
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        return -1;
    }

    setGLAttibute();
    SDL_Window* window = SDL_CreateWindow("yuvPlayer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_OPENGL);
    if(window == NULL)
    {
        SDL_Log("Fail to create window: %s", SDL_GetError());
        return -1;
    }

    SDL_GLContext context = SDL_GL_CreateContext(window);
    if(context == NULL)
    {
        SDL_Log("Fail to create SDL context: %s", SDL_GetError());
        return -1;
    }

    int ret = SDL_GL_MakeCurrent(window, context);
    if(ret != 0)
    {
        SDL_Log("Fail in make current context: %s", SDL_GetError());
        return -1;
    }

    FILE* fp = fopen("test_yuv420p_320x180.yuv", "rb");
    if(fp == NULL)
    {
        cout << "Fail to open yuv file" << std::endl;
        return -1;
    }

    plane[0] = buffer;
    plane[1] = plane[0] + bufferWidth * bufferHeight;
    plane[2] = plane[1] + bufferWidth * bufferHeight / 4;

    Shader shader("simple.vs", "simple.fs");

    setVertex(shader);

    int running = 1;
    while(running)
    {
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        display(fp, shader);
        SDL_GL_SwapWindow(window);
        
    }

    return 0;

}
