#pragma once

#include "Core.h"
#include "Events/Event.h"

namespace GammaEngine {

	class GAMMAENGINE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	Application* CreateApplication();

}
