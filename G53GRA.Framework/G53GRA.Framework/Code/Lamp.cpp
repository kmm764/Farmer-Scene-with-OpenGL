//
//  Lamp.cpp
//  G53GRA.Framework
//
//  Created by Himmy Kong on 04/05/2019.
//  Copyright © 2019 w.o.c.ward. All rights reserved.
//

#include "Lamp.h"
#include<cmath>
Lamp::Lamp(GLuint tLamp, GLuint tChain):_tLamp(tLamp),_tChain(tChain) {
}
void Lamp::Display()
{
    //glPushAttrib(GL_ALL_ATTRIB_BITS);
    glPushMatrix();
    glTranslatef(180.f,80.1f,60.f);
    DrawWholeLamp();
    
    glPopMatrix();
    
    
    
}

void Lamp::Update(const double &deltaTime)
{
    
    DistanceTravelled +=deltaTime*100;
    RotateTravelled += deltaTime*1;
    RotateSin = sin(RotateTravelled);// make sure the number loops between negative and positive
    
}
void Lamp::DrawWholeLamp()
{
    float rotationChain = RotateSin*10;
    float rotationLamp = RotateSin*20;
    glPushAttrib(GL_ALL_ATTRIB_BITS);//push attrib to make sure only the lamp glow
    
    GLfloat position1[4] = { 30.f, 0.f, 0.f, 1.0f}; //move the light source next to the lamp
    glLightfv(GL_LIGHT2, GL_POSITION, position1);
    GLfloat ambient2[3] = { 1.f, 1.f, 1.f}; //ambient on the lamp to make a glow effect
    glLightfv(GL_LIGHT2, GL_AMBIENT, ambient2); //only ambient matters here
    glEnable(GL_LIGHT2);
    
    glColor4f(1.f, 1.f, 1.f, 1.f);
    glDisable(GL_LIGHT1);
    
    
    glRotatef(180.f, 0.f, 0.f, 1.f);//make the lamp face downwards
    

    glPushMatrix();
    glRotatef(rotationChain, 1.f, 0.f, 0.f);
    
    glPushMatrix();
    glScalef(1.5f, 10.f, 1.5f);
    DrawChain(); //draw the chain first
    
    glPopMatrix();//pop the scale
    
    glTranslatef(-3.3f, 10.f, 3.3f); //move the rope to the middle of the lamp
    glRotatef(rotationLamp, 1.f, 0.f, 0.f);
    glPushMatrix();
    glScalef(7.9f, 16.6f, 7.9f); //scale the lamp
    DrawLamp();
    
    glPopMatrix();
    glPopAttrib(); //to make only the lamp glow
    glPopMatrix();
    //lighting from the lamp to nearby objects
    glEnable(GL_LIGHT1);
    
    GLfloat position[4] = { 0.f, -20.f, (rotationLamp+rotationChain), 1.0f};
    glLightfv(GL_LIGHT1, GL_POSITION, position);
    
    GLfloat ambient1[3] = { 0.f, 0.f, 0.f};
    GLfloat diffuse1[3] = { .715f, .715f, .715f};
    GLfloat specular1[3] = {.715f, .715f,.715f};
    
    glLightfv(GL_LIGHT1, GL_AMBIENT, ambient1);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuse1);
    glLightfv(GL_LIGHT1, GL_SPECULAR, specular1);
    
    glLightf(GL_LIGHT1, GL_CONSTANT_ATTENUATION, 0.f);
    glLightf(GL_LIGHT1, GL_LINEAR_ATTENUATION, 0.001f);
    glLightf(GL_LIGHT1, GL_QUADRATIC_ATTENUATION, 0.00008f);
    
    //
}

