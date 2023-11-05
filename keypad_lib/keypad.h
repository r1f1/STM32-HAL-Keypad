
/**
 ******************************************************************************
 * @file     Keypad.h
 * @author   Rafael Hernández Marrero (rafaelh96@gmail.com)
 * @version  V1.0
 * @date     30/10/2023 20:38:43
 * @brief	 Functions declarations available to the user for working with a 4x4 Matrix Array Keypad
 ******************************************************************************
 */

#ifndef KEYPAD_H_
#define KEYPAD_H_

//******************************************** Includes ********************************************//

#include <stdint.h>
#include "stm32f4xx_hal.h"

//******************************************** Helper Macros ********************************************//

#define MATRIX_ARRAY			4
#define NUM_COL					MATRIX_ARRAY
#define NUM_ROW					MATRIX_ARRAY

//******************************************** Keypad types ********************************************//

#define Keypad_PinDef uint16_t
#define Keypad_PortDef GPIO_TypeDef*


/**
 * @struct Keypad_HandleTypeDef keypad.h "keypad.h"
 * @brief Store GPIO pins and ports in their corresponding struct member.
 *
 */
typedef struct{

	Keypad_PinDef pin_rows[MATRIX_ARRAY];
	Keypad_PortDef port_rows[MATRIX_ARRAY];

	Keypad_PinDef pin_columns[MATRIX_ARRAY];
	Keypad_PortDef port_columns[MATRIX_ARRAY];

}Keypad_HandleTypeDef;

//************************************** Function declarations **************************************//


Keypad_HandleTypeDef keypad_create(Keypad_PinDef [], Keypad_PortDef [], Keypad_PinDef [], Keypad_PortDef []);

int32_t key_selected(Keypad_HandleTypeDef*, uint8_t*);


#endif /* KEYPAD_H_ */
