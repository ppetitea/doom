/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 17:41:35 by lbenard           #+#    #+#             */
/*   Updated: 2020/05/02 16:51:04 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# ifdef __linux__
#  include <sys/types.h>
# else
#  include <stdint.h>
# endif

typedef u_int8_t				t_u8;
typedef int8_t					t_i8;
typedef	u_int16_t				t_u16;
typedef int16_t					t_i16;
typedef u_int32_t				t_u32;
typedef int32_t					t_i32;
typedef u_int64_t				t_u64;
typedef int64_t					t_i64;

typedef int			t_bool;

typedef enum		e_result
{
	ERROR,
	WARNING,
	OK
}					t_result;

#define	FALSE 0
#define	TRUE 1

#endif
