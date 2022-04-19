
#include<Game.h>

class Sandbox : public Game::Application
{
public:
	Sandbox()
	{

	}
	~Sandbox()
	{

	}
};
Game::Application* Game::CreateApplication()
{
	return new Sandbox();
	
}