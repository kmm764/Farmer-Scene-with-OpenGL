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

class Windmill:
public DisplayableObject,
public Animation

{
public:
    
    Windmill(GLuint tBase, GLuint tMiddle, GLuint tTop, GLuint tRoof, GLuint tBlade);
    
    void Update(const double &deltaTime);
    void Display();
    void DrawCube(int x);
    void DrawTriangle();
    void DrawRoof();
    void DrawBlade();
    
private:
    GLuint _tBase, _tMiddle, _tTop, _tRoof, _tBlade;
    
    float RotateTravelled =0;
    float RotateSin = 0;
    
    
    
};
