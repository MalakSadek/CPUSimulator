//
//  OperandFactory.h
//  OOPASS2
//
//  Created by Malak Sadek on 11/10/17.
//  Copyright © 2017 Malak Sadek. All rights reserved.
//

#ifndef OperandFactory_h
#define OperandFactory_h
#include <string>
#include "DataAddressOperand.hpp"
#include "InstructionAddressOperand.hpp"
#include "NumberOperand.hpp"
#include <stdio.h>
#include <regex>
#include <iostream>
class OperandFactory {
public:
    static Operand* createOperand(int type, const std::string& instruction);
};

#endif

