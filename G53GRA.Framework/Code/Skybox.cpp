#include "Skybox.h"


//Skybox::Skybox();
Skybox::Skybox(GLuint tTop, GLuint tBottom, GLuint tLeft, GLuint tRight, GLuint tFront, GLuint tBack):
_tTop(tTop), _tBottom(tBottom), _tLeft(tLeft), _tRight(tRight), _tFront(tFront), _tBack(tBack)
{

}


void Skybox::Display() //display the skybox
{
    
    glPushAttrib(GL_ALL_ATTRIB_BITS);//push attrib to make sure only the skybox glow
    
    GLfloat position1[4] = { 30.f, 0.f, 0.f, 1.0f}; //move the light source next to the skybox
    glLightfv(GL_LIGHT2, GL_POSITION, position1);
    GLfloat ambient2[3] = { 0.8f, 0.8f, 0.8f}; //ambient on the skybox to make a glow effect
    glLightfv(GL_LIGHT2, GL_AMBIENT, ambient2); //only ambient matters here
    glEnable(GL_LIGHT2);
    
    
    
    
	glPushMatrix();
    glColor4f(1.f, 1.f, 1.f,1.f);//set the box to white, making sure the texture won't be colored
    glTranslatef(-1000.f, 0.f, -1000.f); //move the box to the middle
    glScalef(2000.f, 2000.f, 2000.f); //scale the box to this size
    
    //Back of the skybox, drawing one plane out facing the camera
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
    
    glPopAttrib();
    
    
    //ground
    glPushMatrix();
    glTranslatef(0.f, 1000.f, 0.f);
    glScalef(1000.f, 1000.f, 1000.f);
    const float TESS_AMT = 25.0f; //seperating the ground into small Quads, so that the light will have an effect on the ground
    float square = 1.0f / TESS_AMT;
    
    glNormal3f(0.0f, 1.0f, 0.0f); //normal facing upwards, for light
    glEnable(GL_TEXTURE_2D); //start applying texture
    glBindTexture(GL_TEXTURE_2D, _tBottom);
    
    //use a forloop to put all the small quads together forming the ground of the skybox
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
	
	
}
