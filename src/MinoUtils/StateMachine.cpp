#include <MinoUtils/StateMachine.hpp>

namespace MinoUtils
{

	bool StateMachine::operator()(Event e)
	{
		assert(_state);
		for(State::ToState ts : 
			_state->_transitionsToStates)
		{

			if(ts.first._event == e)
			{

				if(ts.first._condition
						&& !ts.first._condition())
					return false;

				for(VoidFunc func : ts.first._actions)
					func();

				_state = ts.second;
				return true;
			}
		}

		return false;
	}
}
