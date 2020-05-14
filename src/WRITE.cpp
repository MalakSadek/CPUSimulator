//
//  WRITE.cpp
//  OOPAssignment2
//
//  Created by Malak Sadek on 11/13/17.
//  Copyright © 2017 Malak Sadek. All rights reserved.
//

#include "WRITE.hpp"

WRITE::WRITE(DataAddressOperand* input1, std::string instr):write(input1),instruction(instr){}

void WRITE::runInstr() {
    std::cout<< "WRITE RESULT: " << write->getValue() <<std::endl;
}

std::string WRITE::printInstr() {
    return instruction;
}
