cmake_minimum_required(VERSION 3.19)
project(InkBall)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")

include_directories(${PROJECT_SOURCE_DIR}/include)
link_directories(${PROJECT_SOURCE_DIR}/lib)

add_executable(InkBall src/main.cpp src/SDLWindowDeleter.cpp src/SDLWindowDeleter.h src/Game.cpp src/Game.h
        src/SDLError.h src/SDLRendererDeleter.cpp src/SDLRendererDeleter.h src/SDLTextureDeleter.cpp
        src/SDLTextureDeleter.h src/Drawing.cpp src/Drawing.h src/Vector2.h src/Ball.cpp src/Ball.h src/PlayableLevel.cpp
        src/PlayableLevel.h src/Block.cpp src/Block.h src/Renderable.h src/Updatable.h src/Line.h src/InkTrail.cpp
        src/InkTrail.h src/Pocket.cpp src/Pocket.h src/Collidable.h src/BoxCollidable.h src/Color.h src/Level.h src/GameOverLevel.cpp src/GameOverLevel.h src/Level.cpp src/LevelSerialization.h src/SerializedLevel.cpp src/SerializedLevel.h)

target_link_libraries(InkBall mingw32 SDL2main SDL2 SDL2_image SDL2_ttf)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/assets DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
