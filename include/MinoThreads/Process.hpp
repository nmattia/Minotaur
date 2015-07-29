#ifndef PROCESS_HPP
#define PROCESS_HPP

#include <MinoThreads/IProcess.hpp>

namespace MinoThreads
{
	class Process : public IProcess
	{

		public:
			Process() : _isDead(false){};
			virtual void step() = 0;

			bool isDead();

		protected:
			bool _isDead;
	};
}

#endif /* PROCESS_HPP */
