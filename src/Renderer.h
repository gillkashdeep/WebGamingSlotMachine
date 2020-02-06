#pragma once
#ifndef __RENDERER__
#define __RENDERER__

#include <SDL.h>

/* Renderer Singleton */
class Renderer
{
public:
	static Renderer* Instance()
	{
		if(m_sPInstance == nullptr)
		{
			m_sPInstance = new Renderer();
			return  m_sPInstance;
		}
		return m_sPInstance;
	}

	SDL_Renderer* GetRenderer() const;

	
private:
	Renderer();
	~Renderer();

	static Renderer* m_sPInstance;
	SDL_Renderer* m_pRenderer;
};
#endif /* defined (__RENDERER__)*/