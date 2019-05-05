//
//  Human.cpp
//  G53GRA.Framework
//
//  Created by Himmy Kong on 03/05/2019.
//  Copyright © 2019 w.o.c.ward. All rights reserved.
//

#include "Human.h"
#include<cmath>
void Human::Display()
{
    //glPushAttrib(GL_ALL_ATTRIB_BITS);
    xBody = 15.f;
    yBody = 30.f;
    zBody = 10.f;
    xArm =xBody/3;
    yArm = yBody/3;
    zArm = zBody/2;
    xLeg = xBody*0.9/2;
    yLeg = yBody/2;
    zLeg = zBody*0.9;
    xHead = 10;
    yHead = 8;
    zHead = 10;
    xHoe = 3;
    yHoe = 3;
    zHoe = 70;
    
    
    glPushMatrix();
    glTranslatef(300.f,30.f,50.f);
    //glEnable(GL_LIGHT1);
    
    //glRotatef( RotateTravelled, 0, 0, 1);
     //scale the body
    
    
    glColor4f(0.0f, 1.0f, 0.0f, 1.0f);
    DrawHuman();
    
    glTranslatef(150.f, 0.f, -200.f);
    glColor4f(0.0f, 0.0f, 1.0f, 1.0f);
    DrawHuman();
    glPopMatrix();
    glEnable(GL_LIGHT1);
    //glPopAttrib();
    /*
    GLfloat position[4] = { -10.f, 0.f, 0.f, 1.0f};
    glLightfv(GL_LIGHT1, GL_POSITION, position);
    
    GLfloat ambient1[3] = { 0.f, 0.f, 0.f};
    GLfloat diffuse1[3] = { .715f, .715f, .715f};
    GLfloat specular1[3] = {.715f, .715f,.715f};
    
    glLightfv(GL_LIGHT1, GL_AMBIENT, ambient1);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuse1);
    glLightfv(GL_LIGHT1, GL_SPECULAR, specular1);
    
    glLightf(GL_LIGHT1, GL_CONSTANT_ATTENUATION, 0.f);
    glLightf(GL_LIGHT1, GL_LINEAR_ATTENUATION, 0.001f);
    glLightf(GL_LIGHT1, GL_QUADRATIC_ATTENUATION, 0.0001f);*/
}

void Human::Update(const double &deltaTime)
{
    
    DistanceTravelled +=deltaTime*100;
    RotateTravelled += deltaTime*1;
    RotateSin = sin(RotateTravelled)+1;
    
    
    
}

