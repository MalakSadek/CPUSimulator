//
//  NEG.h
//  OOPASS2
//
//  Created by Malak Sadek on 11/10/17.
//  Copyright © 2017 Malak Sadek. All rights reserved.
//



#ifndef NEG_h
#define NEG_h
#include <stdio.h>
#include "Instruction.h"
#include "DataAddressOperand.hpp"

class NEG : public Instruction
{
private:
    Operand* operand1;
    DataAddressOperand* outputOperand;
    std::string instruction;
    
public:
    NEG(Operand* input1, DataAddressOperand* outp, std::string instr);
    void runInstr();
    std::string printInstr();
};
#endif

