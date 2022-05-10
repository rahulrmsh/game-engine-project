#include "GammaEngine.h"
#include "imgui.h"

class ExampleLayer : public GammaEngine::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		if (GammaEngine::Input::IsKeyPressed(GAMMAENGINE_KEY_TAB))
			GAMMAENGINE_CLIENT_TRACE("Tab key is pressed (poll)!");
	}

	virtual void OnImGuiRender() override
	{
		ImGui::Begin("Test");
		ImGui::Text("Hello World");
		ImGui::End();
	}

	void OnEvent(GammaEngine::Event& event) override
	{
		if (event.GetEventType() == GammaEngine::EventType::KeyPressed)
		{
			GammaEngine::KeyPressedEvent& e = (GammaEngine::KeyPressedEvent&)event;
			if (e.GetKeyCode() == GAMMAENGINE_KEY_TAB)
				GAMMAENGINE_CLIENT_TRACE("Tab key is pressed (event)!");
			GAMMAENGINE_CLIENT_TRACE("{0}", (char)e.GetKeyCode());
		}
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