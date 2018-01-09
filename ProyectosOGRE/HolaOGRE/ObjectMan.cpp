#include "ObjectMan.h"

ObjectMan::ObjectMan(Ogre::SceneNode* scnNode) : node(scnNode) {
	control = new UserControl(this);
}

ObjectMan::~ObjectMan() {
	UserControl* pCtrl = Ogre::any_cast<UserControl*>(
		node->getAttachedObject(0) ->
		getUserObjectBindings().getUserAny());
	delete pCtrl;
}

void ObjectMan::setObjMan(Ogre::MovableObject* mObj) {
	// comprobar que es el primer objeto que se adjunta al nodo
		node->attachObject(mObj);
	//ent->getUserObjectBindings().setUserAny(Any(control));
}