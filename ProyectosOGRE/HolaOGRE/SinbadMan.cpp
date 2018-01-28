#include "SinbadMan.h"

using namespace Ogre;
SinbadMan::SinbadMan(Ogre::SceneNode*n) : ObjectMan(n)
{
	node = n;


	ent = n->getCreator()->createEntity("entSinbad", "Sinbad.mesh");
	setObjMan(ent);
	
	node->scale(5, 5, 5);
	

	ent->setQueryFlags(MY_QUERY_MASK);

	animArms = ent->getAnimationState("RunTop");
	animArms->setLoop(true);
	animArms->setEnabled(true);
	
	animLegs = ent->getAnimationState("RunBase");
	animLegs->setLoop(true);
	animLegs->setEnabled(true);

	animSwords = ent->getAnimationState("DrawSwords");
	animSwords->setLoop(true);
	animSwords->setEnabled(false);


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
	nodeKnot->scale(0.01, 0.01, 0.01);
	nodeKnot->setPosition(Ogre::Vector3(0, 5, 0));
	entKnot->getSubEntity(0)->setMaterialName("knotM", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);

	// Animacion Sinbad
	run = true;
	int duracion = 10;
	int tamDesplazamiento = 120;

	Ogre::Vector3 keyframePos = Ogre::Vector3(60,0,60); // abajo derecha
	esc = Ogre::Vector3(5, 5, 5);

	animationSinbad = n->getCreator()->createAnimation("animSinbad", duracion);
	NodeAnimationTrack * trackSinbad = animationSinbad->createNodeTrack(0);
	trackSinbad->setAssociatedNode(node);

	Real longitudPaso = duracion / 4.0;
	TransformKeyFrame * kf;

	kf = trackSinbad->createNodeKeyFrame(longitudPaso * 0); // Keyframe 0
	kf->setTranslate(keyframePos); // Arriba
	kf->setScale(esc);
	kf->setRotation(Vector3(0, 0, 1).getRotationTo(Vector3(-1, 0, 0)));

	kf = trackSinbad->createNodeKeyFrame(longitudPaso * 0.9); // Keyframe 1
	keyframePos -= Ogre::Vector3::UNIT_X * tamDesplazamiento;
	kf->setTranslate(keyframePos); // Arriba
	kf->setScale(esc);
	kf->setRotation(Vector3(0, 0, 1).getRotationTo(Vector3(-1, 0, 0)));
	

	kf = trackSinbad->createNodeKeyFrame(longitudPaso * 1); // Keyframe 2
	kf->setTranslate(keyframePos);
	kf->setScale(esc);
	kf->setRotation(Vector3(0, 0, 1).getRotationTo(Vector3(0, 0, -1)));

	kf = trackSinbad->createNodeKeyFrame(longitudPaso * 1.9); // Keyframe 3
	keyframePos -= Ogre::Vector3::UNIT_Z * tamDesplazamiento;
	kf->setTranslate(keyframePos); // Arriba
	kf->setScale(esc);
	kf->setRotation(Vector3(0, 0, 1).getRotationTo(Vector3(0, 0, -1)));

	kf = trackSinbad->createNodeKeyFrame(longitudPaso * 2); // Keyframe 4
	kf->setTranslate(keyframePos);
	kf->setScale(esc);
	kf->setRotation(Vector3(0, 0, 1).getRotationTo(Vector3(1, 0, 0)));

	kf = trackSinbad->createNodeKeyFrame(longitudPaso * 2.9); // Keyframe 5
	keyframePos += Ogre::Vector3::UNIT_X * tamDesplazamiento;
	kf->setTranslate(keyframePos); // Arriba
	kf->setScale(esc);
	kf->setRotation(Vector3(0, 0, 1).getRotationTo(Vector3(1, 0, 0)));


	kf = trackSinbad->createNodeKeyFrame(longitudPaso * 3); // Keyframe 6
	kf->setTranslate(keyframePos);
	kf->setScale(esc);

	kf = trackSinbad->createNodeKeyFrame(longitudPaso * 3.9); // Keyframe 7
	keyframePos += Ogre::Vector3::UNIT_Z * tamDesplazamiento;
	kf->setTranslate(keyframePos); // Arriba
	kf->setScale(esc);

	kf = trackSinbad->createNodeKeyFrame(longitudPaso * 4); // Keyframe 8
	kf->setTranslate(keyframePos);
	kf->setScale(esc);
	kf->setRotation(Vector3(0, 0, 1).getRotationTo(Vector3(-1, 0, 0)));

	animationStateSinbad = n->getCreator()->createAnimationState("animSinbad");
	animationStateSinbad->setLoop(true);
	animationStateSinbad->setEnabled(true);

	// Animacion mosca
	/*
	int duracionKnot = 4;
	Ogre::Vector3 keyframePosKnot(0, 5, 0);
	Ogre::Vector3 escKnot(0.01, 0.01, 0.01);

	animationKnot= n->getCreator()->createAnimation("animKnot", duracionKnot);
	NodeAnimationTrack * trackKnot = animationKnot->createNodeTrack(0);
	trackKnot->setAssociatedNode(nodeKnot);

	Real longitudPasoKnot = duracionKnot / 4;
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
	animationStateKnot->setEnabled(true);*/
	
	// Animacion Sinbad va hacia la bomba 
	duracionBomba = 3;
	animationBomba = n->getCreator()->createAnimation("animSinbadBomba", duracionBomba);
	trackBomba = animationBomba->createNodeTrack(0);
	trackBomba->setAssociatedNode(node);
	

	animationStateBomba = n->getCreator()->createAnimationState("animSinbadBomba");
	animationStateBomba->setLoop(false);
	animationStateBomba->setEnabled(false);

	trackBomba->createNodeKeyFrame(duracionBomba * 0); // Keyframe 0
	trackBomba->createNodeKeyFrame( duracionBomba * 0.9); // Keyframe 1
	trackBomba->createNodeKeyFrame(duracionBomba * 1); // Keyframe 2
	//trackBomba->createNodeKeyFrame(duracionBomba * 1); // Keyframe 2

	goBomba = false;
	muerto = false;
	posBomba = (100000, 100000, 100000);
}


