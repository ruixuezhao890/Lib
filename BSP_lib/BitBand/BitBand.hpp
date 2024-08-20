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
#include "stddef.h"
// 把“位带地址+位序号”转换成别名地址的宏
#define BITBAND(addr, bitnum) (((addr) & 0xF0000000) + 0x02000000 + (((addr) & 0x000FFFFF) << 5) + ((bitnum) << 2))

// 把一个地址转换成一个指针指向的内容
#define MEM_ADDR(addr) *((volatile uint32_t *)(addr))

// 把位带别名区地址转换成指针
#define BIT_ADDR(addr, bitnum) MEM_ADDR(BITBAND((addr), (bitnum)))
struct BitOperater {
    volatile uint32_t &bitband;

    BitOperater(uint32_t address, uint8_t bitnum) : bitband(BIT_ADDR(address, bitnum)) {}
    friend bool operator==(const BitOperater &lhs, const BitOperater &rhs) { return lhs.bitband == rhs.bitband; }
    friend bool operator==(const BitOperater &lhs, uint32_t rhs) { return lhs.bitband == rhs; }
    friend bool operator==(uint32_t lhs, const BitOperater &rhs) { return lhs == rhs.bitband; }
    friend bool operator!=(const BitOperater &lhs, const BitOperater &rhs) { return lhs.bitband != rhs.bitband; }
    friend bool operator!=(const BitOperater &lhs, uint32_t rhs) { return lhs.bitband != rhs; }
    friend bool operator!=(uint32_t lhs, const BitOperater &rhs) { return lhs != rhs.bitband; }
    bool operator!(void) const { return !bitband; }
    operator uint32_t(void) const { return bitband; }
};


#endif //NEW_LIB_BITBAND_HPP
