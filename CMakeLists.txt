cmake_minimum_required(VERSION 3.14.3)
project(lem_in_v2 C)

set(CMAKE_C_STANDARD 99)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Werror -Wpedantic")

add_executable(lem_in_v2 src/main/main.c

        src/read_from_input/read_line.c
        src/read_from_input/read_from_input.c
        src/read_from_input/list_fd/list_fd_create_node.c
        src/read_from_input/list_fd/list_fd_pushback.c
        src/read_from_input/list_fd/list_fd_pop.c
        src/read_from_input/list_fd/list_fd_get_elem.c
        src/graph/graph_create/validate_string.c
        src/graph/graph_create/set_ants.c
        src/graph/graph_create/set_nodes.c
        src/graph/graph_create/set_links.c
        src/graph/graph_create/skip_comments.c
        src/graph/graph_create/graph_create.c

        src/list_string/list_string_create_node.c
        src/list_string/list_string_pushback.c

        src/graph/list_link/list_link_create_node.c
        src/graph/list_link/list_link_pushback.c

        src/other/exit_error.c
        src/other/ft_strlen.c
        src/other/ft_memset.c
        src/other/ft_strncat.c
        src/other/ft_strcmp.c
        src/other/ft_atou.c src/graph/graph_delete/graph_delete.c src/list_string/list_string_delete.c src/list_string/list_string_print.c src/graph/structs/s_graph.h src/graph/structs/s_node.h src/graph/structs/s_link.h src/path/find_paths/find_paths.c src/graph/list_node/list_node.h src/graph/list_node/list_node_create_node.c src/graph/list_node/list_node_pushback.c src/path/path.h src/path/create_path_array/create_path_array.c src/path/find_paths/find_one_path/find_one_path.c src/path/find_paths/find_one_path/bfs_search.c src/path/find_paths/find_one_path/set_cost_for_child.c src/path/find_paths/find_one_path/find_one_path.h src/path/find_paths/find_paths.h src/path/find_paths/count_the_new_cost/count_new_cost.c src/path/find_paths/count_the_new_cost/count_new_cost.h src/path/find_paths/count_the_new_cost/get_size_of_first_part.c src/path/find_paths/count_the_new_cost/get_size_of_second_part.c src/path/find_paths/count_the_new_cost/get_death_zone.c src/path/find_paths/insert_the_found_path_into_the_array/insert_found_path_into_array.c src/path/find_paths/insert_the_found_path_into_the_array/insert_found_path_into_array.h src/path/find_paths/insert_the_found_path_into_the_array/swap_paths/swap_paths.c src/path/find_paths/insert_the_found_path_into_the_array/swap_paths/get_sizes.c src/path/find_paths/insert_the_found_path_into_the_array/swap_paths/swap_paths.h)