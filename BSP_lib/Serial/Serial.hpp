/**
*********************************************************************
*********
* @project_name :new_lib
* @file : Serial.hpp
* @author : ruixuezhao890
* @brief : None
* @attention : None
* @date : 2024/9/15 
*********************************************************************
*********
*/


#ifndef NEW_LIB_SERIAL_HPP
#define NEW_LIB_SERIAL_HPP
#include "Gpio/Gpio.hpp"



template <uint32_t Base>
struct SerialHelper
{

    static constexpr uint32_t base = Base;
    static constexpr bool is_valid = false;
};

#ifdef USART1_BASE
constexpr uint32_t PIN_PORT_TX_1=GPIOA_BASE;
constexpr uint32_t PIN_PORT_RX_1=GPIOA_BASE;
constexpr uint32_t PIN_TX_1=9;
constexpr uint32_t PIN_RX_1=10;

template <>
struct SerialHelper<USART1_BASE>
{
//    using TxDmaChannel = Dma1<3>;
//    using RxDmaChannel = Dma1<4>;

    static constexpr uint32_t id = 0;
    static constexpr uint32_t base = USART1_BASE;
    static constexpr uint32_t gpio_af = GPIO_AF7_USART1;
    static constexpr bool is_valid = true;

    static void clock(bool enable) {
        if (enable){
            __HAL_RCC_USART1_CLK_ENABLE();
        }else{
            __HAL_RCC_USART1_CLK_DISABLE();
        }
    }

    struct Pin{
        struct {uint32_t base;uint32_t pin;}tx_pin;
        struct {uint32_t base;uint32_t pin;}rx_pin;
    };
    static constexpr Pin get_pin(){
        Pin pin{
                {PIN_PORT_TX_1,PIN_TX_1},
                {PIN_PORT_RX_1,PIN_RX_1},
        };
        return pin;
    }

};

#endif // USART1_BASE

#ifdef USART2_BASE

constexpr uint32_t PIN_PORT_TX_2=GPIOA_BASE;
constexpr uint32_t PIN_PORT_RX_2=GPIOA_BASE;
constexpr uint32_t PIN_TX_2=9;
constexpr uint32_t PIN_RX_2=9;
template <>
struct SerialHelper<USART2_BASE>
{

//    using TxDmaChannel = Dma1<3>;
//    using RxDmaChannel = Dma1<4>;

    static constexpr uint32_t id = 1;
    static constexpr uint32_t base = USART2_BASE;
    static constexpr uint32_t gpio_af = GPIO_AF7_USART2;
    static constexpr bool is_valid = true;

    static void clock(bool enable) {
        if (enable){
            __HAL_RCC_USART2_CLK_ENABLE();
        }else{
            __HAL_RCC_USART2_CLK_DISABLE();
        }
    }
    struct Pin{
        struct {uint32_t base;uint32_t pin;}tx_pin;
        struct {uint32_t base;uint32_t pin;}rx_pin;
    };
    static constexpr Pin get_pin(){
        Pin pin{
                {PIN_PORT_TX_2,PIN_TX_2},
                {PIN_PORT_RX_2,PIN_RX_2},
        };
        return pin;
    }

};
#endif // USART2_BASE

#ifdef USART3_BASE

constexpr uint32_t PIN_PORT_TX_3=GPIOA_BASE;
constexpr uint32_t PIN_PORT_RX_3=GPIOA_BASE;
constexpr uint32_t PIN_TX_3=9;
constexpr uint32_t PIN_RX_3=9;
template <>
struct SerialHelper<USART3_BASE>
{


//    using TxDmaChannel = Dma1<3>;
//    using RxDmaChannel = Dma1<4>;

    static constexpr uint32_t id = 2;
    static constexpr uint32_t base = USART3_BASE;
    static constexpr uint32_t gpio_af = GPIO_AF7_USART3;
    static constexpr bool is_valid = true;

