#ifndef Door_h__
#define Door_h__

#include "Model.h"
#include <glm/glm.hpp>
#include <vector>
#include <gl\glew.h>

#pragma once
class Door
{
	Model mSquare2;
	Model mSquare3;

public:
	Door(void);
	~Door(void);
	//glm::mat4 DoorModelMatrix;
	glm::mat4 mDoorFace;
	void Initialize();
	void Door::Draw(GLuint modelID, GLuint vpID, glm::mat4 V, glm::mat4 P);
	void Cleanup();
	

};


#endif 