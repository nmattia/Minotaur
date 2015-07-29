#ifndef SINGLETON_HPP
#define SINGLETON_HPP

#include <cassert>
#include <utility>

namespace MinoUtils {


template <class T> class Singleton {


	private:
		static T* s_instance;

	public:
	
		template <typename... Args> static T& create(Args... args){
			assert(!s_instance);
			s_instance = new T(std::forward<Args>(args)...);
			return getInstance();	
		}

		static T& getInstance(){
			assert(s_instance);
			return *s_instance;
		}

		static T* getInstancePtr(){
			return s_instance;
		}

};

template <class T> T* Singleton<T>::s_instance = 0;

}

#endif /* SINGLETON_HPP */
