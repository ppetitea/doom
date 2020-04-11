#include <stdio.h>
#include "libft.h"
#include "node.h"
#include "log.h"
#include "data.h"
#include "data_parser.h"

int main()
{
	t_token		*root;
	char 		*data;

	// test_node_creation();
	// printf("main\n");
	// test_data_creation();
	// test_token_creation();
	root = init_new_token();

	if (!(data = load_from_file("example.json")))
		console(FATAL, __func__, __LINE__, "load data from file fail");
	// ft_putstr(data);
	clean_data(data);
	tokenize(data, root);
	// ft_putstr("\n→");
	// ft_putstr(data);
	// ft_putstr("←\n");
	// print_tokens(root);
	return (0);
}
