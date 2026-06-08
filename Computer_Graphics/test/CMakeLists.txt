cmake_minimum_required(VERSION 3.12)
project(Computer_Graphics)

# Use modern c++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#FINd sfml on your ubuntu system
find_package(SFML 2.5 COMPONENTS graphics window system audio network REQUIRED)

# Automatically find all .cpp files in the directory
file(GLOB RECURSIVE SOURCES "*.cpp")

# Define the executable name and pass all source files to it
add_executable(sfml_app main.cpp Game.cpp)

# Link SFML libararies to your executable
target_link_libraries(sfml_app sfml-graphics sfml-window sfml-system)