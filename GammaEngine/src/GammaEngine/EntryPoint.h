#pragma once

#ifdef GAMMAENGINE_PLATFORM_WINDOWS

	extern GammaEngine::Application* GammaEngine::CreateApplication();

	int main(int argc, char** argv)
	{
		auto app = GammaEngine::CreateApplication();
		app->Run();
		delete app;
	}

#else
	#error Gamma Engine only supports Windows!!!
#endif // GAMMAENGINE_PLATFORM_WINDOWS
