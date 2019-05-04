//
//  Windmill.cpp
//  G53GRA.Framework
//
//  Created by Himmy Kong on 04/05/2019.
//  Copyright © 2019 w.o.c.ward. All rights reserved.
//

#include "Windmill.h"

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
    DrawCube(3); //2 is drawing the middle part
    glPopMatrix();
    
    /*glTranslatef(0.f,yMiddle,0.f);
    
    glPushMatrix();
    glScalef(150, yTop, 150);
    DrawCube(3); //2 is drawing the middle part
    glPopMatrix();*/
    
    glPopMatrix();
}

void Windmill::Update(const double &deltaTime){}

void Windmill::DrawTriangle(){}

void Windmill::DrawRoof(){}

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
            
        case ' ':
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

