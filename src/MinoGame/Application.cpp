#include <MinoGame/Application.hpp>

#include <MinoGL/GUI.hpp>
#include <MinoGL/OpenGLContext.hpp>

#include <MinoThreads/FunctionProcess.hpp>

#include <assert.h>

#include <tolua++.h>
#include <MinoGame/LuaInterface.hpp>
#include <CEGUI/CEGUI.h>
#include <CEGUI/ScriptModules/Lua/ScriptModule.h>

#include <cassert>
#include <iostream>

USE_GRAPHICSWINDOW()

namespace MinoGame {


	Application::Application(ApplicationBuilder builder){

		_viewer = new osgViewer::Viewer();	

		MinoGL::OpenGLContext::create();
		MinoGL::GUI::create(_viewer.get(), builder.game,
				builder.pathToFiles + "/gui");

		addLuaBindings();


		assert(builder.game);
		_game = GamePtr(builder.game);
		_mainLoop.attach(_game.get());
		(*_game)("MinoAppReady");
	}


	void Application::addLuaBindings()
	{
		using namespace MinoThreads;
		FunctionProcess<> * bindLua = new FunctionProcess<>([]
		{

		using namespace CEGUI;
		System & sys = System::getSingleton();
		sys.getScriptingModule();
		LuaScriptModule * luaModule =
		       static_cast<LuaScriptModule*>(sys.getScriptingModule());
		lua_State * luaState = luaModule->getLuaState();
		tolua_LuaInterface_open(luaState);
		return true;
		});

		MinoGL::OpenGLContext::getInstance().attach(bindLua);
	}


	void Application::run(){
		while(!_viewer->done()){
			_mainLoop.tick();
			_viewer->frame();
		}
	}

	Game* Application::getGame()
	{
		return _game.get();
	}

	osgViewer::Viewer* Application::getViewer()
	{
		return _viewer.get();
	}

	MinoThreads::Scheduler& Application::getMainLoop(){
		return _mainLoop;
	}



}

