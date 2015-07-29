#ifndef IPROCESS_HPP
#define IPROCESS_HPP

#include <memory>


namespace MinoThreads
{
	class IProcess
	{
		public:
			virtual void step() = 0;
			virtual bool isDead() = 0;

	};
	

	typedef std::shared_ptr<IProcess> Proc_ptr;
}


#endif /* IPROCESS_HPP */