void Human::DrawHuman()
{
    //body
    glPushMatrix();
    TurnBody();
    DrawBody();
    glPopMatrix();
    
    
    
    //draw LeftUpperArm and draw leftLowerArm
    glPushMatrix();
    TurnBody();
    
    DrawLeftUpperArm();
    DrawLeftLowerArm();
    glPopMatrix();
    
    //draw RightUpperArm and draw RightLowerArm
    glPushMatrix();
    TurnBody();
    DrawRightUpperArm();
    DrawRightLowerArm();
    DrawHoe();
    glPopMatrix();
    
    //left upper leg
    glPushMatrix();
    DrawLeftUpperLeg();
    glPopMatrix();
    
    //left lower leg
    glPushMatrix();
    DrawLeftLowerLeg();
    glPopMatrix();
    
    //right upper leg
    glPushMatrix();
    DrawRightUpperLeg();
    glPopMatrix();
    
    //right lower leg
    glPushMatrix();
    DrawRightLowerLeg();
    glPopMatrix();
    
    //head
    glPushMatrix();
    TurnBody();
    DrawHead();
    glPopMatrix();
    
}
void Human::DrawBody()
{
    
    glScalef(xBody,yBody, zBody);
    DrawCube();
    
}
void Human::DrawRightUpperLeg()
{
    glTranslatef(6.7f,-1.f,-0.5f); //start from (0,0,0) from body
    glRotatef(180, 0, 0, 1);//rotate it 180 so that it render below the body
    glScalef(xLeg, yLeg, zLeg);
    DrawCube();
}
void Human::DrawRightLowerLeg()
{
    glTranslatef(6.7f,-16.f,-0.5f); //start from (0,0,0) from body
    glRotatef(180, 0, 0, 1); //rotate it 180 so that it render below the body
    glScalef(xLeg, yLeg, zLeg);
    DrawCube();
}
void Human::DrawLeftUpperLeg()
{
    glTranslatef(xBody,-1.f,-0.5f); //start from (0,0,0) from body
    glRotatef(180, 0, 0, 1); //rotate it 180 so that it render below the body
    glScalef(xLeg, yLeg, zLeg);
    DrawCube();
}
void Human::DrawLeftLowerLeg()
{
    glTranslatef(xBody,-16.f,-0.5f); //start from (0,0,0) from body
    glRotatef(180, 0, 0, 1); //rotate it 180 so that it render below the body
    glScalef(xLeg, yLeg, zLeg);
    DrawCube();
}
void Human::DrawRightUpperArm()
{
    glTranslatef(0.f,30.f,-3.f); //start from (0,0,0) from body
    glRotatef(180, 0, 0, 1);//rotate it 180 so that it render below the body
    glRotatef(-RotateSin*40+90, 1.f, 0.f, 0.f);
    glPushMatrix();
    glScalef(xArm, yArm, zArm);
    
    DrawCube();
    glPopMatrix();//reset the scale so that it won't affect lower arm rotation or translate
}
void Human::DrawRightLowerArm()
{
    glTranslatef(0.f,yArm,0.f);
    glRotatef(-RotateSin*45+90, 1.f, 0.f, 0.f);
    
    glPushMatrix();
    glScalef(xArm, yArm, zArm);//rotate it 180 so that it render below the body
    DrawCube();
    glPopMatrix();
}
void Human::DrawLeftUpperArm()
{
    glTranslatef(xBody+xBody/3,30.f,-3.f); //start from (0,0,0) from body
    glRotatef(RotateSin*10, 1.f, 0.f, 0.f);
    glRotatef(180, 0, 0, 1); //rotate it 180 so that it render below the body
    glPushMatrix();
    glScalef(xArm, yArm, zArm);
    DrawCube();
    glPopMatrix(); //reset the  scale so that it won't affect lower arm rotation or translate
}
void Human::DrawLeftLowerArm()
{
    glTranslatef(0.f,yArm,0.f);//positive because of the 180 rotation
    glRotatef(RotateSin*5, 1.f, 0.f, 0.f);
    glScalef(xArm, yArm, zArm);
    DrawCube();
}
void Human::DrawHead()
{
    glColor3f(1.f, 0.764f, 0.666f);
    glTranslatef(xBody/2-xHead/2, yBody+0.01f, 0.f);
    glPushMatrix();
    glScalef(xHead, yHead, zHead);
    DrawCube();
    glPopMatrix();
    
    //add hair
    glPushMatrix();
    glColor3f(0.f, 0.f, 0.f);
    glTranslatef(0.f, yHead, 0.f);
    glScalef(xHead, yHead/4, zHead);
    DrawCube();
    glPopMatrix();
    
    
}
void Human::DrawHoe()
{
    glColor3f(0.70f, 0.25f, 0.25f);
    glTranslatef(0.5f, yArm, zHoe*3/4); //where the right hand is holding the hoe
    glPushMatrix();
    glScalef(xHoe,yHoe,zHoe);
    DrawCube();
    //draw hoe head
    glPopMatrix();
    //glTranslatef(0.f, 0.f, zHoe);
    glScalef(3, 20, 2);
    DrawCube();
    
    
}

void Human::TurnBody()
{
    glRotatef(RotateSin*20, 1.f, 0.f, 0.f);
}

void Human::DrawCube()
{
    glBegin(GL_QUADS);
    {
        //front body
        glNormal3f(0.f, 0.f, 1.f);
        glVertex3f(0.f, 0.f, 0.f);
        glVertex3f(1.f,0.f,0.f);
        glVertex3f(1.f,1.f,0.f);
        glVertex3f(0.f, 1.f, 0.f);
        
        //back body
        glNormal3f(0.f, 0.f, -1.f);
        glVertex3f(1.f, 0.f, -1.f);
        glVertex3f(0.f,0.f,-1.f);
        glVertex3f(0.f,1.f,-1.f);
        glVertex3f(1.f, 1.f, -1.f);
        
        //right body
        glNormal3f(1.f, 0.f, 0.f);
        glVertex3f(1.f, 0.f, 0.f);
        glVertex3f(1.f,0.f,-1.f);
        glVertex3f(1.f,1.f,-1.f);
        glVertex3f(1.f,1.f,0.f);
        //left body
        glNormal3f(-1.f, 0.f, 0.f);
        glVertex3f(0.f,0.f,-1.f);
        glVertex3f(0.f,0.f,0.f);
        glVertex3f(0.f,1.f,0.f);
        glVertex3f(0.f, 1.f, -1.f);
        
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
}

