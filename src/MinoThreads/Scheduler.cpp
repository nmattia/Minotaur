#include <MinoThreads/Scheduler.hpp>

namespace MinoThreads
{
	void Scheduler::attach(IProcess* p)
	{
		Proc_ptr proc(p);
		_procList.push_back(proc);
	}


	void Scheduler::tick()
	{
		std::list<Proc_ptr>::iterator it = _procList.begin();


		while(it != _procList.end())
		{

			(*it)->step();
			if((*it)->isDead())
			{
				it = _procList.erase(it);
			}
			else
				it++;
		}
	}

}
