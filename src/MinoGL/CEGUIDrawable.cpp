#include <MinoGL/CEGUIDrawable.hpp>
#include <MinoGL/OpenGLContext.hpp>
#include <iostream>
#include <osgViewer/ViewerEventHandlers>
#include <CEGUI/RendererModules/OpenGL/GLRenderer.h>



CEGUIDrawable::CEGUIDrawable() : _lastSimulationTime(0.0)
{
    setSupportsDisplayList( false );
    setDataVariance( osg::Object::DYNAMIC );
    getOrCreateStateSet()->setMode( GL_LIGHTING, osg::StateAttribute::OFF );
    getOrCreateStateSet()->setMode( GL_DEPTH_TEST, osg::StateAttribute::OFF );
}

CEGUIDrawable::CEGUIDrawable( const CEGUIDrawable& copy,const osg::CopyOp& copyop )
		: osg::Drawable(copy, copyop),
	_lastSimulationTime(copy._lastSimulationTime)
{}

void CEGUIDrawable::drawImplementation( osg::RenderInfo& renderInfo ) const
{	


	MinoGL::OpenGLContext::getInstance().tick();


	//if ( !CEGUI::System::getSingletonPtr()){
		//CEGUI::OpenGLRenderer::bootstrapSystem();
	//}
	if( !CEGUI::System::getSingletonPtr() )
		return;


	osg::State* state = renderInfo.getState();
	state->disableAllVertexArrays();
	state->disableTexCoordPointer( 0 );

	glPushMatrix();
	glPushAttrib( GL_ALL_ATTRIB_BITS );

		CEGUI::OpenGLRenderer* renderer = static_cast<CEGUI::OpenGLRenderer*>(
		    CEGUI::System::getSingleton().getRenderer() );
		osg::Viewport* viewport = renderInfo.getCurrentCamera()->getViewport();
		if ( renderer && viewport )
		{
		
			const CEGUI::Sizef& size = renderer->getDisplaySize();
			if ( size.d_width!=viewport->width() || size.d_height!=viewport->height() )
			{
			    CEGUI::System::getSingleton().notifyDisplaySizeChanged(
				CEGUI::Size<float>(viewport->width(), viewport->height()) );
			}
		}
		
	double currentTime = (state->getFrameStamp() ? state->getFrameStamp()->getSimulationTime() : 0.0);
	CEGUI::System& system = CEGUI::System::getSingleton();
	CEGUI::GUIContext& context = system.getDefaultGUIContext();
	context.injectTimePulse((currentTime - _lastSimulationTime)/1000.0);

	system.renderAllGUIContexts();
	_lastSimulationTime = currentTime;

	glPopAttrib();
	glPopMatrix();
}







