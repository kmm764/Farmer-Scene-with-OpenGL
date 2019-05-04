#include "Skybox.h"


//Skybox::Skybox();
Skybox::Skybox(GLuint tTop, GLuint tBottom, GLuint tLeft, GLuint tRight, GLuint tFront, GLuint tBack):
_tTop(tTop), _tBottom(tBottom), _tLeft(tLeft), _tRight(tRight), _tFront(tFront), _tBack(tBack)
{

}

//Skybox::~Skybox()
//{

//}

void Skybox::Display()
{
	glPushMatrix();
	//glPushAttrib(GL_ALL_ATTRIB_BITS);
    glColor4f(1.f, 1.f, 1.f,1.f);
    glTranslatef(-1000.f, 0.f, -1000.f);
    glScalef(2000.f, 2000.f, 2000.f);
    //Back
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, _tBack);
    glBegin(GL_QUADS);
    {
        glTexCoord2f(0.f, 0.f); glVertex3f(0.f, 0.f, 0.f);
        glTexCoord2f(1.f, 0.f);glVertex3f(1.f,0.f,0.f);
        glTexCoord2f(1.f, 1.f);glVertex3f(1.f,1.f,0.f);
        glTexCoord2f(0.f, 1.f);glVertex3f(0.f,1.f,0.f);
    }
    glEnd();
    
    //right facing inwards
    glBegin(GL_QUADS);
    {
        glTexCoord2f(0.f, 0.f); glVertex3f(1.f, 0.f, 0.f);
        glTexCoord2f(1.f, 0.f);glVertex3f(1.f,0.f,1.f);
        glTexCoord2f(1.f, 1.f);glVertex3f(1.f,1.f,1.f);
        glTexCoord2f(0.f, 1.f);glVertex3f(1.f,1.f,0.f);
    }
    glEnd();
    
    //left facing inwards
    
    glBegin(GL_QUADS);
    {
        glTexCoord2f(0.f, 0.f); glVertex3f(0.f, 0.f, 1.f);
        glTexCoord2f(1.f, 0.f);glVertex3f(0.f,0.f,0.f);
        glTexCoord2f(1.f, 1.f);glVertex3f(0.f,1.f,0.f);
        glTexCoord2f(0.f, 1.f);glVertex3f(0.f,1.f,1.f);
    }
    glEnd();
    
    //front facing inwards
    glBegin(GL_QUADS);
    {
        glTexCoord2f(0.f, 0.f); glVertex3f(1.f, 0.f, 1.f);
        glTexCoord2f(1.f, 0.f);glVertex3f(0.f,0.f,1.f);
        glTexCoord2f(1.f, 1.f);glVertex3f(0.f,1.f,1.f);
        glTexCoord2f(0.f, 1.f);glVertex3f(1.f,1.f,1.f);
    }
    glEnd();
    
    //top facing downwards
    glColor3f(1.f, 1.f, 1.f);
    glBegin(GL_QUADS);
    {
        glTexCoord2f(0.f, 0.f); glVertex3f(0.f, 1.f, 0.f);
        glTexCoord2f(1.f, 0.f);glVertex3f(1.f,1.f,0.f);
        glTexCoord2f(1.f, 1.f);glVertex3f(1.f,1.f,1.f);
        glTexCoord2f(0.f, 1.f);glVertex3f(0.f,1.f,1.f);
    }
    glEnd();
    
    glBindTexture(GL_TEXTURE_2D, 0);
    glDisable(GL_TEXTURE_2D);
    
    glPopMatrix();
    //glNormal3f(0.0f, 1.0f, 0.0f);
    
    
    
    
    //ground
    glPushMatrix();
    glTranslatef(0.f, 1000.f, 0.f);
    glScalef(2000.f, 1000.f, 2000.f);
    const float TESS_AMT = 25.0f;
    float square = 1.0f / TESS_AMT;
    
    glNormal3f(0.0f, 1.0f, 0.0f);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, _tBottom);
    
    
    for (float x = -1.0f; x < 1.0f; x += square)
    {
        for (float y = -1.0f; y < 1.0f; y += square)
        {
            glBegin(GL_QUADS);
            {
                
                glTexCoord2f(0.f, 0.f); glVertex3f(x, -1.0f, y);
                glTexCoord2f(1.f, 0.f); glVertex3f(x, -1.0f, y + square);
                glTexCoord2f(1.f, 1.f); glVertex3f(x + square, -1.0f, y + square);
                glTexCoord2f(0.f, 1.f); glVertex3f(x + square, -1.0f, y);
                
            }
            glEnd();
        }
    }
    glBindTexture(GL_TEXTURE_2D, 0);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();
	//glPopAttrib();
	
}
