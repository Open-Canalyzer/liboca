cmake_minimum_required(VERSION 2.8)
project(liboca C)

include(cmake/CheckCCompilerFlag.txt)
include(cmake/Lint.txt)

set(SRC src/oca.c)
add_lint(${SRC})
include_directories(include)

add_library(${PROJECT_NAME}-static STATIC ${SRC})
set_target_properties(${PROJECT_NAME}-static PROPERTIES OUTPUT_NAME ${PROJECT_NAME} PREFIX "")

add_library(${PROJECT_NAME}-shared SHARED ${SRC})
set_target_properties(${PROJECT_NAME}-shared PROPERTIES OUTPUT_NAME ${PROJECT_NAME} PREFIX "")
