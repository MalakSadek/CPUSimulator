//
//  Processor.hpp
//  OOPAssignment2
//
//  Created by Malak Sadek on 11/13/17.
//  Copyright © 2017 Malak Sadek. All rights reserved.
//

#ifndef Processor_hpp
#define Processor_hpp

#include <stdio.h>
#include <iostream>
#include "Instruction.h"
#include "DataAddressOperand.hpp"
#include "OperandFactory.hpp"
#include "InstructionFactory.hpp"

class Processor {
public:
    Instruction* processInstruction(std::string instruction, int& PC, int& memIndex);
    Operand* processOperand(std::string instruction);
};
#endif /* Processor_hpp */
