set(JMC_LIBS_VERSION 1.0.0)
project ("jmc-libs"
	LANGUAGES CXX
	VERSION ${JMC_LIBS_VERSION}
)
cmake_minimum_required (VERSION 3.20)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(MSVC)
	add_compile_options(
		/Wall
		/source-charset:utf-8
		/wd4996  # disable Compiler Warning (level 3) C4996
	)
else()
	add_compile_options(
		-fno-stack-protector
		-fno-common
		-Wall
		-march=native
	)
	if(CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)
		# GNU Compiler Collection
		add_compile_options(
			-finput-charset=UTF8
			-fmax-errors=5
			$<$<STREQUAL:${CMAKE_GENERATOR},Ninja>:-fdiagnostics-color=always>
		)
	else()
		# Clang
		add_compile_options(
			-finput-charset=UTF-8
			-ferror-limit=5
			$<$<STREQUAL:${CMAKE_GENERATOR},Ninja>:-fcolor-diagnostics>
		)
	endif()
endif()

include_directories(
	${PROJECT_SOURCE_DIR}/modules/jmc-libs/include/com/jmc
	${PROJECT_SOURCE_DIR}/modules/jmc-libs/include/com/jmc/concepts
	${PROJECT_SOURCE_DIR}/modules/jmc-libs/include/com/jmc/container
	${PROJECT_SOURCE_DIR}/modules/jmc-libs/include/com/jmc/exception
	${PROJECT_SOURCE_DIR}/modules/jmc-libs/include/com/jmc/io
	${PROJECT_SOURCE_DIR}/modules/jmc-libs/include/com/jmc/rand
	${PROJECT_SOURCE_DIR}/modules/jmc-libs/include/com/jmc/str
	${PROJECT_SOURCE_DIR}/modules/jmc-libs/include/com/jmc/timer
)

file(GLOB_RECURSE SRCS CONFIGURE_DEPENDS ${PROJECT_SOURCE_DIR}/src/com/jmc/*.cpp)

set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/modules/jmc-libs/lib)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
	add_executable(${PROJECT_NAME} ${SRCS} ${PROJECT_SOURCE_DIR}/src/main.cpp)
else()
	add_library(${PROJECT_NAME} STATIC ${SRCS})
endif()
