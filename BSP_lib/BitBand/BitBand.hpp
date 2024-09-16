/**
*********************************************************************
*********
* @project_name :new_lib
* @file : BitBand.hpp
* @author : ruixuezhao890
* @brief : None
* @attention : None
* @date : 2024/8/19 
*********************************************************************
*********
*/


#ifndef NEW_LIB_BITBAND_HPP
#define NEW_LIB_BITBAND_HPP

#include <cstdint>
#include <cstddef>
class BitOperator {
protected:
    // 设置位为1
    void set() const {
        *reinterpret_cast<volatile uint32_t*>(aliasAddr_) = 1;
    }

    // 清除位为0
    void clear() const {
        *reinterpret_cast<volatile uint32_t*>(aliasAddr_) = 0;
    }

public:
    // 构造函数，初始化需要操作的寄存器地址和位数
    BitOperator(volatile uint32_t* regAddr, uint8_t bitNum)
            : regAddr_(regAddr), bitNum_(bitNum) {
        aliasAddr_ = calcBitBandAlias((uintptr_t)regAddr_, bitNum_);
    }
    // 读取位值
    bool read() const {
        return bool(*reinterpret_cast<volatile uint32_t*>(aliasAddr_));
    }

    // 重载 == 操作符
    bool operator==(const BitOperator& other) const {
        // 比较寄存器地址和位号
        return (regAddr_ == other.regAddr_) && (bitNum_ == other.bitNum_);
    }

    bool operator==(bool other) const{
        return read()==other;
    }

    // 重载 != 操作符
    bool operator!=(const BitOperator& other) const {
        // 使用 == 的结果取反
        return !(*this == other);
    }

    // 重载 ! 操作符
    bool operator!() const {
        // 位为0时返回 true
        return !read();
    }

    // 重载 = 操作符，实现位的赋值
    virtual BitOperator& operator=(uint8_t value) {
        if (value) {
            set();    // 设置位为1
        } else {
            clear();  // 清除位为0
        }
        return *this;
    }

protected:
    volatile uint32_t* regAddr_;  // 原始寄存器地址
    uint8_t bitNum_;              // 位号
    uintptr_t aliasAddr_;         // 位带别名地址

    // 计算位带别名地址
    static uintptr_t calcBitBandAlias(uintptr_t regAddr, uint8_t bitNum) {
        // 基础地址
        return PERIPH_BB_BASE + ((regAddr - PERIPH_BASE) * 32) + (bitNum * 4);
    }
};
#endif //NEW_LIB_BITBAND_HPP
