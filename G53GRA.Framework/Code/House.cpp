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
//--------------------display---------------------
void House::Display()
{
    
    float windowSize[2] = {30.f*1.25781,30.f}; //ratio of the window.bmp is 1:1.25781
    glPushMatrix();
    glPushAttrib(GL_ALL_ATTRIB_BITS);
    
    glTranslatef(0.f,0.f,100.f);

    glEnable(GL_LIGHTING);
    
    glEnable(GL_LIGHT1);
    
    glEnable(GL_TEXTURE_2D);
    //glDisable(GL_LIGHTING);
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
    //front
   
    //drawing house, the cube, using actual coordinates instead of scaling, because I was doing house first
    glBindTexture(GL_TEXTURE_2D, _texFullBricks);
    //the base of the house
    glBegin(GL_QUADS);
    {
        //front
        glNormal3f(0.0f, 0.0f, 1.0f);
        glTexCoord2f(0.f, 0.f); glVertex3f(0.f, 0.f, 0.f);
        glTexCoord2f(2.f, 0.f); glVertex3f(150.f,0.f,0.f);
        glTexCoord2f(2.f, 2.f); glVertex3f(150.f,100.f,0.f);
        glTexCoord2f(0.f, 2.f); glVertex3f(0.f,100.f,0.f);
    
        //right side
        glNormal3f(1.0f, 0.0f, 0.0f);
        glTexCoord2f(0.f, 0.f); glVertex3f(150.f, 0.f, 0.f);
        glTexCoord2f(4.f, 0.f);glVertex3f(150.f,0.f,-300.f);
        glTexCoord2f(4.f, 2.f);glVertex3f(150.f,100.f,-300.f); //print the texture twice, so that the texture won't be stretched out
        glTexCoord2f(0.f, 2.f);glVertex3f(150.f,100.f,0.f);
        //left side
        glNormal3f(-1.0f, 0.0f, 0.0f);
        glTexCoord2f(4.f, 0.f);glVertex3f(0.f, 0.f, 0.f);
        glTexCoord2f(4.f, 2.f);glVertex3f(0.f,100.f,0.f);//same for the left hand side
        glTexCoord2f(0.f, 2.f);glVertex3f(0.f,100.f,-300.f);
        glTexCoord2f(0.f, 0.f);glVertex3f(0.f,0.f,-300.f);
        //back
        glNormal3f(0.0f, 0.0f, -1.0f);
        glTexCoord2f(0.f, 0.f);glVertex3f(150.f, 0.f, -300.f);
        glTexCoord2f(2.f, 0.f);glVertex3f(0.f,0.f,-300.f);
        glTexCoord2f(2.f, 2.f);glVertex3f(0.f,100.f,-300.f);
        glTexCoord2f(0.f, 2.f);glVertex3f(150.f,100.f,-300.f);
        
    }
    glEnd();
    glBindTexture(GL_TEXTURE_2D, 0);
    glDisable(GL_TEXTURE_2D);
    
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, _texFullBricks);
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
    
    //build the two triangles above base
    glBegin(GL_TRIANGLES);
    {
        //front triangle of the house
        glNormal3f(0.0f, 0.0f, 1.0f);
        glTexCoord2f(0.f, 0.f); glVertex3f(0.f, 100.f, 0.f);
        glTexCoord2f(2.f, 0.f); glVertex3f(150.f,100.f,0.f);
        glTexCoord2f(1.f, 1.f); glVertex3f(75.f,150.f,0.f);//1 and 1 to make the texture same as the cube
        //back triangle of the house
        glNormal3f(0.0f, 0.0f, -1.0f);
        glTexCoord2f(0.f, 0.f);glVertex3f(0.f, 100.f, -300.f);
        glTexCoord2f(1.f, 1.f); glVertex3f(75.f,150.f,-300.f);
        glTexCoord2f(2.f, 0.f);glVertex3f(150.f,100.f,-300.f);
        
        
    }
    glEnd();
    glBindTexture(GL_TEXTURE_2D, 0);
    glDisable(GL_TEXTURE_2D);
    //roof
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, _texRoof);
    
    //building roof, double sided for the two roof
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
    
    
    
    //door with texture
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
    
    
    
    
    
    
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, _texWindow);
    
    //right windows with texture
    
    //right window 1
    glPushMatrix();
    glTranslatef(111.5f, 40.f, -60.f); //adjust size so that they are symmetrical
    glScalef(windowSize[0],windowSize[1], windowSize[1]);
    DrawRightWindow();
    glPopMatrix();
    
    //right window 2
    glPushMatrix();
    glTranslatef(111.5f, 40.f, -210.f); //adjust size so that they are symmetrical
    glScalef(windowSize[0],windowSize[1], windowSize[1]);
    DrawRightWindow();
    glPopMatrix();
    
    
    
    //left windows with textures
    
    //left window 1
    glPushMatrix();
    glTranslatef(-1.2f, 40.f, -60.f);  //adjust size so that they are symmetrical
    glScalef(windowSize[0], windowSize[1], windowSize[1]);
    DrawLeftWindow();
    glPopMatrix();
    
    //left window 2
    glPushMatrix();
    glTranslatef(-1.2f, 40.f, -210.f);  //adjust size so that they are symmetrical
    glScalef(windowSize[0], windowSize[1], windowSize[1]);
    DrawLeftWindow();
    glPopMatrix();
    
    glBindTexture(GL_TEXTURE_2D, 0);
    glDisable(GL_TEXTURE_2D);
    
    glPopAttrib();
    glPopMatrix();
}

void House::DrawLeftWindow(){
    glBegin(GL_QUADS);
    {
        //left windows
        glNormal3f(-1.0f, 0.0f, 0.0f);
        glTexCoord2f(0.f, 0.f); glVertex3f(0.f, 0.f, -1.f);
        glTexCoord2f(1.f, 0.f);glVertex3f(0.f,0.f,0.f);
        glTexCoord2f(1.f, 1.f);glVertex3f(0.f,1.f,0.f);
        glTexCoord2f(0.f, 1.f);glVertex3f(0.f,1.f,-1.f);
    }
    glEnd();
}

void House::DrawRightWindow(){
    glBegin(GL_QUADS);
    {
        
        //right windows
        glNormal3f(1.0f, 0.0f, 0.0f);
        glTexCoord2f(0.f, 0.f); glVertex3f(1.f, 0.f, 0.f);
        glTexCoord2f(1.f, 0.f);glVertex3f(1.f,0.f,-1.f);
        glTexCoord2f(1.f, 1.f);glVertex3f(1.f,1.f,-1.f);
        glTexCoord2f(0.f, 1.f);glVertex3f(1.f,1.f,0.f);
        
        
        
    }
    
    glEnd();
}
