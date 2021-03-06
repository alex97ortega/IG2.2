#ifndef __PanelMan_H__
#define __PanelMan_H__
#include "ObjectMan.h"
class PanelMan : public Ogre::RenderTargetListener 
{
public:
	PanelMan(Ogre::SceneNode*n);
	virtual ~PanelMan(); 
	
private:
	Ogre::SceneNode*node;
	Ogre::Entity* ent;
	Ogre::Camera* camRef;
};
#endif
