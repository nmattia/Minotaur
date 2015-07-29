#ifndef NAMEDCLASS_CPP
#define NAMEDCLASS_CPP

#include <string>

#define NAME(name) std::string getName(){ return name;}

namespace MinoUtils
{
	class NamedClass
	{
		public:
			virtual std::string getName() = 0;
	};

}


#endif /* NAMEDCLASS_CPP */
