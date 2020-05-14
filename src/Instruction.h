//
//  Instruction.h
//  OOPASS2
//
//  Created by Malak Sadek on 11/10/17.
//  Copyright © 2017 Malak Sadek. All rights reserved.
//


#ifndef Instruction_h
#define Instruction_h

#include <string>


class Instruction
{
public:
    virtual void runInstr()=0;
    virtual std::string printInstr() = 0;
};

#endif
