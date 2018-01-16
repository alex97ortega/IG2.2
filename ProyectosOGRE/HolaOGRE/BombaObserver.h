#ifndef BOMBAOBSERVER_H_
#define BOMBAOBSERVER_H_

#include "MyApplicationContext.h"
#include <OgreTrays.h>
#include <OgreCameraMan.h>
#include "UserControl.h"
class BombaObserver
{
public:
	BombaObserver();
	virtual ~BombaObserver();

	virtual void onExplosion(Ogre::Vector3 posicionBomba) = 0;
};
#endif

