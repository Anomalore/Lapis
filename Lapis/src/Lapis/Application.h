#pragma once
#include "Core.h"

namespace Lapis 
{
	class LAPIS_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}
