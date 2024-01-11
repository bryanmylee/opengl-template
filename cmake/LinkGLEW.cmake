include(FetchContent)

macro(LinkGLEW TARGET ACCESS)
    FetchContent_Declare(
        glew
        GIT_REPOSITORY https://github.com/Perlmint/glew-cmake
        GIT_TAG glew-cmake-2.2.0
    )

    FetchContent_GetProperties(glew)

    if (NOT glew_POPULATED)
        FetchContent_Populate(glew)

        # This excludes glew from being rebuilt when ALL_BUILD is built
        # it will only be built when a target is built that has a dependency on glew
        add_subdirectory(${glew_SOURCE_DIR} ${glew_BINARY_DIR} EXCLUDE_FROM_ALL)

        # Set the target's folders
        set_target_properties(libglew_static PROPERTIES FOLDER ${PROJECT_NAME}/thirdparty)
    endif()

    target_include_directories(${TARGET} ${ACCESS} ${glew_SOURCE_DIR}/include)
    target_link_libraries(${TARGET} ${ACCESS} libglew_static)

    add_dependencies(${TARGET} libglew_static)
endmacro()