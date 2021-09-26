/*!
 * \file
 * \brief COMMON constants, macros, functions header file
 * \author Dawid Babula
 * \email dbabula@adventurous.pl
 *
 * \par Copyright (C) Dawid Babula, 2016
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */
#ifndef COMMON_H
#define COMMON_H

#include <stdint.h>
/*!
 *
 * \addtogroup common
 * \ingroup drivers
 * \brief Common constants, macros and functions
 */

/*@{*/

#ifndef INLINE_SPECIFIER
#define INLINE_SPECIFIER inline
#endif

/*!
 * \brief Definition of static assert macro
 */
#define STATIC_ASSERT(COND, MSG) typedef char static_assertion_##MSG[(COND)?1:-1]

/*!
 * \brief Dummy function prototype to silence compiler warning
 */
void COMMON_dummy(void);

/*@}*/
#endif
