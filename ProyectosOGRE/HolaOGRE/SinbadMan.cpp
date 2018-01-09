#include "SinbadMan.h"

using namespace Ogre;
SinbadMan::SinbadMan(Ogre::SceneNode*n) : ObjectMan(n)
{
	node = n;


	ent = n->getCreator()->createEntity("entSinbad", "Sinbad.mesh");
	setObjMan(ent);
	
	node->scale(5, 5, 5);
	

	ent->setQueryFlags(MY_QUERY_MASK);

	animState = ent->getAnimationState("Dance");
	animState2 = ent->getAnimationState("RunBase");
	animState->setLoop(true);
	animState->setEnabled(true);
	animState2->setLoop(true);
	animState2->setEnabled(true);



	ent2 = n->getCreator()->createEntity("sword", "Sword.mesh");
	ent2->addQueryFlags(O_QUERY_MASK);
	ent->attachObjectToBone("Handle.L", ent2);
	ent3 = n->getCreator()->createEntity("sword2", "Sword.mesh");
	ent3->addQueryFlags(O_QUERY_MASK);
	ent->attachObjectToBone("Handle.R", ent3);
	//ent->attachObjectToBone("Sheath.R", ent2);

	// Animacion
	int duracion = 10;
	int tamDesplazamiento = 80;
	Ogre::Vector3 keyframePos (-40,0,50); // abajo derecha
	Ogre::Vector3 esc(5, 5, 5);
	//SceneNode * nodeKnot = n->getCreator()->getRootSceneNode()->createChildSceneNode("nKnot");
	//nodeKnot->scale(0.02, 0.02, 0.02);
	//entKnot = n->getCreator()->createEntity("entKnot", "knot.mesh");
	//nodeKnot->attachObject(entKnot); // Examples.material -> "2 – Default " -> MtlPlat2.jpg

	animation = n->getCreator()->createAnimation("animKnot", duracion);
	NodeAnimationTrack * track = animation->createNodeTrack(0);
	track->setAssociatedNode(node);

	Real longitudPaso = duracion / 4.1;
	TransformKeyFrame * kf;

	kf = track->createNodeKeyFrame(longitudPaso * 0); // Keyframe 0
	keyframePos += Ogre::Vector3::UNIT_X* tamDesplazamiento;
	kf->setTranslate(keyframePos); // Arriba
	kf->setScale(esc);
	kf->setRotation(Vector3(0, 0, 1).getRotationTo(Vector3(-1, 0, 0)));

	kf = track->createNodeKeyFrame(longitudPaso * 1); // Keyframe 1
	keyframePos -= Ogre::Vector3::UNIT_X * tamDesplazamiento;
	kf->setTranslate(keyframePos); // Arriba
	kf->setScale(esc);
	kf->setRotation(Vector3(0, 0, 1).getRotationTo(Vector3(-1, 0, 0)));
	

	kf = track->createNodeKeyFrame(longitudPaso * 1.1); // Keyframe 2
	kf->setTranslate(keyframePos);
	kf->setScale(esc);
	kf->setRotation(Vector3(0, 0, 1).getRotationTo(Vector3(0, 0, -1)));

	kf = track->createNodeKeyFrame(longitudPaso * 2); // Keyframe 3
	keyframePos -= Ogre::Vector3::UNIT_Z * tamDesplazamiento;
	kf->setTranslate(keyframePos); // Arriba
	kf->setScale(esc);
	kf->setRotation(Vector3(0, 0, 1).getRotationTo(Vector3(0, 0, -1)));

	kf = track->createNodeKeyFrame(longitudPaso * 2.1); // Keyframe 4
	kf->setTranslate(keyframePos);
	kf->setScale(esc);
	kf->setRotation(Vector3(0, 0, 1).getRotationTo(Vector3(1, 0, 0)));

	kf = track->createNodeKeyFrame(longitudPaso * 3); // Keyframe 5
	keyframePos += Ogre::Vector3::UNIT_X * tamDesplazamiento;
	kf->setTranslate(keyframePos); // Arriba
	kf->setScale(esc);
	kf->setRotation(Vector3(0, 0, 1).getRotationTo(Vector3(1, 0, 0)));


	kf = track->createNodeKeyFrame(longitudPaso * 3.1); // Keyframe 6
	kf->setTranslate(keyframePos);
	kf->setScale(esc);

	kf = track->createNodeKeyFrame(longitudPaso * 4); // Keyframe 7
	keyframePos += Ogre::Vector3::UNIT_Z * tamDesplazamiento;
	kf->setTranslate(keyframePos); // Arriba
	kf->setScale(esc);

	kf = track->createNodeKeyFrame(longitudPaso * 4.1); // Keyframe 6
	kf->setTranslate(keyframePos);
	kf->setScale(esc);
	kf->setRotation(Vector3(0, 0, 1).getRotationTo(Vector3(-1, 0, 0)));

	animationState = n->getCreator()->createAnimationState("animKnot");
	animationState->setLoop(true);
	animationState->setEnabled(true);

}


SinbadMan::~SinbadMan()
{
	
}

void SinbadMan::frameRendered(const Ogre::FrameEvent & evt) {
	animState->addTime(evt.timeSinceLastFrame);
	animState2->addTime(evt.timeSinceLastFrame);
	animationState->addTime(evt.timeSinceLastFrame);
}

bool SinbadMan::mousePicking(const OgreBites::MouseButtonEvent& evt){
	node->showBoundingBox(true);
	return true;
}