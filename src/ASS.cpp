//
//  ASS.cpp
//  OOPAssignment2
//
//  Created by Malak Sadek on 11/13/17.
//  Copyright © 2017 Malak Sadek. All rights reserved.
//

#include "ASS.hpp"

ASS::ASS(class Operand* input1, class DataAddressOperand* outp, std::string instr):operand1(input1),outputOperand(outp),instruction(instr) {}

void ASS::runInstr() {
    outputOperand->setValue(operand1->getValue());
}

std::string ASS::printInstr() {
    return instruction;
}
