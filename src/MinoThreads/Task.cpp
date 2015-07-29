#include <MinoThreads/Task.hpp>

namespace MinoThreads
{

	void Task::step()
	{
		if(_duration)
			_duration->update();
		int n = _freq->pullTicks();
		for(int i = 0; i < n; i++)
			_p->step();
		if( _p->isDead() ||
				(_duration && _duration->isOver()))
		{

			_isDead = true;
		}
	}






}

