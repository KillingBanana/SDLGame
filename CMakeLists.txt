cmake_minimum_required(VERSION 3.10)
project(SDLGame)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -W -Wall -Wextra -pedantic")

set(SRC_FILES src/main.cpp src/Game.cpp src/Game.hpp src/TextureManager.hpp src/TextureManager.cpp src/Map.cpp src/Map.hpp src/ECS/ECS.hpp src/ECS/Components.hpp src/ECS/ECS.cpp src/ECS/Transform.cpp src/ECS/Transform.hpp src/ECS/SpriteRenderer.cpp src/ECS/SpriteRenderer.hpp src/Vector2.cpp src/Vector2.hpp src/ECS/KeyboardController.cpp src/ECS/KeyboardController.hpp src/Clock.cpp src/Clock.hpp src/ECS/Collider.cpp src/ECS/Collider.hpp src/Collision.cpp src/Collision.hpp src/ECS/Tile.cpp src/ECS/Tile.hpp src/Vector2int.cpp src/Vector2int.hpp)

add_executable(SDLGame ${SRC_FILES})

find_package(SDL2 REQUIRED)
target_link_libraries(SDLGame ${SDL2_LIBRARY})
target_include_directories(SDLGame PUBLIC ${SDL2_INCLUDE_DIR})

find_package(SDL2_image REQUIRED)
target_link_libraries(SDLGame ${SDL2_IMAGE_LIBRARIES})
#target_include_directories(SDLGame PUBLIC ${SDL2_IMAGE_INCLUDE_DIRS})
