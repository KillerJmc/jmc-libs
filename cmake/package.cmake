# publish_package(package_name package_version package_lib_name include_dir)
# 
# Generate config files (Config cmake file, Version cmake file, Targets cmake file), lib file, include dir while installing.
# Location:
#     config files:  /usr/local/lib/cmake/${package_name}
#     lib file:      /usr/local/lib
#     include dir:   /usr/local/include            
# Notice: Only for Linux
function(publish_package package_name package_version package_lib_name include_dir) 
    include(CMakePackageConfigHelpers)
    
    # the dir which stores generated config and configVersion files
    set(generated_dir "${CMAKE_CURRENT_BINARY_DIR}/generated" CACHE INTERNAL "")
    # install dir path (for linux: /usr/lib/cmake/${package_name})
    set(cmake_files_install_dir "${CMAKE_INSTALL_LIBDIR}/cmake/${package_name}")

    # config.cmake.in file location
    # the content of this file will be copied to Config.cmake
    set(in_file "${PROJECT_SOURCE_DIR}/cmake/config.cmake.in")
    # the relative path of the generated Config.cmake file 
    set(config_file "${generated_dir}/${package_name}Config.cmake")
    # the relative path of the generated ConfigVersion.cmake file 
    set(version_file "${generated_dir}/${package_name}ConfigVersion.cmake")
    # generated targets file name
    set(targets_export_name ${package_name}Targets CACHE INTERNAL "")

    # while installing: copy include files to /usr/local/include
    install(
        DIRECTORY ${include_dir}/
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
    )

    # generate Config.cmake file
    configure_package_config_file(
        ${in_file}
        ${config_file}
        INSTALL_DESTINATION ${cmake_files_install_dir}
    )

    # generate ConfigVersion.cmake file
    write_basic_package_version_file(
        ${version_file}
        VERSION ${package_version}
        COMPATIBILITY AnyNewerVersion
    )

    # copy generated config and version files to ${generated_dir}
    # and while installing: copy config and version files to /usr/lib/cmake/${package_name}
    install(
        FILES ${config_file} ${version_file}
        DESTINATION ${cmake_files_install_dir}
    )

    # link library to EXPORT ${targets_export_name} 
    # and copy library file to /usr/local/lib/
    install(
        TARGETS ${package_lib_name}
        EXPORT ${targets_export_name}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    )

    # generate Targets.cmake which includes the statement to add library (with namespace)
    # and copy it to /usr/lib/cmake/${package_name}
    install(
        EXPORT ${targets_export_name}
        NAMESPACE ${package_name}::
        DESTINATION ${cmake_files_install_dir}
    )
endfunction()