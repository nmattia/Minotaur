#include <MinoES/EntityReceiver.hpp>
#include <string>
#include <iostream>
#define CHECK_TYPES() if(_types.empty()) initComponentTypeSet();


namespace MinoES
{

	void EntityReceiver::onComponentAdded
		(Entity* entity, Component* comp)
	{
		CHECK_TYPES()

		std::cout << " There we go... " << std::endl;

		if(!recognizeType(comp->getType()))
			return;

		std::cout << "Type recognized : " << comp->getType() << std::endl;

		if(accept(entity))
			_entities.insert(entity);


	}

	void EntityReceiver::onComponentRemoved
		(Entity* entity, Component* comp)
	{
		CHECK_TYPES()
		if(!recognizeType(comp->getType()))
			return;

		if(!accept(entity))
			_entities.erase(_entities.find(entity));



	}

	bool EntityReceiver::recognizeType(ComponentType type)
	{
		for ( std::string type : _types)
			std::cout << type << std::endl;
		std::set<ComponentType>::iterator it = _types.find(type);
		if(it == _types.end())
			return false;


		return true;
	}

	bool EntityReceiver::accept(Entity* entity)
	{
		for(ComponentType type : _types)
		{
			if(!entity->getComponent(type))
				return false;
		}

		std::cout << " entity accepted " << std::endl;
		return true;
	}
}

