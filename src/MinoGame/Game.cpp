#include <MinoUtils/Chronos.hpp>
#include <MinoGame/Game.hpp>
#include <MinoGame/GameState.hpp>

namespace MinoGame
{


	void Game::step()
	{
		GameState* gameState = static_cast<GameState*>(_state);
		if(!gameState)
			return;
		gameState->tick();
	}

	bool Game::operator()(MinoUtils::Event e)
	{
		std::cout << "Game received event!" << std::endl;

		if(StateMachine::operator()(e))
			return true;
		else
		{
			std::cout << "Forwarding to state!" << std::endl;
			GameState* gameState = 
				static_cast<GameState*>(_state);
			if(!gameState)
				return false;
			return (*gameState)(e);
		};

		return false;
	}

}
