#ifndef __UserControl_H__
#define __UserControl_H__

class ObjectMan; // avoid circular dependecy between Usercontrol and ObjectMan

class UserControl
{
public:

	ObjectMan* getControl() { return object; };
	friend class ObjectMan;

protected:
	UserControl(ObjectMan * obj) : object(obj) { };
	~UserControl() { };
	ObjectMan * object;
};

#endif

