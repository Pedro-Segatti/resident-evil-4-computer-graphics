#include "Scene1.h"

CScene1::CScene1()
{
	pCamera = NULL;
	pTexto = NULL;
	pTextures = NULL;

	bIsWireframe = false;
	bIsCameraFPS = true;

	iFPS = 0;
	iFrames = 0;
	ulLastFPS = 0;
	szTitle[256] = 0;

	// Cria gerenciador de impressão de texto na tela
	pTexto = new CTexto();

	// Cria camera
	pCamera = new CCamera(0.0f, 1.0f, 20.0f, 1.0f);

	// Cria o Timer
	pTimer = new CTimer();
	pTimer->Init();

	fTimerPosY = 0.0f;
	fRenderPosY = 0.0f;

	// Carrega todas as texturas
	pTextures = new CTexture();
	pTextures->CreateTextureClamp(0, "../Scene1/back.bmp");
	pTextures->CreateTextureClamp(1, "../Scene1/front.bmp");
	pTextures->CreateTextureClamp(2, "../Scene1/down.bmp");
	pTextures->CreateTextureClamp(3, "../Scene1/up.bmp");
	pTextures->CreateTextureClamp(4, "../Scene1/left.bmp");
	pTextures->CreateTextureClamp(5, "../Scene1/right.bmp");
	pTextures->CreateTextureTGA(6, "../Scene1/tree_6.tga");
	pTextures->CreateTextureMipMap(7, "../Scene1/Sphere.bmp");
	pTextures->CreateTextureMipMap(8, "../Scene1/carpa.jpg");
	pTextures->CreateTextureMipMap(9, "../Scene1/cardume.png");

	LightAmbient[0] = 1.0f;		LightAmbient[1] = 1.0f;		LightAmbient[2] = 1.0f;		LightAmbient[3] = 1.0f;
	LightDiffuse[0] = 1.0f;		LightDiffuse[1] = 0.74f;	LightDiffuse[2] = 0.0f;		LightDiffuse[3] = 1.0f;
	LightSpecular[0] = 1.0f;	LightSpecular[1] = 1.0f;	LightSpecular[2] = 1.0f;	LightSpecular[3] = 1.0f;
	LightPosition[0] = -58.0f;	LightPosition[1] = -4.0f;	LightPosition[2] = 84.5f;	LightPosition[3] = 1.0f;
	Light1Position[0] = -91.0f;	Light1Position[1] = -4.0f;	Light1Position[2] = 84.5f;	Light1Position[3] = 1.0f;
	Light2Position[0] = 20.0f;	Light2Position[1] = 20.0f;	Light2Position[2] = 0.0f;	Light2Position[3] = 1.0f;
	Light2Diffuse[0] = 1.0f;	Light2Diffuse[1] = 1.0f;	Light2Diffuse[2] = 1.0f;	Light2Diffuse[3] = 1.0f;
	LightDirection[0] = 0.0f;	LightDirection[1] = -1.0f;	LightDirection[2] = 0.0f;

	MatAmbient[0] = 0.1f;	MatAmbient[1] = 0.1f;	MatAmbient[2] = 0.1f;	MatAmbient[3] = 1.0f;
	MatDiffuse[0] = 1.0f;	MatDiffuse[1] = 1.0f;	MatDiffuse[2] = 1.0f;	MatDiffuse[3] = 1.0f;
	MatSpecular[0] = 0.5f;	MatSpecular[1] = 0.5f;	MatSpecular[2] = 0.5f;	MatSpecular[3] = 1.0f;
	MatShininess = 128.0f;

	borda = 10.0f;
	cutoff = 45.0f;

	// Criando a fonte de luz Point Light
	glLightfv(GL_LIGHT0, GL_AMBIENT, LightAmbient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, LightDiffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, LightSpecular);
	glLightfv(GL_LIGHT0, GL_POSITION, LightPosition);
	glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, cutoff);
	glLightf(GL_LIGHT0, GL_SPOT_EXPONENT, borda);
	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, LightDirection);

	glLightfv(GL_LIGHT1, GL_AMBIENT, LightAmbient);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, LightDiffuse);
	glLightfv(GL_LIGHT1, GL_SPECULAR, LightSpecular);
	glLightfv(GL_LIGHT1, GL_POSITION, Light1Position);
	glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, cutoff);
	glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, borda);
	glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, LightDirection);


	glLightfv(GL_LIGHT2, GL_AMBIENT, LightAmbient);
	glLightfv(GL_LIGHT2, GL_DIFFUSE, Light2Diffuse);
	glLightfv(GL_LIGHT2, GL_SPECULAR, LightSpecular);
	glLightfv(GL_LIGHT2, GL_POSITION, Light2Position);

	// Criando o Material dos objetos
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, MatAmbient);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, MatDiffuse);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, MatSpecular);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, MatShininess);

	fLightSpeed = 0.5f;


	pCena1 = NULL;
	pCena1 = new CModel_3DS();
	pCena1->Load("../Scene1/Cenario.3ds");

	pPedra = NULL;
	pPedra = new CModel_3DS();
	pPedra->Load("../Scene1/esfera_de_pedra.3ds");

	pArvore = NULL;
	pArvore = new CModel_3DS();
	pArvore->Load("../Scene1/tree.3ds");

	pArvore2 = NULL;
	pArvore2 = new CModel_3DS();
	pArvore2->Load("../Scene1/tree_2.3ds");

	pArvore3 = NULL;
	pArvore3 = new CModel_3DS();
	pArvore3->Load("../Scene1/tree_3.3ds");

	pArvore4 = NULL;
	pArvore4 = new CModel_3DS();
	pArvore4->Load("../Scene1/tree_4.3ds");

	pArvore5 = NULL;
	pArvore5 = new CModel_3DS();
	pArvore5->Load("../Scene1/tree_5.3ds");

	FogColor[0] = 0.8f; FogColor[1] = 0.78f; FogColor[2] = 0.62f; FogColor[3] = 1.0f;


	pTextures->CreateTextureMipMap(11, "../Scene1/SphereMap.bmp");

	// CubeMaps
	texturesCubeMap[0] = "../Scene1/cm_right.bmp";
	texturesCubeMap[1] = "../Scene1/cm_left.bmp";
	texturesCubeMap[2] = "../Scene1/cm_up.bmp";
	texturesCubeMap[3] = "../Scene1/cm_down.bmp";
	texturesCubeMap[4] = "../Scene1/cm_front.bmp";
	texturesCubeMap[5] = "../Scene1/cm_back.bmp";
	pTextures->CreateTextureCubeMap(texturesCubeMap);

	glMultiTexCoord2fARB = (PFNGLMULTITEXCOORD2FARBPROC) wglGetProcAddress("glMultiTexCoord2fARB");
	glActiveTextureARB = (PFNGLACTIVETEXTUREARBPROC) wglGetProcAddress("glActiveTextureARB");
	glClientActiveTextureARB = (PFNGLCLIENTACTIVETEXTUREARBPROC) wglGetProcAddress("glClientActiveTextureARB");

}

