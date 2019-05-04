#pragma once

#include "DisplayableObject.h"

class Moon:

public DisplayableObject

{
public:
    Moon(GLuint tMoon);
    
    void Display();
    void DrawMoon();
    void Update(const double &deltaTime);
    
private:
    GLuint _tMoon;
    float moonTime = 0;
    float moonSin = 0;
    
    
    
};
