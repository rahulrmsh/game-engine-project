#pragma once


#ifndef GAME_PLATFORM_WINDOWS

 extern Game::Application* Game::CreateApplication();

int main(int argc ,char** argv)
{
	Game::Log::Init();
	Game::Log::GetCoreLogger()->warn("initialized log !");
	Game::Log::GetClientLogger()->info("Hello sxxa");
	

	auto app = Game::CreateApplication();
	app->Run();
	
	
}

#endif // PLATFORM_WINDOWS


