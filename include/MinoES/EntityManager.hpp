#ifndef ENTITYMANAGER_HPP
#define ENTITYMANAGER_HPP

#include <MinoES/Entity.hpp>

namespace MinoES
{
    class EntityManager : public EntityDispatcher
    {
        public:
            Entity createEntity();
            void addComponentToEntity(int entityID, Component* component);
            Component* getComponentOfEntity(int entityID, ComponentType type);




    };
}


#endif /* ENTITYMANAGER_HPP */
