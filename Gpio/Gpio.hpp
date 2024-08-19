/**
*********************************************************************
*********
* @project_name :new_lib
* @file : Gpio.hpp
* @author : ruixuezhao890
* @brief : None
* @attention : None
* @date : 2024/8/18
*********************************************************************
*********
*/


#ifndef NEW_LIB_GPIO_HPP
#define NEW_LIB_GPIO_HPP
#include "stm32f4xx.h"


namespace Io {
    template <uint32_t Base, uint8_t Pin>
    struct GpioHelper
    {
        static constexpr uint32_t base = Base;
        static constexpr uint8_t pin = Pin;
        static constexpr bool is_valid = false;
    };

#ifdef GPIOA_BASE

    template <uint8_t Pin>
    struct GpioHelper<GPIOA_BASE, Pin>
    {
        static constexpr size_t id = 0;
        static constexpr uint32_t base = GPIOA_BASE;
        static constexpr uint8_t pin = Pin;
        static constexpr bool is_valid = Pin < 16;
        static void clock(bool enable) {
            if (enable){
                __HAL_RCC_GPIOA_CLK_ENABLE();
            } else{
                __HAL_RCC_GPIOA_CLK_DISABLE();
            }
        }
    };

#endif // GPIOA_BASE

#ifdef GPIOB_BASE

    template <uint8_t Pin>
    struct GpioHelper<GPIOB_BASE, Pin>
    {
        static constexpr size_t id = 1;
        static constexpr uint32_t base = GPIOB_BASE;
        static constexpr uint8_t pin = Pin;
        static constexpr bool is_valid = Pin < 16;
        static void clock(bool enable) {
            if (enable){
                __HAL_RCC_GPIOB_CLK_ENABLE();
            } else{
                __HAL_RCC_GPIOB_CLK_DISABLE();
            }
        }
    };

#endif // GPIOB_BASE

#ifdef GPIOC_BASE

    template <uint8_t Pin>
    struct GpioHelper<GPIOC_BASE, Pin>
    {
        static constexpr size_t id = 2;
        static constexpr uint32_t base = GPIOC_BASE;
        static constexpr uint8_t pin = Pin;
        static constexpr bool is_valid = Pin < 16;
        static void clock(bool enable) {
            if (enable){
                __HAL_RCC_GPIOC_CLK_ENABLE();
            } else{
                __HAL_RCC_GPIOC_CLK_DISABLE();
            }
        }
    };

#endif // GPIOC_BASE

#ifdef GPIOD_BASE

    template <uint8_t Pin>
    struct GpioHelper<GPIOD_BASE, Pin>
    {
        static constexpr size_t id = 3;
        static constexpr uint32_t base = GPIOD_BASE;
        static constexpr uint8_t pin = Pin;
        static constexpr bool is_valid = Pin < 16;
        static void clock(bool enable) {
            if (enable){
                __HAL_RCC_GPIOD_CLK_ENABLE();
            } else{
                __HAL_RCC_GPIOD_CLK_DISABLE();
            }
        }
    };

#endif // GPIOD_BASE

#ifdef GPIOE_BASE

    template <uint8_t Pin>
    struct GpioHelper<GPIOE_BASE, Pin>
    {
        static constexpr size_t id = 4;
        static constexpr uint32_t base = GPIOE_BASE;
        static constexpr uint8_t pin = Pin;
        static constexpr bool is_valid = Pin < 16;
        static void clock(bool enable) {
            if (enable){
                __HAL_RCC_GPIOE_CLK_ENABLE();
            } else{
                __HAL_RCC_GPIOE_CLK_DISABLE();
            }
        }
    };

#endif // GPIOE_BASE

#ifdef GPIOF_BASE

    template <uint8_t Pin>
    struct GpioHelper<GPIOF_BASE, Pin>
    {
        static constexpr size_t id = 5;
        static constexpr uint32_t base = GPIOF_BASE;
        static constexpr uint8_t pin = Pin;
        static constexpr bool is_valid = Pin < 16;
        static void clock(bool enable) {
            if (enable){
                __HAL_RCC_GPIOF_CLK_ENABLE();
            } else{
                __HAL_RCC_GPIOF_CLK_DISABLE();
            }
        }
    };

#endif // GPIOF_BASE

#ifdef GPIOG_BASE

