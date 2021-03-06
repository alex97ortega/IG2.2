#include "HolaApp.h"

using namespace Ogre;

void HolaApp::frameRendered(const FrameEvent &  evt)
{

	//camNode->lookAt(Ogre::Vector3(300, 0, 10), Ogre::Node::TS_WORLD);
	/*for (int i = 0; i < vecObjMan.size(); ++i){
		vecObjMan[i]->frameRendered(evt);
	}
	*/
}

bool HolaApp::keyPressed(const OgreBites::KeyboardEvent& evt)
{
  if (evt.keysym.sym == SDLK_ESCAPE)
  
    mRoot->queueEndRendering();
  if (evt.keysym.sym == SDLK_t){
	  cameraT = !cameraT;
	  if (cameraT)  camMng->setTarget(node);
	  else{
		  camMng->setTarget(scnMgr->getRootSceneNode());
		  camMng->getCamera()->setPosition(0, 50, 200);
	  }
  }

  return true;
}

bool HolaApp::mousePressed(const OgreBites::MouseButtonEvent &  evt)
{
	/*rayScnQuery->setRay(cam->getCameraToViewportRay(
		evt.x / (Real)mWindow->getViewport(0)->getActualWidth(),
		evt.y / (Real)cam->getViewport()->getActualHeight()));
	// coordenadas normalizadas en [0,1]
	while (it != qryResult.end()/* && �) {
		if (it->movable->getName() == "entSinbad")
			it->movable->getParentSceneNode()->translate(10, 10, 10);
		++it;
	}*/
	rayScnQuery->setRay(cam->getCameraToViewportRay(
		evt.x / (Real)mWindow->getViewport(0)->getActualWidth(),
		evt.y / (Real)cam->getViewport()->getActualHeight())); // coordenadas normalizadas en [0,1]
	
	RaySceneQueryResult& qryResult = rayScnQuery->execute();
	RaySceneQueryResult::iterator it = qryResult.begin();
	
	

	if (it != qryResult.end()) {
		UserControl* pCtrl = any_cast<UserControl*>(it->movable -> getUserObjectBindings().getUserAny());
		pCtrl->getControl()->mousePicking(evt);	
	}

  return true;
}

bool HolaApp::mouseMoved(const OgreBites::MouseMotionEvent& evt)
{
  trayMgr->mouseMoved(evt);
  
  return true;
}

void HolaApp::setupInput()
{
  // do not forget to call the base first
  MyApplicationContext::setupInput(); 
  // register for input events
  addInputListener(this);
}

void HolaApp::shutdown()
{
	for (int i = 0; i<vecObjMan.size(); ++i)
	{
		delete vecObjMan[i];
	}
  //scnMgr->removeRenderQueueListener(mOverlaySystem);
  delete trayMgr;  trayMgr = nullptr;
  // do not forget to call the base 
  MyApplicationContext::shutdown();
}

void HolaApp::setup(void)
{
  // do not forget to call the base first
  MyApplicationContext::setup();

  scnMgr = mRoot->createSceneManager(Ogre::ST_GENERIC);

  // register our scene with the RTSS
  mShaderGenerator->addSceneManager(scnMgr);

  scnMgr->addRenderQueueListener(mOverlaySystem);

  trayMgr = new OgreBites::TrayManager("TrayGUISystem", mWindow);
  trayMgr->showFrameStats(OgreBites::TL_BOTTOMLEFT);
  addInputListener(trayMgr);
  setupScene();
}

void HolaApp::setupScene(void)
{
  // without light we would just get a black screen    
  Light* light = scnMgr->createLight("Light");
  light->setDirection(Ogre::Vector3::NEGATIVE_UNIT_Y); // !!! opngl <-> direcci�n a la fuente de luz
  lightNode = scnMgr->getRootSceneNode()->createChildSceneNode();
  lightNode->setPosition(0, 0, 100);
  lightNode->attachObject(light);

  // also need to tell where we are
  camNode = scnMgr->getRootSceneNode()->createChildSceneNode();
  camNode->setPosition(0, 0, 2000);
  camNode->lookAt(Ogre::Vector3(0, 0, -1), Ogre::Node::TS_WORLD);

  // create the camera
  cam = scnMgr->createCamera("Cam");

  cam->setNearClipDistance(1); 
  cam->setFarClipDistance(10000);
  cam->setAutoAspectRatio(true);

  //cam->setPolygonMode(Ogre::PM_WIREFRAME);  // en material
  camNode->attachObject(cam);

  camMng = new OgreBites::CameraMan(camNode);
  addInputListener(camMng);
  camMng->setStyle(OgreBites::CS_ORBIT);
  camMng->getCamera()->setPosition(0, 50, 200);
  // and tell it to render into the main window
  Viewport* vp = getRenderWindow()->addViewport(cam);
  //vp->setBackgroundColour(Ogre::ColourValue(1, 1, 1));


  //Sinbad
 node = scnMgr->getRootSceneNode()->createChildSceneNode("nSinbad");
  SinbadMan* aux = new SinbadMan(node);
  vecObjMan.push_back(aux);
  addInputListener(aux); // solo porque hereda de inpustListener
 

  
  //plano
  Ogre::SceneNode* nodePlane = scnMgr->getRootSceneNode()->createChildSceneNode("nPlane");
  PanelMan* aux2 = new PanelMan(nodePlane);
	//nodePlane->rotate(Quaternion(Degree(-90), Ogre::Vector3::UNIT_X));


  // boooooooomba
  Ogre::SceneNode*nodeBomba = scnMgr->getRootSceneNode()->createChildSceneNode("nBomba");
  BombaMan* aux3 = new BombaMan(nodeBomba);
  vecObjMan.push_back(aux3);
  addInputListener(aux3); // hereda de inpustListener
  aux3->registerBombaObserver(aux);


  // Fondo (con Shaders)
 scnMgr->setSkyPlane(true, Plane(Vector3::UNIT_Z, -50),
	  "mandelbrot1", 1, 1, true, 0.5, 100, 100);

  // scene queries
  rayScnQuery = scnMgr->createRayQuery(Ray());
  rayScnQuery ->setQueryTypeMask(SceneManager::ENTITY_TYPE_MASK);
  rayScnQuery->setQueryMask(MY_QUERY_MASK);
  rayScnQuery->setSortByDistance(true);

}

