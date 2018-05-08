#include "CubeSixFaces.h"


#include <glm\gtx\transform.hpp>
#include <iostream>

CubeSixFaces::CubeSixFaces(void)
{
}


CubeSixFaces::~CubeSixFaces(void)
{
}

void CubeSixFaces::Initialize()
{

	mSquare = Model();
	//f
	mSquare.VertexData.push_back(glm::vec3(-1.0f, -1.0f, 0.0f));
	mSquare.VertexData.push_back(glm::vec3(1.0f, -1.0f, 0.0f));
	mSquare.VertexData.push_back(glm::vec3(1.0f, 1.0f, 0.0f));
	mSquare.VertexData.push_back(glm::vec3(-1.0f, 1.0f, 0.0f));
	//we want a gray CubeSixFaces CubeSixFaces.
	mSquare.ColorData.push_back(glm::vec3(0.5f, 0.7f, 0.9f));
	mSquare.ColorData.push_back(glm::vec3(0.5f, 0.7f, 0.9f));
	mSquare.ColorData.push_back(glm::vec3(0.5f, 0.7f, 0.9f));
	mSquare.ColorData.push_back(glm::vec3(0.5f, 0.7f, 0.9f));
	//first.riangle.
	mSquare.IndicesData.push_back(0);
	mSquare.IndicesData.push_back(1);
	mSquare.IndicesData.push_back(3);
	//secon.triangle.
	mSquare.IndicesData.push_back(1);
	mSquare.IndicesData.push_back(2);
	mSquare.IndicesData.push_back(3);

	mSquare.NormalsData.push_back(vec3(+0, +1, 0));
	mSquare.NormalsData.push_back(vec3(+0, +1, 0));
	mSquare.NormalsData.push_back(vec3(+0, +1, 0));
	mSquare.NormalsData.push_back(vec3(+0, +1, 0));

	mSquare.UVData.push_back(glm::vec2(0.0f,1.0f));
	mSquare.UVData.push_back(glm::vec2(1.0f,1.0f));
	mSquare.UVData.push_back(glm::vec2(1.0f,0.0f));
	mSquare.UVData.push_back(glm::vec2(0.0f,0.0f));
	

mSquare.Initialize();

		


	int numberOfFaces = 6;
	mFacesModelMatrices.resize(numberOfFaces);

	//bottom
	mFacesModelMatrices[0] = glm::translate(0.0f, -1.0f, 0.0f)*glm::rotate(90.0f, glm::vec3(1.0f, 0.0f, 0.0f));
	//top
	mFacesModelMatrices[1] = glm::translate(0.0f, 1.0f, 0.0f)*glm::rotate(90.0f, glm::vec3(1.0f, 0.0f, 0.0f));
	//front
	mFacesModelMatrices[2] = glm::translate(0.0f, 0.0f, 1.0f);
	//back
	mFacesModelMatrices[3] = glm::translate(0.0f, 0.0f, -1.0f);
	//left
	mFacesModelMatrices[4] = glm::translate(-1.0f, 0.0f, 0.0f)*glm::rotate(90.0f, glm::vec3(0.0f, 1.0f, 0.0f));
	//right
	mFacesModelMatrices[5] = glm::translate(1.0f, 0.0f, 0.0f)*glm::rotate(90.0f, glm::vec3(0.0f, 1.0f, 0.0f));

	//this transformation is applied on the whole CubeSixFaces!!!
	CubeSixFacesModelMatrix = glm::scale(2.0f, 2.0f, 2.0f);

}

void CubeSixFaces::Draw(GLuint modelID,GLuint vpID, glm::mat4 V, glm::mat4 P)
{

	for (int i = 0; i < mFacesModelMatrices.size(); i++)
	{
		//cout << mFacesModelMatrices.size();
		glm::mat4 vp = P*V*CubeSixFacesModelMatrix;
		glUniformMatrix4fv(vpID, 1, GL_FALSE, &vp[0][0]);
		glUniformMatrix4fv(modelID, 1, GL_FALSE, &mFacesModelMatrices[i][0][0]);
		
		
		
			if (i == 0)
			{
				glm::vec3 squareNormal = glm::vec3(0.0,1.0, .0);
				mSquare.NormalsData[0].operator=(squareNormal);
				mSquare.NormalsData[1].operator=(squareNormal);
				mSquare.NormalsData[2].operator=(squareNormal);
				mSquare.NormalsData[3].operator=(squareNormal);
				

			}
			else if (i == 1)
			{
				glm::vec3 squareNormal = glm::vec3(0.0, -1.0, 0.0);
				mSquare.NormalsData[0].operator=(squareNormal);
				mSquare.NormalsData[1].operator=(squareNormal);
				mSquare.NormalsData[2].operator=(squareNormal);
				mSquare.NormalsData[3].operator=(squareNormal);


			}
			else if (i == 3)
			{
				glm::vec3 squareNormal = glm::vec3(0.0, 0.0, 1.0);
				mSquare.NormalsData[0].operator=(squareNormal);
				mSquare.NormalsData[1].operator=(squareNormal);
				mSquare.NormalsData[2].operator=(squareNormal);
				mSquare.NormalsData[3].operator=(squareNormal);


			}
			else if (i == 4)
			{
				glm::vec3 squareNormal = glm::vec3(1.0, 0.0, 0.0);
				mSquare.NormalsData[0].operator=(squareNormal);
				mSquare.NormalsData[1].operator=(squareNormal);
				mSquare.NormalsData[2].operator=(squareNormal);
				mSquare.NormalsData[3].operator=(squareNormal);


			}
			else if(i == 5)
			{
				glm::vec3 squareNormal = glm::vec3(-1.0, 0.0, 0.0);
				mSquare.NormalsData[0].operator=(squareNormal);
				mSquare.NormalsData[1].operator=(squareNormal);
				mSquare.NormalsData[2].operator=(squareNormal);
				mSquare.NormalsData[3].operator=(squareNormal);

			}
				else if(i == 2)
			{
				glm::vec3 squareNormal = glm::vec3(0.0, 0.0, 1.0);
				mSquare.NormalsData[0].operator=(squareNormal);
				mSquare.NormalsData[1].operator=(squareNormal);
				mSquare.NormalsData[2].operator=(squareNormal);
				mSquare.NormalsData[3].operator=(squareNormal);

			}
		
			mSquare.Update();
			mSquare.Draw();

		
		
		
		//cout << mFacesModelMatrices.size();
	}

	//glm::mat4 mvp = VP * CubeSixFacesModelMatrix * mFacesModelMatrices[3];
	//glUniformMatrix4fv(mvpUniformMatrixID, 1, GL_FALSE, &mvp[0][0]);
	//mSquare.Draw();
}
	