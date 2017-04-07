project(CEdev)
cmake_minimum_required(VERSION 3.0.2)

if("${CMAKE_SOURCE_DIR}" STREQUAL "${CMAKE_BINARY_DIR}")
  message(WARNING
  "It is not recommended to build in-source, "
  "as it is difficult to clean up later."
  "Please make a build folder and run CMake from there.")
endif()

add_subdirectory(tools/spasm-ng)
add_subdirectory(tools/convpng)
add_subdirectory(tools/convhex)

install(TARGETS GraphX KeypadC FileIO
	ARCHIVE	DESTINATION ${CMAKE_INSTALL_PREFIX})