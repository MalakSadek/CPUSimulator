//
//  HALT.cpp
//  OOPAssignment2
//
//  Created by Malak Sadek on 11/13/17.
//  Copyright © 2017 Malak Sadek. All rights reserved.
//

#include "HALT.hpp"

HALT::HALT(int* pc, std::string instr):PC(pc),instruction(instr){}

void HALT::runInstr() {
    *PC = 1024;
}

std::string HALT::printInstr() {
    return instruction;
}
