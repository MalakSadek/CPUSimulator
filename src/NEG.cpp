//
//  NEG.cpp
//  OOPAssignment2
//
//  Created by Malak Sadek on 11/13/17.
//  Copyright © 2017 Malak Sadek. All rights reserved.
//

#include "NEG.hpp"

NEG::NEG(Operand* input1, DataAddressOperand* outp, std::string instr):operand1(input1),outputOperand(outp),instruction(instr){}

void NEG::runInstr() {
    outputOperand->setValue(-(operand1->getValue()));
}

std::string NEG::printInstr() {
    return instruction;
}
