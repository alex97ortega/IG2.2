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

	ent->setQueryFlags(-1);


	pSys = n->getCreator()->createParticleSystem("parSys", "Smoke");
	n->attachObject(pSys);
	pSys->setEmitting(true);
}


BombaMan::~BombaMan()
{

}
