//
//  Windmill.cpp
//  G53GRA.Framework
//
//  Created by Himmy Kong on 04/05/2019.
//  Copyright © 2019 w.o.c.ward. All rights reserved.
//

#include "Windmill.h"
#include<cmath>

Windmill::Windmill(GLuint tBase, GLuint tMiddle, GLuint tTop, GLuint tRoof, GLuint tBlade): _tBase(tBase), _tMiddle(tMiddle), _tTop(tTop), _tRoof(tRoof), _tBlade(tBlade){}

void Windmill::Display(){
    float yBase = 50;
    float yMiddle = 250;
    float yTop = 50;
    
    glPushMatrix();
    glTranslatef(-300.f,0.f,-450.f);
    
    glPushMatrix();
    glScalef(150, yBase, 150);
    DrawCube(1); //1 is drawing the base
    glPopMatrix();
    
    glTranslatef(0.f,yBase,0.f);
    
    glPushMatrix();
    glScalef(150, yMiddle, 150);
    DrawCube(2); //2 is drawing the middle part
    glPopMatrix();
    
    glTranslatef(0.f,yMiddle,0.f);
    
    glPushMatrix();
    glScalef(150, yTop, 150);
    DrawTriangle();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0, 0, 20);
    glScalef(150, yTop, 190);
    DrawRoof();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(75.f, -50.f, 0.f);
    
    //base wood
    glPushMatrix();
    glTranslatef(-15.f, -15.f, 0.f);
    glRotatef(90, 1.f, 0.f, 0.f);
    glScalef(30, 10, 30);
    DrawCube(3);
    glPopMatrix();
    
    glPushMatrix();
    
    glRotatef(RotateTravelled*10, 0.f, 0.f, 1.f);
    glTranslatef(-5.f, -5.f, 0.f);
    glRotatef(90, 1.f, 0.f, 0.f);
    glScalef(10.f, 55.f, 10.f);
    DrawCube(3); //3 is the wood texture
    glPopMatrix();
    
    /*glPushMatrix();
    glTranslatef(70.f, -45.f, 50.f);
    
    glScalef(10.f, 55.f, 10.f);
    DrawCube(5);
    glPopMatrix();*/
    
    
    glPopMatrix();
    
    glPopMatrix();
}

void Windmill::Update(const double &deltaTime){
    RotateTravelled += deltaTime*1;
    RotateSin = sin(RotateTravelled);// make sure the number loops between negative and positive
}

void Windmill::DrawTriangle(){
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, _tMiddle);
    glColor4f(1.f, 1.f, 1.f, 1.f);
    glBegin(GL_TRIANGLES);
    {
        //front triangle of the house
        glNormal3f(0.0f, 0.0f, 1.0f);
        glTexCoord2f(0.f, 0.f);glVertex3f(0.f, 0.f, 0.f);
        glTexCoord2f(1.f, 1.f);glVertex3f(1.f,0.f,0.f);
        glTexCoord2f(2.f, 0.f);glVertex3f(0.5f,1.f,0.f);//1 and 1 to make the texture same as
        
        //back triangle of the house
        glNormal3f(0.0f, 0.0f, -1.0f);
        glTexCoord2f(0.f, 0.f);glVertex3f(1.f, 0.f, -1.f);
        glTexCoord2f(1.f, 1.f);glVertex3f(0.f,0.f,-1.f);
        glTexCoord2f(2.f, 0.f);glVertex3f(0.5f,1.f,-1.f);
    }
    glEnd();
    glBindTexture(GL_TEXTURE_2D, 0);
    glDisable(GL_TEXTURE_2D);
}

void Windmill::DrawRoof(){
    
    
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, _tRoof);
    glColor4f(1.f, 1.f, 1.f, 1.f);
    glBegin(GL_QUADS);
    {
        //right roof
        glNormal3f(1.0f, 0.0f, 0.0f);
        glTexCoord2f(0.f, 0.f);glVertex3f(1.f, 0.f, 0.f);
        glTexCoord2f(1.f, 0.f);glVertex3f(1.f,0.f,-1.f);
        glTexCoord2f(1.f, 1.f);glVertex3f(0.5f,1.f,-1.f);
        glTexCoord2f(0.f, 1.f);glVertex3f(0.5f,1.f,0.f);
        
        //right roof other side
        glNormal3f(-1.0f, 0.0f, 0.0f);
        glTexCoord2f(0.f, 0.f);glVertex3f(1.f, 0.f, 0.f);
        glTexCoord2f(1.f, 0.f);glVertex3f(0.5f,1.f,0.f);
        glTexCoord2f(1.f, 1.f);glVertex3f(0.5f,1.f,-1.f);
        glTexCoord2f(0.f, 1.f);glVertex3f(1.f,0.f,-1.f);
        
        //left roof
        glNormal3f(-1.0f, 0.0f, 1.0f);
        glTexCoord2f(0.f, 0.f);glVertex3f(0.f, 0.f, -1.f);
        glTexCoord2f(1.f, 0.f);glVertex3f(0.f,0.f, 0.f);
        glTexCoord2f(1.f, 1.f);glVertex3f(0.5f,1.f,0.f);
        glTexCoord2f(0.f, 1.f);glVertex3f(0.5f,1.f,-1.f);
        
        //left roof
        glNormal3f(1.0f, 0.0f, 1.0f);
        glTexCoord2f(0.f, 0.f);glVertex3f(0.f, 0.f, -1.f);
        glTexCoord2f(1.f, 0.f);glVertex3f(0.5f,1.f,-1.f);
        glTexCoord2f(1.f, 1.f);glVertex3f(0.5f,1.f,0.f);
        glTexCoord2f(0.f, 1.f);glVertex3f(0.f,0.f, 0.f);
        
    }
    glEnd();
    glBindTexture(GL_TEXTURE_2D, 0);
    glDisable(GL_TEXTURE_2D);
    
}

void Windmill::DrawBlade(){}

void Windmill::DrawCube(int x){
    unsigned char tex; //experimenting with switch, makes coding more efficient
    switch (x)
    {
        
        case 1:
            tex = _tBase;
            break;
        
        case 2:
            tex = _tMiddle;
            break;
        
        case 3:
            tex = _tTop;
            break;
        
        case 4:
            tex = _tRoof;
            break;
        
        case 5:
            tex = _tBlade;
            break;
            
        default:
            break;
    }
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, tex);
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
        
        //front
        glNormal3f(0.f, 1.f, 0.f);
        glTexCoord2f(0.f, 0.f);glVertex3f(0.f,1.f,0.f);
        glTexCoord2f(1.f, 0.f);glVertex3f(1.f,1.f,0.f);
        glTexCoord2f(1.f, 1.f);glVertex3f(1.f,1.f,-1.f);
        glTexCoord2f(0.f, 1.f);glVertex3f(0.f, 1.f, -1.f);
        //bottom body
        glNormal3f(0.f, -1.f, 0.f);
        glTexCoord2f(0.f, 0.f);glVertex3f(0.f,0.f,0.f);
        glTexCoord2f(1.f, 0.f);glVertex3f(0.f,0.f,-1.f);
        glTexCoord2f(1.f,1.f);glVertex3f(1.f,0.f,-1.f);
        glTexCoord2f(0.f, 1.f);glVertex3f(1.f, 0.f, 0.f);
    }
    glEnd();
    glBindTexture(GL_TEXTURE_2D, 0);
    
    glColor4f(1.f, 1.f, 1.f, 1.f);
    
    
    
}

