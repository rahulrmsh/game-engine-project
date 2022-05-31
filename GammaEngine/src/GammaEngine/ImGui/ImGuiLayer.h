#pragma once

#include "GammaEngine/Core/Layer.h"
#include "GammaEngine/Events/ApplicationEvent.h"
#include "GammaEngine/Events/KeyEvent.h"
#include "GammaEngine/Events/MouseEvent.h"

namespace GammaEngine {

	class GAMMAENGINE_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;

		void Begin();
		void End();
	private:
		float m_Time = 0.0f;
	};

}