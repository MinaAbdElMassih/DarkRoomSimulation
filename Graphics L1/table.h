#pragma once
#ifndef table_h__
#define table_h__
#include <gl\glew.h>
#include <gl\glfw3.h>
#include "glm/glm.hpp"
#include "glm/gtx/transform.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "shader.hpp"
#include "Model.h"
#include "FirstPersonCamera.h"
#include "Cube.h"
#include "Door.h"
#include "CubeSixFaces.h"

#include "ShaderProgram.h"
#include "Model3D.h"

#include <gl/glew.h>
#include <gl/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <memory>
#include "texture.h"
using namespace glm;
using namespace std;
#include "CubeSixFaces.h"

class table
{
	std::unique_ptr<CubeSixFaces> leg1;
	std::unique_ptr<CubeSixFaces> leg2;
	std::unique_ptr<CubeSixFaces> leg3;
	std::unique_ptr<CubeSixFaces> leg4;
	std::unique_ptr<CubeSixFaces> table1;
public:
	glm::mat4 tableModelMatrix;
	table(void);
	~table(void);
	void intialize();
	void draw(GLuint modelID,GLuint vpID, glm::mat4 V, glm::mat4 P);
};

#endif 