#pragma once
#ifndef __GAME__
#define __GAME__

#include <SDL.h>

#include "Renderer.h"
#include "Vector2.h"
#include <basetsd.h>

/* Game Singleton */
class Game
{
public:
	static Game* Instance()
	{
		if(m_sPInstance == nullptr)
		{
			m_sPInstance = new Game();
			return m_sPInstance;
		}
		return m_sPInstance;
	}

	// public Life Cycle functions
	void Render();
	void Update();
	void HandleEvents();
	void Clean();
	void Init();
	bool IsRunning() const;
	void Quit();

	bool Init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

	// Getters and Setters
	Vector2 GetMousePosition();
	void SetFrames(UINT32 frames);
	UINT32 GetFrames();
	
private:
	Game();
	~Game();

	void Start();

	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;
	
	UINT32 m_frames;

	Vector2 m_mousePosition;
	int m_currentFrame;

	static Game* m_sPInstance;

	bool m_bRunning;
};

#endif /* defined (__GAME__) */

