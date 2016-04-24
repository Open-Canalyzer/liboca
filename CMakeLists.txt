cmake_minimum_required(VERSION 2.8)
project(liboca C)

include(cmake/CheckCCompilerFlag.txt)
include(cmake/Lint.txt)

if(${CMAKE_BUILD_TYPE} MATCHES "Debug")
	add_cflag_if_supported("-O0")
	add_cflag_if_supported("-ggdb")
	add_cflag_if_supported("-fprofile-arcs")
	add_cflag_if_supported("-ftest-coverage")
	include(CTest)
elseif()
	add_cflag_if_supported("-O2")
endif()

set(SRC src/oca.c)
add_lint(${SRC})
include_directories(include)

add_library(${PROJECT_NAME}-static STATIC ${SRC})
set_target_properties(${PROJECT_NAME}-static PROPERTIES OUTPUT_NAME ${PROJECT_NAME} PREFIX "")

add_library(${PROJECT_NAME}-shared SHARED ${SRC})
set_target_properties(${PROJECT_NAME}-shared PROPERTIES OUTPUT_NAME ${PROJECT_NAME} PREFIX "")

add_subdirectory("tests")
