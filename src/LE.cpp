//
//  LE.cpp
//  OOPAssignment2
//
//  Created by Malak Sadek on 11/13/17.
//  Copyright © 2017 Malak Sadek. All rights reserved.
//

#include "LE.hpp"

LE::LE(Operand* input1, Operand* input2, DataAddressOperand* outp, std::string instr):operand1(input1),operand2(input2),outputOperand(outp),instruction(instr) {
}

void LE::runInstr() {
    if (operand1->getValue() <= operand2->getValue())
        outputOperand->setValue(1);
    else
        outputOperand->setValue(0);
}

std::string LE::printInstr() {
    return instruction;
}
