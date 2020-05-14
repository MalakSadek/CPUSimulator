//
//  Processor.cpp
//  OOPAssignment2
//
//  Created by Malak Sadek on 11/13/17.
//  Copyright © 2017 Malak Sadek. All rights reserved.
//

#include "Processor.hpp"

Instruction* Processor::processInstruction(std::string instruction, int& PC, int& memIndex) {
    
    std::string instr = instruction;
    instr.erase(remove(instr.begin(), instr.end(), ' '), instr.end());  // remove all the spaces
    instr.erase(remove(instr.begin(), instr.end(), '\t'), instr.end());  // remove all the tabs
    instr.erase(remove(instr.begin(), instr.end(), '\r'), instr.end());  // remove all the \r characters
    
    int type;
    
    //Instructions ADD, MUL, LE: 2 operand inputs, 1 location operand output
    if (((type = int(instr.find("ADD"))) != std::string::npos) || ((type = int(instr.find("MUL"))) != std::string::npos) ||
        ((type = int(instr.find("LE"))) != std::string::npos))
    {
        if (instr.find("LE") != std::string::npos) //Erase the instruction word to extract operands
            instr.erase(type, 2);
        else
            instr.erase(type, 3);
        
        //Feed the operands into the operand factory and it will determine whether it is a location operand or a number operand
        
        Operand* operand1 = processOperand(instr.substr(0, instr.find(',')));
        instr.erase(0, instr.find(',') + 1);    //Delete first operand
        
        Operand* operand2 = processOperand(instr.substr(0, instr.find(',')));
        instr.erase(0, instr.find(',') + 1); //Delete second operand
        
        Operand* outputOperand = processOperand(instr);
        
        DataAddressOperand* outputAddress;
        
        //Check if third operand is not a data memory address
        if ((outputAddress = dynamic_cast<DataAddressOperand*>(outputOperand)) == NULL)
            throw std::invalid_argument(instruction+" Output Operand is not a data memory address!\n");
        
        if (int(instruction.find("ADD")) != std::string::npos)
           return InstructionFactory::CreateInstruction(instruction, &PC, &memIndex, 0, operand1, operand2, outputAddress, 0);
        else if (int(instruction.find("MUL")) != std::string::npos)
            return InstructionFactory::CreateInstruction(instruction, &PC, &memIndex, 1, operand1, operand2, outputAddress, 0);
        else return InstructionFactory::CreateInstruction(instruction, &PC, &memIndex, 2, operand1, operand2, outputAddress, 0);
    }
    
    // Instructions NEG, ASS and JMP0: One location or number operand and one location operand
    else if(((type = int(instr.find("NEG"))) != std::string::npos) ||
            ((type = int(instr.find("ASS"))) != std::string::npos) ||
            ((type = int(instr.find("JMP0"))) != std::string::npos))
    {
        if (instr.find("JMP0") != std::string::npos) {
            instr.erase(type, 4);
            Operand* operand1 = processOperand(instr.substr(0, instr.find(',')));
            
            instr.erase(0, instr.find(',') + 1);
            
            Operand* outputOperand = processOperand(instr);
            
            InstructionAddressOperand* outputAddress = nullptr;
            
            //Check if third operand is not an instruction memory address
            if((outputAddress = dynamic_cast<InstructionAddressOperand*>(outputOperand)) == NULL)
                throw std::invalid_argument(instruction+" Output Operand is not an instruction memory address");
            //If jump location is larger than the total number of instruction
            else if(outputAddress->getValue() > memIndex)
                throw std::invalid_argument(instruction+" Location is larger than the number of instructions!\n");
            else
                return InstructionFactory::CreateInstruction(instruction, &PC, &memIndex, 5, operand1, 0, 0, outputAddress);
        }
        else {
            instr.erase(type, 3);
            Operand* operand1 = processOperand(instr.substr(0, instr.find(',')));
            
            instr.erase(0, instr.find(',') + 1);
            
            Operand* outputOperand = processOperand(instr);
            
            DataAddressOperand* outputAddress = nullptr;
            
            //Check if third operand is not a data memory address
            if((outputAddress = dynamic_cast<DataAddressOperand*>(outputOperand)) == NULL)
                throw std::invalid_argument(instruction+" Output operand is not a data memory address");
            
            if(int(instruction.find("NEG")) != std::string::npos)
                return InstructionFactory::CreateInstruction(instruction, &PC, &memIndex, 3, operand1, 0, outputAddress, 0);
            else return InstructionFactory::CreateInstruction(instruction, &PC, &memIndex, 4, operand1, 0, outputAddress, 0);
        }
    }
    
    // Instructions READ, WRITE and JMP: One location operand
    else if (((type = int(instr.find("READ"))) != std::string::npos) ||
             ((type = int(instr.find("WRITE"))) != std::string::npos) ||
             ((type = int(instr.find("JMP"))) != std::string::npos))
    {
        if (instr.find("JMP") != std::string::npos) instr.erase(type, 3);
        if (instr.find("READ") != std::string::npos) instr.erase(type, 4);
        if (instr.find("WRITE") != std::string::npos) instr.erase(type, 5);
        
        Operand* outputOperand = processOperand(instr);
        DataAddressOperand* outputAddress = nullptr;
        
        if (instruction.find("READ") != std::string::npos) {
            
            //Check if third operand is not a data memory address
            if((outputAddress = dynamic_cast<DataAddressOperand*>(outputOperand)) == NULL)
                throw std::invalid_argument(instruction+" Output operand is not a data memory address");
           
            return InstructionFactory::CreateInstruction(instruction, &PC, &memIndex, 6, 0, 0, outputAddress, 0);
        }
        if (instruction.find("WRITE") != std::string::npos) {
        
            //Check if third operand is not a data memory address
            if((outputAddress = dynamic_cast<DataAddressOperand*>(outputOperand)) == NULL)
                throw std::invalid_argument(instruction+" Output operand is not a data memory address");
          
            return InstructionFactory::CreateInstruction(instruction, &PC, &memIndex, 7, 0, 0, outputAddress, 0);
        }
        else {
            InstructionAddressOperand* outputAddressi = nullptr;
            
            //Check if third operand is not an instruction memory address
            if((outputAddressi = dynamic_cast<InstructionAddressOperand*>(outputOperand)) == NULL)
                throw std::invalid_argument(instruction+" Output operand is not an instruction address");
            
            //If jump location is larger than the total number of instruction
            else if(outputAddressi->getValue() > memIndex)
                throw std::invalid_argument(instruction+" Location is larger than the number of instructions!\n");
            else
                return InstructionFactory::CreateInstruction(instruction, &PC, &memIndex, 8, 0, 0, 0, outputAddressi);
        }
    }
    else if ((type = int(instr.find("HALT"))) != std::string::npos)
         return InstructionFactory::CreateInstruction(instruction, &PC, &memIndex, 9, 0, 0, 0, 0);
    else
        return NULL;
}


