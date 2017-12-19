#ifndef __BombaMan_H__
#define __BombaMan_H__
#include "ObjectMan.h"
#include "ParticleSystemMan.h"

class BombaMan :
	public MyApplicationContext, public ObjectMan
{
public:
	BombaMan(Ogre::SceneNode*n);
	virtual ~BombaMan();

	bool mousePicking(const OgreBites::MouseButtonEvent& evt) { return true; }
	void frameRendered(const Ogre::FrameEvent & evt);

private:
	OgreBites::InputListener* list = new OgreBites::InputListener();
	Ogre::SceneNode*node;
	Ogre::Entity* ent;
	Ogre::Entity* ent2;
	Ogre::Entity* entKnot;
	Ogre::Animation* animation;
	Ogre::AnimationState* animState;
};

#endif
