#include <MinoGL/GUI.hpp>
#include <MinoGL/CEGUIDrawable.hpp>
#include <MinoGL/OpenGLContext.hpp>

#include <MinoThreads/Scheduler.hpp>
#include <MinoThreads/FunctionProcess.hpp>

#include <osg/Node>
#include <osg/Geode>
#include <osg/StateAttribute>
#include <osg/BlendFunc>
#include <osgViewer/Viewer>

#include <CEGUI/CEGUI.h>
#include <CEGUI/RendererModules/OpenGL/GLRenderer.h>
#include <CEGUI/ScriptModules/Lua/ScriptModule.h>

#include <iostream>
namespace MinoGL{

bool GUI::initCEGUI(std::string pathToFiles){

	CEGUI::OpenGLRenderer::bootstrapSystem();

	// Load the CEGUI system
	CEGUI::DefaultResourceProvider* resource =
	    static_cast<CEGUI::DefaultResourceProvider*>( CEGUI::System::getSingleton().getResourceProvider() );
	resource->setResourceGroupDirectory( "schemes", 
			pathToFiles + "/schemes/" );
	resource->setResourceGroupDirectory( "imagesets", 
			pathToFiles + "/imagesets/" );
	resource->setResourceGroupDirectory( "fonts", 
			pathToFiles + "/fonts/" );
	resource->setResourceGroupDirectory( "layouts", pathToFiles + "/layouts/" );
	resource->setResourceGroupDirectory( "looknfeels", 
			pathToFiles + "/looknfeel/" );
	resource->setResourceGroupDirectory( "lua_scripts", 
			pathToFiles + "/lua_scripts/" );


	CEGUI::ImageManager::setImagesetDefaultResourceGroup("imagesets");	
	CEGUI::Font::setDefaultResourceGroup( "fonts" );
	CEGUI::Scheme::setDefaultResourceGroup( "schemes" );
	CEGUI::WidgetLookManager::setDefaultResourceGroup( "looknfeels" );
	CEGUI::WindowManager::setDefaultResourceGroup( "layouts" );
	CEGUI::ScriptModule::setDefaultResourceGroup( "lua_scripts" );

	CEGUI::LuaScriptModule& luaModule = 
		CEGUI::LuaScriptModule::create();

	CEGUI::System& sys = CEGUI::System::getSingleton();
	sys.setScriptingModule(&luaModule);
	return true;
}


void initGLState(osg::Group* root){
	osg::StateSet* state = root->getOrCreateStateSet();
	state->setMode(GL_LIGHTING, osg::StateAttribute::ON);
	state->setMode(GL_DEPTH_TEST, osg::StateAttribute::ON);
	state->setMode(GL_CULL_FACE, osg::StateAttribute::ON);
}


GUI::GUI(osgViewer::Viewer* viewer, MinoGame::Game * game, 
		std::string pathToFiles)
{

	osg::Group* root = new osg::Group();
	initGLState(root);
	viewer->setSceneData(root);
	// OSG initialization
	osg::ref_ptr<osg::Geode> geode = new osg::Geode;
	geode->setCullingActive( false );
	geode->getOrCreateStateSet()->setAttributeAndModes(
			new osg::BlendFunc );
	geode->getOrCreateStateSet()->setRenderingHint(
			osg::StateSet::TRANSPARENT_BIN );

	osg::ref_ptr<osg::Camera> camera = 
		createOrthoCamera(0, 1366.0f, 0, 768.0f);
	
	camera->setAllowEventFocus(true);
	camera->addChild(geode.get());

	root->addChild(camera);

	// CEGUI initialization

	geode->addDrawable( new CEGUIDrawable );

	MinoThreads::FunctionProcess<std::string>* createCEGUIEnv=
		       new MinoThreads::FunctionProcess<std::string>
		       (GUI::initCEGUI, pathToFiles);

	MinoGL::OpenGLContext::getInstance().attach(createCEGUIEnv);
	viewer->addEventHandler( new CEGUIEventHandler(camera.get()) );

	_sceneRoot = new osg::Group();
	_game = GamePtr(game);

	root->addChild(_sceneRoot);

	//_viewer = viewer;
}



void GUI::executeScript(std::string script)
{
	MinoThreads::FunctionProcess<std::string> *f =
		new MinoThreads::FunctionProcess<std::string>(
				[](std::string filename)
			{
				CEGUI::System& sys = 
					CEGUI::System::getSingleton();	
				CEGUI::ScriptModule* lua = 
					sys.getScriptingModule();
				lua->executeScriptFile(filename);
				return true;
			}, script);

	MinoGL::OpenGLContext::getInstance().attach(f);
}



osg::Camera* GUI::createOrthoCamera(double left, double right, 
		double bottom, double top)
{
	osg::ref_ptr<osg::Camera> camera = new osg::Camera;
	camera->setReferenceFrame(osg::Transform::ABSOLUTE_RF);
	camera->setClearMask(GL_DEPTH_BUFFER_BIT);
	camera->setRenderOrder(osg::Camera::POST_RENDER);
	camera->setProjectionMatrix(
			osg::Matrix::ortho2D(left, right, bottom, top));
	camera->getOrCreateStateSet()->setMode(GL_LIGHTING, 
			osg::StateAttribute::OFF);
	return camera.release();
}

void GUI::notifyEvent(std::string event)
{

	(*_game)(event);
}

void GUI::cleanScene()
{
	int nChildren = _sceneRoot->getNumChildren();
	_sceneRoot->removeChildren(0, nChildren);
}

osg::Group* GUI::getSceneRoot()
{
	return _sceneRoot;
}
}