CScene1::~CScene1(void)
{
	if (pTexto)
	{
		delete pTexto;
		pTexto = NULL;
	}

	if (pTextures)
	{
		delete pTextures;
		pTextures = NULL;
	}

	if (pCamera)
	{
		delete pCamera;
		pCamera = NULL;
	}

	if (pTimer)
	{
		delete pTimer;
		pTimer = NULL;
	}

	if (pCena1)
	{
		delete pCena1;
		pCena1 = NULL;
	}
}




int CScene1::DrawGLScene(void)	// Função que desenha a cena
{
	// Get FPS
	if (GetTickCount() - ulLastFPS >= 1000)	// When A Second Has Passed...
	{
		ulLastFPS = GetTickCount();				// Update Our Time Variable
		iFPS = iFrames;							// Save The FPS
		iFrames = 0;							// Reset The FPS Counter
	}
	iFrames++;									// FPS counter

	pTimer->Update();							// Atualiza o timer

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limpa a tela e o Depth Buffer
	glLoadIdentity();									// Inicializa a Modelview Matrix Atual


	// Seta as posições da câmera
	pCamera->setView();

	glEnable(GL_LIGHTING);

	glLightfv(GL_LIGHT0, GL_POSITION, LightPosition);
	glLightfv(GL_LIGHT1, GL_POSITION, Light1Position);
	glLightfv(GL_LIGHT2, GL_POSITION, Light2Position);
	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, LightDirection);


	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	glEnable(GL_LIGHT2);
	
	DrawAxis();

	
	if (bIsWireframe)
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	else
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//                               DESENHA OS OBJETOS DA CENA (INÍCIO)
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);

	

	if (showFog) {
		glEnable(GL_FOG);
		glFogfv(GL_FOG_COLOR, FogColor);
		glFogf(GL_FOG_START, 1.0);
		glFogf(GL_FOG_END, 300.0);
		glFogi(GL_FOG_MODE, GL_LINEAR);
	}
	

	glEnable(GL_TEXTURE_2D);

	glEnable(GL_NORMALIZE);
	pTextures->BeginSphereMapping(7);

	glPushMatrix();
	glTranslatef(Light2Position[0], Light2Position[1], Light2Position[2]);
	//glutSolidSphere(0.5, 10, 10);
	auxSolidSphere(2.0);
	glPopMatrix();

	pTextures->EndSphereMapping();
	glDisable(GL_NORMALIZE);
	
	// Desenha o SkyBox
	CreateSkyBox(0.0f, 100.0f, 0.0f,
		1000.0f, 1000.0f, 1000.0f,
		pTextures);

	

	glPushMatrix();
	glTranslatef(0.0f, -20.0f, 0.0f);
	pCena1->Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-50, -10 ,-95);
	glScalef(0.3,0.3,0.3);
	pPedra->Draw();
	glPopMatrix();


	DrawTree(pArvore, 80.0f, 0.0f, -30.0f, 0.2f, 0.2f, 0.2f);
	DrawTree(pArvore2, -20.0f, 0.0f, -50.0f, 0.1f, 0.1f, 0.1f);
	DrawTree(pArvore3, -5.0f, -3.0f, -23.0f, 0.1f, 0.1f, 0.1f);
	DrawTree(pArvore4, -40.0f, 0.0f, 1.0f, 0.1f, 0.1f, 0.1f);
	DrawTree(pArvore5, -20.0f, -4.0f, 1.0f, 0.1f, 0.1f, 0.1f);
	DrawTree(NULL, 40.0f, -5.0f, 1.0f, 1.0f, 1.0f, 1.0f);

	DrawTree(pArvore, 100.0f, 0.0f, -60.0f, 0.2f, 0.2f, 0.2f);
	DrawTree(pArvore2, -20.0f, 0.0f, -80.0f, 0.1f, 0.1f, 0.1f);
	DrawTree(pArvore3, -10.0f, -5.0f, -50.0f, 0.1f, 0.1f, 0.1f);
	DrawTree(pArvore4, -80.0f, 0.0f, 10.0f, 0.1f, 0.1f, 0.1f);
	DrawTree(pArvore5, -40.0f, -8.0f, 10.0f, 0.1f, 0.1f, 0.1f);

	DrawTree(pArvore, 20.0f, 0.0f, -40.0f, 0.15f, 0.15f, 0.15f);
	DrawTree(pArvore2, 60.0f, 0.0f, -20.0f, 0.2f, 0.2f, 0.2f);
	DrawTree(pArvore3, -20.0f, 0.0f, 40.0f, 0.1f, 0.1f, 0.1f);
	DrawTree(pArvore4, -70.0f, 0.0f, 20.0f, 0.15f, 0.15f, 0.15f);
	DrawTree(pArvore5, 20.0f, 0.0f, 90.0f, 0.1f, 0.1f, 0.1f);

	DrawTree(pArvore, 90.0f, 0.0f, 20.0f, 0.2f, 0.2f, 0.2f);
	DrawTree(pArvore2, 50.0f, 0.0f, 60.0f, 0.2f, 0.2f, 0.2f);
	DrawTree(pArvore3, -70.0f, 0.0f, -30.0f, 0.15f, 0.15f, 0.15f);
	DrawTree(pArvore4, 10.0f, 0.0f, -70.0f, 0.1f, 0.1f, 0.1f);
	DrawTree(pArvore5, -30.0f, 0.0f, 10.0f, 0.15f, 0.15f, 0.15f);
	
	DrawTree(pArvore, 40.0f, 0.0f, 30.0f, 0.2f, 0.2f, 0.2f);
	DrawTree(pArvore2, -60.0f, 0.0f, 60.0f, 0.1f, 0.1f, 0.1f);
	DrawTree(pArvore3, 20.0f, 0.0f, -20.0f, 0.15f, 0.15f, 0.15f);
	DrawTree(pArvore4, -10.0f, 0.0f, 40.0f, 0.2f, 0.2f, 0.2f);
	DrawTree(pArvore5, 50.0f, 0.0f, -10.0f, 0.1f, 0.1f, 0.1f);

	DrawTree(pArvore, -20.0f, 0.0f, -50.0f, 0.15f, 0.15f, 0.15f);
	DrawTree(pArvore2, 80.0f, 0.0f, -40.0f, 0.2f, 0.2f, 0.2f);
	DrawTree(pArvore3, -40.0f, 0.0f, 60.0f, 0.1f, 0.1f, 0.1f);
	DrawTree(pArvore4, 30.0f, 0.0f, -10.0f, 0.15f, 0.15f, 0.15f);
	DrawTree(pArvore5, 70.0f, 0.0f, 10.0f, 0.2f, 0.2f, 0.2f);

	DrawTree(pArvore, -30.0f, 0.0f, 40.0f, 0.2f, 0.2f, 0.2f);
	DrawTree(pArvore2, 10.0f, 0.0f, -30.0f, 0.15f, 0.15f, 0.15f);
	DrawTree(pArvore3, 50.0f, 0.0f, 20.0f, 0.1f, 0.1f, 0.1f);
	DrawTree(pArvore4, -60.0f, 0.0f, -20.0f, 0.15f, 0.15f, 0.15f);
	DrawTree(pArvore5, -10.0f, 0.0f, 50.0f, 0.2f, 0.2f, 0.2f);

	DrawTree(pArvore, 60.0f, 0.0f, -10.0f, 0.18f, 0.18f, 0.18f);
	DrawTree(pArvore2, -20.0f, -7.0f, 95.0f, 0.12f, 0.12f, 0.12f);
	DrawTree(pArvore3, 10.0f, 0.0f, -60.0f, 0.1f, 0.1f, 0.1f);
	DrawTree(pArvore4, -90.0f, 0.0f, 20.0f, 0.16f, 0.16f, 0.16f);
	DrawTree(pArvore5, -40.0f, 0.0f, 20.0f, 0.18f, 0.18f, 0.18f);

	DrawTree(pArvore, -50.0f, 0.0f, -10.0f, 0.2f, 0.2f, 0.2f);
	DrawTree(pArvore2, 40.0f, 0.0f, 60.0f, 0.14f, 0.14f, 0.14f);
	DrawTree(pArvore3, 0.0f, 0.0f, -70.0f, 0.12f, 0.12f, 0.12f);
	DrawTree(pArvore4, -80.0f, 0.0f, 10.0f, 0.16f, 0.16f, 0.16f);

	glTranslatef(40.0f, -0.8f, -50.0f);
	glScalef(1.3f, 1.3f, 1.3f);

	float prismWidth = 2.5f;
	float prismDepth = 2.5f;
	float prismHeight = 8.0f;
	float tetrahedronBaseSize = 2.5f;
	float tetrahedronHeight = 4.0f;
	float baseWidth = 10.0f;
	float baseDepth = 10.0f;
	float baseHeight = 0.1f;
	float wallThickness = 0.5f;
	float wallHeight = 2.0f;

	glPushMatrix();
	// TOTEN
	pTextures->BeginSphereMapping(7);
	// Mover para cima da base da fonte de água
	glBegin(GL_QUADS);
	glVertex3f(-prismWidth / 2, 0, prismDepth / 2);
	glVertex3f(prismWidth / 2, 0, prismDepth / 2);
	glVertex3f(prismWidth / 2, prismHeight, prismDepth / 2);
	glVertex3f(-prismWidth / 2, prismHeight, prismDepth / 2);
	glVertex3f(-prismWidth / 2, 0, -prismDepth / 2);
	glVertex3f(prismWidth / 2, 0, -prismDepth / 2);
	glVertex3f(prismWidth / 2, prismHeight, -prismDepth / 2);
	glVertex3f(-prismWidth / 2, prismHeight, -prismDepth / 2);
	glVertex3f(prismWidth / 2, 0, prismDepth / 2);
	glVertex3f(prismWidth / 2, 0, -prismDepth / 2);
	glVertex3f(prismWidth / 2, prismHeight, -prismDepth / 2);
	glVertex3f(prismWidth / 2, prismHeight, prismDepth / 2);
	glVertex3f(-prismWidth / 2, 0, prismDepth / 2);
	glVertex3f(-prismWidth / 2, 0, -prismDepth / 2);
	glVertex3f(-prismWidth / 2, prismHeight, -prismDepth / 2);
	glVertex3f(-prismWidth / 2, prismHeight, prismDepth / 2);
	glVertex3f(-prismWidth / 2, prismHeight, prismDepth / 2);
	glVertex3f(prismWidth / 2, prismHeight, prismDepth / 2);
	glVertex3f(prismWidth / 2, prismHeight, -prismDepth / 2);
	glVertex3f(-prismWidth / 2, prismHeight, -prismDepth / 2);
	glVertex3f(-prismWidth / 2, 0, prismDepth / 2);
	glVertex3f(prismWidth / 2, 0, prismDepth / 2);
	glVertex3f(prismWidth / 2, 0, -prismDepth / 2);
	glVertex3f(-prismWidth / 2, 0, -prismDepth / 2);
	glEnd();

	// Ponta do Toten
	glTranslatef(0.0f, prismHeight, 0.0f);  // Mover para o topo do prisma
	glBegin(GL_TRIANGLES);
	glVertex3f(0, tetrahedronHeight, 0);
	glVertex3f(-tetrahedronBaseSize / 2, 0, tetrahedronBaseSize / 2);
	glVertex3f(tetrahedronBaseSize / 2, 0, tetrahedronBaseSize / 2);
	glVertex3f(0, tetrahedronHeight, 0);
	glVertex3f(tetrahedronBaseSize / 2, 0, tetrahedronBaseSize / 2);
	glVertex3f(tetrahedronBaseSize / 2, 0, -tetrahedronBaseSize / 2);
	glVertex3f(0, tetrahedronHeight, 0);
	glVertex3f(tetrahedronBaseSize / 2, 0, -tetrahedronBaseSize / 2);
	glVertex3f(-tetrahedronBaseSize / 2, 0, -tetrahedronBaseSize / 2);
	glVertex3f(0, tetrahedronHeight, 0);
	glVertex3f(-tetrahedronBaseSize / 2, 0, -tetrahedronBaseSize / 2);
	glVertex3f(-tetrahedronBaseSize / 2, 0, tetrahedronBaseSize / 2);

	glEnd();
	pTextures->EndSphereMapping();
	glPopMatrix();

	glPushMatrix();
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
	
	//Multi textura
	glPushAttrib(GL_TEXTURE_BIT);
	
	glActiveTextureARB(GL_TEXTURE0_ARB);
	glEnable(GL_TEXTURE_2D);
	pTextures->ApplyTexture(8);
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
	
	glActiveTextureARB(GL_TEXTURE1_ARB);
	glEnable(GL_TEXTURE_2D);
	pTextures->ApplyTexture(9);
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

	// Desenhar a base da fonte de água (prisma retangular baixo)
	glBegin(GL_QUADS);

	glMultiTexCoord2fARB(GL_TEXTURE0_ARB, 0.0f, 0.0f); 
	glMultiTexCoord2fARB(GL_TEXTURE1_ARB, 0.0f, 0.0f);
	glVertex3f(-baseWidth / 2, baseHeight, baseDepth / 2);

	glMultiTexCoord2fARB(GL_TEXTURE0_ARB, 1.0f, 0.0f);
	glMultiTexCoord2fARB(GL_TEXTURE1_ARB, 1.0f, 0.0f);
	glVertex3f(baseWidth / 2, baseHeight, baseDepth / 2);

	glMultiTexCoord2fARB(GL_TEXTURE0_ARB, 1.0f, 1.0f); 
	glMultiTexCoord2fARB(GL_TEXTURE1_ARB, 1.0f, 1.0f);
	glVertex3f(baseWidth / 2, baseHeight, -baseDepth / 2);

	glMultiTexCoord2fARB(GL_TEXTURE0_ARB, 0.0f, 1.0f);
	glMultiTexCoord2fARB(GL_TEXTURE1_ARB, 0.0f, 1.0f);
	glVertex3f(-baseWidth / 2, baseHeight, -baseDepth / 2);
	glEnd();
	glActiveTextureARB(GL_TEXTURE1_ARB);
	glDisable(GL_TEXTURE_2D);
	glActiveTextureARB(GL_TEXTURE0_ARB);
	glDisable(GL_TEXTURE_2D);

	glPopAttrib();
	glPopMatrix();


	glDisable(GL_LIGHT0);
	glDisable(GL_LIGHT1);
	glDisable(GL_LIGHT2);
	glDisable(GL_LIGHTING);

	glDisable(GL_TEXTURE_2D);
	if (showFog) {
		glDisable(GL_FOG);
	}

	DrawTransparentWater();

	// Desenhar o murinho ao redor da base da fonte de água
	glColor3f(0.5f, 0.3f, 0.2f);
	glBegin(GL_QUADS);
	// Frente externa
	glVertex3f(-baseWidth / 2 - wallThickness, 0, baseDepth / 2 + wallThickness);
	glVertex3f(baseWidth / 2 + wallThickness, 0, baseDepth / 2 + wallThickness);
	glVertex3f(baseWidth / 2 + wallThickness, wallHeight, baseDepth / 2 + wallThickness);
	glVertex3f(-baseWidth / 2 - wallThickness, wallHeight, baseDepth / 2 + wallThickness);
	// Trás externa
	glVertex3f(-baseWidth / 2 - wallThickness, 0, -baseDepth / 2 - wallThickness);
	glVertex3f(baseWidth / 2 + wallThickness, 0, -baseDepth / 2 - wallThickness);
	glVertex3f(baseWidth / 2 + wallThickness, wallHeight, -baseDepth / 2 - wallThickness);
	glVertex3f(-baseWidth / 2 - wallThickness, wallHeight, -baseDepth / 2 - wallThickness);
	// Direita externa
	glVertex3f(baseWidth / 2 + wallThickness, 0, baseDepth / 2 + wallThickness);
	glVertex3f(baseWidth / 2 + wallThickness, 0, -baseDepth / 2 - wallThickness);
	glVertex3f(baseWidth / 2 + wallThickness, wallHeight, -baseDepth / 2 - wallThickness);
	glVertex3f(baseWidth / 2 + wallThickness, wallHeight, baseDepth / 2 + wallThickness);
	// Esquerda externa
	glVertex3f(-baseWidth / 2 - wallThickness, 0, baseDepth / 2 + wallThickness);
	glVertex3f(-baseWidth / 2 - wallThickness, 0, -baseDepth / 2 - wallThickness);
	glVertex3f(-baseWidth / 2 - wallThickness, wallHeight, -baseDepth / 2 - wallThickness);
	glVertex3f(-baseWidth / 2 - wallThickness, wallHeight, baseDepth / 2 + wallThickness);
	// Frente interna
	glVertex3f(-baseWidth / 2, baseHeight, baseDepth / 2);
	glVertex3f(baseWidth / 2, baseHeight, baseDepth / 2);
	glVertex3f(baseWidth / 2, wallHeight, baseDepth / 2);
	glVertex3f(-baseWidth / 2, wallHeight, baseDepth / 2);
	// Trás interna
	glVertex3f(-baseWidth / 2, baseHeight, -baseDepth / 2);
	glVertex3f(baseWidth / 2, baseHeight, -baseDepth / 2);
	glVertex3f(baseWidth / 2, wallHeight, -baseDepth / 2);
	glVertex3f(-baseWidth / 2, wallHeight, -baseDepth / 2);
	// Direita interna
	glVertex3f(baseWidth / 2, baseHeight, baseDepth / 2);
	glVertex3f(baseWidth / 2, baseHeight, -baseDepth / 2);
	glVertex3f(baseWidth / 2, wallHeight, -baseDepth / 2);
	glVertex3f(baseWidth / 2, wallHeight, baseDepth / 2);
	// Esquerda interna
	glVertex3f(-baseWidth / 2, baseHeight, baseDepth / 2);
	glVertex3f(-baseWidth / 2, baseHeight, -baseDepth / 2);
	glVertex3f(-baseWidth / 2, wallHeight, -baseDepth / 2);
	glVertex3f(-baseWidth / 2, wallHeight, baseDepth / 2);
	glVertex3f(-baseWidth / 2 - wallThickness, wallHeight, baseDepth / 2 + wallThickness);
	glVertex3f(baseWidth / 2 + wallThickness, wallHeight, baseDepth / 2 + wallThickness);
	glVertex3f(baseWidth / 2, wallHeight, baseDepth / 2);
	glVertex3f(-baseWidth / 2, wallHeight, baseDepth / 2);
	// Trás
	glVertex3f(-baseWidth / 2 - wallThickness, wallHeight, -baseDepth / 2 - wallThickness);
	glVertex3f(baseWidth / 2 + wallThickness, wallHeight, -baseDepth / 2 - wallThickness);
	glVertex3f(baseWidth / 2, wallHeight, -baseDepth / 2);
	glVertex3f(-baseWidth / 2, wallHeight, -baseDepth / 2);
	// Direita
	glVertex3f(baseWidth / 2 + wallThickness, wallHeight, baseDepth / 2 + wallThickness);
	glVertex3f(baseWidth / 2 + wallThickness, wallHeight, -baseDepth / 2 - wallThickness);
	glVertex3f(baseWidth / 2, wallHeight, -baseDepth / 2);
	glVertex3f(baseWidth / 2, wallHeight, baseDepth / 2);
	// Esquerda
	glVertex3f(-baseWidth / 2 - wallThickness, wallHeight, baseDepth / 2 + wallThickness);
	glVertex3f(-baseWidth / 2 - wallThickness, wallHeight, -baseDepth / 2 - wallThickness);
	glVertex3f(-baseWidth / 2, wallHeight, -baseDepth / 2);
	glVertex3f(-baseWidth / 2, wallHeight, baseDepth / 2);
	glEnd();
	glColor3f(1.0f, 0.0f, 0.0f);

	
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//                               DESENHA OS OBJETOS DA CENA (FIM)
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	fTimerPosY = pTimer->GetTime() / 1000.0f;
	fRenderPosY += 0.2f;

	// Impressão de texto na tela...
	// Muda para modo de projeção ortogonal 2D
	// OBS: Desabilite Texturas e Iluminação antes de entrar nesse modo de projeção
	OrthoMode(0, 0, WIDTH, HEIGHT);


	glPushMatrix();
	glTranslatef(0.0f, HEIGHT - 100, 0.0f);	// Move 1 unidade para dentro da tela (eixo Z)

	// Cor da fonte
	glColor3f(1.0f, 1.0f, 0.0f);


	glRasterPos2f(10.0f, 0.0f);	// Posicionando o texto na tela
	if (!bIsWireframe) {
		pTexto->glPrint("[TAB]  Modo LINE"); // Imprime texto na tela
	}
	else {
		pTexto->glPrint("[TAB]  Modo FILL");
	}


	//// Camera LookAt
	glRasterPos2f(10.0f, 40.0f);
	pTexto->glPrint("Player LookAt  : %f, %f, %f", pCamera->Forward[0], pCamera->Forward[1], pCamera->Forward[2]);

	//// Posição do Player
	glRasterPos2f(10.0f, 60.0f);
	pTexto->glPrint("Player Position: %f, %f, %f", pCamera->Position[0], pCamera->Position[1], pCamera->Position[2]);

	//// Imprime o FPS da aplicação e o Timer
	glRasterPos2f(10.0f, 80.0f);
	pTexto->glPrint("Frames-per-Second: %d ---- Timer: %.1f segundos", iFPS, (pTimer->GetTime() / 1000));


	glPopMatrix();

	// Muda para modo de projeção perspectiva 3D
	PerspectiveMode();

	return true;
}

