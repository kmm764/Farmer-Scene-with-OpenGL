#pragma once

#include "DisplayableObject.h"

class Skybox : 
	public DisplayableObject
{
public:
    
    //Skybox();
	Skybox(GLuint tTop, GLuint tBottom, GLuint tLeft, GLuint tRight, GLuint tFront, GLuint tBack);
	//~Skybox();

	void Display();

private:
	GLuint _tTop, _tBottom, _tLeft, _tRight, _tFront, _tBack;
    
};
