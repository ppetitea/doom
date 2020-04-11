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

	if (!(root = init_new_token()))
		return (console(FATAL, __func__, __LINE__, "new token fail").err);
	if (!(data = load_from_file("example.json")))
		console(FATAL, __func__, __LINE__, "load data from file fail");
	ft_putstr(data);
	clean_data(data);
	ft_putstr("\n→");
	ft_putstr(data);
	ft_putstr("←\n");
	tokenize(data, root);
	print_tokens(root);
	return (0);
}
