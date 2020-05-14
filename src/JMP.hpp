//
//  JMP.h
//  OOPASS2
//
//  Created by Malak Sadek on 11/10/17.
//  Copyright © 2017 Malak Sadek. All rights reserved.
//


#ifndef JMP_h
#define JMP_h
#include <stdio.h>
#include "Instruction.h"
#include "InstructionAddressOperand.hpp"


class JMP : public Instruction
{
private:
    int *PC;
    int *instructionMemoryBounds;
    InstructionAddressOperand* location;
    std::string instruction;
    
public:
    JMP(class InstructionAddressOperand* operand1, int* pc, int* instrCount, std::string instr);
    void runInstr();
    std::string printInstr();
    
};

#endif

