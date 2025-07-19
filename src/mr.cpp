#include "mr.h"

#ifdef _WIN32
#include "WindowsRender.h"
#elif __linux__
    #include "LinuxRender.h"
#elif __APPLE__
    #include "MacRender.h"
#endif

namespace mr
{
    std::unique_ptr<Render> createRender()
    {
#ifdef _WIN32
        return std::make_unique<WindowsRender>();
#elif __linux__
        return std::make_unique<LinuxRender>();
#elif __APPLE__
        return std::make_unique<MacRender>();
#else
        #error "Unsupported platform"
#endif
    }

    // 定义全局实例
    std::unique_ptr<Render> render = createRender();

#ifdef _WIN32
    std::unordered_map<HWND, std::shared_ptr<MFrame>> frames;
#elif __linux__
#elif __APPLE__
#else
#error "Unsupported platform"
#endif

}
