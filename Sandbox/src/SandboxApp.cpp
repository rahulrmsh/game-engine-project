#include "GammaEngine.h"

class ExampleLayer : public GammaEngine::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		GAMMAENGINE_CLIENT_INFO("ExampleLayer::Update");
	}

	void OnEvent(GammaEngine::Event& event) override
	{
		GAMMAENGINE_CLIENT_TRACE("{0}", event);
	}

};

class Sandbox : public GammaEngine::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}

	~Sandbox()
	{

	}
};

GammaEngine::Application* GammaEngine::CreateApplication()
{
	return new Sandbox();
}