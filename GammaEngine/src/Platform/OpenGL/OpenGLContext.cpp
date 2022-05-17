#include "gammaenginepch.h"
#include "OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <GL/GL.h>

namespace GammaEngine {

	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		: m_WindowHandle(windowHandle)
	{
		GAMMAENGINE_CORE_ASSERT(windowHandle, "Window handle is null!")
	}

	void OpenGLContext::Init()
	{
		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		GAMMAENGINE_CORE_ASSERT(status, "Failed to initialize Glad!");
		GAMMAENGINE_CORE_INFO("OpenGL Info:");
		GAMMAENGINE_CORE_INFO("  Vendor: {0}", glGetString(GL_VENDOR));
		GAMMAENGINE_CORE_INFO("  Renderer: {0}", glGetString(GL_RENDERER));
		GAMMAENGINE_CORE_INFO("  Version: {0}", glGetString(GL_VERSION));
	}

	void OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(m_WindowHandle);
	}

}