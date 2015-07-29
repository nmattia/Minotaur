#ifndef GUI_HPP
#define GUI_HPP

#include <string>
#include <memory>

#include <MinoUtils/Singleton.hpp>
#include <MinoGame/Game.hpp>
#include <osgViewer/Viewer>
namespace MinoGL {


class GUI : public MinoUtils::Singleton<GUI> {

	typedef std::shared_ptr<MinoGame::Game> GamePtr;
	
	public:
		static void executeScript(std::string script);

		GUI(osgViewer::Viewer* viewer, MinoGame::Game * game, 
				std::string pathToFiles);

		void notifyEvent(std::string event);
		void cleanScene();

		osg::Group* getSceneRoot();

	private:
		static osg::Camera* createOrthoCamera(double, double, double, double); 
		static bool initCEGUI(std::string pathToFiles);
		
		osg::ref_ptr<osg::Group> _sceneRoot;
		GamePtr _game;


};
}

#endif
