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
#include "GammaEngine/Renderer/Buffer.h"

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
		unsigned int m_VertexArray;
		std::unique_ptr<Shader> m_Shader;
		std::unique_ptr<VertexBuffer> m_VertexBuffer;
		std::unique_ptr<IndexBuffer> m_IndexBuffer;
		static Application* s_Instance;
	};

	Application* CreateApplication();

}
