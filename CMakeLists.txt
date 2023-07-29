cmake_minimum_required(VERSION 3.10)
project(game_of_life)

set(CMAKE_CXX_STANDARD 11)

include_directories("/home/polaris/SFML-2.6.0/include")

set(SFML_DIR "/home/polaris/SFML-2.6.0/lib/cmake/SFML")

set(SFML_STATIC_LIBRARIES TRUE)
find_package(SFML COMPONENTS graphics window system REQUIRED)

add_executable(game_of_life main.cpp Cell.cpp Grid.cpp)
target_link_libraries(game_of_life PRIVATE sfml-graphics sfml-window sfml-system)
