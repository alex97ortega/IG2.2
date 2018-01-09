#ifndef __BombaMan_H__
#define __BombaMan_H__
#include "ObjectMan.h"

class BombaMan :public ObjectMan , public OgreBites::InputListener
{
public:
	BombaMan(Ogre::SceneNode*n);
	virtual ~BombaMan();

	bool mousePicking(const OgreBites::MouseButtonEvent& evt) { // if clickeado pSys->setEmitting(true); 
		return true; }
	void frameRendered(const Ogre::FrameEvent & evt);

private:
	Ogre::SceneNode*node;
	Ogre::Entity* ent;
	Ogre::Entity* entKnot;
	Ogre::AnimationState* animState;
	Ogre::ParticleSystem* pSys;

	Ogre::Animation * animation;
	Ogre::AnimationState * animationState;
};

#endif
