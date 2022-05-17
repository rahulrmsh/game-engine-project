#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Window.h"
#include "GammaEngine/Events/ApplicationEvent.h"
#include "GammaEngine/LayerStack.h"
#include "GammaEngine/Events/Event.h"
#include "GammaEngine/Events/ApplicationEvent.h"
#include "GammaEngine/ImGui/ImGuiLayer.h"
#include "GammaEngine/Renderer/Shader.h"
namespace GammaEngine {

	class GAMMAENGINE_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();
		void OnEvent(Event& e);
		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);
		inline Window& GetWindow() { return *m_Window; }
		inline static Application& Get() { return *s_Instance; }

	private:
		bool OnWindowClose(WindowCloseEvent& e);
		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		LayerStack m_LayerStack;
		unsigned int m_VertexArray, m_VertexBuffer, m_IndexBuffer;
		std::unique_ptr<Shader> m_Shader;
		static Application* s_Instance;
	};

	Application* CreateApplication();

}
