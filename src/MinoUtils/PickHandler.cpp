#include <MinoUtils/PickHandler.hpp>

namespace MinoUtils {

bool PickHandler::handle(const osgGA::GUIEventAdapter & ea,
		osgGA::GUIActionAdapter & aa) {
	if (!_f)
		return false;

	if (ea.getEventType() != osgGA::GUIEventAdapter::RELEASE
			|| ea.getButton() != osgGA::GUIEventAdapter::LEFT_MOUSE_BUTTON)
		return false;

	osgViewer::Viewer * viewer = dynamic_cast<osgViewer::Viewer*>(&aa);

	if (viewer) {
		osg::ref_ptr<osgUtil::LineSegmentIntersector> intersector =
				new osgUtil::LineSegmentIntersector(
						osgUtil::Intersector::WINDOW, ea.getX(), ea.getY());
		osgUtil::IntersectionVisitor iv(intersector.get());
		iv.setTraversalMask(~0x1);
		viewer->getCamera()->accept(iv);
		if (intersector->containsIntersections()) {
			const osgUtil::LineSegmentIntersector::Intersection &result =
					*(intersector->getIntersections().begin());

			_f(result);
		}
	}
	return false;

}
}
