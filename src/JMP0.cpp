//
//  JMP0.cpp
//  OOPAssignment2
//
//  Created by Malak Sadek on 11/13/17.
//  Copyright © 2017 Malak Sadek. All rights reserved.
//

#include "JMP0.hpp"


JMP0::JMP0(class Operand* in1, class InstructionAddressOperand* loc, int* pc, int* instrMemBound, std::string instr):PC(pc),instructionMemoryBound(instrMemBound),location(loc),operand1(in1),instruction(instr) {}

void JMP0::runInstr() {
    if (operand1->getValue() == 0) {
            *PC = location->getAddress();
    }
}

std::string JMP0::printInstr() {
    return instruction;
}

