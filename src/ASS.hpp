//
//  ASS.h
//  OOPASS2
//
//  Created by Malak Sadek on 11/10/17.
//  Copyright © 2017 Malak Sadek. All rights reserved.
//


#ifndef ASS_h
#define ASS_h
#include <stdio.h>
#include "Instruction.h"
#include "DataAddressOperand.hpp"



class ASS : public Instruction
{
private:
    Operand* operand1;
    DataAddressOperand* outputOperand;
    std::string instruction;
    
public:
    ASS(class Operand* input1, class DataAddressOperand* outp, std::string instr);
    void runInstr();
    std::string printInstr();
    
};
#endif

