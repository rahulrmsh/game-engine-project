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
#include "GammaEngine/Renderer/VertexArray.h"

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
		std::shared_ptr<Shader> m_Shader;
		std::shared_ptr<VertexArray> m_VertexArray;
		std::shared_ptr<Shader> m_BlueShader;
		std::shared_ptr<VertexArray> m_SquareVA;
		static Application* s_Instance;
	};

	Application* CreateApplication();

}
