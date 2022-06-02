#pragma once

#include "GammaEngine.h"

class ExampleLayer : public GammaEngine::Layer
{
public:
	ExampleLayer();
	virtual ~ExampleLayer() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;

	void OnUpdate(GammaEngine::Timestep ts) override;
	virtual void OnImGuiRender() override;
	void OnEvent(GammaEngine::Event& e) override;
private:
	GammaEngine::ShaderLibrary m_ShaderLibrary;
	GammaEngine::Ref<GammaEngine::Shader> m_Shader;
	GammaEngine::Ref<GammaEngine::VertexArray> m_VertexArray;

	GammaEngine::Ref<GammaEngine::Shader> m_FlatColorShader;
	GammaEngine::Ref<GammaEngine::VertexArray> m_SquareVA;

	GammaEngine::Ref<GammaEngine::Texture2D> m_Texture, m_ChernoLogoTexture;

	GammaEngine::OrthographicCameraController m_CameraController;
	glm::vec3 m_SquareColor = { 0.2f, 0.3f, 0.8f };
};
