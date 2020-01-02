cmake_minimum_required(VERSION 3.14.3)
project(lem_in C)

set(CMAKE_C_STANDARD 99)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Werror -Wpedantic")

add_executable(lem_in src/main.c

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
        src/graph/graph_delete.c
        src/graph/list_node/list_node_create_node.c
        src/graph/list_node/list_node_pushback.c
        src/graph/graph_print_nodes_count.c

        src/list_string/list_string_create_node.c
        src/list_string/list_string_pushback.c
        src/list_string/list_string_delete.c
        src/list_string/list_string_print.c
        src/list_string/list_string_get_last.c

        src/graph/list_link/list_link_create_node.c
        src/graph/list_link/list_link_pushback.c

        src/other/exit_error.c
        src/other/ft_strlen.c
        src/other/ft_memset.c
        src/other/ft_strncat.c
        src/other/ft_strcmp.c
        src/other/ft_atou.c
        src/other/ft_strcat.c
        src/other/uint_operations.c

        src/path/path_array_create.c
        src/path/path_array_init/path_array_init.c
        src/path/path_array_init/find_one_path/find_one_path.c
        src/path/path_array_init/find_one_path/bf_search.c
        src/path/path_array_init/find_one_path/set_cost_for_child.c
        src/path/path_array_init/insert_found_path_into_array/insert_found_path_into_array.c
        src/path/path_array_init/insert_found_path_into_array/swap_paths/swap_paths.c
        src/path/path_array_init/insert_found_path_into_array/swap_paths/get_sizes.c
        src/path/path_array_init/insert_found_path_into_array/swap_paths/swap_ending.c
        src/path/path_array_init/reverse_links/reverse_links.c
        src/path/path_array_init/count_new_cost/count_new_cost.c
        src/path/path_array_copy.c
        src/path/path_array_delete.c
        src/path/path_array_print.c
        src/path/path_array_print_steps_count.c

        src/manage_flags/manage_flags.c
        src/manage_flags/flags_delete.c

        src/run_ants_through_the_graph/run_ants_through_the_graph.c
        src/run_ants_through_the_graph/ant_data/ant_data_create.c
        src/run_ants_through_the_graph/ant_data/ant_data_delete.c src/color/color.h src/color/print_color.c)