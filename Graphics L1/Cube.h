#ifndef Cube_h__
#define Cube_h__

#include "Model.h"
#include <glm/glm.hpp>
#include <vector>
#include <gl/glew.h>
#include <gl/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <memory>
#include "texture.h"
#include "table.h"
using namespace glm;
using namespace std;
class Cube
{
	Model mSquare;
	Model mSquare2;
	std::vector<glm::mat4> mFacesModelMatrices;
	std::unique_ptr<Texture> mTexture1;
	std::unique_ptr<Texture> mTexture2;
	enum RenderingMode
	{
		NO_TEXTURE,
		TEXTURE_ONLY,
		BLEND
	};
	GLuint ProgramID;
	GLuint mRenderingModeID;
	RenderingMode mRenderingMode;
public:
	Cube(void);
	~Cube(void);

	glm::mat4 CubeModelMatrix;
	void Initialize();
	void Cube::Draw(GLuint modelID,GLuint vpID, glm::mat4 V, glm::mat4 P);
	void Cleanup();
};

#endif // Cube_h__
