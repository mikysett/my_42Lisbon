/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_constants.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 13:45:38 by msessa            #+#    #+#             */
/*   Updated: 2021/04/10 22:14:01 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONSTANTS_H
# define FT_CONSTANTS_H

# define BUFFER_SIZE	64

# define IS_OS_MAC		0

#  define MIN_RES_X		300
#  define MIN_RES_Y		300
#  define MAX_RES_X		1820
#  define MAX_RES_Y		1000

# define MIN_MAP_PARAMS	9
# define NB_DIRECTIONS	9
# define NB_CELL_POS	2048
# define CAMERA_DIST	1024
# define WALK_STEP		128

# define NB_SETTINGS	2
# define NB_TEX			4
# define TEX_SIZE		64

# define FOV_66			1.151917306
# define PI				3.141592654
# define ONE_DEGREE		0.017453293
# define FULL_CIRCLE	6.283185307
# define DEGREES_270	4.71238898
# define DEGREES_180	3.141592654
# define DEGREES_90		1.570796327
# define DEGREES_45		0.785398163
# define DEGREES_33		0.575958653

# define MINI_MAP_WIDTH		280
# define MINI_MAP_HEIGHT	280
# define MINI_MAP_CELL_SIZE	14
# define MINI_MAP_PADDING	20
# define PLAYER_SIZE		4
# define DIR_DISTANCE		10
# define CLR_BG			0x44000044
# define CLR_FLOOR		0x44000022
# define CLR_WALL		0x44000088
# define CLR_PLAYER		0x44880000
# define CLR_DIR		0x44008800

# if IS_OS_MAC == 1
#  define KEY_ARR_LEFT	123
#  define KEY_ARR_RIGHT	124
#  define KEY_ARR_UP	126
#  define KEY_ARR_DOWN	125
#  define KEY_ESC		53
#  define KEY_MOV_LEFT	0
#  define KEY_MOV_RIGHT	2
#  define KEY_MOV_UP	13
#  define KEY_MOV_DOWN	1
#  define KEY_SPACE		49
#  define KEY_SHOW_FPS	3
#  define KEY_SHOW_MM	46

#  define DESTROY_NOTIFY	17
#  define DESTROY_NOTIFY_M	131072
#  define KEY_PRESS			2
#  define KEY_PRESS_M		1
#  define KEY_RELEASE		3
#  define KEY_RELEASE_M		2
# else
#  define KEY_ARR_LEFT	65361
#  define KEY_ARR_RIGHT	65363
#  define KEY_ARR_UP	65362
#  define KEY_ARR_DOWN	65364
#  define KEY_ESC		65307
#  define KEY_MOV_LEFT	97
#  define KEY_MOV_RIGHT	100
#  define KEY_MOV_UP	119
#  define KEY_MOV_DOWN	115
#  define KEY_SPACE		32
#  define KEY_SHOW_FPS	'f'
#  define KEY_SHOW_MM	'm'

#  define DESTROY_NOTIFY	33
#  define DESTROY_NOTIFY_M	0
#  define KEY_PRESS			2
#  define KEY_PRESS_M		1
#  define KEY_RELEASE		3
#  define KEY_RELEASE_M		2
# endif

#endif