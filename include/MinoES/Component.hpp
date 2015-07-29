#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include <string>

#define NAME(name) std::string getType(){ return name;}

namespace MinoES
{
    typedef std::string ComponentType;
    class Component
    {
        public:
            virtual ComponentType getType() = 0;
    };

}


#endif /* COMPONENT_HPP */
