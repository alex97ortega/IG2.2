#include "PanelMan.h"


PanelMan::PanelMan()
{

	renderTexture->addListener(list);
}


PanelMan::~PanelMan()
{

	renderTexture->removeListener(list);
}
