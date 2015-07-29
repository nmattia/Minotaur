#ifndef FACTORY_HPP
#define FACTORY_HPP

namespace MinoUtils
{
	template <class T> class Factory 
	{
		public:
			template <typename... Args> static T& create(Args... args)
			{
				return new T(std::forward<Args>(args)...);
			}
	}
}


#endif /* FACTORY_HPP */
