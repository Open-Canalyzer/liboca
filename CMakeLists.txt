cmake_minimum_required(VERSION 2.8)

if (POLICY CMP0042)
	# Newer cmake on MacOS should use @rpath
	cmake_policy (SET CMP0042 NEW)
endif ()

project(liboca C)

#
# The path for our own CMake modules
#
set ( CMAKE_MODULE_PATH
	${PROJECT_SOURCE_DIR}/cmake
)

if(WIN32)
	find_package(7Zip REQUIRED)
	message(STATUS "7Zip Location: " ${ZIP_LOCATION})
endif()

find_package(LibUSB REQUIRED)
message(STATUS "libusb inc: " ${LIBUSB_INCLUDE_DIR})
message(STATUS "libusb lib: " ${LIBUSB_LIBRARY})

include(cmake/CheckCCompilerFlag.txt)
if(WIN32)
	function(add_lint SOURCES_LIST)
		message(STATUS "Linting not supported on WINx platforms")
	endfunction()
else()
	include(cmake/Lint.txt)
endif()

if(${CMAKE_BUILD_TYPE} MATCHES "Debug")
	add_cflag_if_supported("-O0")
	add_cflag_if_supported("-ggdb")
	add_cflag_if_supported("-fprofile-arcs")
	add_cflag_if_supported("-ftest-coverage")

	add_definitions("-DDEBUG")

	include(CTest)
elseif()
	add_cflag_if_supported("-O2")

	add_definitions("-DRELEASE")
endif()

set(SRC src/oca.c)
include_directories(include)
include_directories(${LIBUSB_INCLUDE_DIR})

if(OCA_LINT AND BUILD_TESTING)
	add_lint(${SRC})
endif()

add_library(${PROJECT_NAME}-static STATIC ${SRC})
set_target_properties(${PROJECT_NAME}-static PROPERTIES OUTPUT_NAME ${PROJECT_NAME} PREFIX "")
target_link_libraries(${PROJECT_NAME}-static  ${LIBUSB_LIBRARY})

add_library(${PROJECT_NAME}-shared SHARED ${SRC})
set_target_properties(${PROJECT_NAME}-shared PROPERTIES OUTPUT_NAME ${PROJECT_NAME} PREFIX "")
target_link_libraries(${PROJECT_NAME}-shared ${LIBUSB_LIBRARY})

add_subdirectory("tests")
