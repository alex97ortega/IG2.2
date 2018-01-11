#ifndef __FondoMan_H__
#define __FondoMan_H__
#include "ObjectMan.h"
class FondoMan : public ObjectMan, public Ogre::RenderTargetListener
{
public:
	FondoMan(Ogre::SceneNode*n, Ogre::TexturePtr r);
	virtual ~FondoMan();

private:
	Ogre::SceneNode*node;
	Ogre::Entity* ent;
	Ogre::Camera* camRef;
	Ogre::TexturePtr rttTex;
};
#endif
