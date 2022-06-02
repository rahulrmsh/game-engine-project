#include <GammaEngine.h>
#include <GammaEngine/Core/EntryPoint.h>

#include "Sandbox2D.h"
#include "ExampleLayer.h"

class Sandbox : public GammaEngine::Application
{
public:
	Sandbox()
	{
		// PushLayer(new ExampleLayer());
		PushLayer(new Sandbox2D());
	}

	~Sandbox()
	{
	}
};

GammaEngine::Application* GammaEngine::CreateApplication()
{
	return new Sandbox();
}