    static void clock(bool enable) {
        if (enable){
            __HAL_RCC_USART3_CLK_ENABLE();
        }else{
            __HAL_RCC_USART3_CLK_DISABLE();
        }
    }
    struct Pin{
        struct {uint32_t base;uint32_t pin;}tx_pin;
        struct {uint32_t base;uint32_t pin;}rx_pin;
    };
    static constexpr Pin get_pin(){
        Pin pin{
                {PIN_PORT_TX_3,PIN_TX_3},
                {PIN_PORT_RX_3,PIN_RX_3},
        };
        return pin;
    }

};

#endif // USART3_BASE

#ifdef UART4_BASE
constexpr uint32_t PIN_PORT_TX_4=GPIOA_BASE;
constexpr uint32_t PIN_PORT_RX_4=GPIOA_BASE;
constexpr uint32_t PIN_TX_4=9;
constexpr uint32_t PIN_RX_4=9;
template <>
struct SerialHelper<UART4_BASE>
{



//    using TxDmaChannel = Dma1<3>;
//    using RxDmaChannel = Dma1<4>;

    static constexpr uint32_t id = 3;
    static constexpr uint32_t base = UART4_BASE;
    static constexpr uint32_t gpio_af = GPIO_AF8_UART4;
    static constexpr bool is_valid = true;

    static void clock(bool enable) {
        if (enable){
            __HAL_RCC_UART4_CLK_ENABLE();
        }else{
            __HAL_RCC_UART4_CLK_DISABLE();
        }
    }
    struct Pin{
        struct {uint32_t base;uint32_t pin;}tx_pin;
        struct {uint32_t base;uint32_t pin;}rx_pin;
    };
    static constexpr Pin get_pin(){
        Pin pin{
                {PIN_PORT_TX_4,PIN_TX_4},
                {PIN_PORT_RX_4,PIN_RX_4},
        };
        return pin;
    }

};

#endif // UART4_BASE

#ifdef UART5_BASE

constexpr uint32_t PIN_PORT_TX_5=GPIOA_BASE;
constexpr uint32_t PIN_PORT_RX_5=GPIOA_BASE;
constexpr uint32_t PIN_TX_5=9;
constexpr uint32_t PIN_RX_5=9;
template <>
struct SerialHelper<UART5_BASE>
{



//    using TxDmaChannel = Dma1<3>;
//    using RxDmaChannel = Dma1<4>;

    static constexpr uint32_t id = 4;
    static constexpr uint32_t base = UART5_BASE;
    static constexpr uint32_t gpio_af = GPIO_AF8_UART5;
    static constexpr bool is_valid = true;

    static void clock(bool enable) {
        if (enable){
            __HAL_RCC_UART5_CLK_ENABLE();
        }else{
            __HAL_RCC_UART5_CLK_DISABLE();
        }
    }
    struct Pin{
        struct {uint32_t base;uint32_t pin;}tx_pin;
        struct {uint32_t base;uint32_t pin;}rx_pin;
    };
    static constexpr Pin get_pin(){
        Pin pin{
                {PIN_PORT_TX_5,PIN_TX_5},
                {PIN_PORT_RX_5,PIN_RX_5},
        };
        return pin;
    }

};
#endif // UART5_BASE

#ifdef USART6
constexpr uint32_t PIN_PORT_TX_6=GPIOA_BASE;
constexpr uint32_t PIN_PORT_RX_6=GPIOA_BASE;
constexpr uint32_t PIN_TX_6=9;
constexpr uint32_t PIN_RX_6=9;
template <>
struct SerialHelper<USART6_BASE>
{
//    using TxDmaChannel = Dma1<3>;
//    using RxDmaChannel = Dma1<4>;

    static constexpr uint32_t id = 5;
    static constexpr uint32_t base = USART6_BASE;
    static constexpr uint32_t gpio_af = GPIO_AF8_USART6;
    static constexpr bool is_valid = true;

    static void clock(bool enable) {
        if (enable){
            __HAL_RCC_USART6_CLK_ENABLE();
        }else{
            __HAL_RCC_USART6_CLK_DISABLE();
        }
    }
    struct Pin{
        struct {uint32_t base;uint32_t pin;}tx_pin;
        struct {uint32_t base;uint32_t pin;}rx_pin;
    };
    static constexpr Pin get_pin(){
        Pin pin{
                {PIN_PORT_TX_6,PIN_TX_6},
                {PIN_PORT_RX_6,PIN_RX_6},
        };
        return pin;
    }

};
#endif //USART6_BASE

