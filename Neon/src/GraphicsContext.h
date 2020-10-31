#pragma once

#include <string>
namespace Neon
{
	class Window;
	class GraphicsContext
	{
	public:
		virtual void InitContext() = 0;
		virtual std::string ToString() = 0;
	protected:
	};

	class OpenGLContext : public GraphicsContext
	{
	public:
		OpenGLContext();

		virtual void InitContext();

		virtual std::string ToString();
	};

}