#pragma once

#include "DisplayableObject.h"
#include "Animation.h"

class Human:
public DisplayableObject,
public Animation
{
public:
    
    void Update(const double &deltaTime);
    void Display();
    void DrawHuman();
    void DrawBody();
    void DrawRightUpperLeg();
    void DrawLeftUpperLeg();
    void DrawRightLowerLeg();
    void DrawLeftLowerLeg();
    void DrawRightUpperArm();
    void DrawRightLowerArm();
    void DrawLeftUpperArm();
    void DrawLeftLowerArm();
    void DrawHead();
    void DrawCube();
    void DrawHoe();
    void TurnBody();
    
private:
    double totalPositionAnimationTime =0;
    float DistanceTravelled= 0;
    float RotateTravelled =0;
    float xBody,yBody, zBody, xArm, yArm,zArm, xHead, yHead, zHead ,xLeg, yLeg, zLeg,xHoe,yHoe,zHoe;
    float RotateSin = 0;
   // double totalRotationAnimationTime =0;
    
    
};
