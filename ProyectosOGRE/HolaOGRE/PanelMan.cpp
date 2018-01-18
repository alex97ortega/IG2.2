#include "PanelMan.h"
using namespace Ogre;
PanelMan::PanelMan(Ogre::SceneNode*n, Ogre::TexturePtr r) 
{
	node = n;
	rttTex = r;

	/*node->scale(0.3, 0.3, 0.3);
	node->pitch(Ogre::Degree(-90));
	node->setPosition(0, -25, -50);*/

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
	camRef->setNearClipDistance(1);
	camRef->setFarClipDistance(10000);
	camRef->setAutoAspectRatio(true);
	node->getCreator()->getCamera("Cam")->getParentSceneNode()->attachObject(camRef);


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

	//Textura del plano (reflejo)
/*	TexturePtr rttTex = TextureManager::getSingleton().createManual(
		"texRtt",
		ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
		TEX_TYPE_2D,
		(Real)node->getCreator()->mWindow->getViewport(0)->getActualWidth(),
		(Real)node->getCreator()->getCamera("Cam")->getViewport()->getActualHeight(),
		0, PF_R8G8B8, TU_RENDERTARGET);*/
}


PanelMan::~PanelMan()
{

}
