#pragma once
#include "SceneBaseClass.h"
#include "CTexture.h"
#include "CTimer.h"
#include "CTexto.h"
#include "CCamera.h"
#include <glm/glm.hpp>
#include "CModel_3DS.h"


class CScene1 : public CSceneBaseClass
{
public:
	CScene1();
	~CScene1(void);


	virtual void MouseMove(void);					// Tratamento de movimento do mouse
	virtual void KeyPressed(void);					// Tratamento de teclas pressionadas
	virtual void KeyDownPressed(WPARAM	wParam);	// Tratamento de teclas pressionadas
	virtual int DrawGLScene(void);					// Função que desenha a cena
	virtual void DrawTree(CModel_3DS* tree, float posX, float posY, float posZ, float scaleX, float scaleY, float scaleZ);
	virtual void DrawTransparentWater();
	virtual void DrawFenceVertexArrays(float x, float y, float z);


	void CreateSkyBox(float x, float y, float z,
		float width, float height, float length,
		CTexture* pTextures);

	void Draw3DSGrid(float width, float length);
	void DrawAxis();
	glm::vec3 CalculateTriangleNormalVector(glm::vec3 P1, glm::vec3 P2, glm::vec3 P3);

private:

	bool	keys[256];		// Array usado para rotinas do teclado
	bool	active;			// Window Active Flag Set To TRUE By Default
	bool	fullscreen;		// Exibir janela em modo fullscreem (TRUE) ou em janela (FALSE)
	bool	showFog = true;

	CCamera* pCamera;	// Gerencia câmera OpenGL
	float fDeltaY;				// Rotação da câmera OpenGL no eixo Y
	float fDeltaX;				// Rotação da câmera OpenGL no eixo X

	CTexto* pTexto;	// Objeto que gerencia texto
	CTexture* pTextures;	// Objeto que gerencia texturas
	CTimer* pTimer;	// Objeto que gerencia o timer


	int		iFPS;			// FPS and FPS Counter
	int		iFrames;		// FPS and FPS Counter
	DWORD	ulLastFPS;		// FPS and FPS Counter
	char	szTitle[256];	// FPS and FPS Counter


	bool bIsWireframe;	// Modos Wireframe/Solid
	bool bIsCameraFPS;	// Ativa modo de camera First Person Shooter (true) ou Third Person Shooter (false)

	float fRenderPosY;
	float fTimerPosY;



	// Definindo as propriedades da fonte de luz
	GLfloat LightAmbient[4];
	GLfloat LightDiffuse[4];
	GLfloat Light2Diffuse[4];
	GLfloat LightSpecular[4];
	GLfloat LightPosition[4];
	GLfloat Light1Position[4];
	GLfloat Light2Position[4];
	GLfloat LightDirection[3];
	float fLightSpeed;

	float cutoff;
	float cosborda;
	float borda;

	// Definindo as propriedades do material
	GLfloat MatAmbient[4];
	GLfloat MatDiffuse[4];
	GLfloat MatSpecular[4];
	GLfloat MatShininess;


	CModel_3DS* pCena1;
	CModel_3DS* pPedra;
	CModel_3DS* pArvore;
	CModel_3DS* pArvore2;
	CModel_3DS* pArvore3;
	CModel_3DS* pArvore4;
	CModel_3DS* pArvore5;

	GLfloat FogColor[4];

	LPSTR texturesCubeMap[6];
	GLuint textureArray[2];

	PFNGLMULTITEXCOORD2FARBPROC glMultiTexCoord2fARB = NULL;
	PFNGLACTIVETEXTUREARBPROC   glActiveTextureARB = NULL;
	PFNGLCLIENTACTIVETEXTUREARBPROC glClientActiveTextureARB = NULL;

	float vfFenceVerts[164] =
	{
		// Frente
		-10.48, 7.46, 5.48,  // Top Left
		10.48, 7.46, 5.48,   // Top Right
		10.48, 0.00, 5.48,   // Bottom Right

		10.48, 0.00, 5.48,   // Bottom Right
		-10.48, 0.00, 5.48,  // Bottom Left
		-10.48, 7.46, 5.48,  // Top Left

		// Verso
		-10.48, 7.46, 4.48,  // Top Left
		10.48, 7.46, 4.48,   // Top Right
		10.48, 0.00, 4.48,   // Bottom Right

		10.48, 0.00, 4.48,   // Bottom Right
		-10.48, 0.00, 4.48,  // Bottom Left
		-10.48, 7.46, 4.48,  // Top Left

		// Topo
		-10.48, 7.46, 5.48,  // Front Top Left
		10.48, 7.46, 5.48,   // Front Top Right
		10.48, 7.46, 4.48,   // Back Top Right

		10.48, 7.46, 4.48,   // Back Top Right
		-10.48, 7.46, 4.48,  // Back Top Left
		-10.48, 7.46, 5.48,  // Front Top Left

		// Inferior
		-10.48, 0.00, 5.48,  // Front Bottom Left
		10.48, 0.00, 5.48,   // Front Bottom Right
		10.48, 0.00, 4.48,   // Back Bottom Right

		10.48, 0.00, 4.48,   // Back Bottom Right
		-10.48, 0.00, 4.48,  // Back Bottom Left
		-10.48, 0.00, 5.48   // Front Bottom Left
	};


