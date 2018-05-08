#include "Renderer.h"

#include <iostream>
#include <Windows.h>
#include <gl/glew.h>
#include <gl/glfw3.h>

//#include <Windows.h>
Renderer::Renderer()
{
	collision=false;
	i=0;
	ii=0;
	za2a=0;
	za2aright=0;
	dr=false;
	close=false;
	open=false;
}

Renderer::~Renderer()
{
	Cleanup();
}

void Renderer::Initialize(int WindowWidth, int WindowHeight)
{
	StaticShader.LoadProgram();
StaticModel.LoadFromFile("E:\\Third Year\\Second Semester\\Graphics\\3r29frksn740-chair\\chair\\chair.obj", true);

StaticModel.Initialize();
StaticModel1.LoadFromFile("E:\\Third Year\\Second Semester\\Graphics\\5pqljcshf3pc-sofa\\sofa.obj", true);

StaticModel1.Initialize();

StaticModel2.LoadFromFile("E:\\Third Year\\Second Semester\\Graphics\\7ospnjs46bk0-1\\ROUND SOFA\\ROUND SOFA.obj", true);

StaticModel2.Initialize();

StaticModel3.LoadFromFile("E:\\Third Year\\Second Semester\\Graphics\\vases\\FreebieVases.obj", true);

StaticModel3.Initialize();

StaticModel4.LoadFromFile("E:\\Third Year\\Second Semester\\Graphics\\c1l46pdjvke8-tdv\\tdv.obj", true);

StaticModel4.Initialize();

StaticModel5.LoadFromFile("E:\\Third Year\\Second Semester\\Graphics\\5u1w4d4lq7sw-Kids_Reading_Table\\Kids Reading Table_01_obj.obj", true);

StaticModel5.Initialize();



///////
/*
choiceeID = glGetUniformLocation(ProgramID, "choicee2");
	lightpos = vec3(0.0f, 25.0f, 10.0f);
	/*al2 = vec3(0.3f, 0.3f, 0.3f);
	dl2 = vec3(1.0f, 1.0f, 1.0f);
	sl2 = vec3(1.0f, 1.0f, 1.0f);*/
/*
	al2_id = glGetUniformLocation(ProgramID, "al2");
	dl2_id = glGetUniformLocation(ProgramID, "dl2");
	sl2_id = glGetUniformLocation(ProgramID, "sl2");
	choice_id = glGetUniformLocation(ProgramID, "choice2");
	light_id2 = glGetUniformLocation(ProgramID, "lightpos2");
	lookdirid2 = glGetUniformLocation(ProgramID, "lookdir");
	cam_id2 = glGetUniformLocation(ProgramID, "camerapos");*/
	


///////

	myCamera = std::unique_ptr<FirstPersonCamera>(new FirstPersonCamera());
	PreTime = glfwGetTime();

	glClearColor(0, 0, 0, 0);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	//////////////////////////////////////////////////////////////////////////
	// Camera
	//MyCamera = new FirstPersonCamera();
	// Projection matrix : 
	//MyCamera->SetPerspectiveProjection(45.0f, (float)WindowWidth / (float)WindowHeight, 0.1f, 1000.0f);
	//// View matrix : 
	//MyCamera->SetLookAt(
	//	vec3(+0.0f, +0.0f, +5.0f),// Camera Position
	//	vec3(+0.0f, +0.0f, +0.0f),// Look at Point
	//	vec3(+0.0f, +1.0f, +0.0f) // Up Vector
	//	);
	//////////////////////////////////////////////////////////////////////////

	//////////////////////////////////////////////////////////////////////////
	// Create and compile our GLSL program from the shaders
	ProgramID = LoadShaders("SimpleVertexShader.vertexshader", "SimpleFragmentShader.fragmentshader");
	//////////////////////////////////////////////////////////////////////////
	mRenderingModeID = glGetUniformLocation(ProgramID,"RenderingMode");
	//////////////////////////////////////////////////////////////////////////
	// Use our shader
	glUseProgram(ProgramID);
	// Get the ID of VP from shaders
	ViewProjectionMatrixID = glGetUniformLocation(ProgramID, "ViewProjectionMatrix");
	// Get the ID of ModelMatrix from shaders
	ModelMatrixID = glGetUniformLocation(ProgramID, "ModelMatrix");

	///////////////////////

	choiceeID = glGetUniformLocation(ProgramID, "choicee");
	lightpos = vec3(1.0f, 1.0f, 0.0f);
	al = vec3(0.3f, 0.3f, 0.3f);// ÈíÛíÑ áæä ÇáÈÑæÌßÊ ßáå 
	dl = vec3(1.0f, 1.0f, 1.0f);//ÈíÛíÑ áæä ÇáÍÇÌÇÊ Çááí ÈíÞÚ ÚáíåÇ ÇáßÔÇÝ
	sl = vec3(1.0f, 1.0f, 1.0f);
	al_id = glGetUniformLocation(ProgramID, "al");
	dl_id = glGetUniformLocation(ProgramID, "dl");
	sl_id = glGetUniformLocation(ProgramID, "sl");
	choice_id = glGetUniformLocation(ProgramID, "choice");
	light_id = glGetUniformLocation(ProgramID, "lightpos");
	lookdirid = glGetUniformLocation(ProgramID, "lookdir");//ÇáßÔÇÝ
	//cam_id = glGetUniformLocation(ProgramID, "camerapos");

	/////////////////////////
	//ModelMatrixIDtable = glGetUniformLocation(ProgramID, "ModelMatrix");
	//////////////////////////////////////////////////////////////////////////

	//////////////////////////////////////////////////////////////////////////
	// Initialization using the Ordinary Way
	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);

	GLfloat VertexData[] = {
		-1.0f, +1.0f, 0.0f, 1, 0, 0,
		+1.0f, +1.0f, 0.0f, 1, 0, 0,
		-1.0f, -1.0f, 0.0f, 1, 0, 0,
		+1.0f, +1.0f, 0.0f, 1, 0, 0,
		-1.0f, -1.0f, 0.0f, 1, 0, 0,
		+1.0f, -1.0f, 0.0f, 1, 0, 0,
	};

	glGenBuffers(1, &VertexBufferID);
	glBindBuffer(GL_ARRAY_BUFFER, VertexBufferID);
	glBufferData(GL_ARRAY_BUFFER, sizeof(VertexData), VertexData, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (void*)(0 * sizeof(GLfloat)));
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));

	S = scale(0.5f, 0.5f, 0.5f);
	T = translate(-1.0f, 0.0f, -1.0f);
	R = rotate(0.0f, vec3(0, 0, 1));
	//ModelMatrix = T * R * S;
	//////////////////////////////////////////////////////////////////////////

	//////////////////////////////////////////////////////////////////////////
	// Initialization using Model Class
	// Square consists of 4 vertices
	MySquare = new Model();
	// adding 4 positions
	MySquare->VertexData.push_back(vec3(-0.25, +0.25, 0));
	MySquare->VertexData.push_back(vec3(+0.25, +0.25, 0));
	MySquare->VertexData.push_back(vec3(+0.25, -0.25, 0));
	MySquare->VertexData.push_back(vec3(-0.25, -0.25, 0));
	// adding 4 colors
	MySquare->ColorData.push_back(vec3(+1, +0, +0));
	MySquare->ColorData.push_back(vec3(+1, +0, +0));
	MySquare->ColorData.push_back(vec3(+1, +0, +0));
	MySquare->ColorData.push_back(vec3(+1, +0, +0));
	// adding 4 normals
	MySquare->NormalsData.push_back(vec3(+0, +0, 1));
	MySquare->NormalsData.push_back(vec3(+0, +0, +1));
	MySquare->NormalsData.push_back(vec3(+0, +0, +1));
	MySquare->NormalsData.push_back(vec3(+0, +0, +1));
	// adding 6 indices
	MySquare->IndicesData.push_back(0);
	MySquare->IndicesData.push_back(1);
	MySquare->IndicesData.push_back(2);
	MySquare->IndicesData.push_back(0);
	MySquare->IndicesData.push_back(2);
	MySquare->IndicesData.push_back(3);

		MySquare->UVData.push_back(glm::vec2(0.0f,1.0f));
	MySquare->UVData.push_back(glm::vec2(1.0f,1.0f));
	MySquare->UVData.push_back(glm::vec2(1.0f,0.0f));
	MySquare->UVData.push_back(glm::vec2(0.0f,0.0f));
	/*MySquare->UVData.push_back(glm::vec2(0.0f,0.0f));
	MySquare->UVData.push_back(glm::vec2(1.0f,0.0f));
	MySquare->UVData.push_back(glm::vec2(0.0f,1.0f));
	MySquare->UVData.push_back(glm::vec2(1.0f,1.0f));*/
	
	


	// send data to GPU
	MySquare->Initialize();
	myCube = std::unique_ptr<Cube>(new Cube());
	myCube->Initialize();
	mydoor = std::unique_ptr<Door>(new Door());
	mydoor->Initialize();

	

	skybox = std::unique_ptr<CubeSixFaces>(new CubeSixFaces());
	skybox->Initialize();

	/*table = std::unique_ptr<CubeSixFaces>(new CubeSixFaces());
	table->Initialize();*/

	tableobject = std::unique_ptr<table>(new table());
	tableobject->intialize();
	
	
	mTexture1 = std::unique_ptr<Texture>(new Texture("E:\\Third Year\\Second Semester\\Graphics\\kzbpra2va7ls-4Chair2Tone\\4 Chair 2 Tone\\Texture\\Chair Leather.png",0));
	mTexture2 = std::unique_ptr<Texture>(new Texture("E:\\my-hd-j4303-ua32j4303akxxm-002-front-indigoblue.jpg",1));
	mTexture3 = std::unique_ptr<Texture>(new Texture("E:\\Third Year\\Second Semester\\Graphics\\images.jpg",1));
	
	// Transformations
	S = scale(15.0f, 10.0f, 0.5f);
	T = translate(0.0f, 0.5f, -19.0f);
	R = rotate(45.0f, vec3(0, 0, 1));
	MySquare->ModelMatrix = S*T*glm::rotate(180.0f, glm::vec3(1.0f, 0.0f, 0.0f)) ;


		//////////////////////////////////////////////////////////////////////////
	// Configure the light.
	//setup the light position.
	LightPositionID = glGetUniformLocation(ProgramID,"LightPosition_worldspace");
	lightPosition = glm::vec3(1.0,0.25,0.0);
	glUniform3fv(LightPositionID,1, &lightPosition[0]);
	//setup the ambient light component.
	AmbientLightID = glGetUniformLocation(ProgramID,"ambientLight");
	ambientLight = glm::vec3(-0.5,-0.5,-0.5);
	glUniform3fv(AmbientLightID,1, &ambientLight[0]);
	//setup the eye position.
	EyePositionID = glGetUniformLocation(ProgramID,"EyePosition_worldspace");
	//////////////////////////////////////////////////////////////////////////

	myCamera->SetPerspectiveProjection(45.0f, 4.0f / 3.0f, 0.1f, 100.0f);

	// View matrix : 
	myCamera->Reset(0.0, 0.0,26.0,
		0, 0, 0,
		0, 1, 0);

	//send the eye position to the shaders.
	glUniform3fv(EyePositionID, 1, &myCamera->GetEyePosition()[0]);
	//////////////////////////////////////////////////////////////////////////
}
void Renderer::Draw()
{
	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	// Use our shader
	glUseProgram(ProgramID);
	glm::mat4 P = myCamera->GetProjectionMatrix() ;
	glm::mat4 V = myCamera->GetViewMatrix();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//glUseProgram(ProgramID);

	mat4 ViewProjectionMatrix = myCamera->GetProjectionMatrix() * myCamera->GetViewMatrix();

	///////////
	//glUniformMatrix4fv(ViewProjectionMatrixID, 1, GL_FALSE, &ViewProjectionMatrix[0][0]);

	//glUniform3fv(al_id, 1, &al[0]);//Ïå äæÑ ÇáÈÑæÌßÊ ßáå
	//glUniform3fv(dl_id,1 , &dl[0]);//Ïå ÇáßÔÇÝ
	//glUniform3fv(sl_id, 1, &sl[0]);
	//glUniform1f(choice_id, choice);//Ïå Çááí ÈíÎáí ÇáßÔÇÝ ÔÛÇá æ ÇáäæÑ íØÝí æ íæáÚ æ áæ ÚãáäÇå ßæãäÊ ÇáäæÑ ÈíÔÊÛá æ ÇáßÔÇÝ áÃ
	//


	//glUniform3fv(lookdirid, 1, &myCamera->GetLookDirection()[0]);
	//glUniform3fv(light_id, 0, &lightpos[0]);
	//glUniform3fv(cam_id, 1, &myCamera->GetEyePosition()[0]);


	/////////

	mRenderingMode = RenderingMode::TEXTURE_ONLY;
		glUniform1i(mRenderingModeID,mRenderingMode);
	/*mRenderingMode = RenderingMode::TEXTURE_ONLY;
	glUniform1i(mRenderingModeID, mRenderingMode);*/

	



		
	glUniformMatrix4fv(ModelMatrixID, 1, GL_FALSE, &MySquare->ModelMatrix[0][0]);
	////////

	mTexture3->Bind();
	//skybox->CubeSixFacesModelMatrix=glm::scale(50,50,50);
	
	//////////////////////////////////////////////////////////////////////////
	// Drawing using the Ordinary Way
	
	//glUniform1f(choiceeID, 1.0f);
	///////
	
	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	//Draw the cube.

	mRenderingMode = RenderingMode::NO_TEXTURE;
	mTexture2->Bind();
	MySquare->Draw();
	
	/*skybox->Draw(ModelMatrixID,ViewProjectionMatrixID, V,P);
	skybox->CubeSixFacesModelMatrix=glm::scale(100,100,500);*/
		glUniform1i(mRenderingModeID,mRenderingMode);
		//glUniformMatrix4fv(ModelMatrixID, 1, GL_FALSE, &table->CubeSixFacesModelMatrix[0][0]);
	//table->Draw(ModelMatrixID,ViewProjectionMatrixID, V,P);
		glUniform1f(choiceeID, 1.0f);
		tableobject->draw(ModelMatrixID,ViewProjectionMatrixID, V,P);
		tableobject->tableModelMatrix=glm::scale(0.1f, 0.1f, 0.1f)*tableobject->tableModelMatrix;

		//glUniformMatrix4fv(ModelMatrixID, 1, GL_FALSE, &myCube->CubeModelMatrix[0][0]);
		//glUniform1f(choiceeID, 1.0f);
	myCube->Draw(ModelMatrixID,ViewProjectionMatrixID, V,P);
	glUniform1f(choiceeID, 1.0f);
	//glUniformMatrix4fv(ModelMatrixID, 1, GL_FALSE, &mydoor->mDoorFace[0][0]);
	mydoor->Draw(ModelMatrixID,ViewProjectionMatrixID, V,P);

	
	//glUniformMatrix4fv(ModelMatrixID, 1, GL_FALSE, &table->CubeSixFacesModelMatrix[0][0]);
	//glUniformMatrix4fv(ModelMatrixID, 1, GL_FALSE, &MySquare->ModelMatrix[0][0]);
	
	////////////////////////////////////////////////////////////////////
	mRenderingMode = RenderingMode::TEXTURE_ONLY;
		glUniform1i(mRenderingModeID,mRenderingMode);
	//mTexture1->Bind();
	mTexture3->Bind();

//StaticShader.UseProgram();
//StaticShader.BindViewProjectionMatrix(&ViewProjectionMatrix[0][0]);mat4 R = rotate(45.0f, 0.0f, 0.0f, 0.0f);
mat4 T = translate(1.0f, 0.0f, 0.0f);
mat4 S = scale(-10.0f, -10.0f,- 10.0f);
//StaticModelMatrix = T * R * S;
//StaticShader.BindModelMatrix(&StaticModelMatrix[0][0]);
//StaticModel.Render(&StaticShader); // Draw the Model//mTexture3->Bind();StaticShader.UseProgram();
StaticShader.BindViewProjectionMatrix(&ViewProjectionMatrix[0][0]);//mat4 R = rotate(45.0f, 0.0f, 0.0f, 0.0f);
//mat4 T = translate(1.0f, 0.0f, 0.0f);
//mat4 S = scale(-10.0f, -10.0f,- 10.0f);
//StaticModelMatrix = T * R * S;
//StaticShader.BindModelMatrix(&StaticModelMatrix[0][0]);
StaticModel1.Render(&StaticShader); // Draw the Model
StaticModel2.Render(&StaticShader); 
//StaticShader3.UseProgram();
//StaticShader3.BindViewProjectionMatrix(&ViewProjectionMatrix[0][0]);//mat4 R = rotate(45.0f, 0.0f, 0.0f, 0.0f);
//mat4 T = translate(1.0f, 0.0f, 0.0f);
//mat4 S = scale(-10.0f, -10.0f,- 10.0f);
//StaticModelMatrix = T * R * S;
//StaticShader3.BindModelMatrix(&StaticModelMatrix[0][0]);
StaticModel3.Render(&StaticShader); 

//StaticShader4.UseProgram();
//StaticShader4.BindViewProjectionMatrix(&ViewProjectionMatrix[0][0]);//mat4 R = rotate(45.0f, 0.0f, 0.0f, 0.0f);
//mat4 T = translate(1.0f, 0.0f, 0.0f);
//mat4 S = scale(-10.0f, -10.0f,- 10.0f);
//StaticModelMatrix = T * R * S;
//StaticShader4.BindModelMatrix(&StaticModelMatrix[0][0]);
StaticModel4.Render(&StaticShader); 

mTexture2->Bind();


//StaticShader5.UseProgram();
//StaticShader5.BindViewProjectionMatrix(&ViewProjectionMatrix[0][0]);//mat4 R = rotate(45.0f, 0.0f, 0.0f, 0.0f);
//mat4 T = translate(1.0f, 0.0f, 0.0f);
//mat4 S = scale(-10.0f, -10.0f,- 10.0f);
//StaticModelMatrix = T * R * S;
//StaticShader5.BindModelMatrix(&StaticModelMatrix[0][0]);
StaticModel5.Render(&StaticShader); 
}

