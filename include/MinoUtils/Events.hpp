#ifndef EVENTS_HPP
#define EVENTS_HPP

#include <string>
#include <regex>

#include <MinoUtils/Network.hpp>

namespace MinoUtils
{
namespace Events
{

	typedef std::string HeaderType;

	template<typename BodyType>
	class Event
	{
		public:
			HeaderType header;
			BodyType body;
	};


	template<typename EventType>
	class Filter : public Network::Emitter<EventType>,
			public Network::Listener<EventType>
	{

		public:
			void setPattern(std::string rgx)
			{
				_rgx(rgx);
			}

			void onPackage(EventType e)
			{
				if(std::regex_match(e.header, _rgx))
					emit(e);
			}

		private:
			std::regex _rgx;


	};

}
}

#endif /* EVENTS_HPP */
