#ifndef __ObjectMan_H__
#define __ObjectMan_H__

#include "MyApplicationContext.h"
#include <OgreTrays.h>
#include <OgreCameraMan.h>
#include "UserControl.h"

class ObjectMan
{
public:
	static const Ogre::uint32 MY_QUERY_MASK = 1;
	static const Ogre::uint32 O_QUERY_MASK = 0;

	virtual ~ObjectMan();

	virtual bool mousePicking(const OgreBites::MouseButtonEvent& evt){ return true; };
	virtual void frameRendered(const Ogre::FrameEvent & evt){};
	virtual void setObjMan(Ogre::MovableObject* mObj);

protected:
	ObjectMan(Ogre::SceneNode* scnNode);
	//Ogre::RenderTexture* renderTexture;
	Ogre::SceneNode* node = nullptr;
	UserControl* control = nullptr;
};

#endif