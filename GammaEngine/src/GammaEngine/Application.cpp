#include "Application.h"
#include "Log.h"
#include "Events/ApplicationEvent.h"

namespace GammaEngine {
	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			GAMMAENGINE_CORE_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			GAMMAENGINE_CORE_TRACE(e);
		}

		while (true);
	}
}