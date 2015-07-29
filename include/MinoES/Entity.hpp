#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <MinoES/Component.hpp>
#include <memory>
#include <map>

namespace MinoES
{

    typedef std::shared_ptr<Component> CompPtr;
    typedef std::map<ComponentType, CompPtr> CompMap;

    class EntityListener;

    class Entity
    {
        public:

            void setListener(EntityListener *listener);

            void addComponent(Component *component);

            void removeComponentOfType(ComponentType type);

            Component* getComponent(ComponentType type);

        private:

            EntityListener* _listener;
            CompMap _typesToComponents;


    };

    class EntityListener
    {
        public:
            virtual void onComponentAdded
                (Entity* entity, Component* comp) = 0;

            virtual void onComponentRemoved
                (Entity* entity, Component* comp) = 0;
    };


}



#endif /* ENTITY_HPP */
