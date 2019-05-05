#include "MyScene.h"
#include "Skybox.h"
#include "House.h"
#include "Human.h"
#include "Lamp.h"
#include "Moon.h"
#include "Windmill.h"

MyScene::MyScene(int argc, char** argv, const char *title, const int& windowWidth, const int& windowHeight)
	: Scene(argc, argv, title, windowWidth, windowHeight)
{

}

void MyScene::Initialise()
{
    glEnable(GL_LIGHT1);
	glClearColor(0.f, 0.f, 0.f, 1.0f);
    GlobalLight(0.1f,0.1f,0.1f);
    

    //aaaa
    
    GLuint ft = Scene::GetTexture("stars.bmp");
    GLuint bk = Scene::GetTexture("stars.bmp");
    GLuint lf = Scene::GetTexture("stars.bmp");
    GLuint rt = Scene::GetTexture("stars.bmp");
    GLuint up = Scene::GetTexture("stars.bmp");
    GLuint dn = Scene::GetTexture("grass2.bmp");
    
    GLuint roof = Scene::GetTexture("brownRoof.bmp");
    GLuint fullBricks = Scene::GetTexture("tBricks3.bmp");
    GLuint door = Scene::GetTexture("door.bmp");
    GLuint tWindow = Scene::GetTexture("window.bmp");
    GLuint tLamp = Scene::GetTexture("lamp.bmp");
    GLuint tChain = Scene::GetTexture("chain.bmp");
    GLuint tMoon = Scene::GetTexture("tMoon.bmp");
    
    GLuint tBase = Scene::GetTexture("tBricks.bmp");
    GLuint tMiddle = Scene::GetTexture("tTop.bmp");
    GLuint tTop = Scene::GetTexture("tTop.bmp");
    GLuint tRoof = Scene::GetTexture("brownRoof.bmp");
    GLuint tBlade = Scene::GetTexture("tMoon.bmp");
   
    
    House *house = new House(fullBricks,roof,door,tWindow);
    //cube->size(1000.0f, 1000.0f, 1000.0f);
    AddObjectToScene(house);
    
    
    Skybox *skybox = new Skybox(up,dn,lf,rt,ft,bk);
    //skybox->size(10000.0f, 1000.0f, 10000.0f);
    AddObjectToScene(skybox);
    
    
    
    Human *human = new Human();
    AddObjectToScene(human);
    
    Lamp *lamp= new Lamp(tLamp,tChain);
    AddObjectToScene(lamp);
    
    Moon *moon = new Moon(tMoon);
    AddObjectToScene(moon);
    
    Windmill *windmill = new Windmill(tBase,tMiddle, tTop, tRoof, tBlade);
    AddObjectToScene(windmill);
    
}

void MyScene::Projection()
{
	GLdouble aspect = static_cast<GLdouble>(windowWidth) / static_cast<GLdouble>(windowHeight);
	gluPerspective(60.0, aspect, 1.0, 30000.0);
}

void MyScene::GlobalLight(float x,float y,float z)
{
    //ambient light
    GLfloat ambient[3] = { x, y, z};
    GLfloat diffuse[3] = { 0, 0, 0};
    GLfloat specular[3] = {0, 0,0};
    
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
}
