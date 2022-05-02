#pragma once

#include "Core.h"
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
