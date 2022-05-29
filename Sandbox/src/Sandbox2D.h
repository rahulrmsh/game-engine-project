#pragma once

#include "GammaEngine.h"

class Sandbox2D : public GammaEngine::Layer
{
public:
	Sandbox2D();
	virtual ~Sandbox2D() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;

	void OnUpdate(GammaEngine::Timestep ts) override;
	virtual void OnImGuiRender() override;
	void OnEvent(GammaEngine::Event& e) override;
private:
	GammaEngine::OrthographicCameraController m_CameraController;

	// Temp
	GammaEngine::Ref<GammaEngine::VertexArray> m_SquareVA;
	GammaEngine::Ref<GammaEngine::Shader> m_FlatColorShader;
	GammaEngine::Ref<GammaEngine::Texture2D> m_CheckerboardTexture;
	glm::vec4 m_SquareColor = { 0.2f, 0.3f, 0.8f, 1.0f };
};