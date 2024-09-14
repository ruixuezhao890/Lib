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

extern "C" {
void EXTI0_IRQHandler(){
    function[0]();
}


void EXTI1_IRQHandler(void) {
    function[1]();
}
void EXTI2_IRQHandler(void) {
    function[2]();
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