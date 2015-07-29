#include <MinoES/EntityDispatcher.hpp>

namespace MinoES
{
	void EntityDispatcher::addEntity(Entity* entity)
	{
		entity->setListener(this);
	}

	void EntityDispatcher::onComponentAdded(Entity* entity, 
			Component* comp)
	{

		for(ListenerPtr listener : _listeners)
			listener->onComponentAdded(entity, comp);

	}


	void EntityDispatcher::onComponentRemoved(Entity* entity, Component* comp)
	{

		for(ListenerPtr listener : _listeners)
			listener->onComponentRemoved(entity, comp);

	}

	void EntityDispatcher::addListener(EntityListener* listener)
	{
		ListenerPtr ptr(listener);
		_listeners.push_back(ptr);
	}
}
