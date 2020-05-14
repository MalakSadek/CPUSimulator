//
//  InstructionFactory.h
//  OOPASS2
//
//  Created by Malak Sadek on 11/10/17.
//  Copyright © 2017 Malak Sadek. All rights reserved.
//

#ifndef InstructionFactory_h
#define InstructionFactory_h
#include <string>
#include "Instruction.h"
#include "ADD.hpp"
#include "ASS.hpp"
#include "HALT.hpp"
#include "JMP0.hpp"
#include "JMP.hpp"
#include "LE.hpp"
#include "MUL.hpp"
#include "NEG.hpp"
#include "READ.hpp"
#include "WRITE.hpp"
#include "OperandFactory.hpp"
#include "DataAddressOperand.hpp"
#include "NumberOperand.hpp"
#include "InstructionAddressOperand.hpp"
#include <stdio.h>


class InstructionFactory {
    
public:
    static Instruction* CreateInstruction(std::string instruction, int* PC, int* instructionIndex, int opcode, Operand* operand1, Operand* operand2, DataAddressOperand* outOperandd, InstructionAddressOperand* outOperandi);
};
#endif

