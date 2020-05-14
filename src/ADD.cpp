//
//  ADD.cpp
//  OOPAssignment2
//
//  Created by Malak Sadek on 11/13/17.
//  Copyright © 2017 Malak Sadek. All rights reserved.
//

#include "ADD.hpp"

ADD::ADD(class Operand* in1, class Operand* in2, class DataAddressOperand* outp, std::string instr):operand1(in1),operand2(in2),outOperand(outp),instruction(instr){}

void ADD::runInstr() {
    outOperand->setValue(operand1->getValue()+operand2->getValue());
}

std::string ADD::printInstr() {
    return instruction;
}
