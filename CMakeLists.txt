cmake_minimum_required(VERSION 3.19)
project(InkBall)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")

include_directories(${PROJECT_SOURCE_DIR}/include)
link_directories(${PROJECT_SOURCE_DIR}/lib)

add_executable(InkBall main.cpp SDLWindowDeleter.cpp SDLWindowDeleter.h Game.cpp Game.h SDLError.h SDLRendererDeleter.cpp SDLRendererDeleter.h SDLTextureDeleter.cpp SDLTextureDeleter.h Drawing.cpp Drawing.h Vector2.h Ball.cpp Ball.h Level.cpp Level.h Block.cpp Block.h Renderable.h Updatable.h)

target_link_libraries(InkBall mingw32 SDL2main SDL2 SDL2_image)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/assets DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
