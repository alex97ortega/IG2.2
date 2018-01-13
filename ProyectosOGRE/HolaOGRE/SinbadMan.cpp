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
	ent2->setQueryFlags(MY_QUERY_MASK);
	ent->attachObjectToBone("Handle.L", ent2);
	ent3 = n->getCreator()->createEntity("sword2", "Sword.mesh");
	ent3->setQueryFlags(MY_QUERY_MASK);
	//ent->attachObjectToBone("Handle.R", ent3);
	ent->attachObjectToBone("Sheath.R", ent3);

	nodeKnot = node->createChildSceneNode("nKnot"); 
	entKnot = n->getCreator()->createEntity("knot", "knot.mesh");
	entKnot->setQueryFlags(O_QUERY_MASK);
	nodeKnot->attachObject(entKnot);
	//nodeKnot->scale(0.01, 0.01, 0.01);
	//nodeKnot->setPosition(Ogre::Vector3(0, 5, 0));
	entKnot->getSubEntity(0)->setMaterialName("knotM", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);

	// Animacion Sinbad
	int duracion = 10;
	int tamDesplazamiento = 80;
	Ogre::Vector3 keyframePos (-40,0,50); // abajo derecha
	Ogre::Vector3 esc(5, 5, 5);

	animationSinbad = n->getCreator()->createAnimation("animSinbad", duracion);
	NodeAnimationTrack * trackSinbad = animationSinbad->createNodeTrack(0);
	trackSinbad->setAssociatedNode(node);

	Real longitudPaso = duracion / 4.1;
	TransformKeyFrame * kf;

	kf = trackSinbad->createNodeKeyFrame(longitudPaso * 0); // Keyframe 0
	keyframePos += Ogre::Vector3::UNIT_X* tamDesplazamiento;
	kf->setTranslate(keyframePos); // Arriba
	kf->setScale(esc);
	kf->setRotation(Vector3(0, 0, 1).getRotationTo(Vector3(-1, 0, 0)));

	kf = trackSinbad->createNodeKeyFrame(longitudPaso * 1); // Keyframe 1
	keyframePos -= Ogre::Vector3::UNIT_X * tamDesplazamiento;
	kf->setTranslate(keyframePos); // Arriba
	kf->setScale(esc);
	kf->setRotation(Vector3(0, 0, 1).getRotationTo(Vector3(-1, 0, 0)));
	

	kf = trackSinbad->createNodeKeyFrame(longitudPaso * 1.1); // Keyframe 2
	kf->setTranslate(keyframePos);
	kf->setScale(esc);
	kf->setRotation(Vector3(0, 0, 1).getRotationTo(Vector3(0, 0, -1)));

	kf = trackSinbad->createNodeKeyFrame(longitudPaso * 2); // Keyframe 3
	keyframePos -= Ogre::Vector3::UNIT_Z * tamDesplazamiento;
	kf->setTranslate(keyframePos); // Arriba
	kf->setScale(esc);
	kf->setRotation(Vector3(0, 0, 1).getRotationTo(Vector3(0, 0, -1)));

	kf = trackSinbad->createNodeKeyFrame(longitudPaso * 2.1); // Keyframe 4
	kf->setTranslate(keyframePos);
	kf->setScale(esc);
	kf->setRotation(Vector3(0, 0, 1).getRotationTo(Vector3(1, 0, 0)));

	kf = trackSinbad->createNodeKeyFrame(longitudPaso * 3); // Keyframe 5
	keyframePos += Ogre::Vector3::UNIT_X * tamDesplazamiento;
	kf->setTranslate(keyframePos); // Arriba
	kf->setScale(esc);
	kf->setRotation(Vector3(0, 0, 1).getRotationTo(Vector3(1, 0, 0)));


	kf = trackSinbad->createNodeKeyFrame(longitudPaso * 3.1); // Keyframe 6
	kf->setTranslate(keyframePos);
	kf->setScale(esc);

	kf = trackSinbad->createNodeKeyFrame(longitudPaso * 4); // Keyframe 7
	keyframePos += Ogre::Vector3::UNIT_Z * tamDesplazamiento;
	kf->setTranslate(keyframePos); // Arriba
	kf->setScale(esc);

	kf = trackSinbad->createNodeKeyFrame(longitudPaso * 4.1); // Keyframe 6
	kf->setTranslate(keyframePos);
	kf->setScale(esc);
	kf->setRotation(Vector3(0, 0, 1).getRotationTo(Vector3(-1, 0, 0)));

	animationStateSinbad = n->getCreator()->createAnimationState("animSinbad");
	animationStateSinbad->setLoop(true);
	animationStateSinbad->setEnabled(true);

	// Animacion mosca
	int duracionKnot = 4;
	//Ogre::Vector3 keyframePos(-40, 0, 50); // abajo derecha
	Ogre::Vector3 keyframePosKnot(0, 5, 0);
	Ogre::Vector3 escKnot(0.01, 0.01, 0.01);

	animationKnot= n->getCreator()->createAnimation("animKnot", duracionKnot);
	NodeAnimationTrack * trackKnot = animationKnot->createNodeTrack(0);
	trackKnot->setAssociatedNode(nodeKnot);

	Real longitudPasoKnot = duracionKnot / 3;
	TransformKeyFrame * kf2;

	kf2 = trackKnot->createNodeKeyFrame(longitudPasoKnot * 0); // Keyframe 0
	kf2->setTranslate(keyframePosKnot);
	kf2->setScale(escKnot);
	kf2->setRotation(Vector3(0, 0, 1).getRotationTo(Vector3(0, 0, 1)));

	kf2 = trackKnot->createNodeKeyFrame(longitudPasoKnot * 1); // Keyframe 1
	kf2->setTranslate(keyframePosKnot);
	kf2->setScale(escKnot);
	kf2->setRotation(Vector3(0, 0, 1).getRotationTo(Vector3(-1, 0, 0)));

	kf2 = trackKnot->createNodeKeyFrame(longitudPasoKnot * 2); // Keyframe 2
	kf2->setTranslate(keyframePosKnot);
	kf2->setScale(escKnot);
	kf2->setRotation(Vector3(0, 0, 1).getRotationTo(Vector3(0, 0, -1)));

	kf2 = trackKnot->createNodeKeyFrame(longitudPasoKnot * 3); // Keyframe 3
	kf2->setTranslate(keyframePosKnot);
	kf2->setScale(escKnot);
	kf2->setRotation(Vector3(0, 0, 1).getRotationTo(Vector3(1, 0, 0)));

	kf2 = trackKnot->createNodeKeyFrame(longitudPasoKnot * 4); // Keyframe 4
	kf2->setTranslate(keyframePosKnot);
	kf2->setScale(escKnot);
	kf2->setRotation(Vector3(0, 0, 1).getRotationTo(Vector3(0, 0, 1)));

	animationStateKnot = n->getCreator()->createAnimationState("animKnot");
	animationStateKnot->setLoop(true);
	animationStateKnot->setEnabled(true);
}


SinbadMan::~SinbadMan()
{
	
}

void SinbadMan::frameRendered(const Ogre::FrameEvent & evt) {
	animState->addTime(evt.timeSinceLastFrame);
	animState2->addTime(evt.timeSinceLastFrame);
	animationStateSinbad->addTime(evt.timeSinceLastFrame);
	animationStateKnot->addTime(evt.timeSinceLastFrame);
}

bool SinbadMan::mousePicking(const OgreBites::MouseButtonEvent& evt){
	node->showBoundingBox(true);
	return true;
}