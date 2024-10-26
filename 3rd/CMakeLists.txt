if(NOT EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/raylib/CMakeLists.txt")
    message(STATUS "raylib is not found. Initializing submodule...")
    execute_process(
        COMMAND git submodule update --init --recursive
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        RESULT_VARIABLE GIT_SUBMODULE_RESULT
    )

    if(NOT GIT_SUBMODULE_RESULT EQUAL 0)
        message(FATAL_ERROR "Failed to update git submodule: raylib.")
    endif()
else()
    message(STATUS "raylib directory found.")
endif()

add_subdirectory(raylib)
