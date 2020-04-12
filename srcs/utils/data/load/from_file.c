/*                                                        :::      ::::::::   */
/*   get_file_datas.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 12:51:48 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/21 09:24:03 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "ft/str.h"
#include "utils/log.h"

char	*update_data_with_buffer(char *datas, char *buf)
{
	char	*ret;

	if (datas == NULL)
		return (ft_strdup(buf));
	ret = ft_strjoin(datas, buf);
	free(datas);
	return (ret);
}

char	*load_from_file(char *path)
{
	int	 	fd;
	size_t  buf_size;
	ssize_t read_len;
	char	*buf;
	char	*datas;

	datas = NULL;
	buf_size = 100;
	if ((fd = open(path, O_RDONLY)) <= 2)
		return (console(FATAL, __func__, __LINE__, "open failed").null);
	if (!(buf = (char*)malloc(sizeof(char) * (buf_size + 1))))
		return (console(FATAL, __func__, __LINE__, "malloc failed").null);
	while ((read_len = read(fd, buf, buf_size)) > 0)
	{
		buf[read_len] = '\0';
		if (!(datas = update_data_with_buffer(datas, buf)))
			break ;
	}
	free(buf);
	return (datas);
}