void CScene1::DrawTree(CModel_3DS* tree, float posX, float posY, float posZ, float scaleX, float scaleY, float scaleZ)
{
	if (tree == NULL) {
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glEnable(GL_ALPHA_TEST);
		glAlphaFunc(GL_GREATER, 0.95f);

		pTextures->ApplyTexture(6);
		glPushMatrix();
		glTranslatef(posX, posY, posZ);
		glScalef(scaleX, scaleY, scaleZ);
		glBegin(GL_QUADS);
		glNormal3f(0.0f, 0.0f, 1.0f);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-5.0, 0.0, 0.0);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(5.0, 0.0, 0.0);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(5.0, 10.0, 0.0);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-5.0, 10.0, 0.0);

		glTexCoord2f(0.0f, 0.0f); glVertex3f(0.0, 0.0, 5.0);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(0.0, 0.0, -5.0);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(0.0, 10.0, -5.0);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(0.0, 10.0, 5.0);
		glEnd();
		glPopMatrix();

		glDisable(GL_ALPHA_TEST);
		glDisable(GL_BLEND);
	}
	else {
		glPushMatrix();
		glTranslatef(posX, posY, posZ);
		glScalef(scaleX, scaleY, scaleZ);
		tree->Draw();
		glPopMatrix();
	}
}

