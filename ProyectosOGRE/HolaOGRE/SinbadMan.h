#ifndef __SinbadMan_H__
#define __SinbadMan_H__
#include "ObjectMan.h"
class SinbadMan :public ObjectMan, public OgreBites::InputListener
{
public:
	SinbadMan(Ogre::SceneNode*n);
	virtual ~SinbadMan();

	bool mousePicking(const OgreBites::MouseButtonEvent& evt);
	void frameRendered(const Ogre::FrameEvent & evt);
private:
	Ogre::SceneNode*node;
	Ogre::Entity* ent;
	Ogre::Entity* ent2;
	Ogre::Entity* ent3;
	Ogre::Entity* entKnot;
	Ogre::SceneNode * nodeKnot;
	Ogre::AnimationState* animArms;
	Ogre::AnimationState* animLegs;
	Ogre::Animation* animationSinbad;
	Ogre::AnimationState * animationStateSinbad;
	Ogre::Animation* animationKnot;
	Ogre::AnimationState* animationStateKnot;
	
	Ogre::Real pos;
	bool run;
};

#endif