//
//  JMP.cpp
//  OOPAssignment2
//
//  Created by Malak Sadek on 11/13/17.
//  Copyright © 2017 Malak Sadek. All rights reserved.
//

#include "JMP.hpp"

JMP::JMP(class InstructionAddressOperand* operand1, int* pc, int* instrCount, std::string instr):PC(pc),instructionMemoryBounds(instrCount),instruction(instr),location(operand1) {}

void JMP::runInstr() {           
        *PC = location->getAddress();
}

std::string JMP::printInstr() {
    return instruction;
}
