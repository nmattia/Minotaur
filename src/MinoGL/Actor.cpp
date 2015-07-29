#include <MinoGL/Actor.hpp>

Actor::Actor(){

}

Actor::~Actor(){

}

void Actor::setTransform(float x, float y, float z, 
		float rx, float ry, float rz){

	osg::Vec3d pos(x,y,z);
	osg::Quat att;
	att.makeRotate(rx - M_PI/2.0, osg::X_AXIS, 
			ry, osg::Y_AXIS, rz, osg::Z_AXIS);

	_transform->setPosition(pos);
	_transform->setAttitude(att);


}