void Renderer::Update()
{
	double CurrentTime = glfwGetTime();
	double DeltaTime = (CurrentTime - PreTime)*1000;
	PreTime = CurrentTime;
	/*double speed=0.1;
	double rotationangle=speed*DeltaTime;
	glm::mat4 translateMat = glm::translate(0.5f, 0.0f, 0.0f);
	mydoor->mDoorFace=translateMat* mydoor->mDoorFace;
*/
}


void Renderer::DUpdate()
{
	if(dr==true&&i!=1000)
	{
	double CurrentTime = glfwGetTime();
	double DeltaTime = (CurrentTime - PreTime)*1000;
	PreTime = CurrentTime;
	double speed=0.1;
	double rotationangle=speed*DeltaTime;
	//glm::mat4 translateMat =glm::translate(0.2f, 0.0f, 0.0f);
	mydoor->mDoorFace=mydoor->mDoorFace*glm::rotate(90.0f*((float)DeltaTime), glm::vec3(0.0f, 1.0f, 0.0f));
	
	i++;
	}
	if(i==1000)
	{
		PlaySound(NULL, 0, 0);
		dr=false;
		i=0;
	}
	//while (i=10);
}
void Renderer::closeUpdate()
{
	if(close==true&&ii!=1000)
	{
	double CurrentTime = glfwGetTime();
	double DeltaTime = (CurrentTime - PreTime)*1000;
	PreTime = CurrentTime;
	double speed=0.1;
	double rotationangle=speed*DeltaTime;
	//glm::mat4 translateMat =glm::translate(-0.2f, 0.0f, 0.0f);
	mydoor->mDoorFace=mydoor->mDoorFace*glm::rotate(-90.0f*((float)DeltaTime), glm::vec3(0.0f, 1.0f, 0.0f));
	
	ii++;
	}
	if(ii==1000)
	{
		PlaySound(NULL, 0, 0);
		close=false;
		ii=0;
	}
	//while (i=10);
}

