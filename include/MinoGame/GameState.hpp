#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include <MinoUtils/StateMachine.hpp>
#include <MinoThreads/Scheduler.hpp>
#include <MinoES/EntityDispatcher.hpp>
#include <boost/signals2.hpp>

namespace MinoGame
{
	typedef boost::signals2::signal<bool (MinoUtils::Event)> Signal;
	class GameState : public MinoUtils::State,
			public MinoThreads::Scheduler,
			public Signal,
			public MinoES::EntityDispatcher
	{};
}


#endif /* GAMESTATE_HPP */
