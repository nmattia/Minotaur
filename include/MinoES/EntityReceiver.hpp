#ifndef ENTITYRECEIVER_HPP
#define ENTITYRECEIVER_HPP

#include <MinoES/Entity.hpp>
#include <MinoES/Component.hpp>
#include <set>

#define COMPONENTS( ... ) void initComponentTypeSet() \
{ _types = { __VA_ARGS__ }; }

namespace MinoES
{
    class EntityReceiver : public EntityListener
    {
        public:

            void onComponentAdded(Entity* entity, Component* comp);
            void onComponentRemoved(Entity* entity, 
                    Component* comp);
            virtual void initComponentTypeSet() = 0;

        protected:
            std::set<Entity*> _entities;
            std::set<ComponentType> _types;

            bool recognizeType(ComponentType type);
            bool accept(Entity* entity);
    };
}


#endif /* ENTITYRECEIVER_HPP */