Operand* Processor::processOperand(std::string instruction) {
    std::regex syntax("^\\$?-?([0-9]+)*$", std::regex_constants::icase); //disregard case
    std::regex instrsyntax("#.*", std::regex_constants::icase);
    
    if(regex_match(instruction, syntax))
    {
        if(instruction[0] == '$')
        {
            int location;
            location = std::stoi(instruction.substr(1));
            
            //Check if data memory address is a valid index
            if((location < 0) || (location > 1023))
                throw std::invalid_argument(instruction+" Address is out of data memory bounds!\n");
            
            std::string finallocation = instruction.substr(1);
            return OperandFactory::createOperand(0, finallocation);
        }
        else //Nothing to check for a constant number
            return OperandFactory::createOperand(1, instruction);
    }
    else if (regex_match(instruction, instrsyntax)) {
            if (instruction[0] == '#')
            {
                int location;
                location = std::stoi(instruction.substr(1));
                
                //Check if instruction memory address is a valid index
                if((location < 0) || (location > 1023))
                    throw std::invalid_argument(instruction+" Address is out of instruction memory bounds!\n");
                
                std::string finallocation = instruction.substr(1);
                return OperandFactory::createOperand(2, finallocation);
            }
        else throw std::invalid_argument("Invalid instruction memory operand: " + instruction);
        //If an instruction address operand is written as 5# not #5
    }
    else throw std::invalid_argument("Invalid data memory or number operand: " + instruction);
    //If a data memory operand is written as 5$ not $5 or a letter is entered by mistake
    //For example ADD 3, r, $5
}
