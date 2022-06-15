/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maingnl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carys <carys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 18:14:57 by carys             #+#    #+#             */
/*   Updated: 2022/06/15 13:46:15 by carys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"


int	main(void)
{
	int		fd;
	char	*res;

	
	fd = 0;
//	fd = open("get_next_line.h",O_RDONLY);
	res = get_next_line(fd);

	while (res)
	{
		printf("%s\n", res);
		free(res);
		res = get_next_line(fd);
	}
	close(fd);
	return (0);
}
