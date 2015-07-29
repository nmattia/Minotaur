#ifndef TASK_HPP
#define TASK_HPP

#include <MinoUtils/Chronos.hpp>
#include <MinoThreads/Process.hpp>
#include <memory>

namespace MinoThreads
{
	using namespace MinoUtils::Chronos;
	typedef std::shared_ptr<MinoUtils::Chronos::Frequency> Freq_ptr; 
	typedef std::shared_ptr<MinoUtils::Chronos::Duration> Dur_ptr;
	class Task : public Process
	{
		public:
			Task(IProcess *p) : _p(p){};
			void step();

			void setFrequency(MinoUtils::Chronos::Frequency *freq)
			{
				_freq = Freq_ptr(freq);
				
			};
			void setDuration(MinoUtils::Chronos::Duration *duration)
			{
				_duration = Dur_ptr(duration);
			};
		
		private:
			Proc_ptr _p;
			Freq_ptr _freq;
			Dur_ptr _duration;
			



	};
}


#endif /* TASK_HPP */
