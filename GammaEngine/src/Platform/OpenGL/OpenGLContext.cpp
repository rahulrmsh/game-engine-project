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
		GAMMAENGINE_PROFILE_FUNCTION();
		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		GAMMAENGINE_CORE_ASSERT(status, "Failed to initialize Glad!");
		GAMMAENGINE_CORE_INFO("OpenGL Info:");
		GAMMAENGINE_CORE_INFO("  Vendor: {0}", glGetString(GL_VENDOR));
		GAMMAENGINE_CORE_INFO("  Renderer: {0}", glGetString(GL_RENDERER));
		GAMMAENGINE_CORE_INFO("  Version: {0}", glGetString(GL_VERSION)); 
		#ifdef GAMMAENGINE_ENABLE_ASSERTS
				int versionMajor;
				int versionMinor;
				glGetIntegerv(GL_MAJOR_VERSION, &versionMajor);
				glGetIntegerv(GL_MINOR_VERSION, &versionMinor);
				GAMMAENGINE_CORE_ASSERT(versionMajor > 4 || (versionMajor == 4 && versionMinor >= 5), "GammaEngine requires at least OpenGL version 4.5!");
		#endif
	}

	void OpenGLContext::SwapBuffers()
	{
		GAMMAENGINE_PROFILE_FUNCTION();
		glfwSwapBuffers(m_WindowHandle);
	}

}