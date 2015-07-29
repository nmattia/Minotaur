#ifndef MINO_APPLICATION_HPP
#define MINO_APPLICATION_HPP
#include <MinoGame/ApplicationBuilder.hpp>
#include <MinoUtils/Singleton.hpp>
#include <MinoThreads/Scheduler.hpp>
#include <osg/ref_ptr>
#include <osg/Group>
#include <osgViewer/Viewer>
namespace MinoGame {

    class Application : public MinoUtils::Singleton<Application> {
        typedef std::shared_ptr<Game> GamePtr;

        public:

        Application(ApplicationBuilder builder);
        MinoThreads::Scheduler& getMainLoop();
        void run();
        Game* getGame();
        //osg::Group* getSceneRoot();
        osgViewer::Viewer* getViewer();


        private:
        osg::ref_ptr<osgViewer::Viewer> _viewer;
        //osg::ref_ptr<osg::Group> _sceneRoot;
        MinoThreads::Scheduler _mainLoop;
        GamePtr _game;

        void addLuaBindings();

    };

}
#endif
