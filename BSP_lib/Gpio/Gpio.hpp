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
#include "BitBand/BitBand.hpp"
#define EXIT_SET(x) EXTI##x##_IRQn


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

struct ExtiPrBit : public BitOperater
{
    inline ExtiPrBit(uint8_t bitnum) : BitOperater(EXTI->PR, bitnum) {}
    inline bool is_set(void) const { return bitband; }
    inline void clear(void) { bitband = 1; }
};

    template <uint32_t Base, uint8_t Pin>
    class Gpio{
    private:
        static GPIO_TypeDef * instance_;
        static GPIO_InitTypeDef gpio_initTypeDef;
    public:
        using Helper = GpioHelper<Base, Pin>;
        static constexpr size_t id = Helper::id;
        static constexpr uint32_t base = Base;
        static constexpr uint16_t pin = (0x01<<(Pin&0x0f));
        static constexpr IRQn_Type EXTIx =(IRQn_Type)(Pin <= 4 ? 0 + Pin :Pin <= 9 ? EXTI9_5_IRQn :Pin <= 15 ? EXTI15_10_IRQn :0);

        static constexpr bool is_valid = Helper::is_valid;
        static_assert(is_valid, "Invalid Base or Pin");
/****************************************************************************************************************************************/
        struct Over{
            static void verify(){
                HAL_GPIO_Init(instance_,&gpio_initTypeDef);
            }
            static void verify_it(){
                HAL_GPIO_Init(instance_,&gpio_initTypeDef);
                __NVIC_EnableIRQ(EXTIx);
            }
        };
        struct Input
        {
            static Over analog();
            static Over floating();
            static Over pull_up();
            static Over pull_down();
        };
        struct Output
        {
            static Over push_pull();
            static Over open_drain();
            static Over alternate_push_pull();
            static Over alternate_open_drain();
        };


        static Input  into_input();
        static Output into_output();
        static Output into_output_medium_mhz();
        static Output into_output_low_mhz();
        static Output into_output_high_mhz();
        static Output into_output_very_high_mhz();

/*******************************************************************************************************************************************************************/
        static void clock(bool enable);
        static void clock_enable(bool enable);
        static void clock_disable(bool enable);

        template<uint8_t mode>
        static inline void set_mode(uint8_t speed,uint8_t pull,uint8_t alt){
            gpio_initTypeDef.Pin=pin;
            gpio_initTypeDef.Mode=mode;
            gpio_initTypeDef.Speed=speed?speed:GPIO_SPEED_FREQ_MEDIUM;
            gpio_initTypeDef.Pull=pull?pull:GPIO_NOPULL;
            gpio_initTypeDef.Alternate=alt?alt:255;
            HAL_GPIO_Init(instance_,&gpio_initTypeDef);
        }

       static inline void set(){
           instance_->BSRR=pin;

       }

       static inline void toggle(){
           auto odr = instance_->ODR;

           instance_->BSRR = ((odr & pin) << 16U) | (~odr & pin);
       }

       static inline void reset(){
           auto t=1<<(Pin&0x0f);
           instance_->BSRR=(uint32_t )(t)<<16U;
       }
       static inline bool read(){
         return (instance_->IDR & (pin))!= 0;
       }
       static inline bool lock(){
           __IO uint32_t tmp = GPIO_LCKR_LCKK;
            auto PIN=(pin);
            tmp|=PIN;
            instance_->LCKR=tmp;
            instance_->LCKR = PIN; // 设置GPIO_Pin位
            instance_->LCKR = tmp;     // 再次设置GPIO_Pin位和LCKK位
            tmp = instance_->LCKR;
           if ((instance_->LCKR & GPIO_LCKR_LCKK) != 0) {
               return false;
           }
           return true;
       }


       /******************************************************************************************************************************************************************/

        static void enable_interrupt_from_exti_rising(uint32_t PreemptPriority=3, uint32_t SubPriority=3);
        static void enable_interrupt_from_exti_falling(uint32_t PreemptPriority=3, uint32_t SubPriority=3);
        static void enable_interrupt_from_exti_rising_falling(uint32_t PreemptPriority=3, uint32_t SubPriority=3);

        static void enable_event_from_exti_rising(uint32_t PreemptPriority=3, uint32_t SubPriority=3);
        static void enable_event_from_exti_falling(uint32_t PreemptPriority=3, uint32_t SubPriority=3);
        static void enable_event_from_exti_rising_falling(uint32_t PreemptPriority=3, uint32_t SubPriority=3);

        static void disable_interrupt();


       /******************************************************************************************************************************************************************/
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

#ifdef GPIOH_BASE

    template <uint8_t Pin = 0>
    using PH = Gpio<GPIOH_BASE, Pin>;

    template <uint8_t Pin = 0>
    PG<Pin> ph;

#endif // GPIOH_BASE

#ifdef GPIOI_BASE

    template <uint8_t Pin = 0>
    using PI = Gpio<GPIOI_BASE, Pin>;

    template <uint8_t Pin = 0>
    PG<Pin> pi;

#endif // GPIOI_BASE


#ifdef GPIOJ_BASE

    template <uint8_t Pin = 0>
    using PJ = Gpio<GPIOJ_BASE, Pin>;

    template <uint8_t Pin = 0>
    PG<Pin> pj;

#endif // GPIOJ_BASE

    template <typename T>
    struct is_specialization_of_gpio
    {
        static constexpr bool value = false;
    };

    template <uint32_t Base, uint8_t Pin>
    struct is_specialization_of_gpio<Gpio<Base, Pin>>
    {
        static constexpr bool value = Gpio<Base, Pin>::is_valid;
    };

    template <uint32_t Base, uint8_t Pin>
    GPIO_TypeDef *Gpio<Base, Pin>::instance_ = (GPIO_TypeDef *)Base;

    template <uint32_t Base, uint8_t Pin>
    GPIO_InitTypeDef Gpio<Base, Pin>::gpio_initTypeDef{0};


    template<uint32_t Base, uint8_t Pin>
    inline typename Gpio<Base, Pin>::Input Gpio<Base, Pin>::into_input() {
        gpio_initTypeDef.Pin=pin;
        gpio_initTypeDef.Mode=GPIO_MODE_INPUT;
        return Input{};
    }

    template<uint32_t Base, uint8_t Pin>
    inline typename Gpio<Base, Pin>::Output Gpio<Base, Pin>::into_output() {
        gpio_initTypeDef.Pin=pin;
        gpio_initTypeDef.Mode=GPIO_MODE_OUTPUT_PP;
        gpio_initTypeDef.Speed=GPIO_SPEED_FREQ_MEDIUM;

        return Output{};
    }

    template<uint32_t Base, uint8_t Pin>
    inline typename Gpio<Base, Pin>::Output Gpio<Base, Pin>::into_output_medium_mhz() {
        gpio_initTypeDef.Pin=pin;
        gpio_initTypeDef.Mode=GPIO_MODE_OUTPUT_PP;
        gpio_initTypeDef.Speed=GPIO_SPEED_FREQ_MEDIUM;
        return Output{};
    }

    template<uint32_t Base, uint8_t Pin>
    inline typename Gpio<Base, Pin>::Output Gpio<Base, Pin>::into_output_low_mhz() {
        gpio_initTypeDef.Pin=pin;
        gpio_initTypeDef.Mode=GPIO_MODE_OUTPUT_PP;
        gpio_initTypeDef.Speed=GPIO_SPEED_FREQ_LOW;
        return Output{};
    }

    template<uint32_t Base, uint8_t Pin>
    inline typename Gpio<Base, Pin>::Output Gpio<Base, Pin>::into_output_high_mhz() {
        gpio_initTypeDef.Pin=pin;
        gpio_initTypeDef.Mode=GPIO_MODE_OUTPUT_PP;
        gpio_initTypeDef.Speed=GPIO_SPEED_FREQ_HIGH;
        return Output{};
    }

    template<uint32_t Base, uint8_t Pin>
    inline typename Gpio<Base, Pin>::Output Gpio<Base, Pin>::into_output_very_high_mhz() {
        gpio_initTypeDef.Pin=pin;
        gpio_initTypeDef.Mode=GPIO_MODE_OUTPUT_PP;
        gpio_initTypeDef.Speed=GPIO_SPEED_FREQ_VERY_HIGH;
        return Output{};
    }

template<uint32_t Base, uint8_t Pin>
inline typename Gpio<Base, Pin>::Over Gpio<Base, Pin>::Input::analog() {
    gpio_initTypeDef.Mode=GPIO_MODE_ANALOG;
    return Over{};
}

template<uint32_t Base, uint8_t Pin>
inline typename Gpio<Base, Pin>::Over Gpio<Base, Pin>::Input::floating() {
    gpio_initTypeDef.Pull=GPIO_NOPULL;
    return Over{};
}

template<uint32_t Base, uint8_t Pin>
inline typename Gpio<Base, Pin>::Over Gpio<Base, Pin>::Input::pull_up() {
    gpio_initTypeDef.Pull=GPIO_PULLUP;
    return Over{};
}

template<uint32_t Base, uint8_t Pin>
inline typename Gpio<Base, Pin>::Over Gpio<Base, Pin>::Input::pull_down() {
    gpio_initTypeDef.Pull=GPIO_PULLDOWN;
    return Over{};
}

template<uint32_t Base, uint8_t Pin>
inline typename Gpio<Base, Pin>::Over Gpio<Base, Pin>::Output::push_pull() {
    gpio_initTypeDef.Mode=GPIO_MODE_OUTPUT_PP;
    gpio_initTypeDef.Speed=GPIO_SPEED_FREQ_MEDIUM;
    return Over{};
}

template<uint32_t Base, uint8_t Pin>
inline typename Gpio<Base, Pin>::Over Gpio<Base, Pin>::Output::open_drain() {
    gpio_initTypeDef.Pull=GPIO_MODE_OUTPUT_OD;
    return Over{};
}

template<uint32_t Base, uint8_t Pin>
inline typename Gpio<Base, Pin>::Over Gpio<Base, Pin>::Output::alternate_push_pull() {
    gpio_initTypeDef.Pull=GPIO_MODE_AF_PP;
    return Over{};
}

template<uint32_t Base, uint8_t Pin>
inline typename Gpio<Base, Pin>::Over Gpio<Base, Pin>::Output::alternate_open_drain() {
    gpio_initTypeDef.Pull=GPIO_MODE_AF_OD;
    return Over{};
}


    template <uint32_t Base, uint8_t Pin>
    inline void Gpio<Base, Pin>::clock(bool enable)
    {
        Helper::clock(enable);
    }

    template<uint32_t Base, uint8_t Pin>
    void Gpio<Base, Pin>::clock_enable(bool enable) {
        Helper::clock(true);
    }

    template<uint32_t Base, uint8_t Pin>
    void Gpio<Base, Pin>::clock_disable(bool enable) {
        Helper::clock(false);
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
        ConfigPins<GPIO_MODE_INPUT, Ts...>(speed,pull,0);
    }

    template <typename... Ts>
    inline void ConfigFloatUpInput(uint8_t speed=0) {
        ConfigPins<GPIO_MODE_INPUT, Ts...>(speed,GPIO_PULLUP,0);
    }

    template <typename... Ts>
    inline void ConfigFloatDownInput(uint8_t speed=0) {
        ConfigPins<GPIO_MODE_INPUT, Ts...>(speed,GPIO_PULLDOWN,0);
    }

    template <typename... Ts>
    inline void ConfigAnalogInput(uint8_t pull=0,uint8_t speed=0) {
        ConfigPins<GPIO_MODE_ANALOG, Ts...>(speed,pull,0);
    }

    template<uint32_t Base, uint8_t Pin>
    void Gpio<Base, Pin>::enable_interrupt_from_exti_rising(uint32_t PreemptPriority, uint32_t SubPriority) {
        gpio_initTypeDef.Mode=GPIO_MODE_IT_RISING;
        HAL_NVIC_SetPriority(EXTIx,PreemptPriority,SubPriority);
        Over::verify_it();
    }

    template<uint32_t Base, uint8_t Pin>
    void Gpio<Base, Pin>::enable_interrupt_from_exti_falling(uint32_t PreemptPriority, uint32_t SubPriority) {
        gpio_initTypeDef.Mode=GPIO_MODE_IT_FALLING;
        HAL_NVIC_SetPriority(EXTIx,PreemptPriority,SubPriority);
        Over::verify_it();
    }

    template<uint32_t Base, uint8_t Pin>
    void Gpio<Base, Pin>::enable_interrupt_from_exti_rising_falling(uint32_t PreemptPriority, uint32_t SubPriority) {
        gpio_initTypeDef.Mode=GPIO_MODE_IT_RISING_FALLING;
        HAL_NVIC_SetPriority(EXTIx,PreemptPriority,SubPriority);
        Over::verify_it();
    }

    template<uint32_t Base, uint8_t Pin>
    void Gpio<Base, Pin>::enable_event_from_exti_rising(uint32_t PreemptPriority, uint32_t SubPriority) {
        gpio_initTypeDef.Mode=GPIO_MODE_EVT_RISING;
        HAL_NVIC_SetPriority(EXTIx,PreemptPriority,SubPriority);
        Over::verify_it();
    }

    template<uint32_t Base, uint8_t Pin>
    void Gpio<Base, Pin>::enable_event_from_exti_falling(uint32_t PreemptPriority, uint32_t SubPriority) {
        gpio_initTypeDef.Mode=GPIO_MODE_EVT_FALLING;
        HAL_NVIC_SetPriority(EXTIx,PreemptPriority,SubPriority);
        Over::verify_it();
    }

    template<uint32_t Base, uint8_t Pin>
    void Gpio<Base, Pin>::enable_event_from_exti_rising_falling(uint32_t PreemptPriority, uint32_t SubPriority) {
        gpio_initTypeDef.Mode=GPIO_MODE_EVT_RISING_FALLING;
        HAL_NVIC_SetPriority(EXTIx,PreemptPriority,SubPriority);
        Over::verify_it();
    }

    template<uint32_t Base, uint8_t Pin>
    void Gpio<Base, Pin>::disable_interrupt() {
        __NVIC_DisableIRQ(EXTIx);
    }


#endif //NEW_LIB_GPIO_HPP