	float vfFenceTexCoords[408] =
	{
		0.73, 0.58,
		0.30, 0.58,
		0.30, 0.44,

		0.30, 0.44,
		0.73, 0.44,
		0.73, 0.58,

		0.50, 0.22,
		0.34, 0.22,
		0.34, 0.11,

		0.34, 0.11,
		0.50, 0.11,
		0.50, 0.22,

		0.50, 0.22,
		0.50, 0.11,
		0.82, 0.11,

		0.82, 0.11,
		0.82, 0.22,
		0.50, 0.22,

		0.98, 0.22,
		0.82, 0.22,
		0.82, 0.11,
	};

	float vfFenceNormals[612] =
	{
		0, 1, 0,
		0, 1, 0,
		0, 1, 0,
		-0, 1, 0,
		-0, 1, 0,
		-0, 1, 0,
		1, 0, -0,
		1, 0, -0,
		1, 0, -0,
		1, 0, 0,
		1, 0, 0,
		1, 0, 0,
		0, -0, -1,
		0, -0, -1,
		0, -0, -1,
		0, 0, -1,
		0, 0, -1,
		0, 0, -1,
		-1, 0, -0,
		-1, 0, -0,
		-1, 0, -0,
		-1, 0, 0,
		-1, 0, 0,
		-1, 0, 0,
		0, 1, 0,
		0, 1, 0,
		0, 1, 0,
		0, 1, 0,
		0, 1, 0,
		0, 1, 0,
		-1, 0, -0,
		-1, 0, -0,
		-1, 0, -0,
		-1, 0, 0,
		-1, 0, 0,
		-1, 0, 0,
		0, -1, 0,
		0, -1, 0,
		0, -1, 0,
		0, -1, 0,
		0, -1, 0,
		0, -1, 0,
		1, 0, 0,
		1, 0, 0,
		1, 0, 0,
		1, 0, 0,
		1, 0, 0,
		1, 0, 0,
		0, -1, 0,
		0, -1, 0,
		0, -1, 0,
		-0, -1, 0,
		-0, -1, 0,
		-0, -1, 0,
		1, 0, 0,
		1, 0, 0,
		1, 0, 0,
		1, 0, 0,
		1, 0, 0,
		1, 0, 0,
		-0, 1, 0,
		-0, 1, 0,
		-0, 1, 0,
		0, 1, 0,
		0, 1, 0,
		0, 1, 0,
		-1, 0, 0,
		-1, 0, 0,
		-1, 0, 0,
		-1, 0, -0,
		-1, 0, -0,
		-1, 0, -0,
		0, 1, 0,
		0, 1, 0,
		0, 1, 0,
		0, 1, 0,
		0, 1, 0,
		0, 1, 0,
		-1, 0, -0,
		-1, 0, -0,
		-1, 0, -0,
		-1, 0, 0,
		-1, 0, 0,
		-1, 0, 0,
		0, -1, 0,
		0, -1, 0,
		0, -1, 0,
		0, -1, 0,
		0, -1, 0,
		0, -1, 0,
		1, 0, 0,
		1, 0, 0,
		1, 0, 0,
		1, 0, 0,
		1, 0, 0,
		1, 0, 0,
		0, 0, 1,
		0, 0, 1,
		0, 0, 1,
		0, 0, 1,
		0, 0, 1,
		0, 0, 1,
		0, 0, 1,
		0, 0, 1,
		0, 0, 1,
		0, 0, 1,
		0, 0, 1,
		0, 0, 1,
		0, -0, 1,
		0, -0, 1,
		0, -0, 1,
		0, 0, 1,
		0, 0, 1,
		0, 0, 1,
		0, -0, 1,
		0, -0, 1,
		0, -0, 1,
		0, 0, 1,
		0, 0, 1,
		0, 0, 1,
		0, 0, 1,
		0, 0, 1,
		0, 0, 1,
		0, 0, 1,
		0, 0, 1,
		0, 0, 1,
		0, -0, 1,
		0, -0, 1,
		0, -0, 1,
		0, -0, 1,
		0, -0, 1,
		0, -0, 1,
		0, -0, 1,
		0, -0, 1,
		0, -0, 1,
		0, 0, 1,
		0, 0, 1,
		0, 0, 1,
		0, 0, 1,
		0, 0, 1,
		0, 0, 1,
		0, 0, 1,
		0, 0, 1,
		0, 0, 1,
		0, -0, 1,
		0, -0, 1,
		0, -0, 1,
		0, -0, 1,
		0, -0, 1,
		0, -0, 1,
		0, 0, 1,
		0, 0, 1,
		0, 0, 1,
		0, 0, 1,
		0, 0, 1,
		0, 0, 1,
	};

};

