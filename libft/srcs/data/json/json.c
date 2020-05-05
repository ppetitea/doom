/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/16 14:56:57 by ppetitea          #+#    #+#             */
/*   Updated: 2020/04/16 21:02:01 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data/json_parser.h"
#include <stdlib.h>

t_data *json_parse(char *path)
{
	t_data		*json;
	t_token		*token;
	char 		*data;

	if (!(token = init_new_token()))
		return (console(FATAL, __func__, __LINE__, "new token fail").null);
	if (!(data = load_from_file(path)))
		return (console(FATAL, __func__, __LINE__, "load data fail").null);
	if (!clean_data(data))
	{
		free(data);
		return (console(FATAL, __func__, __LINE__, "clean data fail").null);
	}
	if (!tokenize(data, token))
	{
		free(data);
		return (console(FATAL, __func__, __LINE__, "tokenize data fail").null);
	}
	if (!(json = parse(token)))
		console(FATAL, __func__, __LINE__, "parse data from tokens fail");
	free(data);
	free(token);
	return (json);
}