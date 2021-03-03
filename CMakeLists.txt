cmake_minimum_required(VERSION 3.17)
project(Push_Swap C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -Wextra -g3 -fsanitize=address")
set(CMAKE_LINKER_FLAGS)

add_executable(push_swap main.c utils.c push_swap.h operations.c findOps.c)
add_executable(checker checker.c utils.c push_swap.h operations.c findOps.c)

find_library(LIBFT libft.a libft)
target_link_libraries(push_swap LINK_PUBLIC ${LIBFT})
target_link_libraries(checker LINK_PUBLIC ${LIBFT})