#include <stdio.h>
#include "libft.h"
#include "utils/node.h"
#include "utils/log.h"
#include "utils/data.h"
#include "utils/data_parser.h"

int main()
{
	t_data		*json;
	t_token		*token;
	char 		*data;

	if (!(token = init_new_token()))
		return (console(FATAL, __func__, __LINE__, "new token fail").err);
	if (!(data = load_from_file("example.json")))
		console(FATAL, __func__, __LINE__, "load data from file fail");
	// ft_putstr(data);
	clean_data(data);
	// ft_putstr("\n→");
	// ft_putstr(data);
	// ft_putstr("←\n");
	tokenize(data, token);
	// print_tokens(token);
	if (!(json = parse(token)))
		console(FATAL, __func__, __LINE__, "parse data from tokens fail");
	print_datas(json);
	return (0);
}
