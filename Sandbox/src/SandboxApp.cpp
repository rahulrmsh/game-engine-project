#include "GammaEngine.h"

class Sandbox : public GammaEngine::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

GammaEngine::Application* GammaEngine::CreateApplication()
{
	return new Sandbox();
}