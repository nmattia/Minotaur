#ifndef STATEMACHINE_HPP
#define STATEMACHINE_HPP

#include <string>
#include <vector>
#include <cassert>
#include <functional>
#include <initializer_list>

namespace MinoUtils
{

	typedef std::string Event;
	typedef std::function<void()> VoidFunc;
	typedef std::vector<VoidFunc> VoidVec;
	typedef std::function<bool()> BoolFunc;
	class StateMachine;
	class Transition
	{
		friend class StateMachine;
		public:
			Transition(Event event) : 
				_event(event){};

			Transition(Event event,
					std::function<bool()> condition,
				std::initializer_list<VoidFunc> actions):
				_event(event), _condition(condition),
				 _actions(actions){};



		private:
			Event _event;
			BoolFunc _condition;
			VoidVec _actions;
	};

	class State
	{
		friend class StateMachine;
		typedef std::pair<Transition, State*> ToState;
		public:
			void addTransitionToState(Transition t, State* s)
			{
				_transitionsToStates.push_back(
						ToState(t,s));
			};


		private:
			std::vector<ToState> _transitionsToStates;

	};

	class StateMachine
	{

		public:
			StateMachine() : _state(NULL){};
			void setState(State* state)
			{
				assert(!_state);
				_state = state;
			}

			virtual bool operator()(Event e);
			

		protected:
			State* _state;
	};

}



#endif /* STATEMACHINE_HPP */
