#ifndef SCHEDULER_HPP
#define SCHEDULER_HPP

#include <MinoThreads/IProcess.hpp>
#include <list>



namespace MinoThreads
{
	class Scheduler
	{
		public:
			void attach(IProcess* p);
			void tick();

		protected:
			std::list<Proc_ptr> _procList;
	};
}


#endif /* SCHEDULER_HPP */
