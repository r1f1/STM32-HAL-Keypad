# STM32-HAL-Keypad

## Overview

This is a simple library for [STM32 32-bit Arm Cortex MCUs](https://www.st.com/en/microcontrollers-microprocessors/stm32-32-bit-arm-cortex-mcus.html) to work with a [4x4 Matrix Keypad](http://wiki.sunfounder.cc/index.php?title=4X4_Matrix_Keypad_Module).

To develop this library it was used [STM32CubeIDE](https://www.st.com/en/development-tools/stm32cubeide.html) and [HAL APIs](https://www.st.com/resource/en/user_manual/um1725-description-of-stm32f4-hal-and-lowlayer-drivers-stmicroelectronics.pdf) to interact with peripherals and low-level resources.    

In this repository you will find the keypad library, ready to attach to your new project and a project example, tested with the STM32F4DISCOVERY board.

## Examples

**SMT32F4DISCOVERY**

Brief description of the example attached

```c++
Keypad_HandleTypeDef keypad_init(void);

uint8_t key = 0;

int main(){
    Keypad_HandleTypeDef keypad = keypad_init();
    while(1){
        while(!key_selected(&keypad, &key));
    }
}

Keypad_HandleTypeDef keypad_init(void){

    Keypad_HandleTypeDef keypad;
    
    Keypad_PinDef pin_columns[4] = {COLUMN_1_Pin, COLUMN_2_Pin, COLUMN_3_Pin, COLUMN_4_Pin};
    Keypad_PortDef port_columns[4] = { COLUMN_1_GPIO_Port, COLUMN_2_GPIO_Port, COLUMN_3_GPIO_Port, COLUMN_4_GPIO_Port };
    
    Keypad_PinDef pin_rows[4] = {ROW_1_Pin, ROW_2_Pin, ROW_3_Pin, ROW_4_Pin};
    Keypad_PortDef port_rows[4] = { ROW_1_GPIO_Port, ROW_2_GPIO_Port, ROW_3_GPIO_Port, ROW_4_GPIO_Port };
    
    keypad = keypad_create(pin_rows, port_rows, pin_columns, port_columns);
    
    return keypad;
}
```

In this example, the process will stop running until you press a button. Adding the `key` variable to the _Live Expression_ tab, while debugging, will show you the pressed key.

## Documentation

A brief documentation of the structures and functions provided by the library are shown below. For detailed instructions, refer to the doxygen compliant documentation within the `keypad.c` file.

### Macro definitions

List of macro definitions with a brief description is shown below.

| Name | Description |
|     :---:    |     ---      |
| `Keypad_PinDef`   | Macro specific to define GPIO pins data type i.e. `uint16_t`     | 
| `Keypad_PortDef`     | Macro specific to define GPIO ports data type i.e. `GPIO_TypeDef*`       | 

### Structure

List of structures provided with the library with a brief description is shown below.

| Name | Description |
|     :---:    |     ---      |
| `Keypad_HandleTypeDef`   | Struct to handle the GPIO pins and ports for columns and rows     | 

### Functions

List of functions provided with the library with a brief description is shown below.

| Name | Description |
|     :---:    |     ---      |
| `keypad_create`   | Store GPIO pins and ports and returns a `Keypad_HandleTypeDef` handler    | 
| `key_selected`   | Iterate over GPIO pins used as columns and GPIO pins used as rows until the user press a key. Once this is done the function returns 1 and overwrite the current `key` value with the new character pressed   | 


