#include "Door.h"

#include <glm\gtx\transform.hpp>
Door::Door(void)
{
}


Door::~Door(void)
{
}


void Door::Initialize()
{
		mSquare2 = Model();
		//f
		mSquare2.VertexData.push_back(glm::vec3(-0.5f, -0.5f, 0.0f));
		mSquare2.VertexData.push_back(glm::vec3(0.5f, -0.5f, 0.0f));
		mSquare2.VertexData.push_back(glm::vec3(0.5f, 0.5f, 0.0f));
		mSquare2.VertexData.push_back(glm::vec3(-0.5f, 0.5f, 0.0f));

		mSquare2.VertexData.push_back(glm::vec3(0.5f, 0.5f, 0.0f));
		mSquare2.VertexData.push_back(glm::vec3(-0.5f, 0.5f, 0.0f));
		mSquare2.VertexData.push_back(glm::vec3(-0.5f, -0.5f, 0.0f));
		mSquare2.VertexData.push_back(glm::vec3(0.5f, -0.5f, 0.0f));
		//we want a gray cube cube.
		mSquare2.ColorData.push_back(glm::vec3(0.0f, 1.0f, 1.0f));
		mSquare2.ColorData.push_back(glm::vec3(0.0f, 1.0f, 1.0f));
		mSquare2.ColorData.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
		mSquare2.ColorData.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
		//first.riangle.
		mSquare2.IndicesData.push_back(0);
		mSquare2.IndicesData.push_back(1);
		mSquare2.IndicesData.push_back(3);
		//secon.triangle.
		mSquare2.IndicesData.push_back(1);
		mSquare2.IndicesData.push_back(2);
		mSquare2.IndicesData.push_back(3);


				//first.riangle.
		mSquare2.IndicesData.push_back(4);
		mSquare2.IndicesData.push_back(5);
		mSquare2.IndicesData.push_back(7);
		//secon.triangle.
		mSquare2.IndicesData.push_back(5);
		mSquare2.IndicesData.push_back(6);
		mSquare2.IndicesData.push_back(7);

		glm::vec3 squareNormal = glm::vec3(0.0, 0.0, 1.0);
		mSquare2.NormalsData.push_back(squareNormal);
		mSquare2.NormalsData.push_back(squareNormal);
		mSquare2.NormalsData.push_back(squareNormal);
		mSquare2.NormalsData.push_back(squareNormal);



		mSquare2.Initialize();

		
		mDoorFace=  glm::translate(0.0f, 0.0f, 1.0f) * glm::scale(2.0f, 2.0f, 2.0f);

}




void Door::Draw(GLuint modelID,GLuint vpID, glm::mat4 V, glm::mat4 P)
{

		glm::mat4 vp = P*V*glm::scale(10.0f, 10.0f, 10.0f);
		glUniformMatrix4fv(vpID, 1, GL_FALSE, &vp[0][0]);
		glUniformMatrix4fv(modelID, 1, GL_FALSE, &mDoorFace[0][0]);
		mSquare2.Draw();
}







