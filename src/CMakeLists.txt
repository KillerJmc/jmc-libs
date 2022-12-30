# get cpp source files in .
file(GLOB_RECURSE SRCS CONFIGURE_DEPENDS *.cpp)
add_static_library(${PROJECT_NAME} ${INCLUDE_DIR} ${SRCS})
