#include "PanelMan.h"

using namespace Ogre;
PanelMan::PanelMan(Ogre::SceneNode*n, Ogre::Camera* cam, TexturePtr r)
{
	node = n;
	camRef = cam;
	rttTex = r;


	 ent = n->getCreator()->createEntity("entFondo", "mFondo");
	// material del plano
	MyApplicationContext::addInputListener(list);
	ent->getSubEntity(0)->getMaterial()->
		getTechnique(0)->getPass(0) ->
		createTextureUnitState("RustedMetal.jpg");
	node->attachObject(ent);


	node->scale(0.3, 0.3, 0.3);
	node->pitch(Ogre::Degree(-90));
	node->setPosition(0, -25, -50);



	// el reflejo que nunca llegó a salir



	RenderTexture* renderTexture = rttTex->getBuffer()->getRenderTarget();
	Viewport * v = renderTexture->addViewport(camRef);
	v->setClearEveryFrame(true);
	v->setBackgroundColour(ColourValue::Black);

	TextureUnitState* t = ent->getSubEntity(0)->getMaterial()->
		getTechnique(0)->getPass(0)->
		createTextureUnitState("texRtt");
	t->setColourOperation(LBO_ADD); // backgroundColour -> black
	// LBO_MODULATE / LBO_REPLACE / LBO_ALPHA_BLEND;
	t->setTextureAddressingMode(TextureUnitState::TAM_CLAMP);
	t->setProjectiveTexturing(true, camRef);

	ent->setQueryFlags(0);

}


PanelMan::~PanelMan()
{

	MyApplicationContext::removeInputListener(list);
}
