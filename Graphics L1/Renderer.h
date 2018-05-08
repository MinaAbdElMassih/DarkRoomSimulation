#ifndef Renderer_h__
#define Renderer_h__

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
#include "table.h"
using namespace glm;
using namespace std;

class Renderer
{
	enum RenderingMode
	{
		NO_TEXTURE,
		TEXTURE_ONLY,
		BLEND
	};
	std::unique_ptr<Texture> mTexture1;
	std::unique_ptr<Texture> mTexture2;
	std::unique_ptr<Texture> mTexture3;
	

	GLuint mRenderingModeID;
	RenderingMode mRenderingMode;
	GLuint ProgramID;
	GLuint VertexBufferID;
	GLuint VertexArrayID;
	GLuint ViewProjectionMatrixID;
	GLuint ModelMatrixID;
	GLuint ModelMatrixIDtable;
	std::unique_ptr<FirstPersonCamera> myCamera;
	//GLuint MatrixID;

	//FirstPersonCamera* MyCamera;
	std::unique_ptr<Cube> myCube;
	std::unique_ptr<CubeSixFaces> skybox;
	std::unique_ptr<table> tableobject;
	std::unique_ptr<Door> mydoor;
	glm::vec3 checkvector;
	bool collision;
	GLuint EyePositionID;

	Model* MySquare;

	mat4 ModelMatrix, S, R, T;
	mat4 ModelMatrixtable;

	double PreTime;
	bool dr;
	bool close;
	GLuint AmbientLightID;
	GLuint LightPositionID;
	glm::vec3 ambientLight;
	glm::vec3 lightPosition;
	int i;
	int ii;
	int za2a;
	int za2aright;
	bool open;

	ShaderProgram StaticShader;
Model3D StaticModel; // Stores 3D Model Data
mat4 StaticModelMatrix;

//ShaderProgram StaticShader1;
Model3D StaticModel1; // Stores 3D Model Data
mat4 StaticModelMatrix1;


//ShaderProgram StaticShader2;
Model3D StaticModel2; // Stores 3D Model Data
mat4 StaticModelMatrix2;


//ShaderProgram StaticShader3;
Model3D StaticModel3; // Stores 3D Model Data
mat4 StaticModelMatrix3;


//ShaderProgram StaticShader4;
Model3D StaticModel4; // Stores 3D Model Data
mat4 StaticModelMatrix4;

//ShaderProgram StaticShader5;
Model3D StaticModel5; // Stores 3D Model Data
mat4 StaticModelMatrix5;




///////

GLfloat choiceeID;
	GLfloat choice_id;
	GLfloat choicee ;
	GLfloat choice ;
	GLfloat choice2 ;
	GLfloat choicee2 ;
	vec3 al, dl, sl, lightpos;
	vec3 al2, dl2, sl2, lightpos2;
	GLuint al_id, dl_id, sl_id, light_id, cam_id;
	GLuint al2_id, dl2_id, sl2_id, light_id2, cam_id2;
	GLuint lookdirid;
	GLuint lookdirid2;

///////


public:
	Renderer();
	~Renderer();
	
	void Renderer::closeUpdate();
	void Initialize(int WindowWidth, int WindowHeight);
	void Draw();
	void HandleKeyboardInput(int Key,GLFWwindow* window);
	void HandleMouseMove(double DeltaX, double DeltaY);
	void HandleMouseClick(int MouseAction, int MouseButton, double MouseXPos, double MouseYPos);
	void HandleWindowResize(int WindowWidth, int WindowHeight);
	void Update();
	void Renderer::movetvright();
	void movetv();
	void Cleanup();
	void DUpdate();
};

#endif