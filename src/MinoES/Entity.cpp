#include <MinoES/Entity.hpp>
namespace MinoES
{

	void Entity::setListener(EntityListener *listener)
	{
		_listener = listener;
	}

	void Entity::addComponent(Component *component)
	{
		std::shared_ptr<Component> ptr(component);
		_typesToComponents[component->getType()] = ptr;
		_listener->onComponentAdded(this, component);
	}

	void Entity::removeComponentOfType(ComponentType type)
	{
		Component* comp = getComponent(type);
		if(comp)
		{
			_typesToComponents.erase(type);
			_listener->onComponentRemoved(this, comp);
		}
		
	
	}

	Component* Entity::getComponent(ComponentType type)
	{ 

		CompMap::const_iterator pos = _typesToComponents.find(type);	
		if( pos == _typesToComponents.end())
		{
			return NULL;
		}
		return pos->second.get();
	}
}
