set(PROJECT_VERSION 2.1.0)

cmake_minimum_required(VERSION 3.12)
project (jmc-libs LANGUAGES CXX VERSION ${PROJECT_VERSION})

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(cmake/internal_utils.cmake)
add_compiler_args()
init_internal_args()

set(INCLUDE_DIR ${PROJECT_SOURCE_DIR}/src)
include_directories(${INCLUDE_DIR})

add_subdirectory(src)
add_subdirectory(test)

include(cmake/package.cmake)
publish_package(JmcLibs ${PROJECT_VERSION} ${PROJECT_NAME} ${INCLUDE_DIR})
