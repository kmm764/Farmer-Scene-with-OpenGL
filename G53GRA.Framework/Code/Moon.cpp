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

void Moon::Display() //display the moon
{
    
    float moonPosition[3] = {-600.f,800.1f,-820.f}; //set the moon position with an array
    //glPushAttrib(GL_ALL_ATTRIB_BITS);
    glPushMatrix(); //save position
    glTranslatef(moonPosition[0],moonPosition[1],moonPosition[2]);//move the moon the the desire location set earlier
    glRotatef(45.f, 0.f, 1.f, 0.f);//rotate down 45 facing the camera
    glRotatef(20.f, 1.f, 0.f, 0.f); //rotate it towards the scene
    glScalef(100.f, 100.f, 100.f); //make it to a reasonable size
    glColor4f(1.f, 1.f, 1.f, 1.f); //set to white
    
    glPushAttrib(GL_ALL_ATTRIB_BITS);//push attrib to make sure only the Moon glow
    
    GLfloat position1[4] = { 30.f, 0.f, 0.f, 1.0f}; //move the light source next to the Moon
    glLightfv(GL_LIGHT2, GL_POSITION, position1);
    GLfloat ambient2[3] = { 0.8f, 0.8f, 0.8f}; //ambient on the Moon to make a glow effect
    glLightfv(GL_LIGHT2, GL_AMBIENT, ambient2); //only ambient matters here
    glEnable(GL_LIGHT2);
    
    
    DrawMoon(); //draw the moon, with texture
    
    glPopAttrib();//return to previous location
    
    
    
    glPopMatrix();
   
    glPushMatrix();
    glRotatef(45.f, 1.f, 0.f, 0.f);  //rotate Light3 light source
    glRotatef(-15.f, 0.f, 1.f, 0.f);  //rotate again to make the light towards the sceen
    GLfloat position[4] = { moonPosition[0], moonPosition[1]-400, moonPosition[2]+50, 1.0f};//set the light3 location next to the moon, to make a effect as if the moon is lighting the sceen
    glLightfv(GL_LIGHT3, GL_POSITION, position);
    
    GLfloat ambient1[3] = { 0.f, 0.f, 0.f};
    GLfloat diffuse1[3] = { .515f, .515f, .715f}; //slighly blue light just similar to the moon
    GLfloat specular1[3] = {.515f, .515f,.715f};
    
    glLightfv(GL_LIGHT3, GL_AMBIENT, ambient1);
    glLightfv(GL_LIGHT3, GL_DIFFUSE, diffuse1);
    glLightfv(GL_LIGHT3, GL_SPECULAR, specular1);
    
    glLightf(GL_LIGHT3, GL_CONSTANT_ATTENUATION, 0.f);
    glLightf(GL_LIGHT3, GL_LINEAR_ATTENUATION, 0.000001f);
    glLightf(GL_LIGHT3, GL_QUADRATIC_ATTENUATION, 0.000001f); //adjusted so that the light only reaches the ground
    glEnable(GL_LIGHT3);
    glPopMatrix();
}





void Moon::DrawMoon() //draw a simple 2d planer facing the scene, and put a moon texture on it with _tMoon
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


