cmake_minimum_required(VERSION 3.20)
project(snake)

set(CMAKE_CXX_STANDARD 14)

add_executable(snake main.cpp game_engine/GameEngine.cpp game_engine/GameEngine.h game_engine/Snake.cpp game_engine/Snake.h game_engine/GameObject.cpp game_engine/GameObject.h renderer/ConsoleRenderer.cpp renderer/ConsoleRenderer.h renderer/Renderer.h game_engine/Map.cpp game_engine/Map.h)
