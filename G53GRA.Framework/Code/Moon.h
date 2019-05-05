#pragma once

#include "DisplayableObject.h"

class Moon:

public DisplayableObject //include displayable object

{
public:
    Moon(GLuint tMoon);
    
    void Display();
    void DrawMoon();
    
    
private:
    GLuint _tMoon;
    
    
    
    
};
