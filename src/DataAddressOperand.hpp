//
//  LocationOperand.h
//  OOPASS2
//
//  Created by Malak Sadek on 11/10/17.
//  Copyright © 2017 Malak Sadek. All rights reserved.
//


#ifndef LocationOperand_hpp
#define LocationOperand_hpp

#include "Operand.h"
#include "DataMemory.hpp"

//Location operands inherit from operand class and define their own getValue, since they represent the values stored in data memory locations, they also have a setValue function and a getAddress function

class DataAddressOperand : public Operand
{
private:
    int index;
public:
    DataAddressOperand(int i);
    int getValue() const;
    int getAddress() const;
    void setValue(const int& value);
};

#endif




