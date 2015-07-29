#ifndef PICKHANDLER_HPP
#define PICKHANDLER_HPP

#include <osg/ref_ptr>
#include <osg/MatrixTransform>
#include <osgUtil/LineSegmentIntersector>
#include <osgViewer/Viewer>
#include <osgGA/TrackballManipulator>
#include <osgDB/ReadFile>

#include <functional>

namespace MinoUtils
{

class PickHandler : public osgGA::GUIEventHandler
{
	typedef std::function<
		void(const osgUtil::LineSegmentIntersector::Intersection &)> 
				Func;

	public :

		bool handle(const osgGA::GUIEventAdapter & ea,
				osgGA::GUIActionAdapter & aa);
		void setCallback(Func f)
		{
			_f = f;
		}

	protected:
		Func _f;
};

	
	



}

#endif /* PICKHANDLER_HPP */

