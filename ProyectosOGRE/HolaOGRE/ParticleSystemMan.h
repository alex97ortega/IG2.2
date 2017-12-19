#pragma once
#include "ObjectMan.h"
class ParticleSystemMan :
	public MyApplicationContext, public ObjectMan
{
public:
	ParticleSystemMan(Ogre::SceneNode*n);
	virtual ~ParticleSystemMan();

	bool mousePicking(const OgreBites::MouseButtonEvent& evt) { return true; }
	void frameRendered(const Ogre::FrameEvent & evt);

private:
	OgreBites::InputListener* list = new OgreBites::InputListener();
	Ogre::SceneNode*node;
	Ogre::Entity* ent;
	Ogre::Entity* entKnot;
	Ogre::Animation* animation;
	Ogre::AnimationState* animState;
};

