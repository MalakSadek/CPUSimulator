//
//  MUL.cpp
//  OOPAssignment2
//
//  Created by Malak Sadek on 11/13/17.
//  Copyright © 2017 Malak Sadek. All rights reserved.
//

#include "MUL.hpp"

MUL::MUL(Operand* input1, Operand* input2, DataAddressOperand* outp, std::string instr):operand1(input1),operand2(input2),outputOperand(outp),instruction(instr){}

void MUL::runInstr() {
    outputOperand->setValue(operand1->getValue()*operand2->getValue());
}

std::string MUL::printInstr() {
    return instruction;
}
