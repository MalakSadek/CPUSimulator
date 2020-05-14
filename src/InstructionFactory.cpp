//
//  InstructionFactory.cpp
//  OOPAssignment2
//
//  Created by Malak Sadek on 11/13/17.
//  Copyright © 2017 Malak Sadek. All rights reserved.
//

#include "InstructionFactory.hpp"

Instruction* InstructionFactory::CreateInstruction(std::string instruction, int* PC, int* instructionIndex, int opcode, Operand* operand1, Operand* operand2, DataAddressOperand* outputAddressd, InstructionAddressOperand* outputAddressi)
{
    switch (opcode) { //Opcode received from processor and tells the factory which instruction child class to create
        case 0:
        {
            return new ADD(operand1, operand2, outputAddressd, instruction);
            break;
        }
        case 1:
        {
            return new MUL(operand1, operand2, outputAddressd, instruction);
            break;
        }
        case 2:
        {
            return new LE(operand1, operand2, outputAddressd, instruction);
            break;
        }
        case 3:
        {
            return new NEG(operand1, outputAddressd, instruction);
            break;
        }
        case 4:
        {
            return new ASS(operand1, outputAddressd, instruction);
            break;
        }
        case 5:
        {
            return new JMP0(operand1, outputAddressi, PC, instructionIndex, instruction);
            break;
        }
        case 6:
        {
            return new READ(outputAddressd, instruction);
            break;
        }
        case 7:
        {
            return new WRITE(outputAddressd, instruction);
            break;
        }
        case 8:
        {
            return new JMP(outputAddressi, PC, instructionIndex, instruction);
            break;
        }
        case 9:
        {
            return new HALT(PC, instruction);
            break;
        }
        default:
            return NULL;
            break;
    }
}