void Lamp::DrawChain()
{
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, _tChain);
    glBegin(GL_QUADS);
    {
        //front body
        glNormal3f(0.f, 0.f, 1.f);
        glTexCoord2f(0.f, 0.f); glVertex3f(0.f, 0.f, 0.f);
        glTexCoord2f(1.f, 0.f); glVertex3f(1.f,0.f,0.f);
        glTexCoord2f(1.f, 1.f); glVertex3f(1.f,1.f,0.f);
        glTexCoord2f(0.f, 1.f); glVertex3f(0.f, 1.f, 0.f);
        
        //back body
        glNormal3f(0.f, 0.f, -1.f);
        glTexCoord2f(0.f, 0.f); glVertex3f(1.f, 0.f, -1.f);
        glTexCoord2f(1.f, 0.f); glVertex3f(0.f,0.f,-1.f);
        glTexCoord2f(1.f, 1.f); glVertex3f(0.f,1.f,-1.f);
        glTexCoord2f(0.f, 1.f); glVertex3f(1.f, 1.f, -1.f);
        
        //right body
        glNormal3f(1.f, 0.f, 0.f);
        glTexCoord2f(0.f, 0.f); glVertex3f(1.f, 0.f, 0.f);
        glTexCoord2f(1.f, 0.f); glVertex3f(1.f,0.f,-1.f);
        glTexCoord2f(1.f, 1.f); glVertex3f(1.f,1.f,-1.f);
        glTexCoord2f(0.f, 1.f); glVertex3f(1.f,1.f,0.f);
        //left body
        glNormal3f(-1.f, 0.f, 0.f);
        glTexCoord2f(0.f, 0.f); glVertex3f(0.f,0.f,-1.f);
        glTexCoord2f(1.f, 0.f); glVertex3f(0.f,0.f,0.f);
        glTexCoord2f(1.f, 1.f); glVertex3f(0.f,1.f,0.f);
        glTexCoord2f(0.f, 1.f); glVertex3f(0.f, 1.f, -1.f);
    }
    glEnd();
    glBindTexture(GL_TEXTURE_2D, 0);
    glDisable(GL_TEXTURE_2D);
    glColor4f(0.f, 0.f, 0.f, 1.f);
    glBegin(GL_QUADS);
    {
        
        //top body
        glNormal3f(0.f, 1.f, 0.f);
        glVertex3f(0.f,1.f,0.f);
        glVertex3f(1.f,1.f,0.f);
        glVertex3f(1.f,1.f,-1.f);
        glVertex3f(0.f, 1.f, -1.f);
        //bottom body
        glNormal3f(0.f, -1.f, 0.f);
        glVertex3f(0.f,0.f,0.f);
        glVertex3f(0.f,0.f,-1.f);
        glVertex3f(1.f,0.f,-1.f);
        glVertex3f(1.f, 0.f, 0.f);
    }
    
    glEnd();
    glColor4f(1.f, 1.f, 1.f, 1.f);
    
    
    
    
}

void Lamp::DrawLamp(){
    
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, _tLamp);
    glBegin(GL_QUADS);
    {
        //front body
        glNormal3f(0.f, 0.f, 1.f);
        glTexCoord2f(0.f, 0.f); glVertex3f(0.f, 0.f, 0.f);
        glTexCoord2f(1.f, 0.f); glVertex3f(1.f,0.f,0.f);
        glTexCoord2f(1.f, 1.f); glVertex3f(1.f,1.f,0.f);
        glTexCoord2f(0.f, 1.f); glVertex3f(0.f, 1.f, 0.f);
        
        //back body
        glNormal3f(0.f, 0.f, -1.f);
        glTexCoord2f(0.f, 0.f); glVertex3f(1.f, 0.f, -1.f);
        glTexCoord2f(1.f, 0.f); glVertex3f(0.f,0.f,-1.f);
        glTexCoord2f(1.f, 1.f); glVertex3f(0.f,1.f,-1.f);
        glTexCoord2f(0.f, 1.f); glVertex3f(1.f, 1.f, -1.f);
        
        //right body
        glNormal3f(1.f, 0.f, 0.f);
        glTexCoord2f(0.f, 0.f); glVertex3f(1.f, 0.f, 0.f);
        glTexCoord2f(1.f, 0.f); glVertex3f(1.f,0.f,-1.f);
        glTexCoord2f(1.f, 1.f); glVertex3f(1.f,1.f,-1.f);
        glTexCoord2f(0.f, 1.f); glVertex3f(1.f,1.f,0.f);
        //left body
        glNormal3f(-1.f, 0.f, 0.f);
        glTexCoord2f(0.f, 0.f); glVertex3f(0.f,0.f,-1.f);
        glTexCoord2f(1.f, 0.f); glVertex3f(0.f,0.f,0.f);
        glTexCoord2f(1.f, 1.f); glVertex3f(0.f,1.f,0.f);
        glTexCoord2f(0.f, 1.f); glVertex3f(0.f, 1.f, -1.f);
    }
    glEnd();
    glBindTexture(GL_TEXTURE_2D, 0);
    glDisable(GL_TEXTURE_2D);
    glColor4f(0.f, 0.f, 0.f, 1.f);
    glBegin(GL_QUADS);
    {
        
        //top body
        glNormal3f(0.f, 1.f, 0.f);
        glVertex3f(0.f,1.f,0.f);
        glVertex3f(1.f,1.f,0.f);
        glVertex3f(1.f,1.f,-1.f);
        glVertex3f(0.f, 1.f, -1.f);
        //bottom body
        glNormal3f(0.f, -1.f, 0.f);
        glVertex3f(0.f,0.f,0.f);
        glVertex3f(0.f,0.f,-1.f);
        glVertex3f(1.f,0.f,-1.f);
        glVertex3f(1.f, 0.f, 0.f);
    }
    
    glEnd();
    glColor4f(1.f, 1.f, 1.f, 1.f);
    
    
    
}
