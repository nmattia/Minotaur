#ifndef CHRONOS_HPP
#define CHRONOS_HPP

#include <chrono>
#include <iostream>
namespace MinoUtils
{
namespace Chronos
{

	long millis();

	class Duration
	{

		public:
			virtual void update() = 0;
			virtual bool isOver() = 0;
	};

	template<int num, int den>
	class Seconds : public Duration
	{
		public:
			Seconds(long n)
				: _millis(n*num/den*1e3),
				_millisLeft(_millis),
				_lastSystemMillis(0){}

			void update()
			{
				long now = Chronos::millis();

				if(_lastSystemMillis)
				{
				//TODO Find new thread-safe way
					_millisLeft -= 
					now - _lastSystemMillis;
				}
				_lastSystemMillis = now;
			}

			bool isOver()
			{
			       bool wrapAround = false;
			       if(_millisLeft <= 0)
			       {
				       wrapAround = true;
				       _millisLeft += _millis;
			       }
			       
			       return wrapAround;
			}

		private:
			long _millis;
			long _lastSystemMillis;
			long _millisLeft;
	};

	class Ticks : public Duration
	{
		public:
			Ticks(int n) : _ticks(n), _ticksLeft(n){}

			void update() { _ticksLeft--; }
			bool isOver()
			{ 
				bool wrapAround = false;
				if(_ticksLeft <= 0)
				{
					wrapAround = true;
					_ticksLeft += _ticks;
				}
				return wrapAround;
			}

		private:
			int _ticks;
			int _ticksLeft;

	};

	class Frequency
	{
		public:
			Frequency(Duration *period): 
				_period(period){}
			int pullTicks()
			{
				_period->update();
				int ticks = 0;
				while(_period->isOver())
					ticks++;
				return ticks;
			}


		private:
			Duration* _period;

	};




}


}


#endif /* CHRONOS_HPP */
