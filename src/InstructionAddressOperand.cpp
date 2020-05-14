//
//  InstructionAddressOperand.cpp
//  OOPAssignment2
//
//  Created by Malak Sadek on 11/15/17.
//  Copyright © 2017 Malak Sadek. All rights reserved.
//

#include "InstructionAddressOperand.hpp"

InstructionAddressOperand::InstructionAddressOperand(int i):index(i){}

int InstructionAddressOperand::getValue() const {
    return DataMemory::getmemPointer()->operator[](index);  //value stored in data memory at i
}

int InstructionAddressOperand::getAddress() const {    //data memory address of this operand
    return index;
}

void InstructionAddressOperand::setValue(const int& value) {       //set value at data memory index i
    DataMemory::getmemPointer()->operator[](index) = value;
}