    template <uint8_t Pin>
    struct GpioHelper<GPIOG_BASE, Pin>
    {
        static constexpr size_t id = 6;
        static constexpr uint32_t base = GPIOG_BASE;
        static constexpr uint8_t pin = Pin;
        static constexpr bool is_valid = Pin < 16;
        static void clock(bool enable) {
            if (enable){
                __HAL_RCC_GPIOG_CLK_ENABLE();
            } else{
                __HAL_RCC_GPIOG_CLK_DISABLE();
            }
        }
    };

#endif // GPIOG_BASE
#ifdef GPIOH_BASE

    template <uint8_t Pin>
    struct GpioHelper<GPIOH_BASE, Pin>
    {
        static constexpr size_t id = 7;
        static constexpr uint32_t base = GPIOH_BASE;
        static constexpr uint8_t pin = Pin;
        static constexpr bool is_valid = Pin < 16;
        static void clock(bool enable) {
            if (enable){
                __HAL_RCC_GPIOH_CLK_ENABLE();
            } else{
                __HAL_RCC_GPIOH_CLK_DISABLE();
            }
        }
    };

#endif // GPIOH_BASE
#ifdef GPIOI_BASE

    template <uint8_t Pin>
    struct GpioHelper<GPIOI_BASE, Pin>
    {
        static constexpr size_t id = 8;
        static constexpr uint32_t base = GPIOI_BASE;
        static constexpr uint8_t pin = Pin;
        static constexpr bool is_valid = Pin < 16;
        static void clock(bool enable) {
            if (enable){
                __HAL_RCC_GPIOI_CLK_ENABLE();
            } else{
                __HAL_RCC_GPIOI_CLK_DISABLE();
            }
        }
    };

#endif // GPIOI_BASE
#ifdef GPIOJ_BASE

    template <uint8_t Pin>
    struct GpioHelper<GPIOJ_BASE, Pin>
    {
        static constexpr size_t id = 9;
        static constexpr uint32_t base = GPIOJ_BASE;
        static constexpr uint8_t pin = Pin;
        static constexpr bool is_valid = Pin < 16;
        static void clock(bool enable) {
            if (enable){
                __HAL_RCC_GPIOJ_CLK_ENABLE();
            } else{
                __HAL_RCC_GPIOJ_CLK_DISABLE();
            }
        }
    };

#endif // GPIOJ_BASE
    template <uint32_t Base, uint8_t Pin>
    class Gpio{
    private:
        static GPIO_TypeDef * instance_;
        static GPIO_InitTypeDef gpio_initTypeDef;
    public:
        using Helper = GpioHelper<Base, Pin>;
        static constexpr size_t id = Helper::id;
        static constexpr uint32_t base = Base;
        static constexpr uint8_t pin = Pin;
        static constexpr bool is_valid = Helper::is_valid;
        static_assert(is_valid, "Invalid Base or Pin");

        static void clock(bool enable);

        template<uint8_t mode>
        static inline void set_mode(uint8_t speed,uint8_t pull,uint8_t alt){
            gpio_initTypeDef.Pin=1 <<(Pin&0x0f);
            gpio_initTypeDef.Mode=mode;
            gpio_initTypeDef.Speed=speed?speed:GPIO_SPEED_MEDIUM;
            gpio_initTypeDef.Pull=pull?pull:GPIO_NOPULL;
            gpio_initTypeDef.Alternate=alt?alt:255;
            HAL_GPIO_Init(instance_,&gpio_initTypeDef);
        }

       static inline void set(){
           instance_->BSRR=(0x01<<(Pin&0x0f));

       }

       static inline void toggle(){
           auto odr = instance_->ODR;
            auto t=1<<(Pin&0x0f);
           instance_->BSRR = ((odr & t) << 16U) | (~odr & t);
       }