void Renderer::HandleKeyboardInput(int key,GLFWwindow* window)
{
	checkvector = myCamera->GetEyePosition();
	
	switch (key)
	{
		//Moving forward
	case GLFW_KEY_UP:
	case GLFW_KEY_W:
		//checkvector.z > -10 && checkvector.z < 10 
		if (collision==true && checkvector.z>-2.4)
		{
			//cout<<checkvector.z;
			myCamera->Walk(0.5);
		}
		else if(checkvector.z > -8 && open==true && collision==false)
			
		{
			//cout<<"hhh";
			myCamera->Walk(0.5);
		}
		//	myCamera->Walk(0.5);
		/*cout<<"*";
		cout<<checkvector.x;
		cout<<" ";
		cout<<checkvector.y;
		cout<<" ";
		cout<<checkvector.z;
		cout<< "*";*/
		
		break;

		//Moving backword
	case GLFW_KEY_DOWN:
	case GLFW_KEY_S:
		if(open==false && collision==false)
		{
			myCamera->Walk(-0.5);
		}
		else if(collision==true && checkvector.z < 10)
		{
			myCamera->Walk(-0.5);
			
		}
		/*else if ( collision==false&&checkvector.z < 26 )
		{
			myCamera->Walk(-0.5);
		}
		*/
		else if(open==true && collision==false)

			myCamera->Walk(-0.5);
		/*else if (collision == false)
			myCamera->Walk(-0.5);*/
	
		break;

		// Moving right
	case GLFW_KEY_RIGHT:
	case GLFW_KEY_D:
		if (checkvector.x < 9 )
		{
			myCamera->Strafe(0.1);
		}
		/*else if (collision == false)
			myCamera->Strafe(0.1);*/
		
		break;

		// Moving left
	case GLFW_KEY_LEFT:
	case GLFW_KEY_A:
		if ( checkvector.x > -9 )
		{
			myCamera->Strafe(-0.1);
		}
		/*else if (collision == false)
			myCamera->Strafe(-0.1);*/

		break;
		
		// Moving up
	case GLFW_KEY_SPACE:
	case GLFW_KEY_R:
		if (checkvector.y< 6  )
		{
			myCamera->Fly(0.1);
		}
	/*	else if (collision == false)
			myCamera->Fly(0.1);*/

		break;

		// Moving down
	case GLFW_KEY_LEFT_CONTROL:
	case GLFW_KEY_F:
		if (collision==true && checkvector.y> -8 )
		{
			myCamera->Fly(-0.1);
		}
		else if ( checkvector.y> -7 )
		{
			myCamera->Fly(-0.1);
		}
		/*else if (collision == false)
			myCamera->Fly(-0.1);*/
		break;

	case GLFW_KEY_H:
		myCamera->Reset
			(
			0, 10, 10,
			0, 0, 0,
		0,-1, 0
		);

		//myCamera->Fly(3);
		//myCamera->Yaw(-1);
		//myCamera->Roll(-1);
		myCamera->Pitch(-1);
		
		//glUniform3fv(EyePositionID, 1, &myCamera->GetEyePosition()[0]);
		
		collision = true;
		
		break;

	case GLFW_KEY_N:
		//mydoor->mDoorFace = glm::rotate(90.0f, glm::vec3(0.0f, 1.0f, 0.0f))* glm::translate(3.5f, 0.0f, 0.0f)* mydoor->mDoorFace;
		
		mydoor->mDoorFace = glm::translate(0.5f, 0.0f, 0.0f)* mydoor->mDoorFace;
		//PlaySound(TEXT("C:\\wave.wav"), NULL,SND_ASYNC)
		PlaySound(TEXT("C:\\Users\\LENOVO.SYR\\Downloads\\creaking-door-1.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
			//DUpdate();
		dr=true;
		open=true;
		
		
		break;

	case GLFW_KEY_M:
		myCamera->Reset(0.0, 0.0, 26.0,
			0, 0, 0,
			0, 1, 0);
		//myCamera->Yaw(-0.1);
	myCamera->Pitch(0.4);
		collision = false;
		myCamera->Fly(4);
		//myCamera->Pitch(5);
		break;
		case GLFW_KEY_K:

			/*mydoor->Initialize();
			mydoor->Draw(ModelMatrixID,ViewProjectionMatrixID, myCamera->GetViewMatrix(),myCamera->GetProjectionMatrix());*/
			mydoor->mDoorFace = glm::translate(-0.5f, 0.0f, 0.5f)* mydoor->mDoorFace;
			PlaySound(TEXT("C:\\Users\\LENOVO.SYR\\Downloads\\creaking-door-1.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
			
		close=true;
			open=false;
		break;


		case GLFW_KEY_T:

			if ( za2a<=60)
		{
			movetv();
			za2a++;
			za2aright--;
		}
			
			
		break;

		case GLFW_KEY_Q:

			if ( za2aright<=60)
		{
			movetvright();
			za2aright++;
			za2a--;
		}
			
			else
				
				{
					//za2aright=0;
			
				//za2a=0;
			}
		break;


		case GLFW_KEY_L:

			ambientLight = glm::vec3(-2.2,-2.2,-2.2);
	glUniform3fv(AmbientLightID,1, &ambientLight[0]);
		break;

		


		case GLFW_KEY_Z:

			ambientLight = glm::vec3(-0.5,-0.5,-0.5);
	glUniform3fv(AmbientLightID,1, &ambientLight[0]);
		break;

		

	default:
		break;
	}


	//continue the remaining movements.

	myCamera->UpdateViewMatrix();

	//update the eye position uniform.
	glUniform3fv(EyePositionID, 1, &myCamera->GetEyePosition()[0]);

}

void Renderer::HandleMouseMove(double DeltaX, double DeltaY)
{
	
	myCamera->Yaw(DeltaX);
	myCamera->Pitch(DeltaY);
	myCamera->UpdateViewMatrix();
	//update the eye position uniform.
	glUniform3fv(EyePositionID,1, &myCamera->GetEyePosition()[0]);
	/*cout<<"*";
	cout<<DeltaX;
	cout<<" ";
	cout<<DeltaY;
	cout<<"*";*/
	/*cout<<myCamera->;
	cout<<"*";*/
}

void Renderer::HandleMouseClick(int MouseAction, int MouseButton, double MouseXPos, double MouseYPos)
{
	cout<<"*";
	cout<<MouseXPos;
	cout<<" ";
	cout<<MouseYPos;
	cout<<"*";
}

void Renderer::HandleWindowResize(int WindowWidth, int WindowHeight)
{
	myCamera->SetPerspectiveProjection(45.0f, (float)WindowWidth / (float)WindowHeight, 0.1f, 1000.0f);
}

void Renderer::Cleanup()
{
	glDeleteProgram(ProgramID);
	//delete MyCamera;
}

void Renderer::movetv()
{
	MySquare->ModelMatrix=glm::translate(-0.1f, 0.0f, 0.0f)*MySquare->ModelMatrix;
}
void Renderer::movetvright()
{
	MySquare->ModelMatrix=glm::translate(0.1f, 0.0f, 0.0f)*MySquare->ModelMatrix;
}