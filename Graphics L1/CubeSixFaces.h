//#pragma once
#ifndef CubeSixFaces_h__
#define CubeSixFaces_h__

#include "Model.h"
#include <glm/glm.hpp>
#include <vector>
#include <gl\glew.h>

class CubeSixFaces
{

	Model mSquare;
	Model mSquare2;
	std::vector<glm::mat4> mFacesModelMatrices;
public:
	CubeSixFaces(void);
	~CubeSixFaces(void);

	glm::mat4 CubeSixFacesModelMatrix;
	void Initialize();
	void CubeSixFaces::Draw(GLuint modelID,GLuint vpID, glm::mat4 V, glm::mat4 P);
	void Cleanup();};

#endif // Cube_h__
