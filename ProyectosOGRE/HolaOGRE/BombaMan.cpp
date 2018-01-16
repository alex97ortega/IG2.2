#include "BombaMan.h"

using namespace Ogre;

BombaMan::BombaMan(Ogre::SceneNode*n) : ObjectMan(n)
{
	node = n;


	ent = n->getCreator()->createEntity("entBomba", "uv_sphere.mesh");
	setObjMan(ent);
	//node->attachObject(ent);

	// finally something to render
	node->setPosition(0, -25, 0);
	node->scale(0.05, 0.05, 0.05);
	//node->showBoundingBox(true);

	ent->setQueryFlags(MY_QUERY_MASK);
	// material
	ent->getSubEntity(0)->setMaterialName("uv_sphere", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);

	// Humo (sistema de particulas)
	pSys = n->getCreator()->createParticleSystem("parSys", "Smoke");
	pSys->addQueryFlags(O_QUERY_MASK);
	n->attachObject(pSys);
	pSys->setEmitting(false);

	// Animacion
	int duracion = 3;
	int tamDesplazamiento = 3;
	Ogre::Vector3 keyframePos(0, -25, 0);
	Ogre::Vector3 esc(0.05, 0.05, 0.05);
	animation = node->getCreator()->createAnimation("animBomba", duracion);
	NodeAnimationTrack * track = animation->createNodeTrack(0);
	track->setAssociatedNode(node);

	Real longitudPaso = duracion / 4.0; // 4 = 5 (numero kf) menos 1
	TransformKeyFrame * kf;

	kf = track->createNodeKeyFrame(longitudPaso * 0); // origen
	kf->setTranslate(keyframePos);
	kf->setScale(esc);

	kf = track->createNodeKeyFrame(longitudPaso * 1); // arriba
	keyframePos += Ogre::Vector3::UNIT_Y * tamDesplazamiento;
	kf->setTranslate(keyframePos); 
	kf->setScale(esc);

	kf = track->createNodeKeyFrame(longitudPaso * 2); //centro (este no es del todo necesario pero lo dejo para que se entienda)
	keyframePos -= Ogre::Vector3::UNIT_Y * tamDesplazamiento;
	kf->setTranslate(keyframePos); 
	kf->setScale(esc);

	kf = track->createNodeKeyFrame(longitudPaso * 3); //abajo
	keyframePos -= Ogre::Vector3::UNIT_Y * tamDesplazamiento;
	kf->setTranslate(keyframePos); 
	kf->setScale(esc);

	kf = track->createNodeKeyFrame(longitudPaso * 4); // origen
	keyframePos += Ogre::Vector3::UNIT_Y * tamDesplazamiento;
	kf->setTranslate(keyframePos); 
	kf->setScale(esc);

	animationState = node->getCreator()->createAnimationState("animBomba");
	animationState->setLoop(true);
	animationState->setEnabled(true);

}


BombaMan::~BombaMan()
{

}

void BombaMan::frameRendered(const Ogre::FrameEvent & evt) {
	animationState->addTime(evt.timeSinceLastFrame);
}

bool BombaMan::mousePicking(const OgreBites::MouseButtonEvent& evt){

	Ogre::Vector3 posAnimation(0, 0, 0);
	pSys->setEmitting(true);
	for (auto o : observadores) o->onExplosion(posAnimation);
		return true;
}

void BombaMan::registerBombaObserver(BombaObserver* o){
	observadores.push_back(o);
}
