#ifndef __PanelMan_H__
#define __PanelMan_H__
#include "ObjectMan.h"
class PanelMan :
	public ObjectMan
{
public:
	PanelMan();
	virtual ~PanelMan();
private:
	Ogre::RenderTargetListener* list = new Ogre::RenderTargetListener();
};
#endif
