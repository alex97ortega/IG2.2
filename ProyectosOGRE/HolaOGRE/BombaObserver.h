#ifndef BOMBAOBSERVER_H_
#define BOMBAOBSERVER_H_
class BombaObserver
{
public:
	BombaObserver();
	virtual ~BombaObserver();

	virtual void onExplosion() = 0;
};
#endif

