cmake_minimum_required(VERSION 3.19)
project(InkBall)

set(CMAKE_CXX_STANDARD 20)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

include_directories(${PROJECT_SOURCE_DIR}/include)
link_directories(${PROJECT_SOURCE_DIR}/lib)

include_directories(include/SDL2/include)
add_subdirectory(include/SDL2)

include_directories(include/SDL2_image/include)
add_subdirectory(include/SDL2_image)

set(FREETYPE_INCLUDE_DIRS ${PROJECT_SOURCE_DIR}/include/SDL2_ttf/external/freetype-2.11.1/include)

include_directories(include/SDL2_ttf)
#add_subdirectory(include/SDL2_ttf)

add_executable(InkBall src/main.cpp src/SDLWindowDeleter.cpp src/SDLWindowDeleter.h src/Game.cpp src/Game.h
        src/SDLError.h src/SDLRendererDeleter.cpp src/SDLRendererDeleter.h src/SDLTextureDeleter.cpp
        src/SDLTextureDeleter.h src/Drawing.cpp src/Drawing.h src/Vector2.h src/Ball.cpp src/Ball.h src/PlayableLevel.cpp
        src/PlayableLevel.h src/Block.cpp src/Block.h src/Renderable.h src/Updatable.h src/Line.h src/InkTrail.cpp
        src/InkTrail.h src/Pocket.cpp src/Pocket.h src/Collidable.h src/BoxCollidable.h src/Color.h src/Level.h
        src/Level.cpp src/LevelSerialization.h src/SerializedLevel.cpp src/SerializedLevel.h src/LevelDeserialization.cpp
        src/LevelDeserialization.h src/Threads.h src/MenuLevel.cpp src/MenuLevel.h src/MenuItem.h src/EscapeMenu.cpp
        src/EscapeMenu.h src/TextScreenLevel.cpp src/TextScreenLevel.h src/LevelSelectMenu.cpp src/LevelSelectMenu.h)

# Uncomment for 32-bit
#set_target_properties(InkBall PROPERTIES COMPILE_FLAGS "-m32" LINK_FLAGS "-m32")

file(COPY ${CMAKE_CURRENT_BINARY_DIR}/include/SDL2/SDL2d.dll DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY ${CMAKE_CURRENT_BINARY_DIR}/include/SDL2_image/SDL2_image.dll DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY ${CMAKE_CURRENT_BINARY_DIR}/include/SDL2_image/external/libpng-1.6.37/libpng16d.dll DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY ${CMAKE_CURRENT_BINARY_DIR}/include/SDL2_image/external/zlib-1.2.11/zlibd1.dll DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
target_link_libraries(InkBall SDL2main SDL2 SDL2_image)
# Add SDL2_ttf whenever you get it working...

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/assets DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/levels DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

