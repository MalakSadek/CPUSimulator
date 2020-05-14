//
//  MUL.h
//  OOPASS2
//
//  Created by Malak Sadek on 11/10/17.
//  Copyright © 2017 Malak Sadek. All rights reserved.
//


#ifndef MUL_h
#define MUL_h
#include <stdio.h>
#include "Instruction.h"
#include "DataAddressOperand.hpp"

class MUL : public Instruction
{
private:
    Operand* operand1;
    Operand* operand2;
    DataAddressOperand* outputOperand;
    std::string instruction;
    
public:
    MUL(Operand* input1, Operand* input2, DataAddressOperand* outp, std::string instr);
    void runInstr();
    std::string printInstr();
    
};

#endif

