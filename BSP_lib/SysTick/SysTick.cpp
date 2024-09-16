/**
*********************************************************************
*********
* @project_name :new_lib
* @file : sys_tick.cpp
* @author : ruixuezhao890
* @brief : None
* @attention : None
* @date : 2024/8/18 
*********************************************************************
*********
*/


#include "SysTick.hpp"

void SysSetTick::delay(uint32_t nms)  {
    while (nms)
    {
        nms -= ((SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk) != 0U);
    }
}

void SysSetTick::sys_tick_setup(uint32_t system_clock) {
    SysTick_Config(system_clock);
    __NVIC_EnableIRQ(SysTick_IRQn);
}
