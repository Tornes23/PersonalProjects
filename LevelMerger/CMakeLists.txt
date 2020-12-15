cmake_minimum_required(VERSION 3.6.2)

##################################
# Build configuration
set(PRJ_NAME LevelMerger)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")

# Source files
set(SRC
	src/imgui.hpp
	src/math.hpp
	src/imgui.hpp
	src/pch.hpp
	src/opengl.hpp
	src/System/System.hpp
	src/System/System.cpp
	src/Camera/Camera.cpp
	src/Camera/Camera.hpp
	src/Window/Window.cpp
	src/Window/Window.hpp
	src/Debug/Debug.cpp
	src/Debug/Debug.hpp
	)

include_directories(src)
# Projects
project(${PRJ_NAME})

##################################
# Libraries
set(DEPENDENCIES_DIR $ENV{USERPROFILE}/documents/ProjectDependencies)
string(REPLACE "\\" "/" DEPENDENCIES_DIR ${DEPENDENCIES_DIR})

# glm
include_directories("${DEPENDENCIES_DIR}/glm")

# glfw
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory("${DEPENDENCIES_DIR}/glfw" "glfw")
include_directories("${DEPENDENCIES_DIR}/glfw/include/")

# glad
add_subdirectory("${DEPENDENCIES_DIR}/glad" "glad")
include_directories("${CMAKE_CACHEFILE_DIR}/glad/include/")

# lodepng
include_directories("${DEPENDENCIES_DIR}/lodepng")
set(SRC_EXTERNAL "${SRC_EXTERNAL}" "${DEPENDENCIES_DIR}/lodepng/lodepng.cpp")

# imgui
include_directories("${DEPENDENCIES_DIR}/imgui")
set(SRC_EXTERNAL "${SRC_EXTERNAL}" "${DEPENDENCIES_DIR}/imgui/examples/imgui_impl_glfw.cpp")
set(SRC_EXTERNAL "${SRC_EXTERNAL}" "${DEPENDENCIES_DIR}/imgui/examples/imgui_impl_opengl3.cpp")
set(SRC_EXTERNAL "${SRC_EXTERNAL}" "${DEPENDENCIES_DIR}/imgui/imgui.cpp")
set(SRC_EXTERNAL "${SRC_EXTERNAL}" "${DEPENDENCIES_DIR}/imgui/imgui_demo.cpp")
set(SRC_EXTERNAL "${SRC_EXTERNAL}" "${DEPENDENCIES_DIR}/imgui/imgui_draw.cpp")
set(SRC_EXTERNAL "${SRC_EXTERNAL}" "${DEPENDENCIES_DIR}/imgui/ImGuizmo.cpp")
set(SRC_EXTERNAL "${SRC_EXTERNAL}" "${DEPENDENCIES_DIR}/imgui/imgui_widgets.cpp")
add_compile_definitions(IMGUI_IMPL_OPENGL_LOADER_GLAD)

##################################
# Compile arguments
set(CMAKE_CXX_STANDARD 20)
message("Using MSVC")
# Visual Studio Configuration
# Enable warnings
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W3")

# Warnings as errors
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /WX") 
add_compile_definitions(_CRT_SECURE_NO_WARNINGS)

# Disable specific warning
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /wd4201") # nameless struct/union
 
# Binaries
add_executable(${PRJ_NAME} ${SRC} ${SRC_EXTERNAL} src/main.cpp)
target_link_libraries(${PRJ_NAME} glfw glad)
