//
//  Moon.cpp
//  G53GRA.Framework
//
//  Created by Himmy Kong on 04/05/2019.
//  Copyright © 2019 w.o.c.ward. All rights reserved.
//

#include "Moon.h"
#include<cmath>

Moon::Moon(GLuint tMoon): _tMoon(tMoon)
{
}

void Moon::Display()
{
    
    float moonPosition[3] = {-600.f,800.1f,-820.f};
    //glPushAttrib(GL_ALL_ATTRIB_BITS);
    glPushMatrix();
    glTranslatef(moonPosition[0],moonPosition[1],moonPosition[2]);
    glRotatef(45.f, 0.f, 1.f, 0.f);//rotate towards the player
    glRotatef(20.f, 1.f, 0.f, 0.f);
    glScalef(100.f, 100.f, 100.f);
    glColor4f(1.f, 1.f, 1.f, 1.f);
    
    glPushAttrib(GL_ALL_ATTRIB_BITS);//push attrib to make sure only the lamp glow
    
    GLfloat position1[4] = { 30.f, 0.f, 0.f, 1.0f}; //move the light source next to the lamp
    glLightfv(GL_LIGHT2, GL_POSITION, position1);
    GLfloat ambient2[3] = { 0.8f, 0.8f, 0.8f}; //ambient on the lamp to make a glow effect
    glLightfv(GL_LIGHT2, GL_AMBIENT, ambient2); //only ambient matters here
    glEnable(GL_LIGHT2);
    
    
    DrawMoon();
    
    glPopAttrib();
    
    
    
    glPopMatrix();
   
    glPushMatrix();
    glRotatef(45.f, 1.f, 0.f, 0.f);
    glRotatef(-15.f, 0.f, 1.f, 0.f);
    GLfloat position[4] = { moonPosition[0], moonPosition[1]-400, moonPosition[2]+50, 1.0f};
    glLightfv(GL_LIGHT3, GL_POSITION, position);
    
    GLfloat ambient1[3] = { 0.f, 0.f, 0.f};
    GLfloat diffuse1[3] = { .715f, .715f, .715f};
    GLfloat specular1[3] = {.715f, .715f,.715f};
    
    glLightfv(GL_LIGHT3, GL_AMBIENT, ambient1);
    glLightfv(GL_LIGHT3, GL_DIFFUSE, diffuse1);
    glLightfv(GL_LIGHT3, GL_SPECULAR, specular1);
    
    glLightf(GL_LIGHT3, GL_CONSTANT_ATTENUATION, 0.f);
    glLightf(GL_LIGHT3, GL_LINEAR_ATTENUATION, 0.000001f);
    glLightf(GL_LIGHT3, GL_QUADRATIC_ATTENUATION, 0.000003f);
    glEnable(GL_LIGHT3);
    glPopMatrix();
}


void Moon::Update(const double &deltaTime)
{
    
    moonTime += deltaTime;
    moonSin = sin(moonTime);// make sure the number loops between negative and positive
    
}


void Moon::DrawMoon()
{
    
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, _tMoon);
    glBegin(GL_QUADS);
    {
        //front body
        glNormal3f(0.f, 0.f, 1.f);
        glTexCoord2f(0.f, 0.f); glVertex3f(0.f, 0.f, 0.f);
        glTexCoord2f(1.f, 0.f); glVertex3f(1.f,0.f,0.f);
        glTexCoord2f(1.f, 1.f); glVertex3f(1.f,1.f,0.f);
        glTexCoord2f(0.f, 1.f); glVertex3f(0.f, 1.f, 0.f);
    }
    glEnd();
    glBindTexture(GL_TEXTURE_2D, 0);
    glDisable(GL_TEXTURE_2D);
    
    
}


