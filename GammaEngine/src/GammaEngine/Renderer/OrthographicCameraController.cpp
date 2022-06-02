#include "gammaenginepch.h"
#include "OrthographicCameraController.h"
#include "GammaEngine/Core/Input.h"
#include "GammaEngine/Core/KeyCodes.h"

namespace GammaEngine {
	OrthographicCameraController::OrthographicCameraController(float aspectRatio,float rotation)
		:m_AspectRatio(aspectRatio), m_Bounds({ -m_AspectRatio * m_ZoomLevel, m_AspectRatio * m_ZoomLevel, -m_ZoomLevel, m_ZoomLevel }), m_Camera(m_Bounds.Left, m_Bounds.Right, m_Bounds.Bottom, m_Bounds.Top), m_Rotation(rotation)
	{

	}
	
	void OrthographicCameraController::OnUpdate(Timestep ts)
	{
		GAMMAENGINE_PROFILE_FUNCTION();
		if (Input::IsKeyPressed(GAMMAENGINE_KEY_A))
		{
			m_CameraPosition.x -= cos(glm::radians(m_CameraRotation)) * m_CameraTranslationSpeed * ts;
			m_CameraPosition.y -= sin(glm::radians(m_CameraRotation)) * m_CameraTranslationSpeed * ts;
		}
		else if (Input::IsKeyPressed(GAMMAENGINE_KEY_D))
		{
			m_CameraPosition.x += cos(glm::radians(m_CameraRotation)) * m_CameraTranslationSpeed * ts;
			m_CameraPosition.y += sin(glm::radians(m_CameraRotation)) * m_CameraTranslationSpeed * ts;
		}

		if (Input::IsKeyPressed(GAMMAENGINE_KEY_W))
		{
			m_CameraPosition.x += -sin(glm::radians(m_CameraRotation)) * m_CameraTranslationSpeed * ts;
			m_CameraPosition.y += cos(glm::radians(m_CameraRotation)) * m_CameraTranslationSpeed * ts;
		}
		else if (Input::IsKeyPressed(GAMMAENGINE_KEY_S))
		{
			m_CameraPosition.x -= -sin(glm::radians(m_CameraRotation)) * m_CameraTranslationSpeed * ts;
			m_CameraPosition.y -= cos(glm::radians(m_CameraRotation)) * m_CameraTranslationSpeed * ts;
		}
		
			if (Input::IsKeyPressed(GAMMAENGINE_KEY_Q))
				m_CameraRotation += m_CameraRotationSpeed * ts;
			if (Input::IsKeyPressed(GAMMAENGINE_KEY_E))
				m_CameraRotation -= m_CameraRotationSpeed * ts;
			if (m_CameraRotation > 180.0f)
				m_CameraRotation -= 360.0f;
			else if (m_CameraRotation <= -180.0f)
				m_CameraRotation += 360.0f;
			m_Camera.SetRotation(m_CameraRotation);
		
		m_Camera.SetPosition(m_CameraPosition);
		m_CameraTranslationSpeed = m_ZoomLevel;
		
	}

	void OrthographicCameraController::OnEvent(Event& e)
	{
		GAMMAENGINE_PROFILE_FUNCTION();
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<MouseScrolledEvent>(GAMMAENGINE_BIND_EVENT_FN(OrthographicCameraController::OnMouseScrolled));
		dispatcher.Dispatch<WindowResizeEvent>(GAMMAENGINE_BIND_EVENT_FN(OrthographicCameraController::OnWindowResized));
		
	}

	bool OrthographicCameraController::OnMouseScrolled(MouseScrolledEvent& e)
	{
		m_ZoomLevel -= e.GetYOffset() * 0.5f;
		m_ZoomLevel = std::max(m_ZoomLevel, 0.25f);
		
		m_Bounds = { -m_AspectRatio * m_ZoomLevel, m_AspectRatio * m_ZoomLevel, -m_ZoomLevel, m_ZoomLevel };
		m_Camera.setProjection(m_Bounds.Left, m_Bounds.Right, m_Bounds.Bottom, m_Bounds.Top);
		return false;
	}

	bool OrthographicCameraController::OnWindowResized(WindowResizeEvent& e)
	{
		GAMMAENGINE_PROFILE_FUNCTION();
		m_AspectRatio -= (float)e.GetWidth() /(float) e.GetHeight();
		m_Bounds = { -m_AspectRatio * m_ZoomLevel, m_AspectRatio * m_ZoomLevel, -m_ZoomLevel, m_ZoomLevel };
		m_Camera.setProjection(m_Bounds.Left, m_Bounds.Right, m_Bounds.Bottom, m_Bounds.Top);
		return false;
	}
}

