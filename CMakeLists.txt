cmake_minimum_required(VERSION 2.6)
project (Portfolio CXX)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

include (GNUInstallDirs)
include (CMakePackageConfigHelpers)

set (PROJECT_LABEL "Portfolio")
add_definitions (-D_CRT_SECURE_NO_WARNINGS)

find_Package(OpenGL REQUIRED)

if(UNIX)
	set (LINK_DIRECTORY "/usr/lib")
	set (LIBS "-X11 ${OPENGL_LIBRARIES}")
	set (COMMON_FLAGS "-std=c++11 -DSO -Wall -Wextra")
	set (DEBUG_FLAGS "-g -DDEBUG")
	set (ERROR_OUTPUT "2> errors.txt")
	
	if(CMAKE_BUILD_TYPE MATCHES Release)
		add_definitions(${COMMON_FLAGS} ${ERROR_OUTPUT})
	elseif (CMAKE_BUILD_TYPE MATCHES Debug)
		add_definitions(${COMMON_FLAGS} ${DEBUG_FLAGS} ${ERROR_OUTPUT})
	elseif(CMAKE_BUILD_TYPE MATCHES "")
		add_definitions(${COMMON_FLAGS} ${DEBUG_FLAGS} ${ERROR_OUTPUT})
	endif()
endif(UNIX)

if(WIN32)
	set (LIBS "${OPENGL_LIBRARIES}")
endif(WIN32)

set (COMMON_OUTPUT_DIR "./bin")
set (DEBUG_OUTPUT_DIR "./bin/Debug/")
set (RELEASE_OUTPUT_DIR "./bin/Release/")

set (TINYWINDOW_EXAMPLE_DIR "./dependencies/tinywindow/Example")
#set (TINYWINDOW_VULKAN_DIR "./dependencies/tinywindow/Vulkan")
set (TINYEXTENDER_EXAMPLE_DIR "./dependencies/tinyextender/Example")
set (TINYSHADERS_EXAMPLE_DIR "./dependencies/tinyshaders/Example")
set (TINYCLOCK_EXAMPLE_DIR "./dependencies/tinyclock/Example")
set (ASSIMP_DIR "./dependencies/assimp")
#set (SOIL_DIR "./dependencies/SOIL")

#build dependencies
add_subdirectory("${TINYWINDOW_EXAMPLE_DIR}")
#add_subdirectory("${TINYWINDOW_VULKAN_DIR}")
add_subdirectory("${TINYEXTENDER_EXAMPLE_DIR}")
add_subdirectory("${TINYSHADERS_EXAMPLE_DIR}")
add_subdirectory("${TINYCLOCK_EXAMPLE_DIR}")
add_subdirectory("${ASSIMP_DIR}")
#add_subdirectory("${SOIL_DIR}")

add_subdirectory("./examples/TemporalAA")