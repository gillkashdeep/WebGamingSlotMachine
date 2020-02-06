#include "Game.h"
#include <ctime>
#include <iostream>

Game* Game::m_sPInstance = nullptr;

void Game::Render()
{
	SDL_RenderClear(m_pRenderer); // clear the renderer to the draw colour

	//m_currentScene->draw();

	SDL_RenderPresent(m_pRenderer); // draw to the screen
}

void Game::Update()
{
}

void Game::HandleEvents()
{
	//m_currentScene->handleEvents();

	SDL_Event event;
	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			m_bRunning = false;
			break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				m_bRunning = false;
				break;
			}
			break;
		default:
			break;
		}
	}
}

void Game::Clean()
{
	std::cout << "cleaning game" << std::endl;

	SDL_DestroyRenderer(m_pRenderer);
	SDL_DestroyWindow(m_pWindow);

	// Clean Up for ImGui
	//ImGui::DestroyContext();

	//TTF_Quit();

	SDL_Quit();
}

void Game::Init()
{
	m_bRunning = true;
}

bool Game::IsRunning() const
{
	return m_bRunning;
}

void Game::Quit()
{
	m_bRunning = false;
}

bool Game::Init(const char * title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	int flags = 0;

	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	// initialize SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		std::cout << "SDL Init success" << std::endl;

		// if succeeded create our window
		m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

		// if window creation successful create our renderer
		if (m_pWindow != 0)
		{
			std::cout << "window creation success" << std::endl;
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);


			if (m_pRenderer != 0) // render init success
			{
				std::cout << "renderer creation success" << std::endl;
				SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 255);
			}
			else
			{
				std::cout << "renderer init failure" << std::endl;
				return false; // render int fail
			}

			// IMGUI 
			//ImGui::CreateContext();
			//ImGuiSDL::Initialize(m_pRenderer, width, height);

			// Initialize Font Support
			/*if (TTF_Init() == -1)
			{
				printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
				return false;
			}*/



			//TheTextureManager::Instance()->load("../../Assets/textures/animate-alpha.png", "animate", m_pRenderer);
			Start();

		}
		else
		{
			std::cout << "window init failure" << std::endl;
			return false; // window init fail
		}
	}
	else
	{
		std::cout << "SDL init failure" << std::endl;
		return false; //SDL could not intialize
	}

	std::cout << "init success" << std::endl;
	m_bRunning = true; // everything initialized successfully - start the main loop

	return true;
}

Vector2 Game::GetMousePosition()
{
	return m_mousePosition;
}

void Game::SetFrames(const UINT32 frames)
{
	m_frames = frames;
}

UINT32 Game::GetFrames()
{
	return m_frames;
}

Game::Game() :
	m_pWindow(nullptr), m_frames(0), m_currentFrame(0), m_bRunning(true)
{
	m_pRenderer = Renderer::Instance()->GetRenderer();
	srand(unsigned(time(nullptr)));  // random seed
}


Game::~Game()
{
}

void Game::Start()
{
}
