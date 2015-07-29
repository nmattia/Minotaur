#ifndef CEGUIDRAWABLE_HPP
#define CEGUIDRAWABLE_HPP

#include <CEGUI/CEGUI.h>
#include <osg/Drawable>
#include <osgGA/GUIEventHandler>
//#include <MinoGL/CEGUIInitializer.hpp>


class CEGUIDrawable : public osg::Drawable
{
	public:
		CEGUIDrawable();
		CEGUIDrawable( const CEGUIDrawable& copy,const osg::CopyOp& copyop=osg::CopyOp::SHALLOW_COPY );
		META_Object( osg, CEGUIDrawable );

		virtual void drawImplementation( osg::RenderInfo& renderInfo ) const;
    
	protected:
		virtual ~CEGUIDrawable() {}

		mutable double _lastSimulationTime;
};



class CEGUIEventHandler : public osgGA::GUIEventHandler
{
public:
    CEGUIEventHandler( osg::Camera* camera ) : _camera(camera) {}
    
    virtual bool handle( const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& aa )
    {
        int x = ea.getX(), y = ea.getY(), width = ea.getWindowWidth(), height = ea.getWindowHeight();
        if ( ea.getMouseYOrientation()==osgGA::GUIEventAdapter::Y_INCREASING_UPWARDS )
            y = ea.getWindowHeight() - y;
        if ( !CEGUI::System::getSingletonPtr() )
            return false;

	
	CEGUI::GUIContext& context = CEGUI::System::getSingleton().getDefaultGUIContext();
        
        switch ( ea.getEventType() )
        {
        case osgGA::GUIEventAdapter::PUSH:
            context.injectMousePosition( x, y );
            context.injectMouseButtonDown( convertMouseButton(ea.getButton()) );
            break;
	case osgGA::GUIEventAdapter::RELEASE:
		context.injectMousePosition( x, y );
		context.injectMouseButtonUp( convertMouseButton(ea.getButton()) );
            break;
        case osgGA::GUIEventAdapter::SCROLL:
            if ( ea.getScrollingMotion()==osgGA::GUIEventAdapter::SCROLL_DOWN ){
                context.injectMouseWheelChange( -1 );
	    }
            else if ( ea.getScrollingMotion()==osgGA::GUIEventAdapter::SCROLL_UP ){
               context.injectMouseWheelChange( +1 );
	    }
            break;
        case osgGA::GUIEventAdapter::DRAG:
        case osgGA::GUIEventAdapter::MOVE:
            context.injectMousePosition( x, y );
            break;
        case osgGA::GUIEventAdapter::RESIZE:
            if ( _camera.valid() )
            {
                _camera->setProjectionMatrix( osg::Matrixd::ortho2D(0.0, width, 0.0, height) );
                _camera->setViewport( 0.0, 0.0, width, height );
            }
            break;
        default:
            return false;
        }
        
	CEGUI::Window* rootWindow= context.getRootWindow();
	if ( rootWindow )
	{
		CEGUI::Window* window = rootWindow->getChildAtPosition(CEGUI::Vector2<float>(x,y));
		if(window){
			return true;
		}
	}
        return false;
    }
    
protected:
    CEGUI::MouseButton convertMouseButton( int button )
    {
        switch ( button )
        {
        case osgGA::GUIEventAdapter::LEFT_MOUSE_BUTTON:
            return CEGUI::LeftButton;
        case osgGA::GUIEventAdapter::MIDDLE_MOUSE_BUTTON:
            return CEGUI::MiddleButton;
        case osgGA::GUIEventAdapter::RIGHT_MOUSE_BUTTON:
            return CEGUI::RightButton;
        default: break;
        }
        return static_cast<CEGUI::MouseButton>(button);
    }
    
    osg::observer_ptr<osg::Camera> _camera;
};

#endif
