#ifndef NETWORK_HPP
#define NETWORK_HPP

#include <memory>
#include <vector>
namespace MinoUtils
{
namespace Network
{

	template<typename PackageType>
	class Listener
	{
		public:
			virtual void onPackage(PackageType m) = 0;
	};



	template<typename PackageType>
	class Emitter
	{
		typedef std::shared_ptr<Listener<PackageType>> ListenerPtr;
		public:
			void emit(PackageType m)
			{
				_listener->onPackage(m);
			}
			void setListener(Listener<PackageType> *listener)
			{
				_listener = ListenerPtr(listener);
			}
		private:
			ListenerPtr _listener;
	};

	template<typename PackageType>
	class Dispatcher : public Listener<PackageType>
	{
		typedef std::shared_ptr<Listener<PackageType>> ListenerPtr;
		public:
			void addListener(Listener<PackageType> *listener)
			{
				_listeners.push_back(ListenerPtr(listener));
			}

			void onPackage(PackageType m)
			{
				for(ListenerPtr listener : _listeners)
				{
					listener->onPackage(m);
				}
			}


		private:
			std::vector<ListenerPtr> _listeners;
	};



}
}

#endif /* NETWORK_HPP */
