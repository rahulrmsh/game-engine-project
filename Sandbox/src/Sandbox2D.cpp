#include "Sandbox2D.h"
#include <imgui.h>

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

Sandbox2D::Sandbox2D()
	: Layer("Sandbox2D"), m_CameraController(1280.0f / 720.0f)
{
}

void Sandbox2D::OnAttach()
{
	GAMMAENGINE_PROFILE_FUNCTION();
	m_CheckerboardTexture = GammaEngine::Texture2D::Create("assets/textures/Checkerboard.png");
}

void Sandbox2D::OnDetach()
{
	GAMMAENGINE_PROFILE_FUNCTION();
}

void Sandbox2D::OnUpdate(GammaEngine::Timestep ts)
{
	GAMMAENGINE_PROFILE_FUNCTION();

	m_CameraController.OnUpdate(ts);
	// Render
	{
		GAMMAENGINE_PROFILE_SCOPE("Renderer Prep");
		GammaEngine::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
		GammaEngine::RenderCommand::Clear();
	}

	{
		GAMMAENGINE_PROFILE_SCOPE("Renderer Draw");
		GammaEngine::Renderer2D::BeginScene(m_CameraController.GetCamera());
		GammaEngine::Renderer2D::DrawQuad({ -1.0f, 0.0f }, { 0.8f, 0.8f }, { 0.8f, 0.2f, 0.3f, 1.0f });
		GammaEngine::Renderer2D::DrawQuad({ 0.5f, -0.5f }, { 0.5f, 0.75f }, { 0.2f, 0.3f, 0.8f, 1.0f });
		GammaEngine::Renderer2D::DrawQuad({ 0.0f, 0.0f, -0.1f }, { 10.0f, 10.0f }, m_CheckerboardTexture);
		GammaEngine::Renderer2D::EndScene();
	}
}

void Sandbox2D::OnImGuiRender()
{
	GAMMAENGINE_PROFILE_FUNCTION();

	ImGui::Begin("Settings");
	ImGui::ColorEdit4("Square Color", glm::value_ptr(m_SquareColor));
	ImGui::End();
}

void Sandbox2D::OnEvent(GammaEngine::Event& e)
{
	m_CameraController.OnEvent(e);
}