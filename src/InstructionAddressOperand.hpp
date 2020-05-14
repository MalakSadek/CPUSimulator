//
//  InstructionAddressOperand.hpp
//  OOPAssignment2
//
//  Created by Malak Sadek on 11/15/17.
//  Copyright © 2017 Malak Sadek. All rights reserved.
//

#ifndef InstructionAddressOperand_hpp
#define InstructionAddressOperand_hpp
#include "Operand.h"
#include "DataMemory.hpp"
#include <stdio.h>

class InstructionAddressOperand : public Operand
{
private:
    int index;
public:
    InstructionAddressOperand(int i);
    int getValue() const;
    int getAddress() const;
    void setValue(const int& value);
};

#endif /* InstructionAddressOperand_hpp */
