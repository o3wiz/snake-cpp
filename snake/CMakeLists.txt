set(SRCS
	"source/Game.cpp"
	"source/Apple.cpp"
	"source/Snake.cpp"
	"source/Utils.cpp"
)
set(HDRS
	"include/Apple.hpp"
	"include/Drawable.hpp"
	"include/Game.hpp"
	"include/Snake.hpp"
	"include/Specs.hpp"
	"include/Utils.hpp"
)
add_library(snake ${SRCS} ${HDRS})
target_include_directories(snake PUBLIC "include")
target_link_libraries(snake PUBLIC raylib)
add_compile_definitions(SNAKE_RESOURCES="${CMAKE_CURRENT_LIST_DIR}/resources")