template<uint32_t Base>
class Serial {
private:
    using Helper = SerialHelper<Base>;
    static UART_HandleTypeDef serial_initTypeDef;
public:
    struct IdleBit:public BitOperator{
        IdleBit(): BitOperator(&serial_initTypeDef.Instance->CR1,USART_CR1_IDLEIE_Pos){};
    };
    struct TeBit:public BitOperator{
        TeBit(): BitOperator(&serial_initTypeDef.Instance->CR1,USART_CR1_TE_Pos){};

        TeBit &operator=(uint8_t value) override {
            BitOperator::operator=(value);
            return *this;
        }
    };

    static TeBit teBit;


    static constexpr uint32_t base = Base;
    static constexpr uint32_t id = Helper::id;
    static constexpr bool is_valid = Helper::is_valid;

    static void clock(bool enable) {
        Helper::clock(enable);
    }

    template<uint32_t tx_port,uint32_t tx_pin,uint32_t rx_port,uint32_t rx_pin>
    static void pin_init(){
      using tx=Gpio<tx_port,tx_pin> ;
      using rx=Gpio<rx_port,rx_pin> ;
      ConfigAfPPOut<tx,rx>(Helper::gpio_af,GPIO_SPEED_FREQ_VERY_HIGH,GPIO_PULLUP);
    }

    static void pin_init_default(){
        using tx=Gpio<Helper::get_pin().tx_pin.base,Helper::get_pin().tx_pin.pin> ;
        using rx=Gpio<Helper::get_pin().rx_pin.base,Helper::get_pin().rx_pin.pin> ;
        ConfigAfPPOut<tx,rx>(Helper::gpio_af,GPIO_SPEED_FREQ_VERY_HIGH,GPIO_PULLUP);
    }
    static void default_config(uint32_t baud_rate){
        serial_initTypeDef.Instance = (USART_TypeDef *)base;
        serial_initTypeDef.Init.BaudRate = baud_rate;                    /* 波特率 */
        serial_initTypeDef.Init.WordLength = UART_WORDLENGTH_8B;        /* 字长为8位数据格式 */
        serial_initTypeDef.Init.StopBits = UART_STOPBITS_1;             /* 一个停止位 */
        serial_initTypeDef.Init.Parity = UART_PARITY_NONE;              /* 无奇偶校验位 */
        serial_initTypeDef.Init.HwFlowCtl = UART_HWCONTROL_NONE;        /* 无硬件流控 */
        serial_initTypeDef.Init.Mode = UART_MODE_TX_RX;                 /* 收发模式 */
        enable_transmit();
        enable_receive();
    }
    static inline void enable(){
        HAL_UART_Init(&serial_initTypeDef);
    }

    static inline void disable(){
        HAL_UART_DeInit(&serial_initTypeDef);
    }

    static inline void set_baud_rate(uint32_t baud_rate){
        serial_initTypeDef.Init.BaudRate=baud_rate;
    }

    static inline void set_stop_1bits(){
        serial_initTypeDef.Init.StopBits = UART_STOPBITS_1;
    }

    static inline void set_stop_2bits(){
        serial_initTypeDef.Init.StopBits = UART_STOPBITS_2;
    }

    static inline void set_word_length_8(){
        serial_initTypeDef.Init.WordLength = UART_WORDLENGTH_8B;
    }

    static inline void set_word_length_9(){
        serial_initTypeDef.Init.WordLength = UART_WORDLENGTH_9B;
    }

    static inline void set_parity_none(){
        serial_initTypeDef.Init.Parity = UART_PARITY_NONE;
    }
    static inline void set_parity_even(){
        serial_initTypeDef.Init.Parity = UART_PARITY_EVEN;
    }
    static inline void set_parity_odd(){
        serial_initTypeDef.Init.Parity = UART_PARITY_ODD;
    }