void CScene1::DrawTransparentWater()
{	
	float baseWidth = 10.0f;
	float baseDepth = 10.0f;
	float baseHeight = 0.3f;

	
	glDisable(GL_TEXTURE_2D);


	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	
	glColor4f(0.0f, 0.0f, 1.0f, 0.3f);

	glPushMatrix();
	glTranslatef(0.0f, 1.0f, 0.0f);
	
	glBegin(GL_QUADS);

	glNormal3f(0.0f, 0.0f, -1.0f);
	glVertex3f(-baseWidth / 2, baseHeight, baseDepth / 2);
	glVertex3f(baseWidth / 2, baseHeight, baseDepth / 2);
	glVertex3f(baseWidth / 2, baseHeight, -baseDepth / 2);
	glVertex3f(-baseWidth / 2, baseHeight, -baseDepth / 2);

	glEnd();
	glPopMatrix();
	glDisable(GL_BLEND);
}


void CScene1::MouseMove(void) // Tratamento de movimento do mouse
{
	// Realiza os cálculos de rotação da visão do Player (através das coordenadas
	// X do mouse.
	POINT mousePos;
	int middleX = WIDTH >> 1;
	int middleY = HEIGHT >> 1;

	GetCursorPos(&mousePos);

	if ((mousePos.x == middleX) && (mousePos.y == middleY)) return;

	SetCursorPos(middleX, middleY);

	fDeltaX = (float)((middleX - mousePos.x)) / 10;
	fDeltaY = (float)((middleY - mousePos.y)) / 10;

	// Rotaciona apenas a câmera
	pCamera->rotateGlob(-fDeltaX, 0.0f, 1.0f, 0.0f);
	pCamera->rotateLoc(-fDeltaY, 1.0f, 0.0f, 0.0f);
}

