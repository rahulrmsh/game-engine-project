#include "gammaenginepch.h"
#include "GammaEngine/Renderer/GraphicsContext.h"

#include "GammaEngine/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLContext.h"

namespace GammaEngine {

	Scope<GraphicsContext> GraphicsContext::Create(void* window)
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::None:    GAMMAENGINE_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
			case RendererAPI::API::OpenGL:  return CreateScope<OpenGLContext>(static_cast<GLFWwindow*>(window));
		}

		GAMMAENGINE_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

}