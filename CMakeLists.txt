cmake_minimum_required(VERSION 3.15)
project(lem_in_v2 C)

set(CMAKE_C_STANDARD 99)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Werror -Wpedantic")

add_executable(lem_in_v2 src/main/main.c src/graph/create_graph/read/read_line.c src/other/exit_error.c src/other/other.h src/other/ft_strlen.c src/list_string/list_string.h src/list_string/list_string_create_node.c src/list_string/list_string_pushback.c src/graph/create_graph/validate_string.c src/graph/create_graph/set_ants.c src/graph/create_graph/set_rooms.c src/graph/create_graph/set_links.c src/graph/create_graph/skip_comments.c src/graph/structs/s_graph.h src/graph/list_link/list_link.h src/graph/list_node/list_node.h src/graph/structs/s_node.h src/graph/structs/s_link.h src/graph/list_link/list_link_create_node.c src/graph/list_link/list_link_pushback.c src/graph/graph.h src/graph/create_graph/create_graph.h src/graph/create_graph/read/read.h src/graph/create_graph/read/read_input.c src/graph/create_graph/create_graph.c src/graph/create_graph/read/list_fd/list_fd.h src/graph/create_graph/read/list_fd/list_fd_create_node.c src/other/ft_memset.c src/graph/create_graph/read/list_fd/list_fd_pushback.c src/graph/create_graph/read/list_fd/list_fd_pop.c src/graph/create_graph/read/list_fd/list_fd_get_elem.c src/other/ft_strncat.c src/other/ft_strcmp.c src/other/ft_atou.c)