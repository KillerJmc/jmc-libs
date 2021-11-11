set(JMC_LIBS_VERSION 1.0.0)
message("-----------------------------------------------------------")
message("Installing jmc-libs module, version: " ${JMC_LIBS_VERSION})

# grab headers
set(JMC_LIBS_INCLUDE_DIR
	${CMAKE_CURRENT_LIST_DIR}/include/com/jmc
	${CMAKE_CURRENT_LIST_DIR}/include/com/jmc/concepts
	${CMAKE_CURRENT_LIST_DIR}/include/com/jmc/container
	${CMAKE_CURRENT_LIST_DIR}/include/com/jmc/exception
	${CMAKE_CURRENT_LIST_DIR}/include/com/jmc/io
	${CMAKE_CURRENT_LIST_DIR}/include/com/jmc/rand
	${CMAKE_CURRENT_LIST_DIR}/include/com/jmc/str
	${CMAKE_CURRENT_LIST_DIR}/include/com/jmc/timer
)

# grab libs
set(JMC_LIBS_LIB_FILE ${CMAKE_CURRENT_LIST_DIR}/lib/jmc-libs.lib)

# add headers
include_directories(${JMC_LIBS_INCLUDE_DIR})

# add libs
link_libraries(${JMC_LIBS_LIB_FILE})

message("Install jmc-libs module finished!")
message("-----------------------------------------------------------")