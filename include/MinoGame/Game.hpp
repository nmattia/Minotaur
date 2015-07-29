#ifndef GAME_HPP
#define GAME_HPP

#include <MinoThreads/Scheduler.hpp>
#include <MinoThreads/Process.hpp>
#include <MinoUtils/StateMachine.hpp>

namespace MinoGame
{
	// Could use pointer to connection to connect with state
	class Game : public MinoThreads::Scheduler,
			public MinoThreads::Process,
			public MinoUtils::StateMachine
	{
		public:
			void step();
			bool operator()(MinoUtils::Event e);

	};
}


#endif /* GAME_HPP */