void CScene1::KeyPressed(void) // Tratamento de teclas pressionadas
{

	// Verifica se a tecla 'W' foi pressionada e move o Player para frente
	if (GetKeyState('W') & 0x80)
	{
		pCamera->moveGlob(pCamera->Forward[0], pCamera->Forward[1], pCamera->Forward[2]);
	}
	// Verifica se a tecla 'S' foi pressionada e move o Player para tras
	else if (GetKeyState('S') & 0x80)
	{
		pCamera->moveGlob(-pCamera->Forward[0], -pCamera->Forward[1], -pCamera->Forward[2]);
	}
	// Verifica se a tecla 'A' foi pressionada e move o Player para esquerda
	else if (GetKeyState('A') & 0x80)
	{
		pCamera->moveGlob(-pCamera->Right[0], -pCamera->Right[1], -pCamera->Right[2]);
	}
	// Verifica se a tecla 'D' foi pressionada e move o Player para direira
	else if (GetKeyState('D') & 0x80)
	{
		pCamera->moveGlob(pCamera->Right[0], pCamera->Right[1], pCamera->Right[2]);
	}
	else if (GetKeyState('Q') & 0x80)
	{
		pCamera->moveGlob(0.0f, -pCamera->Up[1], 0.0f);
	}
	else if (GetKeyState('E') & 0x80)
	{
		pCamera->moveGlob(0.0f, pCamera->Up[1], 0.0f);
	}
	// Senão, interrompe movimento do Player
	else
	{
	}

	if (GetKeyState(VK_UP) & 0x80)
	{

		Light2Position[2] -= fLightSpeed;
	}
	if (GetKeyState(VK_DOWN) & 0x80)
	{
		Light2Position[2] += fLightSpeed;
	}
	if (GetKeyState(VK_LEFT) & 0x80)
	{
		Light2Position[0] -= fLightSpeed;
	}
	if (GetKeyState(VK_RIGHT) & 0x80)
	{
		Light2Position[0] += fLightSpeed;
	}
	if (GetKeyState(VK_PRIOR) & 0x80)
	{
		Light2Position[1] += fLightSpeed;
	}
	if (GetKeyState(VK_NEXT) & 0x80)
	{
		Light2Position[1] -= fLightSpeed;
	}

}

