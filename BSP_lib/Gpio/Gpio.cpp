/**
*********************************************************************
*********
* @project_name :new_lib
* @file : Gpio.cpp
* @author : ruixuezhao890
* @brief : None
* @attention : None
* @date : 2024/8/21 
*********************************************************************
*********
*/
#include "Gpio.hpp"
call_back function[16];
extern "C" {
void EXTI0_IRQHandler(){
    function[0]();
}


void EXTI1_IRQHandler(void) {
    function[1]();
}
void EXTI2_IRQHandler(void) {
    if(__HAL_GPIO_EXTI_GET_IT(GPIO_PIN_2) != RESET) {
        __HAL_GPIO_EXTI_CLEAR_IT(GPIO_PIN_2);
        if (function[2]) {
            function[2]();
        }
    }
}
void EXTI3_IRQHandler(void) {
    function[3]();
}

void EXTI4_IRQHandler(void) {
    function[4]();
}

void EXTI9_5_IRQHandler(void) {
    for (int i = 5; i < 10; ++i) {
        if (function[i]){
            function[i]();
        }
    }
}

void EXTI15_10_IRQHandler(void) {
    for (int i = 10; i < 16; ++i) {
        if (function[i]){
            function[i]();
        }
    }
}
}