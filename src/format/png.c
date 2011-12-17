/*!The Treasure Box Library
 * 
 * TBox is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2.1 of the License, or
 * (at your option) any later version.
 * 
 * TBox is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public License
 * along with TBox; 
 * If not, see <a href="http://www.gnu.org/licenses/"> http://www.gnu.org/licenses/</a>
 * 
 * Copyright (C) 2009 - 2011, ruki All rights reserved.
 *
 * \author		ruki
 * \file		png.c
 *
 */

/* /////////////////////////////////////////////////////////
 * includes
 */
#include "prefix.h"

/* /////////////////////////////////////////////////////////
 * interfaces
 */

tb_size_t tb_format_png_probe(tb_gstream_t* gst)
{
	tb_byte_t* p = TB_NULL;
	if (!tb_gstream_bneed(gst, &p, 8)) return 0;
	tb_assert_and_check_return_val(p, 0);

	if (p[0] == 0x89 && p[1] == 'P' && p[2] == 'N' && p[3] == 'G'
		&& p[4] == 0x0d && p[5] == 0x0a && p[6] == 0x1a && p[7] == 0x0a)
		return 80;
	else return 0;
}
