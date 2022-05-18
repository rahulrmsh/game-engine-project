#include "gammaenginepch.h"
#include "RenderCommand.h"

#include "Platform/OpenGL/OpenGLRendererAPI.h"

namespace GammaEngine {

	RendererAPI* RenderCommand::s_RendererAPI = new OpenGLRendererAPI;

}