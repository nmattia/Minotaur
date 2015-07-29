#ifndef ENTITYDISPATCHER_HPP
#define ENTITYDISPATCHER_HPP

#include <vector>
#include <memory>
#include <MinoES/Entity.hpp>

namespace MinoES
{

    typedef std::shared_ptr<EntityListener> ListenerPtr;

    class EntityDispatcher : public EntityListener 
    {
        public:

            void addEntity(Entity* entity);

            void onComponentAdded
                (Entity* entity, Component* comp);

            void onComponentRemoved
                (Entity* entity, Component* comp);

            void addListener(EntityListener* listener);

        private:
            std::vector<ListenerPtr> _listeners;


    };
}


#endif /* ENTITYDISPATCHER_HPP */
