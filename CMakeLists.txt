cmake_minimum_required(VERSION 3.8)

#set(SFML_STATIC_LIBRARIES TRUE)
find_package(SFML 2 COMPONENTS system window graphics audio REQUIRED)
include_directories(${SFML_INCLUDE_DIR})

add_library(core
  src/systems/collision.cpp
  src/systems/graphics.cpp
  src/systems/physics.cpp
  src/systems/sound.cpp
  src/systems/systems.hpp
)
target_link_libraries(core PUBLIC ${SFML_LIBRARIES})

add_executable(GameTest src/main.cpp)
target_link_libraries(GameTest core)

add_custom_command(TARGET GameTest POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/resources ${CMAKE_BINARY_DIR}/resources
)
