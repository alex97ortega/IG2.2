#ifndef __SinbadMan_H__
#define __SinbadMan_H__
#include "ObjectMan.h"
class SinbadMan :
	public MyApplicationContext,public ObjectMan
{
public:
	SinbadMan();
	virtual ~SinbadMan();
private:
	OgreBites::InputListener* list = new OgreBites::InputListener();
};

#endif