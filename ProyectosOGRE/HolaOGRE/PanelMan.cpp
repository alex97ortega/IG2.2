#include "PanelMan.h"
using namespace Ogre;
PanelMan::PanelMan(Ogre::SceneNode*n) 
{
	node = n;

	// Plano 
	MeshPtr plane = MeshManager::getSingleton().createPlane("mFondo",
		ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
		Plane(Vector3::UNIT_Y, -25),
		(Real)node->getCreator()->getCamera("Cam")->getViewport()->getActualWidth(),
		(Real)node->getCreator()->getCamera("Cam")->getViewport()->getActualHeight(),
		10, 10, true, 1, 1.0, 1.0, Vector3::UNIT_Z);

	//Textura reflejo
	TexturePtr rttTex = TextureManager::getSingleton().createManual(
		"texRtt",
		ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
		TEX_TYPE_2D,
		(Real)node->getCreator()->getCamera("Cam")->getViewport()->getActualWidth(),
		(Real)node->getCreator()->getCamera("Cam")->getViewport()->getActualHeight(),
		0, PF_R8G8B8, TU_RENDERTARGET);
	

	ent = n->getCreator()->createEntity("entFondo", "mFondo");
	node->attachObject(ent);
	ent->setQueryFlags(0);

	// material del plano (RustedMetal)
	/*ent->getSubEntity(0)->getMaterial()->
		getTechnique(0)->getPass(0) ->
		createTextureUnitState("RustedMetal.jpg");*/

	// material agua
	ent->getSubEntity(0)->setMaterialName("panel", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME); 
	
	// camref
	camRef = n->getCreator()->createCamera("RefCam");
	camRef->enableReflection(Plane(Vector3::UNIT_Y, 0));
	camRef->enableCustomNearClipPlane(Plane(Vector3::UNIT_Y, 0));
	camRef->setNearClipDistance(node->getCreator()->getCamera("Cam")->getNearClipDistance());
	camRef->setFarClipDistance(node->getCreator()->getCamera("Cam")->getFarClipDistance());
	camRef->setAutoAspectRatio(node->getCreator()->getCamera("Cam")->getAutoAspectRatio());
	node->getCreator()->getCamera("Cam")->getParentSceneNode()->attachObject(camRef);
	camRef->enableReflection(Plane(Vector3::UNIT_Y, -25));
	camRef->enableCustomNearClipPlane(Plane(Vector3::UNIT_Y, -25));
	camRef->setQueryFlags(0);

	// Añadimos un puerto de vista al RenderTarget con la nueva cámara
	RenderTexture* renderTexture = rttTex->getBuffer()->getRenderTarget();
	Viewport * v = renderTexture->addViewport(camRef);
	v->setClearEveryFrame(true);
	v->setBackgroundColour(ColourValue::Black);

	//setMaterialName("panel", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	// Añadimos la nueva textura (reflejo) al material del panel
	TextureUnitState* t = ent->getSubEntity(0)->getMaterial()->
		getTechnique(0)->getPass(0)->
		createTextureUnitState("texRtt");
	t->setColourOperation(LBO_ADD); // backgroundColour -> black
	// LBO_MODULATE / LBO_REPLACE / LBO_ALPHA_BLEND;
	t->setTextureAddressingMode(TextureUnitState::TAM_CLAMP);
	t->setProjectiveTexturing(true, camRef);

}


PanelMan::~PanelMan()
{

}
