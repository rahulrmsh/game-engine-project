#pragma once

#include "GammaEngine/Core.h"
#include "GammaEngine/Core/Timestep.h"
#include "GammaEngine/Events/Event.h"

namespace GammaEngine {

	class GAMMAENGINE_API Layer
	{
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer();

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate(Timestep ts) {}
		virtual void OnImGuiRender() {}
		virtual void OnEvent(Event& event) {}

		inline const std::string& GetName() const { return m_DebugName; }
	protected:
		std::string m_DebugName;
	};

}