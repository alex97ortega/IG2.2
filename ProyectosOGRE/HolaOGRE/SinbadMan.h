#ifndef __SinbadMan_H__
#define __SinbadMan_H__
#include "ObjectMan.h"
#include "BombaObserver.h"
class SinbadMan :public ObjectMan, public OgreBites::InputListener, public BombaObserver
{
public:
	SinbadMan(Ogre::SceneNode*n);
	virtual ~SinbadMan();

	// De ObjectMan
	bool mousePicking(const OgreBites::MouseButtonEvent& evt);
	void frameRendered(const Ogre::FrameEvent & evt);

	// De BombaObserver
	void onExplosion();

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
	Ogre::Animation* animationBomba;
	Ogre::AnimationState* animationStateBomba;

	Ogre::Vector3 keyframePos; // abajo derecha
	Ogre::Vector3 esc;

	Ogre::Real time; // momento de la animacion en el que para de correr
	bool run;

	// Animacion Sinbad va hacia la bomba
	Ogre::Real duracionBomba;
	Ogre::NodeAnimationTrack * trackBomba;
	Ogre::TransformKeyFrame * kf3;
	Ogre::Vector3 posBomba; // sitio donde esta en el momento en el que la bomba es clickeada
};

#endif