#ifndef __SinbadMan_H__
#define __SinbadMan_H__
#include "ObjectMan.h"
class SinbadMan :public ObjectMan, public OgreBites::InputListener
{
public:
	SinbadMan(Ogre::SceneNode*n);
	virtual ~SinbadMan();

	bool mousePicking(const OgreBites::MouseButtonEvent& evt) { return true; }
	void frameRendered(const Ogre::FrameEvent & evt);
private:
	Ogre::SceneNode*node;
	Ogre::Entity* ent;
	Ogre::Entity* ent2;
	Ogre::Entity* ent3;
	Ogre::Entity* entKnot;
	Ogre::Animation* animation;
	Ogre::AnimationState* animState;
	Ogre::AnimationState* animState2;
	Ogre::AnimationState * animationState;
};

#endif