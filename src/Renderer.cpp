#include "Renderer.h"

Renderer* Renderer::m_sPInstance = nullptr;

SDL_Renderer* Renderer::GetRenderer() const
{
	return m_pRenderer;
}

Renderer::Renderer()
{
}

Renderer::~Renderer()
{
}
