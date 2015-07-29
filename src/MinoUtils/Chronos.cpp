#include <MinoUtils/Chronos.hpp>

namespace MinoUtils
{
	namespace Chronos
	{
		long millis()
		{
			using namespace std::chrono;
			return duration_cast< milliseconds >
				(high_resolution_clock::now()
				 .time_since_epoch()).count();
		}
	}
}

