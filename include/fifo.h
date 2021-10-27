/*!
 * \file
 * \brief FIFO ADT header file
 * \author Dawid Babula
 * \email dbabula@adventurous.pl
 *
 * \par Copyright (C) Dawid Babula, 2018
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

#ifndef FIFO_H
#define FIFO_H

/*!
 *
 * \addtogroup fifo
 * \ingroup drivers
 * \brief FIFO ADT implementation
 */

/*@{*/

#include <stdint.h>

/*!
 * \brief Defines maximal amount of elements in fifo
 */
#define FIFO_ELEMENTS_MAX UINT16_MAX

typedef uint16_t FIFO_elements_no_t;

/*!
 * \brief Fifo configuration structure
 */
typedef struct
{
    FIFO_elements_no_t elements_no; /*!< Amount of elements */
    uint8_t elements_size; /*!< Size of element */
    uint8_t *buffer; /*!< External fifo buffer */
} FIFO_config_t;

/*!
 * \brief Fifo internal structure
 */
typedef struct
{
    FIFO_elements_no_t head; /*!< Fifo head, moves by enqueing */
    FIFO_elements_no_t tail; /*!< Fifo tail, moves by dequeing */
    FIFO_config_t config; /*!< Fifo configuration */
} FIFO_t;

/*!
 * \brief Enqueues element into the fifo
 *
 * \param fifo  reference to the interal fifo structure
 * \param data  reference to the element to be enqueued
 *
 * \retval 0 success
 * \retval -1 failure, fifo is full
 */
int8_t FIFO_enqueue(FIFO_t *fifo, const void *data);

/*!
 * \brief Dequeues element from the fifo
 *
 * \param fifo  reference to the interal fifo structure
 * \param data  reference to the storage where element is going to be denqueued
 *
 * \retval 0 success
 * \retval -1 failure, fifo is empty
 */
int8_t FIFO_dequeue(FIFO_t *fifo, void *data);


/*!
 * \brief Gets amount of elements, which are possible to be enqueued
 *
 * \param fifo  reference to the interal fifo structure
 *
 * \return amount of elements possible for enqueing
 */
FIFO_elements_no_t FIFO_get_free(const FIFO_t *fifo);


/*!
 * \brief Gets amount of elements, which are possible to be denqueued
 *
 * \param fifo  reference to the interal fifo structure
 *
 * \return amount of elements possible for denqueing
 */
FIFO_elements_no_t FIFO_get_occupied(const FIFO_t *fifo);

/*!
 * \brief Configures fifo ADT
 *
 * \param fifo  reference to the interal fifo structure
 * \param config  reference to the configuration structure
 */
void FIFO_configure(FIFO_t *fifo, const FIFO_config_t *config);

/*@}*/
#endif
