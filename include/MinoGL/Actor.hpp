#ifndef ACTOR_HPP
#define ACTOR_HPP

#include <osg/ref_ptr>
#include <osg/Node>
#include <osg/PositionAttitudeTransform>
class Actor{
	public:
	
	Actor();
	~Actor();

	osg::ref_ptr<osg::Node> _model;
	osg::ref_ptr<osg::PositionAttitudeTransform> _transform;





	void setTransform(float x, float y, float z,
			float rx, float ry, float rz);
	private:
	
};

#endif
