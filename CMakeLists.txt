# Project setting.
project(Agile-Practise CXX C)

# CMake version requires.
cmake_minimum_required(VERSION 2.6.2)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

set(GTEST_ROOT $ENV{GTEST_ROOT})
if(NOT GTEST_ROOT)
	set(GTEST_ROOT "${CMAKE_SOURCE_DIR}/module/gtest")
endif()
message(STATUS "GTEST_ROOT:" ${GTEST_ROOT})

set(QT_ROOT $ENV{QT_ROOT})
if(NOT QT_ROOT)
	set(QT_ROOT "${CMAKE_SOURCE_DIR}/module/qt")
endif()
message(STATUS "QT_ROOT:" ${QT_ROOT})

set (PROJECT_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set (EXTRA_LIB_DIR "")

# Binary file directory.	
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
SET(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

add_subdirectory(${PROJECT_SOURCE_DIR}/src/core)
add_subdirectory(${PROJECT_SOURCE_DIR}/src/affiliations)
add_subdirectory(${PROJECT_SOURCE_DIR}/src/schedules)
add_subdirectory(${PROJECT_SOURCE_DIR}/src/classifications)
add_subdirectory(${PROJECT_SOURCE_DIR}/src/methods)
add_subdirectory(${PROJECT_SOURCE_DIR}/src/transactions)
add_subdirectory(${PROJECT_SOURCE_DIR}/src/database)
add_subdirectory(${PROJECT_SOURCE_DIR}/src/payrollGUI)
add_subdirectory(${PROJECT_SOURCE_DIR}/src/test)

# Build a CPack driven installer package
include (InstallRequiredSystemLibraries)
set (CPACK_PACKAGE_VERSION_MAJOR "1")
set (CPACK_PACKAGE_VERSION_MINOR "0")
set (CPACK_PACKAGE_VERSION_PATCH "0")
include (CPack)
