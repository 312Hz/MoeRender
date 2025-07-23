cmake_minimum_required(VERSION 3.30)
project(MoeRender LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_DEPENDS_IN_PROJECT_ON TRUE)

add_executable(MoeRender
        test/main.cpp
        src/mr.cpp
        include/mr.h
        src/render/WindowsRender.cpp
        include/render/WindowsRender.h
        include/render/Render.h
        src/render/LinuxRender.cpp
        include/render/LinuxRender.h
        src/MFrame.cpp
        include/MFrame.h
        include/component/Component.h
        include/event/Event.h
        include/event/mouse/MouseEvent.h
        src/component/Component.cpp
        include/event/mouse/MouseHoverEvent.h
        include/component/TextField.h
)

target_include_directories(MoeRender PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/event>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/event/mouse>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/event/frame>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/render>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/component>
)

#target_link_libraries(MoeRender
#        PRIVATE
#        kernel32
#        user32
#        gdi32
#        winspool
#        shell32
#        ole32
#        oleaut32
#        uuid
#        comdlg32
#        advapi32
#        comctl32
#)

#if (WIN32 AND MSVC)
#    set_target_properties(MoeRender PROPERTIES
#            LINK_FLAGS "/SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup"
#    )
#elseif (WIN32 AND MINGW)
#    target_link_options(MoeRender PRIVATE
#            -mwindows -Wl,-e,mainCRTStartup
#    )
#endif()