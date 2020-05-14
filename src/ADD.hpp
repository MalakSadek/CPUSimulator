//
//  ADD.h
//  OOPASS2
//
//  Created by Malak Sadek on 11/10/17.
//  Copyright © 2017 Malak Sadek. All rights reserved.
//

#ifndef ADD_hpp
#define ADD_hpp
#include <stdio.h>
#include "Instruction.h"
#include "DataAddressOperand.hpp"


class ADD : public Instruction
{
private:
    Operand* operand1;
    Operand* operand2;
    DataAddressOperand* outOperand;
    std::string instruction;
    
public:
    ADD(class Operand* in1, class Operand* in2, class DataAddressOperand* outp, std::string instr);
    void runInstr();
    std::string printInstr();
};

#endif


