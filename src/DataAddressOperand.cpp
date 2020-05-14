//
//  LocationOperand.cpp
//  OOPASS2
//
//  Created by Malak Sadek on 11/10/17.
//  Copyright © 2017 Malak Sadek. All rights reserved.
//

#include "DataAddressOperand.hpp"

DataAddressOperand::DataAddressOperand(int i):index(i){}

int DataAddressOperand::getValue() const {
    return DataMemory::getmemPointer()->operator[](index);  //value stored in data memory at i
    return 0;
}

int DataAddressOperand::getAddress() const {    //data memory address of this operand
    return index;
}

void DataAddressOperand::setValue(const int& value) {       //set value at data memory index i
    DataMemory::getmemPointer()->operator[](index) = value;
}
