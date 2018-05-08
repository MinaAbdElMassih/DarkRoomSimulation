#include "table.h"


table::table(void)
{
}


table::~table(void)
{
}

void table::intialize()
{
	leg1 = std::unique_ptr<CubeSixFaces>(new CubeSixFaces());
	leg1->Initialize();

	leg2 = std::unique_ptr<CubeSixFaces>(new CubeSixFaces());
	leg2->Initialize();

	leg3 = std::unique_ptr<CubeSixFaces>(new CubeSixFaces());
	leg3->Initialize();

	leg4 = std::unique_ptr<CubeSixFaces>(new CubeSixFaces());
	leg4->Initialize();

	table1 = std::unique_ptr<CubeSixFaces>(new CubeSixFaces());

	//tableModelMatrix=glm::scale(0.1f, 0.1f, 0.1f);
	table1->Initialize();

}

void table::draw(GLuint modelID,GLuint vpID, glm::mat4 V, glm::mat4 P)
{
	leg1->CubeSixFacesModelMatrix=  glm::scale(0.4f, 1.0f, 0.5f)*glm::translate(5.0f, -9.0f, 2.0f);
	leg1->Draw(modelID,vpID,V, P);

	leg2->CubeSixFacesModelMatrix=  glm::scale(0.4f, 1.0f, 0.5f)*glm::translate(-5.0f, -9.0f, 2.0f);
	leg2->Draw(modelID,vpID,V, P);

	leg3->CubeSixFacesModelMatrix=  glm::scale(0.4f, 1.0f, 0.5f)*glm::translate(5.0f, -9.0f,13.0f);
	leg3->Draw(modelID,vpID,V, P);

	leg4->CubeSixFacesModelMatrix=  glm::scale(0.4f, 1.0f, 0.5f)*glm::translate(-5.0f, -9.0f, 13.0f);
	leg4->Draw(modelID,vpID,V, P);

	table1->CubeSixFacesModelMatrix= glm::scale(0.4f,1.1f, 0.5f)* glm::scale(7.0f, 0.3f, 9.0f)*glm::translate(0.0f, -23.0f, 1.0f);
	table1->Draw(modelID,vpID,V, P);}

