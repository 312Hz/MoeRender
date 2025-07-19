#ifndef MR_H
#define MR_H

#include <memory>
#include <vector>

#include "Render.h"

namespace mr
{
    extern std::unique_ptr<Render> render;
#ifdef _WIN32
    extern std::unordered_map<HWND, std::shared_ptr<MFrame>> frames;
#elif __linux__
#elif __APPLE__
#else
#error "Unsupported platform"
#endif

}

#endif