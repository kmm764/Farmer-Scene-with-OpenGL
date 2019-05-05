#pragma once

#include "DisplayableObject.h"
#include "Animation.h"

class Lamp:
public DisplayableObject,
public Animation
{
public:
    Lamp(GLuint tLamp, GLuint tChain);
    
    void Update(const double &deltaTime);
    void Display();
    void DrawCube();
    void TurnBody();
    void DrawChain();
    void DrawLamp();
    void DrawWholeLamp();
    
private:
    GLuint _tLamp, _tChain;
    double totalPositionAnimationTime =0;
    float DistanceTravelled= 0;
    float RotateTravelled =0;
    float RotateSin = 0;
    
    
    
};
