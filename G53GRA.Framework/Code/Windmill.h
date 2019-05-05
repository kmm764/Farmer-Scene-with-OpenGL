//
//  Windmill.hpp
//  G53GRA.Framework
//
//  Created by Himmy Kong on 04/05/2019.
//  Copyright © 2019 w.o.c.ward. All rights reserved.
//

#pragma once

#include "DisplayableObject.h"
#include "Animation.h"
#include "../Framework/Interface/Input.h"

class Windmill:
public DisplayableObject,
public Animation,
public Input

{
public:
    
    Windmill(GLuint tBase, GLuint tMiddle, GLuint tTop, GLuint tRoof, GLuint tBlade);
    
    void Update(const double &deltaTime);
    void Display();
    void DrawCube(int x);
    void DrawTriangle();
    void DrawRoof();
    void DrawBlade();
    void TurnBlade(int bladeN = 0, int onOff = 0, float rN =0);
    void HandleKey(unsigned char key, int state, int x, int y);
    
    
private:
    GLuint _tBase, _tMiddle, _tTop, _tRoof, _tBlade;
    int uKey,yKey;
    float RotateTravelled =0;
    float RotateSin = 0;
    
    
    
};
