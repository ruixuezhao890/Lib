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
void EXTI0_IRQHandler() {
    if (__HAL_GPIO_EXTI_GET_IT(GPIO_PIN_0) != RESET) {
        __HAL_GPIO_EXTI_CLEAR_IT(GPIO_PIN_0);
        if (function[0])
            function[0]();
    }


}


void EXTI1_IRQHandler(void) {
    if (__HAL_GPIO_EXTI_GET_IT(GPIO_PIN_1)) {
        __HAL_GPIO_EXTI_CLEAR_IT(GPIO_PIN_1);
        if (function[1]) {
            function[1]();
        }

    }

}
void EXTI2_IRQHandler(void) {
    if (__HAL_GPIO_EXTI_GET_IT(GPIO_PIN_2) != RESET) {
        __HAL_GPIO_EXTI_CLEAR_IT(GPIO_PIN_2);
        if (function[2]) {
            function[2]();
        }
    }
}
void EXTI3_IRQHandler(void) {
    if (__HAL_GPIO_EXTI_GET_IT(GPIO_PIN_3) != RESET) {
        __HAL_GPIO_EXTI_CLEAR_IT(GPIO_PIN_3);
        if (function[3])
            function[3]();
    }
}

void EXTI4_IRQHandler(void) {
    if (__HAL_GPIO_EXTI_GET_IT(GPIO_PIN_4) != RESET) {
        __HAL_GPIO_EXTI_CLEAR_IT(GPIO_PIN_4);
        if (function[4])
            function[4]();
    }
}
void EXTI9_5_IRQHandler(void) {
    for (int i = 5; i < 10; ++i) {
        auto pin_name = (0x01 << (i & 0x0f));
        if (__HAL_GPIO_EXTI_GET_IT(pin_name) != RESET) {
            __HAL_GPIO_EXTI_CLEAR_IT(pin_name);
            if (function[i]) {
                function[i]();
            }
        }

    }
}

void EXTI15_10_IRQHandler(void) {
    for (int i = 10; i < 16; ++i) {
        auto pin_name = (0x01 << (i & 0x0f));
        if (__HAL_GPIO_EXTI_GET_IT(pin_name) != RESET) {
            __HAL_GPIO_EXTI_CLEAR_IT(pin_name);
            if (function[i]) {
                function[i]();
            }
        }

    }
}
}