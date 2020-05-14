//
//  WRITE.h
//  OOPASS2
//
//  Created by Malak Sadek on 11/10/17.
//  Copyright © 2017 Malak Sadek. All rights reserved.
//

#ifndef WRITE_h
#define WRITE_h

#include "Instruction.h"
#include "DataAddressOperand.hpp"
#include <stdio.h>
#include <iostream>
class WRITE : public Instruction
{
private:
    DataAddressOperand* write;
    std::string instruction;
    
public:
    WRITE(DataAddressOperand* input1, std::string instr);
    void runInstr();
    std::string printInstr();
    
};

#endif

