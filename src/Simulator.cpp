//
//  Simulator.cpp
//  OOPAssignment2
//
//  Created by Malak Sadek on 11/13/17.
//  Copyright © 2017 Malak Sadek. All rights reserved.
//

#include "Simulator.hpp"

Simulator::Simulator(std::string filePath) {
   
    //Creates the data memory
    DataMemory::createMemory();
    
    instructionFile.open(filePath);
    if (instructionFile.fail()) {
        std::cout << "Cannot open instruction file!\n";
    }
    
    //Creates the instruction memory
    instructionMemory = new Instruction* [1024];
    
    for (int i = 0; i < 1024; i++)
        instructionMemory[i] = nullptr;
    
    memIndex = 0;
    PC = 0;
}

void  Simulator::startSimulator() {
    std::string instruction = "";
    int error = 0;  //This is used so that if an error is detected in an instruction, the rest are not executed
    
    while ((!instructionFile.eof())&&(!error))
    {
        getline(instructionFile, instruction);
        if (instruction == "") continue;
        try
        {
            Processor p;
            Instruction* instr  = p.processInstruction(instruction, PC, memIndex);
            
            if (instr == NULL) {
                std::cout << "Unknown Instruction :\t" + instruction << std::endl;
                //If unidentified instruction
                error = 1;
            }
            else instructionMemory[memIndex++] = instr; //If valid instruction, it is added to memory
        }
        catch (std::invalid_argument e) {
            std::cout << "Error in Instruction : " << instruction << "\n" << e.what() << std::endl;
            //If identified instruction but there is another error
            error = 1;
        }
    }
    
    while ((PC < 1024)&&(!error))
    {
        try
        {
            instructionMemory[PC++]->runInstr();    //Instructions are executed
        }
        catch (std::invalid_argument e)
        {
            std::cout << "Error in Instruction: " << e.what() << std::endl;
            //Instruction has no syntax errors, but there was an execution error
            error = 1;
            break;
        }
    }
}

void  Simulator::displayMemory() {
    DataMemory::getmemPointer()->print();
}

void  Simulator::displayCode() {
        for (int i=0; i<memIndex; i++) {
            std::cout<< instructionMemory[i]->printInstr() <<std::endl;
}
}