       static inline void reset(){
           auto t=1<<(Pin&0x0f);
           instance_->BSRR=(uint32_t )(t)<<16U;
       }
       static inline bool read(){
         return (instance_->IDR & (1<<(Pin & 0x0f)))!= 0;
       }
       static inline bool lock(){
           __IO uint32_t tmp = GPIO_LCKR_LCKK;
            auto PIN=(1<<(Pin&0x0f));
            tmp|=PIN;
            instance_->LCKR=tmp;
            instance_->LCKR = PIN; // 设置GPIO_Pin位
            instance_->LCKR = tmp;     // 再次设置GPIO_Pin位和LCKK位
           tmp = instance_->LCKR;
           if ((instance_->LCKR & GPIO_LCKR_LCKK) != 0) {
               return HAL_OK;
           }
           return HAL_ERROR;
       }
    };

#ifdef GPIOA_BASE

    template <uint8_t Pin = 0>
    using PA = Gpio<GPIOA_BASE, Pin>;

    template <uint8_t Pin = 0>
    PA<Pin> pa;

#endif // GPIOA_BASE

#ifdef GPIOB_BASE

    template <uint8_t Pin = 0>
    using PB = Gpio<GPIOB_BASE, Pin>;

    template <uint8_t Pin = 0>
    PB<Pin> pb;

#endif // GPIOB_BASE

#ifdef GPIOC_BASE

    template <uint8_t Pin = 0>
    using PC = Gpio<GPIOC_BASE, Pin>;

    template <uint8_t Pin = 0>
    PC<Pin> pc;

#endif // GPIOC_BASE

#ifdef GPIOD_BASE

    template <uint8_t Pin = 0>
    using PD = Gpio<GPIOD_BASE, Pin>;

    template <uint8_t Pin = 0>
    PD<Pin> pd;

#endif // GPIOD_BASE

#ifdef GPIOE_BASE

    template <uint8_t Pin = 0>
    using PE = Gpio<GPIOE_BASE, Pin>;

    template <uint8_t Pin = 0>
    PE<Pin> pe;

#endif // GPIOE_BASE

#ifdef GPIOF_BASE

    template <uint8_t Pin = 0>
    using PF = Gpio<GPIOF_BASE, Pin>;

    template <uint8_t Pin = 0>
    PF<Pin> pf;

#endif // GPIOF_BASE

#ifdef GPIOG_BASE

    template <uint8_t Pin = 0>
    using PG = Gpio<GPIOG_BASE, Pin>;

    template <uint8_t Pin = 0>
    PG<Pin> pg;

#endif // GPIOG_BASE

    template <uint32_t Base, uint8_t Pin>
    GPIO_TypeDef *Gpio<Base, Pin>::instance_ = (GPIO_TypeDef *)Base;

    template <uint32_t Base, uint8_t Pin>
    GPIO_InitTypeDef Gpio<Base, Pin>::gpio_initTypeDef{0};


    template <uint32_t Base, uint8_t Pin>
    inline void Gpio<Base, Pin>::clock(bool enable)
    {
        Helper::clock(enable);
    }

    template <uint8_t mode, typename... Ts>
    inline void ConfigPins(uint8_t speed,uint8_t pull,uint8_t alt) {
        ((Ts::template set_mode<mode>(speed,pull,alt)),...);
    }
    template <typename... Ts>
    inline void ConfigPPOut(uint8_t speed=0,uint8_t pull=0) {
        ConfigPins<GPIO_MODE_OUTPUT_PP, Ts...>(speed,pull,0);
    }

    template <typename... Ts>
    inline void ConfigODOut(uint8_t pull=0,uint8_t speed=0) {
        ConfigPins<GPIO_MODE_OUTPUT_OD, Ts...>(speed,pull,0);
    }

    template <typename... Ts>
    inline void ConfigAfPPOut(uint8_t alt=0,uint8_t speed=0,uint8_t pull=0) {
        ConfigPins<GPIO_MODE_AF_PP, Ts...>(speed,pull,alt);
    }
    template <typename... Ts>
    inline void ConfigAfODOut(uint8_t alt=0,uint8_t pull=0,uint8_t speed=0) {
        ConfigPins<GPIO_MODE_AF_OD, Ts...>(speed,pull,alt);
    }
    template <typename... Ts>
    inline void ConfigFloatInput(uint8_t pull=0,uint8_t speed=0) {
        ConfigPins<GPIO_MODE_OUTPUT_OD, Ts...>(speed,pull,0);
    }
} // Io

#endif //NEW_LIB_GPIO_HPP