SinbadMan::~SinbadMan()
{
	
}
const float PI = 3.14;
void SinbadMan::frameRendered(const Ogre::FrameEvent & evt) {
	animArms->addTime(evt.timeSinceLastFrame);
	animLegs->addTime(evt.timeSinceLastFrame);
	animSwords->addTime(evt.timeSinceLastFrame);
	animationStateSinbad->addTime(evt.timeSinceLastFrame);
	//animationStateKnot->addTime(evt.timeSinceLastFrame);
	if(goBomba)animationStateBomba->addTime(evt.timeSinceLastFrame);

	//if (node->getPosition().x == posBomba.x && node->getPosition().z == posBomba.z){
	if(animationStateBomba->hasEnded()){
		animationStateBomba->setEnabled(false);
		muerto = true;
		animLegs->setEnabled(false);
		animSwords->setEnabled(false);
	}
	if (muerto){ 
		/*Ogre::Vector3 pos = node->getPosition();
		pos.x -= 10;
		node->setPosition(pos); */

		//node->translate(-10, 0, 0, Ogre::Node::TS_WORLD);
		//node->translate(Vector3(-10, 0, 0));
		node->translate(-1, 0, 0);
	}
	
	//nodeknot->yaw(Ogre::Degree(10 * evt.timeSinceLastFrame));
	nodeKnot->yaw(Ogre::Radian(PI/36), Ogre::Node::TransformSpace::TS_LOCAL);
}

bool SinbadMan::mousePicking(const OgreBites::MouseButtonEvent& evt){
	if (run){ // Se para
		run = false;
		time = animationStateSinbad->getTimePosition();
		animArms->setEnabled(false);
		animLegs->setEnabled(false);
	}
	else{ // Continua
		run = true;
		animationStateSinbad->setTimePosition(time);
		animArms->setEnabled(true);
		animLegs->setEnabled(true);
	}
	animationStateSinbad->setEnabled(run);
	return true;
	//node->showBoundingBox(true);
}

void SinbadMan::onExplosion(Ogre::Vector3 posicionBomba){
	posBomba = posicionBomba;
	goBomba = true;
	animationStateSinbad->setEnabled(false);
	animationStateBomba->setEnabled(false);

	ent->detachObjectFromBone(ent3);
	ent->attachObjectToBone("Handle.R", ent3);
	animArms->setEnabled(false);
	animSwords->setEnabled(true);

	Ogre::Vector3 posSinbadBomba = node->getPosition();
	Ogre::TransformKeyFrame * kf3;


	kf3 = trackBomba->getNodeKeyFrame(0);
	kf3->setTranslate(posSinbadBomba);
	kf3->setRotation(Vector3(0, 0, 1).getRotationTo(posicionBomba - posSinbadBomba));
	kf3->setScale(esc);


	kf3 = trackBomba->getNodeKeyFrame(1);
	kf3->setTranslate(posicionBomba);
	kf3->setRotation(Vector3(0, 0, 1).getRotationTo(posicionBomba - posSinbadBomba));
	kf3->setScale(esc);
	
	kf3 = trackBomba->getNodeKeyFrame(2);
	kf3->setTranslate(posicionBomba - Vector3(0, 25, 0));
	kf3->setRotation(Vector3(0, 0, 1).getRotationTo(Vector3(0, 1, 0)));
	kf3->setScale(esc);

	/*kf3 = trackBomba->getNodeKeyFrame(3);
	kf3->setTranslate(Vector3(-250, -25, 0));
	kf3->setRotation(Vector3(0, 0, 1).getRotationTo(Vector3(0, 1, 0)));
	kf3->setScale(esc);*/
	
	
	animationStateBomba->setEnabled(true);
}
