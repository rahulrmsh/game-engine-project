#pragma once


#ifndef GAME_PLATFORM_WINDOWS

extern Game::Application* Game::CreateApplication();

int main(int argc ,char** argv)
{
	printf("hello");
	auto app = Game::CreateApplication();
	app->Run();
	
	return 0;
}

#endif // PLATFORM_WINDOWS


