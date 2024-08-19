/**
*********************************************************************
*********
* @project_name :new_lib
* @file : Rcc.cpp
* @author : ruixuezhao890
* @brief : None
* @attention : None
* @date : 2024/8/18 
*********************************************************************
*********
*/


#include "rcc.hpp"
#include "main.h"

#ifndef HSE
#define HSE 8000000U
#endif // !HSE

#ifndef HSI
#define HSI 8000000U
#endif // !HSI
namespace Rcc {
    Clocks clocks_;
    ClockConfig default_clock_config{
            .pll_numerator=336,
            .pll_multiplier=8,
            .pll_post_divider=2,
            .pll_quality_factor=7
    };
    void calculate_clocks(ClockConfig &clock_config,uint8_t mod) {
        uint32_t temp_clock=0;
        if (mod==RCC_OSCILLATORTYPE_HSE){
            temp_clock=(HSE*clock_config.pll_numerator/clock_config.pll_multiplier);
        }else{
            temp_clock=(HSI*clock_config.pll_numerator/clock_config.pll_multiplier);
        }
        clocks_.system_clock_frequency=temp_clock/clock_config.pll_post_divider;
        clocks_.ahb_bus_clock_frequency=clocks_.system_clock_frequency;
        clocks_.apb1_peripheral_clock_frequency=clocks_.ahb_bus_clock_frequency/clocks_.apb1_clock_prescaler;
        clocks_.apb2_peripheral_clock_frequency=clocks_.ahb_bus_clock_frequency/clocks_.apb2_clock_prescaler;
        clocks_.apb_q_peripheral_clock_frequency=temp_clock/clocks_.apb_q_clock_prescaler;
    }
} // Rcc