void CScene1::KeyDownPressed(WPARAM	wParam) // Tratamento de teclas pressionadas
{
	switch (wParam)
	{
	case VK_TAB:
		bIsWireframe = !bIsWireframe;
		break;

	case VK_SPACE:
		pTimer->Init();
		break;

	case VK_RETURN:
		break;

	case 'F':
		showFog = !showFog;
		break;
	}

}

//	Cria um grid horizontal ao longo dos eixos X e Z
void CScene1::Draw3DSGrid(float width, float length)
{

	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glColor3f(0.0f, 0.3f, 0.0f);
	glPushMatrix();
	for (float i = -width; i <= length; i += 1)
	{
		for (float j = -width; j <= length; j += 1)
		{
			// inicia o desenho das linhas
			glBegin(GL_QUADS);
			glNormal3f(0.0f, 1.0f, 0.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(i, 0.0f, j + 1);
			glTexCoord2f(1.0f, 0.0f); glVertex3f(i + 1, 0.0f, j + 1);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(i + 1, 0.0f, j);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(i, 0.0f, j);
			glEnd();
		}
	}
	glPopMatrix();
	//glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}



void CScene1::DrawAxis()
{
	glPushMatrix();
	glTranslatef(0.0f, 0.0f, 0.0f);
	glBegin(GL_LINES);
	// Eixo X
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-1000.0f, 0.0f, 0.0f);
	glVertex3f(1000.0f, 0.0f, 0.0f);

	// Eixo Y
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(0.0f, 1000.0f, 0.0f);
	glVertex3f(0.0f, -1000.0f, 0.0f);

	// Eixo Z
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(0.0f, 0.0f, 1000.0f);
	glVertex3f(0.0f, 0.0f, -1000.0f);
	glEnd();
	glPopMatrix();
}

void CScene1::CreateSkyBox(float x, float y, float z,
	float width, float height, float length,
	CTexture* pTextures)
{
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
	glPushMatrix();

	// Centraliza o Skybox em torno da posição especificada(x, y, z)
	x = x - width / 2;
	y = y - height / 2;
	z = z - length / 2;


	// Aplica a textura que representa a parte da frente do skybox (BACK map)
	pTextures->ApplyTexture(0);

	// Desenha face BACK do cubo do skybox
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x, y, z);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x + width, y, z);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x + width, y + height, z);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x, y + height, z);
	glEnd();


	// Aplica a textura que representa a parte da frente do skybox (FRONT map)
	pTextures->ApplyTexture(1);

	// Desenha face FRONT do cubo do skybox
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x, y, z + length);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x, y + height, z + length);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x + width, y + height, z + length);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x + width, y, z + length);
	glEnd();


	// Aplica a textura que representa a parte da frente do skybox (DOWN map)
	pTextures->ApplyTexture(2);

	// Desenha face BOTTOM do cubo do skybox
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x, y, z);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x, y, z + length);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x + width, y, z + length);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x + width, y, z);
	glEnd();


	// Aplica a textura que representa a parte da frente do skybox (UP map)
	pTextures->ApplyTexture(3);

	// Desenha face TOP do cubo do skybox
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x, y + height, z);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x + width, y + height, z);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x + width, y + height, z + length);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x, y + height, z + length);
	glEnd();


	// Aplica a textura que representa a parte da frente do skybox (LEFT map)
	pTextures->ApplyTexture(4);

	// Desenha face LEFT do cubo do skybox
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x, y, z);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x, y + height, z);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x, y + height, z + length);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x, y, z + length);
	glEnd();


	// Aplica a textura que representa a parte da frente do skybox (RIGHT map)
	pTextures->ApplyTexture(5);

	// Desenha face RIGHT do cubo do skybox
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x + width, y, z);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x + width, y, z + length);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x + width, y + height, z + length);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x + width, y + height, z);
	glEnd();

	glPopMatrix();
}