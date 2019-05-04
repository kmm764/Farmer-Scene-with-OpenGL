#pragma once

#include "DisplayableObject.h"
#include "Animation.h"

class Moon:
public DisplayableObject,
public Animation
{
public:
    Moon(GLuint tMoon);
    
    void Update(const double &deltaTime);
    void Display();
    
private:
    GLuint _tMoon;
    double totalPositionAnimationTime =0;
    float DistanceTravelled= 0;
    float RotateTravelled =0;
    float RotateSin = 0;
    
    
    
};
