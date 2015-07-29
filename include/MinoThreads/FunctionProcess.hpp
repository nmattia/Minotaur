#ifndef FUNCTIONPROCESS_HPP
#define FUNCTIONPROCESS_HPP

#include <MinoThreads/Process.hpp>
#include <utility>
#include <functional>

namespace MinoThreads
{
	template <typename... T> class FunctionProcess : public Process
	{		
		public:
			using BindingType = decltype(std::bind(std::declval<std::function<bool(T...)>>(),
						std::declval<T>()...));
			
			template <typename... K> FunctionProcess(std::function<bool(T...)> func,
					K&&... args) : _bindedFunc(func,std::forward<K>(args)...)
			{}

			void step()
			{
				_isDead = _bindedFunc();
			}
		private:
			BindingType _bindedFunc;


	};
}


#endif /* FUNCTIONPROCESS_HPP */
