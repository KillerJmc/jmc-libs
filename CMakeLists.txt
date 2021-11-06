project ("jmc-libs")
cmake_minimum_required (VERSION 3.20)
set(CMAKE_CXX_STANDARD 23)

add_compile_options("/utf-8")

include_directories(
	${PROJECT_SOURCE_DIR}/modules/jmc-libs/include/com/jmc/
	${PROJECT_SOURCE_DIR}/modules/jmc-libs/include/com/jmc/io
	${PROJECT_SOURCE_DIR}/modules/jmc-libs/include/com/jmc/exception
	${PROJECT_SOURCE_DIR}/modules/jmc-libs/include/com/jmc/str
)

file(GLOB_RECURSE SRCS CONFIGURE_DEPENDS ${PROJECT_SOURCE_DIR}/src/com/jmc/*.cpp)

set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/modules/jmc-libs/lib)

set(DEBUG false)

if (${DEBUG})
	add_executable(jmc-libs ${SRCS} ${PROJECT_SOURCE_DIR}/src/main.cpp)
else()
	add_library(jmc-libs STATIC ${SRCS})
endif()