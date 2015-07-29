#ifndef ENTITYLISTENER_HPP
#define ENTITYLISTENER_HPP

//#include <MinoES/Entity.hpp>

namespace MinoES
{
    class Entity;
    class EntityListener
    {
        virtual void onComponentAdded
            (Entity* entity, Component* comp) = 0;

        virtual void onComponentRemoved
            (Entity* entity, Component* comp) = 0;
    };
}


#endif /* ENTITYLISTENER_HPP */
