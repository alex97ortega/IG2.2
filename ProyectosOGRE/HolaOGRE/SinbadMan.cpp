#include "SinbadMan.h"

using namespace Ogre;
SinbadMan::SinbadMan(Ogre::SceneNode*n)
{
	node = n;


	ent = n->getCreator()->createEntity("entSinbad", "Sinbad.mesh");

	// finally something to render
	//node->setPosition(0, 50, 0);
	node->scale(5, 5, 5);
	//node->showBoundingBox(true);
	//node->roll(Ogre::Degree(-45));
	node->attachObject(ent);
	MyApplicationContext::addInputListener(list);

	ent->setQueryFlags(-1);
}


SinbadMan::~SinbadMan()
{
	MyApplicationContext::removeInputListener(list);
	
}
