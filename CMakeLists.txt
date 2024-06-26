cmake_minimum_required(VERSION 3.28)
project(game)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lSDL2 -lSDL2_image")
file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})

add_executable(game src/main.cpp
        src/Game.cpp
        src/Game.h
        src/TextureManager.h
        src/TextureManager.cpp
        src/GameObject.cpp
        src/GameObject.h
        src/Map.h
        src/Map.cpp
        src/EntityComponentSystem/EntityComponentSystem.h
        src/EntityComponentSystem/Components.h
        src/Vector2D.h
        src/Vector2D.cpp
        src/EntityComponentSystem/KeyboardController.h)
