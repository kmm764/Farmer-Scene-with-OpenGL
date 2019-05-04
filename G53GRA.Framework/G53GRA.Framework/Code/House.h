#pragma once

#include "DisplayableObject.h"

class House :
public DisplayableObject
{
public:
    House(GLuint texFullBricks, GLuint texRoof,GLuint texDoor,GLuint texWindow);
    //~House();
    
    void Display();
    
private:
    GLuint _texFullBricks, _texRoof, _texDoor, _texWindow;
    
};
