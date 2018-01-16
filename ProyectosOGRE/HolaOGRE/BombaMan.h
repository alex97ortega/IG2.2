#ifndef __BombaMan_H__
#define __BombaMan_H__
#include "ObjectMan.h"
#include "BombaObserver.h"

class BombaMan :public ObjectMan , public OgreBites::InputListener
{
public:
	BombaMan(Ogre::SceneNode*n);
	virtual ~BombaMan();

	virtual void registerBombaObserver(BombaObserver* o);
	
	// De Objectman
	bool mousePicking(const OgreBites::MouseButtonEvent& evt);
	void frameRendered(const Ogre::FrameEvent & evt);

private:
	Ogre::SceneNode*node;
	Ogre::Entity* ent;
	Ogre::Entity* entKnot;
	Ogre::AnimationState* animState;
	Ogre::ParticleSystem* pSys;

	Ogre::Animation * animation;
	Ogre::AnimationState * animationState;
	std::vector<BombaObserver*> observadores;
};

#endif
