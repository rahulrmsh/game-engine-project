#include "gammaenginepch.h"
#include "OpenGLVertexArray.h"

#include <glad/glad.h>

namespace GammaEngine {

	static GLenum ShaderDataTypeToOpenGLBaseType(ShaderDataType type)
	{
		switch (type)
		{
		case GammaEngine::ShaderDataType::Float:    return GL_FLOAT;
		case GammaEngine::ShaderDataType::Float2:   return GL_FLOAT;
		case GammaEngine::ShaderDataType::Float3:   return GL_FLOAT;
		case GammaEngine::ShaderDataType::Float4:   return GL_FLOAT;
		case GammaEngine::ShaderDataType::Mat3:     return GL_FLOAT;
		case GammaEngine::ShaderDataType::Mat4:     return GL_FLOAT;
		case GammaEngine::ShaderDataType::Int:      return GL_INT;
		case GammaEngine::ShaderDataType::Int2:     return GL_INT;
		case GammaEngine::ShaderDataType::Int3:     return GL_INT;
		case GammaEngine::ShaderDataType::Int4:     return GL_INT;
		case GammaEngine::ShaderDataType::Bool:     return GL_BOOL;
		}

		GAMMAENGINE_CORE_ASSERT(false, "Unknown ShaderDataType!");
		return 0;
	}

	OpenGLVertexArray::OpenGLVertexArray()
	{
		GAMMAENGINE_PROFILE_FUNCTION();
		glCreateVertexArrays(1, &m_RendererID);
	}

	OpenGLVertexArray::~OpenGLVertexArray()
	{
		GAMMAENGINE_PROFILE_FUNCTION();
		glDeleteVertexArrays(1, &m_RendererID);
	}

	void OpenGLVertexArray::Bind() const
	{
		GAMMAENGINE_PROFILE_FUNCTION();
		glBindVertexArray(m_RendererID);
	}

	void OpenGLVertexArray::Unbind() const
	{
		GAMMAENGINE_PROFILE_FUNCTION();
		glBindVertexArray(0);
	}

	void OpenGLVertexArray::AddVertexBuffer(const std::shared_ptr<VertexBuffer>& vertexBuffer)
	{
		GAMMAENGINE_PROFILE_FUNCTION();
		GAMMAENGINE_CORE_ASSERT(vertexBuffer->GetLayout().GetElements().size(), "Vertex Buffer has no layout!");

		glBindVertexArray(m_RendererID);
		vertexBuffer->Bind();

		uint32_t index = 0;
		const auto& layout = vertexBuffer->GetLayout();
		for (const auto& element : layout)
		{
			glEnableVertexAttribArray(m_VertexBufferIndex);
			glVertexAttribPointer(m_VertexBufferIndex,
				element.GetComponentCount(),
				ShaderDataTypeToOpenGLBaseType(element.Type),
				element.Normalized ? GL_TRUE : GL_FALSE,
				layout.GetStride(),
				(const void*)element.Offset);
			m_VertexBufferIndex++;
		}
		m_VertexBuffers.push_back(vertexBuffer);
		m_VertexBufferIndexOffset += layout.GetElements().size();
	}

	void OpenGLVertexArray::SetIndexBuffer(const std::shared_ptr<IndexBuffer>& indexBuffer)
	{
		GAMMAENGINE_PROFILE_FUNCTION();
		glBindVertexArray(m_RendererID);
		indexBuffer->Bind();

		m_IndexBuffer = indexBuffer;
	}

}