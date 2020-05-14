//
//  HALT.h
//  OOPASS2
//
//  Created by Malak Sadek on 11/10/17.
//  Copyright © 2017 Malak Sadek. All rights reserved.
//

#ifndef HALT_h
#define HALT_h
#include <stdio.h>
#include "Instruction.h"
#include <iostream>

class HALT: public Instruction
{
private:
    int* PC;
    std::string instruction;
    
public:
    HALT(int* pc, std::string instr);
    void runInstr();
    std::string printInstr();
    
};

#endif


