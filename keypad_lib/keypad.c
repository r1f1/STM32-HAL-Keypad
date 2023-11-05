
/**
 ******************************************************************************
 * @file     Keypad.c
 * @author   Rafael Hernández Marrero (rafaelh96@gmail.com)
 * @version  V1.0
 * @date     30/10/2023 20:38:43
 * @brief	 Functions definitions available to the user for working with a 4x4 Matrix Array Keypad
 ******************************************************************************
 */

//******************************************** Includes ********************************************//
#include "keypad.h"
#include <stdio.h>

//*************************************** Matrix definition ****************************************//

// Matrix with the keypad symbols, stored in a array in the same location as they are in the physical device

const uint8_t Keys_matrix[MATRIX_ARRAY][MATRIX_ARRAY] = {
								{ 1,     2,    3,   'A' },
								{ 4,     5,    6,   'B' },
								{ 7,     8,    9,   'C' },
								{ '*',   0,   '#',  'D' }};


//************************************** Function definitions **************************************//


/**
 * @fn Keypad_HandleTypeDef keypad_create(uint16_t[], GPIO_TypeDef*[], uint16_t[], GPIO_TypeDef*[])
 * @brief Initialise the keypad handler with the GPIO pins and GPIO ports configured by the user.
 * @param pin_rows Array with the GPIO pins assigned to the ROWS.
 * @param port_rows Array with the GPIO ports assigned to the ROWS.
 * @param pin_columns Array with the GPIO pins assigned to the COLUMNS.
 * @param port_columns Array with the GPIO ports assigned to the COLUMNS.
 * @return Keypad_HandleTypeDef Keypad handler.
 */

Keypad_HandleTypeDef keypad_create(Keypad_PinDef pin_rows[], Keypad_PortDef port_rows[], Keypad_PinDef pin_columns[], Keypad_PortDef port_columns[]){
    Keypad_HandleTypeDef keypad;

    for (uint8_t i = 0; i < MATRIX_ARRAY; i++){
        keypad.pin_rows[i] = pin_rows[i];
        keypad.port_rows[i] = port_rows[i];

        keypad.pin_columns[i] = pin_columns[i];
        keypad.port_columns[i] = port_columns[i];
    }


    return keypad;
}

/**
 * @fn int32_t key_selected(Keypad_HandleTypeDef*, uint8_t*)
 * @brief Iterates every GPIO pin associated to the columns and the rows until the user press a button.
 * @param keypad Keypad handler.
 * @param key Store the matching value from the matrix.
 * @return int32_t Returns 1 if a button is pressed and 0 if not.
 */

int32_t key_selected(Keypad_HandleTypeDef *keypad, uint8_t *key){

	for (uint8_t row = 0; row < NUM_ROW; row++){

		// Set output PINs (rows) to HIGH state.
		for (uint8_t i = 0; i < NUM_ROW; i++){
			HAL_GPIO_WritePin(keypad->port_rows[i] , keypad->pin_rows[i], GPIO_PIN_SET);
		}

		// Set Output pin to LOW.
		HAL_GPIO_WritePin(keypad->port_rows[row], keypad->pin_rows[row], GPIO_PIN_RESET);

		GPIO_PinState Column_state;

		for (uint8_t col = 0; col < NUM_COL; col++){

			Column_state = HAL_GPIO_ReadPin(keypad->port_columns[col], keypad->pin_columns[col]);

			if (!Column_state){
				HAL_Delay(500);
				*key = Keys_matrix[row][col];
				return 1;
			}

		}

	}
	return 0;
}
