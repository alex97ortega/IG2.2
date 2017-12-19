#include "BombaMan.h"

using namespace Ogre;

BombaMan::BombaMan(Ogre::SceneNode*n)
{
	node = n;


	ent = n->getCreator()->createEntity("entBomba", "uv_sphere.mesh");

	// finally something to render
	node->setPosition(0, -25, 0);
	node->scale(0.05, 0.05, 0.05);
	//node->showBoundingBox(true);
	//node->roll(Ogre::Degree(-45));
	node->attachObject(ent);
	ent->getSubEntity(0)->setMaterialName("uv_sphere", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	MyApplicationContext::addInputListener(list);

	ent->setQueryFlags(-1);

}


BombaMan::~BombaMan()
{
	MyApplicationContext::removeInputListener(list);

}

void BombaMan::frameRendered(const Ogre::FrameEvent & evt) {
	
}