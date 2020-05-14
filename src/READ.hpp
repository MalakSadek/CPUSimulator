//
//  READ.h
//  OOPASS2
//
//  Created by Malak Sadek on 11/10/17.
//  Copyright © 2017 Malak Sadek. All rights reserved.
//


#ifndef READ_h
#define READ_h
#include <stdio.h>
#include "Instruction.h"
#include "DataAddressOperand.hpp"
#include <iostream>
class READ : public Instruction
{
private:
    DataAddressOperand* read;
    std::string instruction;
public:
    READ(DataAddressOperand* input1, std::string instr);
    void runInstr();
    std::string printInstr();
    
};
#endif


