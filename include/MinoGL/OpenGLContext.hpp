#ifndef OPENGLCONTEXT_HPP
#define OPENGLCONTEXT_HPP

#include <MinoThreads/Scheduler.hpp>
#include <MinoUtils/Singleton.hpp>

namespace MinoGL
{
	class OpenGLContext : public MinoThreads::Scheduler,
		public MinoUtils::Singleton<OpenGLContext>
	{

	};
}
		

#endif /* OPENGLCONTEXT_HPP */
