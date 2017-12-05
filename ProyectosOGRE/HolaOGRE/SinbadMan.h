#ifndef __SinbadMan_H__
#define __SinbadMan_H__
#include "ObjectMan.h"
class SinbadMan :
	public MyApplicationContext,public ObjectMan
{
public:
	SinbadMan(Ogre::SceneNode*n);
	virtual ~SinbadMan();

	bool mousePicking(const OgreBites::MouseButtonEvent& evt) { return true; }
	void frameRendered(const Ogre::FrameEvent & evt) {  }
private:
	OgreBites::InputListener* list = new OgreBites::InputListener();
	Ogre::SceneNode*node;
	Ogre::Entity* ent;
};

#endif