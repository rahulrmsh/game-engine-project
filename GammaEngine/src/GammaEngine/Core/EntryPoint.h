#pragma once

#ifdef GAMMAENGINE_PLATFORM_WINDOWS

	extern GammaEngine::Application* GammaEngine::CreateApplication();

	int main(int argc, char** argv)
	{
		GammaEngine::Log::Init();

		GAMMAENGINE_PROFILE_BEGIN_SESSION("Startup", "GammaEngineProfile-Startup.json");
		auto app = GammaEngine::CreateApplication();
		GAMMAENGINE_PROFILE_END_SESSION();

		GAMMAENGINE_PROFILE_BEGIN_SESSION("Runtime", "GammaEngineProfile-Runtime.json");
		app->Run();
		GAMMAENGINE_PROFILE_END_SESSION();

		GAMMAENGINE_PROFILE_BEGIN_SESSION("Startup", "GammaEngineProfile-Shutdown.json");
		delete app;
		GAMMAENGINE_PROFILE_END_SESSION();
	}

#else
	#error Gamma Engine only supports Windows!!!
#endif // GAMMAENGINE_PLATFORM_WINDOWS
