//
//  JMP0.h
//  OOPASS2
//
//  Created by Malak Sadek on 11/10/17.
//  Copyright © 2017 Malak Sadek. All rights reserved.
//


#ifndef JMP0_h
#define JMP0_h
#include <stdio.h>
#include "Instruction.h"
#include "InstructionAddressOperand.hpp"

class JMP0 : public Instruction
{
private:
    int* PC, *instructionMemoryBound; //Address of the last instruction in the instruction memory
    InstructionAddressOperand* location;
    Operand* operand1;
    std::string instruction;
    
public:
    
    JMP0(class Operand* in1, class InstructionAddressOperand* loc, int* pc, int* instrMemBound, std::string instr);
    void runInstr();
    std::string printInstr();
    
};

#endif

