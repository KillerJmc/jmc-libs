# add_compiler_args()
function(add_compiler_args)
	if (MSVC)
		# MSVC
		add_compile_options(/utf-8)
	else()
		add_compile_options(
			-fno-stack-protector
			-fno-common
			-Wall
			-march=native
		)
		if (CMAKE_COMPILER_IS_GNUCXX)
			# GCC
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
endfunction()

# init_internal_args()
macro(init_internal_args)
	set(CMAKE_INSTALL_LIBDIR "lib")
	set(CMAKE_INSTALL_INCLUDEDIR "include")
endmacro()

# add_static_library(hyphen_lib_name include_dir src...)
function(add_static_library hyphen_lib_name include_dir)
    # add static library ${hyphen_lib_name} with sources
    add_library(${hyphen_lib_name} STATIC ${ARGN})

	# transfer hyphen lib name to camel case
	include(${PROJECT_SOURCE_DIR}/cmake/str_utils.cmake)
	hyphen_to_camel_case(${hyphen_lib_name} camel_case_lib_name)
	# add library alias: ${camel_case_lib_name}::${hyphen_lib_name} -> ${hyphen_lib_name}
	# example: JmcLibs::jmc-libs -> jmc-libs
    add_library(${camel_case_lib_name}::${hyphen_lib_name} ALIAS ${hyphen_lib_name})

    # include ${include_dir} while build and install target
	# and bind install include dir path to /usr/local/include
	target_include_directories(
		${hyphen_lib_name} 
		SYSTEM INTERFACE 
			"$<BUILD_INTERFACE:${include_dir}>" 
			"$<INSTALL_INTERFACE:$<INSTALL_PREFIX>/${CMAKE_INSTALL_INCLUDEDIR}>"
	)

    # set output dirs path
    set_target_properties(
        ${hyphen_lib_name}
        PROPERTIES
            RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
            LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
            ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    )
endfunction()