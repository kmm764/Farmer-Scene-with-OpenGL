//
//  cube.cpp
//  G53GRA.Framework
//
//  Created by Himmy Kong on 03/05/2019.
//  Copyright © 2019 w.o.c.ward. All rights reserved.
//

#include "House.h"
#include<cmath>

House::House(GLuint texFullBricks, GLuint texRoof, GLuint texDoor,GLuint texWindow):_texFullBricks(texFullBricks),_texRoof(texRoof), _texDoor(texDoor), _texWindow(texWindow) {
}

void House::Display()
{
    glPushMatrix();
    glPushAttrib(GL_ALL_ATTRIB_BITS);
    
    glTranslatef(0.f,0.f,100.f);

    glEnable(GL_LIGHTING);
    
    glEnable(GL_LIGHT1);
    
    glEnable(GL_TEXTURE_2D);
    //glDisable(GL_LIGHTING);
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
    //front
   
    //drawing house
    glBindTexture(GL_TEXTURE_2D, _texFullBricks);
    glBegin(GL_QUADS);
    {
        //front
        glNormal3f(0.0f, 0.0f, 1.0f);
        glTexCoord2f(0.f, 0.f); glVertex3f(0.f, 0.f, 0.f);
        glTexCoord2f(1.f, 0.f); glVertex3f(150.f,0.f,0.f);
        glTexCoord2f(1.f, 1.f); glVertex3f(150.f,100.f,0.f);
        glTexCoord2f(0.f, 1.f); glVertex3f(0.f,100.f,0.f);
    
        //right side
        glNormal3f(1.0f, 0.0f, 0.0f);
        glTexCoord2f(0.f, 0.f); glVertex3f(150.f, 0.f, 0.f);
        glTexCoord2f(2.f, 0.f);glVertex3f(150.f,0.f,-300.f);
        glTexCoord2f(2.f, 1.f);glVertex3f(150.f,100.f,-300.f); //print the texture twice, so that the texture won't be stretched out
        glTexCoord2f(0.f, 1.f);glVertex3f(150.f,100.f,0.f);
        //left side
        glNormal3f(-1.0f, 0.0f, 0.0f);
        glTexCoord2f(2.f, 0.f);glVertex3f(0.f, 0.f, 0.f);
        glTexCoord2f(2.f, 1.f);glVertex3f(0.f,100.f,0.f);//same for the left hand side
        glTexCoord2f(0.f, 1.f);glVertex3f(0.f,100.f,-300.f);
        glTexCoord2f(0.f, 0.f);glVertex3f(0.f,0.f,-300.f);
        //back
        glNormal3f(0.0f, 0.0f, -1.0f);
        glTexCoord2f(0.f, 0.f);glVertex3f(150.f, 0.f, -300.f);
        glTexCoord2f(1.f, 0.f);glVertex3f(0.f,0.f,-300.f);
        glTexCoord2f(1.f, 1.f);glVertex3f(0.f,100.f,-300.f);
        glTexCoord2f(0.f, 1.f);glVertex3f(150.f,100.f,-300.f);
        
    }
    glEnd();
    glBindTexture(GL_TEXTURE_2D, 0);
    glDisable(GL_TEXTURE_2D);
    
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, _texFullBricks);
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
    
    glBegin(GL_TRIANGLES);
    {
        //front triangle of the house
        glNormal3f(0.0f, 0.0f, 1.0f);
        glTexCoord2f(0.f, 0.f); glVertex3f(0.f, 100.f, 0.f);
        glTexCoord2f(1.f, 0.f); glVertex3f(150.f,100.f,0.f);
        glTexCoord2f(0.5f, 0.5f); glVertex3f(75.f,150.f,0.f);
        //back triangle of the house
        glNormal3f(0.0f, 0.0f, -1.0f);
        glTexCoord2f(0.f, 0.f);glVertex3f(0.f, 100.f, -300.f);
        glTexCoord2f(0.5f, 0.5f); glVertex3f(75.f,150.f,-300.f);
        glTexCoord2f(1.f, 0.f);glVertex3f(150.f,100.f,-300.f);
        
        
    }
    glEnd();
    glBindTexture(GL_TEXTURE_2D, 0);
    glDisable(GL_TEXTURE_2D);
    //roof
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, _texRoof);
    glBegin(GL_QUADS);
    {
       
        //right side
        
        glTexCoord2f(0.f, 0.f);glVertex3f(180.f, 80.f, 20.f);
        glTexCoord2f(3.f, 0.f);glVertex3f(180.f,80.f,-320.f);
        glTexCoord2f(3.f, 3.f);glVertex3f(75.f,150.f,-320.f);
        glTexCoord2f(0.f, 3.f);glVertex3f(75.f,150.f,20.f);
        //right other face
        glTexCoord2f(0.f, 0.f);glVertex3f(75.f,150.f,20.f);
        glTexCoord2f(3.f, 0.f);glVertex3f(75.f,150.f,-320.f);
        glTexCoord2f(3.f, 3.f);glVertex3f(180.f,80.f,-320.f);
        glTexCoord2f(0.f, 3.f);glVertex3f(180.f, 80.f, 20.f);
        //left side
        glTexCoord2f(0.f, 0.f);glVertex3f(-30.f, 80.f, 20.f);
        glTexCoord2f(3.f, 0.f);glVertex3f(75.f,150.f,20.f);
        glTexCoord2f(3.f, 3.f);glVertex3f(75.f,150.f,-320.f);
        glTexCoord2f(0.f, 3.f);glVertex3f(-30.f, 80.f, -320.f);
        //left side other face
        glTexCoord2f(0.f, 0.f);glVertex3f(-30.f, 80.f, -320.f);
        glTexCoord2f(3.f, 0.f);glVertex3f(75.f,150.f,-320.f);
        glTexCoord2f(3.f, 3.f);glVertex3f(75.f,150.f,20.f);
        glTexCoord2f(0.f, 3.f);glVertex3f(-30.f, 80.f, 20.f);
    }
    
    glEnd();
    //glEnable(GL_LIGHTING);
    glBindTexture(GL_TEXTURE_2D, 0);
    glDisable(GL_TEXTURE_2D);
    
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, _texDoor);
    
    
    glTranslatef(1.f, 0.f, 0.f);
    glBegin(GL_QUADS);
    {
        
        //right side Door
        glNormal3f(1.0f, 0.0f, 0.0f);
        glTexCoord2f(0.f, 0.f); glVertex3f(150.f, 0.f, -130.f);
        glTexCoord2f(1.f, 0.f);glVertex3f(150.f,0.f,-170.f);
        glTexCoord2f(1.f, 1.f);glVertex3f(150.f,70.f,-170.f);
        glTexCoord2f(0.f, 1.f);glVertex3f(150.f,70.f,-130.f);
    }
    
    glEnd();
    glBindTexture(GL_TEXTURE_2D, 0);
    glDisable(GL_TEXTURE_2D);
    
    glPopAttrib();
    glPopMatrix();
}

/*void Cube::Update()
{
    
    
    //pos[0] = scale[0]*sin(_runtime);
    //pos[1] = scale[1]*cos(_runtime);
    
    glEnable(GL_LIGHTING);
    GLfloat position[4] = { -30.f, 50.f, 0.f, 1.0f};
    glLightfv(GL_LIGHT1, GL_POSITION, position);
    
    GLfloat ambient1[3] = { 0.f, 0.f, 0.f};
    GLfloat diffuse1[3] = { .715f, .715f, .715f};
    GLfloat specular1[3] = {.715f, .715f,.715f};
    
    glLightfv(GL_LIGHT1, GL_AMBIENT, ambient1);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuse1);
    glLightfv(GL_LIGHT1, GL_SPECULAR, specular1);
    
    glLightf(GL_LIGHT1, GL_CONSTANT_ATTENUATION, 0.f);
    glLightf(GL_LIGHT1, GL_LINEAR_ATTENUATION, 0.01f);
    glLightf(GL_LIGHT1, GL_QUADRATIC_ATTENUATION, 0.001f);
    
    glEnable(GL_LIGHT1);
}
*/
