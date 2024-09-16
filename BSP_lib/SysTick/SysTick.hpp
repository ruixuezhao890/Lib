/**
*********************************************************************
*********
* @project_name :new_lib
* @file : sys_tick.hpp
* @author : ruixuezhao890
* @brief : None
* @attention : None
* @date : 2024/8/18 
*********************************************************************
*********
*/


#ifndef NEW_LIB_SYSTICK_HPP
#define NEW_LIB_SYSTICK_HPP
#include "stm32f4xx.h"

namespace SysSetTick{
    namespace InterruptsOperator{
       inline void enable(){
           SET_BIT(SysTick->CTRL, SysTick_CTRL_TICKINT_Msk);
        }
        inline void disable(){
            CLEAR_BIT(SysTick->CTRL, SysTick_CTRL_TICKINT_Msk);
       }
       inline bool is_enable(){
           return SysTick->CTRL&SysTick_CTRL_TICKINT_Msk;
       }
    };
   inline void reload(uint32_t load) { SysTick->LOAD = load; }
   inline void clear_count() { SysTick->VAL = 0; }
   inline void count(bool enable) { MODIFY_REG(SysTick->CTRL, SysTick_CTRL_CLKSOURCE_Msk | SysTick_CTRL_ENABLE_Msk, enable ?
                                                        SysTick_CTRL_CLKSOURCE_Msk | SysTick_CTRL_ENABLE_Msk : 0); }

    void sys_tick_setup(uint32_t system_clock);
    void delay(uint32_t nms);

}

#ifdef  USE_FULL_ASSERT

/**
 * @brief       当编译提示出错的时候此函数用来报告错误的文件和所在行
 * @param       file：指向源文件
 *              line：指向在文件中的行数
 * @retval      无
 */
void assert_failed(uint8_t* file, uint32_t line)
{
    while (1)
    {
    }
}
#endif
#endif //NEW_LIB_SYSTICK_HPP
