/**
*********************************************************************
*********
* @project_name :new_lib
* @file : Rcc.hpp
* @author : ruixuezhao890
* @brief : None
* @attention : None
* @date : 2024/8/18 
*********************************************************************
*********
*/


#ifndef NEW_LIB_RCC_HPP
#define NEW_LIB_RCC_HPP
#include "stm32f4xx.h"
namespace Rcc {

    struct ClockConfig {
        uint32_t pll_numerator; // PLL 分子
        uint32_t pll_multiplier; // PLL 倍频器
        uint32_t pll_post_divider; // PLL 分频器
        uint32_t pll_quality_factor; // PLL 质量因子
    };

    void calculate_clocks(ClockConfig &clock_config,uint8_t mod);

    struct Clocks
    {
        uint32_t system_clock_frequency;           // 系统时钟（SYSCLK）频率
        uint32_t ahb_bus_clock_frequency;          // AHB总线时钟（HCLK）频率
        uint32_t apb1_peripheral_clock_frequency;  // APB1外设时钟（PCLK1）频率
        uint32_t apb2_peripheral_clock_frequency;  // APB2外设时钟（PCLK2）频率
        uint32_t apb_q_peripheral_clock_frequency;  // APB2外设时钟（PCLK2）频率
        uint32_t ahb_clock_prescaler;              // AHB总线时钟预分频器值
        uint32_t apb1_clock_prescaler;             // APB1外设时钟预分频器值
        uint32_t apb2_clock_prescaler;             // APB2外设时钟预分频器值
        uint32_t apb_q_clock_prescaler;             // APB2外设时钟预分频器值
        uint32_t timer_clock_frequency;           // 定时器1时钟（TIM1CLK）频率
        uint32_t adc_clock_frequency;              // ADC时钟（ADCLK）频率
        uint32_t timer_clock_prescaler;           // 定时器1时钟预分频器值
        uint32_t adc_clock_prescaler;              // ADC时钟预分频器值
    };
    extern ClockConfig default_clock_config;

    extern Clocks clocks_;

    template<uint8_t clock_src>
    int clock_setup(ClockConfig &clock_config)  {

        HAL_StatusTypeDef ret = HAL_OK;
        RCC_OscInitTypeDef rcc_osc_init = {0};
        RCC_ClkInitTypeDef rcc_clk_init = {0};

        __HAL_RCC_PWR_CLK_ENABLE();                                         /* 使能PWR时钟 */

        __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);      /* 设置调压器输出电压级别，以便在器件未以最大频率工作 */

        /* 使能HSE，并选择HSE作为PLL时钟源，配置PLL1，开启USB时钟 */
        rcc_osc_init.OscillatorType = clock_src;        /* 时钟源为HSE */
        rcc_osc_init.HSEState = RCC_HSE_ON;                          /* 打开HSE */
        rcc_osc_init.PLL.PLLState = RCC_PLL_ON;                      /* 打开PLL */
        rcc_osc_init.PLL.PLLSource = RCC_PLLSOURCE_HSE;              /* PLL时钟源选择HSE */
        rcc_osc_init.PLL.PLLN = clock_config.pll_numerator;
        rcc_osc_init.PLL.PLLM = clock_config.pll_multiplier;
        rcc_osc_init.PLL.PLLP = clock_config.pll_post_divider;
        rcc_osc_init.PLL.PLLQ = clock_config.pll_quality_factor;
        ret = HAL_RCC_OscConfig(&rcc_osc_init);                      /* 初始化RCC */
        if(ret != HAL_OK)
        {
            return 1;                                                /* 时钟初始化失败，可以在这里加入自己的处理 */
        }

        /* 选中PLL作为系统时钟源并且配置HCLK,PCLK1和PCLK2 */
        rcc_clk_init.ClockType = ( RCC_CLOCKTYPE_SYSCLK \
                                    | RCC_CLOCKTYPE_HCLK \
                                    | RCC_CLOCKTYPE_PCLK1 \
                                    | RCC_CLOCKTYPE_PCLK2);

        rcc_clk_init.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;         /* 设置系统时钟时钟源为PLL */
        rcc_clk_init.AHBCLKDivider = RCC_SYSCLK_DIV1;                /* AHB分频系数为1 */
        rcc_clk_init.APB1CLKDivider = RCC_HCLK_DIV4;                 /* APB1分频系数为4 */
        rcc_clk_init.APB2CLKDivider = RCC_HCLK_DIV2;                 /* APB2分频系数为2 */
        clocks_.ahb_clock_prescaler=1;
        clocks_.apb1_clock_prescaler=4;
        clocks_.apb2_clock_prescaler=2;
        clocks_.apb_q_clock_prescaler=clock_config.pll_quality_factor;
        ret = HAL_RCC_ClockConfig(&rcc_clk_init, FLASH_LATENCY_5);   /* 同时设置FLASH延时周期为5WS，也就是6个CPU周期 */


        if(ret != HAL_OK)
        {
            return 1;                                                /* 时钟初始化失败 */
        }
        HAL_NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4);
        calculate_clocks(clock_config,clock_src);
        /* STM32F405x/407x/415x/417x Z版本的器件支持预取功能 */
        if (HAL_GetREVID() == 0x1001)
        {
            __HAL_FLASH_PREFETCH_BUFFER_ENABLE();                    /* 使能flash预取 */
        }
        return 0;
    }



} // Rcc

#endif //NEW_LIB_RCC_HPP
