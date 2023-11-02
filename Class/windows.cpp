#include "./windows.hpp"
#include <iostream>

windows::windows(const std::string &title, int w, int h) : _title(title), _w(w), _h(h)
{
    if (!init())
    {
        _closed = true;
    }
    _closed = !init();
}

// Destroy everything
windows::~windows()
{
    SDL_DestroyRenderer(_renderer);
    SDL_DestroyWindow(_windows);
    SDL_Quit();
}

/*
 * Setting the windows
 * Setting renderer
 */
bool windows::init()
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        std::cerr << "Failed init";
        return 0;
    }

    // Size windows setting
    _windows = SDL_CreateWindow(_title.c_str(),
                                SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED,
                                _w,
                                _h,
                                0);

    if (_windows == nullptr)
    {
        std::cerr << "failed windows";
        return 0;
    }

    // Now we can create a windows color
    _renderer = SDL_CreateRenderer(_windows, -1, SDL_RENDERER_ACCELERATED);
    if (_renderer == nullptr)
    {
        std::cerr << "Failed rendere";
        return 0;
    }
    return true;
}

// For don't crash
void windows::pollEvents()
{
    SDL_Event event;

    if (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
            _closed = true;
            break;
        default:
            break;
        }
    }
}

// Create a rederer color
void windows::clear() const
{
    // SDL_SetRenderDrawColor(_renderer, 0, 230, 255, 255); // color
    // SDL_RenderClear(_renderer);

    // draw a rect
    SDL_Rect rect;
    rect.w = 550;
    rect.h = 400;
    rect.x = (_w / 2) - (rect.w / 2);
    rect.y = (_h / 2) - (rect.h / 2);

    SDL_SetRenderDrawColor(_renderer, 255, 75, 0, 255); // color
    SDL_RenderFillRect(_renderer, &rect);               // Draw the rect

    SDL_RenderPresent(_renderer);
}

// Getters
SDL_Renderer* windows::getRenderer()
{
    return this->_renderer;
}

/*
 *
 */