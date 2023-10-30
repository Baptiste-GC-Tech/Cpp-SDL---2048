#pragma once
#include <SDL.h>
#include <string>

class windows
{

private:
    std::string _title;
    int _w = 800;
    int _h = 600;

    bool init();
    bool _closed = false;

    SDL_Window *_windows = nullptr;
    SDL_Renderer *_renderer = nullptr;

public:
    windows(const std::string &title, int w, int h);
    ~windows();

    void pollEvents();
    void clear() const;

    inline bool isClosed() const { return _closed; }
};
