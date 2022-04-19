#pragma once

#include "Core.h"
namespace Game {

	class Game_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	Application* CreateApplication();
}