   static void inline set_hw_none(){
        serial_initTypeDef.Init.HwFlowCtl=UART_HWCONTROL_NONE;
    }
   static void inline set_hw_rts(){
       serial_initTypeDef.Init.HwFlowCtl=UART_HWCONTROL_RTS;
    }
   static void inline set_hw_cts(){
       serial_initTypeDef.Init.HwFlowCtl=UART_HWCONTROL_CTS;
    }
   static void inline set_hw_rts_cts(){
       serial_initTypeDef.Init.HwFlowCtl=UART_HWCONTROL_RTS_CTS;
    }

    static void inline set_uart_tx_mode(){
        serial_initTypeDef.Init.Mode=UART_MODE_TX;
    }
    static void inline set_uart_rx_mode(){
        serial_initTypeDef.Init.Mode=UART_MODE_RX;
    }
    static void inline set_uart_tx_rx_mode(){
        serial_initTypeDef.Init.Mode=UART_MODE_TX_RX;
    }

    static void inline enable_transmit(){
//        if((serial_initTypeDef.Instance->CR1 & USART_CR1_TE) == 0)
//        {
//            /* Enable the UART Transmission by setting the TE bit in the CR1 register */
//            serial_initTypeDef.Instance->CR1 |= USART_CR1_TE;
//        }
        if (teBit.read()==0){
            teBit= 1;
        }
    }

    static void inline disable_transmit(){
        if((serial_initTypeDef.Instance->CR1 & USART_CR1_TE) != 0)
        {
            /* Disable the UARTTransmission by clearing the TE bit in the CR1 register */
            serial_initTypeDef.Instance->CR1 &= ~(USART_CR1_TE);
        }
    }

    static void inline enable_receive(){
        if((serial_initTypeDef.Instance->CR1 & USART_CR1_RE) == 0)
        {
            /* Enable the UART Reception by setting the RE bit in the CR1 register */
            serial_initTypeDef.Instance->CR1 |= USART_CR1_RE;
        }
    }

    static void inline disable_receive(){
        /* Check if the UART Reception is enabled */
        if((serial_initTypeDef.Instance->CR1 & USART_CR1_RE) != 0)
        {
            /* Disable the UART Reception by clearing the RE bit in the CR1 register */
            serial_initTypeDef.Instance->CR1 &= ~(USART_CR1_RE);
        }
    }

    static inline void put_char(uint8_t ch){
        /* Wait until the UART is ready to send data (TXE flag set) */
        while (!(serial_initTypeDef.Instance->SR & USART_SR_TXE));

        /* Write the character to the data register */
        serial_initTypeDef.Instance->DR = (ch & 0xFF);

        /* Wait until the character has been sent from the shift register (TC flag set) */
        while (!(serial_initTypeDef.Instance->SR & USART_SR_TC));
    }

    static inline void transmit(const char * ptr,uint8_t size){
        if (!ptr){
            return;
        }
        for (int i = 0; i < size; ++i) {
            put_char(ptr[i]);
        }
    }

};
template<uint32_t Base>
UART_HandleTypeDef Serial<Base>::serial_initTypeDef={};

template<uint32_t Base>
typename Serial<Base>::TeBit Serial<Base>::teBit;


#ifdef USART1_BASE
using Serial1 = Serial<USART1_BASE>;
inline Serial1 serial1;
#endif // USART1_BASE

#ifdef USART2_BASE
using Serial2 = Serial<USART2_BASE>;
inline Serial2 serial2;
#endif // USART2_BASE

#ifdef USART3_BASE
using Serial3 = Serial<USART3_BASE>;
inline Serial3 serial3;
#endif // USART3_BASE

#ifdef UART4_BASE
using Serial4 = Serial<UART4_BASE>;
inline Serial4 serial4;
#endif // USRT4_BASE

#ifdef UART5_BASE
using Serial5 = Serial<UART5_BASE>;
inline Serial5 serial5;
#endif // UART5_BASE

#ifdef USART6_BASE
using Serial6 = Serial<USART6_BASE>;
inline Serial6 serial6;
#endif // USART6_BASE
#endif //NEW_LIB_SERIAL_HPP
