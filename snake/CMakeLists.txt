set(SRCS
    "${CMAKE_CURRENT_LIST_DIR}/source/Game.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/source/Apple.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/source/Snake.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/source/Utils.cpp"
)
add_library(snake ${SRCS})
target_include_directories(snake PUBLIC "include")
target_link_libraries(snake PUBLIC raylib)
