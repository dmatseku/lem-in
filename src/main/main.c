#include "../graph/graph.h"
#include "../graph/structs/s_graph.h"
#include "../read_from_input/read_from_input.h"
#include "../path/path.h"
#include <fcntl.h>
#include <unistd.h>
//#include <time.h>
//#include <stdio.h>

int main(void)
{
	t_list_string	*input;
	t_graph			*graph;
	t_path_array	*paths;
//	clock_t			start;
//	clock_t 		end;

//	start = clock();
	int fd = open("../Examples/super1.txt", O_RDONLY);
	input = read_from_input(fd);
	graph = graph_create(input);
	close(fd);
	list_string_print(input);
	paths = find_paths(graph);
	graph_delete(graph);
	list_string_delete(input);
//	end = clock();
//	printf("%.4lf\n", (double)(end - start) / CLOCKS_PER_SEC);
	return (0);
}
