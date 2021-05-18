cmake_minimum_required(VERSION 3.19)
project(InkBall)


option(MINGW_STDTHREADS_GENERATE_STDHEADERS "" ON)
add_subdirectory(${PROJECT_SOURCE_DIR}/include/mingw)
#target_link_libraries(${TARGET} ${PROJECT_SOURCE_DIR}/include/mingw)

set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_EXE_LINKER_FLAGS "-pthread")

include_directories(${PROJECT_SOURCE_DIR}/include)
link_directories(${PROJECT_SOURCE_DIR}/lib)

add_executable(InkBall src/main.cpp src/SDLWindowDeleter.cpp src/SDLWindowDeleter.h src/Game.cpp src/Game.h
        src/SDLError.h src/SDLRendererDeleter.cpp src/SDLRendererDeleter.h src/SDLTextureDeleter.cpp
        src/SDLTextureDeleter.h src/Drawing.cpp src/Drawing.h src/Vector2.h src/Ball.cpp src/Ball.h src/PlayableLevel.cpp
        src/PlayableLevel.h src/Block.cpp src/Block.h src/Renderable.h src/Updatable.h src/Line.h src/InkTrail.cpp
        src/InkTrail.h src/Pocket.cpp src/Pocket.h src/Collidable.h src/BoxCollidable.h src/Color.h src/Level.h src/Level.cpp src/LevelSerialization.h src/SerializedLevel.cpp src/SerializedLevel.h src/LevelDeserialization.cpp src/LevelDeserialization.h src/Threads.h src/MenuLevel.cpp src/MenuLevel.h src/MenuItem.h src/EscapeMenu.cpp src/EscapeMenu.h src/TextScreenLevel.cpp src/TextScreenLevel.h)

target_link_libraries(InkBall mingw32 SDL2main SDL2 SDL2_image SDL2_ttf)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/assets DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/levels DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
