cmake_minimum_required(VERSION 3.16)
project(expressions)
SET(CMAKE_INSTALL_RPATH "${PROJECT_SOURCE_DIR}/bin")
SET(TASK_NAME expressions)

add_compile_options(-pedantic -Werror -Wextra -fsanitize=address -fsanitize=undefined -std=c++17)

add_link_options(-pedantic -Werror -Wextra -fsanitize=address -fsanitize=undefined -std=c++17)

enable_testing()
add_executable(${TASK_NAME} src/expressions.cpp src/expressions.hpp)

target_link_libraries(${TASK_NAME} Threads::Threads ${GTEST_LIBRARIES} ${GMOCK_BOTH_LIBRARIES})

install (
        TARGETS ${TASK_NAME}
        RUNTIME DESTINATION ${PROJECT_SOURCE_DIR}/bin
)