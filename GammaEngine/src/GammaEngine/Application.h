#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Window.h"
#include "GammaEngine/Events/ApplicationEvent.h"
#include "GammaEngine/LayerStack.h"
#include "GammaEngine/Events/Event.h"
#include "GammaEngine/Events/ApplicationEvent.h"
#include "GammaEngine/ImGui/ImGuiLayer.h"
#include "GammaEngine/Core/Timestep.h"

namespace GammaEngine {

	class Application
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
		bool OnWindowResize(WindowResizeEvent& e);
		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		bool m_Minimized = false;
		LayerStack m_LayerStack;
		
		static Application* s_Instance;
		float m_LastFrameTime = 0.0f;
	};

	Application* CreateApplication();

}
